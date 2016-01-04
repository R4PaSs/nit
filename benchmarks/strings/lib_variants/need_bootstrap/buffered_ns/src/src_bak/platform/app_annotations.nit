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

# Annotations to gather metadata on `app.nit` projects
module app_annotations

private import parser_util
import modelize
import literal
import semantize
private import annotation

# Metadata associated to an `app.nit` project
class AppProject
	# Pretty name of the resulting application
	var name: String = mainmodule.first_real_mmodule.name is lazy

	# Short project name used in `namespace` and configuration files
	var short_name: String = mainmodule.name.replace("-", "_") is lazy

	# Namespace/package used to identify the application
	var namespace = "org.nitlanguage.{short_name}" is lazy

	# Version of the application
	var version = "0.1"

	# Numerical version code of the application
	var version_code: Int is lazy do

		# Get the date and time (down to the minute) as string
		var local_time = new Tm.localtime
		var local_time_s = local_time.strftime("%y%m%d%H%M")
		return local_time_s.to_i
	end

	private var modelbuilder: ModelBuilder
	private var mainmodule: MModule

	init
	do
		var annot = modelbuilder.lookup_annotation_on_modules("app_name", mainmodule)
		if annot != null then
			var val = annot.arg_as_string(modelbuilder)
			if val != null then name = val
		end

		annot = modelbuilder.lookup_annotation_on_modules("app_version", mainmodule)
		if annot != null then version = annot.as_version(modelbuilder)

		annot = modelbuilder.lookup_annotation_on_modules("app_namespace", mainmodule)
		if annot != null then
			var val = annot.arg_as_string(modelbuilder)
			if val != null then namespace = val
		end

		modelbuilder.toolcontext.check_errors
	end

	redef fun to_s do return """
name: {{{name}}}
namespace: {{{namespace}}}
version: {{{version}}}"""
end

redef class AAnnotation
	# Returns a version string (example: "1.5.6b42a7c") from an annotation `version(1, 5, git_revision)`.
	#
	# The user can enter as many fields as needed. The call to `git_revision` will be replaced by the short
	# revision number. If the working tree is dirty, it will append another field with "d" for dirty.
	private fun as_version(modelbuilder: ModelBuilder): String
	do
		var version_fields = new Array[Object]

		var args = n_args
		if args.length < 1 then
			modelbuilder.error(self, "Syntax Error: `{name}` expects at least one argument.")
			return ""
		else
			for arg in args do
				var format_error = "Syntax Eror: `{name}` expects its arguments to be of type Int or a call to `git_revision`."

				var value
				value = arg.as_int
				if value != null then
					version_fields.add value
					continue
				end

				value = arg.as_string
				if value != null then
					version_fields.add value
				end

				value = arg.as_id
				if value == "git_revision" then
					# Get Git short revision
					var proc = new ProcessReader("git", "rev-parse", "--short", "HEAD")
					proc.wait
					assert proc.status == 0
					var lines = proc.read_all
					var revision = lines.split("\n").first

					# Is it dirty?
					# If not, the return of `git diff --shortstat` is an empty line
					proc = new ProcessReader("git", "diff-index", "--quiet", "HEAD")
					proc.wait
					var dirty = proc.status != 0
					if dirty then revision += ".d"

					version_fields.add revision
					continue
				end

				modelbuilder.error(self, format_error)
				return ""
			end
		end

		return version_fields.join(".")
	end
end
