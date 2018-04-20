
          integer N_DDL_BANKS 
          parameter ( N_DDL_BANKS = 210 ) 

          integer INDEX_TO_BANKS( N_DDL_BANKS ), INDEX16_TO_BANKS( N_DDL_BANKS ) 

          integer WHICH_ARRAY( N_DDL_BANKS ) 

          character*4 ddl_bank_names( N_DDL_BANKS ) 

        integer  BEAM_ind, BMPR_ind, BREP_ind, CALB_ind
        integer  CALL_ind, CC_ind, CC01_ind, CC1_ind
        integer  CCDI_ind, CCH_ind, CCMT_ind, CCPB_ind
        integer  CCPE_ind, CCRC_ind, CCS_ind, CCT_ind
        integer  CHI2_ind, CL01_ind, CLST_ind, CPED_ind
        integer  CSQL_ind, DC0_ind, DC1_ind, DCDW_ind
        integer  DCGM_ind, DCGW_ind, DCH_ind, DCMN_ind
        integer  DCPB_ind, DCV1_ind, DCV2_ind, DCV3_ind
        integer  DDLY_ind, DGEO_ind, DHCL_ind, DITM_ind
        integer  DOCA_ind, DPCP_ind, DPSP_ind, DSPC_ind
        integer  DSPS_ind, DSTC_ind, DTCP_ind, DTRK_ind
        integer  EC_ind, EC01_ind, EC1_ind, EC1P_ind
        integer  EC1R_ind, ECCA_ind, ECCL_ind, ECCT_ind
        integer  ECDI_ind, ECG_ind, ECH_ind, ECHB_ind
        integer  ECMT_ind, ECP_ind, ECP1_ind, ECPB_ind
        integer  ECPC_ind, ECPE_ind, ECPI_ind, ECPO_ind
        integer  ECRB_ind, ECS_ind, ECT_ind, EID0_ind
        integer  EPIC_ind, EVNT_ind, FBPM_ind, G1SL_ind
        integer  G2SL_ind, G3SL_ind, G4SL_ind, GCPB_ind
        integer  GGEO_ind, GP_X_ind, GP_Y_ind, GPAR_ind
        integer  GPID_ind, HBER_ind, HBID_ind, HBLA_ind
        integer  HBTB_ind, HBTR_ind, HCAL_ind, HDPL_ind
        integer  HEAD_ind, HEVT_ind, HLB_ind, HLS_ind
        integer  IC_ind, ICHB_ind, ICPB_ind, KFIT_ind
        integer  L1PG_ind, L2H_ind, L2S_ind, LASR_ind
        integer  LCDI_ind, LCPB_ind, LOWQ_ind, LSRT_ind
        integer  MCEV_ind, MCHD_ind, MCTK_ind, MCVX_ind
        integer  MS1_ind, MTRK_ind, MVRT_ind, PART_ind
        integer  PCO_ind, PHTM_ind, PID1_ind, PID2_ind
        integer  PID3_ind, PID4_ind, PID5_ind, PID6_ind
        integer  PIDT_ind, PRTM_ind, PSO_ind, PTDB_ind
        integer  RC26_ind, RCST_ind, REF_ind, RF_ind
        integer  RFT_ind, RGLK_ind, RNLG_ind, RNPE_ind
        integer  RTSL_ind, RUNC_ind, S1ST_ind, SC_ind
        integer  SC1_ind, SCC_ind, SCDI_ind, SCG_ind
        integer  SCGD_ind, SCH_ind, SCMD_ind, SCMT_ind
        integer  SCMW_ind, SCP_ind, SCPB_ind, SCPE_ind
        integer  SCPS_ind, SCR_ind, SCRC_ind, SCS_ind
        integer  SCT_ind, SGMP_ind, SH_ind, SHHB_ind
        integer  SHPB_ind, SHT_ind, SPAR_ind, SPIN_ind
        integer  ST_ind, ST1_ind, STG_ind, STH_ind
        integer  STN0_ind, STN1_ind, STPB_ind, STPE_ind
        integer  STR_ind, STRE_ind, STS_ind, STSN_ind
        integer  SYNC_ind, TACO_ind, TAGE_ind, TAGI_ind
        integer  TAGM_ind, TAGR_ind, TAGT_ind, TATL_ind
        integer  TATR_ind, TBER_ind, TBID_ind, TBLA_ind
        integer  TBTR_ind, TCSB_ind, TCT_ind, TDPL_ind
        integer  TESC_ind, TGBI_ind, TGEO_ind, TGPB_ind
        integer  TGS_ind, TGTL_ind, TGTR_ind, TLV1_ind
        integer  TPC_ind, TPCH_ind, TPE0_ind, TPE1_ind
        integer  TRCF_ind, TRGS_ind, TRKS_ind, TRL1_ind
        integer  TRPB_ind, TRUE_ind, TSPR_ind, TSRG_ind
        integer  UNUS_ind, VERT_ind
        integer  BEAM_ind16, BMPR_ind16, BREP_ind16, CALB_ind16
        integer  CALL_ind16, CC_ind16, CC01_ind16, CC1_ind16
        integer  CCDI_ind16, CCH_ind16, CCMT_ind16, CCPB_ind16
        integer  CCPE_ind16, CCRC_ind16, CCS_ind16, CCT_ind16
        integer  CHI2_ind16, CL01_ind16, CLST_ind16, CPED_ind16
        integer  CSQL_ind16, DC0_ind16, DC1_ind16, DCDW_ind16
        integer  DCGM_ind16, DCGW_ind16, DCH_ind16, DCMN_ind16
        integer  DCPB_ind16, DCV1_ind16, DCV2_ind16, DCV3_ind16
        integer  DDLY_ind16, DGEO_ind16, DHCL_ind16, DITM_ind16
        integer  DOCA_ind16, DPCP_ind16, DPSP_ind16, DSPC_ind16
        integer  DSPS_ind16, DSTC_ind16, DTCP_ind16, DTRK_ind16
        integer  EC_ind16, EC01_ind16, EC1_ind16, EC1P_ind16
        integer  EC1R_ind16, ECCA_ind16, ECCL_ind16, ECCT_ind16
        integer  ECDI_ind16, ECG_ind16, ECH_ind16, ECHB_ind16
        integer  ECMT_ind16, ECP_ind16, ECP1_ind16, ECPB_ind16
        integer  ECPC_ind16, ECPE_ind16, ECPI_ind16, ECPO_ind16
        integer  ECRB_ind16, ECS_ind16, ECT_ind16, EID0_ind16
        integer  EPIC_ind16, EVNT_ind16, FBPM_ind16, G1SL_ind16
        integer  G2SL_ind16, G3SL_ind16, G4SL_ind16, GCPB_ind16
        integer  GGEO_ind16, GP_X_ind16, GP_Y_ind16, GPAR_ind16
        integer  GPID_ind16, HBER_ind16, HBID_ind16, HBLA_ind16
        integer  HBTB_ind16, HBTR_ind16, HCAL_ind16, HDPL_ind16
        integer  HEAD_ind16, HEVT_ind16, HLB_ind16, HLS_ind16
        integer  IC_ind16, ICHB_ind16, ICPB_ind16, KFIT_ind16
        integer  L1PG_ind16, L2H_ind16, L2S_ind16, LASR_ind16
        integer  LCDI_ind16, LCPB_ind16, LOWQ_ind16, LSRT_ind16
        integer  MCEV_ind16, MCHD_ind16, MCTK_ind16, MCVX_ind16
        integer  MS1_ind16, MTRK_ind16, MVRT_ind16, PART_ind16
        integer  PCO_ind16, PHTM_ind16, PID1_ind16, PID2_ind16
        integer  PID3_ind16, PID4_ind16, PID5_ind16, PID6_ind16
        integer  PIDT_ind16, PRTM_ind16, PSO_ind16, PTDB_ind16
        integer  RC26_ind16, RCST_ind16, REF_ind16, RF_ind16
        integer  RFT_ind16, RGLK_ind16, RNLG_ind16, RNPE_ind16
        integer  RTSL_ind16, RUNC_ind16, S1ST_ind16, SC_ind16
        integer  SC1_ind16, SCC_ind16, SCDI_ind16, SCG_ind16
        integer  SCGD_ind16, SCH_ind16, SCMD_ind16, SCMT_ind16
        integer  SCMW_ind16, SCP_ind16, SCPB_ind16, SCPE_ind16
        integer  SCPS_ind16, SCR_ind16, SCRC_ind16, SCS_ind16
        integer  SCT_ind16, SGMP_ind16, SH_ind16, SHHB_ind16
        integer  SHPB_ind16, SHT_ind16, SPAR_ind16, SPIN_ind16
        integer  ST_ind16, ST1_ind16, STG_ind16, STH_ind16
        integer  STN0_ind16, STN1_ind16, STPB_ind16, STPE_ind16
        integer  STR_ind16, STRE_ind16, STS_ind16, STSN_ind16
        integer  SYNC_ind16, TACO_ind16, TAGE_ind16, TAGI_ind16
        integer  TAGM_ind16, TAGR_ind16, TAGT_ind16, TATL_ind16
        integer  TATR_ind16, TBER_ind16, TBID_ind16, TBLA_ind16
        integer  TBTR_ind16, TCSB_ind16, TCT_ind16, TDPL_ind16
        integer  TESC_ind16, TGBI_ind16, TGEO_ind16, TGPB_ind16
        integer  TGS_ind16, TGTL_ind16, TGTR_ind16, TLV1_ind16
        integer  TPC_ind16, TPCH_ind16, TPE0_ind16, TPE1_ind16
        integer  TRCF_ind16, TRGS_ind16, TRKS_ind16, TRL1_ind16
        integer  TRPB_ind16, TRUE_ind16, TSPR_ind16, TSRG_ind16
        integer  UNUS_ind16, VERT_ind16
        integer  BEAM_array, BMPR_array, BREP_array, CALB_array
        integer  CALL_array, CC_array, CC01_array, CC1_array
        integer  CCDI_array, CCH_array, CCMT_array, CCPB_array
        integer  CCPE_array, CCRC_array, CCS_array, CCT_array
        integer  CHI2_array, CL01_array, CLST_array, CPED_array
        integer  CSQL_array, DC0_array, DC1_array, DCDW_array
        integer  DCGM_array, DCGW_array, DCH_array, DCMN_array
        integer  DCPB_array, DCV1_array, DCV2_array, DCV3_array
        integer  DDLY_array, DGEO_array, DHCL_array, DITM_array
        integer  DOCA_array, DPCP_array, DPSP_array, DSPC_array
        integer  DSPS_array, DSTC_array, DTCP_array, DTRK_array
        integer  EC_array, EC01_array, EC1_array, EC1P_array
        integer  EC1R_array, ECCA_array, ECCL_array, ECCT_array
        integer  ECDI_array, ECG_array, ECH_array, ECHB_array
        integer  ECMT_array, ECP_array, ECP1_array, ECPB_array
        integer  ECPC_array, ECPE_array, ECPI_array, ECPO_array
        integer  ECRB_array, ECS_array, ECT_array, EID0_array
        integer  EPIC_array, EVNT_array, FBPM_array, G1SL_array
        integer  G2SL_array, G3SL_array, G4SL_array, GCPB_array
        integer  GGEO_array, GP_X_array, GP_Y_array, GPAR_array
        integer  GPID_array, HBER_array, HBID_array, HBLA_array
        integer  HBTB_array, HBTR_array, HCAL_array, HDPL_array
        integer  HEAD_array, HEVT_array, HLB_array, HLS_array
        integer  IC_array, ICHB_array, ICPB_array, KFIT_array
        integer  L1PG_array, L2H_array, L2S_array, LASR_array
        integer  LCDI_array, LCPB_array, LOWQ_array, LSRT_array
        integer  MCEV_array, MCHD_array, MCTK_array, MCVX_array
        integer  MS1_array, MTRK_array, MVRT_array, PART_array
        integer  PCO_array, PHTM_array, PID1_array, PID2_array
        integer  PID3_array, PID4_array, PID5_array, PID6_array
        integer  PIDT_array, PRTM_array, PSO_array, PTDB_array
        integer  RC26_array, RCST_array, REF_array, RF_array
        integer  RFT_array, RGLK_array, RNLG_array, RNPE_array
        integer  RTSL_array, RUNC_array, S1ST_array, SC_array
        integer  SC1_array, SCC_array, SCDI_array, SCG_array
        integer  SCGD_array, SCH_array, SCMD_array, SCMT_array
        integer  SCMW_array, SCP_array, SCPB_array, SCPE_array
        integer  SCPS_array, SCR_array, SCRC_array, SCS_array
        integer  SCT_array, SGMP_array, SH_array, SHHB_array
        integer  SHPB_array, SHT_array, SPAR_array, SPIN_array
        integer  ST_array, ST1_array, STG_array, STH_array
        integer  STN0_array, STN1_array, STPB_array, STPE_array
        integer  STR_array, STRE_array, STS_array, STSN_array
        integer  SYNC_array, TACO_array, TAGE_array, TAGI_array
        integer  TAGM_array, TAGR_array, TAGT_array, TATL_array
        integer  TATR_array, TBER_array, TBID_array, TBLA_array
        integer  TBTR_array, TCSB_array, TCT_array, TDPL_array
        integer  TESC_array, TGBI_array, TGEO_array, TGPB_array
        integer  TGS_array, TGTL_array, TGTR_array, TLV1_array
        integer  TPC_array, TPCH_array, TPE0_array, TPE1_array
        integer  TRCF_array, TRGS_array, TRKS_array, TRL1_array
        integer  TRPB_array, TRUE_array, TSPR_array, TSRG_array
        integer  UNUS_array, VERT_array

