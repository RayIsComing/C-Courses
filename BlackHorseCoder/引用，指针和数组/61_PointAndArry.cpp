


typedef short unsigned int WORD;

typedef WORD                                     FIXED_UW_16;
#define V_UW_16(val)                             ((WORD)((val)*65536))
#define S_UW_16                                  16


/* T_FILTER: Range [0, 1) Res: 0.0000152587890625 */
typedef FIXED_UW_16                              T_FILTER;
#define V_FILTER(val)                            (V_UW_16(val))
#define S_FILTER                                 S_UW_16
#define CfMAX_T_FILTER                           ((T_FILTER)MAX_UW)
#define CfMIN_T_FILTER                           ((T_FILTER)MIN_UW)


typedef short signed int   INTEGER;

typedef INTEGER                                  FIXED_SW_04;
#define V_SW_04(val)                             ((INTEGER)((val)*16))
#define S_SW_04                                  4


/* T_NEWTON_METER: Range [-2048Nm, 2048Nm) Res: 0.0625Nm */
typedef FIXED_SW_04                              T_NEWTON_METER;
#define V_NEWTON_METER(val)                      (V_SW_04(val))
#define S_NEWTON_METER                           S_SW_04
#define CfMAX_T_NEWTON_METER                     ((T_NEWTON_METER)MAX_SW)
#define CfMIN_T_NEWTON_METER                     ((T_NEWTON_METER)MIN_SW)


typedef WORD                                     FIXED_UW_08;
#define V_UW_08(val)                             ((WORD)((val)*256))
#define S_UW_08                                  8

/* T_AXIS: Range [0, 256) Res: 0.00390625 */
typedef FIXED_UW_08                              T_AXIS;
#define V_AXIS(val)                              (V_UW_08(val))
#define S_AXIS                                   S_UW_08
#define CfMAX_T_AXIS                             ((T_AXIS)MAX_UW)
#define CfMIN_T_AXIS                             ((T_AXIS)MIN_UW)



int ssLookup_xy_us(int* Map, unsigned int ScaledVariable )
{
  return 1;
}


typedef struct {
   WORD length;
   INTEGER data[17];
   } MAP17_SW;

const MAP17_SW        CRUZ_CALXADDR KtCRUZ_M_ControlHysteresis = {17,
     {V_NEWTON_METER(5),  V_NEWTON_METER(5),  V_NEWTON_METER(5),
      V_NEWTON_METER(5),  V_NEWTON_METER(5),  V_NEWTON_METER(5),
      V_NEWTON_METER(15), V_NEWTON_METER(15), V_NEWTON_METER(15),
      V_NEWTON_METER(15), V_NEWTON_METER(15), V_NEWTON_METER(15),
      V_NEWTON_METER(20), V_NEWTON_METER(20), V_NEWTON_METER(20),
      V_NEWTON_METER(20), V_NEWTON_METER(20)}};


static void DtrmnCRUZ_DsrdEngineTorque(void){

 // T_FILTER         LfCRUZ_k_TorqFiltCoeff;

 T_NEWTON_METER   LfCRUZ_M_DsrdEngineTorque;

 T_AXIS           LfCRUZ_RscldIndex;

T_NEWTON_METER   LfCRUZ_M_TorqueHysteresis;

 const int CsRSCL_MAP17_TORQ =
                       {17, V_NEWTON_METER(-100.0), V_NEWTON_METER(300.0) };

LfCRUZ_RscldIndex = usLookup_Rescale_xy_ss(&CsRSCL_MAP17_TORQ,
                         LfCRUZ_M_DsrdEngineTorque);

LfCRUZ_M_TorqueHysteresis = ssLookup_xy_us(&KtCRUZ_M_ControlHysteresis,
                         LfCRUZ_RscldIndex);





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

