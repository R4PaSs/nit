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

# Web server for Brewnit : a homebrewing helper made with Nit
module brewnit_web

import opts
import privileges
import brewnit_controller

# Avoids a crash when running automatic tests
if "NIT_TESTING".environ == "true" then exit 0

var iface = "localhost:8080"

var vh = new VirtualHost(iface)
vh.routes.add new Route("/dashboard", new BrewnitDashboard)
vh.routes.add new Route("/register", new BrewnitRegister)
vh.routes.add new Route("/login", new BrewnitLogin)
vh.routes.add new Route(null, new BrewnitWelcome)

var fac = new HttpFactory.and_libevent
fac.config.virtual_hosts.add vh

print "Launching server on http://{iface}/"
fac.run
