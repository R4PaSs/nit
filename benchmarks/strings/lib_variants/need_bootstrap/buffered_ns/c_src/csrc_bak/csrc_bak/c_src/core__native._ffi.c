/*
	Extern implementation of Nit module native
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "core__native._ffi.h"
#ifdef ANDROID
	#include <android/log.h>
	#define PRINT_ERROR(...) (void)__android_log_print(ANDROID_LOG_WARN, "Nit", __VA_ARGS__)
#else
	#define PRINT_ERROR(...) fprintf(stderr, __VA_ARGS__)
#endif
#line 16 "/home/r4pass/nit/lib/core/text/native.nit"


#ifndef NIT_STRING
	#define NIT_STRING
	// A char* wrapper with some facilities to improve runtime
	typedef struct nit_string {
		// Position of the next available byte in items
		long next;
		// Capacity of items
		long capacity;
		// The content of the native string
		char items[];
	} nit_string;
#endif

#ifdef __linux__
	#include <endian.h>
#endif
#ifdef __APPLE__
	#include <libkern/OSByteOrder.h>
	#define be32toh(x) OSSwapBigToHostInt32(x)
#endif

#ifdef __pnacl__
	#define be16toh(val) (((val) >> 8) | ((val) << 8))
	#define be32toh(val) ((be16toh((val) << 16) | (be16toh((val) >> 16))))
#endif
#ifndef be32toh
	#define be32toh(val) betoh32(val)
#endif
double native___NativeString_atof___impl( char* self )
{
#line 115 "/home/r4pass/nit/lib/core/text/native.nit"

 return atof(self); }
long native___NativeString_fetch_4_ffi___impl( char* self, long pos )
{
#line 295 "/home/r4pass/nit/lib/core/text/native.nit"

 return (long)*((uint32_t*)(self+pos)); }
long native___NativeString_fetch_4h_ffi___impl( char* self, long pos )
{
#line 296 "/home/r4pass/nit/lib/core/text/native.nit"

 return (long)be32toh(*((uint32_t*)(self+pos))); }
