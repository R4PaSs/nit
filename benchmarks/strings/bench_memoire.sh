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

source ../bench_common.sh
source ../bench_plot.sh

# Default number of times a command must be run with bench_command
# Can be overrided with 'the option -n'
count=5

benches="iteration
concat
substring
index
compiler"

maxlen=false
curr_maxlen=64

function usage()
{
	echo "run_bench: [options]* bench_name args"
	echo ""
	echo "Options:"
	echo "  -v: verbose mode"
	echo "  -n count: number of execution for each bar (default: $count)"
	echo "  -h: this help"
	echo "  --head-only: do not try to pass benchmarks on variants"
	echo "  --maxlen: benching maxlen from 1 to 4096 on each power of two for current bench"
	echo ""
	echo "Benches : "
	echo "  index: indexed access benchmark"
	echo "    - usage : index loops strlen_min strlen_inc strlen_max"
	echo "  concat: string concatenation benchmark"
	echo "    - usage : concat loops ccts min_strlen strlen_inc max_strlen"
	echo "  iteration: iteration benchmark"
	echo "    - usage : iteration loops strlen_min strlen_inc strlen_max"
	echo "  substring: substring benchmark"
	echo "    - usage : substring loops strlen_min strlen_inc strlen_max"
	echo "  compiler: compiler benchmark (sg means semi-global, else separate)"
	echo "    - usage : compiler [sg]"
}

