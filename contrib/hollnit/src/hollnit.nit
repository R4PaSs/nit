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
import texts

redef class App

	# Game world
	var world: World = generate_world is lazy

	var gnd_texture = new Texture("textures/plane.png")

	var plane_textures: Array[Texture] = [
		new Texture("textures/plane_left.png"),
		new Texture("textures/plane.png")]

	var helicopter_textures: Array[Texture] = [
		new Texture("textures/helicopter.png"),
		new Texture("textures/helicopter_right.png")]

	var enemy_texture = new Texture("textures/enemy.png")

	var player_textures: Array[Texture] =
		[for f in [1..12] do new Texture("textures/player/run-cycle-inked2_xcf-Frame_{f.pad(2)}__100ms___replace_.png")]

	var bullet_texture = new Texture("textures/bullet.png")

	var city_texture = new Texture("textures/city_background_clean.png")

	# Ground
	private var ground_texture = new Texture("textures/fastgras01.png")

	# ---
	# Blood splatter
	private var splatter_texture = new Texture("textures/blood_splatter.png")
	private var splatter_material: TexturedMaterial do
		var mat = new TexturedMaterial([1.0]*4, [0.0]*4, [0.0]*4)
		mat.ambient_texture = splatter_texture
		return mat
	end
	private var splatter_model = new LeafModel(new Plane, splatter_material)

	var tree_texture = new Texture("textures/Tree03.png")

	# ---
	# Particle effects

	# Explosion particle system
	var explosions = new ParticleSystem(20, explosion_program,
		new Texture("particles/explosion00.png"))

	var blood = new ParticleSystem(20, explosion_program,
		new Texture("particles/blood07.png"))

	var smoke = new ParticleSystem(500, smoke_program,
		new Texture("particles/blackSmoke12.png"))

	var clouds = new ParticleSystem(1600, cloud_program,
		new Texture("particles/whitePuff12.png"))

	# ---
	# Sound effects

	#private var fx_fire = new Sound("sounds/fire.mp3")

	# ---
	# UI
	private var texts_sheet = new TextsImages

	private var ui_tutorial_wasd: Texture = texts_sheet.tutorial_wasd
	private var ui_respawn: Texture = texts_sheet.respawn

	fun generate_world: World
	do
		var world = new World
		world.spawn_player
		world.planes.add new Platform(new Point3d[Float](0.0, 190.0, 0.0), 16.0, 4.0)
		return world
	end

	fun generate_debug_world: World
	do
		var world = new World

		for i in [0..100] do
			world.planes.add new Platform(new Point3d[Float](0.0, i.to_f*16.0 + 8.0, 0.0), 16.0, 4.0)
			world.planes.add new Platform(new Point3d[Float](0.0, i.to_f*16.0 + 16.0, 0.0), 16.0, 4.0)

		end

		# Enemies
		world.enemies.add new WalkingEnemy(new Point3d[Float](20.0, 200.0, 0.0), 4.0, 4.0, new Ak47)
		world.enemies.add new JetpackEnemy(new Point3d[Float](-20.0, 200.0, 0.0), 4.0, 4.0, new Ak47)

		world.spawn_player
		return world
	end

	redef fun on_create
	do
		super

		# Move the camera to show all the world world in the screen range
		world_camera.reset_height(40.0)
		ui_camera.reset_height(1080.0)

		# Register particle systems
		particle_systems.add explosions
		particle_systems.add blood
		particle_systems.add smoke
		particle_systems.add clouds

		# Setup ground
		# TODO we may need to move this plane if the player goes far from the center
		var ground_mesh = new Plane
		ground_mesh.repeat_x = 100.0
		ground_mesh.repeat_y = 100.0

		var ground_material = new TexturedMaterial(
			[0.0, 0.1, 0.0, 1.0], [0.4, 0.4, 0.4, 1.0], [0.0]*4)
		ground_material.diffuse_texture = ground_texture

		var ground_model = new LeafModel(ground_mesh, ground_material)
		var ground = new Actor(ground_model, new Point3d[Float](0.0, 0.0, 0.0))
		ground.scale = 5000.0
		actors.add ground

		# City
		var city_sprite = new Sprite(city_texture, new Point3d[Float](0.0, 600.0, -999.0))
		city_sprite.scale = 1.2
		sprites.add city_sprite


		# Trees
		for i in 1000.times do
			var s = 0.1 + 0.1.rand
			var h = tree_texture.height * s
			var sprite = new Sprite(tree_texture,
				new Point3d[Float](0.0 & 1500.0, h/2.0 - 10.0*s, 10.0 - 1009.0.rand))
			sprite.scale = s
			sprites.add sprite

			var c = 1.0.rand
			c *= 0.7
			sprite.color = [c, 1.0, c, 1.0]
		end

		# Clouds
		var no_clouds_layer = 400.0
		for i in [0..1000[ do
			var zp = 1.0.rand
			var x = 0.0 & 1000.0 * zp
			var y = no_clouds_layer + (world.boss_altitude - no_clouds_layer*2.0).rand
			var z = -500.0*zp - 10.0

			var r = 50.0 & 1.0
			for j in [0..16[ do
				var a = 2.0*pi.rand
				var rj = r.rand
				clouds.add(new Point3d[Float](x+2.0*a.cos*rj, y+a.sin*rj, z & 1.0),
					48000.0 & 16000.0, inf)
			end
		end

		world_camera.far = 1100.0
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

		# Randomly add smoke
		var poss = [
			new Point3d[Float](432.0, 550.0, -1001.0),
			new Point3d[Float](-497.0, 630.0, -1001.0)]

		var r = 8.0
		if 2.rand == 0 then # for pos in poss.rand do
			var pos = poss.rand
			smoke.add(
				new Point3d[Float](pos.x & r, pos.y & r, pos.z & r),
				48000.0 & 8000.0, 10.0)
		end

		# Move camera
		world_camera.position.x = player_pos.x
		world_camera.position.y = player_pos.y + 5.0

		# Try to fire as long as a key is pressed
		if pressed_keys.not_empty then
			var a = inf
			if pressed_keys.has("a") then
				if pressed_keys.has("w") then
					a = 0.75 * pi
				else if pressed_keys.has("s") then
					a = 1.25 * pi
				else
					a = pi
				end
			else if pressed_keys.has("d") then
				if pressed_keys.has("w") then
					a = 0.25 * pi
				else if pressed_keys.has("s") then
					a = 1.75 * pi
				else
					a = 0.0
				end
			else if pressed_keys.has("w") then
				a = 0.50 * pi
			else if pressed_keys.has("s") then
				a = 1.50 * pi
			end

			if a != inf and player != null then
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
			if player != null and player.is_alive then

				if (event.name == "space" or event.name == "up") and event.is_down then
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

			if player != null and not player.is_alive then
				if event.name == "space" then
					ui_sprites.clear
					world.spawn_player
				end
			end
		end

		return s
	end
end

redef class Body
	fun sprite: Sprite is abstract

	init do app.sprites.add sprite

	redef fun destroy(world)
	do
		super
		app.sprites.remove sprite
	end
end

redef class Platform

	fun textures: Array[Texture] do return app.plane_textures

	redef var sprite = new Sprite(textures.first, center) is lazy
	init do sprite.scale = width/sprite.texture.width

	redef fun update(dt, world)
	do
		super

		if inertia.x < 0.0 then
			sprite.texture = textures[0]
		else if inertia.x > 0.0 then
			sprite.texture = textures[1]
		end
	end
end

redef class Helicopter
	redef fun textures do return app.helicopter_textures
end

redef class Enemy
	redef var sprite = new Sprite(app.player_textures.rand, center) is lazy
	init do sprite.scale = width/sprite.texture.width * 2.0
end

redef class Player
	redef var sprite = new Sprite(app.player_textures.rand, center) is lazy
	init do sprite.scale = width/sprite.texture.width * 2.0

	redef fun die(world)
	do
		super

		var force = 4.0
		health = 0.0
		for i in 32.times do
			app.blood.add(
				new Point3d[Float](center.x & force, center.y & force, center.z & force),
				(1024.0 & 2048.0) * force, 0.3 & 0.1)
		end

		if center.y < 10.0 then
			# Blood splatter on the ground
			var splatter = new Actor(app.splatter_model,
				new Point3d[Float](center.x, 0.05 & 0.04, center.y))
			splatter.scale = 32.0
			splatter.rotation = 2.0 * pi.rand
			app.actors.add splatter
		end

		# Display respawn instructions
		# TODO explosions and delay
		app.ui_sprites.add new Sprite(app.ui_respawn, app.ui_camera.center)
	end
end

redef class Bullet
	redef var sprite = new Sprite(app.bullet_texture, center) is lazy
	init do
		sprite.scale = 0.05
		sprite.rotation = -angle
	end
end

redef class World

	redef fun explode(center, force)
	do
		super

		# Particles
		app.explosions.add(center, 4096.0 * force, 0.3)
		for i in 64.times do
			app.explosions.add(
				new Point3d[Float](center.x & force, center.y & force/2.0, center.z & force),
				(2048.0 & 1024.0) * force, 0.3 & 0.3, 0.5.rand)
		end
	end
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

#class Animation
	#super Sprite

	#var time_per_frame: Float

	#private var current_t = 0.0

	#new (frames: Array[Texture], center: Point3d[Float], time_per_frame: Float)
	#do
		#init(frames.first, center, frames, time_per_frame)
	#end

	#var frames: Array[Texture]

	#redef fun sprite
	#do
	#end
#end
