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

source ./bench_common.sh
source ./bench_plot.sh

# Default number of times a command must be run with bench_command
# Can be overrided with 'the option -n'
count=5

echo "Compiling"

../bin/nitg --global ./strings/concat_bench.nit --make-flags "CFLAGS=\"-g -O2 -DNOBOEHM\""
#../bin/nitg --global ./strings/cct_bench.nit --make-flags "CFLAGS=\"-g -O2 -DNOBOEHM\""

stop=false
while [ "$stop" = false ]; do
	case "$1" in
		-v) verbose=true; shift;;
		-h) usage; exit;;
		-n) count="$2"; shift; shift;;
		--dry) dry_run=true; shift;;
		--fast) fast=true; shift;;
		--html) html="index.html"; echo >"$html" "<html><head></head><body>"; shift;;
		*) stop=true
	esac
done

#echo "*** Benching thresholds ***"

prepare_res concat_ropes.out concat_ropes ropes
for i in `seq 1 "$1"`; do
	echo "String length = $i"
	bench_command $i ropes$i ./concat_bench rope $i $2 "NIT_GC_CHOOSER=large"
done

prepare_res concat_flat.out concat_flat flat
for i in `seq 1 "$1"`; do
	echo "String length = $i"
	bench_command $i flat$i ./concat_bench flat $i $2 "NIT_GC_CHOOSER=large"
done

prepare_res concat_buf.out concat_buf buf_rope
for i in `seq 1 "$1"`; do
	echo "String length = $i"
	bench_command $i buff_rope$i ./concat_bench buffered $i $2 "NIT_GC_CHOOSER=large"
done

plot concat.gnu


#echo "*** Benching general concatenation performance ***"

#prepare_res cct_ropestring.out cct_ropestring cct_ropestring
#for i in `seq 1 "$1"`; do
#	echo "String length = $i"
#	bench_command $i ropestring$i ./cct_bench rope $i $2 "NIT_GC_CHOOSER=large"
#done

#prepare_res cct_flatstring.out cct_flatstring cct_flatstring
#for i in `seq 1 "$1"`; do
#	echo "String length = $i"
#	bench_command $i flatstring$i ./cct_bench flats $i $2 "NIT_GC_CHOOSER=large"
#done

#prepare_res cct_flatbuffer.out cct_flatbuffer cct_flatbuffer
#for i in `seq 1 "$1"`; do
#	echo "String length = $i"
#	bench_command $i flatbuffer$i ./cct_bench flatb $i $2 "NIT_GC_CHOOSER= large"
#done

#plot cct.gnu
