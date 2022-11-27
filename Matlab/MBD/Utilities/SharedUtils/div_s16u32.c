/*
 * File: C:\Cvs\GDi_Documentation\EMS_Core\FPRC_BMW\Model\HPCTL\Autocode\slprj\ert\_sharedutils\div_s16u32.c
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
 * Real-Time Workshop code generated for Simulink model fprcmhpctl.
 *
 * Model version                        : 1.853
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Mon Jan 25 10:10:11 2010
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Mon Jan 25 10:10:13 2010
 */

#include "rtwtypes.h"

#include "rtw_shared_utils.h"
int16_T div_s16u32(uint32_T numerator, uint32_T denominator)
{
  int16_T quotient;
  if(denominator == 0) {
    quotient = MAX_int16_T;
    /* divide by zero handler */
  } else {
    quotient = (int16_T)(uint32_T)(numerator / denominator);
  }
  return quotient;
}

