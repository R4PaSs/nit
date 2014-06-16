#!/bin/bash
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

source ./bench_plot.sh

# Default number of times a command must be run with bench_command
# Can be overrided with 'the option -n'
count=10

echo "Compiling"

../bin/nitg --global ./strings/concat_bench.nit --make-flags "CFLAGS=\"-g -O2 -DNOBOEHM\""

#
#
#  $1: title of the command
#  $2: long desription of the command
#  rest: the command to execute
function bench_command()
{
	if [ "$dry_run" = "true" ]; then return; fi
	local title="$1"
	local desc="$2"
	shift
	shift
	if test "$verbose" = true; then outputopts="/dev/stdout"; else outputopts="/dev/null"; fi
	timeout="time.out"
	echo "$title" > "$timeout"
	echo "# $desc" >> "$timeout"
	echo "\$ $@" >> "$timeout"
	echo
	echo "** [$title] $desc **"
	echo " $ $@"

	# Execute the commands $count times
	for i in `seq 1 "$count"`; do
		(ulimit -t 300; /usr/bin/time -f "%U" -o "$timeout" -a "$@") > $outputopts 2>&1 || die "$1: failed"
		echo -n "$i. "
		tail -n 1 "$timeout"
	done

	line=`compute_stats "$timeout"`
	echo "$line ($res)"
	echo $line >> "$res"
	#rm $timeout
}

#
echo "Starting bench"

prepare_res concat_ropes.out concat_ropes ropes
for i in `seq 1 "$1"`; do
	echo "String length = $i"
	bench_command $i ropes$i ./concat_bench rope $i $2
done

prepare_res concat_flat.out concat_flat flat
for i in `seq 1 "$1"`; do
	echo "String length = $i"
	bench_command $i flat$i ./concat_bench flat $i $2
done

plot concat.gnu
