/*
 * File: C:\cvs\GDi_Documentation_JUS\EMS_Core\VVTS\Model\LRN\autocode\slprj\ert\_sharedutils\mul_s32_s32_s32_sat.c
 *
 *                   Delphi Powertrain Systems
 *
 *                   This document is the property of
 *                   Delphi Powertrain Systems
 *                   It must not be copied (in whole or in part)
 *                   or disclosed without prior written consent
 *                   of the company. Any copies by any method
 *                   must also include a copy of this legend.
 *
 * Real-Time Workshop code generated for Simulink model vvtsmlrn.
 *
 * Model version                        : 1.95
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Mon Jun 28 14:32:47 2010
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Mon Jun 28 14:32:49 2010
 */

#include "rtwtypes.h"

#include "rtw_shared_utils.h"

#include "mul_wide_s32.h"
int32_T mul_s32_s32_s32_sat(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  if(((int32_T)u32_chi > 0) || ((u32_chi == 0) && (u32_clo >= 2147483648U))) {
    result = MAX_int32_T;
  } else if(((int32_T)u32_chi < -1) || (((int32_T)u32_chi == -1) && (u32_clo <
     2147483648U))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }
  return result;
}

