#ifndef __ET_KEYWORD_H
#define __ET_KEYWORD_H

#include "complier.h"

// extern c
#ifdef __cplusplus
#define __et_extern_c			extern "C"
#define __et_extern_c_enter		extern "C" {
#define __et_extern_c_leave		}
#else
#define __et_extern_c
#define __et_extern_c_enter
#define __et_extern_c_leave
#endif

// export for shared library
#if defined(ET_COMPILER_IS_MSVC)
#define __et_export				__declspec(dllexport)
#elif defined(ET_COMPILER_IS_GCC) && ((__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3))
#define __et_export				__attribute__((visibility("default")))
#else
#define __et_export
#endif

#endif // !__ET_KEYWORD_H
