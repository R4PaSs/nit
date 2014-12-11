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

# Model for the data of Brewnit
module brewnit_model

import sqlite3
import sha1
import model

# A SQLiteDB object for `Brewnit`
class BrewnitDB
	super Sqlite3DB

	init open(x) do
		if not x.to_s.file_exists then
			super
			create_db
			return
		end
		super
	end

	# Creates the tables and triggers for Brewnit (SQLite3 DB)
	fun create_db do
		assert create_table("IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, login TEXT, password CHAR(40), mail TEXT);") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS equipments(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, capacity REAL, estimated_efficiency REAL, trub_losses REAL, boil_loss_rate REAL);") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS hops(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT);") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS fermentables(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, colour REAL, potential REAL, diastatic_power REAL)") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS ferm_types(id INTEGER PRIMARY KEY, name TEXT)") else
			print error or else "?"
		end
		assert execute("INSERT INTO ferm_types(id, name) VALUES(0, 'Grain')") else
			print error or else "?"
		end
		assert execute("INSERT INTO ferm_types(id, name) VALUES(1, 'Extract')") else
			print error or else "?"
		end
		assert execute("INSERT INTO ferm_types(id, name) VALUES(2, 'Sugar')") else
			print error or else "?"
		end
		assert execute("INSERT INTO ferm_types(id, name) VALUES(3, 'Adjunct')") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS hop_types(id INTEGER PRIMARY KEY, name TEXT)") else
			print error or else "?"
		end
		assert execute("INSERT INTO hop_types(id, name) VALUES(0, 'Leaf')") else
			print error or else "?"
		end
		assert execute("INSERT INTO hop_types(id, name) VALUES(1, 'Pellet')") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS hop_uses(id INTEGER PRIMARY KEY, name TEXT)") else
			print error or else "?"
		end
		assert execute("INSERT INTO hop_uses(id, name) VALUES(0, 'Boil')") else
			print error or else "?"
		end
		assert execute("INSERT INTO hop_uses(id, name) VALUES(1, 'Dry Hop')") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS yeast_manufacturers(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT);") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS yeasts(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, flocculation INTEGER, manufacturer INTEGER, FOREIGN KEY(manufacturer) REFERENCES yeast_manufacturers(id));") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS recipes(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, volume REAL, yeast INTEGER, mash_temperature REAL, user INTEGER, FOREIGN KEY(yeast) REFERENCES yeasts(id), FOREIGN KEY(user) REFERENCES users(id));") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS brews(id INTEGER PRIMARY KEY AUTOINCREMENT, user INTEGER, recipe INTEGER, equipment INTEGER, og REAL, fg REAL, FOREIGN KEY(recipe) REFERENCES recipes(id), FOREIGN KEY(equipment) REFERENCES equipments(id), FOREIGN KEY(user) REFERENCES users(id));") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS recipe_ferms(recipe INTEGER, fermentable INTEGER, quantity REAL, FOREIGN KEY(recipe) REFERENCES recipes(id), FOREIGN KEY(fermentable) REFERENCES fermentables(id));") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS recipe_hops(recipe INTEGER, hop INTEGER, quantity REAL, aa REAL, use INTEGER, FOREIGN KEY(recipe) REFERENCES recipes(id), FOREIGN KEY(hop) REFERENCES hops(id), FOREIGN KEY(use) REFERENCES hop_uses(id));") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS recipe_yeasts(recipe INTEGER, yeast INTEGER, quantity REAL, FOREIGN KEY(recipe) REFERENCES recipes(id), FOREIGN KEY(yeast) REFERENCES yeasts(id));") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS brew_ferms(brew INTEGER, fermentable INTEGER, quantity REAL, FOREIGN KEY(brew) REFERENCES brews(id), FOREIGN KEY(fermentable) REFERENCES fermentables(id));") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS brew_hops(brew INTEGER, hop INTEGER, quantity REAL, aa REAL, use INTEGER, FOREIGN KEY(brew) REFERENCES brews(id), FOREIGN KEY(hop) REFERENCES hops(id), FOREIGN KEY(use) REFERENCES hop_uses(id));") else
			print error or else "?"
		end
		assert create_table("IF NOT EXISTS brew_yeasts(brew INTEGER, yeast INTEGER, quantity REAL, FOREIGN KEY(brew) REFERENCES brews(id), FOREIGN KEY(yeast) REFERENCES yeasts(id));") else
			print error or else "?"
		end
		#NOTE: The following triggers could be replaced by ON DELETE CASCADE clauses
		# Thing is, SQLite does not seem to support those operations
		# (well, not by default, it seems we must re-compile the lib
		# to support it). So, well, let's just create triggers heh.
	end

	# Loads a user from DB using its login and password, salted and hashed
	fun load_user(login, pass: String): User do
		var res = select("id, login, password, mail FROM users WHERE login = {login.html_escape.to_sql_string} AND password = {pass.to_sql_string};")
		if res == null then
			print error or else "?"
			return new User("","","")
		end
		var infos = res.iterator.to_a
		if infos.length == 0 then
			print "Cannot find user/pass combination {login.html_escape.to_sql_string}/{pass}"
			return new User("","","")
		end
		if infos.length > 1 then
			print "Duplicate entries for user {login.html_escape.to_sql_string} !"
			return new User("","","")
		end
		var stmt = res.iterator.item
		var usr = new User(stmt[1].to_s, stmt[2].to_s, stmt[3].to_s)
		usr.id = stmt[0].to_i
		return usr
	end

	fun load_recipe(id: Int): Recipe do
		var rec = select("* FROM recipes WHERE id = {id};")
	end

	redef fun select(s) do
		print "Executing select SELECT {s}"
		return super
	end

	redef fun execute(s) do
		print "Executing request {s}"
		return super
	end
