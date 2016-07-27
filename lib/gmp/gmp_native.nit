# Support of big numbers with GMP
module gmp_native is ldflags("-lgmp")

in "C" `{
#include <gmp.h>
`}

extern class NativeGMPBigint `{ mpz_t* `}
	super Numeric

	redef type OTHER: NativeGMPBigint

	# Creates a new GMPBigint with default value (i.e. 0)
	new `{
		mpz_t* tmp = calloc(sizeof(mpz_t), 1);
		mpz_init(*tmp);
		return tmp;
	`}

	new from_int(i: Int) `{
		mpz_t* tmp = calloc(sizeof(mpz_t), 1);
		mpz_init_set_si(*tmp, i);
		return tmp;
	`}

	# Creates a new GMPBigint from the string given in parameter.
	#
	# The rules for the base it is specified in follow those of GMP.
	# I.E. if the prefix is:
	#
	# * 0x or 0X, it is considered a base 16 number
	# * 0b or 0B, it is considered a base 2 number
	# * 0, it is considered a base 8 number
	# * Otherwise, it is considered a base 10 number
	new from_string(ns: NativeString) `{
		mpz_t* tmp = calloc(sizeof(mpz_t), 1);
		mpz_init_set_str(*tmp, ns, 0);
		return tmp;
	`}

	# Changes value of `self` using `ns`
	fun set_value_from_str(ns: NativeString) `{
		mpz_set_str(*self, ns, 0);
	`}

	redef fun +(o) `{
		mpz_t* res = calloc(sizeof(mpz_t), 1);
		mpz_add(*res, *self, *o);
		return res;
	`}

	redef fun -(o) `{
		mpz_t* res = calloc(sizeof(mpz_t), 1);
		mpz_sub(*res, *self, *o);
		return res;
	`}

	redef fun - `{
		mpz_t* res = calloc(sizeof(mpz_t), 1);
		mpz_neg(*res, *self);
		return res;
	`}

	redef fun *(o) `{
		mpz_t* res = calloc(sizeof(mpz_t), 1);
		mpz_mul(*res, *self, *o);
		return res;
	`}

	redef fun /(o) `{
		mpz_t* res = calloc(sizeof(mpz_t), 1);
		mpz_tdiv_q(*res, *self, *o);
		return res;
	`}

	fun %(o: NativeGMPBigint): NativeGMPBigint `{
		mpz_t* res = calloc(sizeof(mpz_t), 1);
		mpz_tdiv_r(*res, *self, *o);
		return res;
	`}

	redef fun to_i `{ return mpz_get_si(*self); `}

	redef fun to_f `{ return mpz_get_d(*self); `}
	
	redef fun to_b do return to_i.to_b

	fun to_s_size: Int `{ return gmp_snprintf(NULL, 0, "%Zd", *self); `}

	fun append_native(ns: NativeString, sz: Int) `{ gmp_snprintf(ns, sz + 1, "%Zd", *self); `}

	redef fun to_s do
		var ln = to_s_size
		var ns = new NativeString(ln + 1)
		append_native(ns, ln)
		return ns.to_s_with_length(ln)
	end

	redef fun zero do return new NativeGMPBigint

	fun abs: NativeGMPBigint `{
		mpz_t* res = calloc(sizeof(mpz_t), 1);
		mpz_abs(*res, *self);
		return res;
	`}
end
