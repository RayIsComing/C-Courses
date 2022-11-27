/*
 * File: C:\Cvs\GDi_Documentation\EMS_Core\FPRC_BMW\Model\HPCTL\Autocode\slprj\ert\_sharedutils\div_repeat_u32.c
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
uint32_T div_repeat_u32(uint32_T numerator, uint32_T denominator, uint32_T
 nRepeatSub)
{
  uint32_T quotient;
  uint32_T iRepeatSub;
  uint8_T numeratorExtraBit;
  if(denominator == 0) {
    quotient = MAX_uint32_T;
    /* divide by zero handler */
  } else {
    quotient = numerator / denominator;
    numerator %= denominator;
    for(iRepeatSub = 0; iRepeatSub < nRepeatSub; iRepeatSub++) {
      numeratorExtraBit = (numerator >= 0x80000000U);
      numerator <<= 1;
      quotient <<= 1;
      if(numeratorExtraBit || (numerator >= denominator)) {
        quotient++;
        numerator = numerator - denominator;
      }
    }
  }
  return quotient;
}

