/*************************************************************************************************
*
* This file is used for auto-code.  It is manually modified.
*
* Filename:    ctcm_types.h
*
* Description: Word size definitions of compiler, expected by Mathworks Embedded Coder.
*              Initial content from Lucas, but cleaned up to only contain necessary
*              items for CTCM auto-code files.
*
*
* Forward Engine Management Systems
*
* Copyright 1999-2011, Delphi Technologies, Inc.
* All rights reserved.
*
**************************************************************************************************
*
* Current Module Info:
*
* %full_name:     kok_pt2#4/incl/ctcm_types.h/3.1.1.1.2 %
* %date_created:  Fri Apr 29 14:53:41 2016 %
* %version:       3.1.1.1.2 %
* %derived_by:    pj1rgk %
*
*************************************************************************************************/


#ifndef _CTCM_TYPES_H_
#define _CTCM_TYPES_H_

// #include "dd_fault_periodic.h"
/*******************************************************************************
* Storage modifier
*******************************************************************************/

#define CAL             volatile const
#define STATIC          static

//#if XeSYST_DDS_AUTOCODE_LIB == CeSYST_AVAILABLE
//#include "s_s_lib_types.h"
//#else
/*******************************************************************************
* Basic types definitions
*******************************************************************************/
typedef unsigned char		U8;
typedef CAL U8				U8_CAL;
#define U8_MIN				(0U)
#define U8_MAX				(255U)

typedef signed char			S8;
typedef CAL S8				S8_CAL;
#define S8_MIN				(-128)
#define S8_MAX				(127)

typedef unsigned short		U16;
typedef CAL U16				U16_CAL;
#define U16_MIN				(0U)
#define U16_MAX				(65535U)

typedef signed short		S16;
typedef CAL S16				S16_CAL;
#define S16_MIN				(-32768)
#define S16_MAX				(32767)

typedef unsigned int		U32;
typedef CAL U32				U32_CAL;
#define U32_MIN				(0UL)
#define U32_MAX				(4294967295UL)

typedef signed int			S32;
typedef CAL S32				S32_CAL;
#define S32_MIN				(-2147483647L -1)
#define S32_MAX				(2147483647L)

typedef unsigned long long	U64;
typedef CAL U64				U64_CAL;
#define U64_MIN				(0x0ULL)
#define U64_MAX				(0xFFFFFFFFFFFFFFFFULL)

typedef signed long long	S64;
typedef CAL S64				S64_CAL;
#define S64_MIN				(0x8000000000000000LL)
#define S64_MAX				(0x7FFFFFFFFFFFFFFFLL)

/*******************************************************************************
* Binary points definitions
*******************************************************************************/

#define BIN0            1
#define BIN1            2
#define BIN2            4
#define BIN3            8
#define BIN4            16
#define BIN5            32
#define BIN6            64
#define BIN7            128
#define BIN8            256
#define BIN9            512

#define BIN10           1024
#define BIN11           2048
#define BIN12           4096
#define BIN13           8192
#define BIN14           16384
#define BIN15           32768
#define BIN16           65536L
#define BIN17           131072L
#define BIN18           262144L
#define BIN19           524288L

#define BIN20           1048576L
#define BIN21           2097152L
#define BIN22           4194304L
#define BIN23           8388608L
#define BIN24           16777216L
#define BIN25           33554432L
#define BIN26           67108864L
#define BIN27           134217728L
#define BIN28           268435456L
#define BIN29           536870912L

#define BIN30           1073741824L
#define BIN31           2147483648UL
#define BIN32           4294967296ULL
#define BIN33           8589934592ULL
#define BIN34           17179869184ULL
#define BIN35           34359738368ULL
#define BIN36           68719476736ULL
#define BIN37           137438953472ULL
#define BIN38           274877906944ULL
#define BIN39           549755813888ULL

#define BIN40           1099511627776ULL
#define BIN41           2199023255552ULL
#define BIN42           4398046511104ULL
#define BIN43           8796093022208ULL
#define BIN44           17592186044416ULL
#define BIN45           35184372088832ULL
#define BIN46           70368744177664ULL
#define BIN47           140737488355328ULL
#define BIN48           281474976710656ULL
#define BIN49           562949953421312ULL