C define the COMMON BLOCK 


          common /clas_index/
     +        index_to_banks, index16_to_banks, which_array 

C  Now equivalance the array to the individual names
        EQUIVALENCE (INDEX_TO_BANKS(1) , BEAM_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(2) , BMPR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(3) , BREP_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(4) , CALB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(5) , CALL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(6) , CC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(7) , CC01_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(8) , CC1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(9) , CCDI_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(10) , CCH_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(11) , CCMT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(12) , CCPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(13) , CCPE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(14) , CCRC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(15) , CCS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(16) , CCT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(17) , CHI2_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(18) , CL01_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(19) , CLST_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(20) , CPED_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(21) , CSQL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(22) , DC0_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(23) , DC1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(24) , DCDW_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(25) , DCGM_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(26) , DCGW_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(27) , DCH_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(28) , DCMN_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(29) , DCPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(30) , DCV1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(31) , DCV2_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(32) , DCV3_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(33) , DDLY_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(34) , DGEO_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(35) , DHCL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(36) , DITM_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(37) , DOCA_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(38) , DPCP_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(39) , DPSP_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(40) , DSPC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(41) , DSPS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(42) , DSTC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(43) , DTCP_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(44) , DTRK_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(45) , EC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(46) , EC01_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(47) , EC1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(48) , EC1P_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(49) , EC1R_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(50) , ECCA_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(51) , ECCL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(52) , ECCT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(53) , ECDI_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(54) , ECG_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(55) , ECH_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(56) , ECHB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(57) , ECMT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(58) , ECP_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(59) , ECP1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(60) , ECPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(61) , ECPC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(62) , ECPE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(63) , ECPI_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(64) , ECPO_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(65) , ECRB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(66) , ECS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(67) , ECT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(68) , EID0_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(69) , EPIC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(70) , EVNT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(71) , FBPM_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(72) , G1SL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(73) , G2SL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(74) , G3SL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(75) , G4SL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(76) , GCPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(77) , GGEO_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(78) , GP_X_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(79) , GP_Y_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(80) , GPAR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(81) , GPID_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(82) , HBER_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(83) , HBID_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(84) , HBLA_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(85) , HBTB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(86) , HBTR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(87) , HCAL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(88) , HDPL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(89) , HEAD_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(90) , HEVT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(91) , HLB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(92) , HLS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(93) , IC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(94) , ICHB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(95) , ICPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(96) , KFIT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(97) , L1PG_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(98) , L2H_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(99) , L2S_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(100) , LASR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(101) , LCDI_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(102) , LCPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(103) , LOWQ_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(104) , LSRT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(105) , MCEV_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(106) , MCHD_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(107) , MCTK_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(108) , MCVX_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(109) , MS1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(110) , MTRK_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(111) , MVRT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(112) , PART_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(113) , PCO_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(114) , PHTM_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(115) , PID1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(116) , PID2_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(117) , PID3_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(118) , PID4_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(119) , PID5_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(120) , PID6_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(121) , PIDT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(122) , PRTM_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(123) , PSO_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(124) , PTDB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(125) , RC26_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(126) , RCST_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(127) , REF_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(128) , RF_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(129) , RFT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(130) , RGLK_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(131) , RNLG_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(132) , RNPE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(133) , RTSL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(134) , RUNC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(135) , S1ST_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(136) , SC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(137) , SC1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(138) , SCC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(139) , SCDI_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(140) , SCG_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(141) , SCGD_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(142) , SCH_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(143) , SCMD_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(144) , SCMT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(145) , SCMW_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(146) , SCP_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(147) , SCPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(148) , SCPE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(149) , SCPS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(150) , SCR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(151) , SCRC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(152) , SCS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(153) , SCT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(154) , SGMP_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(155) , SH_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(156) , SHHB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(157) , SHPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(158) , SHT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(159) , SPAR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(160) , SPIN_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(161) , ST_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(162) , ST1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(163) , STG_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(164) , STH_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(165) , STN0_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(166) , STN1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(167) , STPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(168) , STPE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(169) , STR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(170) , STRE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(171) , STS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(172) , STSN_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(173) , SYNC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(174) , TACO_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(175) , TAGE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(176) , TAGI_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(177) , TAGM_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(178) , TAGR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(179) , TAGT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(180) , TATL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(181) , TATR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(182) , TBER_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(183) , TBID_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(184) , TBLA_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(185) , TBTR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(186) , TCSB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(187) , TCT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(188) , TDPL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(189) , TESC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(190) , TGBI_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(191) , TGEO_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(192) , TGPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(193) , TGS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(194) , TGTL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(195) , TGTR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(196) , TLV1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(197) , TPC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(198) , TPCH_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(199) , TPE0_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(200) , TPE1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(201) , TRCF_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(202) , TRGS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(203) , TRKS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(204) , TRL1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(205) , TRPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(206) , TRUE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(207) , TSPR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(208) , TSRG_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(209) , UNUS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(210) , VERT_ind) 

