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

	var plane_texture = new Texture("textures/plane.png")

	var helicopter_texture = new Texture("textures/helicopter.png")

	var enemy_texture = new Texture("textures/enemy.png")

	var player_textures: Array[Texture] =
		[for f in [1..12] do new Texture("textures/player/run-cycle-inked2_xcf-Frame_{f.pad(2)}__100ms___replace_.png")]

	var bullet_texture = new Texture("textures/bullet.png")

	var city_texture = new Texture("textures/city_background_clean.png")

	var parachute_texture = new Texture("textures/parachute.png")

	var iss_model = new Model("models/iss.obj")

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

	private var tutorial_wasd = new Sprite(app.texts_sheet.tutorial_wasd,
		app.ui_camera.center.offset(0.0, -150.0, 0.0)) is lazy

	private var tutorial_arrows = new Sprite(app.texts_sheet.tutorial_arrows,
		app.ui_camera.center.offset(0.0, -300.0, 0.0)) is lazy

	private var tutorial_chute = new Sprite(app.texts_sheet.tutorial_chute,
		app.ui_camera.center.offset(0.0, -450.0, 0.0)) is lazy

	var score_counter = new CounterSprites(texts_sheet.n,
		new Point3d[Float](32.0, -64.0, 0.0))

	var altitude_counter = new CounterSprites(texts_sheet.n,
		new Point3d[Float](1400.0, -64.0, 0.0))

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

		show_splash_screen new Texture("textures/splash.jpg")

		# Load 3d models
		iss_model.load

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

		ui_sprites.add_all([tutorial_wasd, tutorial_arrows, tutorial_chute])
	end

	redef fun update(dt)
	do
		# Game logic
		world.update dt

		score_counter.value = world.score
		var alt = 0
		if world.player != null then alt = world.player.altitude.to_i
		altitude_counter.value = alt

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
				hide_tutorial_wasd
			end
		end
	end

	# Remove tutorial sprite about WASD from `ui_sprites`
	private fun hide_tutorial_wasd do if ui_sprites.has(tutorial_wasd) then ui_sprites.remove(tutorial_wasd)

	# Remove tutorial sprite about arrows from `ui_sprites`
	private fun hide_tutorial_arrows do if ui_sprites.has(tutorial_arrows) then ui_sprites.remove(tutorial_arrows)

	# Remove tutorial sprite about space from `ui_sprites`
	private fun hide_tutorial_chute do if ui_sprites.has(tutorial_chute) then ui_sprites.remove(tutorial_chute)

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

				var arrows = once ["left", "right"]
				if arrows.has(event.name) then hide_tutorial_arrows

				if player.altitude < world.boss_altitude then
					if event.name == "space" and event.is_down and not player.parachute_deployed and player.plane == null then
						player.parachute
						if player.parachute_deployed then
							var pc = player.center
							world.parachute = new Parachute(new Point3d[Float](pc.x, pc.y + 5.0, pc.z), 2.0, 5.0)
						end
						hide_tutorial_chute
					end

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

					if player.moving == 0.0 then
					player.sprite.as(PlayerSprite).stop_running
					else player.sprite.as(PlayerSprite).start_running
				else
					if event.name == "up" and event.is_down then
						player.y_moving = 50.0
					end

					if event.name == "down" and event.is_down then
						player.y_moving = -50.0
					end

					if event.name == "left" then
						player.x_moving = -50.0
					end

					if event.name == "right" then
						player.x_moving = 50.0
					end
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
	# Sprite representing this entity if there is no `actor`
	fun sprite: Sprite is abstract

	# 3D actor
	fun actor: nullable Actor do return null

	init
	do
		var actor = actor
		if actor != null then
			app.actors.add actor
		else app.sprites.add sprite
	end

	redef fun destroy(world)
	do
		super
		app.sprites.remove sprite
	end
end

redef class Human
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
	end
end

redef class Platform

	redef var sprite = new Sprite(app.plane_texture, center) is lazy
	init do sprite.scale = width/sprite.texture.width

	redef fun update(dt, world)
	do
		super

		if inertia.x < 0.0 then
			sprite.invert_x = true
		else if inertia.x > 0.0 then
			sprite.invert_x = false
		end
	end
end

redef class Helicopter
	redef var sprite = new Sprite(app.helicopter_texture, center) is lazy

	redef var actor is lazy do
		var actor = new Actor(app.iss_model, center)
		actor.rotation = pi/2.0
		return actor
	end
end

redef class Enemy
	redef var sprite = new Sprite(app.player_textures.rand, center) is lazy
	init do sprite.scale = width/sprite.texture.width * 2.0
end

redef class Parachute
	redef var sprite = new Sprite(app.parachute_texture, center) is lazy
	init do sprite.scale = width / sprite.texture.width * 2.0
end

redef class Player
	redef var sprite = new PlayerSprite(app.player_textures[1], center, app.player_textures, 0.08) is lazy
	init do sprite.scale = width/sprite.texture.width * 2.0

	redef fun update(dt, world)
	do
		super
		if moving > 0.0 then
			sprite.invert_x = false
		else if moving < 0.0 then
			sprite.invert_x = true
		end
	end

	redef fun die(world)
	do
		super

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
		app.ui_sprites.add new Sprite(app.texts_sheet.respawn, app.ui_camera.center)
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

class PlayerSprite
	super Sprite

	var running_animation: Array[Texture]

	var current_animation: nullable Array[Texture] = null

	private var anim_ot = 0.0

	var time_per_frame: Float

	fun start_running
	do
		anim_ot = app.world.t
		current_animation = running_animation
	end

	fun stop_running do current_animation = null

	redef fun texture
	do
		var anim = current_animation
		if anim != null then
			var dt = app.world.t - anim_ot
			var i = (dt / time_per_frame).to_i+2
			return anim.modulo(i)
		end

		return super
	end
end

class CounterSprites
	var textures: Array[Texture]

	private var sprites = new Array[Sprite]

	var anchor: Point3d[Float]

	private var dx: Float is noinit
	init
	do
		var sx = 0.0
		for t in textures do sx += t.width
		dx = sx / textures.length.to_f
	end

	fun value=(value: Int)
	do
		for s in sprites do app.ui_sprites.remove s
		sprites.clear

		var s = value.to_s # TODO manipulate ints directly
		var x = 0.0
		for c in s do
			var i = c.to_i
			var tex = textures[i]

			x += tex.width/2.0
			sprites.add new Sprite(tex, new Point3d[Float](anchor.x + x, anchor.y, anchor.z))
			x += tex.width/2.0
		end

		app.ui_sprites.add_all sprites
	end
end
