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

redef class App
	#private var fx_fire = new Sound("sounds/fire.mp3")

	redef fun on_create
	do
		super

		# Move the camera to show all the world world in the screen range
		world_camera.reset_height(800.0)
	end

	redef fun update(dt)
	do
	end

	redef fun accept_event(event)
	do
		if event isa QuitEvent then
			exit 0
		else if event isa KeyEvent then

			if event.name == "escape" then
				exit 0
			end
		end

		return false
	end
end
