#include "nitc__nith.main.0.h"
struct nitni_global_ref_list_t *nitni_global_ref_list;
void initialize_nitni_global_refs() {
	nitni_global_ref_list = (struct nitni_global_ref_list_t*)nit_alloc(sizeof(struct nitni_global_ref_list_t));
	nitni_global_ref_list->head = NULL;
	nitni_global_ref_list->tail = NULL;
}

void nitni_global_ref_add( struct nitni_ref *ref ) {
	if ( nitni_global_ref_list->head == NULL ) {
		nitni_global_ref_list->head = ref;
		ref->prev = NULL;
	} else {
		nitni_global_ref_list->tail->next = ref;
		ref->prev = nitni_global_ref_list->tail;
	}
	nitni_global_ref_list->tail = ref;

	ref->next = NULL;
}

void nitni_global_ref_remove( struct nitni_ref *ref ) {
	if ( ref->prev == NULL ) {
		nitni_global_ref_list->head = ref->next;
	} else {
		ref->prev->next = ref->next;
	}

	if ( ref->next == NULL ) {
		nitni_global_ref_list->tail = ref->prev;
	} else {
		ref->next->prev = ref->prev;
	}
}

extern void nitni_global_ref_incr( struct nitni_ref *ref ) {
	if ( ref->count == 0 ) /* not registered */
	{
		/* add to list */
		nitni_global_ref_add( ref );
	}

	ref->count ++;
}

extern void nitni_global_ref_decr( struct nitni_ref *ref ) {
	if ( ref->count == 1 ) /* was last reference */
	{
		/* remove from list */
		nitni_global_ref_remove( ref );
	}

	ref->count --;
}

