/*
 * File: C:\Users\hzccpt\Documents\MyDelphi\Tools\Matlab\AutoCode\SpecTool2\Core_RSMs\sys\vios_map_12x\vios_map_12x_files\slprj\ert\_sharedutils\div_su32.c
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
 * Real-Time Workshop code generated for Simulink model vios_map_12x.
 *
 * Real-Time Workshop file version      : 8.1 (R2011b) 08-Jul-2011
 * Real-Time Workshop file generated on : Fri Mar 18 09:57:39 2016
 * TLC version                          : 8.1 (Jul  9 2011)
 * C source code generated on           : Fri Mar 18 09:57:40 2016
 */

#include "rtwtypes.h"
#include "rtw_shared_utils.h"

S32 div_su32(U32 numerator, U32 denominator)
{
  S32 quotient;
  if (denominator == 0) {
    quotient = MAX_int32_T;

    /* Divide by zero handler */
  } else {
    quotient = (S32)(denominator == 0 ? MAX_uint32_T : numerator /
                         denominator);
  }

  return quotient;
}
