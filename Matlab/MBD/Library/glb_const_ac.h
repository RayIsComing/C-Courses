#ifndef GLB_CONST_AC_H
#define GLB_CONST_AC_H
 
/*************************************************************************************************
*
* This file is generated by auto-scripting.  It should not be manually modified, but via DD entry.
*
* Filename:    glb_const_ac.h
*
* Description: AutoCode Global Scalar Constant definitions.
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
* %full_name:     kok_pt2#3/incl/glb_const_ac.h/3.1.2 %
* %date_created:  Mon Feb  3 10:38:42 2014 %
* %version:       3.1.2 %
* %derived_by:    tzzpjy %
*
*************************************************************************************************/
 
 
/******************************************************************************************
 *    Global Data Type Include Files                                                      *
 ******************************************************************************************/
#include  "t_apptypes.h"                  /* Generic data types                           */
 
 
/******************************************************************************************
 *    Global Scalar Constant Definitions for Auto-Code                                    *
 ******************************************************************************************/
 
 
#define CbTRUE                          ( CbTRUE )          /* True                       */
#define CbFALSE                         ( CbFALSE )         /* False                      */
#define Cf_CONVERT_RATIO_TO_PCT         ( 100.0F )          /* Conversion factor          */
#define Cf_CONVERT_PCT_TO_RATIO         ( 0.01F )           /* Conversion factor          */
#define Cf_F32_n1                       ( -1.0F )           /* value = -1                 */
#define Cf_F32_0                        ( 0.0F )            /* value = 0                  */
#define Cf_F32_1                        ( 1.0F )            /* value = 1                  */
#define Cf_F32_2                        ( 2.0F )            /* value = 2                  */
#define Cf_F32_3                        ( 3.0F )            /* value = 3                  */
#define Cf_F32_4                        ( 4.0F )            /* value = 4                  */
#define Cf_F32_10                       ( 10.0F )           /* value = 10                 */
#define Cf_F32_0p5                      ( 0.5F )            /* value = 0.5                */
#define eps                             ( 0.000001F )       /* epsilon, effective zero for floating point calcs*/
#define Cf_FILTER_1                     ( V_FILTER(0.99997) )/* Max value of filter coefficient.*/
#define k_a                             ( V_FIX_U16_15(1.4) )/* Ratio of specific heats for air [ratio]*/
#define k_e                             ( V_FIX_U16_15(1.33) )/* Ratio of specific heats for exhaust [ratio]*/
#define cp_a                            ( V_FIX_U16_05(1004.5) )/* Specific heat capacity at constant pressure, air [J/kgK]*/
#define cp_e                            ( V_FIX_U16_05(1156.6969) )/* Specific heat capacity at constant pressure, exhaust [J/kgK]*/
#define cp_a_over_cp_e                  ( V_FIX_U16_16(0.868421052631579) )/* cp_a / cp_e [ratio]*/
#define Cc_U16_00_val_0                 ( V_FIX_U16_00(0) )
#define Cc_U16_00_val_1                 ( V_FIX_U16_00(1) )
 
 
#endif /* GLB_CONST_AC_H */
 
 
/*************************************************************************************************
*
* Revision History for AutoCode Data Dictionary Global settings :
*
* Rev.  YYMMDD Who RSM#  Changes 
* ----  ------ --- ----  ------------------------------------------------------------------------ 
* 1.0   110222 mm  9300  Original implementation as part of introducing new auto-code process.
* 2.0   120524 mm  9855  Addition of physical constants.
*
*************************************************************************************************/
