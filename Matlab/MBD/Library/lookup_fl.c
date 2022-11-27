/*************************************************************************************************
*
* This file is used for auto-code.  It is manually modified.
*
* Filename:    lookup_fl.c
*
* Description: Definition file for floating pt look-up.  C-fcts implemented as S-fcts.
*              Initial content from Delphi Diesel, but cleaned up for CTCM use.
*
*
* Forward Engine Management Systems
*  
* Copyright 1999-2011, Delphi Technologies, Inc.
* All rights reserved.
*
**************************************************************************************************
*
* Current Module Info:
*
* %full_name:     kok_pt2#1/csrc/lookup_fl.c/1.1.1 %
* %date_created:  Mon Jul  2 15:33:32 2012 %
* %version:       1.1.1 %
* %derived_by:    tzzpjy %
*
*************************************************************************************************/

#define _LOOKUP_FL_C_
 

#include <lookup_fl.h>


/*******************************************************************************
 *   Helper functions                                                          *
 *******************************************************************************/

/*****************************************************************************/
/*                                                                           */
/*                                 SYNOPSIS                                  */
/*                                 --------                                  */
/*                                                                           */
/*    Function Prototyping :-                                                */
/*    -----------------------                                                */
/*    float interpolate_fl_ratio(float m1, float m2,                         */
/*                                float frac_num)                            */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*    m1    First map value                                                  */
/*    m2    Second map value                                                 */
/*    frac_num  Numerator of fraction to interpolate by                      */
/*    frac_den  Denominator of fraction to interpolate by                    */
/*                                                                           */
/*    Function Return Value :-                                               */
/*    ------------------------                                               */
/*                                                                           */
/*    The interpolated value                                                 */
/*                                                                           */
/*                                                                           */
/*    Function Specification :-                                              */
/*    -------------------------                                              */
/*                                                                           */
/*  Linear interpolation of m1 and m2 by the factor frac_num / frac_den.     */
/*  Note that this function has been specifically written to be used with    */
/*  the __binary_search_xx functions, allowing certain assumptions that are  */
/*  not necessarily true in the general case.                                */
/*                                                                           */
/*  frac_num must be less than or equal to frac_den                          */
/*  frac_den must be non-zero                                                */
/*                                                                           */
/*****************************************************************************/
float interpolate_fl_ratio(float m1, float m2, float frac_num )
                               
{
    float delta_m;
    float result;

    delta_m = (m2 - m1);
    result =  m1 + ( delta_m *  frac_num);

    return (result);
}



/*******************************************************************************
 *   2D LookUp : Idx vs. Val                                                   *
 *******************************************************************************/

/*****************************************************************************/
/*                                                                           */
/*                                 SYNOPSIS                                  */
/*                                 --------                                  */
/*                                                                           */
/*    Function Prototyping :-                                                */
/*    -----------------------                                                */
/*                                                                           */
/*   US idxLookup_fl(const float *column,                                    */ 
/*                                      float target,                        */
/*                                        U16 size)                          */
/*    column    pointer to the column in which to perform a binary search    */
/*    target    value to find in column                                      */
/*    size      Number of rows that comprise column                          */
/*                                                                           */
/*   The output is in two bytes the MS is the index N and LS byte is  scaled */
/*    value (target- x1)* 255 /(x2-x1)                                       */
/*                                                                           */
/*    Function Return Value :-                                               */
/*    ------------------------                                               */
/*                                                                           */
/*    The index into column of the closest element less than target          */
/*                                                                           */
/*                                                                           */
/*    Function Specification :-                                              */
/*    -------------------------                                              */
/*                                                                           */
/*  Does a binary search on column to locate the element in column with the  */
/*  largest value that is less than or equal to target.                      */
/*                                                                           */
/*  The values in column must be monotonically increasing.                   */
/*  When beyond_axis is FALSE, the returned index is guaranteed to point to  */
/*  an element which is less than the subsequent element                     */
/*  i.e. (upper-lower) > 0                                                   */
/*                                                                           */
/*****************************************************************************/
U16 idx_Lookup_fl(const float *column, float target, U16 size)
                                
{
    U16 lower = ZERO_CPV;
    U16 middle;
    U16 upper;
    U16 result;
    float ratio_xy;
    
    if (target <= column[lower])
    {
        result =0;
        /* return lower */
    }
    else
    {
        upper = (size - ONE_CPV);
        if (target >= column[upper])
        {
            lower = upper;
            result =0;
         }
        else
        {
           
            while (upper > (lower + ONE_CPV))
            {
                middle = (U16) ((upper + lower) >> ONE_CPV);

                if (target >= column[middle])
                {
                    lower = middle;
                }
                else
                {
                    upper = middle;
                }
            }
            ratio_xy = ((float)255 * (target-column[lower]))/(column[lower+1]- column[lower]);
            result = (U16)ratio_xy; 
        }
    }
    lower = lower << 8;
    result= (result & 0xff) | lower;
    return (result);
}




