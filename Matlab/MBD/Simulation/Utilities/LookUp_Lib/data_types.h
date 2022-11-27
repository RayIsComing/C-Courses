#ifndef _DATA_TYPES_H_
#define _DATA_TYPES_H_

/*******************************************************************************
* Basic types definitions
*******************************************************************************/

typedef unsigned char   U8;
#define U8_DISP         U8
#define U8_CAL          volatile const U8
#define U8_MIN          (0U)
#define U8_MAX          (255U)

typedef signed char     S8;
#define S8_DISP         S8
#define S8_CAL          volatile const S8
#define S8_MIN          (-128)
#define S8_MAX          ( 127)

typedef unsigned short  U16;
#define U16_DISP        U16
#define U16_CAL         volatile const U16
#define U16_MIN         (0U)
#define U16_MAX         (65535U)

typedef signed short    S16;
#define S16_DISP        S16
#define S16_CAL         volatile const S16
#define S16_MIN         (-32768)
#define S16_MAX         ( 32767)

typedef unsigned int    U32;
#define U32_DISP        U32
#define U32_CAL         volatile const U32
#define U32_MIN         (0U)
#define U32_MAX         (4294967295U)

typedef signed int      S32;
#define S32_DISP        S32
#define S32_CAL         volatile const S32
#define S32_MIN         (-2147483648)
#define S32_MAX         ( 2147483647)

typedef float           F32;
#define F32_DISP        F32
#define F32_CAL         volatile const F32

typedef double          F64;
#define F64_DISP        F64
#define F64_CAL         volatile const F64

typedef U8              flag;

typedef flag            FLAG;

#endif
