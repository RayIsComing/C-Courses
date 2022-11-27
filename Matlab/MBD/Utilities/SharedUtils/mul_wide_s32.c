/*
 * File: C:\cvs\GDi_Documentation_JUS\EMS_Core\VVTS\Model\LRN\autocode\slprj\ert\_sharedutils\mul_wide_s32.c
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
 * Real-Time Workshop code generated for Simulink model vvtsmlrn.
 *
 * Model version                        : 1.95
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Mon Jun 28 14:32:47 2010
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Mon Jun 28 14:32:49 2010
 */

#include "rtwtypes.h"

#include "rtw_shared_utils.h"
void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
 *ptrOutBitsLo)
{
  uint32_T outBitsHi;
  uint32_T outBitsLo;
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Hi;
  uint32_T productLoHi;
  uint32_T carry;
  absIn0 = (uint32_T)(in0 < 0 ? -in0 : in0);
  absIn1 = (uint32_T)(in1 < 0 ? -in1 : in1);
  in0Hi = absIn0 >> 16;
  in0Lo = absIn0 & 65535U;
  in1Hi = absIn1 >> 16;
  absIn0 = absIn1 & 65535U;
  absIn1 = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 = in0Lo * absIn0;
  carry = 0;
  outBitsLo = (productLoHi << 16) + absIn0;
  if(outBitsLo < absIn0) {
    carry++;
  }
  absIn0 = outBitsLo;
  outBitsLo = (absIn1 << 16) + outBitsLo;
  if(outBitsLo < absIn0) {
    carry++;
  }
  outBitsHi = ((in0Hi * in1Hi + carry) + (productLoHi >> 16)) + (absIn1 >> 16);
  if(!((in0 == 0) || (in1 == 0) || ((in0 > 0) == (in1 > 0)))) {
    outBitsHi = ~outBitsHi;
    outBitsLo = ~outBitsLo;
    outBitsLo++;
    if(outBitsLo == 0) {
      outBitsHi++;
    }
  }
  *ptrOutBitsHi = outBitsHi;
  *ptrOutBitsLo = outBitsLo;
}