function bench_index()
{
	if [ $# -lt 4 ]; then
		echo "Wrong arguments for benchmark index."
		usage
		exit
	fi

	echo "Generating executable index_bench for variant $variant";
	nitc --global index_bench.nit

	bench_indexed_variant $1 $2 $3 $4

	rm index_bench
}

# $1: loops
# $2: strlen min
# $3: strlen inc
# $4: strlen max
function bench_indexed_variant()
{
	tmp="${variant}"
	prepare_res_lines "out/index/$tmp.out" "$variant" "$variant"
	for i in `seq 1 ${#strlens[@]}`; do
		idx="${strlens[$i - 1]}"
		bench_command $idx "$variant" ./index_bench -m string --loops $1 --strlen $idx
	done
}

# $1: loops
# $2: strlen min
# $3: strlen inc
# $4: strlen max
function bench_index_maxlen()
{
	tmp="${variant}"
	prepare_res_lines "out/index/$tmp.out" "$variant" "$variant"
	echo "Generating executable index_bench for variant $variant"
	nitc --global index_bench.nit -D maxlen=$curr_maxlen
	for i in `seq 1 ${#maxlens[@]}`; do
		idx="${maxlens[$i - 1]}"
		bench_command $idx "$variant" ./index_bench -m string --loops $1 --strlen $idx
	done
}

function bench_concat()
{
	if [ $# -lt 5 ]; then
		echo "Wrong arguments for benchmark concat."
		usage
		exit
	fi

	echo "Generating executable chain_concat for variant $variant"
	nitc --global chain_concat.nit

	bench_concat_variant $1 $2 $3 $4 $5

	rm chain_concat
}

# $1: loops
# $2: concatenations
function bench_concat_variant()
{
	tmp="${variant}"
	prepare_res_lines "out/concat/$tmp.out" "$variant" "$variant"
	for i in `seq 1 ${#strlens[@]}`; do
		idx="${strlens[$i - 1]}"
		bench_command $idx "$variant" ./chain_concat -m string --loops $1 --strlen $idx --ccts $2
	done
}

# $1: loops
# $2: concatenations
function bench_concat_maxlen()
{
	tmp="${variant}"
	prepare_res_lines "out/concat/$tmp.out" "$variant" "$variant"
	echo "Generating executable chain_concat for variant $variant"
	nitc --global chain_concat.nit -D maxlen=$curr_maxlen
	for i in `seq 1 ${#maxlens[@]}`; do
		idx="${maxlens[$i - 1]}"
		bench_command $idx "$variant" ./chain_concat -m string --loops $1 --strlen $idx --ccts $2
	done
}

function bench_iteration()
{
	if [ $# -lt 4 ]; then
		echo "Wrong arguments for benchmark iteration."
		usage
		exit
	fi
	echo "Generating executable iteration_bench for variant $variant"
	nitc --global iteration_bench.nit

	bench_iterate_variant "index" $1 $2 $3 $4

	rm iteration_bench
}

# $1: iterator or index
# $2: loops
function bench_iterate_variant()
{
	tmp="${variant}"
	prepare_res_lines "out/iteration/$tmp.out" "$variant" "$variant"
	for i in `seq 1 ${#strlens[@]}`; do
		idx="${strlens[$i - 1]}"
		bench_command $idx "$variant" ./iteration_bench -m string --iter-mode $1 --loops $2 --strlen $idx
	done
}

# $1: iterator or index
# $2: loops
function bench_iteration_maxlen()
{
	tmp="${variant}"
	prepare_res_lines "out/iteration/$tmp.out" "$variant" "$variant"
	echo "Generating executable iteration_bench for variant $variant"
	nitc --global iteration_bench.nit -D maxlen=$curr_maxlen
	for i in `seq 1 ${#maxlens[@]}`; do
		idx="${maxlens[$i - 1]}"
		bench_command $idx "$variant" ./iteration_bench -m string --iter-mode index --loops $1 --strlen $idx
	done
	rm iteration_bench
}

function bench_substring()
{
	if [ $# -lt 4 ]; then
		echo "Wrong arguments for benchmark substring."
		usage
		exit
	fi
	echo "Generating executable substr_bench for variant $variant"
	nitc --global substr_bench.nit

	bench_substring_variant $1 $2 $3 $4

	rm substr_bench
}

# $1: loops
function bench_substring_variant()
{
	tmp="${variant}"
	prepare_res_lines "out/substring/$tmp.out" "$variant" "$variant"
	for i in `seq 1 ${#strlens[@]}`; do
		idx="${strlens[$i - 1]}"
		bench_command $idx "$variant" ./substr_bench -m string --loops $1 --strlen $idx
	done
}

# $1: loops
# $2: strlen min
# $3: strlen increment
# $4: strlen max
function bench_substring_maxlen()
{
	tmp="${variant}"
	echo "Generating executable substr_bench for variant $variant"
	nitc --global substr_bench.nit -D maxlen=$curr_maxlen
	prepare_res_lines "out/substring/$tmp.out" "$variant" "$variant"
	for i in `seq 1 ${#maxlens[@]}`; do
		idx="${maxlens[$i - 1]}"
		bench_command $idx "$variant" ./substr_bench -m string --loops $1 --strlen $idx
	done
	rm substr_bench
}

function bench_compiler()
{
	nitc="nitc --separate"
	if [ "$1" = "sg" ]; then
		nitc="nitc --semi-global"
	fi
	prepare_res "out/compiler/$variant.out" "$variant" "$variant"

	echo "Pre-compiling nitc"
	# Do it four times before bench to have stable times when generating C
	$nitc ../../src/nitc.nit -o ../../bin/nitc
	echo "nitc (1/4)"
	$nitc ../../src/nitc.nit -o ../../bin/nitc
	echo "nitc (2/4)"
	$nitc ../../src/nitc.nit -o ../../bin/nitc
	echo "nitc (3/4)"
	$nitc ../../src/nitc.nit -o ../../bin/nitc
	echo "nitc (4/4)"

	bench_command nitc "$variant" $nitc ../../src/nitc.nit

	rm nitc
}

function bench_compiler_maxlen()
{
	nitc="nitc --separate"
	if [ "$1" = "sg" ]; then
		nitc="nitc --semi-global"
	fi
	prepare_res "out/compiler/$variant.out" "$variant" "$variant"

	echo "Pre-compiling nitc"
	# Do it four times before bench to have stable times when generating C
	$nitc ../../src/nitc.nit -o ../../bin/nitc -D maxlen=$curr_maxlen
	echo "nitc (1/4)"
	$nitc ../../src/nitc.nit -o ../../bin/nitc -D maxlen=$curr_maxlen
	echo "nitc (2/4)"
	$nitc ../../src/nitc.nit -o ../../bin/nitc -D maxlen=$curr_maxlen
	echo "nitc (3/4)"
	$nitc ../../src/nitc.nit -o ../../bin/nitc -D maxlen=$curr_maxlen
	echo "nitc (4/4)"

	bench_command nitc "$variant" $nitc ../../src/nitc.nit -D maxlen=$curr_maxlen

	rm nitc
}

function prepare_compiler()
{
	cd ../../c_src
	rm nitc
	make clean
	cd ../src
	./ncall.sh
	mv nitc.good ../bin/nitc
	cd ../benchmarks/strings
}

function setup_lib()
{
	rm -rf ../../lib
	if [ "$1" = "Chaînes bufferisées" ]; then
		echo "Doing buffered"
		rm -rf ../../c_src
		rm -rf ../../src
		mv lib_variants/need_bootstrap/buffered_ns/c_src ../../c_src
		mv lib_variants/need_bootstrap/buffered_ns/lib ../../lib
		mv lib_variants/need_bootstrap/buffered_ns/src ../../src
		prepare_compiler
	elif [ "$1" = "Plates uniquement" ]; then
		echo "Doing flat only"
		mv lib_variants/regular/noropes_var/ ../../lib
	elif [ "$1" = "Cordes uniquement" ]; then
		echo "Doing ropes only"
		mv lib_variants/regular/fullrope_var/ ../../lib
	elif [ "$1" = "Sous-chaînage linéaire" ]; then
		echo "Doing constant substring"
		mv lib_variants/regular/linear_sub_var/ ../../lib
	fi
}

function restore_lib()
{
	git stash
}

stop=false
while [ "$stop" = false ]; do
	case "$1" in
		--maxlen) maxlen=true; shift;;
		-v) verbose=true; shift;;
		-h) usage; exit;;
		-n) count="$2"; shift; shift;;
		*) stop=true
	esac
