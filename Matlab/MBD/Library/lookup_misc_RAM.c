/*************************************************************************************************
*
* This file is used for auto-code.  It is manually modified.
*
* Filename:    lookup_misc_RAM.c
*
* Description: Definition file for RAM look-up and misc. RAM operations.  C-fcts implemented as S-fcts.
*
*
* Forward Engine Management Systems
*
* Copyright 1999-2014, Delphi Technologies, Inc.
* All rights reserved.
*
**************************************************************************************************
*
* Current Module Info:
*
* %full_name:     kok_pt2#2/csrc/lookup_misc_RAM.c/2 %
* %date_created:  Mon Feb  3 10:38:43 2014 %
* %version:       2 %
* %derived_by:    tzzpjy %
*
*************************************************************************************************/

#define _LOOKUP_MISC_RAM_C_

#include <lookup_misc_RAM.h>


// ***************************** Table Look-Up *********************************

/*******************************************************************************
 *   Table Look-Up helper functions                                            *
 *******************************************************************************/

// ****** 16Bit ******

/*****************************************************************************/
/*                                                                           */
/*                                 SYNOPSIS                                  */
/*                                 --------                                  */
/*                                                                           */
/*    Function Prototyping :-                                                */
/*    -----------------------                                                */
/*    uint16 interpolate_uint16 (uint16 m1, uint16 m2,                       */
/*                                uint16 frac_num,                           */
/*                                uint16 frac_den)                           */
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
U16 interpolate_uw_RAM(U16 m1, U16 m2, U16 frac_num, U16 frac_den)
{
    U16 delta_m;
    U16 result;
	U32 tempval;

    if (m2 >= m1)
    {
        delta_m = m2 - m1;
		tempval= (U32) delta_m	 * (U32) frac_num;
		tempval= tempval / (U32)frac_den;
        result = (U16) ((U32)m1 +tempval);

    }
    else
    {
        delta_m = m1 - m2;
        tempval= (U32) delta_m	 * (U32) frac_num;
		tempval= tempval / (U32)frac_den;
        result = (U16) ((U32)m1 - tempval);
    }

    return (result);
}

/*****************************************************************************/
/*                                                                           */
/*                                 SYNOPSIS                                  */
/*                                 --------                                  */
/*                                                                           */
/*    Function Prototyping :-                                                */
/*    -----------------------                                                */
/*    uint16 interpolate_uint16 (uint16 m1, uint16 m2,                       */
/*                                uint16 frac_num,                           */
/*                                uint16 frac_den)                           */
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
U16 interpolate_uw_ratio_RAM(U16 m1, U16 m2, U16 frac_num, U16 frac_den)
{
    U16 delta_m;
    U16 result;

    if (m2 >= m1)
    {
        delta_m = m2 - m1;
        result = (U16) ((U32)m1 +
                        (((U32) delta_m * (U32) frac_num) / (U32)frac_den));
    }
    else
    {
        delta_m = m1 - m2;
        result = (U16) ((U32)m1 -
                        (((U32) delta_m * (U32) frac_num) / (U32)frac_den));
    }

    return (result);
}


/*****************************************************************************/
/*                                                                           */
/*                                 SYNOPSIS                                  */
/*                                 --------                                  */
/*                                                                           */
/*    Function Prototyping :-                                                */
/*    -----------------------                                                */
/*    int16 interpolate_fl__(int16 m1, int16 m2,                             */
/*                                uint16 frac_num,                           */
/*                                uint16 frac_den)                           */
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
S16 interpolate_sw_RAM(S16 m1, S16 m2, U16 frac_num, U16 frac_den)
{
    S32 delta_m;
    S16 result;

    delta_m = ((S32)m2 -(S32) m1);
	delta_m = delta_m *  (S32)frac_num;
	delta_m	= delta_m  / (S32)frac_den;
    result =  m1 + (S16)delta_m;

    return result;
}

