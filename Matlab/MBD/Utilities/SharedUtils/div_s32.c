/*
 * File: C:\cvs\GDi_Documentation\EMS_Core\SPRK\Model\SS\Autocode\slprj\ert\_sharedutils\div_s32.c
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
 * Real-Time Workshop code generated for Simulink model sprkmss.
 *
 * Model version                        : 1.457
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Wed Sep 08 13:38:13 2010
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Wed Sep 08 13:38:14 2010
 */

#include "rtwtypes.h"
#include "rtw_shared_utils.h"

int32_T div_s32(int32_T sf_numerator, int32_T sf_denominator)
{
  uint32_T sf_absNumerator;
  uint32_T sf_absDenominator;
  uint32_T sf_quotientNeedsNegation;
  uint32_T sf_tempAbsQuotient;
  if(sf_denominator == 0) {
    return (int32_T)(sf_numerator >= 0 ? MAX_int32_T : MIN_int32_T);
  } else {
   sf_absNumerator = (uint32_T)(sf_numerator >= 0 ? sf_numerator :
      -sf_numerator);
   sf_absDenominator = (uint32_T)(sf_denominator >= 0 ? sf_denominator :
      -sf_denominator);
    sf_quotientNeedsNegation = (uint32_T)((sf_numerator < 0) != (sf_denominator
      < 0));
    sf_tempAbsQuotient = (uint32_T)(sf_absNumerator / sf_absDenominator);
    return (int32_T)(sf_quotientNeedsNegation ?
     (int32_T)(-((int32_T)sf_tempAbsQuotient)) : (int32_T)sf_tempAbsQuotient);
  }
}

