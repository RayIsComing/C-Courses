/*
 * File: C:\cvs\GDi_Documentation_JUS\EMS_Core\VVTS\slprj\ert\_sharedutils\mul_u32_u32_u32_sr9_sat.c
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
 * Model version                        : 1.174
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Thu May 20 17:08:00 2010
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Thu May 20 17:08:00 2010
 */

#include "rtwtypes.h"

#include "rtw_shared_utils.h"
uint32_T mul_u32_u32_u32_sr9_sat(uint32_T a, uint32_T b)
{
  uint32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_u32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << 23 | u32_clo >> 9;
  u32_chi = u32_chi >> 9;
  if(u32_chi) {
    result = MAX_uint32_T;
  } else {
    result = u32_clo;
  }
  return result;
}