/*******************************************************************************
 *   2D LookUp : Val vs. Idx                                                   *
 *******************************************************************************/
 /* us and ss handled directly by legacy functions */

/*****************************************************************************/
/*                                                                           */
/*                                 SYNOPSIS                                  */
/*                                 --------                                  */
/*                                                                           */
/*    Function Prototyping :-                                                */
/*    -----------------------                                                */
/*                                                                           */
/*    float TblLookup_IndFrac_xy(const float *mapin, U16  x)                 */
/*    mapin  map information structure                                       */
/*    x      input value                                                     */
/*                                                                           */
/*                                                                           */
/*    Function Return Value :-                                               */
/*    ------------------------                                               */
/*                                                                           */
/*    The interpolated float value.                                          */
/*                                                                           */
/*                                                                           */
/*    Function Specification :-                                              */
/*    -------------------------                                              */
/*                                                                           */
/*    This function uses a signed word 1D map with unsigned word variable    */
/*    breakpoints to interpolate the output given an input value.            */
/*                                                                           */
/*    The map information at *mapin is in a structure defined as follows:-   */
/*                                                                           */
/*                                                                           */
/*    For a one-dimensional map NUM_OF_Y_BPOINTS and the pointer *Y_BPOINTS  */
/*    will always be zero, while *X_BPOINTS will hold the address of the     */
/*    array of breakpoints, and *MAP_PTS will point to the corresponding     */
/*    data array.                                                            */
/*                                                                           */
/*    Note: The contents of X_BPOINTS must be monotonically                  */
/*          increasing. i.e. The breakpoint values must increase with        */
/*          increasing index values.                                         */
/*                                                                           */
/*****************************************************************************/

float fl_LookUp_idx(const float *column, U16 x, U16 size)
{
    U16 index;
    float result;
    float x_ratio;
        
    index = x >> 8;
	size = size - 1; // convert to 0-based index

    if ( (x & 0xff) && (index < size) )
    {
        /* Interpolate to get result */
        x_ratio = (float) ( ((float) (x & 0xff)) / ((float) 255) ); 
        result = interpolate_fl_ratio(column[index], column[index + ONE_CPV],
                                   x_ratio);
    }
    else if (index < size)
    {
        result = column[index];
    }
    else 
    {
        result = column[size];
    }
    return (result);
}



/*******************************************************************************
 *   3D LookUp : Val vs. Idx                                                   *
 *******************************************************************************/
 /* us and ss handled directly by legacy functions */

/*****************************************************************************/
/*                                                                           */
/*                                 SYNOPSIS                                  */
/*                                 --------                                  */
/*                                                                           */
/*    Function Prototyping :-                                                */
/*    -----------------------                                                */
/*                                                                           */
/*    S16 map_2d_fl_with_fl_fl_var(MAPTYPE *mapin, U16 x, U16     y)         */
/*    mapin  map information structure                                       */
/*    x      x input is index and scaled value                               */
/*    y      y input is index and scaled value                               */
/*                                                                           */
/*                                                                           */
/*    Function Return Value :-                                               */
/*    ------------------------                                               */
/*                                                                           */
/*    The interpolated float value.                                          */
/*                                                                           */
/*                                                                           */
/*    Function Specification :-                                              */
/*    -------------------------                                              */
/*                                                                           */
/*    This function uses a float 2D map with float x variable                */
/*    breakpoints and float y variable breakpoints to interpolate the output */    
/*    given a float x and a float y input value.                             */
/*                                                                           */
/*    The map information at *mapin is in a structure defined as follows:-   */
/*                                                                           */
/*    typedef struct                                                         */
/*    {                                                                      */
/*        U16          NUM_OF_X_BPOINTS;                                     */
/*        U16          NUM_OF_Y_BPOINTS;                                     */
/*        void         *MAP_PTS;                                             */
/*    }  MAPTYPE ;                                                           */
/*                                                                           */
/*    For a two-dimensional map *X_BPOINTS and *Y_BPOINTS will hold the      */
/*    addresses of the arrays of breakpoints for the X and Y axes, and       */
/*    *MAP_PTS will point to the corresponding data array.                   */
/*                                                                           */
/*    Note: The contents of X_BPOINTS and Y_BPOINTS must be                  */
/*          monotonically increasing. i.e. The breakpoint values must        */
/*          increase with increasing index values.                           */
/*                                                                           */
/*****************************************************************************/

