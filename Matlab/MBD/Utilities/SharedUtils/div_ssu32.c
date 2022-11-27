/*
 * File: C:\EMS\Autocode\Diesel_Autocode_pojects\US_Gas\projFiles\simulink\models\p_t_gpf_dp_soot_mass_est_files\slprj\ert\_sharedutils\div_ssu32.c
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
 * Real-Time Workshop code generated for Simulink model p_t_gpf_dp_soot_mass_est.
 *
 * Real-Time Workshop file version      : 8.1 (R2011b) 08-Jul-2011
 * Real-Time Workshop file generated on : Mon Feb 26 09:12:06 2018
 * TLC version                          : 8.1 (Jul  9 2011)
 * C source code generated on           : Mon Feb 26 09:12:06 2018
 */

#include "rtwtypes.h"
#include "rtw_shared_utils.h"

S32 div_ssu32(S32 numerator, U32 denominator)
{
  S32 quotient;
  U32 tempAbsQuotient;
  U32 quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    quotientNeedsNegation = (numerator < 0);
    tempAbsQuotient = denominator == 0 ? MAX_uint32_T : (U32)(numerator >=
      0 ? numerator : -numerator) / denominator;
    quotient = quotientNeedsNegation ? -(S32)tempAbsQuotient : (S32)
      tempAbsQuotient;
  }

  return quotient;
}
