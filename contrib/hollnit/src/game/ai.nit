module ai

intrude import core

redef class Enemy

	redef fun update(dt, world)
	do
		super

		var player = world.player
		if is_alive and player != null and player.is_alive and can_shoot(world) then
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
