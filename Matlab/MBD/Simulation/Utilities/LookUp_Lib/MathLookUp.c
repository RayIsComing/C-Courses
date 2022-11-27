#include "data_types.h"

/* *** 2D : Independent Look Up Table *** */

/***** Unsigned in put ********/
U16 usLookup_Independent_xy_us(const U16 * TableAddr, U16 Value,U16 Intervals)
{
    U16 ArrayIndex;
    U16 Lower,Upper;
    U32 temp3;
    U16 temp1,temp4;
    float InterpFrac,temp2;
    
    
    /* Perform limit checks and rescale. */
    if (Value <= TableAddr[0])
    {
        return 0x0000;
    }
    else if (Value >= TableAddr[Intervals])
    {
        return ((Intervals << 8)-1);
    }
    else
    {
        /* Determine array index */
        for(ArrayIndex = 0; Value >= TableAddr[ArrayIndex]; ArrayIndex++);
        
        ArrayIndex--;
        
        /* Determine interpolation fraction */
        
        Lower = TableAddr[ArrayIndex];
        Upper = TableAddr[ArrayIndex + 1];
        
        temp1 = (Value - Lower);					/* temp1 has n bits */
        temp3 = (Upper - Lower);					/* temp3 has n bits */
        InterpFrac = (F32)temp1 /(F32) temp3;			/* InterpFrac has 16 bits */
        
        temp2 = (InterpFrac + (F32)ArrayIndex) * 256.0;
        temp4 = (U16)temp2;
        /* Pack array index and interpolation fraction into a table index. */
        return temp4;
    }
    
}

/***** signed in put ********/
U16 usLookup_Independent_xy_ss(const S16 * TableAddr, S16 Value,U16 Intervals)
{
    U16 ArrayIndex;
    S16 Lower,Upper;
    S32 temp3;
    S16 temp1;
    U16 temp4;
    float InterpFrac,temp2;
    
    
    /* Perform limit checks and rescale. */
    if (Value <= TableAddr[0])
    {
        return 0x0000;
    }
    else if (Value >= TableAddr[Intervals])
    {
        return ((Intervals << 8) - 1);
    }
    else
    {
        /* Determine array index */
        for(ArrayIndex = 0; Value >= TableAddr[ArrayIndex]; ArrayIndex++);
        
        ArrayIndex--;
        
        /* Determine interpolation fraction */
        
        Lower = TableAddr[ArrayIndex];
        Upper = TableAddr[ArrayIndex + 1];
        
        temp1 = (Value - Lower);					/* temp1 has n bits */
        temp3 = (Upper - Lower);					/* temp3 has n bits */
        InterpFrac = (F32)temp1 /(F32) temp3;			/* InterpFrac has 16 bits */
        
        temp2 = (InterpFrac + (F32)ArrayIndex) * 256.0;
        temp4 = (U16)temp2;
        /* Pack array index and interpolation fraction into a table index. */
        return temp4;
    }
    
}


/* *** 2D : Unsigned Val vs. Idx *** */
/***** Unsigned Output ***************/
U16 usLookup_xy_us(const U16 *TableAddr, U16 index, U16 Intervals)
{
    U16 ArrayIndex;
    F32 interfrac;
    U16 Lower,Upper;
    U16 Value;
    
    ArrayIndex = (U16)index / (U16)256;
    interfrac  = (F32)index / (F32)256.0;
    
    if (((F32)interfrac >= (F32)Intervals) && ((F32)interfrac < ((F32)Intervals + 1.0)))
    {
        interfrac = ((F32)interfrac - (F32)ArrayIndex);
        
        Value = (U16)((F32)65535 * (F32)(1-interfrac));
    }
    else if((F32)interfrac >= ((F32)Intervals + 1.0))
    {
        Value = 0x0000;
    }
    else
    {
        interfrac = ((F32)interfrac - (F32)ArrayIndex);
        Lower = TableAddr[ArrayIndex];
        Upper = TableAddr[ArrayIndex + 1];
        
        if (Upper >= Lower)
        {
            Value = (U16)((F32)Lower + (F32)(Upper - Lower) * (F32)interfrac);
        }else
        {
            Value = (U16)((F32)Lower - (F32)(Lower - Upper) * (F32)interfrac);
        }
    }
    return Value;
}