C  Now equivalance the array to the individual names for the 16 bit banks
        EQUIVALENCE (INDEX16_TO_BANKS(1) , BEAM_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(2) , BMPR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(3) , BREP_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(4) , CALB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(5) , CALL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(6) , CC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(7) , CC01_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(8) , CC1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(9) , CCDI_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(10) , CCH_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(11) , CCMT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(12) , CCPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(13) , CCPE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(14) , CCRC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(15) , CCS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(16) , CCT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(17) , CHI2_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(18) , CL01_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(19) , CLST_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(20) , CPED_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(21) , CSQL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(22) , DC0_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(23) , DC1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(24) , DCDW_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(25) , DCGM_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(26) , DCGW_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(27) , DCH_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(28) , DCMN_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(29) , DCPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(30) , DCV1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(31) , DCV2_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(32) , DCV3_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(33) , DDLY_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(34) , DGEO_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(35) , DHCL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(36) , DITM_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(37) , DOCA_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(38) , DPCP_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(39) , DPSP_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(40) , DSPC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(41) , DSPS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(42) , DSTC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(43) , DTCP_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(44) , DTRK_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(45) , EC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(46) , EC01_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(47) , EC1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(48) , EC1P_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(49) , EC1R_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(50) , ECCA_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(51) , ECCL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(52) , ECCT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(53) , ECDI_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(54) , ECG_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(55) , ECH_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(56) , ECHB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(57) , ECMT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(58) , ECP_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(59) , ECP1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(60) , ECPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(61) , ECPC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(62) , ECPE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(63) , ECPI_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(64) , ECPO_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(65) , ECRB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(66) , ECS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(67) , ECT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(68) , EID0_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(69) , EPIC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(70) , EVNT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(71) , FBPM_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(72) , G1SL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(73) , G2SL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(74) , G3SL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(75) , G4SL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(76) , GCPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(77) , GGEO_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(78) , GP_X_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(79) , GP_Y_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(80) , GPAR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(81) , GPID_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(82) , HBER_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(83) , HBID_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(84) , HBLA_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(85) , HBTB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(86) , HBTR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(87) , HCAL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(88) , HDPL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(89) , HEAD_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(90) , HEVT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(91) , HLB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(92) , HLS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(93) , IC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(94) , ICHB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(95) , ICPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(96) , KFIT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(97) , L1PG_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(98) , L2H_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(99) , L2S_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(100) , LASR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(101) , LCDI_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(102) , LCPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(103) , LOWQ_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(104) , LSRT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(105) , MCEV_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(106) , MCHD_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(107) , MCTK_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(108) , MCVX_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(109) , MS1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(110) , MTRK_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(111) , MVRT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(112) , PART_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(113) , PCO_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(114) , PHTM_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(115) , PID1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(116) , PID2_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(117) , PID3_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(118) , PID4_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(119) , PID5_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(120) , PID6_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(121) , PIDT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(122) , PRTM_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(123) , PSO_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(124) , PTDB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(125) , RC26_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(126) , RCST_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(127) , REF_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(128) , RF_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(129) , RFT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(130) , RGLK_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(131) , RNLG_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(132) , RNPE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(133) , RTSL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(134) , RUNC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(135) , S1ST_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(136) , SC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(137) , SC1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(138) , SCC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(139) , SCDI_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(140) , SCG_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(141) , SCGD_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(142) , SCH_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(143) , SCMD_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(144) , SCMT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(145) , SCMW_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(146) , SCP_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(147) , SCPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(148) , SCPE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(149) , SCPS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(150) , SCR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(151) , SCRC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(152) , SCS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(153) , SCT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(154) , SGMP_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(155) , SH_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(156) , SHHB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(157) , SHPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(158) , SHT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(159) , SPAR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(160) , SPIN_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(161) , ST_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(162) , ST1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(163) , STG_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(164) , STH_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(165) , STN0_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(166) , STN1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(167) , STPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(168) , STPE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(169) , STR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(170) , STRE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(171) , STS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(172) , STSN_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(173) , SYNC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(174) , TACO_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(175) , TAGE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(176) , TAGI_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(177) , TAGM_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(178) , TAGR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(179) , TAGT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(180) , TATL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(181) , TATR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(182) , TBER_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(183) , TBID_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(184) , TBLA_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(185) , TBTR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(186) , TCSB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(187) , TCT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(188) , TDPL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(189) , TESC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(190) , TGBI_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(191) , TGEO_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(192) , TGPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(193) , TGS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(194) , TGTL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(195) , TGTR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(196) , TLV1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(197) , TPC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(198) , TPCH_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(199) , TPE0_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(200) , TPE1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(201) , TRCF_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(202) , TRGS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(203) , TRKS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(204) , TRL1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(205) , TRPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(206) , TRUE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(207) , TSPR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(208) , TSRG_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(209) , UNUS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(210) , VERT_ind16) 

