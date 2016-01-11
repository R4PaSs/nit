function bench_regular()
{
	rm -rf out/compiler_sep_vars
	rm -rf out/compiler_sg_vars
	rm -rf out/concat_vars
	rm -rf out/index_vars
	rm -rf out/substring_vars
	rm -rf out/iteration_vars
	git stash
	./bench_memoire.sh compiler
	mv out/compiler/ out/compiler_sep_vars
	git stash
	./bench_memoire.sh compiler sg
	mv out/compiler out/compiler_sg_vars
	git stash
	./bench_memoire.sh concat 5000000 10 8 8 1024
	mv out/concat out/concat_vars
	git stash
	./bench_memoire.sh index 50000000 8 8 1024
	mv out/index out/index_vars
	git stash
	./bench_memoire.sh substring 10000000 8 8 1024
	mv out/substring out/substring_vars
	git stash
	./bench_memoire.sh iteration 1000000 8 8 1024
	mv out/iteration out/iteration_vars
	git stash
	cd ../json
	./bench_json.sh
	cd ../strings
}

function bench_maxlen()
{
	rm -rf out/compiler_sep_maxlen
	rm -rf out/compiler_sg_maxlen
	rm -rf out/concat_maxlen
	rm -rf out/index_maxlen
	rm -rf out/substring_maxlen
	rm -rf out/iteration_maxlen
	./bench_memoire.sh --maxlen compiler
	mv out/compiler/ out/compiler_sep_maxlen
	./bench_memoire.sh --maxlen compiler sg
	mv out/compiler out/compiler_sg_maxlen
	./bench_memoire.sh --maxlen concat 5000000 10
	mv out/concat out/concat_maxlen
	./bench_memoire.sh --maxlen index 50000000
	mv out/index out/index_maxlen
	./bench_memoire.sh --maxlen substring 1000000
	mv out/substring out/substring_maxlen
	./bench_memoire.sh --maxlen iteration 1000000
	mv out/iteration out/iteration_maxlen
}

bench_regular
bench_maxlen
