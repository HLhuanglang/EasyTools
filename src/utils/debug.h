#ifndef __ET_UTILS_DEBUG_H
#define __ET_UTILS_DEBUG_H

#include "utils_prefix.h"
#include "module.h"

#include <cstdio>
#include <cstdarg>

#define END "\033[0m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"

void et_print(const char *fmt, ...);

#define et_trace_debug(msg, ...) \
do  {	\
	et_print(GREEN "[%s][DEBUG]-[%s:%d]" msg __et_newline END, ET_TRACE_MODULE_NAME ,__et_filename, __et_line, ##__VA_ARGS__);\
} while (0);

#define et_trace_error(msg, ...) \
do  { \
	et_print(RED "[%s][ERROR]-[%s:%d]" msg __et_newline END, ET_TRACE_MODULE_NAME,__et_filename,__et_line, ##__VA_ARGS__);\
} while (0);

#endif // !__ET_UTILS_DEBUG_H
