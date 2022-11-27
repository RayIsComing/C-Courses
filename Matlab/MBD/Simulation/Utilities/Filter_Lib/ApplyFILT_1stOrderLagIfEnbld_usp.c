float ApplyFILT_1stOrderLag_usp(float LfFILT_Old,
                               float LfFILT_New,
                               float LfFILT_k_Coeff )
  {
  float LfFILT_Result;

  if ( (LfFILT_Old == LfFILT_New)
     || (LfFILT_k_Coeff == 0) )
      {
         LfFILT_Result = LfFILT_Old;
      }

  else if (LfFILT_New > LfFILT_Old)
      {
          LfFILT_Result = LfFILT_New - LfFILT_Old;
          LfFILT_Result = LfFILT_k_Coeff * LfFILT_Result;
          if (LfFILT_Result == 0)
              {
                 LfFILT_Result = 0.03125;  /* Force a change of 1 LSB */
              }

          LfFILT_Result = LfFILT_Old + LfFILT_Result;
      }

  else /* if (LfFILT_New < LfFILT_Old) */
      {
          LfFILT_Result = LfFILT_Old - LfFILT_New;
          LfFILT_Result = LfFILT_k_Coeff * LfFILT_Result;
          if (LfFILT_Result == 0)
              {
                 LfFILT_Result = 0.03125;  /* Force a change of 1 LSB */
              }

          LfFILT_Result = LfFILT_Old - LfFILT_Result;
      } /* end if (LfFILT_Old > LfFILT_New) */

  return(LfFILT_Result);

  } /* End ApplyFILT_1stOrderLag_usp */
  
  float ApplyFILT_1stOrderLagIfEnbld_usp(
                                float      LfFILT_Old,
                                float      LfFILT_New,
                                float  LfFILT_k_Coef )
{
  float  LfFILT_Result;

  if ( LfFILT_k_Coef >= 1.0 )
  {
    LfFILT_Result = LfFILT_New;
  }
  else
  {
    LfFILT_Result = ApplyFILT_1stOrderLag_usp( LfFILT_Old, LfFILT_New, LfFILT_k_Coef );
  }

  return LfFILT_Result;
}


unsigned short ApplyFILT_1stOrderLag_usp_fixed(unsigned short LfFILT_Old_f,
                               unsigned short LfFILT_New_f,
                               unsigned short LfFILT_k_Coeff_f)
  {
  unsigned short LfFILT_Result;

  if ( (LfFILT_Old_f == LfFILT_New_f)
     || (LfFILT_k_Coeff_f == 0) )
      {
         LfFILT_Result = LfFILT_Old_f;
      }

  else if (LfFILT_New_f > LfFILT_Old_f)
      {
		  LfFILT_Result = LfFILT_New_f - LfFILT_Old_f;
          LfFILT_Result = (LfFILT_k_Coeff_f * LfFILT_Result * 0.0000152587890625);
          if (LfFILT_Result == 0)
              {
                 LfFILT_Result = 1;  /* Force a change of 1 LSB */
              }
          LfFILT_Result = LfFILT_Old_f + LfFILT_Result;
      }

  else /* if (LfFILT_New < LfFILT_Old) */
      {
          LfFILT_Result = LfFILT_Old_f - LfFILT_New_f;
          LfFILT_Result = (LfFILT_k_Coeff_f * LfFILT_Result * 0.0000152587890625);
          if (LfFILT_Result == 0)
              {
                 LfFILT_Result = 1;  /* Force a change of 1 LSB */
              }

          LfFILT_Result = LfFILT_Old_f - LfFILT_Result;
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
