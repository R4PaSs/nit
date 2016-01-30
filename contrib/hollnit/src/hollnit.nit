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

module hollnit

import gamnit::depth
import gamnit::keys
import gamnit::limit_fps

import game

redef class App

	# Game world
	var world: World = generate_world is lazy

	var plane_texture = new Texture("textures/plane.png")
	var ennemy_texture = new Texture("textures/ennemy.png")
	var player_textures: Array[Texture] =
		[for f in [1..12] do new Texture("textures/player/run-cycle-inked2_xcf-Frame_{f.pad(2)}__100ms___replace_.png")]
	var bullet_texture = new CheckerTexture

	var low_background_texture = new Texture("textures/low_background.png")

	# ---
	# Particle effects

	# Explosion image for particle effect
	private var texture_explosion = new Texture("particles/explosion00.png")

	# Explosion particle system
	var explosions = new ParticleSystem(20, explosion_program, texture_explosion)

	# ---
	# Sound effects

	#private var fx_fire = new Sound("sounds/fire.mp3")

	fun generate_world: World
	do
		var world = new World
		world.player = new Player(new Point3d[Float](0.0, 20.0, 0.0), 4.0, 4.0,
			new Ak47)
		world.planes.add new Platform(new Point3d[Float](0.0, 10.0, 0.0), 16.0, 4.0)
		world.planes.add new Platform(new Point3d[Float](20.0, 22.0, 0.0), 16.0, 4.0)
		return world
	end

	redef fun on_create
	do
		super

		# Move the camera to show all the world world in the screen range
		world_camera.reset_height(40.0)

		particle_systems.add explosions
	end

	redef fun update(dt)
	do
		# Game logic
		world.update dt

		# Update background color
		var player = world.player
		var player_pos = if player != null then player.center else new Point3d[Float](0.0, 0.0, 0.0)
		var altitude = player_pos.y
		var p = altitude / world.boss_altitude
		var ip = 1.0 - p
		glClearColor(0.3*ip, 0.3*ip, ip, 1.0)

		# Move camera
		#world_camera.position.x = player_pos.x
		#world_camera.position.y = player_pos.y

		# Try to fire as long as a key is pressed
		for key in pressed_keys do
			var a = inf
			if key == "a" then
				a = pi
			else if key == "d" then
				a = 0.0
			else if key == "q" then
				a = 0.75 * pi
			else if key == "w" then
				a = 0.50 * pi
			else if key == "e" then
				a = 0.25 * pi
			end

			if a != inf then
				player.shoot(a, world)
			end
		end
	end

	redef fun accept_event(event)
	do
		var s = super

		if event isa QuitEvent then
			exit 0
		else if event isa KeyEvent then
			if event.name == "escape" and event.is_down then
				exit 0
			end

			var player = world.player
			if player != null then

				if event.name == "space" and event.is_down then
					player.jump
				end

				if event.name == "left" then
					var mod = if event.is_down then -1.0 else 1.0
					player.moving += mod
				end

				if event.name == "right" then
					var mod = if event.is_down then 1.0 else -1.0
					player.moving += mod
				end
			end
		end

		if event isa PointerEvent and event.depressed then
		# Particles
		var pos = new Point3d[Float](0.0, 0.0, 0.0)
		app.explosions.add(new Point3d[Float](pos.x, 1.0, pos.y), 4096.0, 0.3)
		for i in 8.times do
			app.explosions.add(
				new Point3d[Float](pos.x & 1.0, 1.0 & 1.0, pos.y & 1.0),
				2048.0 & 1024.0, 0.3 & 0.1)
		end
		end

		return s
	end
end

redef class Body
	fun sprite: Sprite is abstract

	init do app.sprites.add sprite
end

redef class Platform
	redef var sprite = new Sprite(app.plane_texture, center) is lazy
	init do sprite.scale = width/sprite.texture.width
end

redef class Ennemy
	redef var sprite = new Sprite(app.ennemy_texture, center) is lazy
end

redef class Player
	redef var sprite = new Sprite(app.player_textures.rand, center) is lazy
	init do sprite.scale = width/sprite.texture.width * 2.0
end

redef class Bullet
	redef var sprite = new Sprite(app.bullet_texture, center) is lazy
	init do
		sprite.scale = 0.5
		sprite.rotation = angle
	end
end

redef class World
end

redef class Int
	# Pad a number with `0`s on the left side to reach `size` digits
	private fun pad(size: Int): String
	do
		var s = to_s
		var d = size - s.length
		if d > 0 then s = "0"*d + s
		return s
	end
end

redef class Float
	# Fuzzy value in `[self-variation..self+variation]`
	fun &(variation: Float): Float do return self - variation + 2.0*variation.rand
end
