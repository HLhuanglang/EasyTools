#ifndef __ET_TYPES_H
#define __ET_TYPES_H

// basic types
using et_int_t = signed int;
using et_uint_t = unsigned int;
using et_short_t = signed short;
using et_ushort_t = unsigned short;
using et_bool_t = et_int_t;
using et_int8_t = signed char;
using et_sint8_t = et_int8_t;
using et_uint8_t = unsigned char;
using et_int16_t = et_short_t;
using et_sint16_t = et_int16_t;
using et_uint16_t = et_ushort_t;
using et_int32_t = et_int_t;
using et_sint32_t = et_int32_t;
using et_uint32_t = et_uint_t;
using et_char_t = char;
using et_uchar_t = unsigned char;
using et_byte_t = et_uint8_t;
using et_void_t = void;
using et_pointer_t = et_void_t *;

// bool values
#define et_true                     ((et_bool_t)1)
#define et_false                    ((et_bool_t)0)

// null
#ifdef __cplusplus
#   define et_null                  (0)
#else
#   define et_null                  ((et_pointer_t)0)
#endif

#endif // !__ET_TYPES_H
