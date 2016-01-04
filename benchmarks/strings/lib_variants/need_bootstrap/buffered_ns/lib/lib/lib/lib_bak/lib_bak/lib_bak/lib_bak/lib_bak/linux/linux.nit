# This file is part of NIT ( http://www.nitlanguage.org ).
#
# Copyright 2014 Alexis Laferrière <alexis.laf@xymus.net>
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

# Implementation of app.nit for the Linux platform
module linux

import app

redef class App
	# Path to the expected location of the asset folder of this program
	#
	# The asset folder should be located relative to the executable at `../assets/`.
	# This value can be redefined to change the expected location.
	var assets_dir: String = sys.program_name.dirname / "../assets/" is lazy

	redef fun setup
	do
		super

		on_create
		on_restore_state
		on_start
		on_resume
	end

	redef fun run
	do
		super

		on_pause
		on_save_state
		on_stop
		on_destroy
	end
end
