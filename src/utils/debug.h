#ifndef __ET_UTILS_DEBUG_H
#define __ET_UTILS_DEBUG_H

#include "utils_prefix.h"

#include <cstdio>
#include <cstdarg>

#define END "\033[0m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"

__et_extern_c_enter

__et_export void  et_print(const char *fmt, ...);

#define et_debug(module_name,msg, ...) \
do  {	\
	et_print(GREEN "[%s][DEBUG]-[%s:%d]"msg __et_newline END, module_name,__et_filename, __et_line, ##__VA_ARGS__);\
} while (0);

#define et_error(module_name,msg, ...) \
do  { \
	et_print(RED "[%s][ERROR]-[%s:%d]"msg __et_newline END, module_name,__et_filename,__et_line, ##__VA_ARGS__);\
} while (0);

__et_extern_c_leave

#endif // !__ET_UTILS_DEBUG_H
