/*
 * File: C:\cvs\BMW_DPH_Layer\BMW_Projects\B38_PST1\Output\Autocode\slprj\ert\_sharedutils\div_repeat_u32_sat.c
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
 * Real-Time Workshop code generated for Simulink model bmwl_ConvD2B.
 *
 * Model version                        : 1.1
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Tue Feb 09 08:12:19 2010
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Tue Feb 09 08:12:20 2010
 */

#include "rtwtypes.h"

#include "rtw_shared_utils.h"
uint32_T div_repeat_u32_sat(uint32_T numerator, uint32_T denominator, uint32_T
 nRepeatSub)
{
  uint32_T quotient;
  uint32_T iRepeatSub;
  uint8_T numeratorExtraBit;
  uint32_T tempQuotient;
  uint8_T overflow;
  if(denominator == 0) {
    quotient = MAX_uint32_T;
    /* divide by zero handler */
  } else {
    overflow = 0U;
    tempQuotient = numerator / denominator;
    numerator %= denominator;
    for(iRepeatSub = 0; iRepeatSub < nRepeatSub; iRepeatSub++) {
      numeratorExtraBit = (numerator >= 0x80000000U);
      numerator <<= 1;
      overflow = (overflow || (tempQuotient >= 0x80000000U));
      tempQuotient <<= 1;
      if(numeratorExtraBit || (numerator >= denominator)) {
        tempQuotient++;
        numerator = numerator - denominator;
      }
    }
    if(overflow) {
      quotient = 0xFFFFFFFFU;
    } else {
      quotient = tempQuotient;
    }
  }
  return quotient;
}