#include <signal.h>
#ifndef NO_STACKTRACE
#define UNW_LOCAL_ONLY
#include <libunwind.h>
#include "c_functions_hash.h"
#endif
int glob_argc;
char **glob_argv;
val *glob_sys;
static void show_backtrace(void) {
#ifndef NO_STACKTRACE
char* opt = getenv("NIT_NO_STACK");
unw_cursor_t cursor;
if(opt==NULL){
unw_context_t uc;
unw_word_t ip;
char* procname = malloc(sizeof(char) * 100);
unw_getcontext(&uc);
unw_init_local(&cursor, &uc);
PRINT_ERROR("-------------------------------------------------\n");
PRINT_ERROR("--   Stack Trace   ------------------------------\n");
PRINT_ERROR("-------------------------------------------------\n");
while (unw_step(&cursor) > 0) {
	unw_get_proc_name(&cursor, procname, 100, &ip);
	const char* recv = get_nit_name(procname, strlen(procname));
	if (recv != NULL){
		PRINT_ERROR("` %s\n", recv);
	}else{
		PRINT_ERROR("` %s\n", procname);
	}
}
PRINT_ERROR("-------------------------------------------------\n");
free(procname);
}
#endif /* NO_STACKTRACE */
}
void sig_handler(int signo){
PRINT_ERROR("Caught signal : %s\n", strsignal(signo));
show_backtrace();
signal(signo, SIG_DFL);
kill(getpid(), signo);
}
void fatal_exit(int status) {
show_backtrace();
exit(status);
}
int main(int argc, char** argv) {
val* var /* : Sys */;
#ifndef ANDROID
signal(SIGABRT, sig_handler);
signal(SIGFPE, sig_handler);
signal(SIGILL, sig_handler);
signal(SIGINT, sig_handler);
signal(SIGTERM, sig_handler);
signal(SIGSEGV, sig_handler);
#endif
signal(SIGPIPE, SIG_IGN);
glob_argc = argc; glob_argv = argv;
initialize_gc_option();
initialize_nitni_global_refs();
var = NEW_core__Sys(&type_core__Sys);
glob_sys = var;
{
((void(*)(val* self))(var->class->vft[COLOR_core__kernel__Object__init]))(var); /* init on <var:Sys>*/
}
{
((void(*)(val* self))(var->class->vft[COLOR_core__kernel__Sys__run]))(var); /* run on <var:Sys>*/
}
return 0;
}
const char FILE_nitc__nith[] = "nith.nit";
const char FILE_nitc__modelize[] = "./modelize/modelize.nit";
const char FILE_nitc__modelize_property[] = "./modelize/modelize_property.nit";
const char FILE_nitc__modelize_class[] = "./modelize/modelize_class.nit";
const char FILE_nitc__modelbuilder[] = "./modelbuilder.nit";
const char FILE_nitc__loader[] = "./loader.nit";
const char FILE_nitc__modelbuilder_base[] = "./modelbuilder_base.nit";
const char FILE_nitc__model[] = "./model/model.nit";
const char FILE_nitc__mmodule[] = "./model/mmodule.nit";
const char FILE_nitc__location[] = "./location.nit";
const char FILE_core[] = "/home/r4pass/nit/lib/core/core.nit";
const char FILE_core__posix[] = "/home/r4pass/nit/lib/core/posix.nit";
const char FILE_core__text[] = "/home/r4pass/nit/lib/core/text/text.nit";
const char FILE_core__ropes[] = "/home/r4pass/nit/lib/core/text/ropes.nit";
const char FILE_core__flat[] = "/home/r4pass/nit/lib/core/text/flat.nit";
const char FILE_core__abstract_text[] = "/home/r4pass/nit/lib/core/text/abstract_text.nit";
const char FILE_core__native[] = "/home/r4pass/nit/lib/core/text/native.nit";
const char FILE_core__kernel[] = "/home/r4pass/nit/lib/core/kernel.nit";
const char FILE_core__math[] = "/home/r4pass/nit/lib/core/math.nit";
const char FILE_core__collection[] = "/home/r4pass/nit/lib/core/collection/collection.nit";
const char FILE_core__range[] = "/home/r4pass/nit/lib/core/collection/range.nit";
const char FILE_core__abstract_collection[] = "/home/r4pass/nit/lib/core/collection/abstract_collection.nit";
const char FILE_core__list[] = "/home/r4pass/nit/lib/core/collection/list.nit";
const char FILE_core__array[] = "/home/r4pass/nit/lib/core/collection/array.nit";
const char FILE_core__circular_array[] = "/home/r4pass/nit/lib/core/collection/circular_array.nit";
const char FILE_core__sorter[] = "/home/r4pass/nit/lib/core/collection/sorter.nit";
const char FILE_core__hash_collection[] = "/home/r4pass/nit/lib/core/collection/hash_collection.nit";
const char FILE_core__union_find[] = "/home/r4pass/nit/lib/core/collection/union_find.nit";
const char FILE_core__string_search[] = "/home/r4pass/nit/lib/core/text/string_search.nit";
const char FILE_core__environ[] = "/home/r4pass/nit/lib/core/environ.nit";
const char FILE_core__file[] = "/home/r4pass/nit/lib/core/file.nit";
const char FILE_core__stream[] = "/home/r4pass/nit/lib/core/stream.nit";
const char FILE_core__error[] = "/home/r4pass/nit/lib/core/error.nit";
const char FILE_core__bytes[] = "/home/r4pass/nit/lib/core/bytes.nit";
const char FILE_core__codecs[] = "/home/r4pass/nit/lib/core/codecs/codecs.nit";
const char FILE_core__codec_base[] = "/home/r4pass/nit/lib/core/codecs/codec_base.nit";
const char FILE_core__utf8[] = "/home/r4pass/nit/lib/core/codecs/utf8.nit";
const char FILE_core__time[] = "/home/r4pass/nit/lib/core/time.nit";
const char FILE_core__gc[] = "/home/r4pass/nit/lib/core/gc.nit";
const char FILE_core__exec[] = "/home/r4pass/nit/lib/core/exec.nit";
const char FILE_core__bitset[] = "/home/r4pass/nit/lib/core/bitset.nit";
const char FILE_core__queue[] = "/home/r4pass/nit/lib/core/queue.nit";
const char FILE_core__numeric[] = "/home/r4pass/nit/lib/core/numeric.nit";
const char FILE_core__re[] = "/home/r4pass/nit/lib/core/re.nit";
const char FILE_core__fixed_ints[] = "/home/r4pass/nit/lib/core/fixed_ints.nit";
const char FILE_nitc__mpackage[] = "./model/mpackage.nit";
const char FILE_nitc__model_base[] = "./model/model_base.nit";
const char FILE_more_collections[] = "/home/r4pass/nit/lib/more_collections.nit";
const char FILE_serialization[] = "/home/r4pass/nit/lib/serialization/serialization.nit";
const char FILE_poset[] = "/home/r4pass/nit/lib/poset.nit";
const char FILE_nitc__mdoc[] = "./model/mdoc.nit";
const char FILE_ordered_tree[] = "/home/r4pass/nit/lib/ordered_tree.nit";
const char FILE_nitc__toolcontext[] = "./toolcontext.nit";
const char FILE_opts[] = "/home/r4pass/nit/lib/opts.nit";
const char FILE_nitc__version[] = "./version.nit";
const char FILE_template[] = "/home/r4pass/nit/lib/template/template.nit";
const char FILE_nitc__parser[] = "./parser/parser.nit";
const char FILE_nitc__parser_prod[] = "./parser/parser_prod.nit";
const char FILE_nitc__lexer[] = "./parser/lexer.nit";
const char FILE_nitc__parser_nodes[] = "./parser/parser_nodes.nit";
const char FILE_nitc__lexer_work[] = "./parser/lexer_work.nit";
const char FILE_nitc__tables[] = "./parser/tables.nit";
const char FILE_nitc__parser_work[] = "./parser/parser_work.nit";
const char FILE_ini[] = "/home/r4pass/nit/lib/ini.nit";
const char FILE_nitc__phase[] = "./phase.nit";
const char FILE_nitc__annotation[] = "./annotation.nit";
const char FILE_nitc__literal[] = "./literal.nit";
const char FILE_nitc__mmodule_data[] = "./model/mmodule_data.nit";
const char FILE_nitc__transform[] = "./transform.nit";
const char FILE_nitc__astbuilder[] = "./astbuilder.nit";
const char FILE_nitc__typing[] = "./semantize/typing.nit";
const char FILE_nitc__local_var_init[] = "./semantize/local_var_init.nit";
const char FILE_nitc__flow[] = "./semantize/flow.nit";
const char FILE_nitc__scope[] = "./semantize/scope.nit";
const char FILE_nitc__astvalidation[] = "./astvalidation.nit";
const char FILE_nitc__semantize[] = "./semantize/semantize.nit";
const char FILE_nitc__auto_super_init[] = "./semantize/auto_super_init.nit";
const char FILE_nitc__rapid_type_analysis[] = "./rapid_type_analysis.nit";
const char FILE_csv[] = "/home/r4pass/nit/lib/csv/csv.nit";
const char FILE_nitc__separate_erasure_compiler[] = "./compiler/separate_erasure_compiler.nit";
const char FILE_nitc__separate_compiler[] = "./compiler/separate_compiler.nit";
const char FILE_nitc__abstract_compiler[] = "./compiler/abstract_compiler.nit";
const char FILE_nitc__platform[] = "./platform/platform.nit";
const char FILE_nitc__parser_util[] = "./parser_util.nit";
const char FILE_nitc__c_tools[] = "./c_tools.nit";
const char FILE_nitc__mixin[] = "./mixin.nit";
const char FILE_counter[] = "/home/r4pass/nit/lib/counter.nit";
const char FILE_nitc__coloring[] = "./compiler/coloring.nit";
const char FILE_nitc__light_only[] = "./compiler/compiler_ffi/light_only.nit";
const char FILE_nitc__light[] = "./compiler/compiler_ffi/light.nit";
const char FILE_nitc__light_ffi[] = "./ffi/light_ffi.nit";
const char FILE_nitc__nitni_utilities[] = "./nitni/nitni_utilities.nit";
const char FILE_nitc__nitni_base[] = "./nitni/nitni_base.nit";
const char FILE_nitc__light_ffi_base[] = "./ffi/light_ffi_base.nit";
const char FILE_nitc__extern_classes[] = "./ffi/extern_classes.nit";
const char FILE_nitc__light_c[] = "./ffi/light_c.nit";
void gc_finalize (void *obj, void *client_data) {
val* var /* : Finalizable */;
var = obj;
{
((void(*)(val* self))(var->class->vft[COLOR_core__gc__Finalizable__finalize]))(var); /* finalize on <var:Finalizable>*/
}
}