/*****************************************************************************/
/*                                                                           */
/*                                 SYNOPSIS                                  */
/*                                 --------                                  */
/*                                                                           */
/*    Function Prototyping :-                                                */
/*    -----------------------                                                */
/*    int16 interpolate_fl__(int16 m1, int16 m2,                             */
/*                                uint16 frac_num,                           */
/*                                uint16 frac_den)                           */
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
S16 interpolate_sw_ratio_RAM(S16 m1, S16 m2, U16 frac_num, U16 frac_den)
{
    S16 delta_m;
    S16 result;

    delta_m = (m2 - m1);
    result =  (m1 +
              (((S32) delta_m *  (S32)frac_num) / ((S32)frac_den)));

    return result;
}

// ****** F32 ******
/* Reuse interpolate_fl_ratio() from lookup_fl.c/.h */


// ********* Table Look-Up **********

/*******************************************************************************
 *   2D LookUp : Idx vs. Val                                                   *
 *******************************************************************************/

// ****** 16Bit ******

/*****************************************************************************/
/*                                                                           */
/*                                 SYNOPSIS                                  */
/*                                 --------                                  */
/*                                                                           */
/*    Function Prototyping :-                                                */
/*    -----------------------                                                */
/*                                                                           */
/*    U16 usLookup_Independent_xy_us(const U16 * column,                     */
/*                                  U16 target,                              */
/*                                  U16 size)                                */
/*    column    pointer to the column in which to perform a binary search    */
/*    target    value to find in column                                      */
/*    size      Number of rows that comprise column                          */
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
/*                                                                           */
/*****************************************************************************/
U16 usLookup_Independent_xy_us_RAM(U16 * column, U16 target, U16 size)
{
    U16 lower = ZERO_CPV;
    U16 middle;
    U16 upper;
	U32 ratio;
	U16 result;

    if (target <= column[lower])
    {
          result=0;    /* return lower */
    }
    else
    {
        upper = (size - ONE_CPV);
        if (target >= column[upper])
        {
/*          lower = upper; */
/* 			result = 0;       */
            lower = upper - ONE_CPV; /* In order to mimic legacy code */
			result = 255;			 /* In order to mimic legacy code */
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

//            ratio   = ((U32)255 * (target-column[lower]))/ ((U32)(column[lower+1]- column[lower]));
            ratio   = ((U32)256 * (target-column[lower]))/ ((U32)(column[lower+1]- column[lower]));
            result  = (U16)ratio;
            result  = (result & 0xff);
		}
    }
	lower = lower<< 8;
    result= result | lower;
    return (result);
}

/*****************************************************************************/
/*                                                                           */
/*                                 SYNOPSIS                                  */
/*                                 --------                                  */
/*                                                                           */
/*    Function Prototyping :-                                                */
/*    -----------------------                                                */
/*                                                                           */
/*    U16 usLookup_Independent_xy_ss(const S16 * column,                     */
/*                                  S16 target,                              */
/*                                  U16 size)                                */
/*    column    pointer to the column in which to perform a binary search    */
/*    target    value to find in column                                      */
/*    size      Number of rows that comprise column                          */
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
/*                                                                           */
/*****************************************************************************/
U16 usLookup_Independent_xy_ss_RAM(S16 * column, S16 target, U16 size)
{
    U16 lower = ZERO_CPV;
    U16 middle;
    U16 upper;
	S32 ratio;
	U16 result;

    if (target <= column[lower])
    {
          result=0;    /* return lower */
    }
    else
    {
        upper = (size - ONE_CPV);
        if (target >= column[upper])
        {
/*          lower = upper; */
/* 			result = 0;       */
            lower = upper - ONE_CPV; /* In order to mimic legacy code */
			result = 255;			 /* In order to mimic legacy code */
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

            //ratio   = ((S32)255 * (target-column[lower]))/ ((S32)(column[lower+1]- column[lower]));
            ratio   = ((S32)256 * (target-column[lower]))/ ((S32)(column[lower+1]- column[lower]));
            result  = (U16)ratio;
            result  = (result & 0xff);
		}
    }
	lower = lower<< 8;
    result= result | lower;
    return (result);
}