done

if [ $# -lt 1 ]; then
	usage;
	exit;
fi

isok=false
for i in $benches; do
	if [ $1 = $i ]; then
		isok=true;
	fi
done
if [ "$isok" = false ]; then
	usage;
	exit;
fi

bench=$1;
shift;

mkdir -p out

if [ -d out/$bench ]; then
	rm -rf out/$bench
fi
mkdir -p out/$bench

declare -a maxlens=(16 32 64 128 256 512 1024 2048 4096)

declare -a strlens=(8 16 32 64 128 256 396 512 768 1024)

if [ "$maxlen" = "true" ]; then
	for i in `seq 1 ${#maxlens[@]}`; do
		echo "Bench ${bench} with maxlen ${maxlens[$i - 1]}"
		curr_maxlen="${maxlens[$i - 1]}"
		variant="Mélange cordes plates - ${curr_maxlen}"
		echo $curr_maxlen
		bench_${bench}_maxlen $@
	done
	if [ "$bench" = "compiler" ]; then
		plot out/$bench/$bench.gnu
	else
		plot_lines out/$bench/$bench.gnu
	fi
	exit 0
fi

declare -a variant_names=('Plates uniquement' 'Cordes uniquement' 'Sous-chaînage linéaire' 'Chaînes bufferisées')

variant='Mélange cordes plates'
echo "Executing bench ${bench} for variant ${variant}"
bench_$bench $@

for script in `seq 1 ${#variant_names[@]}`; do
	variant="${variant_names[$script - 1]}"
	echo "Executing bench ${bench} for variant ${variant}"
	setup_lib "$variant"
	bench_$bench "$@"
	restore_lib "$variant"
done;

if [ "$bench" = "compiler" ]; then
	plot out/$bench/$bench.gnu
else
	plot_lines out/$bench/$bench.gnu
fi
