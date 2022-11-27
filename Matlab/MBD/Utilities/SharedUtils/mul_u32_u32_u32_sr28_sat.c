/*
 * File: C:\EMS\Autocode\Diesel_Autocode_pojects\US_Gas\projFiles\simulink\models\p_t_gpf_model_soot_mass_est_files\slprj\ert\_sharedutils\mul_u32_u32_u32_sr28_sat.c
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
 * Real-Time Workshop file generated on : Mon Feb 26 09:46:02 2018
 * TLC version                          : 8.1 (Jul  9 2011)
 * C source code generated on           : Mon Feb 26 09:46:02 2018
 */

#include "rtwtypes.h"
#include "rtw_shared_utils.h"

U32 mul_u32_u32_u32_sr28_sat(U32 a, U32 b)
{
  U32 result;
  U32 u32_chi;
  U32 u32_clo;
  mul_wide_u32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << 4U | u32_clo >> 28U;
  u32_chi >>= 28U;
  if (u32_chi) {
    result = MAX_uint32_T;
  } else {
    result = u32_clo;
  }

  return result;
}