// ****** F32 ******

/*****************************************************************************/
/*                                                                           */
/*                                 SYNOPSIS                                  */
/*                                 --------                                  */
/*                                                                           */
/*    Function Prototyping :-                                                */
/*    -----------------------                                                */
/*                                                                           */
/*   US idxLookup_fl(float *column,                                          */
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
U16 idx_Lookup_fl_RAM(float *column, float target, U16 size)

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

// ****** 16Bit ******

U16 usLookup_xy_us_RAM(U16 *column, U16 x, U16 size)
{
    U16 index;
    U16  result;
    U16  x_ratio;

    index = x >> 8;
	size = size - 1; // convert to 0-based index

    if ( (x & 0xff) && (index < size) )
    {
        /* Interpolate to get result */
        x_ratio = x & 0xff;
        //result = interpolate_uw_ratio(column[index], column[index + ONE_CPV], x_ratio, 255);
        result = interpolate_uw_ratio_RAM(column[index], column[index + ONE_CPV], x_ratio, 256); //To emulate legacy
    }
    else if (index < size )
    {
        result = column[index];
    }
    else
    {
     result = column[size];
    }

    return (result);
}


S16 ssLookup_xy_us_RAM(S16 *column, U16 x, U16 size)
{
    U16 index;
    S16  result;
    U16  x_ratio;

    index = x >> 8;
	size = size - 1; // convert to 0-based index

    if ( (x & 0xff) && (index < size) )
    {
        /* Interpolate to get result */
        x_ratio = x & 0xff;
        //result = interpolate_sw_ratio(column[index], column[index + ONE_CPV],x_ratio, 255);
        result = interpolate_sw_ratio_RAM(column[index], column[index + ONE_CPV],x_ratio, 256); //To emulate legacy
    }
    else if (index < size )
    {
        result = column[index];
    }
    else
    {
     result = column[size];
    }
    return (result);
}


// ****** F32 ******
/*****************************************************************************/
/*                                                                           */
/*                                 SYNOPSIS                                  */
/*                                 --------                                  */
/*                                                                           */
/*    Function Prototyping :-                                                */
/*    -----------------------                                                */
/*                                                                           */
/*    float TblLookup_IndFrac_xy(float *mapin, U16  x)                       */
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

float fl_LookUp_idx_RAM(float *column, U16 x, U16 size)
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

