module ai

intrude import core

redef class Ennemy

	redef fun update(dt, world) do
		super
		var player = world.player
		if player != null then
			if player.center.dist2(self.center) < 20.0 * 20.0 then
				shoot(world, player.center)
			end
		end
	end

	fun shoot(world: World, target: Point3d[Float]) do
		var angle = self.center.atan2(target)
		var x_inertia = angle.cos * weapon.power
		var y_inertia = angle.sin * weapon.power
		var bullet = new EnnemyBullet(self.center, 2.0, 2.0, angle, self.weapon, world.player.as(not null))
		bullet.inertia.x = self.inertia.x + x_inertia
		bullet.inertia.y = self.inertia.y + y_inertia
		world.ennemy_bullets.add(bullet)
	end
end