/***** Unsigned Output ***************/
S16 ssLookup_xy_us(const S16 *TableAddr, U16 index, U16 Intervals)
{
    U16 ArrayIndex;
    F32 interfrac;
    S16 Lower,Upper;
    U16 Value;
    
    ArrayIndex = (U16)index / (U16)256;
    interfrac  = (F32)index / (F32)256.0;
    
    if (((F32)interfrac >= (F32)Intervals) && ((F32)interfrac < ((F32)Intervals + 1.0)))
    {
        interfrac = ((F32)interfrac - (F32)ArrayIndex);
        Value = (U16)((F32)32512 * (F32)(1-interfrac));
        
    }
    else if((F32)interfrac >= ((F32)Intervals + 1.0))
    {
        Value = 0x0000;
    }
    else
    {
        interfrac = ((F32)interfrac - (F32)ArrayIndex);
        Lower = TableAddr[ArrayIndex];
        Upper = TableAddr[ArrayIndex + 1];
        
        if (Upper >= Lower)
        {
            Value = (S16)((F32)Lower + (F32)(Upper - Lower) * (F32)interfrac);
        }else
        {
            Value = (S16)((F32)Lower - (F32)(Lower - Upper) * (F32)interfrac);
        }
    }
    return Value;
}

/***** Unsigned Output ***************/
U32 ulLookup_xy_us(const U32 *TableAddr, U16 index, U16 Intervals)
{
    U16 ArrayIndex;
    F32 interfrac;
    U32 Lower,Upper;
    U32 Value;
    
    ArrayIndex = (U16)index / (U16)256;
    interfrac  = (F32)index / (F32)256.0;
    
    if (((F32)interfrac >= (F32)Intervals) && ((F32)interfrac < ((F32)Intervals + 1.0)))
    {
        interfrac = ((F32)interfrac - (F32)ArrayIndex);
        
        Value = (U32)((F64)65535 * (F64)(1-interfrac));
    }
    else if((F32)interfrac >= ((F32)Intervals + 1.0))
    {
        Value = 0x0000;
    }
    else
    {
        interfrac = ((F32)interfrac - (F32)ArrayIndex);
        Lower = TableAddr[ArrayIndex];
        Upper = TableAddr[ArrayIndex + 1];
        
        if (Upper >= Lower)
        {
            Value = (U32)((F64)Lower + (F64)(Upper - Lower) * (F64)interfrac);
        }else
        {
            Value = (U32)((F64)Lower - (F64)(Lower - Upper) * (F64)interfrac);
        }
    }
    return Value;
}

#define ONE_CPV 1
#define FALSE 0
#define TRUE 1
/****** Interpolate Function ************/
U16 interpolate_uw(U16 m1, U16 m2, F32 frac_num)
{
    U16 delta_m;
    U16 result;
	F32 tempval;

    if (m2 >= m1)
    {
        delta_m = m2 - m1;
		tempval= (F32) delta_m	 * (F32) frac_num;
        result = (U16) ((F32)m1 +(F32)tempval);
                       
    }
    else
    {
        delta_m = m1 - m2;
        tempval= (F32) delta_m	 * (F32) frac_num;
        result = (U16) ((F32)m1 - (F32)tempval);
    }

    return (result);
}

/******** 3D XYZ Unsigned Look up table ****************/

