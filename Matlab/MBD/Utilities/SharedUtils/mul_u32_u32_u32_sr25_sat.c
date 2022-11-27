/*
 * File: M:\task_bourgeoj_gv21225\gill_vob\6_coding\src\appli\fqd\tests\fqd_post_exh_temp_ctrl_vw_tests\slprj\ert\_sharedutils\mul_u32_u32_u32_sr25_sat.c
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
 * Real-Time Workshop code generated for Simulink model fqd_post_exh_temp_ctrl_vw.
 *
 * Real-Time Workshop file version      : 6.6  (R2007a)  01-Feb-2007
 * Real-Time Workshop file generated on : Thu Jul 09 14:27:33 2009
 * TLC version                          : 6.6 (Jan 16 2007)
 * C source code generated on           : Thu Jul 09 14:27:37 2009
 */

#include "rtwtypes.h"

#include "rtw_shared_utils.h"
U32 mul_u32_u32_u32_sr25_sat(U32 a, U32 b)
{
  U32 result;
  U32 u32_chi;
  U32 u32_clo;
  mul_wide_u32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << 7 | u32_clo >> 25;
  u32_chi = u32_chi >> 25;
  if(u32_chi) {
    result = MAX_uint32_T;
  } else {
    result = u32_clo;
  }
  return result;
}

