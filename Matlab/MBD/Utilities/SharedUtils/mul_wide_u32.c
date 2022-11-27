/*
 * File: C:\cvs\GDi_Documentation_JUS\EMS_Core\VVTS\slprj\ert\_sharedutils\mul_wide_u32.c
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
 * Model version                        : 1.174
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Thu May 20 17:08:00 2010
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Thu May 20 17:08:00 2010
 */

#include "rtwtypes.h"

#include "rtw_shared_utils.h"
void mul_wide_u32(uint32_T in0, uint32_T in2, uint32_T *ptrOutBitsHi, uint32_T
 *ptrOutBitsLo)
{
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  uint32_T carry;
  in0Hi = in0 >> 16;
  in0Lo = in0 & 65535U;
  in1Hi = in2 >> 16;
  in1Lo = in2 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = in0Lo * in1Hi;
  in0Lo = in0Lo * in1Lo;
  carry = 0;
  in1Lo = (productLoHi << 16) + in0Lo;
  if(in1Lo < in0Lo) {
    carry++;
  }
  in0Lo = in1Lo;
  in1Lo = (productHiLo << 16) + in1Lo;
  if(in1Lo < in0Lo) {
    carry++;
  }
  in0Lo = ((in0Hi * in1Hi + carry) + (productLoHi >> 16)) + (productHiLo >> 16);
  *ptrOutBitsHi = in0Lo;
  *ptrOutBitsLo = in1Lo;
}

