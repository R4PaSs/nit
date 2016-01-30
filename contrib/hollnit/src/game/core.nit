# This file is part of NIT ( http://www.nitlanguage.org ).
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import geometry

class World
	var planes = new Array[Platform]

	var ennemies = new Array[Ennemy]

	var ennemy_bullets = new Array[Bullet]

	var player_bullets = new Array[Bullet]

	var player: nullable Player = null is writable

	var boss_altitude = 10000.0

	# Runtime of this game
	var t = 0.0

	fun camera_view: Box[Float]
	do
		# TODO update from client
		var border = 100.0
		var player = player
		if player != null then
			return new Box[Float](
				player.center.x-border, player.center.x+border,
				player.center.y+border, player.center.y-border)
		else
			return new Box[Float](
				-border, border,
				border, -border)
		end
	end

	fun update(dt: Float)
	do
		t += dt

		for plane in planes do plane.update(dt, self)
		for ennemy in ennemies do ennemy.update(dt, self)

		var player = player
		if player != null then player.update(dt, self)

		for i in ennemy_bullets do i.update(dt, self)
		for i in player_bullets do i.update(dt, self)
	end

	fun explode(center: Point3d[Float], force: Float)
	do
		var lists = [planes, ennemies: Sequence[Body]]
		var player = player
		if player != null then lists.add([player])

		for l in lists do
			for body in l do
				body.apply_force(center, force)
			end
		end
	end
end

abstract class Body
	super Boxed[Float]

	# Position at the center of the body
	var center: Point3d[Float]

	# Inertia of this body
	var inertia = new Point3d[Float](0.0, 0.0, 0.0)

	# Is this body still alive?
	var is_alive = true

	fun mass: Float do return 1.0

	var width: Float

	var height: Float

	var health: Float = max_health

	fun max_health: Float do return 100.0

	fun affected_by_gravity: Bool do return true

	fun update(dt: Float, world: World)
	do
		if affected_by_gravity then inertia.y -= 4.0

		center.x += dt * inertia.x
		center.y += dt * inertia.y
		center.z += dt * inertia.z

		# Hit the gorund
		# TODO damage/die
		if center.y < 0.0 then
			center.y = 0.0
			inertia.y = 0.0
		end
	end

	fun apply_force(origin: Point3d[Float], force: Float)
	do
		var dx = center.x - origin.x
		var dy = center.y - origin.y

		var d2 = dx*dx + dy*dy
		#TODO if d2 > ? then return

		inertia.x += force / dx / mass
		inertia.y += force / dy / mass
	end

	fun hit(value: Float) do self.health -= value
	fun destroy(world: World) do end
	
	redef fun top do return center.y + height / 2.0
	redef fun bottom do return center.y - height / 2.0
	redef fun left do return center.x - width / 2.0
	redef fun right do return center.x + width / 2.0
end

# A plane
class Platform
	super Body

	redef fun mass do return 100.0

	redef fun affected_by_gravity do return false
end

abstract class Human
	super Body

	# Input direction in `[-1.0 .. 1.0]`
	var moving = 0.0 is writable

	# `moving` speed
	var walking_speed = 20.0

	var freefall_accel = 50.0

	# On which plane? if any
	var plane: nullable Platform = null

	# Equipped weapon
	var weapon: Weapon

	# Apply a jump from input
	fun jump
	do
		if plane != null then
			# On solid plane, jump
			inertia.y += 80.0
			plane = null

			inertia.x = moving * 24.0
		end
	end

	redef fun update(dt, world)
	do
		var on_plane = plane
		if on_plane != null then
			# On a plane, applying special physics do not call super!

			# Precise movements
			center.x += moving * walking_speed * dt

			# Detect fall

			if not (plane.left < right and plane.right > left) then
				self.plane = null
			end
		else
			# Freefall

			# Only influence the inertia
			inertia.x += moving * freefall_accel * dt

			var old_y = bottom
			super

			# Detect collision with planes
			for plane in world.planes do # TODO optimize with quad tree
				if plane.left < right and plane.right > left then
					if old_y > plane.top and bottom <= plane.top then
						# Landed on a plane
						self.plane = plane
						inertia.x = 0.0
						inertia.y = 0.0
						center.y = plane.top + height / 2.0
						break
					end
				end
			end
		end

		if center.y == 0.0 then
			is_alive = false
		end
	end
end

class Player
	super Human
	
	fun shoot(angle: Float, world: World) do
		if world.t - weapon.last_shot < weapon.cooldown then return
		var x_inertia = angle.cos * weapon.power
		var y_inertia = angle.sin * weapon.power
		var new_center = new Point3d[Float](self.center.x, self.center.y, self.center.z + 0.1)
		var bullet = new PlayerBullet(new_center, 2.0, 2.0, angle, self.weapon, world.t,  world.planes, world.ennemies)
		bullet.inertia.x = self.inertia.x + x_inertia
		bullet.inertia.y = self.inertia.y + y_inertia
		world.player_bullets.add(bullet)
		weapon.last_shot = world.t
	end
end

class Ennemy
	super Human
end

class Powerup
	super Body
end

class Weapon
	var last_shot: Float is writable, noinit
	fun damage: Float is abstract
	fun cooldown: Float is abstract
	fun power: Float is abstract
	fun bullet_lifespan: Float is abstract
end

class Bullet
	super Body
	var angle: Float
	var weapon: Weapon
	var creation_time: Float
	redef fun affected_by_gravity do return false
	redef fun update(dt, world) do
		super
		if world.t - creation_time >= weapon.bullet_lifespan then destroy(world)
	end
	fun hit_ennemy(body: Body) do body.hit(self.weapon.damage)
end

class PlayerBullet
	super Bullet
	var planes: Array[Platform]
	var ennemies: Array[Ennemy]
	redef fun update(dt, world) do
		super
		for i in planes do if self.intersects(i) then hit_ennemy(i)
		for i in ennemies do if self.intersects(i) then hit_ennemy(i)
	end

	redef fun destroy(world) do
		super
		world.player_bullets.remove(self)
	end
end

class EnnemyBullet
	super Bullet
	var player: Player
	redef fun update(dt, world) do
		super
		if self.intersects(player) then hit_ennemy(player)
	end

	redef fun destroy(world) do
		super
		world.ennemy_bullets.remove(self)
	end
end


class Ak47
	super Weapon
	redef var damage = 10.0
	redef var cooldown = 0.5
	redef var power = 10.0
	redef var bullet_lifespan = 3.0
end
