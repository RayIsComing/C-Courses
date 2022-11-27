/*
 * File: C:\cvs\BMW_DPH_Layer\BMW_Projects\B38_PST1\Output\Autocode\slprj\ert\_sharedutils\div_repeat_s8s32_floor.c
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
 * Real-Time Workshop file generated on : Wed Apr 21 16:20:52 2010
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Wed Apr 21 16:20:53 2010
 */

#include "rtwtypes.h"

#include "rtw_shared_utils.h"
int8_T div_repeat_s8s32_floor(int32_T numerator, int32_T denominator, uint32_T
 nRepeatSub)
{
  int8_T quotient;
  uint32_T quotientNeedsNegation;
  uint32_T absNumerator;
  uint32_T absDenominator;
  if(denominator == 0) {
    quotient = numerator >= 0 ? MAX_int8_T : MIN_int8_T;
    /* divide by zero handler */
  } else {
    absNumerator = (uint32_T)(numerator >= 0 ? numerator : -numerator);
    absDenominator = (uint32_T)(denominator >= 0 ? denominator : -denominator);
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    if(quotientNeedsNegation) {
      absNumerator = div_repeat_u32_ceiling(absNumerator, absDenominator,
       nRepeatSub);
      quotient = (int8_T)(-((int32_T)absNumerator));
    } else {
      absNumerator = div_repeat_u32(absNumerator, absDenominator, nRepeatSub);
      quotient = (int8_T)absNumerator;
    }
  }
  return quotient;
}