// ****** 16Bit ******

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
U16 usLookup_xyz_us_us_RAM(U16* TblData,U16 x_idx,U16 y_idx, U16 x_length, U16 y_length)
{
    U16 result;
    U16 x_ratio;
    U16 y_ratio;
    U16 *map;
    U16 m_result1;
    U16 m_result2;
    U16 x_index;
    U16 y_index;
    U16 m1;               /* Map data variables */
    U16 m2;
    flag x_out_of_bounds;
    flag y_out_of_bounds;

    x_out_of_bounds=FALSE;
    y_out_of_bounds=FALSE;
    x_index = x_idx >> 8;
    y_index = y_idx >> 8;
    x_ratio = (x_idx & 0x00ff);
    y_ratio = (y_idx & 0x00ff);
    map     = (U16*) TblData;


	/* Determine possible out-of-bounds --> axis end-pt saturation */
/* 	if (x_index > (x_length - ONE_CPV)) /* NOTE : This saturation should not be  */
/* 	{									/* necessary as should have been handled */
/* 		x_index = x_length - ONE_CPV;	/* by idx calc function.                 */
/* 	}									/* Consider deleting for optimization    */
  	if ((x_ratio==0) && ((x_index ==  0) || (x_index == (x_length - ONE_CPV))))
	{
        x_out_of_bounds = TRUE;
	}
/* 	if (y_index > (y_length - ONE_CPV)) /* NOTE : This saturation should not be  */
/* 	{									/* necessary as should have been handled */
/* 		y_index = y_length - ONE_CPV;	/* by idx calc function.                 */
/* 	}									/* Consider deleting for optimization    */
  	if ((y_ratio==0) && ((y_index ==  0) || (y_index == (y_length - ONE_CPV))))
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
            m_result1 = interpolate_uw_RAM ( m1, m2, (U16) (x_ratio), (U16) (255));

            /* Two pts in X-direction in neighboring Y-cells */
            m1 = map[(x_index * y_length) + y_index + ONE_CPV];
            m2 = map[((x_index + ONE_CPV) * y_length) + y_index + ONE_CPV];

            /* Interpolate on X-axis (2) */
            m_result2 = interpolate_uw_RAM ( m1, m2, (U16) (x_ratio), (U16) (255));

            /* Interpolate on Y-axis */
            result = interpolate_uw_RAM ( m_result1, m_result2, (U16) (y_ratio), (U16) (255));
        }
        else if (y_out_of_bounds == TRUE) /* and (x_out_of_bounds == FALSE) */
        {
            /* Interpolate on X-axis */
            m2 = map[((x_index + ONE_CPV) * y_length) + y_index];

            result = interpolate_uw_RAM ( m1, m2, (U16) (x_ratio), (U16) (255));
        }
        else /* (x_out_of_bounds == TRUE) and (y_out_of_bounds == FALSE) */
        {
            /* Interpolate on Y-axis */
            m2 = map[(x_index * y_length) + y_index + ONE_CPV];

            result = interpolate_uw_RAM ( m1, m2, (U16) (y_ratio), (U16) (255));
        }
    }
    else /* ((x_out_of_bounds == TRUE) and (y_out_of_bounds == TRUE)) */
    {
        result = m1;
    }
    return (result);
}


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
S16 ssLookup_xyz_us_us_RAM(S16* TblData,U16 x_idx,U16 y_idx, U16 x_length, U16 y_length)
{
    S16 result;
    U16 x_ratio;
    U16 y_ratio;
    S16 *map;
    S16 m_result1;
    S16 m_result2;
    U16 x_index;
    U16 y_index;
    S16 m1;               /* Map data variables */
    S16 m2;
    flag x_out_of_bounds;
    flag y_out_of_bounds;

    x_out_of_bounds=FALSE;
    y_out_of_bounds=FALSE;
    x_index = x_idx >> 8;
    y_index = y_idx >> 8;
    x_ratio = (x_idx & 0x00ff);
    y_ratio = (y_idx & 0x00ff);
    map     = (S16*) TblData;

	/* Determine possible out-of-bounds --> axis end-pt saturation */
/* 	if (x_index > (x_length - ONE_CPV)) /* NOTE : This saturation should not be  */
/* 	{									/* necessary as should have been handled */
/* 		x_index = x_length - ONE_CPV;	/* by idx calc function.                 */
/* 	}									/* Consider deleting for optimization    */
  	if ((x_ratio==0) && ((x_index ==  0) || (x_index == (x_length - ONE_CPV))))
	{
        x_out_of_bounds = TRUE;
	}
/* 	if (y_index > (y_length - ONE_CPV)) /* NOTE : This saturation should not be  */
/* 	{									/* necessary as should have been handled */
/* 		y_index = y_length - ONE_CPV;	/* by idx calc function.                 */
/* 	}									/* Consider deleting for optimization    */
  	if ((y_ratio==0) && ((y_index ==  0) || (y_index == (y_length - ONE_CPV))))
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
            m_result1 = interpolate_sw_RAM ( m1, m2,(U16) (x_ratio), (U16) (255));

            /* Two pts in X-direction in neighboring Y-cells */
            m1 = map[(x_index * y_length) + y_index + ONE_CPV];
            m2 = map[((x_index + ONE_CPV) * y_length) + y_index + ONE_CPV];

            /* Interpolate on X-axis (2) */
            m_result2 = interpolate_sw_RAM ( m1, m2, (U16) (x_ratio), (U16) (255));

            /* Interpolate on Y-axis */
            result = interpolate_sw_RAM ( m_result1, m_result2, (U16) (y_ratio), (U16) (255));

        }
        else if (y_out_of_bounds == TRUE) /* and (x_out_of_bounds == FALSE) */
        {
            /* Interpolate on X-axis */
            m2 = map[((x_index + ONE_CPV) * y_length) + y_index];

            result = interpolate_sw_RAM ( m1, m2, (U16) (x_ratio), (U16) (255));
        }
        else /* (x_out_of_bounds == TRUE) and (y_out_of_bounds == FALSE) */
        {
            /* Interpolate on Y-axis */
            m2 = map[(x_index * y_length) + y_index + ONE_CPV];

            result = interpolate_sw_RAM ( m1, m2, (U16) (y_ratio), (U16) (255));
        }
    }
    else /* ((x_out_of_bounds == TRUE) and (y_out_of_bounds == TRUE)) */
    {
        result = m1;
    }
    return (result);
}

