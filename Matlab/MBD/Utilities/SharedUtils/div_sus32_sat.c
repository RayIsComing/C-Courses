/*
 * File: d:\cvs\gsxxxwa\simulink\models\slprj\ert\_sharedutils\div_sus32_sat.c
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
 * Real-Time Workshop code generated for Simulink model acm_vgt_bst_dmnd.
 *
 * Model version                        : 1.231
 * Real-Time Workshop file version      : 6.3  (R14SP3)  26-Jul-2005
 * Real-Time Workshop file generated on : Fri Nov 25 14:22:09 2005
 * TLC version                          : 6.3 (Aug  5 2005)
 * C source code generated on           : Fri Nov 25 14:22:09 2005
 */

#include "rtwtypes.h"

#include "rtw_shared_utils.h"
S32 div_sus32_sat(U32 numerator, S32 denominator)
{
  S32 quotient;
  U32 tempAbsQuotient;
  U32 quotientNeedsNegation;
  if(denominator == 0) {
    quotient = MAX_int32_T;
    /* divide by zero handler */
  } else {
    quotientNeedsNegation = (denominator < 0);
    tempAbsQuotient = (U32)(numerator / (U32)(denominator >= 0 ?
      denominator : -denominator));
    if((!quotientNeedsNegation) && (tempAbsQuotient >= 2147483647U)) {
      return MAX_int32_T;
    } else if(quotientNeedsNegation && (tempAbsQuotient > 2147483647U)) {
      return MIN_int32_T;
    } else {
     return quotientNeedsNegation ? (S32)-(S32)tempAbsQuotient :
      (S32)tempAbsQuotient;
    }
  }
  return quotient;
}

