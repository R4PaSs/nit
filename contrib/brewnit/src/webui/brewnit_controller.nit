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

# Actions for Brewnit web application
module brewnit_controller

import nitcorn
import sha1
import templates
import brewnit_model

redef class Session
	var user: User
end

# Any kind of brewnit `Action` (serves a request)
abstract class BrewnitAction
	super Action

	# Path to db
	var db_path = "brewnit"

end

# Welcome page for Brewnit
class BrewnitWelcome
	super BrewnitAction

	redef fun answer(request, url) do
		var session = request.session
		if session != null then
			print "Session existing {session.user.login}"
			return (new BrewnitDashboard).answer(request, url)
		end
		var rsp = new HttpResponse(200)
		rsp.body = (new BrewnitHomePage).write_to_string
		rsp.session = request.session
		return rsp
	end
end

class BrewnitRegister
	super BrewnitAction

	redef fun answer(request, url) do
		var get = request.get_args
		var rq = url.split("/")
		if rq.has("confirm") then
			var login = request.string_arg("login")
			var addrss = request.string_arg("mail")
			var pass = request.string_arg("pass")
			var errors = new Array[String]
			if login == null or login == "" then
				login = ""
				errors.add "A username is required"
			end
			if addrss == null or addrss == "" then
				errors.add "An e-mail address is required"
				addrss = ""
			end
			if pass == null or pass == "" then
				errors.add "The password is mandatory"
				pass = ""
			end
			var error = errors.join("\n")
			var usr = new User(login, (pass + "salt1234").sha1_to_s, addrss)
			var db = new BrewnitDB.open(db_path)
			if error == "" then
				usr.commit(db)
				if usr.id == -1 then error = "Login already taken, please choose another one."
			end
			var pg: BrewnitPage
			if error == "" then
				pg = new BrewnitHomePage
			else
				pg = new RegistrationPage
				pg.user = usr
				pg.error = error
			end
			db.close
			var rsp = new HttpResponse(200)
			rsp.session = request.session
			rsp.body = pg.write_to_string
			return rsp
		end
		var pg = new RegistrationPage
		var rsp = new HttpResponse(200)
		rsp.session = request.session
		rsp.body = pg.write_to_string
		return rsp
	end
end

class BrewnitLogin
	super BrewnitAction

	redef fun answer(request, url) do
		var get = request.get_args
		var rq = url.split("/")
		var sess = request.session
		if rq.has("confirm") then
			var login = request.string_arg("login")
			var pass = request.string_arg("pass")
			var errors = new Array[String]
			if login == null or login == "" then
				login = ""
			end
			if pass == null or pass == "" then
				pass = ""
			end
			var error = errors.join("\n")
			var pg: BrewnitPage
			var db = new BrewnitDB.open(db_path)
			var usr = db.load_user(login, (pass + "salt1234").sha1_to_s)
			db.close
			if usr.id == -1 then error = "Wrong combinaison of login/password."
			if error != "" then
				pg = new LoginPage
				pg.user = new User(login, "", "")
				pg.error = error
				var rsp = new HttpResponse(200)
				rsp.session = sess
				rsp.body = pg.write_to_string
				return rsp
			end
			print "User loaded: {usr.login}, id = {usr.id}"
			sess = new Session
			sess.user = usr
			var rsp = new HttpResponse(200)
			pg = new DashboardPage
			rsp.session = sess
			pg.user = usr
			rsp.body = pg.write_to_string
			return rsp
		end
		var pg = new LoginPage
		var rsp = new HttpResponse(200)
		rsp.session = sess
		rsp.body = pg.write_to_string
		return rsp
	end
end

class BrewnitDashboard
	super BrewnitAction

	redef fun answer(request, url) do
		var rsp = new HttpResponse(200)
		var session = request.session
		rsp.session = session
		if session == null then
			print "No session"
			rsp.body = (new BrewnitHomePage).write_to_string
			return rsp
		end
		var dsh = new DashboardPage
		dsh.user = request.session.user
		rsp.body = dsh.write_to_string
		return rsp
	end
end

