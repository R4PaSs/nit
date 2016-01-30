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
		for plane in planes do plane.update(dt, self)
		for ennemy in ennemies do ennemy.update(dt, self)

		var player = player
		if player != null then player.update(dt, self)

		for i in ennemy_bullets do i.update(dt, self)
		for i in player_bullets do i.update(dt, self)
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
		center.x += dt * inertia.x
		center.y += dt * inertia.y
		center.z += dt * inertia.z

		if affected_by_gravity then inertia.y -= 0.1

		# Hit the gorund
		# TODO damage/die
		if center.y < 0.0 then center.y = 0.0
	end

	fun apply_force(origin: Point3d[Float], force: Float)
	do
		var dx = center.x - origin.x
	end

	redef fun top do return center.y - height / 2.0
	redef fun bottom do return center.y + height / 2.0
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
	var moving = 0.0

	# `moving` speed
	var speed = 5.0

	# On which plane? if any
	var plane: nullable Platform = null

	# Equipped weapon
	var weapon: Weapon

	# Apply a jump from input
	fun jump
	do
		inertia.y += 20.0

		print "jump"
	end
end

class Player
	super Human
end

class Ennemy
	super Human
end

class Powerup
	super Body
end

class Weapon
	var damage: Float
	var cooldown: Float
end

class Bullet
	super Body
	var weapon: Weapon
	var ennemies: Array[Body]
	redef fun affected_by_gravity do return false
	redef fun update(dt, world) do
		super
		for i in ennemies do if self.intersects(i)  then hit(i)
	end
	fun hit(body: Body) do body.health -= self.weapon.damage
end


class Ak47
	super Weapon
	redef var damage = 10.0
	redef var cooldown = 0.5
end
