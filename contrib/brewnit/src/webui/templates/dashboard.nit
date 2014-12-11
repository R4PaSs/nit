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

module dashboard

import boilerplate
import brewnit_model

class DashboardPage
	super BrewnitPage

	var user: nullable User = null is writable

	init do
		header.page_js = """
"""
	end

	redef fun rendering do
		# Do stuff with body before rendering
		var bdy = new Template

		bdy.add "<div class=\"container\">"

		bdy.add """
		<div class="page-header">
		<center><h1>Welcome {{{if user != null then user.login else ""}}} !</h1></center>
		</div>
		"""
		bdy.add """
		<h1>Latest recipes created</h1>"""
		var recipes: Array[Recipe]
		if user != null then
			recipes = user.last_recipes(5)
		end
		bdy.add """<table>
		</table>
		"""
		bdy.add "</div>"
		body = bdy
		super
	end

end
