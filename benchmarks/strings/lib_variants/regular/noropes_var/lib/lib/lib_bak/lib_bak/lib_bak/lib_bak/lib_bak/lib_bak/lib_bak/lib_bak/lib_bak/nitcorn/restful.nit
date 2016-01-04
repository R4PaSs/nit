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

# Support module for the `nitrestful` tool and the `restful` annotation
module restful is new_annotation(restful)

import nitcorn
import json::serialization

# Action with `restful` methods
class RestfulAction
	super Action

	redef fun answer(request, truncated_uri) do return new HttpResponse(400)

	# Service to deserialize arguments from JSON
	#
	# Accepts `nullable String` for convenience, but returns `null` when `val == null`.
	#
	# This method is called by the code generated by `nitrestful`.
	# It can be specialized to customize its behavior.
	protected fun deserialize_arg(val: nullable String): nullable Object
	do
		if val == null then return null

		var deserializer = new JsonDeserializer(val)
		if deserializer.errors.not_empty then
			print_error deserializer.errors.join("\n")
			return null
		end

		return deserializer.deserialize
	end
end