C  Now equivalance the array which_bank which is a flag to which
     
C  IW or JW array 
        EQUIVALENCE (WHICH_ARRAY(1) , BEAM_array) 
        EQUIVALENCE (WHICH_ARRAY(2) , BMPR_array) 
        EQUIVALENCE (WHICH_ARRAY(3) , BREP_array) 
        EQUIVALENCE (WHICH_ARRAY(4) , CALB_array) 
        EQUIVALENCE (WHICH_ARRAY(5) , CALL_array) 
        EQUIVALENCE (WHICH_ARRAY(6) , CC_array) 
        EQUIVALENCE (WHICH_ARRAY(7) , CC01_array) 
        EQUIVALENCE (WHICH_ARRAY(8) , CC1_array) 
        EQUIVALENCE (WHICH_ARRAY(9) , CCDI_array) 
        EQUIVALENCE (WHICH_ARRAY(10) , CCH_array) 
        EQUIVALENCE (WHICH_ARRAY(11) , CCMT_array) 
        EQUIVALENCE (WHICH_ARRAY(12) , CCPB_array) 
        EQUIVALENCE (WHICH_ARRAY(13) , CCPE_array) 
        EQUIVALENCE (WHICH_ARRAY(14) , CCRC_array) 
        EQUIVALENCE (WHICH_ARRAY(15) , CCS_array) 
        EQUIVALENCE (WHICH_ARRAY(16) , CCT_array) 
        EQUIVALENCE (WHICH_ARRAY(17) , CHI2_array) 
        EQUIVALENCE (WHICH_ARRAY(18) , CL01_array) 
        EQUIVALENCE (WHICH_ARRAY(19) , CLST_array) 
        EQUIVALENCE (WHICH_ARRAY(20) , CPED_array) 
        EQUIVALENCE (WHICH_ARRAY(21) , CSQL_array) 
        EQUIVALENCE (WHICH_ARRAY(22) , DC0_array) 
        EQUIVALENCE (WHICH_ARRAY(23) , DC1_array) 
        EQUIVALENCE (WHICH_ARRAY(24) , DCDW_array) 
        EQUIVALENCE (WHICH_ARRAY(25) , DCGM_array) 
        EQUIVALENCE (WHICH_ARRAY(26) , DCGW_array) 
        EQUIVALENCE (WHICH_ARRAY(27) , DCH_array) 
        EQUIVALENCE (WHICH_ARRAY(28) , DCMN_array) 
        EQUIVALENCE (WHICH_ARRAY(29) , DCPB_array) 
        EQUIVALENCE (WHICH_ARRAY(30) , DCV1_array) 
        EQUIVALENCE (WHICH_ARRAY(31) , DCV2_array) 
        EQUIVALENCE (WHICH_ARRAY(32) , DCV3_array) 
        EQUIVALENCE (WHICH_ARRAY(33) , DDLY_array) 
        EQUIVALENCE (WHICH_ARRAY(34) , DGEO_array) 
        EQUIVALENCE (WHICH_ARRAY(35) , DHCL_array) 
        EQUIVALENCE (WHICH_ARRAY(36) , DITM_array) 
        EQUIVALENCE (WHICH_ARRAY(37) , DOCA_array) 
        EQUIVALENCE (WHICH_ARRAY(38) , DPCP_array) 
        EQUIVALENCE (WHICH_ARRAY(39) , DPSP_array) 
        EQUIVALENCE (WHICH_ARRAY(40) , DSPC_array) 
        EQUIVALENCE (WHICH_ARRAY(41) , DSPS_array) 
        EQUIVALENCE (WHICH_ARRAY(42) , DSTC_array) 
        EQUIVALENCE (WHICH_ARRAY(43) , DTCP_array) 
        EQUIVALENCE (WHICH_ARRAY(44) , DTRK_array) 
        EQUIVALENCE (WHICH_ARRAY(45) , EC_array) 
        EQUIVALENCE (WHICH_ARRAY(46) , EC01_array) 
        EQUIVALENCE (WHICH_ARRAY(47) , EC1_array) 
        EQUIVALENCE (WHICH_ARRAY(48) , EC1P_array) 
        EQUIVALENCE (WHICH_ARRAY(49) , EC1R_array) 
        EQUIVALENCE (WHICH_ARRAY(50) , ECCA_array) 
        EQUIVALENCE (WHICH_ARRAY(51) , ECCL_array) 
        EQUIVALENCE (WHICH_ARRAY(52) , ECCT_array) 
        EQUIVALENCE (WHICH_ARRAY(53) , ECDI_array) 
        EQUIVALENCE (WHICH_ARRAY(54) , ECG_array) 
        EQUIVALENCE (WHICH_ARRAY(55) , ECH_array) 
        EQUIVALENCE (WHICH_ARRAY(56) , ECHB_array) 
        EQUIVALENCE (WHICH_ARRAY(57) , ECMT_array) 
        EQUIVALENCE (WHICH_ARRAY(58) , ECP_array) 
        EQUIVALENCE (WHICH_ARRAY(59) , ECP1_array) 
        EQUIVALENCE (WHICH_ARRAY(60) , ECPB_array) 
        EQUIVALENCE (WHICH_ARRAY(61) , ECPC_array) 
        EQUIVALENCE (WHICH_ARRAY(62) , ECPE_array) 
        EQUIVALENCE (WHICH_ARRAY(63) , ECPI_array) 
        EQUIVALENCE (WHICH_ARRAY(64) , ECPO_array) 
        EQUIVALENCE (WHICH_ARRAY(65) , ECRB_array) 
        EQUIVALENCE (WHICH_ARRAY(66) , ECS_array) 
        EQUIVALENCE (WHICH_ARRAY(67) , ECT_array) 
        EQUIVALENCE (WHICH_ARRAY(68) , EID0_array) 
        EQUIVALENCE (WHICH_ARRAY(69) , EPIC_array) 
        EQUIVALENCE (WHICH_ARRAY(70) , EVNT_array) 
        EQUIVALENCE (WHICH_ARRAY(71) , FBPM_array) 
        EQUIVALENCE (WHICH_ARRAY(72) , G1SL_array) 
        EQUIVALENCE (WHICH_ARRAY(73) , G2SL_array) 
        EQUIVALENCE (WHICH_ARRAY(74) , G3SL_array) 
        EQUIVALENCE (WHICH_ARRAY(75) , G4SL_array) 
        EQUIVALENCE (WHICH_ARRAY(76) , GCPB_array) 
        EQUIVALENCE (WHICH_ARRAY(77) , GGEO_array) 
        EQUIVALENCE (WHICH_ARRAY(78) , GP_X_array) 
        EQUIVALENCE (WHICH_ARRAY(79) , GP_Y_array) 
        EQUIVALENCE (WHICH_ARRAY(80) , GPAR_array) 
        EQUIVALENCE (WHICH_ARRAY(81) , GPID_array) 
        EQUIVALENCE (WHICH_ARRAY(82) , HBER_array) 
        EQUIVALENCE (WHICH_ARRAY(83) , HBID_array) 
        EQUIVALENCE (WHICH_ARRAY(84) , HBLA_array) 
        EQUIVALENCE (WHICH_ARRAY(85) , HBTB_array) 
        EQUIVALENCE (WHICH_ARRAY(86) , HBTR_array) 
        EQUIVALENCE (WHICH_ARRAY(87) , HCAL_array) 
        EQUIVALENCE (WHICH_ARRAY(88) , HDPL_array) 
        EQUIVALENCE (WHICH_ARRAY(89) , HEAD_array) 
        EQUIVALENCE (WHICH_ARRAY(90) , HEVT_array) 
        EQUIVALENCE (WHICH_ARRAY(91) , HLB_array) 
        EQUIVALENCE (WHICH_ARRAY(92) , HLS_array) 
        EQUIVALENCE (WHICH_ARRAY(93) , IC_array) 
        EQUIVALENCE (WHICH_ARRAY(94) , ICHB_array) 
        EQUIVALENCE (WHICH_ARRAY(95) , ICPB_array) 
        EQUIVALENCE (WHICH_ARRAY(96) , KFIT_array) 
        EQUIVALENCE (WHICH_ARRAY(97) , L1PG_array) 
        EQUIVALENCE (WHICH_ARRAY(98) , L2H_array) 
        EQUIVALENCE (WHICH_ARRAY(99) , L2S_array) 
        EQUIVALENCE (WHICH_ARRAY(100) , LASR_array) 
        EQUIVALENCE (WHICH_ARRAY(101) , LCDI_array) 
        EQUIVALENCE (WHICH_ARRAY(102) , LCPB_array) 
        EQUIVALENCE (WHICH_ARRAY(103) , LOWQ_array) 
        EQUIVALENCE (WHICH_ARRAY(104) , LSRT_array) 
        EQUIVALENCE (WHICH_ARRAY(105) , MCEV_array) 
        EQUIVALENCE (WHICH_ARRAY(106) , MCHD_array) 
        EQUIVALENCE (WHICH_ARRAY(107) , MCTK_array) 
        EQUIVALENCE (WHICH_ARRAY(108) , MCVX_array) 
        EQUIVALENCE (WHICH_ARRAY(109) , MS1_array) 
        EQUIVALENCE (WHICH_ARRAY(110) , MTRK_array) 
        EQUIVALENCE (WHICH_ARRAY(111) , MVRT_array) 
        EQUIVALENCE (WHICH_ARRAY(112) , PART_array) 
        EQUIVALENCE (WHICH_ARRAY(113) , PCO_array) 
        EQUIVALENCE (WHICH_ARRAY(114) , PHTM_array) 
        EQUIVALENCE (WHICH_ARRAY(115) , PID1_array) 
        EQUIVALENCE (WHICH_ARRAY(116) , PID2_array) 
        EQUIVALENCE (WHICH_ARRAY(117) , PID3_array) 
        EQUIVALENCE (WHICH_ARRAY(118) , PID4_array) 
        EQUIVALENCE (WHICH_ARRAY(119) , PID5_array) 
        EQUIVALENCE (WHICH_ARRAY(120) , PID6_array) 
        EQUIVALENCE (WHICH_ARRAY(121) , PIDT_array) 
        EQUIVALENCE (WHICH_ARRAY(122) , PRTM_array) 
        EQUIVALENCE (WHICH_ARRAY(123) , PSO_array) 
        EQUIVALENCE (WHICH_ARRAY(124) , PTDB_array) 
        EQUIVALENCE (WHICH_ARRAY(125) , RC26_array) 
        EQUIVALENCE (WHICH_ARRAY(126) , RCST_array) 
        EQUIVALENCE (WHICH_ARRAY(127) , REF_array) 
        EQUIVALENCE (WHICH_ARRAY(128) , RF_array) 
        EQUIVALENCE (WHICH_ARRAY(129) , RFT_array) 
        EQUIVALENCE (WHICH_ARRAY(130) , RGLK_array) 
        EQUIVALENCE (WHICH_ARRAY(131) , RNLG_array) 
        EQUIVALENCE (WHICH_ARRAY(132) , RNPE_array) 
        EQUIVALENCE (WHICH_ARRAY(133) , RTSL_array) 
        EQUIVALENCE (WHICH_ARRAY(134) , RUNC_array) 
        EQUIVALENCE (WHICH_ARRAY(135) , S1ST_array) 
        EQUIVALENCE (WHICH_ARRAY(136) , SC_array) 
        EQUIVALENCE (WHICH_ARRAY(137) , SC1_array) 
        EQUIVALENCE (WHICH_ARRAY(138) , SCC_array) 
        EQUIVALENCE (WHICH_ARRAY(139) , SCDI_array) 
        EQUIVALENCE (WHICH_ARRAY(140) , SCG_array) 
        EQUIVALENCE (WHICH_ARRAY(141) , SCGD_array) 
        EQUIVALENCE (WHICH_ARRAY(142) , SCH_array) 
        EQUIVALENCE (WHICH_ARRAY(143) , SCMD_array) 
        EQUIVALENCE (WHICH_ARRAY(144) , SCMT_array) 
        EQUIVALENCE (WHICH_ARRAY(145) , SCMW_array) 
        EQUIVALENCE (WHICH_ARRAY(146) , SCP_array) 
        EQUIVALENCE (WHICH_ARRAY(147) , SCPB_array) 
        EQUIVALENCE (WHICH_ARRAY(148) , SCPE_array) 
        EQUIVALENCE (WHICH_ARRAY(149) , SCPS_array) 
        EQUIVALENCE (WHICH_ARRAY(150) , SCR_array) 
        EQUIVALENCE (WHICH_ARRAY(151) , SCRC_array) 
        EQUIVALENCE (WHICH_ARRAY(152) , SCS_array) 
        EQUIVALENCE (WHICH_ARRAY(153) , SCT_array) 
        EQUIVALENCE (WHICH_ARRAY(154) , SGMP_array) 
        EQUIVALENCE (WHICH_ARRAY(155) , SH_array) 
        EQUIVALENCE (WHICH_ARRAY(156) , SHHB_array) 
        EQUIVALENCE (WHICH_ARRAY(157) , SHPB_array) 
        EQUIVALENCE (WHICH_ARRAY(158) , SHT_array) 
        EQUIVALENCE (WHICH_ARRAY(159) , SPAR_array) 
        EQUIVALENCE (WHICH_ARRAY(160) , SPIN_array) 
        EQUIVALENCE (WHICH_ARRAY(161) , ST_array) 
        EQUIVALENCE (WHICH_ARRAY(162) , ST1_array) 
        EQUIVALENCE (WHICH_ARRAY(163) , STG_array) 
        EQUIVALENCE (WHICH_ARRAY(164) , STH_array) 
        EQUIVALENCE (WHICH_ARRAY(165) , STN0_array) 
        EQUIVALENCE (WHICH_ARRAY(166) , STN1_array) 
        EQUIVALENCE (WHICH_ARRAY(167) , STPB_array) 
        EQUIVALENCE (WHICH_ARRAY(168) , STPE_array) 
        EQUIVALENCE (WHICH_ARRAY(169) , STR_array) 
        EQUIVALENCE (WHICH_ARRAY(170) , STRE_array) 
        EQUIVALENCE (WHICH_ARRAY(171) , STS_array) 
        EQUIVALENCE (WHICH_ARRAY(172) , STSN_array) 
        EQUIVALENCE (WHICH_ARRAY(173) , SYNC_array) 
        EQUIVALENCE (WHICH_ARRAY(174) , TACO_array) 
        EQUIVALENCE (WHICH_ARRAY(175) , TAGE_array) 
        EQUIVALENCE (WHICH_ARRAY(176) , TAGI_array) 
        EQUIVALENCE (WHICH_ARRAY(177) , TAGM_array) 
        EQUIVALENCE (WHICH_ARRAY(178) , TAGR_array) 
        EQUIVALENCE (WHICH_ARRAY(179) , TAGT_array) 
        EQUIVALENCE (WHICH_ARRAY(180) , TATL_array) 
        EQUIVALENCE (WHICH_ARRAY(181) , TATR_array) 
        EQUIVALENCE (WHICH_ARRAY(182) , TBER_array) 
        EQUIVALENCE (WHICH_ARRAY(183) , TBID_array) 
        EQUIVALENCE (WHICH_ARRAY(184) , TBLA_array) 
        EQUIVALENCE (WHICH_ARRAY(185) , TBTR_array) 
        EQUIVALENCE (WHICH_ARRAY(186) , TCSB_array) 
        EQUIVALENCE (WHICH_ARRAY(187) , TCT_array) 
        EQUIVALENCE (WHICH_ARRAY(188) , TDPL_array) 
        EQUIVALENCE (WHICH_ARRAY(189) , TESC_array) 
        EQUIVALENCE (WHICH_ARRAY(190) , TGBI_array) 
        EQUIVALENCE (WHICH_ARRAY(191) , TGEO_array) 
        EQUIVALENCE (WHICH_ARRAY(192) , TGPB_array) 
        EQUIVALENCE (WHICH_ARRAY(193) , TGS_array) 
        EQUIVALENCE (WHICH_ARRAY(194) , TGTL_array) 
        EQUIVALENCE (WHICH_ARRAY(195) , TGTR_array) 
        EQUIVALENCE (WHICH_ARRAY(196) , TLV1_array) 
        EQUIVALENCE (WHICH_ARRAY(197) , TPC_array) 
        EQUIVALENCE (WHICH_ARRAY(198) , TPCH_array) 
        EQUIVALENCE (WHICH_ARRAY(199) , TPE0_array) 
        EQUIVALENCE (WHICH_ARRAY(200) , TPE1_array) 
        EQUIVALENCE (WHICH_ARRAY(201) , TRCF_array) 
        EQUIVALENCE (WHICH_ARRAY(202) , TRGS_array) 
        EQUIVALENCE (WHICH_ARRAY(203) , TRKS_array) 
        EQUIVALENCE (WHICH_ARRAY(204) , TRL1_array) 
        EQUIVALENCE (WHICH_ARRAY(205) , TRPB_array) 
        EQUIVALENCE (WHICH_ARRAY(206) , TRUE_array) 
        EQUIVALENCE (WHICH_ARRAY(207) , TSPR_array) 
        EQUIVALENCE (WHICH_ARRAY(208) , TSRG_array) 
        EQUIVALENCE (WHICH_ARRAY(209) , UNUS_array) 
        EQUIVALENCE (WHICH_ARRAY(210) , VERT_array) 

