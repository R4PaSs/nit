#include "nit.common.h"
#define COLOR_core__file__FileStream___path 1
#define COLOR_core__file__FileStream___file 2
extern const char FILE_core__file[];
int kernel___Pointer_address_is_null___impl( void* self );
#define COLOR_core__stream__Stream___last_error 0
#define COLOR_core__kernel__Object___61d_61d 4
val* NEW_core__IOError(const struct type* type);
extern const struct type type_core__IOError;
val* core__flat___NativeString___to_s_full(char* self, long p0, long p1);
#define COLOR_core__error__Error__message_61d 12
#define COLOR_core__kernel__Object__init 0
long file___NativeFile_io_close___impl( void* self );
val* NEW_core__NativeArray(int length, const struct type* type);
extern const struct type type_core__NativeArray__core__String;
long kernel___Sys_errno___impl( struct nitni_instance * self );
val* core__abstract_text___Int___strerror(long self);
#define COLOR_core__abstract_text__NativeArray__native_to_s 12
extern const struct type type_core__Int;
extern const char FILE_core__kernel[];
long file___NativeFile_set_buffering_type___impl( void* self, long buf_length, long mode );
#define COLOR_core___core__FileReader___core__stream__Stream__close 32
void core___core__BufferedReader___buffer_reset(val* self);
#define COLOR_core__file__FileReader___end_reached 8
#define COLOR_core__stream__BufferedReader___buffer 3
#define COLOR_core__stream__BufferedReader___buffer_capacity 7
long file___NativeFile_io_read___impl( void* self, char* buf, long len );
int file___NativeFile_ferror___impl( void* self );
#define COLOR_core__stream__BufferedReader___buffer_length 6
#define COLOR_core__stream__BufferedReader___buffer_pos 4
void core___core__BufferedReader___prepare_buffer(val* self, long p0);
val* NEW_core__file__NativeFile(const struct type* type);
extern const struct type type_core__file__NativeFile;
#define COLOR_core__abstract_text__Text__to_cstring 21
val* core__file___core__file__NativeFile___io_open_read(val* self, char* p0);
#define COLOR_core__file__FileWriter___is_writable 3
#define COLOR_core__bytes__Bytes___items 2
#define COLOR_core__bytes__Bytes___length 3
void core___core__FileWriter___write_native(val* self, char* p0, long p1, long p2);
#define COLOR_core__file__Text__write_native_to 50
#define COLOR_core___core__FileWriter___core__stream__Stream__close 23
long file___NativeFile_io_write___impl( void* self, char* buf, long from, long len );
val* core__flat___Int___core__abstract_text__Object__to_s(long self);
val* core__file___core__file__NativeFile___io_open_write(val* self, char* p0);
#define COLOR_core___core__Stdin___core__kernel__Object__init 33
val* core__file___core__file__NativeFile___native_stdin(val* self);
#define COLOR_core___core__Stdout___core__kernel__Object__init 24
val* core__file___core__file__NativeFile___native_stdout(val* self);
long file___Sys_buffer_mode_line___impl( struct nitni_instance * self );
void core___core__FileStream___set_buffering_mode(val* self, long p0, long p1);
#define COLOR_core___core__Stderr___core__kernel__Object__init 24
val* core__file___core__file__NativeFile___native_stderr(val* self);
val* NEW_core__FileWriter(const struct type* type);
extern const struct type type_core__FileWriter;
void core___core__FileWriter___open(val* self, val* p0);
#define COLOR_core__stream__Writable__write_to 28
void core___core__FileWriter___core__stream__Stream__close(val* self);
#define COLOR_core__file__Path___path 0
#define COLOR_core__file__Path___simplified 3
val* core__file___String___simplify_path(val* self);
val* core__file___Text___to_path(val* self);
void core___core__Path___simplified_61d(val* self, val* p0);
#define COLOR_core__file__Path___last_error 7
val* core___core__Path___open_ro(val* self);
val* core___core__Path___open_wo(val* self);
short int core___core__BufferedReader___Reader__eof(val* self);
val* core___core__Reader___read(val* self, long p0);
void core___core__FileWriter___core__stream__Writer__write(val* self, val* p0);
void core___core__FileReader___core__stream__Stream__close(val* self);
val* NEW_core__FileReader(const struct type* type);
extern const struct type type_core__FileReader;
void core___core__FileReader___open(val* self, val* p0);
extern const struct type type_core__Path;
val* core___core__Path___simplified(val* self);
#define COLOR_core__kernel__Object__hash 11
#define COLOR_core___core__Path___core__kernel__Object__init 20
#define COLOR_core__file__FileStat___stat 0
#define COLOR_core__file__FileStat___finalized 1
void kernel___Pointer_free___impl( void* self );
int file___NativeFileStat_is_dir___impl( void* self );
#define COLOR_core___core__FileStat___core__kernel__Object__init 18
val* NEW_core__Path(const struct type* type);
#define COLOR_core__abstract_text__Object__to_s 3
#define COLOR_core__file__Path__path_61d 16
#define COLOR_core__abstract_text__Text__substrings 36
#define COLOR_core__abstract_collection__Iterator__iterator 16
#define COLOR_core__abstract_collection__Iterator__is_ok 12
#define COLOR_core__abstract_collection__Iterator__item 13
#define COLOR_core__abstract_text__FlatText___bytelen 7
#define COLOR_core__abstract_collection__Iterator__next 14
#define COLOR_core__abstract_collection__Iterator__finish 15
int file___NativeString_file_exists___impl( char* self );
val* BOX_core__Pointer(void*);
extern const struct type type_core__file__NativeFileStat;
extern const struct class class_core__file__NativeFileStat;
void* file___NativeString_file_stat___impl( char* self );
val* NEW_core__FileStat(const struct type* type);
extern const struct type type_core__FileStat;
#define COLOR_core__file__FileStat__stat_61d 14
void core___core__Path___copy(val* self, val* p0);
#define COLOR_core__file__String__file_extension 82
short int core___core__Text___has_suffix(val* self, val* p0);
#define COLOR_core__abstract_text__Text__length 22
#define COLOR_core__abstract_text__Text__substring 24
#define COLOR_core__abstract_text__Text__chars 23
#define COLOR_core__abstract_collection__SequenceRead___91d_93d 29
#define COLOR_core__abstract_collection__SequenceRead__last_index_of_from 35
val* core__file___String___strip_extension(val* self, val* p0);
char* file___NativeString_file_realpath___impl( char* self );
short int core__file___String___file_exists(val* self);
val* core__flat___NativeString___to_s_with_copy(char* self);
val* core__string_search___Text___split_with(val* self, val* p0);
val* NEW_core__Array(const struct type* type);
extern const struct type type_core__Array__core__String;
void core___core__Array___core__kernel__Object__init(val* self);
val* core___core__AbstractArrayRead___core__abstract_collection__Collection__iterator(val* self);
short int core___core__AbstractArrayRead___core__abstract_collection__Collection__is_empty(val* self);
val* core___core__SequenceRead___last(val* self);
val* core___core__AbstractArray___core__abstract_collection__Sequence__pop(val* self);
void core___core__AbstractArray___core__abstract_collection__Sequence__push(val* self, val* p0);
#define COLOR_core__array__AbstractArrayRead___length 0
val* core___core__SequenceRead___Collection__first(val* self);
val* core__abstract_text___Collection___join(val* self, val* p0);
#define COLOR_core__abstract_text__Text__is_empty 37
uint32_t core___core__Text___last(val* self);
val* core__file___String___join_path(val* self, val* p0);
val* core__file___Sys___getcwd(val* self);
val* core__file___String____47d(val* self, val* p0);
val* core__string_search___Text___split(val* self, val* p0);
val* core___core__AbstractArray___core__abstract_collection__Sequence__shift(val* self);
#define COLOR_core__abstract_text__String___42d 81
#define COLOR_core__abstract_text__String___43d 76
val* NEW_core__FlatBuffer(const struct type* type);
extern const struct type type_core__FlatBuffer;
#define COLOR_core___core__FlatBuffer___core__kernel__Object__init 102
val* core___core__Array___core__abstract_collection__SequenceRead___91d_93d(val* self, long p0);
void core___core__FlatBuffer___core__abstract_text__Buffer__add(val* self, uint32_t p0);
void core___core__FlatBuffer___core__abstract_text__Buffer__append(val* self, val* p0);
val* core___core__FlatBuffer___core__abstract_text__Object__to_s(val* self);
int file___NativeString_file_mkdir___impl( char* self );
#define COLOR_core__abstract_collection__SequenceRead__last_index_of 32
val* NEW_core__file__NativeDir(const struct type* type);
extern const struct type type_core__file__NativeDir;
val* core__file___core__file__NativeDir___opendir(val* self, char* p0);
char* file___NativeDir_readdir___impl( void* self );
short int core___core__FlatString___core__kernel__Object___61d_61d(val* self, val* p0);
void core___core__Array___core__abstract_collection__SimpleCollection__add(val* self, val* p0);
void file___NativeDir_closedir___impl( void* self );
#define COLOR_core__abstract_text__FlatText___items 5
#define COLOR_core__flat__FlatString___first_byte 1
long core__flat___FlatText___last_byte(val* self);
unsigned char core___core__Char___ascii(uint32_t self);
val* NEW_core__FlatString(const struct type* type);
extern const struct type type_core__FlatString;
void core___core__FlatString___with_infos(val* self, char* p0, long p1, long p2);
extern const struct class class_core__file__NativeFile;
void* file___new_NativeFile_io_open_read___impl( char* path );
void* file___new_NativeFile_io_open_write___impl( char* path );
void* file___new_NativeFile_native_stdin___impl(  );
void* file___new_NativeFile_native_stdout___impl(  );
void* file___new_NativeFile_native_stderr___impl(  );
extern const struct class class_core__file__NativeDir;
void* file___new_NativeDir_opendir___impl( char* path );
#define COLOR_core__file__Sys___stdout 3
val* NEW_core__Stdout(const struct type* type);
extern const struct type type_core__Stdout;
void core___core__Stdout___core__kernel__Object__init(val* self);
#define COLOR_core__file__Sys___stderr 5
val* NEW_core__Stderr(const struct type* type);
extern const struct type type_core__Stderr;
void core___core__Stderr___core__kernel__Object__init(val* self);
val* core__file___Sys___stdout(val* self);
val* core__flat___Array___core__abstract_text__Collection__plain_to_s(val* self);
char* file___Sys_native_getcwd___impl( struct nitni_instance * self );
val* core__flat___NativeString___core__abstract_text__Object__to_s(char* self);
