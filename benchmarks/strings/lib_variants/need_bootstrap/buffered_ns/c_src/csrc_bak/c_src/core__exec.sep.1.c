#include "core__exec.sep.0.h"
/* method exec#Sys#system for (self: Sys, String): Int */
long core__exec___Sys___system(val* self, val* p0) {
long var /* : Int */;
val* var_command /* var command: String */;
char* var1 /* : NativeString */;
long var2 /* : Int */;
long var4 /* : Int */;
var_command = p0;
{
var1 = ((char*(*)(val* self))(var_command->class->vft[COLOR_core__abstract_text__Text__to_cstring]))(var_command); /* to_cstring on <var_command:String>*/
}
{
{ /* Inline exec#NativeString#system (var1) on <var1:NativeString> */
var4 = exec___NativeString_system___impl(var1);
var2 = var4;
goto RET_LABEL3;
RET_LABEL3:(void)0;
}
}
var = var2;
goto RET_LABEL;
RET_LABEL:;
return var;
}
/* method exec#NativeString#system for (self: NativeString): Int */
long core__exec___NativeString___system(char* self) {
long var /* : Int */;
long var1 /* : Int */;
var1 = exec___NativeString_system___impl(self);
var = var1;
goto RET_LABEL;
RET_LABEL:;
return var;
}