U16 usLookup_xyz_us_us(const U16* TableAddr,U16 TableIndexX,U16 TableIndexY, U16 SizeX, U16 SizeY)
{
    U16 result;
    F32 x_ratio;
    F32 y_ratio;
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
    x_index = TableIndexX >> 8;
    y_index = TableIndexY >> 8;
    x_ratio = ((F32)TableIndexX / (F32)256) - (F32)x_index;
    y_ratio = ((F32)TableIndexY / (F32)256) - (F32)y_index;
    map     = (U16*) TableAddr;

  	if ((x_ratio==0) && ((x_index <  0) || (x_index > (SizeX - ONE_CPV))))
	{
        x_out_of_bounds = TRUE;
	}

  	if ((y_ratio==0) && ((y_index <  0) || (y_index > (SizeY - ONE_CPV))))
	{
        y_out_of_bounds = TRUE;
	}

	/* First data point                                                   */
    m1 = map[(x_index * SizeY) + y_index];

	/* Interpolate                                                        */
    if ((x_out_of_bounds == FALSE) || (y_out_of_bounds == FALSE))
    {
        if ((x_out_of_bounds == FALSE) && (y_out_of_bounds == FALSE))
        {
            /* Interpolate 3 times */
           
		    /* Second pt in X-direction */
            m2 = map[((x_index + ONE_CPV) * SizeY) + y_index];

            /* Interpolate on X-axis (1) */
            m_result1 = interpolate_uw ( m1, m2, (F32) (x_ratio));
    
            /* Two pts in X-direction in neighboring Y-cells */  
            m1 = map[(x_index * SizeY) + y_index + ONE_CPV];
            m2 = map[((x_index + ONE_CPV) * SizeY) + y_index + ONE_CPV];

            /* Interpolate on X-axis (2) */
            m_result2 = interpolate_uw ( m1, m2, (F32) (x_ratio));

            /* Interpolate on Y-axis */
            result = interpolate_uw ( m_result1, m_result2, (F32) (y_ratio));
        }
        else if (y_out_of_bounds == TRUE) /* and (x_out_of_bounds is FALSE) */
        {
            /* Interpolate on X-axis */
            m2 = map[((x_index + ONE_CPV) * SizeY) + y_index];

            result = interpolate_uw ( m1, m2, (F32) (x_ratio));
        }
        else /* (x_out_of_bounds == TRUE) and (y_out_of_bounds == FALSE) */
        {
            /* Interpolate on Y-axis */
            m2 = map[(x_index * SizeY) + y_index + ONE_CPV];

            result = interpolate_uw ( m1, m2, (F32) (y_ratio));
        }
    }
    else /* ((x_out_of_bounds == TRUE) and (y_out_of_bounds == TRUE)) */
    {
        result = 0x0000;
    }
    return (result);
}

/****** Interpolate Function ************/
S16 interpolate_sw(S16 m1, S16 m2, F32 frac_num)
{
    F32 delta_m;
    S16 result;
    F32 tempval;
    
    if (m2 >= m1)
    {
        delta_m = m2 - m1;
		tempval= (F32) delta_m	 * (F32) frac_num;
        result = (S16) ((F32)m1 +(F32)tempval);
                       
    }
    else
    {
        delta_m = m1 - m2;
        tempval= (F32) delta_m	 * (F32) frac_num;
        result = (S16) ((F32)m1 - (F32)tempval);
    }    
    return result;
}

