#ifndef __ET_COMPILER_H
#define __ET_COMPILER_H

// visual c++
#if defined(_MSC_VER)
#define ET_COMPILER_IS_MSVC

// gnu c/c++
#elif defined(__GNUC__)
#define ET_COMPILER_IS_GCC
#endif

#endif // !__ET_COMPILER_H
