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
# limitations under the License

# Welcome page for Brewnit
module welcome

import boilerplate

# Welcome page for Brewnit
class BrewnitHomePage
	super BrewnitPage

	init do
		body = """
		<div class="page-header">
		<h1 class="text-center">Welcome to Brewnit!</h1>
			</div>
			<p class="text-center">
				<p class="text-center">Brewnit is a free (as in free software), easy-to-use, homebrewing helper.</p>
				<p class="text-center">It will help you plan recipes and brew multiple iterations of each recipe.</p>
				<p class="text-center">While the tool is not magical (i.e. it will still require a bit of knowledge from your part on how to brew beer) it eases the process a lot</p>
				<p class="text-center">You can start using it right now by registering and start creating your own recipes and brew them!</p>
				<p class="text-center">
				<form action="register">
				<button type="submit" class="btn btn-lg center-block btn-primary">Register</button>
				</form>
				</p>
				<p class="text-center">
				<form action="login">
				<button type="submit" class="btn btn-lg center-block btn-success">Login</button>
				</form>
				</p>
			</p>
"""
	end

end