C  Define the DDL bank names 
         data  DDL_BANK_NAMES(1)/'BEAM'/ 
         data  DDL_BANK_NAMES(2)/'BMPR'/ 
         data  DDL_BANK_NAMES(3)/'BREP'/ 
         data  DDL_BANK_NAMES(4)/'CALB'/ 
         data  DDL_BANK_NAMES(5)/'CALL'/ 
         data  DDL_BANK_NAMES(6)/'CC  '/ 
         data  DDL_BANK_NAMES(7)/'CC01'/ 
         data  DDL_BANK_NAMES(8)/'CC1 '/ 
         data  DDL_BANK_NAMES(9)/'CCDI'/ 
         data  DDL_BANK_NAMES(10)/'CCH '/ 
         data  DDL_BANK_NAMES(11)/'CCMT'/ 
         data  DDL_BANK_NAMES(12)/'CCPB'/ 
         data  DDL_BANK_NAMES(13)/'CCPE'/ 
         data  DDL_BANK_NAMES(14)/'CCRC'/ 
         data  DDL_BANK_NAMES(15)/'CCS '/ 
         data  DDL_BANK_NAMES(16)/'CCT '/ 
         data  DDL_BANK_NAMES(17)/'CHI2'/ 
         data  DDL_BANK_NAMES(18)/'CL01'/ 
         data  DDL_BANK_NAMES(19)/'CLST'/ 
         data  DDL_BANK_NAMES(20)/'CPED'/ 
         data  DDL_BANK_NAMES(21)/'CSQL'/ 
         data  DDL_BANK_NAMES(22)/'DC0 '/ 
         data  DDL_BANK_NAMES(23)/'DC1 '/ 
         data  DDL_BANK_NAMES(24)/'DCDW'/ 
         data  DDL_BANK_NAMES(25)/'DCGM'/ 
         data  DDL_BANK_NAMES(26)/'DCGW'/ 
         data  DDL_BANK_NAMES(27)/'DCH '/ 
         data  DDL_BANK_NAMES(28)/'DCMN'/ 
         data  DDL_BANK_NAMES(29)/'DCPB'/ 
         data  DDL_BANK_NAMES(30)/'DCV1'/ 
         data  DDL_BANK_NAMES(31)/'DCV2'/ 
         data  DDL_BANK_NAMES(32)/'DCV3'/ 
         data  DDL_BANK_NAMES(33)/'DDLY'/ 
         data  DDL_BANK_NAMES(34)/'DGEO'/ 
         data  DDL_BANK_NAMES(35)/'DHCL'/ 
         data  DDL_BANK_NAMES(36)/'DITM'/ 
         data  DDL_BANK_NAMES(37)/'DOCA'/ 
         data  DDL_BANK_NAMES(38)/'DPCP'/ 
         data  DDL_BANK_NAMES(39)/'DPSP'/ 
         data  DDL_BANK_NAMES(40)/'DSPC'/ 
         data  DDL_BANK_NAMES(41)/'DSPS'/ 
         data  DDL_BANK_NAMES(42)/'DSTC'/ 
         data  DDL_BANK_NAMES(43)/'DTCP'/ 
         data  DDL_BANK_NAMES(44)/'DTRK'/ 
         data  DDL_BANK_NAMES(45)/'EC  '/ 
         data  DDL_BANK_NAMES(46)/'EC01'/ 
         data  DDL_BANK_NAMES(47)/'EC1 '/ 
         data  DDL_BANK_NAMES(48)/'EC1P'/ 
         data  DDL_BANK_NAMES(49)/'EC1R'/ 
         data  DDL_BANK_NAMES(50)/'ECCA'/ 
         data  DDL_BANK_NAMES(51)/'ECCL'/ 
         data  DDL_BANK_NAMES(52)/'ECCT'/ 
         data  DDL_BANK_NAMES(53)/'ECDI'/ 
         data  DDL_BANK_NAMES(54)/'ECG '/ 
         data  DDL_BANK_NAMES(55)/'ECH '/ 
         data  DDL_BANK_NAMES(56)/'ECHB'/ 
         data  DDL_BANK_NAMES(57)/'ECMT'/ 
         data  DDL_BANK_NAMES(58)/'ECP '/ 
         data  DDL_BANK_NAMES(59)/'ECP1'/ 
         data  DDL_BANK_NAMES(60)/'ECPB'/ 
         data  DDL_BANK_NAMES(61)/'ECPC'/ 
         data  DDL_BANK_NAMES(62)/'ECPE'/ 
         data  DDL_BANK_NAMES(63)/'ECPI'/ 
         data  DDL_BANK_NAMES(64)/'ECPO'/ 
         data  DDL_BANK_NAMES(65)/'ECRB'/ 
         data  DDL_BANK_NAMES(66)/'ECS '/ 
         data  DDL_BANK_NAMES(67)/'ECT '/ 
         data  DDL_BANK_NAMES(68)/'EID0'/ 
         data  DDL_BANK_NAMES(69)/'EPIC'/ 
         data  DDL_BANK_NAMES(70)/'EVNT'/ 
         data  DDL_BANK_NAMES(71)/'FBPM'/ 
         data  DDL_BANK_NAMES(72)/'G1SL'/ 
         data  DDL_BANK_NAMES(73)/'G2SL'/ 
         data  DDL_BANK_NAMES(74)/'G3SL'/ 
         data  DDL_BANK_NAMES(75)/'G4SL'/ 
         data  DDL_BANK_NAMES(76)/'GCPB'/ 
         data  DDL_BANK_NAMES(77)/'GGEO'/ 
         data  DDL_BANK_NAMES(78)/'GP_X'/ 
         data  DDL_BANK_NAMES(79)/'GP_Y'/ 
         data  DDL_BANK_NAMES(80)/'GPAR'/ 
         data  DDL_BANK_NAMES(81)/'GPID'/ 
         data  DDL_BANK_NAMES(82)/'HBER'/ 
         data  DDL_BANK_NAMES(83)/'HBID'/ 
         data  DDL_BANK_NAMES(84)/'HBLA'/ 
         data  DDL_BANK_NAMES(85)/'HBTB'/ 
         data  DDL_BANK_NAMES(86)/'HBTR'/ 
         data  DDL_BANK_NAMES(87)/'HCAL'/ 
         data  DDL_BANK_NAMES(88)/'HDPL'/ 
         data  DDL_BANK_NAMES(89)/'HEAD'/ 
         data  DDL_BANK_NAMES(90)/'HEVT'/ 
         data  DDL_BANK_NAMES(91)/'HLB '/ 
         data  DDL_BANK_NAMES(92)/'HLS '/ 
         data  DDL_BANK_NAMES(93)/'IC  '/ 
         data  DDL_BANK_NAMES(94)/'ICHB'/ 
         data  DDL_BANK_NAMES(95)/'ICPB'/ 
         data  DDL_BANK_NAMES(96)/'KFIT'/ 
         data  DDL_BANK_NAMES(97)/'L1PG'/ 
         data  DDL_BANK_NAMES(98)/'L2H '/ 
         data  DDL_BANK_NAMES(99)/'L2S '/ 
         data  DDL_BANK_NAMES(100)/'LASR'/ 
         data  DDL_BANK_NAMES(101)/'LCDI'/ 
         data  DDL_BANK_NAMES(102)/'LCPB'/ 
         data  DDL_BANK_NAMES(103)/'LOWQ'/ 
         data  DDL_BANK_NAMES(104)/'LSRT'/ 
         data  DDL_BANK_NAMES(105)/'MCEV'/ 
         data  DDL_BANK_NAMES(106)/'MCHD'/ 
         data  DDL_BANK_NAMES(107)/'MCTK'/ 
         data  DDL_BANK_NAMES(108)/'MCVX'/ 
         data  DDL_BANK_NAMES(109)/'MS1 '/ 
         data  DDL_BANK_NAMES(110)/'MTRK'/ 
         data  DDL_BANK_NAMES(111)/'MVRT'/ 
         data  DDL_BANK_NAMES(112)/'PART'/ 
         data  DDL_BANK_NAMES(113)/'PCO '/ 
         data  DDL_BANK_NAMES(114)/'PHTM'/ 
         data  DDL_BANK_NAMES(115)/'PID1'/ 
         data  DDL_BANK_NAMES(116)/'PID2'/ 
         data  DDL_BANK_NAMES(117)/'PID3'/ 
         data  DDL_BANK_NAMES(118)/'PID4'/ 
         data  DDL_BANK_NAMES(119)/'PID5'/ 
         data  DDL_BANK_NAMES(120)/'PID6'/ 
         data  DDL_BANK_NAMES(121)/'PIDT'/ 
         data  DDL_BANK_NAMES(122)/'PRTM'/ 
         data  DDL_BANK_NAMES(123)/'PSO '/ 
         data  DDL_BANK_NAMES(124)/'PTDB'/ 
         data  DDL_BANK_NAMES(125)/'RC26'/ 
         data  DDL_BANK_NAMES(126)/'RCST'/ 
         data  DDL_BANK_NAMES(127)/'REF '/ 
         data  DDL_BANK_NAMES(128)/'RF  '/ 
         data  DDL_BANK_NAMES(129)/'RFT '/ 
         data  DDL_BANK_NAMES(130)/'RGLK'/ 
         data  DDL_BANK_NAMES(131)/'RNLG'/ 
         data  DDL_BANK_NAMES(132)/'RNPE'/ 
         data  DDL_BANK_NAMES(133)/'RTSL'/ 
         data  DDL_BANK_NAMES(134)/'RUNC'/ 
         data  DDL_BANK_NAMES(135)/'S1ST'/ 
         data  DDL_BANK_NAMES(136)/'SC  '/ 
         data  DDL_BANK_NAMES(137)/'SC1 '/ 
         data  DDL_BANK_NAMES(138)/'SCC '/ 
         data  DDL_BANK_NAMES(139)/'SCDI'/ 
         data  DDL_BANK_NAMES(140)/'SCG '/ 
         data  DDL_BANK_NAMES(141)/'SCGD'/ 
         data  DDL_BANK_NAMES(142)/'SCH '/ 
         data  DDL_BANK_NAMES(143)/'SCMD'/ 
         data  DDL_BANK_NAMES(144)/'SCMT'/ 
         data  DDL_BANK_NAMES(145)/'SCMW'/ 
         data  DDL_BANK_NAMES(146)/'SCP '/ 
         data  DDL_BANK_NAMES(147)/'SCPB'/ 
         data  DDL_BANK_NAMES(148)/'SCPE'/ 
         data  DDL_BANK_NAMES(149)/'SCPS'/ 
         data  DDL_BANK_NAMES(150)/'SCR '/ 
         data  DDL_BANK_NAMES(151)/'SCRC'/ 
         data  DDL_BANK_NAMES(152)/'SCS '/ 
         data  DDL_BANK_NAMES(153)/'SCT '/ 
         data  DDL_BANK_NAMES(154)/'SGMP'/ 
         data  DDL_BANK_NAMES(155)/'SH  '/ 
         data  DDL_BANK_NAMES(156)/'SHHB'/ 
         data  DDL_BANK_NAMES(157)/'SHPB'/ 
         data  DDL_BANK_NAMES(158)/'SHT '/ 
         data  DDL_BANK_NAMES(159)/'SPAR'/ 
         data  DDL_BANK_NAMES(160)/'SPIN'/ 
         data  DDL_BANK_NAMES(161)/'ST  '/ 
         data  DDL_BANK_NAMES(162)/'ST1 '/ 
         data  DDL_BANK_NAMES(163)/'STG '/ 
         data  DDL_BANK_NAMES(164)/'STH '/ 
         data  DDL_BANK_NAMES(165)/'STN0'/ 
         data  DDL_BANK_NAMES(166)/'STN1'/ 
         data  DDL_BANK_NAMES(167)/'STPB'/ 
         data  DDL_BANK_NAMES(168)/'STPE'/ 
         data  DDL_BANK_NAMES(169)/'STR '/ 
         data  DDL_BANK_NAMES(170)/'STRE'/ 
         data  DDL_BANK_NAMES(171)/'STS '/ 
         data  DDL_BANK_NAMES(172)/'STSN'/ 
         data  DDL_BANK_NAMES(173)/'SYNC'/ 
         data  DDL_BANK_NAMES(174)/'TACO'/ 
         data  DDL_BANK_NAMES(175)/'TAGE'/ 
         data  DDL_BANK_NAMES(176)/'TAGI'/ 
         data  DDL_BANK_NAMES(177)/'TAGM'/ 
         data  DDL_BANK_NAMES(178)/'TAGR'/ 
         data  DDL_BANK_NAMES(179)/'TAGT'/ 
         data  DDL_BANK_NAMES(180)/'TATL'/ 
         data  DDL_BANK_NAMES(181)/'TATR'/ 
         data  DDL_BANK_NAMES(182)/'TBER'/ 
         data  DDL_BANK_NAMES(183)/'TBID'/ 
         data  DDL_BANK_NAMES(184)/'TBLA'/ 
         data  DDL_BANK_NAMES(185)/'TBTR'/ 
         data  DDL_BANK_NAMES(186)/'TCSB'/ 
         data  DDL_BANK_NAMES(187)/'TCT '/ 
         data  DDL_BANK_NAMES(188)/'TDPL'/ 
         data  DDL_BANK_NAMES(189)/'TESC'/ 
         data  DDL_BANK_NAMES(190)/'TGBI'/ 
         data  DDL_BANK_NAMES(191)/'TGEO'/ 
         data  DDL_BANK_NAMES(192)/'TGPB'/ 
         data  DDL_BANK_NAMES(193)/'TGS '/ 
         data  DDL_BANK_NAMES(194)/'TGTL'/ 
         data  DDL_BANK_NAMES(195)/'TGTR'/ 
         data  DDL_BANK_NAMES(196)/'TLV1'/ 
         data  DDL_BANK_NAMES(197)/'TPC '/ 
         data  DDL_BANK_NAMES(198)/'TPCH'/ 
         data  DDL_BANK_NAMES(199)/'TPE0'/ 
         data  DDL_BANK_NAMES(200)/'TPE1'/ 
         data  DDL_BANK_NAMES(201)/'TRCF'/ 
         data  DDL_BANK_NAMES(202)/'TRGS'/ 
         data  DDL_BANK_NAMES(203)/'TRKS'/ 
         data  DDL_BANK_NAMES(204)/'TRL1'/ 
         data  DDL_BANK_NAMES(205)/'TRPB'/ 
         data  DDL_BANK_NAMES(206)/'TRUE'/ 
         data  DDL_BANK_NAMES(207)/'TSPR'/ 
         data  DDL_BANK_NAMES(208)/'TSRG'/ 
         data  DDL_BANK_NAMES(209)/'UNUS'/ 
         data  DDL_BANK_NAMES(210)/'VERT'/ 