/******** 3D XYZ signed Look up table ****************/
S16 ssLookup_xyz_us_us(const S16* TableAddr,U16 TableIndexX,U16 TableIndexY, U16 SizeX, U16 SizeY)
{
    S16 result;
    F32 x_ratio;
    F32 y_ratio;
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
    x_index = TableIndexX >> 8;
    y_index = TableIndexY >> 8;
    x_ratio = ((F32)TableIndexX / (F32) 256.0)-(F32)x_index;
    y_ratio = ((F32)TableIndexY / (F32) 256.0)-(F32)y_index;
    map     = (S16*) TableAddr;


  	if ((x_ratio==0) && ((x_index <  0) || (x_index > (SizeX - ONE_CPV))))
	{
        x_out_of_bounds = TRUE;
	}

  	if ((y_ratio==0) && ((y_index <  0) || (y_index > (SizeY - ONE_CPV))))
	{
        y_out_of_bounds = TRUE;
	}

	/* First data point                                                   */
    m1 = map[(x_index * SizeY) + y_index];

	/* Interpolate                                                        */
    if ((x_out_of_bounds == FALSE) || (y_out_of_bounds == FALSE))
    {
        if ((x_out_of_bounds == FALSE) && (y_out_of_bounds == FALSE))
        {
            /* Interpolate 3 times */
          
		    /* Second pt in X-direction */
            m2 = map[((x_index + ONE_CPV) * SizeY) + y_index];

            /* Interpolate on X-axis (1) */
            m_result1 = interpolate_sw ( m1, m2,(F32) (x_ratio));
    
            /* Two pts in X-direction in neighboring Y-cells */  
            m1 = map[(x_index * SizeY) + y_index + ONE_CPV];
            m2 = map[((x_index + ONE_CPV) * SizeY) + y_index + ONE_CPV];

            /* Interpolate on X-axis (2) */
            m_result2 = interpolate_sw ( m1, m2, (F32) (x_ratio));

            /* Interpolate on Y-axis */
            result = interpolate_sw ( m_result1, m_result2, (F32) (y_ratio));

        }
        else if (y_out_of_bounds == TRUE) /* and (x_out_of_bounds is FALSE) */
        {
            /* Interpolate on X-axis */
            m2 = map[((x_index + ONE_CPV) * SizeY) + y_index];

            result = interpolate_sw ( m1, m2, (F32) (x_ratio));
        }
        else /* (x_out_of_bounds == TRUE) and (y_out_of_bounds == FALSE) */
        {
            /* Interpolate on Y-axis */
            m2 = map[(x_index * SizeY) + y_index + ONE_CPV];

            result = interpolate_sw ( m1, m2, (F32) (y_ratio));
        }
    }
    else /* ((x_out_of_bounds == TRUE) and (y_out_of_bounds == TRUE)) */
    {
        result = 0x0000;
    }
    return (result);
}

/* 32 Bit Interpolation */
U32 interpolate_ul(U32 m1, U32 m2, F32 frac_num)
{
    U32 delta_m;
    U32 result;
	F64 tempval;

    if (m2 >= m1)
    {
        delta_m = m2 - m1;
		tempval= (F32) delta_m	 * (F32) frac_num;
        result = (U32) ((F64)m1 +(F64)tempval);
                       
    }
    else
    {
        delta_m = m1 - m2;
        tempval= (F32) delta_m	 * (F32) frac_num;
        result = (U32) ((F64)m1 - (F64)tempval);
    }

    return (result);
}

/* Unsigned long Look Up Table */
U32 ulLookup_xyz_us_us(const U32* TblData,U16 x_idx,U16 y_idx, U16 x_length, U16 y_length)
{
    U32 result;
    F32 x_ratio;
    F32 y_ratio;
    U32 *map;
    U32 m_result1;
    U32 m_result2;
    U16 x_index;
    U16 y_index;
    U32 m1;               /* Map data variables */
    U32 m2;
    flag x_out_of_bounds;
    flag y_out_of_bounds;
 
    x_out_of_bounds=FALSE;
    y_out_of_bounds=FALSE;
    x_index = x_idx >> 8;
    y_index = y_idx >> 8;
    x_ratio = ((F32)x_idx / (F32)256.0) - (F32)x_index;
    y_ratio = ((F32)y_idx / (F32)256.0) - (F32)y_index;
    map     = (U32*) TblData;



  	if ((x_ratio==0) && ((x_index <  0) || (x_index > (x_length - ONE_CPV))))
	{
        x_out_of_bounds = TRUE;
	}

  	if ((y_ratio==0) && ((y_index <  0) || (y_index > (y_length - ONE_CPV))))
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
            m_result1 = interpolate_ul ( m1, m2, (F32) (x_ratio));
    
            /* Two pts in X-direction in neighboring Y-cells */  
            m1 = map[(x_index * y_length) + y_index + ONE_CPV];
            m2 = map[((x_index + ONE_CPV) * y_length) + y_index + ONE_CPV];

            /* Interpolate on X-axis (2) */
            m_result2 = interpolate_ul ( m1, m2, (F32) (x_ratio));

            /* Interpolate on Y-axis */
            result = interpolate_ul ( m_result1, m_result2, (F32) (y_ratio));
        }
        else if (y_out_of_bounds == TRUE) /* and (x_out_of_bounds is FALSE) */
        {
            /* Interpolate on X-axis */
            m2 = map[((x_index + ONE_CPV) * y_length) + y_index];

            result = interpolate_ul ( m1, m2, (F32) (x_ratio));
        }
        else /* (x_out_of_bounds == TRUE) and (y_out_of_bounds == FALSE) */
        {
            /* Interpolate on Y-axis */
            m2 = map[(x_index * y_length) + y_index + ONE_CPV];

            result = interpolate_ul ( m1, m2, (F32) (y_ratio));
        }
    }
    else /* ((x_out_of_bounds == TRUE) and (y_out_of_bounds == TRUE)) */
    {
        result = 0x0000;
    }
    return (result);
}