#define BIN50           1125899906842624ULL
#define BIN51           2251799813685248ULL
#define BIN52           4503599627370496ULL
#define BIN53           9007199254740992ULL
#define BIN54           18014398509481984ULL
#define BIN55           36028797018963968ULL
#define BIN56           72057594037927936ULL
#define BIN57           144115188075855872ULL
#define BIN58           288230376151711744ULL
#define BIN59           576460752303423488ULL

#define BIN60           1152921504606846976ULL
#define BIN61           2305843009213693952ULL
#define BIN62           4611686018427387904ULL
#define BIN63           9223372036854775808ULL

/*******************************************************************************
* Decimal points definitions
*******************************************************************************/

#define DEC0            1
#define DEC1            10
#define DEC2            100
#define DEC3            1000
#define DEC4            10000
#define DEC5            100000L
#define DEC6            1000000L
#define DEC7            10000000L
#define DEC8            100000000L
#define DEC9            1000000000L
#define DEC10           10000000000ULL

/* BIT TYPES */

#define BIT0  ((U32)0x00000001)
#define BIT1  ((U32)0x00000002)
#define BIT2  ((U32)0x00000004)
#define BIT3  ((U32)0x00000008)
#define BIT4  ((U32)0x00000010)
#define BIT5  ((U32)0x00000020)
#define BIT6  ((U32)0x00000040)
#define BIT7  ((U32)0x00000080)
#define BIT8  ((U32)0x00000100)
#define BIT9  ((U32)0x00000200)
#define BIT10 ((U32)0x00000400)
#define BIT11 ((U32)0x00000800)
#define BIT12 ((U32)0x00001000)
#define BIT13 ((U32)0x00002000)
#define BIT14 ((U32)0x00004000)
#define BIT15 ((U32)0x00008000)
#define BIT16 ((U32)0x00010000)
#define BIT17 ((U32)0x00020000)
#define BIT18 ((U32)0x00040000)
#define BIT19 ((U32)0x00080000)
#define BIT20 ((U32)0x00100000)
#define BIT21 ((U32)0x00200000)
#define BIT22 ((U32)0x00400000)
#define BIT23 ((U32)0x00800000)
#define BIT24 ((U32)0x01000000)
#define BIT25 ((U32)0x02000000)
#define BIT26 ((U32)0x04000000)
#define BIT27 ((U32)0x08000000)
#define BIT28 ((U32)0x10000000)
#define BIT29 ((U32)0x20000000)
#define BIT30 ((U32)0x40000000)
#define BIT31 ((U32)0x80000000)

/*******************************************************************************
* Boolean definitions
*******************************************************************************/

#ifdef FALSE
#undef FALSE
#endif
#ifdef TRUE
#undef TRUE
#endif

typedef enum
{
   FALSE = 0,
   TRUE
} BOOL_TYPE;


#define DISABLED        FALSE
#define ENABLED         TRUE

#define DEBOUNCE_OFF             FALSE
#define DEBOUNCE_ON              TRUE

#define LOW             FALSE
#define HIGH            TRUE


/*******************************************************************************
* Bit oriented definitions
*******************************************************************************/

typedef unsigned short  BIT_FIELD;


/*******************************************************************************
* Other definitions
*******************************************************************************/
#ifndef NULL
#define NULL            (void *)(0)
#endif

//#endif    /* XeSYST_DDS_AUTOCODE_LIB == CeSYST_NOT_AVAILABLE */


typedef float           F32;


/*****************************************************************************
 *   Definitions used by Library files                                       *
 *****************************************************************************/
/* Types and constants */
typedef U8              flag;

#ifndef false
#define false (0)
#endif

#ifndef true
#define true  (1)
#endif

#define ZERO_CPV        0
#define ONE_CPV         1


#endif

/*************************************************************************************************
*
* Revision History for AutoCode Data Dictionary Global settings :
*
* Rev.  YYMMDD Who  RSM# Changes
* ----  ------ --- ----- ------------------------------------------------------------------------
* 1.0   110321 mm   9300 Original implementation as part of introducing new auto-code process.
* 2     110629 me   -BM- Added TRUE and FALSE for Diab build
* 3.0   120327 mm  10120 Deleted all C language word replacements (e.g. "is",...) to avoid s-fct issues.
* tci_pt3#3.1.1.1.1
*       160401 YN  12748 Moved contents of s_s_lib_types.h to this file to avoid the redefinitions
* 3.1.1.2.1
*       160404 dvp 12775  added swtich for compatibility with Autocode library
*                         XeSYST_DDS_AUTOCODE_LIB
*       160429 NS -BM Merges
*************************************************************************************************/
