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

var s = "word]]> 12 34.5 word 33.r"
var reader = new StringReader(s)

while not reader.eof do
	print "Read until ]]> = {reader.scanner.read_until("]]>")}"
	print "Read int = {reader.scanner.read_int}"
	print "Read float = {reader.scanner.read_float}"
	print "Read word = {reader.scanner.read_word}"
	print "Read next 4 chars = \"{reader.read(4)}\""
end
