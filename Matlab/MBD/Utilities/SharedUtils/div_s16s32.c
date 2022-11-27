/*
 * File: C:\Cvs\GDi_Documentation\EMS_Core\FPRC_BMW\Model\HPCTL\Autocode\slprj\ert\_sharedutils\div_s16s32.c
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
int16_T div_s16s32(int32_T numerator, int32_T denominator)
{
  int16_T quotient;
  uint32_T tempAbsQuotient;
  uint32_T quotientNeedsNegation;
  if(denominator == 0) {
    quotient = numerator >= 0 ? MAX_int16_T : MIN_int16_T;
    /* divide by zero handler */
  } else {
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
   tempAbsQuotient = (uint32_T)((uint32_T)(numerator >= 0 ? numerator :
      -numerator) / (uint32_T)(denominator >= 0 ? denominator : -denominator));
   quotient = quotientNeedsNegation ? (int16_T)(-((int32_T)tempAbsQuotient)) :
      (int16_T)tempAbsQuotient;
  }
  return quotient;
}

