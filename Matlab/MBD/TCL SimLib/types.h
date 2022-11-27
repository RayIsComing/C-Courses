/*******************************************************************************
*                    Delphi Diesel Systems
*
*                    This document is the property of
*                    Delphi Diesel Systems
*                    It must not be copied (in whole or in part)
*                    or disclosed without prior written consent
*                    of the company. Any copies by any method
*                    must also include a copy of this legend.
********************************************************************************
* Task File History: This comment block is automatically
*                    updated by the configuration management tool
*                    DO NOT Update manually
*------------------------------------------------------------------------------*
*
* Ref X:\mazghim_view_KHA\blois_soft_vob\Software\_Software\src\types.h
* Version int :/main/19 Date: 29/8/2003 15 h 6 m User:nevel 
*    TWK_model:N/A
*    comments :Change S32_MIN definition
* Version dev :\main\branch_brou_nma\1 Date: 21/8/2003 14 h 35 m User:brous 
*    TWK_model:N/A
*    comments :Change S32_MIN definition
* Version int :\main\18 Date: 5/5/2003 10 h 2 m User:nevel 
*    TWK_model:LDCR_Application_NMA21_SPEC1
*    comments :Suppression de la double définition de BIN29
* Version dev :\main\branch_spiewek_dc_nma10\2 Date: 29/4/2003 17 h 54 m User:spiewea 
*    TWK_model:NA
*    comments :Suppression de la double définition de BIN29
* Version dev :\main\branch_spiewek_dc_nma10\1 Date: 29/4/2003 15 h 38 m User:spiewea
*    TWK_model:NA
*    comments :Correction of NULL definition: It becomes (void *)(0)
* Version int :\main\17 Date: 30/1/2002 14 h 4 m User:baijoth
*    TWK_model:NA
*    comments :Change S32_MIN valeur en decimale mise en hexa
* Version dev :\main\branch_gueriot\2 Date: 14/11/2001 11 h 35 m User:gueriop
*    TWK_model:NA
*    comments :Change S32_MIN valeur en decimale mise en hexa
* Version dev :\main\branch_gueriot\1 Date: 13/11/2001 15 h 11 m User:gueriop
*    TWK_model:NA
*    comments :Ajout d'un cast devant S32_MIN suite à un bug dans l'utilisation dans la macro M_PID_S32
* Version int :\main\P0413\1 Date: 24/9/2001 13 h 59 m User:nevel
*    TWK_model:
*    comments :add BIN25 to BIN32
* Version dev :\main\branch_cochet\1 Date: 19/9/2001 13 h 48 m User:cochett
*    TWK_model:LDCR_Peugeot_Apllication_PSAB41_IMPL1
*    comments :add BIN25 to BIN32
* Version int :\main\16 Date: 16/1/2001 10 h 44 m User:cheucll
*    TWK_model:LDCR_Peugeot_Apllication_PSAB41_IMPL1
*    comments :PSA_B4 PHASE_14
* Version dev :\main\branch_oudin\3 Date: 5/1/2001 14 h 21 m User:oudinp
*    TWK_model:_
*    comments :Add TPV storage modifier definition.
* Version int : Date: 29/9/2000 15 h 14 m User:cheucll
*    TWK_model:_
*    comments :Remove RAM_BOOL and CONST_BOOL type
* Version int : Date: 8/9/2000 12 h 50 m User:cheucll
*    TWK_model:_
*    comments :Update BIN up to BIN24
* Version int : Date: 14/6/2000 15 h 15 m User:cheucll
*    TWK_model:_
*    comments :Add definitions of BIN18 to BIN20
* Version int :\main\12 Date: 15/5/2000 9 h 43 m User:cheucll
*       TWK_model = " "
*    comments :Add hwi_set_interrupt_pending(S_S_ASYNC_SCHEDULER_INTERRUPT_LEVEL)
* Version int :\main\11 Date: 24/3/2000 9 h 51 m User:cheucll
*       TWK_model = " "
*    comments :Remove BOOL_TYPE enum and BIT_BOOL_TYPE struct useless labels

* BIT_BOOL is now only a const BIT_BOOL_TYPE (remove volatile)
* Version dev :\main\branch_oudin\2 Date: 23/3/2000 18 h 14 m User:oudinp
*
*    comments :Remove BOOL_TYPE enum and BIT_BOOL_TYPE struct useless labels
*
* BIT_BOOL is now only a const BIT_BOOL_TYPE (remove volatile)
* Version dev :\main\branch_oudin\1 Date: 20/3/2000 14 h 53 m User:oudinp
*
*    comments :Add CAL as volatile const
* Version int :\main\8 Date: 9/3/2000 17 h 8 m User:cheucll
*       TWK_model = " "
*    comments :Replace // comment by / *      * /
* Version int :\main\6 Date: 8/3/2000 18 h 5 m User:cheucll
*       TWK_model = " "
*    comments :Remove DISP types
*
*******************************************************************************/

