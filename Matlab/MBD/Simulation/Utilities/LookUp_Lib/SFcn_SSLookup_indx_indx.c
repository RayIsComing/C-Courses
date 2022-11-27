/*
 * File: SFcn_SSLookup_indx_indx.c
 *
 *
 *
 *   --- THIS FILE GENERATED BY S-FUNCTION BUILDER: 3.0 ---
 *
 *   This file is an S-function produced by the S-Function
 *   Builder which only recognizes certain fields.  Changes made
 *   outside these fields will be lost the next time the block is
 *   used to load, edit, and resave this file. This file will be overwritten
 *   by the S-function Builder block. If you want to edit this file by hand,
 *   you must change it only in the area defined as:
 *
 *        %%%-SFUNWIZ_defines_Changes_BEGIN
 *        #define NAME 'replacement text'
 *        %%% SFUNWIZ_defines_Changes_END
 *
 *   DO NOT change NAME--Change the 'replacement text' only.
 *
 *   For better compatibility with the Simulink Coder, the
 *   "wrapper" S-function technique is used.  This is discussed
 *   in the Simulink Coder's Manual in the Chapter titled,
 *   "Wrapper S-functions".
 *
 *  -------------------------------------------------------------------------
 * | See matlabroot/simulink/src/sfuntmpl_doc.c for a more detailed template |
 *  -------------------------------------------------------------------------
 * Created: Mon Feb 18 15:17:13 2013
 *
 *
 */

#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME SFcn_SSLookup_indx_indx
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/* %%%-SFUNWIZ_defines_Changes_BEGIN --- EDIT HERE TO _END */

/* %%%-SFUNWIZ_defines_Changes_END --- EDIT HERE TO _BEGIN */
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
#include "simstruc.h"
#include "fixedpoint.h"
#include "MathLookUp.h"

#define N_PAR 0

/* define error messages */
#define ERR_INVALID_SET_INPUT_DTYPE_CALL  \
"Invalid call to mdlSetInputPortDataType"
#define ERR_INVALID_SET_OUTPUT_DTYPE_CALL \
        "Invalid call to mdlSetOutputPortDataType"
#define ERR_INVALID_DTYPE     "Invalid input or output port data type"
#define TRUE 1
#define FALSE 0
        /*====================*
         * S-function methods *
         *====================*/
        /* Function: mdlInitializeSizes ===============================================
         * Abstract:
         *   Setup sizes of the various vectors.
         */
        static void mdlInitializeSizes(SimStruct *S)
{
    
    ssSetNumSFcnParams(S, N_PAR);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch will be reported by Simulink */
    }
    if (!ssSetNumInputPorts(S, 3)) return;
    /*Input Port 0 */
    ssSetInputPortMatrixDimensions(  S, 0, DYNAMICALLY_SIZED, DYNAMICALLY_SIZED);
    ssSetInputPortDataType(S, 0, DYNAMICALLY_TYPED);
    ssSetInputPortDirectFeedThrough(S, 0, TRUE);
    ssSetInputPortReusable(S, 0, TRUE);
    ssSetInputPortOverWritable(S, 0, FALSE);
    ssSetInputPortComplexSignal( S, 0, COMPLEX_NO);
    ssSetInputPortRequiredContiguous( S, 0, TRUE );
    
    
    /*Input Port 1 */
    ssSetInputPortWidth(S,  1, 1); /* */
    ssSetInputPortDataType(S, 1, SS_UINT16);
    ssSetInputPortDirectFeedThrough(S, 1, TRUE);
    ssSetInputPortReusable(S, 1, TRUE);
    ssSetInputPortOverWritable(S, 1, FALSE);
    ssSetInputPortComplexSignal( S, 1, COMPLEX_NO);
    ssSetInputPortRequiredContiguous( S, 1, TRUE );
    
    /*Input Port 2 */
    ssSetInputPortWidth(S,  2, 1); /* */
    ssSetInputPortDataType(S, 2, SS_UINT16);
    ssSetInputPortDirectFeedThrough(S, 2, TRUE);
    ssSetInputPortReusable(S, 2, TRUE);
    ssSetInputPortOverWritable(S, 2, FALSE);
    ssSetInputPortComplexSignal( S, 2, COMPLEX_NO);
    ssSetInputPortRequiredContiguous( S, 2, TRUE );    
    if (!ssSetNumOutputPorts(S, 1)) return;
    
    ssSetOutputPortWidth(S, 0, 1);
    ssSetOutputPortDataType(S, 0, DYNAMICALLY_TYPED);
    ssSetOutputPortComplexSignal(S, 0, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 0, 1);
    
    ssSetNumSampleTimes(S, 1);
    
    /* specify the sim state compliance to be same as a built-in block */
    ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);
    
    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
    ssSetOptions(S, (SS_OPTION_DISCRETE_VALUED_OUTPUT |
            SS_OPTION_USE_TLC_WITH_ACCELERATOR |
            SS_OPTION_WORKS_WITH_CODE_REUSE |
            SS_OPTION_NONVOLATILE |
            SS_OPTION_CALL_TERMINATE_ON_EXIT |
            SS_OPTION_CAN_BE_CALLED_CONDITIONALLY));
}


