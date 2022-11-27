/*
 * File: C:\EMS\Spectool_Work\48v_Autocoding\projFiles\simulink\models\p_t_gpf_model_soot_mass_est_files\slprj\ert\_sharedutils\mul_s32_s32_u32_sr7_sat.c
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
 * Real-Time Workshop code generated for Simulink model p_t_gpf_model_soot_mass_est.
 *
 * Real-Time Workshop file version      : 8.1 (R2011b) 08-Jul-2011
 * Real-Time Workshop file generated on : Tue Apr 10 15:25:29 2018
 * TLC version                          : 8.1 (Jul  9 2011)
 * C source code generated on           : Tue Apr 10 15:25:32 2018
 */

#include "rtwtypes.h"
#include "rtw_shared_utils.h"

S32 mul_s32_s32_u32_sr7_sat(S32 a, U32 b)
{
  S32 result;
  U32 u32_chi;
  U32 u32_clo;
  mul_wide_su32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << 25U | u32_clo >> 7U;
  u32_chi = (U32)((S32)u32_chi >> 7);
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
