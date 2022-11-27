/*************************************************************************************************
*
* This file is used for auto-code.  It is manually modified.
*
* Filename:    copy_RAM.c
*
* Description: Definition file for RAM copy operations.
*
*
* Forward Engine Management Systems
*
* Copyright 1999-2014, Delphi Technologies, Inc.
* All rights reserved.
*
**************************************************************************************************
*
* Current Module Info:
*
* %full_name:     kok_pt2#1/csrc/copy_RAM.c/1 %
* %date_created:  Mon Feb  3 10:38:37 2014 %
* %version:       1 %
* %derived_by:    tzzpjy %
*
*************************************************************************************************/

#define _COPY_RAM_C_

#include <copy_RAM.h>
#include  "filepall.h"


/*******************************************************************************
 *   NVM misc support                                                          *
 *******************************************************************************/

// The following RAM copy functions (CopyRAM_Array/Scalar_xy, CopyRAM_to_CritNVM_Array/Scalar_xy) are called from handmod tlc code that supports NVM copy s-fcts.
// The handmod tlc code could not directly write the code because the functions need to define a local idx for counting through the arrays
// which cannot be done as part of the tlc code because that code is inlined, and some compilers (e.g. Diab) do not allow a local variable declaration
// in the middle of a function.

/* FUTURE TODO : Add support for byte and long sizes. */


// CopyRAM
// ****** 16Bit ******
void CopyRAM_Array_us(U16 *map_To , U16 *map_From, U16 size)
{
	U16 idx;

	for (idx=0; idx < size; idx ++ ) {
		map_To[idx] = map_From[idx];
	}
}

void CopyRAM_Scalar_us(U16 *map_To , U16 *map_From)
{
	*map_To = *map_From;
}

void CopyRAM_Array_ss(S16 *map_To , S16 *map_From, U16 size)
{
	U16 idx;

	for (idx=0; idx < size; idx ++ ) {
		map_To[idx] = map_From[idx];
	}
}

void CopyRAM_Scalar_ss(S16 *map_To , S16 *map_From)
{
	*map_To = *map_From;
}

// ****** F32 ******
void CopyRAM_Array_fl(float *map_To , float *map_From, U16 size)
{
	U16 idx;

	for (idx=0; idx < size; idx ++ ) {
		map_To[idx] = map_From[idx];
	}
}

void CopyRAM_Scalar_fl(float *map_To , float *map_From)
{
	*map_To = *map_From;
}

// CopyRAM_to_CritNVM
// ****** 16Bit ******
void CopyRAM_to_CritNVM_Array_us(U16 *map_To , U16 *map_From, U16 size)
{
	U16 idx;

	for (idx=0; idx < size; idx ++ ) {
		WriteFILE_NVM_CriticalWord( &map_To[idx], map_From[idx] );
	}
}

void CopyRAM_to_CritNVM_Scalar_us(U16 *map_To , U16 *map_From)
{
	WriteFILE_NVM_CriticalWord( map_To, *map_From );
}

void CopyRAM_to_CritNVM_Array_ss(S16 *map_To , S16 *map_From, U16 size)
{
	U16 idx;

	for (idx=0; idx < size; idx ++ ) {
		WriteFILE_NVM_CriticalWord( &map_To[idx], map_From[idx] );
	}
}

void CopyRAM_to_CritNVM_Scalar_ss(S16 *map_To , S16 *map_From)
{
	WriteFILE_NVM_CriticalWord( map_To, *map_From );
}

// ****** F32 ******
/* Legacy nvmc lib does not support WriteFILE_NVM_CriticalXXXX for XXXX = float */

/*************************************************************************************************
*
* Revision History for AutoCode Data Dictionary Global settings :
*
* Rev.  YYMMDD Who RSM#  Changes
* ----  ------ --- ----- ------------------------------------------------------------------------
* 1.0   140124 mm  11268 Original implementation.
*
*************************************************************************************************/
