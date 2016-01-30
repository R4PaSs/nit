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
	var planes = new Array[Plane]

	var ennemies = new Array[Human]

	var player: nullable Human = null

	var boss_height = 10000.0

	fun update(dt: Float)
	do
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

	fun update(dt: Float)
	do
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

class Plane
	super Body

	redef fun mass do return 100.0
end

class Human
	super Body

	# Input direction in `[-1.0 .. 1.0]`
	var moving = 0.0

	# `moving` speed
	var speed = 5.0

	# On which plane? if any
	var plane: nullable Plane = null

	# Equipped weapon
	var weapon: Weapon

	# Apply a jump from input
	fun jump
	do
	end
end

class Powerup
	super Body
end

class Weapon
	var damage: Float

	var cooldown: Float
end
