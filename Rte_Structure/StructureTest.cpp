extern VAR(Rte_tsASW_Core3_Task_25ms, RTE_VAR_NOINIT) Rte_ASW_Core3_Task_25ms; /* PRQA S 0759 */ /* MD_MSR_Union */
//
typedef struct
{
  Rte_tsTB_ASW_Core3_Task_25ms Rte_TB;
} Rte_tsASW_Core3_Task_25ms;
//
typedef struct
{
  Rte_DE_UInt8 Rte_I_VehInAdpr_PP_TjaSwtPrsd_TjaSwtPrsd;//Lei
} Rte_tsTB_ASW_Core3_Task_25ms;
//
typedef struct
{
  UInt8 value;
} Rte_DE_UInt8;
//

#  define Rte_ASW_Core3_Task_25ms.Rte_TB.Rte_I_VehInAdpr_PP_TjaSwtPrsd_TjaSwtPrsd.value=1;

#  define Rte_IRead_ACC_Step_PR_TjaSwtPrsd_TjaSwtPrsd()  (Rte_ASW_Core3_Task_25ms.Rte_TB.Rte_I_VehInAdpr_PP_TjaSwtPrsd_TjaSwtPrsd.value)
  


