/*************************************************************************************************
*
* This file is used for auto-code.  It is manually modified.
*
* Filename:    lookup_fl.h
*
* Description: Header file for floating pt look-up.
*              Initial content from Delphi Diesel, but cleaned up for CTCM use.
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
* %full_name:     kok_pt2#1/incl/lookup_fl.h/1 %
* %date_created:  Fri Apr  8 16:19:31 2011 %
* %version:       1 %
* %derived_by:    tzzpjy %
*
*************************************************************************************************/

#ifndef _LOOKUP_FL_H_
#define _LOOKUP_FL_H_
#include <ctcm_types.h> 


/*******************************************************************************
 *   Helper functions                                                          *
 *******************************************************************************/
float interpolate_fl_ratio(float m1, float m2,float frac_num );

/*******************************************************************************
 *   2D LookUp : Idx vs. Val                                                   *
 *******************************************************************************/
U16 idx_Lookup_fl(const float *column,float target, U16 size);

/*******************************************************************************
 *   2D LookUp : Val vs. Idx                                                   *
 *******************************************************************************/
float fl_LookUp_idx(const float *column,U16 x,U16 size);

/*******************************************************************************
 *   3D LookUp : Val vs. Idx                                                   *
 *******************************************************************************/
float fl_LookUp_idx_idx(const float* TblData,U16 x_idx,U16 y_idx, U16 x_length, U16 y_length);


#endif

/*************************************************************************************************
*
* Revision History for AutoCode Data Dictionary Global settings :
*
* Rev.  YYMMDD Who RSM# Changes 
* ----  ------ --- ---- ------------------------------------------------------------------------ 
* 1.0   110321 mm  9300 Original implementation as part of introducing new auto-code process.
*
*************************************************************************************************/


