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

# Basic catalog generator for Nit packages
#
# See: <http://nitlanguage.org/catalog/>
#
# The tool scans packages and generates the HTML files of a catalog.
#
# ## Features
#
# * [X] scan packages and their `.ini`
# * [X] generate lists of packages
# * [X] generate a page per package with the readme and most metadata
# * [ ] link/include/be included in the documentation
# * [ ] propose `related packages`
# * [X] show directory content (a la nitls)
# * [X] gather git information from the working directory
# * [ ] gather git information from the repository
# * [ ] gather package information from github
# * [ ] gather people information from github
# * [X] reify people
# * [X] separate information gathering from rendering
# * [ ] move up information gathering in (existing or new) service modules
# * [X] add command line options
# * [ ] harden HTML (escaping, path injection, etc)
# * [ ] nitcorn server with RESTful API
#
# ## Issues and limitations
#
# The tool works likee the other tools and expects to find valid Nit source code in the directories
#
# * cruft and temporary files will be collected
# * missing source file (e.g. not yet generated by nitcc) will make information
#   incomplete (e.g. invalid module thus partial dependency and metrics)
#
# How to use the tool as the basis of a Nit code archive on the web usable with a package manager is not clear.
module catalog

import md5 # To get gravatar images
import counter # For statistics
import modelize # To process and count classes and methods

redef class MPackage
	# Return the associated metadata from the `ini`, if any
	fun metadata(key: String): nullable String
	do
		var ini = self.ini
		if ini == null then return null
		return ini[key]
	end

	# The consolidated list of tags
	var tags = new Array[String]

	# The list of maintainers
	var maintainers = new Array[Person]

	# The list of contributors
	var contributors = new Array[Person]

	# The date of the most recent commit
	var last_date: nullable String = null

	# The date of the oldest commit
	var first_date: nullable String = null
end

redef class Int
	# Returns `log(self+1)`. Used to compute score of packages
	fun score: Float do return (self+1).to_f.log
end

# A contributor/author/etc.
#
# It comes from git or the metadata
#
# TODO get more things from github by using the email as a key
# "https://api.github.com/search/users?q={email}+in:email"
class Person
	# The name. Eg "John Doe"
	var name: String is writable

	# The email, Eg "john.doe@example.com"
	var email: nullable String is writable

	# Some homepage. Eg "http://example.com/~jdoe"
	var page: nullable String is writable

	# Return a full-featured link to a person
	fun to_html: String
	do
		var res = ""
		var e = name.html_escape
		var page = self.page
		if page != null then
			res += "<a href=\"{page.html_escape}\">"
		end
		var email = self.email
		if email != null then
			var md5 = email.md5.to_lower
			res += "<img src=\"https://secure.gravatar.com/avatar/{md5}?size=20&amp;default=retro\">&nbsp;"
		end
		res += e
		if page != null then res += "</a>"
		return res
	end

	# The standard representation of a person.
	#
	# ~~~
	# var jd = new Person("John Doe", "john.doe@example.com", "http://example.com/~jdoe")
	# assert jd.to_s == "John Doe <john.doe@example.com> (http://example.com/~jdoe)"
	# ~~~
	#
	# It can be used as the input of `parse`.
	#
	# ~~~
	# var jd2 = new Person.parse(jd.to_s)
	# assert jd2.to_s == jd.to_s
	# ~~~
	redef fun to_s
	do
		var res = name
		var email = self.email
		if email != null then res += " <{email}>"
		var page = self.page
		if page != null then res += " ({page})"
		return res
	end

	# Crete a new person from its standard textual representation.
	#
	# ~~~
	# var jd = new Person.parse("John Doe <john.doe@example.com> (http://example.com/~jdoe)")
	# assert jd.name == "John Doe"
	# assert jd.email == "john.doe@example.com"
	# assert jd.page == "http://example.com/~jdoe"
	# ~~~
	#
	# Emails and page are optional.
	#
	# ~~~
	# var jd2 = new Person.parse("John Doe")
	# assert jd2.name == "John Doe"
	# assert jd2.email == null
	# assert jd2.page == null
	# ~~~
	init parse(person: String)
	do
		var name = person
		var email = null
		var page = null
		# Regular expressions are broken, need to investigate.
		# So split manually.
		#
		#var re = "([^<(]*?)(<([^>]*?)>)?(\\((.*)\\))?".to_re
		#var m = (person+" ").search(re)
		#print "{person}: `{m or else "?"}` `{m[1] or else "?"}` `{m[3] or else "?"}` `{m[5] or else "?"}`"
		do
			var sp1 = person.split_once_on("<")
			if sp1.length < 2 then
				break
			end
			var sp2 = sp1.last.split_once_on(">")
			if sp2.length < 2 then
				break
			end
			name = sp1.first.trim
			email = sp2.first.trim
			var sp3 = sp2.last.split_once_on("(")
			if sp3.length < 2 then
				break
			end
			var sp4 = sp3.last.split_once_on(")")
			if sp4.length < 2 then
				break
			end
			page = sp4.first.trim
		end

		init(name, email, page)
	end
