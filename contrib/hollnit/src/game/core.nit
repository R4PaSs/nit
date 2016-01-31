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

	var enemies = new Array[Enemy]

	var enemy_bullets = new Array[Bullet]

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

		for plane in planes.reverse_iterator do plane.update(dt, self)
		for enemy in enemies.reverse_iterator do enemy.update(dt, self)

		var player = player
		if player != null then player.update(dt, self)

		for i in enemy_bullets.reverse_iterator do i.update(dt, self)
		for i in player_bullets.reverse_iterator do i.update(dt, self)
	end

	fun explode(center: Point3d[Float], force: Float)
	do
		var lists = [planes, enemies: Sequence[Body]]
		var player = player
		if player != null then lists.add([player])

		for l in lists do
			for body in l do
				body.apply_force(center, force)
			end
		end
	end

	fun spawn_player
	do
		var old_player = player
		var pos = null
		if old_player != null then
			pos = old_player.center
			pos.y += 50.0
		end

		if pos == null then pos = new Point3d[Float](0.0, 200.0, 0.0)

		player = new Player(pos, 4.0, 4.0, new Ak47)
	end
end

abstract class Body
	super Boxed[Float]

	# Position at the center of the body
	var center: Point3d[Float]

	# Inertia of this body
	var inertia = new Point3d[Float](0.0, 0.0, 0.0) is writable

	# Is this body still alive?
	var is_alive = true

	fun mass: Float do return 1.0

	var width: Float

	var height: Float

	var health: Float = max_health

	fun max_health: Float do return 100.0

	fun affected_by_gravity: Bool do return true

	fun dead: Bool do return health <= 0.0

	fun update(dt: Float, world: World)
	do
		if affected_by_gravity then inertia.y -= 4.0

		center.x += dt * inertia.x
		center.y += dt * inertia.y
		center.z += dt * inertia.z

		# Hit the gorund
		# TODO damage/die
		if bottom <= 0.0 and affected_by_gravity then
			center.y = height / 2.0
			inertia.y = 0.0
		end
	end

	fun apply_force(origin: Point3d[Float], force: Float)
	do
		var dx = center.x - origin.x
		var dy = center.y - origin.y

		var d2 = dx*dx + dy*dy
		var d = d2.sqrt
		#TODO if d2 > ? then return

		inertia.x += dx * force / d / mass * 4.0
		inertia.y += dy * force / d / mass * 12.0

		if self isa Player then
			self.plane = null
		end
	end

	fun hit(value: Float, world: World)
	do
		self.health -= value
		if self.health <= 0.0 then die(world)
	end

	# Die in the game logic with animations for the player
	#
	# Calls `destroy` by default.
	fun die(world: World)
	do
		is_alive = false
		destroy world
	end

	# Destroy this objects and most references to it
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

	redef fun die(world)
	do
		super
		world.explode(center, width)
	end

	redef fun destroy(world)
	do
		world.planes.remove self
		super
	end

	var old_inertia: nullable Point3d[Float] = null

	fun out_of_screen(player: Player, world: World): Bool do
		var camera = world.camera_view
		if right < camera.left - 30.0 then return true
		if left > camera.right + 30.0 then return true
		if top < camera.bottom - 30.0 then return true
		if bottom > camera.top + 30.0 then return true
		return false
	end

	fun player_dist(world: World): Float do
		var p = world.player
		if p == null then return 0.0
		var px = p.center.x
		var dst = center.x - px
		print "Player x position = {px}, distance = {dst}"
		return dst.abs
	end

	redef fun update(dt, world) do
		inertia.y *= 0.95
		super
		var dst = player_dist(world)
		if dst < 20.0 then
			var oi = inertia
			var ninertia: Point3d[Float]
			var speed = 10.0 & 15.0
			if speed < 10.0 then speed = 10.0
			if oi.x < 0.0 then
				ninertia = new Point3d[Float](-speed, 0.1, 0.0)
			else
				ninertia = new Point3d[Float](speed, 0.1, 0.0)
			end
			#print "Changed inertia from {inertia} to {ninertia}"
			inertia = ninertia
			old_inertia = oi
		else
			var oi = old_inertia
			if oi == null then return
			inertia = oi
		end
	end

end

class Helicopter
	super Platform
end

