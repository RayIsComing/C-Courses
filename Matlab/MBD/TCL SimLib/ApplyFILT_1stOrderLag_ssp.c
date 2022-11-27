/*
 *   ApplyFILT_1stOrderLag_ssp.c Simple C-MEX S-function for function call.
 *
 *   ABSTRACT:
 *     The purpose of this sfunction is to call a simple legacy 
 *     function during simulation:
 *
 *        int16 y1 = ApplyFILT_1stOrderLag_ssp(int16 u1, int16 u2, uint16 u3)
 *
 *   Simulink version           : 6.6 (R2007a) 01-Feb-2007
 *   C source code generated on : 11-Jul-2007 15:51:20
 */

/*
   %%%-MATLAB_Construction_Commands_Start
   def = legacy_code('initialize');
   def.SFunctionName = 'ApplyFILT_1stOrderLag_ssp';
   def.OutputFcnSpec = 'int16 y1 = ApplyFILT_1stOrderLag_ssp(int16 u1, int16 u2, uint16 u3)';
   def.HeaderFiles = {'filtlib.h'};
   def.SourceFiles = {'filtlib.c'};
   legacy_code('sfcn_cmex_generate', def);
   legacy_code('compile', def);
   %%%-MATLAB_Construction_Commands_End
 */

/*
 * Must specify the S_FUNCTION_NAME as the name of the S-function.
 */
#define S_FUNCTION_NAME                 ApplyFILT_1stOrderLag_ssp
#define S_FUNCTION_LEVEL                2

/*
 * Need to include simstruc.h for the definition of the SimStruct and
 * its associated macro definitions.
 */
#include "simstruc.h"

/*
 * Specific header file(s) required by the legacy code function.
 */
#include "filtlib.h"

/* Function: mdlInitializeSizes ===========================================
 * Abstract:
 *    The sizes information is used by Simulink to determine the S-function
 *    block's characteristics (number of inputs, outputs, states, etc.).
 */
static void mdlInitializeSizes(SimStruct *S)
{
  /* Number of expected parameters */
  ssSetNumSFcnParams(S, 0);

  /*
   * Set the number of dworks. 
   */
  if (! ssSetNumDWork(S, 0)) return;

  /*
   * Set the number of input ports. 
   */
  if (!ssSetNumInputPorts(S, 3)) return;

  /*
   * Configure the input port 1
   */
  ssSetInputPortDataType(S, 0, DYNAMICALLY_TYPED);
  ssSetInputPortWidth(S, 0, 1);
  ssSetInputPortComplexSignal(S, 0, COMPLEX_NO);
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortAcceptExprInRTW(S, 0, 1);
  ssSetInputPortOverWritable(S, 0, 1);
  ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
  ssSetInputPortRequiredContiguous(S, 0, 1);

  /*
   * Configure the input port 2
   */
  ssSetInputPortDataType(S, 1, DYNAMICALLY_TYPED);
  ssSetInputPortWidth(S, 1, 1);
  ssSetInputPortComplexSignal(S, 1, COMPLEX_NO);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortAcceptExprInRTW(S, 1, 1);
  ssSetInputPortOverWritable(S, 1, 1);
  ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
  ssSetInputPortRequiredContiguous(S, 1, 1);

  /*
   * Configure the input port 3
   */
  ssSetInputPortDataType(S, 2, DYNAMICALLY_TYPED);
  ssSetInputPortWidth(S, 2, 1);
  ssSetInputPortComplexSignal(S, 2, COMPLEX_NO);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetInputPortAcceptExprInRTW(S, 2, 1);
  ssSetInputPortOverWritable(S, 2, 1);
  ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
  ssSetInputPortRequiredContiguous(S, 2, 1);

  /*
   * Set the number of output ports.
   */
  if (!ssSetNumOutputPorts(S, 1)) return;

  /*
   * Configure the output port 1
   */
  ssSetOutputPortDataType(S, 0, DYNAMICALLY_TYPED);
  ssSetOutputPortWidth(S, 0, 1);
  ssSetOutputPortComplexSignal(S, 0, COMPLEX_NO);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
  ssSetOutputPortOutputExprInRTW(S, 0, 1);

  /*
   * Set the number of sample time. 
   */
  ssSetNumSampleTimes(S, 1);

  /*
   * All options have the form SS_OPTION_<name> and are documented in
   * matlabroot/simulink/include/simstruc.h. The options should be
   * bitwise or'd together as in
   *   ssSetOptions(S, (SS_OPTION_name1 | SS_OPTION_name2))
   */
  ssSetOptions(S,
   SS_OPTION_USE_TLC_WITH_ACCELERATOR |
   SS_OPTION_CAN_BE_CALLED_CONDITIONALLY |
   SS_OPTION_EXCEPTION_FREE_CODE |
   SS_OPTION_WORKS_WITH_CODE_REUSE |
   SS_OPTION_SFUNCTION_INLINED_FOR_RTW |
   SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME);
}

