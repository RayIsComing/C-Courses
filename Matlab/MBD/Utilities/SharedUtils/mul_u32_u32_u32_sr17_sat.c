/*
 * File: C:\d\cvs\MDL_GDi_LUX\EMS_Core\FUEL\Model\SCH\autocode\slprj\ert\_sharedutils\mul_u32_u32_u32_sr17_sat.c
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
 * Real-Time Workshop code generated for Simulink model fuelmsch.
 *
 * Model version                        : 1.949
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Wed Feb 09 14:30:43 2011
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Wed Feb 09 14:30:44 2011
 */

#include "rtwtypes.h"

#include "rtw_shared_utils.h"
uint32_T mul_u32_u32_u32_sr17_sat(uint32_T a, uint32_T b)
{
  uint32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_u32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << 15 | u32_clo >> 17;
  u32_chi = u32_chi >> 17;
  if(u32_chi) {
    result = MAX_uint32_T;
  } else {
    result = u32_clo;
  }
  return result;
}