#ifndef TYPES_H
#define TYPES_H

/*******************************************************************************
* Basic types definitions
*******************************************************************************/

typedef unsigned char   U8;
/* #define U8_DISP         U8 */
#define U8_CAL          volatile const U8
#define U8_MIN          (0U)
#define U8_MAX          (255U)

typedef signed char     S8;
/* #define S8_DISP         S8 */
#define S8_CAL          volatile const S8
#define S8_MIN          (-128)
#define S8_MAX          (127)

typedef unsigned short  U16;
/* #define U16_DISP        U16 */
#define U16_CAL         volatile const U16
#define U16_MIN         (0U)
#define U16_MAX         (65535U)

typedef signed short    S16;
/* #define S16_DISP        S16 */
#define S16_CAL         volatile const S16
#define S16_MIN         (-32768)
#define S16_MAX         (32767)

typedef unsigned int    U32;
/* #define U32_DISP        U32 */
#define U32_CAL         volatile const U32
#define U32_MIN         (0UL)
#define U32_MAX         (4294967295UL)

typedef signed int      S32;
/* #define S32_DISP        S32 */
#define S32_CAL         volatile const S32
//#define S32_MIN         ((S32)(0x80000000))
#define S32_MIN         (-2147483647L -1)

#define S32_MAX         (2147483647L)
/*((S32)(-2147483648L))*/



#ifdef _QAC_
            /* STUB for QAC only */
typedef unsigned long U64;
typedef signed long   S64;

#else

#ifndef MATLAB_MEX_FILE
typedef unsigned long long U64;
typedef signed long long   S64;
#endif

#endif

/* S64 LIMITS */
#define S64_MIN         (0x8000000000000000LL)
#define S64_MAX         (0x7FFFFFFFFFFFFFFFLL)

#define U64_MIN         (0x0ULL)
#define U64_MAX         (0xFFFFFFFFFFFFFFFFULL)

/*******************************************************************************
* Storage modifier
*******************************************************************************/

#define CAL             volatile const

#ifdef TUNING
	#define TPV
#else
	#define	TPV			const
#endif


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
#define BIN31           2147483648L
#define BIN32           4294967296L



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


/*******************************************************************************
* Boolean definitions
*******************************************************************************/

#define DISABLED        FALSE
#define ENABLED         TRUE

#define OFF             FALSE
#define ON              TRUE

#define LOW             FALSE
#define HIGH            TRUE


/*******************************************************************************
* Bit oriented definitions
*******************************************************************************/

typedef unsigned short  BIT_FIELD;

#define U16_FLAG        U16

typedef struct
{
    const U8            flag_pos;
    U16_FLAG *          const flag_carrier;
} BIT_BOOL_TYPE;

#define BIT_BOOL         const BIT_BOOL_TYPE


/*******************************************************************************
* Other definitions
*******************************************************************************/

#define NULL            (void *)(0)

#endif


/*----------------------------------------------------------------------------*/
/* LEVEL BLOCK                                                                */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* TYPES.H rev 1.2 - 01 April 2004 - Julien Schmitt                           */
/*                                                                            */
/* - added levelblock                                                         */
/* - do not define type U64 when MATLAB_MEX_FILE is set because Visual C++    */
/*   (used to compile matlab S-Functions) doesnot accept a "long long" type.  */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* TYPES.H rev 1.3 - 17 November 2004 - Julien Schmitt                        */
/*                                                                            */
/* - created new S64 type                                                     */
/* - added limits for S64 and U64                                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*--- End of file TYPES.H ---*/