/* signed long Interpolation */
S32 interpolate_sl(S32 m1, S32 m2, F32 frac_num, U16 frac_den)
{
    F64 delta_m;
    S32 result;

    if (m2 > m1)
    {
    delta_m = ((S32)m2 -(S32) m1);
	delta_m = (F32)delta_m *  (F32)frac_num;
    result =  (S32)((F64)m1 + (F64)delta_m);
    }
    else
    {
    delta_m = ((S32)m1 -(S32) m2);
	delta_m = (F32)delta_m *  (F32)frac_num;
    result =  (S32)((F64)m1 + (F64)delta_m);        
    }
    return result;
}

/* signed long Look Up Table */
S32 slLookup_xyz_us_us(const S32* TblData,U16 x_idx,U16 y_idx, U16 x_length, U16 y_length)
{
    S32 result;
    F32 x_ratio;
    F32 y_ratio;
    S32 *map;
    S32 m_result1;
    S32 m_result2;
    U16 x_index;
    U16 y_index;
    S32 m1;               /* Map data variables */
    S32 m2;
    flag x_out_of_bounds;
    flag y_out_of_bounds;

    x_out_of_bounds=FALSE;
    y_out_of_bounds=FALSE;
    x_index = x_idx >> 8;
    y_index = y_idx >> 8;
    x_ratio = ((F32)x_idx / (F32)256.0) - (F32)x_index;
    y_ratio = ((F32)y_idx / (F32)256.0) - (F32)y_index;
    map     = (S32*) TblData;


  	if ((x_ratio==0) && ((x_index <  0) || (x_index > (x_length - ONE_CPV))))
	{
        x_out_of_bounds = TRUE;
	}

  	if ((y_ratio==0) && ((y_index <  0) || (y_index > (y_length - ONE_CPV))))
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
            m_result1 = interpolate_sl ( m1, m2,(F32) (x_ratio), (U16) (255));
    
            /* Two pts in X-direction in neighboring Y-cells */  
            m1 = map[(x_index * y_length) + y_index + ONE_CPV];
            m2 = map[((x_index + ONE_CPV) * y_length) + y_index + ONE_CPV];

            /* Interpolate on X-axis (2) */
            m_result2 = interpolate_sl ( m1, m2, (F32) (x_ratio), (U16) (255));

            /* Interpolate on Y-axis */
            result = interpolate_sl ( m_result1, m_result2, (F32) (y_ratio), (U16) (255));

        }
        else if (y_out_of_bounds == TRUE) /* and (x_out_of_bounds is FALSE) */
        {
            /* Interpolate on X-axis */
            m2 = map[((x_index + ONE_CPV) * y_length) + y_index];

            result = interpolate_sl ( m1, m2, (F32) (x_ratio), (U16) (255));
        }
        else /* (x_out_of_bounds == TRUE) and (y_out_of_bounds == FALSE) */
        {
            /* Interpolate on Y-axis */
            m2 = map[(x_index * y_length) + y_index + ONE_CPV];

            result = interpolate_sl ( m1, m2, (F32) (y_ratio), (U16) (255));
        }
    }
    else /* ((x_out_of_bounds == TRUE) and (y_out_of_bounds == TRUE)) */
    {
        result = 0x0000;
    }
    return (result);
}
