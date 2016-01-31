module ai

intrude import core

redef class Enemy

	redef fun update(dt, world)
	do
		super

		var player = world.player
		if is_alive and player != null and player.is_alive and can_shoot(world) then
			# Shoot if possible
			if player.center.dist2(self.center) < 20.0 * 20.0 then
				aim_and_shoot(world, player)
			end
		end
	end

	fun aim_and_shoot(world: World, target: Body)
	do
		# TODO aim forward of `moving` target
		var angle = self.center.atan2(target.center)

		shoot(angle, world)
	end
end

redef class JetpackEnemy
	redef fun update(dt, world)
	do
		super

		var player = world.player
		if is_alive and player != null and player.is_alive and can_shoot(world) then
			# Move towards player
			var pc = player.center
			var sc = center
			if pc.x < sc.x then
				inertia.x -= 1.0
				if inertia.x < -40.0 then inertia.x = -40.0
			else
				inertia.x += 1.0
				if inertia.x > 40.0 then inertia.x = 40.0
			end
			if pc.y < sc.y then
				inertia.y -= 1.0
				if inertia.y < -40.0 then inertia.y = -40.0
			else
				inertia.y += 1.0
				if inertia.y > 40.0 then inertia.y = 40.0
			end
		end
		#print "Updated jetpack soldier position to {center}, player position is {player.center}"
	end
end
