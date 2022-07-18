#ifndef __ET_KEYWORD_H
#define __ET_KEYWORD_H

#include "complier.h"

#include <cstring>	//for strrchr

#if defined(ET_COMPILER_IS_MSVC)
#   define __et_func                          __FUNCTION__
#   define __et_file                          __FILE__
#   define __et_line                          __LINE__
#   define __et_date                          __DATE__
#   define __et_time                          __TIME__
#   define __et_asm                           __asm
#   define __et_inline                        __inline
#   define __et_inline_force                  __forceinline
#   define __et_cdecl                         __cdecl
#   define __et_stdcall                       __stdcall
#   define __et_fastcall                      __fastcall
#   define __et_thiscall                      __thiscall
#   define __et_packed
#   define __et_aligned(a)                    __declspec(align(a))

#elif defined(ET_COMPILER_IS_GCC)

#   define __et_func                          __FUNCTION__
#   define __et_file                          __FILE__
#   define __et_line                          __LINE__
#   define __et_date                          __DATE__
#   define __et_time                          __TIME__
#   define __et_asm                           __asm__
#   define __et_inline                        __inline__
#   define __et_inline_force                  __inline__ __attribute__((always_inline))
#   define __et_packed                        __attribute__((packed, aligned(1)))
#   define __et_aligned(a)                    __attribute__((aligned(a)))
#   if defined(__x86_64) \
    || defined(__amd64__) \
    || defined(__amd64) \
    || defined(_M_IA64) \
    || defined(_M_X64)
#       define __tb_cdecl
#       define __tb_stdcall
#       define __tb_fastcall
#       define __tb_thiscall
#   else
#       define __tb_cdecl                     __attribute__((__cdecl__))
#       define __tb_stdcall                   __attribute__((__stdcall__))
#       define __tb_fastcall                  __attribute__((__fastcall__))
#       define __tb_thiscall                  __attribute__((__thiscall__))
#   endif
#endif

#define __et_filename                                                       \
  (strrchr(__et_file, __et_dir_separtor) ? strrchr(__et_file, __et_dir_separtor) + 1 \
                                    : __et_file)

// extern c
#ifdef __cplusplus
#   define __et_extern_c			extern "C"
#   define __et_extern_c_enter		extern "C" {
#   define __et_extern_c_leave		}
#else
#   define __et_extern_c
#   define __et_extern_c_enter
#   define __et_extern_c_leave
#endif

// export for shared library
#if defined(ET_COMPILER_IS_MSVC)
#   define __et_export				__declspec(dllexport)
#elif defined(ET_COMPILER_IS_GCC) && ((__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3))
#   define __et_export				__attribute__((visibility("default")))
#else
#   define __et_export
#endif

// newline
#ifdef ET_CONFIG_OS_WINDOWS
#   define __et_newline                       "\r\n"
#else
#   define __et_newline                       "\n"
#endif

// separtor
#ifdef ET_CONFIG_OS_WINDOWS
#   define __et_dir_separtor '\\'
#   define __et_dir_separtor_str "\\"
#else
#   define __et_dir_separtor '/'
#   define __et_dir_separtor_str "/"
#endif

#endif // !__ET_KEYWORD_H
