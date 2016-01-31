import core

redef class World

	var max_planes = 12
	var max_enemies = 5

	redef fun update(dt) do
		super
		spawn_enemy(spawn_plane)
	end

	fun spawn_plane: Bool do
		var p = player
		if p == null then return false
		for i in planes.reverse_iterator do
			if i.out_of_screen(p, self) then
				print "Despawning plane"
				i.destroy(self)
			end
		end
		if p.dead then return false
		if planes.length >= max_planes then return false
		var spawn = 100.rand
		if spawn < 95 then return false
		var pos: Point3d[Float]
		var xspawn = 50.0.rand
		var direction: Int
		if xspawn >= 25.0 then
			xspawn = camera_view.right - 1.0
			direction = 1
		else
			xspawn = camera_view.left - 8.0
			direction = 0
		end
		var yspawn: Float
		if planes.length == 0 then
			print "First plane spawn"
			yspawn = p.center.y & 25.0
		else
			var py = p.center.y
			var planes_below = 0
			var planes_above = 0
			var above_y = new Array[Float]
			var below_y = new Array[Float]
			for i in planes do
				print "Plane coordinates = {i.center}"
				var iy = i.center.y
				if iy > py then
					planes_above += 1
					above_y.add iy
				else
					planes_below += 1
					below_y.add iy
				end
			end
			if planes_below < planes_above then
				if planes_below == 0 then
					yspawn = py - 15.0.rand
				else
					yspawn = below_y.rand - 25.0.rand
				end
			else
				if planes_above == 0 then
					yspawn = py + 15.0.rand
				else
					yspawn = above_y.rand + 25.0.rand
				end
			end
		end
		pos = new Point3d[Float](xspawn, yspawn, 0.0 & 0.2)
		print("Spawning plane at position {pos}")
		var platform_type = 100.rand
		var plane: Platform
		if platform_type < 90 then
			plane = new Platform(pos, 16.0, 4.0)
		else
			plane = new Helicopter(pos, 16.0, 4.0)
		end
		var xspeed = 50.0
		if direction == 1 then xspeed = -xspeed
		plane.inertia = new Point3d[Float](xspeed, -0.1, 0.0)
		planes.add(plane)
		return true
	end

	fun spawn_enemy(spawned_plane: Bool) do
		var p = player
		if p == null then return
		if enemies.length >= max_enemies then return
		var spawn = 100.rand
		if spawn < 95 then return
		if spawned_plane then
			print "Spawning enemy"
			var pl = planes.last
			var pos = new Point3d[Float](pl.center.x, pl.center.y + pl.left / 2.0, 0.0)
			var enemy = new WalkingEnemy(pos, 3.0, 3.0, new Ak47)
			enemy.inertia = pl.inertia
			enemies.add enemy
			return
		end
		print "Spawning enemy"
		var randx = camera_view.top.rand + p.center.x
		var randy = camera_view.left.rand + p.center.y
		var pos = new Point3d[Float](randx, randy, 0.0)
		var enemy = new JetpackEnemy(pos, 3.0, 3.0, new Ak47)
		enemy.inertia = new Point3d[Float](10.0.rand, 10.0.rand, 0.0)
		enemies.add enemy
	end
end
