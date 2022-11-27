#include <stdio.h>
//define a enum type;

//
typedef	enum{
		 hi = 1,
		 morning = 2,
		 afternoon = 3,
		 bye = 4
	} HiType;
 
int main()
{
	
	//int type;
	//定义个变量 type,他的数据类型是HiType; 
	HiType type;
	
	printf("Please input the type.\n");
	scanf("%d",&type);
	switch(type)
	{
		case hi:
			printf("你好");
			break;
		case morning:
		    printf("早上好");
			break;
		case afternoon:
		    printf("晚上好");
			break;
		case bye:
		    printf("再见");
		    break;
		default:
		    printf("what??") ;
	}
}



/*

typedef enum {
       CeFLOS_InitialState,
       CeFLOS_DewPtHeatState,
       CeFLOS_RampUpState,
       CeFLOS_MaxDC_State,
       CeFLOS_RampDownState,
       CeFLOS_SteadyState,
       CcFLOS_NumberOfFLOS_States
     } TeFLOS_DESIRED_DC_STATES;




TeFLOS_DESIRED_DC_STATES   LeFLOS_SW_HeaterDC_State;	
 
switch ( LeFLOS_SW_HeaterDC_State )
    {
      case CeFLOS_InitialState:
      case CeFLOS_DewPtHeatState:
        LeFLOS_SW_HeaterDC_State = CeFLOS_RampUpState;
        SetTIMC_StopWatch16(SaFLOS_t_RampTimer,
                            LeFLOS_SW_Sensor,
                            V_FLOS_CtrlTimerType(0) );
        ResumeTIMC_StopWatch(SaFLOS_RampTimerEnbl,
                             LeFLOS_SW_Sensor);
        break;

      case CeFLOS_RampUpState:
        if ( GetTIMC_t_StopWatch16(SaFLOS_t_RampTimer,
                                   LeFLOS_SW_Sensor) >=
             KaFLOS_t_SW_RampUpTime[LeFLOS_SW_SensorLoc] )
        {
          LeFLOS_SW_HeaterDC_State = CeFLOS_MaxDC_State;
          SetTIMC_StopWatch16(SaFLOS_t_RampTimer,
                              LeFLOS_SW_Sensor,
                              V_FLOS_CtrlTimerType(0) );
        }
        break;

      case CeFLOS_MaxDC_State:
        LwFLOS_t_MaxDC_Time = usLookup_xy_us(CpFLOS_t_SW_MaxDC_Time[LeFLOS_SW_SensorLoc],
                                             SfFLOS_CoolTempStartRscldIndex);

        if ( GetTIMC_t_StopWatch16(SaFLOS_t_RampTimer,
                                   LeFLOS_SW_Sensor) >=
             LwFLOS_t_MaxDC_Time )
        {
          LeFLOS_SW_HeaterDC_State = CeFLOS_RampDownState;
          SetTIMC_StopWatch16(SaFLOS_t_RampTimer,
                              LeFLOS_SW_Sensor,
                              V_FLOS_CtrlTimerType(0) );
        }
        break;

      case CeFLOS_RampDownState:
        if ( GetTIMC_t_StopWatch16(SaFLOS_t_RampTimer,
                                   LeFLOS_SW_Sensor) >=
             KfFLOS_t_RampDownTime )
        {
          LeFLOS_SW_HeaterDC_State = CeFLOS_SteadyState;
          SetTIMC_StopWatch16(SaFLOS_t_RampTimer,
                              LeFLOS_SW_Sensor,
                              V_FLOS_CtrlTimerType(0) );
          HaltTIMC_StopWatch(SaFLOS_RampTimerEnbl,
                             LeFLOS_SW_Sensor);
        }
        break;

      default:  /* CeFLOS_SteadyState or default */
        //LeFLOS_SW_HeaterDC_State = CeFLOS_SteadyState;
       // break;
  //  }  /*  end switch */

	//*/
