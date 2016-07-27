import gmp::gmp_native

var bg = new NativeGMPBigint.from_int(32)
var bg_str = new NativeGMPBigint.from_string("12497486218957978125642368951290".to_cstring)

print bg
print bg_str

var mul = bg * bg_str

print mul

var div_op = new NativeGMPBigint.from_int(500)
var div_res = mul / div_op

print div_res

print div_res % div_op
