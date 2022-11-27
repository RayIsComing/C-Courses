/*
 *   usLookup_xyz_us_us.c Simple C-MEX S-function for function call.
 *
 *   ABSTRACT:
 *     The purpose of this sfunction is to call a simple legacy 
 *     function during simulation:
 *
 *        uint16 y1 = usLookup_xyz_us_us(uint16 u1[1], uint16 u2, uint16 u3)
 *
 *   Simulink version           : 6.6 (R2007a) 01-Feb-2007
 *   C source code generated on : 04-Jul-2007 10:17:09
 */

/*
   %%%-MATLAB_Construction_Commands_Start
   def = legacy_code('initialize');
   def.SFunctionName = 'usLookup_xyz_us_us';
   def.OutputFcnSpec = 'uint16 y1 = usLookup_xyz_us_us(uint16 u1[1], uint16 u2, uint16 u3)';
   def.HeaderFiles = {'mathlib.h'};
   def.SourceFiles = {'mathlib.c'};
   legacy_code('sfcn_cmex_generate', def);
   legacy_code('compile', def);
   %%%-MATLAB_Construction_Commands_End
 */

/*
 * Must specify the S_FUNCTION_NAME as the name of the S-function.
 */
#define S_FUNCTION_NAME                 usLookup_xyz_us_us
#define S_FUNCTION_LEVEL                2

/*
 * Need to include simstruc.h for the definition of the SimStruct and
 * its associated macro definitions.
 */
#include "simstruc.h"

/*
 * Specific header file(s) required by the legacy code function.
 */
#include "mathlib.h"
#include "types.h"



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
   * Configure the input port 1 (map)
   */
  ssSetInputPortDataType(S, 0, DYNAMICALLY_TYPED);
  ssSetInputPortWidth(S, 0,DYNAMICALLY_SIZED);
  ssSetInputPortDimensionInfo( S, 0, DYNAMIC_DIMENSION);
  ssSetInputPortComplexSignal(S, 0, COMPLEX_NO);
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortAcceptExprInRTW(S, 0, 0);
  ssSetInputPortOverWritable(S, 0, 0);
  ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
  ssSetInputPortRequiredContiguous(S, 0, 1);

  /*
   * Configure the input port 2 (ind-x)
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
   * Configure the input port 3 (ind-y)
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



/*******************************************************************************
*
*  Function Name   :    lib_umap3d
*  Description     :    see above comment
*
*******************************************************************************/
// U16 lib_umap3d(MAP3D_U16* map, U16 x, U16 y)
U16 usLookup_xyz_us_us(MAP3D_U16* map, U16 x, U16 y)
{

   U16_CAL * xv_p;    /* A pointer to 2 elements of the x vector. */
   U16_CAL * yv_p;    /* A pointer to 2 elements of the y vector. */
   U16_CAL * zm_p;    /* A pointer to 2 elements of the desired row of zmat */
   U16   x_size;  /* A local copy of map->x_size (for efficiency). */

   /* DETERMINE BRACKETTING X & Y VALUES. */

   /* find bracketting x values, x values decrease in value by defn.
   ** nx & nx+1 will be the indexes into the x vector
   ** if x lies outside xval[0] .. xval[x_size-1] then return the nearest
   ** x index.
   */
   x_size   = map->x_size;
   xv_p     = map->xval;  /* Point to first component of x vector */
   yv_p     = map->yval;  /* Point to first component of y vector */

   {  /* Block containing nx, ny */

       U16 nx;              /* index into x vector */
       U16 ny;              /* index into y vector */


       /* find bracketting x values, x values increase in value by defn. */

       if (x < *xv_p)              /* If x lies outside the defined range ... */
       {
           nx=0;                   /* ... then the search is done, else ...   */
       }
       else
       {
           nx = x_size-(U16)1;      /* ...  search from the last element.     */
           xv_p += nx;
           do
           {
               --xv_p;
               --nx;
           }
          while (x < *xv_p);

          /* From above tests loop is guaranteed to terminate within the array
          ** and both xv_p & (xv_p+1) point into the x vector.
          */

       }            /* end if */


       /* find bracketting y values, y values increase in value by defn. */

       if (y < *yv_p)              /* If y lies outside the defined range ... */
       {
           ny=0;                   /* ... then the search is done, else ... */
       }
       else
       {                           /* ...  search from the last element. */
           ny = (U16)map->y_size-(U16)1;
           yv_p += ny;
           do
           {
               --yv_p;
               --ny;
           }
          while (y < *yv_p);

          /* From above tests loop is guaranteed to terminate within the array
          ** and both yv_p & (yv_p+1) point into the y vector.
          */
       }            /* end if */


       /* Set pointer to cell within z-matrix. */

       zm_p = map->zmat + ny*x_size + nx;  /* point to col nx, row ny */

   }   /* Block containing nx, ny */

   /* DETERMINE Z VALUE */


   /* Both x & y may be on a limit or else fall within their permitted range.
   ** The function interpolate1d_U16 effectively 'clips' x & y to fall within
   ** their permitted range.
   */

   {    /* Block containing z2d */


        /* STAGE I: Collapse x dimension of 2-d cell onto line with
        **          desired x value.
        */

        U16 z2d[2];

        /* Interpolation along yv[0] to give z2d[0] */

        z2d[0] =  interpolate1d_U16( x, xv_p, zm_p );

        /* Interpolation along yv[1] to give z2d[1]  */

        zm_p += x_size;     /* Point to col nx, row ny+1 */
        z2d[1] =  interpolate1d_U16( x, xv_p, zm_p );

        /* STAGE II: Collapse y dimension of line onto point with
        **           desired x & y values.
        */

        return ( interpolate1d_U16( y, yv_p, &z2d[0] ) );

   }    /* Block containing z2d */
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
  uint16_T *u1 = (uint16_T *) ssGetInputPortSignal(S, 0);
  uint16_T *u2 = (uint16_T *) ssGetInputPortSignal(S, 1);
  uint16_T *u3 = (uint16_T *) ssGetInputPortSignal(S, 2);
  uint16_T *y1 = (uint16_T *) ssGetOutputPortSignal(S, 0);

  /*
   * Call the legacy code function
   */
  uint16_T* map = u1;
  uint16_T indexx = *u2;
  uint16_T indexy = *u3;
  
  uint16_T Result = usLookup_xyz_us_us( u1, *u2, *u3);
  
  *y1 = Result;
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
