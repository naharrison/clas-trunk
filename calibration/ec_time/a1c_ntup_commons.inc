*********************************************************
*                                                       *
* This file was generated by HUWFUN.                    *
*                                                       *
*********************************************************
*
*     Ntuple Id:      10   
*     Ntuple Title:   CLAS
*     Creation:       25/04/99 17.30.46
*
*********************************************************
*
      LOGICAL         CHAIN
      CHARACTER*128   CFILE
      INTEGER         IDNEVT,NCHEVT,ICHEVT
      REAL            OBS(13)
*
      COMMON /PAWIDN/ IDNEVT,OBS
      COMMON /PAWCHN/ CHAIN, NCHEVT, ICHEVT
      COMMON /PAWCHC/ CFILE
*
*--   Ntuple Variable Declarations
*
      REAL q_l,rf_time1,rf_time2,p(20),b(20),cx(20),cy(20),cz(20),vx(20)
     + ,vy(20),vz(20),etot(20),ec_ei(20),ec_eo(20),ec_t(20),ec_r(20)
     + ,ech_x(20),ech_y(20),ech_z(20),edep(20),sc_t(20),sc_r(20)
     + ,cc_t(20),cc_r(20),dc_xsc(20),dc_ysc(20),dc_zsc(20),dc_cxsc(20)
     + ,dc_cysc(20),dc_czsc(20),dc_xec(20),dc_yec(20),dc_zec(20)
      INTEGER npart,evntid,gpart,id(20),dc(20),cc(20),sc(20),ec(20)
     + ,q(20),ec_part,ec_sect(20),ec_whol(20),sc_part,sc_sect(20)
     + ,sc_pd(20),cc_part,cc_sect(20),cc_segm(20),nphe(20),dc_part
     + ,dc_sect(20),dc_stat(20),ecpc_nhit,ecpc_hit(256),ecpc_id(256)
     + ,ecpc_tdc(256),ecpc_adc(256)
*
      COMMON /PAWCR4/ npart,evntid,q_l,rf_time1,rf_time2,gpart,id,dc,cc
     + ,sc,ec,p,q,b,cx,cy,cz,vx,vy,vz,ec_part,ec_sect,ec_whol,etot,ec_ei
     + ,ec_eo,ec_t,ec_r,ech_x,ech_y,ech_z,sc_part,sc_sect,sc_pd,edep
     + ,sc_t,sc_r,cc_part,cc_sect,cc_segm,nphe,cc_t,cc_r,dc_part,dc_sect
     + ,dc_stat,dc_xsc,dc_ysc,dc_zsc,dc_cxsc,dc_cysc,dc_czsc,dc_xec
     + ,dc_yec,dc_zec,ecpc_nhit,ecpc_hit,ecpc_id,ecpc_tdc,ecpc_adc