/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specifiy  the sample time.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime( S, 0, FIXED_IN_MINOR_STEP_OFFSET );
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
}

#define     MDL_SET_WORK_WIDTHS
static void mdlSetWorkWidths(SimStruct *S)
{
    DTypeId dataTypeId = ssGetOutputPortDataType( S, 0 );
    
    int vNumBits = ssGetDataTypeFxpWordLength( S, dataTypeId);
    int Bytesize = 8;
    int doublewordsize = 32;
    if ((vNumBits == Bytesize) || (vNumBits == doublewordsize))
    {
        ssSetErrorStatus(S,"This Look Up Table is a 16 bit look up table so please provide 16 bit data");
    }
}

static int isDataTypeSupported(SimStruct *S, DTypeId dataTypeId)
{
    int intDataTypeSupported = 0;
    
    if ( ssGetDataTypeIsFxpFltApiCompat( S, dataTypeId ) == 0)
    {
        ssSetErrorStatus(S,"Unrecognized data type.");
        goto EXIT_POINT;
    }
    else
    {
        fxpStorageContainerCategory storageContainer =
                ssGetDataTypeStorageContainCat( S, dataTypeId );
        
        switch ( storageContainer )
        {
            case FXP_STORAGE_UINT8:
            case FXP_STORAGE_INT8:
            case FXP_STORAGE_UINT16:
            case FXP_STORAGE_INT16:
            case FXP_STORAGE_UINT32:
            case FXP_STORAGE_INT32:
                
                if ( !ssGetDataTypeIsScalingPow2( S, dataTypeId ) )
                {
                    ssSetErrorStatus(S,"Only fixed point data types with power of two scaling are supported.");
                    goto EXIT_POINT;
                }
                
                intDataTypeSupported = 1;
                break;
                
            case FXP_STORAGE_SCALEDDOUBLE:
                
                ssSetErrorStatus(S,"Scaled doubles data types are not supported.");
                goto EXIT_POINT;
                break;
                
            case FXP_STORAGE_DOUBLE:
            case FXP_STORAGE_SINGLE:
                
                ssSetErrorStatus(S,"Floating point data types are not supported.");
                goto EXIT_POINT;
                break;
                
            case FXP_STORAGE_CHUNKARRAY:
            case FXP_STORAGE_OTHER_SINGLE_WORD:
            case FXP_STORAGE_MULTIWORD:
                ssSetErrorStatus(S,"Fixed point data types with more than 32 bits are not supported.");
                goto EXIT_POINT;
                break;
                
            default:
                
                ssSetErrorStatus( S, "Unanticipated data type case." );
        }
    }
    
    EXIT_POINT:
        return ( intDataTypeSupported );
}


#define MDL_SET_INPUT_PORT_DIMENSION_INFO
static void mdlSetInputPortDimensionInfo(SimStruct        *S,
        int_T            port,
        const DimsInfo_T *pDimsInfo)
{
    /* accept any dimensions, there is no relationship between the dimensions
     * of any ports.
     */
    if (port == 0)
    {
        ssSetInputPortDimensionInfo(S,port, pDimsInfo);
    }else
    {
        ssSetInputPortDimensionInfo(S,port, pDimsInfo);
    }
}