abstract class Human
	super Body

	# Input direction in `[-1.0 .. 1.0]`
	var moving = 0.0 is writable

	# `moving` speed when on a plane, applied directly to `center`
	var walking_speed = 20.0

	# `moving` speed when in freefall, applied to `inertia`
	var freefall_accel = 100.0

	var jump_accel = 24.0

	# On which plane? if any
	var plane: nullable Platform = null

	# Position in relation to `plane`
	private var dx_to_plane = 0.0

	# Equipped weapon
	var weapon: Weapon

	# Apply a jump from input
	fun jump
	do
		var plane = plane
		if plane != null then
			# On solid plane, jump
			inertia.y += 100.0
			inertia.x = plane.inertia.x + moving * jump_accel

			self.plane = null
		end
	end

	redef fun update(dt, world)
	do
		if not is_alive then return

		var on_plane = plane
		if on_plane != null then
			# Is it still alive?
			if not on_plane.is_alive then
				on_plane = null
				self.plane = null
			end
		end

		if on_plane != null then
			# On a plane, applying special physics do not call super!

			# Precise movements
			center.x = on_plane.center.x + dx_to_plane + moving * walking_speed * dt
			center.y = on_plane.top + height / 2.0

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
						plane.inertia.y += inertia.y / plane.mass

						# Update self
						self.plane = plane
						inertia.x = 0.0
						inertia.y = 0.0
						center.y = plane.top + height / 2.0

						break
					end
				end
			end
		end

		on_plane = self.plane
		if on_plane != null then
			dx_to_plane = center.x - on_plane.center.x
		end

		if bottom <= 0.0 then
			die world
			inertia.x = 0.0
			inertia.y = 0.0
		end
	end

	# Is the weapon ready to shoot yet?
	fun can_shoot(world: World): Bool
	do
		return is_alive and world.t - weapon.last_shot >= weapon.cooldown
	end

	fun shoot(angle: Float, world: World) do
		if not can_shoot(world) then return

		var x_inertia = angle.cos * weapon.power
		var y_inertia = angle.sin * weapon.power
		var new_center = new Point3d[Float](self.center.x, self.center.y, self.center.z + 0.1)

		var bullet = register_bullet(new_center, angle, world)
		bullet.inertia.x = x_inertia
		bullet.inertia.y = y_inertia
		weapon.last_shot = world.t
	end

	protected fun register_bullet(new_center: Point3d[Float], angle: Float, world: World): Bullet
	do
		var bullet = new EnemyBullet(new_center, 2.0, 2.0, angle, self.weapon, world.t, world.player.as(not null))
		world.enemy_bullets.add(bullet)
		return bullet
	end
end

class Player
	super Human

	redef fun register_bullet(new_center, angle, world)
	do
		var bullet = new PlayerBullet(new_center, 2.0, 2.0, angle, self.weapon, world.t,  world.planes, world.enemies)
		world.player_bullets.add(bullet)
		return bullet
	end

	redef fun max_health do return 200.0
end

abstract class Enemy
	super Human

	redef fun max_health do return 20.0

	redef fun destroy(world)
	do
		super
		world.enemies.remove self
	end
end

class WalkingEnemy
	super Enemy
end

class JetpackEnemy
	super Enemy

	redef fun affected_by_gravity do return false
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

	fun hit_enemy(body: Body, world: World) do body.hit(self.weapon.damage, world)
end

class PlayerBullet
	super Bullet

	var planes: Array[Platform]

	var enemies: Array[Enemy]

	redef fun update(dt, world) do
		super
		for i in planes do if self.intersects(i) then
			hit_enemy(i, world)
			destroy(world)
		end
		for i in enemies do if self.intersects(i) then
			hit_enemy(i, world)
			destroy(world)
		end
	end

	redef fun destroy(world) do
		super
		world.player_bullets.remove(self)
	end
end

class EnemyBullet
	super Bullet

	var player: Player

	redef fun update(dt, world) do
		super
		if self.intersects(player) then
			hit_enemy(player, world)
			destroy(world)
		end
	end

	redef fun destroy(world) do
		super
		world.enemy_bullets.remove(self)
	end
end

class Ak47
	super Weapon

	redef var damage = 10.0

	redef var cooldown = 0.1

	redef var power = 50.0

	redef var bullet_lifespan = 3.0
end

redef class Float
	# Fuzzy value in `[self-variation..self+variation]`
	fun &(variation: Float): Float do return self - variation + 2.0*variation.rand
end