/***************************   Nomenclature   ****************************/
/*             <-- x_length -->  <-- x_length -->	   <-- x_length -->  */
/* TblData = [ v11, v12, ... v1n v21 v22, ... v2n ... vm1 vm2, ... vmn ] */
/* where n = x_length, m = y_length										 */
/* 			                                                             */    
/* TblData =															 */
/* v11 v12 ... v1n	 /\													 */
/* v21 v22 ... v2n	  |													 */
/* .			  .														 */
/* .			  .	 y_length											 */
/* vm1 vm2 ... vmn	  |													 */
/* <- x_length  ->	 \/													 */
/*																		 */
/*   --> x																 */
/*	|																	 */
/*	\/																	 */
/*	y									 								 */
/*************************************************************************/
float fl_LookUp_idx_idx(const float* TblData,U16 x_idx,U16 y_idx, U16 x_length, U16 y_length)
{
    float result;
    float x_ratio;
    float y_ratio;
    float *map;
    float m_result1;
    float m_result2;
    U16 x_index;
    U16 y_index;
    U16 ratio;
    float m1;            
    float m2;
    flag x_out_of_bounds;
    flag y_out_of_bounds;
     
    x_out_of_bounds=FALSE;
    y_out_of_bounds=FALSE;
    x_index = x_idx >> 8;
    y_index = y_idx >> 8;
    ratio = (x_idx & 0x00ff);
    x_ratio =  (float)ratio/(float)255; 
    ratio = (y_idx & 0x00ff);
    y_ratio = (float)ratio/(float)255; 
    map     = (float*) TblData;

	/* Determine possible out-of-bounds --> axis end-pt saturation */
    ratio = (x_idx & 0x00ff);
/* 	if (x_index > (x_length - ONE_CPV)) /* NOTE : This saturation should not be  */
/* 	{									/* necessary as should have been handled */
/* 		x_index = x_length - ONE_CPV;	/* by idx calc function.                 */
/* 		ratio = FL_ZERO_CPV;			/* Consider deleting for optimization    */
/* 	}									                                         */
	if ((ratio==0) && ((x_index ==  0) || (x_index == (x_length - ONE_CPV))))
	{
	    x_out_of_bounds = TRUE;
	}

    ratio = (y_idx & 0x00ff);    
/* 	if (y_index > (y_length - ONE_CPV)) /* NOTE : This saturation should not be  */
/* 	{									/* necessary as should have been handled */
/* 		y_index = y_length - ONE_CPV;	/* by idx calc function.                 */
/* 		ratio = FL_ZERO_CPV;			/* Consider deleting for optimization    */
/* 	}								                                             */
    if ((ratio==0) && ((y_index ==  0) || (y_index == (y_length - ONE_CPV))))
	{
        y_out_of_bounds = TRUE;
	}
      
	/* First data point                                                   */
    m1 = map[(x_index * y_length) + y_index];
   
	/* Interpolate                                                        */
    if ((x_out_of_bounds == FALSE) || (y_out_of_bounds == FALSE))
    {
        if ((x_out_of_bounds == FALSE) && (y_out_of_bounds == FALSE))
        {
            /* Interpolate 3 times */
           
		    /* Second pt in X-direction */
            m2 = map[((x_index + ONE_CPV) * y_length) + y_index];

            /* Interpolate on X-axis (1) */
            m_result1 = interpolate_fl_ratio( m1, m2, x_ratio);
           
            /* Two pts in X-direction in neighboring Y-cells */  
            m1 = map[(x_index * y_length) + y_index + ONE_CPV];
            m2 = map[((x_index + ONE_CPV) * y_length) + y_index + ONE_CPV];

            /* Interpolate on X-axis (2) */
            m_result2 = interpolate_fl_ratio( m1, m2, x_ratio);
                                         
            /* Interpolate on Y-axis */
            result = interpolate_fl_ratio( m_result1, m_result2, y_ratio);
        }
        else if (y_out_of_bounds == TRUE) /* && (x_out_of_bounds == TRUE) */
        {
            /* Interpolate on X-axis */
            m2 = map[((x_index+ ONE_CPV)  * y_length) + y_index ];

            result = interpolate_fl_ratio( m1, m2, x_ratio);
        }
        else /* (x_out_of_bounds == TRUE) && (y_out_of_bounds == FALSE) */
        {
            /* Interpolate on Y-axis */
             m2 = map[(x_index * y_length) + y_index + ONE_CPV];

             result = interpolate_fl_ratio( m1, m2, y_ratio);
        }
    }
    else /* ((x_out_of_bounds == TRUE) && (y_out_of_bounds == TRUE)) */
    {
        result = m1;
    }
    return (result);
}

/*************************************************************************************************
*
* Revision History for AutoCode Data Dictionary Global settings :
*
* Rev.  YYMMDD Who  RSM# Changes 
* ----  ------ --- ----- ------------------------------------------------------------------------ 
* 1.0   110321 mm   9300 Original implementation as part of introducing new auto-code process.
* 2.0   120327 mm  10120 Changed "is" to "==" as "is" was deleted from ctcm_types.h
*
*************************************************************************************************/



