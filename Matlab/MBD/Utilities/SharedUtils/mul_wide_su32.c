/*
 * File: C:\cvs\GDi_Documentation_JUS\EMS_Core\VVTS\slprj\ert\_sharedutils\mul_wide_su32.c
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
 * Real-Time Workshop code generated for Simulink model vvts_bldcctrl.
 *
 * Model version                        : 1.195
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Wed May 26 11:40:33 2010
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Wed May 26 11:40:33 2010
 */

#include "rtwtypes.h"

#include "rtw_shared_utils.h"
void mul_wide_su32(int32_T in0, uint32_T in2, uint32_T *ptrOutBitsHi, uint32_T
 *ptrOutBitsLo)
{
  uint32_T outBitsHi;
  uint32_T outBitsLo;
  uint32_T absIn0;
  uint32_T in0Hi;
  uint32_T in1Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  uint32_T carry;
  absIn0 = (uint32_T)(in0 < 0 ? -in0 : in0);
  in0Hi = absIn0 >> 16;
  absIn0 = absIn0 & 65535U;
  in1Hi = in2 >> 16;
  in1Lo = in2 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = absIn0 * in1Hi;
  absIn0 = absIn0 * in1Lo;
  carry = 0;
  outBitsLo = (productLoHi << 16) + absIn0;
  if(outBitsLo < absIn0) {
    carry++;
  }
  absIn0 = outBitsLo;
  outBitsLo = (productHiLo << 16) + outBitsLo;
  if(outBitsLo < absIn0) {
    carry++;
  }
  outBitsHi = ((in0Hi * in1Hi + carry) + (productLoHi >> 16)) + (productHiLo >>
    16);
  if(!((in2 == 0) || (in0 >= 0))) {
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