# define MDL_SET_OUTPUT_PORT_DIMENSION_INFO
static void mdlSetOutputPortDimensionInfo(SimStruct        *S,
        int_T            port,
        const DimsInfo_T *pDimsInfo)
{
    /* never an output port, but a consistency checker may complain, so
     * this functions only purpose is to shutup the checker.
     */
    ssSetOutputPortDimensionInfo(S,port, pDimsInfo);
}

#define MDL_SET_INPUT_PORT_DATA_TYPE
static void mdlSetInputPortDataType(SimStruct *S, int port, DTypeId dataTypeIdInput)
{
    if (port == 0)
    {
        if ( isDataTypeSupported( S, dataTypeIdInput ) )
        {
            DTypeId dataTypeIdOutput;
            
            ssSetInputPortDataType( S, port, dataTypeIdInput );
            
            dataTypeIdOutput = ssRegisterDataTypeFxpBinaryPoint(
                    S,
                    ssGetDataTypeFxpIsSigned(       S, dataTypeIdInput ),
                    ssGetDataTypeFxpWordLength(     S, dataTypeIdInput ),
                    ssGetDataTypeFractionLength(    S, dataTypeIdInput ),
                    0 /* false means do NOT obey data type override setting for this subsystem */ );
            
            ssSetOutputPortDataType( S, 0, dataTypeIdOutput );
        }
    }else{
        ssSetInputPortDataType( S, port, SS_UINT16 );
    }
}


#define MDL_SET_OUTPUT_PORT_DATA_TYPE
static void mdlSetOutputPortDataType(SimStruct *S, int port, DTypeId dataTypeIdOutput)
{
    if ( isDataTypeSupported( S, dataTypeIdOutput ) )
    {
        DTypeId dataTypeIdInput;
        
        ssSetOutputPortDataType( S, port, dataTypeIdOutput );
        
        dataTypeIdInput = ssRegisterDataTypeFxpBinaryPoint(
                S,
                ssGetDataTypeFxpIsSigned(       S, dataTypeIdOutput ),
                ssGetDataTypeFxpWordLength(     S, dataTypeIdOutput ),
                ssGetDataTypeFractionLength(    S, dataTypeIdOutput ),
                0 /* false means do NOT obey data type override setting for this subsystem */ );
        
        ssSetInputPortDataType( S, 0, dataTypeIdInput );
    }
}

/* Function: mdlOutputs =======================================================
 *
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    const void *pVoidIn1       =           (const void *)ssGetInputPortSignal(S,0);
    void *pVoidOut1            =           ( void *)ssGetOutputPortSignal(S,0);
    int_T *U0PortDim           =            ssGetInputPortDimensions(S ,0);
    DTypeId dataTypeId         =           ssGetInputPortDataType( S, 0);
    uint16_T *u1               =           (uint16_T *) ssGetInputPortSignal(S, 1);
    uint16_T *u2               =           (uint16_T *) ssGetInputPortSignal(S, 2);
    uint16_T XWidth            =           U0PortDim[0];
    uint16_T YWidth            =           U0PortDim[1];    
    
    fxpStorageContainerCategory storageContainer =
            ssGetDataTypeStorageContainCat( S, dataTypeId );
    

    switch ( storageContainer )
    {
        case FXP_STORAGE_INT16:
            (*((int16_T *)pVoidOut1)) = ssLookup_xyz_us_us(((int16_T *)pVoidIn1),*u1,*u2,YWidth,XWidth);
            break;
        default:
            ssSetErrorStatus( S, "This data type is not supported by this sfunction." );
    }
}

/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)
{
    
}

/*=======================================*
 * Required closing for C MEX S-Function *
 *=======================================*/

#ifdef    MATLAB_MEX_FILE  /* Is this file being compiled as a MEX-file? */
# include "simulink.c"     /* MEX-file interface mechanism               */
# include "fixedpoint.c"
#else
# include "cg_sfun.h"      /* Code generation registration function      */
#endif

/* [EOF] SFcn_SSLookup_indx_indx.c */

