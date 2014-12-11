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

# Contains the main components of a webpage for Brewnit
module boilerplate

import template

# Header for a Brewnit page
class BrewnitHeader
	super Template

	# Javascript code that is included in the `BrewnitPage`
	var page_js = "" is writable

	redef fun rendering do
		add """
<!DOCTYPE html>
<html>
<head>
	<title>Brewnit - A homebrewer's friend</title>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">
	<script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.min.js"></script>
	<script src="//netdna.bootstrapcdn.com/bootstrap/3.0.0/js/bootstrap.min.js"></script>
	<script>
		{{{page_js}}}
	</script>
	<style>
		.menu {
			background-color: #e3b72e;
			background-repeat: repeat-x;
			color: white;
		}
		.navbar-brand{
			color: white;
		}
		.navbar-brand:hover{
			color: #EEEEEE;
		}
		.navbar-nav{
			color: white;
		}
		.navbar-nav: hover{
			background-color: #e3b72e;
			color: white;
		}
	</style>
</head>
<body>
<nav class="menu" role="navigation">
	<div class="container">
		<div class="navbar-header">
			<a class="navbar-brand" href="/" >Home</a>
		</div>
	</div>
</nav>
<div class="container">
"""
	end

end

# Footer for a Brewnit page
class BrewnitFooter
	super Template

	redef fun rendering do
		add """
</div>
</body>
<div class="footer">
	<div class="well well-sm">
		<p class="text-muted text-center">
			Brewnit, a homebrewer's friend.
		</p>
		<p class="text-muted text-center">
			Proudly powered by <a href="http://nitlanguage.org/">Nit</a>!
		</p>
	</div>
</div>
</html>
"""
	end

end

# Any Brewnit page that contains the header, body and footer.
class BrewnitPage
	super Template

	var header = new BrewnitHeader

	var body: Streamable = "" is writable

	var footer = new BrewnitFooter

	redef fun rendering do
		add header
		add body
		add footer
	end

end
