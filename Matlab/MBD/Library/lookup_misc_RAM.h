/*************************************************************************************************
*
* This file is used for auto-code.  It is manually modified.
*
* Filename:    lookup_misc_RAM.h
*
* Description: Header file for RAM look-up and misc. RAM operations.
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
* %full_name:     kok_pt2#2/incl/lookup_misc_RAM.h/2 %
* %date_created:  Mon Feb  3 10:38:45 2014 %
* %version:       2 %
* %derived_by:    tzzpjy %
*
*************************************************************************************************/

#ifndef _LOOKUP_MISC_RAM_H_
#define _LOOKUP_MISC_RAM_H_

#include <ctcm_types.h>
#include <lookup_fl.h>	 /* for interpolate_fl_ratio() */

// ***************************** Table Look-Up *********************************

/*******************************************************************************
 *   Table Look-Up helper functions                                            *
 *******************************************************************************/
// ****** 16Bit ******
U16 interpolate_uw_RAM(U16 m1, U16 m2, U16 frac_num, U16 frac_den);
U16 interpolate_uw_ratio_RAM(U16 m1, U16 m2, U16 frac_num, U16 frac_den);
S16 interpolate_sw_RAM(S16 m1, S16 m2, U16 frac_num, U16 frac_den);
S16 interpolate_sw_ratio_RAM(S16 m1, S16 m2, U16 frac_num, U16 frac_den);
// ****** F32 ******
/* Reuse interpolate_fl_ratio() from lookup_fl.c/.h */


// ********* Table Look-Up **********

/*******************************************************************************
 *   2D LookUp : Idx vs. Val                                                   *
 *******************************************************************************/
// ****** 16Bit ******
U16 usLookup_Independent_xy_us_RAM(U16 * column, U16 target, U16 size);
U16 usLookup_Independent_xy_ss_RAM(S16 * column, S16 target, U16 size);
// ****** F32 ******
U16 idx_Lookup_fl_RAM(float *column,float target, U16 size);


/*******************************************************************************
 *   2D LookUp : Val vs. Idx                                                   *
 *******************************************************************************/
// ****** 16Bit ******
U16 usLookup_xy_us_RAM(U16 *column, U16 x, U16 size);
S16 ssLookup_xy_us_RAM(S16 *column, U16 x, U16 size);
// ****** F32 ******
float fl_LookUp_idx_RAM(float *column,U16 x,U16 size);


/*******************************************************************************
 *   3D LookUp : Val vs. Idx                                                   *
 *******************************************************************************/
// ****** 16Bit ******
U16 usLookup_xyz_us_us_RAM(U16* TblData,U16 x_idx,U16 y_idx, U16 x_length, U16 y_length);
S16 ssLookup_xyz_us_us_RAM(S16* TblData,U16 x_idx,U16 y_idx, U16 x_length, U16 y_length);
// ****** F32 ******
float fl_LookUp_idx_idx_RAM(float* TblData,U16 x_idx,U16 y_idx, U16 x_length, U16 y_length);


// ***************************** Misc ******************************************

/*******************************************************************************
 *   NVM misc support                                                          *
 *******************************************************************************/
void write_RAMcopy_to_CritNVM_us(U16 CritNVM_tbl, U16 size);
void write_RAMcopy_to_CritNVM_ss(S16 CritNVM_tbl, U16 size);
void write_RAMcopy_to_CritNVM_fl(float CritNVM_tbl, U16 size);
void write_RAMcopy_to_NonCritNVM_us(U16 CritNVM_tbl, U16 size);
void write_RAMcopy_to_NonCritNVM_ss(S16 CritNVM_tbl, U16 size);
void write_RAMcopy_to_NonCritNVM_fl(float CritNVM_tbl, U16 size);
void write_CritNVM_to_RAMcopy_us(U16 CritNVM_tbl, U16 size);
void write_CritNVM_to_RAMcopy_ss(S16 CritNVM_tbl, U16 size);
void write_CritNVM_to_RAMcopy_fl(float CritNVM_tbl, U16 size);


#endif

/*************************************************************************************************
*
* Revision History for AutoCode Data Dictionary Global settings :
*
* Rev.  YYMMDD Who RSM#  Changes
* ----  ------ --- ----- ------------------------------------------------------------------------
* 1.0   120327 mm  10120 Original implementation.
* 2.0   140124 mm  11268 RAMcopy changes.
*
*************************************************************************************************/

