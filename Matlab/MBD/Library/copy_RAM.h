/*************************************************************************************************
*
* This file is used for auto-code.  It is manually modified.
*
* Filename:    copy_RAM.h
*
* Description: Header file for misc RAM copy operations.
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
* %full_name:     kok_pt2#1/incl/copy_RAM.h/1 %
* %date_created:  Mon Feb  3 10:38:39 2014 %
* %version:       1 %
* %derived_by:    tzzpjy %
*
*************************************************************************************************/

#ifndef _COPY_RAM_H_
#define _COPY_RAM_H_

#include <ctcm_types.h>


// ***************************** Misc ******************************************

/*******************************************************************************
 *   NVM misc support                                                          *
 *******************************************************************************/
void CopyRAM_Array_us(U16 *map_To , U16 *map_From, U16 size);
void CopyRAM_Scalar_us(U16 *map_To , U16 *map_From);
void CopyRAM_Array_ss(S16 *map_To , S16 *map_From, U16 size);
void CopyRAM_Scalar_ss(S16 *map_To , S16 *map_From);
void CopyRAM_Array_fl(float *map_To , float *map_From, U16 size);
void CopyRAM_Scalar_fl(float *map_To , float *map_From);

void CopyRAM_to_CritNVM_Array_us(U16 *map_To , U16 *map_From, U16 size);
void CopyRAM_to_CritNVM_Scalar_us(U16 *map_To , U16 *map_From);
void CopyRAM_to_CritNVM_Array_ss(S16 *map_To , S16 *map_From, U16 size);
void CopyRAM_to_CritNVM_Scalar_ss(S16 *map_To , S16 *map_From);


#endif

/*************************************************************************************************
*
* Revision History for AutoCode Data Dictionary Global settings :
*
* Rev.  YYMMDD Who RSM#  Changes
* ----  ------ --- ----- ------------------------------------------------------------------------
* 1.0   140124 mm  11268 Original implementation.
*
*************************************************************************************************/