end


# The main class of the calatog generator that has the knowledge
class Catalog

	# The modelbuilder
	# used to access the files and count source lines of code
	var modelbuilder: ModelBuilder

	# Packages by tag
	var tag2proj = new MultiHashMap[String, MPackage]

	# Packages by category
	var cat2proj = new MultiHashMap[String, MPackage]

	# Packages by maintainer
	var maint2proj = new MultiHashMap[Person, MPackage]

	# Packages by contributors
	var contrib2proj = new MultiHashMap[Person, MPackage]

	# Dependency between packages
	var deps = new POSet[MPackage]

	# Number of modules by package
	var mmodules = new Counter[MPackage]

	# Number of classes by package
	var mclasses = new Counter[MPackage]

	# Number of methods by package
	var mmethods = new Counter[MPackage]

	# Number of line of code by package
	var loc = new Counter[MPackage]

	# Number of errors
	var errors = new Counter[MPackage]

	# Number of warnings and advices
	var warnings = new Counter[MPackage]

	# Number of warnings per 1000 lines of code (w/kloc)
	var warnings_per_kloc = new Counter[MPackage]

	# Documentation score (between 0 and 100)
	var documentation_score = new Counter[MPackage]

	# Number of commits by package
	var commits = new Counter[MPackage]

	# Score by package
	#
	# The score is loosely computed using other metrics
	var score = new Counter[MPackage]

	# List of known people
	var persons = new HashMap[String, Person]

	# Scan, register and add a contributor to a package
	fun register_contrib(person: String, mpackage: MPackage): Person
	do
		var p = persons.get_or_null(person)
		if p == null then
			var new_p = new Person.parse(person)
			# Maybe, we already have this person in fact?
			p = persons.get_or_null(new_p.to_s)
			if p == null then
				p = new_p
				persons[p.to_s] = p
			end
		end
		var projs = contrib2proj[p]
		if not projs.has(mpackage) then
			projs.add mpackage
			mpackage.contributors.add p
		end
		return p
	end

	# Compute information for a package
	fun package_page(mpackage: MPackage)
	do
		var score = score[mpackage].to_f

		var mdoc = mpackage.mdoc_or_fallback
		if mdoc != null then
			score += 100.0
			score += mdoc.content.length.score
		end


		var tryit = mpackage.metadata("upstream.tryit")
		if tryit != null then
			score += 1.0
		end
		var apk = mpackage.metadata("upstream.apk")
		if apk != null then
			score += 1.0
		end

		var homepage = mpackage.metadata("upstream.homepage")
		if homepage != null then
			score += 5.0
		end
		var maintainer = mpackage.metadata("package.maintainer")
		if maintainer != null then
			score += 5.0
			var person = register_contrib(maintainer, mpackage)
			mpackage.maintainers.add person
			var projs = maint2proj[person]
			if not projs.has(mpackage) then projs.add mpackage
		end
		var license = mpackage.metadata("package.license")
		if license != null then
			score += 5.0
		end

		var browse = mpackage.metadata("upstream.browse")
		if browse != null then
			score += 5.0
		end

		var tags = mpackage.metadata("package.tags")
		var ts = mpackage.tags
		if tags != null then
			for t in tags.split(",") do
				t = t.trim
				if t == "" then continue
				ts.add t
			end
		end
		if ts.is_empty then ts.add "none"
		if tryit != null then ts.add "tryit"
		if apk != null then ts.add "apk"
		for t in ts do
			tag2proj[t].add mpackage
		end
		var cat = ts.first
		cat2proj[cat].add mpackage
		score += ts.length.score

		if deps.has(mpackage) then
			score += deps[mpackage].greaters.length.score
			score += deps[mpackage].direct_greaters.length.score
			score += deps[mpackage].smallers.length.score
			score += deps[mpackage].direct_smallers.length.score
		end

		var contributors = mpackage.contributors
		var more_contributors = mpackage.metadata("package.more_contributors")
		if more_contributors != null then
			for c in more_contributors.split(",") do
				register_contrib(c.trim, mpackage)
			end
		end
		score += contributors.length.to_f

		var mmodules = 0
		var mclasses = 0
		var mmethods = 0
		var loc = 0
		var errors = 0
		var warnings = 0
		# The documentation value of each entity is ad hoc.
		var entity_score = 0.0
		var doc_score = 0.0
		for g in mpackage.mgroups do
			mmodules += g.mmodules.length
			var gs = 1.0
			entity_score += gs
			if g.mdoc != null then doc_score += gs
			for m in g.mmodules do
				var source = m.location.file
				if source != null then
					for msg in source.messages do
						if msg.level == 2 then
							errors += 1
						else
							warnings += 1
						end
					end
				end
				var am = modelbuilder.mmodule2node(m)
				if am != null then
					var file = am.location.file
					if file != null then
						loc += file.line_starts.length - 1
					end
				end
				var ms = gs
				if m.is_test_suite then ms /= 100.0
				entity_score += ms
				if m.mdoc != null then doc_score += ms else ms /= 10.0
				for cd in m.mclassdefs do
					var cs = ms * 0.2
					if not cd.is_intro then cs /= 100.0
					if not cd.mclass.visibility <= private_visibility then cs /= 100.0
					entity_score += cs
					if cd.mdoc != null then doc_score += cs
					mclasses += 1
					for pd in cd.mpropdefs do
						var ps = ms * 0.1
						if not pd.is_intro then ps /= 100.0
						if not pd.mproperty.visibility <= private_visibility then ps /= 100.0
						entity_score += ps
						if pd.mdoc != null then doc_score += ps
						if not pd isa MMethodDef then continue
						mmethods += 1
					end
				end
			end
		end
		self.mmodules[mpackage] = mmodules
		self.mclasses[mpackage] = mclasses
		self.mmethods[mpackage] = mmethods
		self.loc[mpackage] = loc
		self.errors[mpackage] = errors
		self.warnings[mpackage] = warnings
		if loc > 0 then
			self.warnings_per_kloc[mpackage] = warnings * 1000 / loc
		end
		var documentation_score =  (100.0 * doc_score / entity_score).to_i
		self.documentation_score[mpackage] = documentation_score

		#score += mmodules.score
		score += mclasses.score
		score += mmethods.score
		score += loc.score
		score += documentation_score.score

		self.score[mpackage] = score.to_i
	end

	# Collect more information on a package using the `git` tool.
	fun git_info(mpackage: MPackage)
	do
		var ini = mpackage.ini
		if ini == null then return

		# TODO use real git info
		#var repo = ini.get_or_null("upstream.git")
		#var branch = ini.get_or_null("upstream.git.branch")
		#var directory = ini.get_or_null("upstream.git.directory")

		var dirpath = mpackage.root.filepath
		if dirpath == null then return

		# Collect commits info
		var res = git_run("log", "--no-merges", "--follow", "--pretty=tformat:%ad;%aN <%aE>", "--", dirpath)
		var contributors = new Counter[String]
		var commits = res.split("\n")
		if commits.not_empty and commits.last == "" then commits.pop
		self.commits[mpackage] = commits.length
		for l in commits do
			var s = l.split_once_on(';')
			if s.length != 2 or s.last == "" then continue

			# Collect date of last and first commit
			if mpackage.last_date == null then mpackage.last_date = s.first
			mpackage.first_date = s.first

			# Count contributors
			contributors.inc(s.last)
		end
		for c in contributors.sort.reverse_iterator do
			register_contrib(c, mpackage)
		end

	end
end

# Execute a git command and return the result
fun git_run(command: String...): String
do
	# print "git {command.join(" ")}"
	var p = new ProcessReader("git", command...)
	var res = p.read_all
	p.close
	p.wait
	return res
end
