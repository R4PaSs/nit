intrude import string

in "C header" `{
#include <stdlib.h>
#include <string.h>
`}

redef class FlatString

	redef fun to_cstring import FlatString.items `{
		char* ns = FlatString_items(recv);
		int sl = strlen(ns);
		char* nns = malloc(sl + 6);
		memcpy(nns, ns, sl);
		char* ds = "Dummy";
		nns[sl+5] = "\0";
		memcpy(nns+sl, ds, 5);
		return;
	`}
end