end

# Any kind of Object that can be dumped into or loaded from the Database
class DBObject
	fun commit(db: BrewnitDB) is abstract
end

# Any user of Brewnit
class User
	super DBObject
	
	# Id of the user in Database, defaults to -1 if not created yet
	var id: Int = -1

	# Login of the user
	var login: String

	# The password for the user, salted and hashed as SHA-1
	var pass: String
	
	# E-mail address of the user
	var mail: String

	# Get the latest recipes for the user
	fun last_recipes(limit: Int, db: BrewnitDB): Array[Recipe] do
		var req = db.select("id FROM recipes WHERE user={id} ORDER BY id DESC LIMIT {limit};")
		var ret = new Array[Recipe]
		for i in req.iterator do
			ret.push db.load_recipe(i[0])
		end
		return ret
	end

	redef fun commit(db: BrewnitDB) do
		if login == "" then
			print "Login cannot be void"
			return
		end
		if pass == "" then
			print "Password cannot be void"
			return
		end
		if mail == "" then
			print "Mail cannot be void"
			return
		end
		if id == -1 then
			var usrs = db.select("id FROM users WHERE login = {login.html_escape.to_sql_string};")
			if usrs != null then
				var us = usrs.iterator.to_a
				if us.length > 0 then
					print "Found users {us}"
					print "User {login.html_escape.to_sql_string} already existing."
					print db.error or else "?"
					return
				end
			end
			var res = db.execute("INSERT INTO users(login, password, mail) VALUES ({login.html_escape.to_sql_string}, {pass.html_escape.to_sql_string}, {mail.html_escape.to_sql_string});")
			if not res then
				print "Cannot create user {login}"
				print db.error or else "?"
				return
			end
			id = db.last_insert_rowid
			return
		end
		var res = db.execute("UPDATE users SET login={login.html_escape.to_sql_string}, pass={pass.html_escape.to_sql_string}, mail = {mail.html_escape.to_sql_string} WHERE id={id};")
		if not res then
			print "Cannot update user {login}"
			print db.error or else "?"
		end
	end
end

redef class Recipe
	super DBObject

	# Since a Brew and a Recipe have no fundamental difference model-wise,
	# a flag will be used to differentiate between the two-entities on the
	# DB side.
	var is_brew = false

	init from_db(id: Int, db: BrewnitDB, is_brew: Bool) do
		var dbobj: nullable Statement
		if is_brew then
			dbobj = db.select("* FROM brews WHERE id={id};")
		else
			dbobj = db.select("* FROM recipes WHERE id={id};")
		end
		if dbobj == null then return
	end

	# Brew is a functional equivalent to clone, with is_brew set to true.
	#fun brew: Recipe do
	#	var ret = new Recipe
	#	ret.is_brew = true
	#	return ret
	#end
end

redef class Hop
	super DBObject

	init from_db(id: Int, db: BrewnitDB) do
		db.select("* FROM hops WHERE id={id};")
	end
end
