/*
 * File: C:\cvs\GDi_Documentation_JUS\EMS_Core\VVTS\slprj\ert\_sharedutils\mul_s32_s32_u32_sr2_sat.c
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
 * Real-Time Workshop code generated for Simulink model vvts_bldcctrl.
 *
 * Model version                        : 1.195
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Wed May 26 11:40:33 2010
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Wed May 26 11:40:33 2010
 */

#include "rtwtypes.h"

#include "rtw_shared_utils.h"

int32_T mul_s32_s32_u32_sr2_sat(int32_T a, uint32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_su32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << 30 | u32_clo >> 2;
  u32_chi = (uint32_T)((int32_T)u32_chi >> 2);
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