/* Function: mdlInitializeSampleTimes =====================================
 * Abstract:
 *    This function is used to specify the sample time(s) for your
 *    S-function. You must register the same number of sample times as
 *    specified in ssSetNumSampleTimes.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
  ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);

#if defined(ssSetModelReferenceSampleTimeDefaultInheritance)
  ssSetModelReferenceSampleTimeDefaultInheritance(S);
#endif
}


static int16_T AppFILT_1stOrderLag_ssp(int16_T *LfFILT_Old,
                                       int16_T *LfFILT_New,
                                       uint16_T *LfFILT_k_Coeff )
  {
  int16_T LfFILT_Result;
  int32_T LfFILT_TempResult;
  //ssPrintf("LfFILT_Old = %i;\n",*LfFILT_Old);
  //ssPrintf("LfFILT_New = %i;\n",*LfFILT_New);
  
  if ( (*LfFILT_Old == *LfFILT_New)
     || (LfFILT_k_Coeff == 0) )
      {
         LfFILT_Result = *LfFILT_Old;
      }

  else if (*LfFILT_New > *LfFILT_Old)
      {
          LfFILT_Result=*LfFILT_New-*LfFILT_Old;
          LfFILT_TempResult=(int32_T)(*LfFILT_k_Coeff  * LfFILT_Result);
          //ssPrintf("LfFILT_TempResult (case New > Old) = %i;\n",LfFILT_TempResult);
          
 		  LfFILT_Result=(int16_T)(LfFILT_TempResult>>16); //Fixed point type T_FILTER
          if (LfFILT_Result == 0)
              {
                 LfFILT_Result = 0x0001;  /* Force a change of 1 LSB */
              }

          LfFILT_Result= *LfFILT_Old+LfFILT_Result;
      }

  else /* if (LfFILT_New < LfFILT_Old) */
      {
         LfFILT_Result=*LfFILT_Old-*LfFILT_New;
         LfFILT_TempResult=(int32_T)(*LfFILT_k_Coeff * LfFILT_Result);
         //ssPrintf("LfFILT_TempResult (case New < Old) = %i;\n",LfFILT_TempResult);         
 		 LfFILT_Result=(int16_T)(LfFILT_TempResult>>16); //Fixed point type T_FILTER
         if (LfFILT_Result == 0)
              {
                 LfFILT_Result = 0x0001;  /* Force a change of 1 LSB */
              }

          LfFILT_Result=*LfFILT_Old - LfFILT_Result;
      } /* end if (LfFILT_Old > LfFILT_New) */
  //ssPrintf("LfFILT_Result = %i;\n",LfFILT_Result);
  return(LfFILT_Result);
}

/* Function: mdlOutputs ===================================================
 * Abstract:
 *    In this function, you compute the outputs of your S-function
 *    block. Generally outputs are placed in the output vector(s),
 *    ssGetOutputPortSignal.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  /*
   * Get access to Parameter/Input/Output/DWork/size information
   */
  int16_T *u1 = (int16_T *) ssGetInputPortSignal(S, 0);
  int16_T *u2 = (int16_T *) ssGetInputPortSignal(S, 1);
  uint16_T *u3 = (uint16_T *) ssGetInputPortSignal(S, 2);
  int16_T *y1 = (int16_T *) ssGetOutputPortSignal(S, 0);

  /*
   * Call the legacy code function
   */
  *y1 = AppFILT_1stOrderLag_ssp( u1, u2, u3);
}

/* Function: mdlTerminate =================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.
 */
static void mdlTerminate(SimStruct *S)
{
}

/*
 * Required S-function trailer
 */
#ifdef MATLAB_MEX_FILE
# include "simulink.c"
#else
# include "cg_sfun.h"
#endif
