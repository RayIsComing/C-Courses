/*
 * File: C:\EMS\Spectool_Work\48v_Autocoding\projFiles\simulink\models\epm_48v_bat_supv_files\slprj\ert\_sharedutils\mul_s32_s32_s32_sr30_sat.c
 *
 *                   Delphi Diesel Systems
 *
 *                   This document is the property of
 *                   Delphi Diesel Systems
 *                   It must not be copied (in whole or in part)
 *                   or disclosed without prior written consent
 *                   of the company. Any copies by any method
 *                   must also include a copy of this legend.
 *
 * Real-Time Workshop code generated for Simulink model epm_48v_bat_supv.
 *
 * Real-Time Workshop file version      : 8.1 (R2011b) 08-Jul-2011
 * Real-Time Workshop file generated on : Wed Sep 21 17:28:24 2016
 * TLC version                          : 8.1 (Jul  9 2011)
 * C source code generated on           : Wed Sep 21 17:28:25 2016
 */

#include "rtwtypes.h"
#include "rtw_shared_utils.h"

S32 mul_s32_s32_s32_sr30_sat(S32 a, S32 b)
{
  S32 result;
  U32 u32_chi;
  U32 u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << 2U | u32_clo >> 30U;
  u32_chi = (U32)((S32)u32_chi >> 30);
  if (((S32)u32_chi > 0) || ((u32_chi == 0U) && (u32_clo >= 2147483648U))) {
    result = MAX_int32_T;
  } else if (((S32)u32_chi < -1) || (((S32)u32_chi == -1) && (u32_clo <
               2147483648U))) {
    result = MIN_int32_T;
  } else {
    result = (S32)u32_clo;
  }

  return result;
}