// ****** F32 ******
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
float fl_LookUp_idx_idx_RAM(float* TblData,U16 x_idx,U16 y_idx, U16 x_length, U16 y_length)
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


/**********************************************************************************/

/*******************************************************************************
 *   NVM misc support                                                          *
 *******************************************************************************/
/* The following functions (RAMcopy_to_CritNVM, RAMcopy_to_NonCritNVM, CritNVM_to_RAMcopy) all do nothing.					*/
/* Their only purpose is to create the s-fct with the correct fct interface.  Their content is irrelevant, as				*/
/* the auto-code to be generated is handmodified in the tlc-files.  The handmod tlc code instead calls one of				*/
/* the functions in copy_RAM.c (CopyRAM or CopyRAM_to_CritNVM).  This 2-step process is necessary							*/
/* because the functions need to define a local idx for counting through the arrays, but it cannot be done as part			*/
/* of the tlc code because that code is inlined, and some compilers (e.g. Diab) do not allow a local variable declaration	*/
/* in the middle of a function.																								*/

// RAMcopy_to_CritNVM
// ****** 16Bit ******
void write_RAMcopy_to_CritNVM_us(U16 CritNVM_tbl, U16 size)
{
	// do nothing
    return;
}

void write_RAMcopy_to_CritNVM_ss(S16 CritNVM_tbl, U16 size)
{
	// do nothing
    return;
}

// ****** F32 ******
void write_RAMcopy_to_CritNVM_fl(float CritNVM_tbl, U16 size)
{
	// do nothing
    return;
}

// RAMcopy_to_NonCritNVM
// ****** 16Bit ******
void write_RAMcopy_to_NonCritNVM_us(U16 CritNVM_tbl, U16 size)
{
	// do nothing
    return;
}

void write_RAMcopy_to_NonCritNVM_ss(S16 CritNVM_tbl, U16 size)
{
	// do nothing
    return;
}

// ****** F32 ******
void write_RAMcopy_to_NonCritNVM_fl(float CritNVM_tbl, U16 size)
{
	// do nothing
    return;
}

// CritNVM_to_RAMcopy
// ****** 16Bit ******
void write_CritNVM_to_RAMcopy_us(U16 CritNVM_tbl, U16 size)
{
	// do nothing
    return;
}

void write_CritNVM_to_RAMcopy_ss(S16 CritNVM_tbl, U16 size)
{
	// do nothing
    return;
}

// ****** F32 ******
void write_CritNVM_to_RAMcopy_fl(float CritNVM_tbl, U16 size)
{
	// do nothing
    return;
}


/*************************************************************************************************
*
* Revision History for AutoCode Data Dictionary Global settings :
*
* Rev.  YYMMDD Who RSM#  Changes
* ----  ------ --- ----- ------------------------------------------------------------------------
* 1.0   120327 mm  10120 Original implementation.
* 2.0   140124 mm  11268 RAMcopy changes.
*
*************************************************************************************************/
