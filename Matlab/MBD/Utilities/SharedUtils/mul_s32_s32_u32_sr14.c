/*
 * File: C:\projFiles\simulink\models\p_t_gpf_model_soot_mass_est_files\slprj\ert\_sharedutils\mul_s32_s32_u32_sr14.c
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
 * Real-Time Workshop file generated on : Wed Jul 25 13:25:39 2018
 * TLC version                          : 8.1 (Jul  9 2011)
 * C source code generated on           : Wed Jul 25 13:25:40 2018
 */

#include "rtwtypes.h"
#include "rtw_shared_utils.h"

S32 mul_s32_s32_u32_sr14(S32 a, U32 b)
{
  U32 u32_chi;
  U32 u32_clo;
  mul_wide_su32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << 18U | u32_clo >> 14U;
  return (S32)u32_clo;
}
