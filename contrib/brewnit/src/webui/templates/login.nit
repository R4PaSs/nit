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

module login

import boilerplate
import brewnit_model

class LoginPage
	super BrewnitPage

	var user: nullable User = null is writable

	var error: nullable String = null is writable

	init do
		header.page_js = """
"""
	end

	redef fun rendering do
		# Do stuff with body before rendering
		var bdy = new Template

		bdy.add "<div class=\"container\">"
		bdy.add "<center>"

		if error != null then
			bdy.add "<p></p>"
			bdy.add """<div class="alert alert-danger alert-dismissible" role="alert">
				<button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
				"""
			bdy.add error.as(not null)
			bdy.add "</div>"
		end

		bdy.add """
		<div class="page-header">
			<center><h1>Login</h1></center>
		</div>
		"""
		bdy.add """<form class="form-horizontal" action="/login/confirm" method="POST" role="form">
			<div class = "form-group">
				<label for="login" class="col-sm-4 control-label">Username</label>
				<div class="col-sm-8">
					<input name="login" id="login" type="text" class="form-control" placeholder="Username" value="{{{if user != null then user.login else ""}}}">
				</div>
			</div>
			<div class = "form-group">
				<label for="pass" class="col-sm-4 control-label">Password</label>
				<div class="col-sm-8">
					<input name="pass" id="pass" type="password" class="form-control" placeholder="" value="">
				</div>
			</div>
			<div class="form-group">
				<button type="submit" class="btn btn-lg btn-success">Login</button>
			</div>
		</form>
		</center>
		</div>
"""
		body = bdy
		super
	end

end
