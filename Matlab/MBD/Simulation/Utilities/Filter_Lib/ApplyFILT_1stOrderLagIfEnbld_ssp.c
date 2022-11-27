float ApplyFILT_1stOrderLag_ssp(float LfFILT_Old,
                               float LfFILT_New,
                               float LfFILT_k_Coeff )
  {
  float LfFILT_Result;
  float LfFILT_temp1;

  if ( (LfFILT_Old == LfFILT_New)
     || (LfFILT_k_Coeff == 0) )
      {
         LfFILT_Result = LfFILT_Old;
      }

  else if (LfFILT_New > LfFILT_Old)
      {
          LfFILT_temp1 = LfFILT_New - LfFILT_Old;
		  if(LfFILT_temp1 >= 255.9921875)
		  {
		  LfFILT_Result = 255.9921875;
		  }
		  else if(LfFILT_temp1 <= -256)
		  {
		  LfFILT_Result = -256;
		  }
		  else
		  {
		  LfFILT_Result = LfFILT_temp1;
		  }		  
          LfFILT_Result = LfFILT_k_Coeff * LfFILT_Result;
          if (LfFILT_Result == 0)
              {
                 LfFILT_Result = 0.03125;  /* Force a change of 1 LSB */
              }

          LfFILT_Result = LfFILT_Old + LfFILT_Result;
      }

  else /* if (LfFILT_New < LfFILT_Old) */
      {
          LfFILT_temp1 = LfFILT_Old - LfFILT_New;
		  if(LfFILT_temp1 >= 255.9921875)
		  {
		  LfFILT_Result = 255.9921875;
		  }
		  else if(LfFILT_temp1 <= -256)
		  {
		  LfFILT_Result = -256;
		  }	
		  else
		  {
		  LfFILT_Result = LfFILT_temp1;
		  }
          LfFILT_Result = LfFILT_k_Coeff * LfFILT_Result;
          if (LfFILT_Result == 0)
              {
                 LfFILT_Result = 0.03125;  /* Force a change of 1 LSB */
              }

          LfFILT_Result = LfFILT_Old - LfFILT_Result;
      } /* end if (LfFILT_Old > LfFILT_New) */

  return(LfFILT_Result);

  } /* End ApplyFILT_1stOrderLag_usp */
  
  // float ApplyFILT_1stOrderLagIfEnbld_usp(
                                // float      LfFILT_Old,
                                // float      LfFILT_New,
                                // float  LfFILT_k_Coef )
// {
  // float  LfFILT_Result;

  // if ( LfFILT_k_Coef >= 1.0 )
  // {
    // LfFILT_Result = LfFILT_New;
  // }
  // else
  // {
    // LfFILT_Result = ApplyFILT_1stOrderLag_usp( LfFILT_Old, LfFILT_New, LfFILT_k_Coef );
  // }

  // return LfFILT_Result;
// }


signed short ApplyFILT_1stOrderLag_ssp_fixed(signed short LfFILT_Old_f,
                               signed short LfFILT_New_f,
                               unsigned short LfFILT_k_Coeff_f)
  {
  signed short LfFILT_Result;
  signed short LfFILT_temp1;
  unsigned short LfFILT_temp2;

  if ( (LfFILT_Old_f == LfFILT_New_f)
     || (LfFILT_k_Coeff_f == 0) )
      {
         LfFILT_Result = LfFILT_Old_f;
      }

  else if (LfFILT_New_f > LfFILT_Old_f)
      {
		  LfFILT_temp2 = LfFILT_New_f - LfFILT_Old_f;
		  
		  		  if(LfFILT_temp2 >= 32767)
		  {
		  LfFILT_Result = 32767;
		  }
		  else if(LfFILT_temp1 <= -32768)
		  {
		  LfFILT_Result = -32768;
		  }
		  else
		  {
		  LfFILT_Result = (signed short)LfFILT_temp2;
		  }		  
		  
          LfFILT_temp1 = LfFILT_k_Coeff_f * LfFILT_Result * 0.0000152587890625;
          if (LfFILT_temp1 == 0)
              {
                 LfFILT_Result = 1;  /* Force a change of 1 LSB */
              }
          LfFILT_Result = LfFILT_Old_f + LfFILT_temp1;
      }

  else /* if (LfFILT_New < LfFILT_Old) */
      {
          LfFILT_temp2 = LfFILT_Old_f - LfFILT_New_f;
		  
		  		  		  if(LfFILT_temp2 >= 32767)
		  {
		  LfFILT_Result = 32767;
		  }
		  else if(LfFILT_temp1 <= -32768)
		  {
		  LfFILT_Result = -32768;
		  }
		  else
		  {
		  LfFILT_Result = (signed short)LfFILT_temp2;
		  }
		  
          LfFILT_temp1 = LfFILT_k_Coeff_f * LfFILT_Result * 0.0000152587890625;
          if (LfFILT_temp1 == 0)
              {
                 LfFILT_Result = 1;  /* Force a change of 1 LSB */
              }

         LfFILT_Result = LfFILT_Old_f - LfFILT_temp1;
      } /* end if (LfFILT_Old > LfFILT_New) */

  return(LfFILT_Result);

  } /* End ApplyFILT_1stOrderLag_usp */
  
  // unsigned short ApplyFILT_1stOrderLagIfEnbld_usp_fixed(
                                // unsigned short      LfFILT_Old_f,
                                // unsigned short      LfFILT_New_f,
                                // unsigned short  LfFILT_k_Coef_f )
// {
  // unsigned short  LfFILT_Result;

  // if ( LfFILT_k_Coef_f >= 65535 )
  // {
    // LfFILT_Result = LfFILT_New_f;
  // }
  // else
  // {
    // LfFILT_Result = ApplyFILT_1stOrderLag_usp_fixed( LfFILT_Old_f, LfFILT_New_f, LfFILT_k_Coef_f );
  // }

  // return LfFILT_Result;
// }
