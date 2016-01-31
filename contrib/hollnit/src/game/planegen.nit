import core

redef class Float
	# Fuzzy value in `[self-variation..self+variation]`
	fun &(variation: Float): Float do return self - variation + 2.0*variation.rand
end

redef class World

	var max_planes = 10
	var max_enemies = 10

	redef fun update(dt) do
		super
		spawn_plane
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
			var possible_y = new Array[Float]
			for i in planes do
				print "Plane coordinates = {i.center}"
				var iy = i.center.y
				for j in possible_y do
					if (j - iy).abs < 10.0 then continue
				end
				possible_y.add iy
			end
			if not possible_y.is_empty then
				yspawn = possible_y.rand & 30.0
			else
				yspawn = p.center.y & 25.0
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
			#var enemy = new Enemy(pos, 3.0, 3.0, new Ak47)
			#enemy.inertia = pl.inertia
			#enemies.add enemy
			return
		end
		print "Spawning enemy"
		var randx = camera_view.top.rand + p.center.x
		var randy = camera_view.left.rand + p.center.y
		var pos = new Point3d[Float](randx, randy, 0.0)
		#var enemy = new Enemy(pos, 0.5, 0.5, new Ak47)
		#enemies.add enemy
	end
end
