*CMZ :  1.00/00 16/12/94  17.00.00  by  Pavel Binko
*-- Author :    Volker Blobel   16/12/94
      SUBROUTINE LASELE
*
************************************************************************
*
*     SELECT statement
*
************************************************************************
*
*KEEP,CTEXTIR.
*     one statement up to 5280 = 66 * 80 characters
      PARAMETER (LSTMT=5280)
      CHARACTER STMT*(LSTMT),ERRMES*72,NORMES*72
      PARAMETER (NDIMIT=640)
      REAL RTX(4,NDIMIT)
      COMMON/CTXTIR/NST,MST,KST,INU,NTX,ITX(4,NDIMIT)
      COMMON/CTXTST/STMT,ERRMES,NORMES
      EQUIVALENCE (ITX(1,1),RTX(1,1))
      SAVE/CTXTIR/,/CTXTST/
*KEEP,FCOMMON.
#ifndef Linux
*     IEEE format
      PARAMETER (LOCAL=1)
#else /* Linux */
*     DEC format (little-endian IEEE)
      PARAMETER (LOCAL=4)
#endif /* Linux */
*     Number of units
      PARAMETER (NUNITS=30)
*     The first possible free logical unit number
      PARAMETER (NFREEU=11)
*     Length of the integer vector IOPEN (for open and close)
      PARAMETER (IOPMAX=30)
*     Length of the integer vector LUNPAR (for statistics and inquire)
      PARAMETER (ILPMAX=30)
*     Length of the integer vector LISTI (file attributes)
      PARAMETER (ILIMAX=5)
*     length of different unit-information
      PARAMETER (NOPEN=50,NLGEN=15,NLSTU=25,NLSTA=10,NLKEY=11,NLHDR=70)
*     offset of different unit-information
      PARAMETER (ISGEN=NOPEN)
      PARAMETER (IRSTU=NOPEN+NLGEN,
     +           IRSTA=NOPEN+NLGEN+NLSTU,
     +           IRKEY=NOPEN+NLGEN+NLSTU+NLSTA,
     +           IRHDR=NOPEN+NLGEN+NLSTU+NLSTA+NLKEY,
     +           IWSTU=NOPEN+NLGEN+NLSTU+NLSTA+NLKEY+NLHDR)
      PARAMETER (IWSTA=IWSTU+NLSTU,
     +           IWKEY=IWSTU+NLSTU+NLSTA,
     +           IWHDR=IWSTU+NLSTU+NLSTA+NLKEY,
     +           NLDIM=IWSTU+NLSTU+NLSTA+NLKEY+NLHDR)
      COMMON/FUCOM/LUNW,LUNR,LW,LR,INDW,INDR,LUND,IVL(NUNITS),
     +             LUNIT(99),LUNBK(NUNITS),INFU(NLDIM,NUNITS),
     +             INFMT(200),IFMT(200),NFMT,
     +             NAMEB1,NAMEB2,NFMTB,IFMTB(200),NFMTH,IFMTH(64)
*     NAMEB1=  first part of BOSname
*     NAMEB2= second part of BOSname
*     IFMTB(1) ... IFMTB(NFMTB) = integer format information
*     IFMTH(1) ... IFMTH(NFMTH) = hollerith format information
      CHARACTER  FILNAM*256,HOSNAM*127,DATNAM*16,GENNAM*256,VOLNAM*6
      COMMON/DBCHOM/FILNAM(NUNITS),HOSNAM(NUNITS),DATNAM(NUNITS)
     +,             GENNAM(NUNITS),VOLNAM(NUNITS)
*     name of the data file
      CHARACTER*256 DTFLNM(NUNITS),RLFLNM(NUNITS)
*     host name for the data file
      CHARACTER*127 DTFLHO(NUNITS),RLFLHO(NUNITS)
*     MeDia type for the DaTa FiLe
      CHARACTER*16  DTFLMD(NUNITS),RLFLMD(NUNITS)
*     CuRrent data NaMe in DaTa file (it's used by index files)
      INTEGER     DTCRNM(2,NUNITS)
*     CuRrent Run Number in DaTa file (it's used by index files)
      INTEGER     DTCRRN(NUNITS)
*     volume name of cartridge for the data file
      CHARACTER*127 DTFLVS(NUNITS)
*     key block in data file
      INTEGER DTFLKB(NUNITS)
*     key position in data file block
      INTEGER DTFLPS(NUNITS)
*     index type
      LOGICAL IDXNEW
      COMMON/DBCHC1/DTFLNM,DTFLHO,DTFLMD,DTFLVS
     +,             RLFLNM,RLFLHO,RLFLMD
      COMMON/DBCHC2/DTFLKB,DTFLPS,DTCRNM,DTCRRN
      COMMON/DBCHC3/IDXNEW
      SAVE/FUCOM/,/DBCHOM/,/DBCHC1/,/DBCHC2/,/DBCHC3/
*KEEP,FBUFFER.
*     buffer common
      PARAMETER (NBUF=100000)
      COMMON/FBUF/IBUF(NBUF)
      SAVE/FBUF/
*KEND.
*     indices in ITX
      PARAMETER( JSTA=1,JEND=2,JTYPE=3,JVAL=4 )
*     types in ITX
      PARAMETER( JSIGN=1,JSTRING=2,JWORD=3,JINT=4,JREAL=6 )
*
      CHARACTER  DANAME*16, CW*8
      INTEGER NUMS(1503),NCLASS(32)
      INTEGER ERECORD,ERECKEY,ENUMRA,ENUMRB,ERECNAME,EBLOCK
*
************************************************************************
*
*     Bank number 1000*LUN+20
*
*     collected information
*
*     1     report flag
*     2     not used
*     3     not used
*     4     mbytes for STOPMB
*     5     seconds for STOPSEC
*     6     1 - some BLOCK/NOTBLOCK selection exists
*     7     1 - some other selection exists
*     8     mode, 0=FSELECT, 1=SELECT, 2=RSELECT
*
*     All other SELECT items are in the banks
*     with nums 1000*LUN+21..199
*     Structure of each is: tag info tag info ...
*     Possible values for tag info are:
*
*     RECORD/NOTRECORD
*     tag   1/-1
*     info  count intervals
*                            interval is: 0 rnum
*                                         1 low
*                                         2 high
*                                         3 low high
*     RECKEY/NOTRECKEY
*     tag 2/-2
*     info  record-name record-number-A count intervals
*
*     RECNAME/NOTRECNAME
*     tag 3/-3
*     info count recnames
*
*     NUMRA/NOTNUMRA
*     tag 4/-4
*     info count intervals
*
*     NUMRB/NOTNUMRB
*     tag 5/-5
*     info count intervals
*
*     CLASS/NOTCLASS
*     tag   6/-6
*     info  mask
*
*     BLOCK/NOTBLOCK
*     tag 7/-7
*     info count block-names
*
*     BEFOREDATE/AFTERDATE
*     tag 8/-8
*     info date
*
**********************************************************
*
      CALL TEXT32
      CALL STMTNU
      ERRMES = ' '
      IF(NTX.LT.2)THEN
         ERRMES='Data name missing'
         GOTO 90
      ENDIF
      IF(NTX.EQ.2)THEN
         ERRMES='Selection parameters missing'
         GOTO 90
      ENDIF
      IF(ITX(JTYPE,3).EQ.JSIGN.AND.ITX(JVAL,3).EQ.6) THEN
*        Equal sign after data name - error
         ERRMES='Data name missing'
         GOTO 90
      ENDIF
      DANAME=STMT(ITX(JSTA,2):ITX(JEND,2))
*     check DANAME existing?
      LUN=IFRST(DANAME,0)
      IF(LUN.LT.1.OR.LUN.GT.99) THEN
         ERRMES='File not opened'
         GOTO 90
      END IF
      LL=LUNIT(LUN)
      IF(LL.LE.0) THEN
         ERRMES='File not opened'
         GOTO 90
      END IF
 
*     Maximal allowed bank index
      IBNLIM = 1000*LUN+199
 
      IF( NTX.EQ.3 .AND. STMT(ITX(JSTA,3):ITX(JEND,3)).EQ.'RESET' ) THEN
         NORMES = 'SELECT information cleared for '//DANAME
         DO 714 I=1000*LUN+20,1000*LUN+199
714      IND=INDXA(IBUF,I,-1)
         GOTO 100
      ENDIF
      DO 715 I=3,NTX
         IF(ITX(JTYPE,I).EQ.JWORD.AND.
     +      (I.EQ.NTX .OR.
     +       ITX(JTYPE,I+1).NE.JSIGN.OR.ITX(JVAL,I+1).NE.6) )
     +      ITX(JTYPE,I) = JSTRING
715   CONTINUE
*
*     Last used bank index
      IBNKUS = 1000*LUN+20
      IND = INDXB(IBUF,IBNKUS)
      IF(IND.EQ.0) GOTO 712
      IF(IBUF(IND+8).NE.1) THEN
*        Selection was RSELECT or FSELECT, clear it
         DO 7141 I=1000*LUN+20,1000*LUN+199
7141     IND=INDXA(IBUF,I,-1)
         GOTO 712
      ENDIF
      DO 711 I=1,1000
         IND = INDXC(IBUF,IND)
         IF(IND.EQ.0) GOTO 712
         IDENT = IBUF(IND-2)
         IF(IDENT.GT.IBNLIM) GOTO 712
         IF(IDENT.LE.IBNKUS) CALL LOGERROR('Error in LASELE 1')
         IBNKUS = IDENT
 711  CONTINUE
 712  CONTINUE
      IF(IBNKUS.EQ.IBNLIM) THEN
         ERRMES='Too many SELECT statements'
         GOTO 90
      END IF
 
*     check the correctness and calculate space
      ERECORD= 0
      ERECKEY= 0
      ENUMRA= 0
      ENUMRB= 0
      ERECNAME= 0
      EBLOCK= 0
      ISIZE = 0
*     starting with I=3 (I=1,2 is SELECT daname)
      I=3
10    CONTINUE
      IF( ITX(JTYPE,I).NE.JWORD ) THEN
         ERRMES='Keyword or equal sign missing'
         GOTO 90
      END IF
      IF( I+1.EQ.NTX ) THEN
         ERRMES='No information after equal sign'
         GOTO 90
      END IF
      KSTA = ITX(JSTA,I)
      KEND = ITX(JEND, I)
      IF( STMT(KSTA:KEND).EQ.'RECORD' .OR.
     +    STMT(KSTA:KEND).EQ.'NOTRECORD' ) THEN
         IF( ERECORD.NE.0 ) THEN
            ERRMES = 'Invalid set of keywords'
            GOTO 90
         ENDIF
         I = I+2
         CALL STRNUM(I,NUMS,NNU)
         IF(NNU.EQ.0.OR.NNU.GT.1500) GOTO 90
         ERECORD = NNU-3
         ISIZE = ISIZE + 2 + ERECORD
      ELSE IF(
     +    STMT(KSTA:KEND).EQ.'NUMRA' .OR.
     +    STMT(KSTA:KEND).EQ.'NOTNUMRA' ) THEN
         IF( ENUMRA+ERECKEY.NE.0 ) THEN
            ERRMES = 'Invalid set of keywords'
            GOTO 90
         ENDIF
         I = I+2
         CALL STRNUM(I,NUMS,NNU)
         IF(NNU.EQ.0.OR.NNU.GT.1500) GOTO 90
         ENUMRA = NNU-3
         ISIZE = ISIZE + 2 + ENUMRA
      ELSE IF(
     +    STMT(KSTA:KEND).EQ.'NUMRB' .OR.
     +    STMT(KSTA:KEND).EQ.'NOTNUMRB' ) THEN
         IF( ENUMRB+ERECKEY.NE.0 ) THEN
            ERRMES = 'Invalid set of keywords'
            GOTO 90
         ENDIF
         I = I+2
         CALL STRNUM(I,NUMS,NNU)
         IF(NNU.EQ.0.OR.NNU.GT.1500) GOTO 90
         ENUMRB = NNU-3
         ISIZE = ISIZE + 2 + ENUMRB
      ELSE IF( STMT(KSTA:KEND).EQ.'RECKEY' .OR.
     +    STMT(KSTA:KEND).EQ.'NOTRECKEY' ) THEN
         IF( ENUMRA+ENUMRB+ERECNAME+ERECKEY.NE.0 ) THEN
            ERRMES = 'Invalid set of keywords'
            GOTO 90
         ENDIF
         I=I+2
*        get record name
         IF(ITX(JTYPE,I).NE.JSTRING) GOTO 90
         I=I+1
         IF( I.LE.NTX .AND. ITX(JTYPE,I).EQ.JSIGN .AND.
     +       STMT(KSTA:KEND).EQ.',' ) I = I+1
         IF( I.GT.NTX ) THEN
            ERRMES = 'Missing parameters after RECKEY'
            GOTO 90
         ENDIF
         IF(ITX(JTYPE,I).NE.JINT) GOTO 90
         I=I+1
         IF( I.LE.NTX .AND. ITX(JTYPE,I).EQ.JSIGN .AND.
     +       STMT(KSTA:KEND).EQ.',' ) I = I+1
         IF( I.GT.NTX ) THEN
            ERRMES = 'Missing parameters after RECKEY'
            GOTO 90
         ENDIF
         CALL STRNUM(I,NUMS,NNU)
         IF(NNU.EQ.0.OR.NNU.GT.1500) GOTO 90
         ERECKEY = NNU-3
         ISIZE = ISIZE + 5 + ERECKEY
      ELSE IF( STMT(KSTA:KEND).EQ.'RECNAME' .OR.
     +    STMT(KSTA:KEND).EQ.'NOTRECNAME' ) THEN
         IF( ERECNAME+ERECKEY.NE.0 ) THEN
            ERRMES = 'Invalid set of keywords'
            GOTO 90
         ENDIF
         I=I+2
721      CONTINUE
         IF( ITX(JTYPE,I).EQ.JSTRING ) THEN
            ERECNAME = ERECNAME+2
            I = I+1
            GOTO 721
         ELSE IF( STMT(ITX(JSTA,I):ITX(JEND,I)).EQ.',' ) THEN
            I = I+1
            GOTO 721
         ENDIF
         I = I-1
         ISIZE = ISIZE + 2 + ERECNAME
      ELSE IF(
     +    STMT(KSTA:KEND).EQ.'BLOCK' .OR.
     +    STMT(KSTA:KEND).EQ.'NOTBLOCK' ) THEN
         IF( EBLOCK.NE.0 ) THEN
            ERRMES = 'Invalid set of keywords'
            GOTO 90
         ENDIF
         I=I+2
722      CONTINUE
         IF( ITX(JTYPE,I).EQ.JSTRING ) THEN
            EBLOCK = EBLOCK+2
            I = I+1
            GOTO 722
         ELSE IF( STMT(ITX(JSTA,I):ITX(JEND,I)).EQ.',' ) THEN
            I = I+1
            GOTO 722
         ENDIF
         I = I-1
         ISIZE = ISIZE + 2 + EBLOCK
      ELSE IF( STMT(KSTA:KEND).EQ.'CLASS' .OR.
     +    STMT(KSTA:KEND).EQ.'NOTCLASS' ) THEN
         I = I+2
         CALL STRNUM(I,NUMS,NNU)
         IF(NNU.EQ.0.OR.NNU.GT.1500) GOTO 90
         K = 3
728      IF(K.GE.NNU) GOTO 729
         IF(NUMS(K+1).NE.3) THEN
            IF(NUMS(K+2).LT.1.OR.NUMS(K+2).GT.30) GOTO 90
         ELSE
*           interval
            IF(NUMS(K+2).GT.NUMS(K+3)) GOTO 90
            IF(NUMS(K+2).LT.1) GOTO 90
            IF(NUMS(K+3).GT.30) GOTO 90
            K = K+1
         END IF
         K = K+2
         GOTO 728
729      CONTINUE
         ISIZE = ISIZE + 2
      ELSE IF( STMT(KSTA:KEND).EQ.'BEFOREDATE' .OR.
     +    STMT(KSTA:KEND).EQ.'AFTERDATE' ) THEN
         IF( ITX(JTYPE,I+2).NE.JINT ) GOTO 90
         I = I+2
         ISIZE = ISIZE+2
      ELSE IF( STMT(KSTA:KEND).EQ.'STOPMB' .OR.
     +    STMT(KSTA:KEND).EQ.'STOPSEC' ) THEN
         IF( ITX(JTYPE,I+2).NE.JINT .AND.
     +       ITX(JTYPE,I+2).NE. JREAL ) GOTO 90
         I = I+2
      ELSE
         ERRMES = 'Unknown keyword '//STMT(KSTA:KEND)
         GOTO 90
      END IF
      I = I+1
      IF( I.LE.NTX ) GOTO 10
 
*     make sure that bank 20  is there
      IND20=INDXB(IBUF,1000*LUN+20)
      IF(IND20.EQ.0) THEN
*        create bank for single steering information
         IND20=INDXA(IBUF,1000*LUN+20,8)
         IF(IND20.EQ.0) GOTO 95
         DO 82 J=1,7
   82    IBUF(IND20+J) = 0
*        set the flag "SELECT"
         IBUF(IND20+8) = 1
      END IF
*     create select bank
      IF(ISIZE.GT.0) THEN
         INDZ=INDXA(IBUF,IBNKUS+1,ISIZE)
         IF(INDZ.EQ.0) GOTO 95
      END IF
 
*     store information
      ISIZE = 0
*     starting with I=3 (I=1,2 is SELECT daname)
      I=3
20    CONTINUE
      KSTA = ITX(JSTA,I)
      KEND = ITX(JEND,I)
      IF( STMT(KSTA:KEND).EQ.'RECORD' .OR.
     +    STMT(KSTA:KEND).EQ.'NOTRECORD' ) THEN
         IBUF(IND20+7) = 1
         IF( STMT(KSTA:KSTA).EQ.'N' ) THEN
            KW = -1
         ELSE
            KW = 1
         ENDIF
         I = I+2
         ISV1 = IBUF(INDZ+ISIZE)
         CALL STRNUM(I,IBUF(INDZ+ISIZE),NNU)
         IBUF(INDZ+ISIZE) = ISV1
         IBUF(INDZ+ISIZE+1) = KW
         IBUF(INDZ+ISIZE+2) = ERECORD
         ISIZE = ISIZE + 2 + ERECORD
      ELSE IF(
     +    STMT(KSTA:KEND).EQ.'NUMRA' .OR.
     +    STMT(KSTA:KEND).EQ.'NOTNUMRA' ) THEN
         IBUF(IND20+7) = 1
         IF( STMT(KSTA:KSTA+1).EQ.'NO' ) THEN
            KW = -4
         ELSE
            KW = 4
         ENDIF
         I = I+2
         ISV1 = IBUF(INDZ+ISIZE)
         CALL STRNUM(I,IBUF(INDZ+ISIZE),NNU)
         IBUF(INDZ+ISIZE) = ISV1
         IBUF(INDZ+ISIZE+1) = KW
         IBUF(INDZ+ISIZE+2) = ENUMRA
         ISIZE = ISIZE + 2 + ENUMRA
      ELSE IF(
     +    STMT(KSTA:KEND).EQ.'NUMRB' .OR.
     +    STMT(KSTA:KEND).EQ.'NOTNUMRB' ) THEN
         IBUF(IND20+7) = 1
         IF( STMT(KSTA:KSTA+1).EQ.'NO' ) THEN
            KW = -5
         ELSE
            KW = 5
         ENDIF
         I = I+2
         ISV1 = IBUF(INDZ+ISIZE)
         CALL STRNUM(I,IBUF(INDZ+ISIZE),NNU)
         IBUF(INDZ+ISIZE) = ISV1
         IBUF(INDZ+ISIZE+1) = KW
         IBUF(INDZ+ISIZE+2) = ENUMRB
         ISIZE = ISIZE + 2 + ENUMRB
      ELSE IF( STMT(KSTA:KEND).EQ.'RECKEY' .OR.
     +    STMT(KSTA:KEND).EQ.'NOTRECKEY' ) THEN
         IBUF(IND20+7) = 1
         IF( STMT(KSTA:KSTA).EQ.'N' ) THEN
            KW = -2
         ELSE
            KW = 2
         ENDIF
         I=I+2
*        get record name
         CW = STMT(ITX(JSTA,I):ITX(JEND,I))
         I=I+1
         NUMRA = ITX(JVAL,I)
         I=I+1
         CALL STRNUM(I,IBUF(INDZ+ISIZE+3),NNU)
         IBUF(INDZ+ISIZE+1) = KW
         CALL TXTOHL(CW,IBUF(INDZ+ISIZE+2),NBLA)
         IBUF(INDZ+ISIZE+4) = NUMRA
         IBUF(INDZ+ISIZE+5) = ERECKEY
         ISIZE = ISIZE + 5 + ERECKEY
      ELSE IF( STMT(KSTA:KEND).EQ.'RECNAME' .OR.
     +    STMT(KSTA:KEND).EQ.'NOTRECNAME' ) THEN
         IBUF(IND20+7) = 1
         IF( STMT(KSTA:KSTA).EQ.'N' ) THEN
            KW = -3
         ELSE
            KW = 3
         ENDIF
         I=I+2
         IBUF(INDZ+ISIZE+1) = KW
         IBUF(INDZ+ISIZE+2) = ERECNAME
         ISIZE = ISIZE+2
821      CONTINUE
         IF( ITX(JTYPE,I).EQ.JSTRING ) THEN
            CW = STMT(ITX(JSTA,I):ITX(JEND,I))
            CALL TXTOHL(CW,IBUF(INDZ+ISIZE+1),NBLA)
            I = I+1
            ISIZE = ISIZE+2
            GOTO 821
         ELSE IF( STMT(ITX(JSTA,I):ITX(JEND,I)).EQ.',' ) THEN
            I = I+1
            GOTO 821
         ENDIF
         I = I-1
      ELSE IF(
     +    STMT(KSTA:KEND).EQ.'BLOCK' .OR.
     +    STMT(KSTA:KEND).EQ.'NOTBLOCK' ) THEN
         IBUF(IND20+6) = 1
         IF( STMT(KSTA:KSTA).EQ.'N' ) THEN
            KW = -7
         ELSE
            KW = 7
         ENDIF
         I=I+2
         IBUF(INDZ+ISIZE+1) = KW
         IBUF(INDZ+ISIZE+2) = EBLOCK
         ISIZE = ISIZE+2
822      CONTINUE
         IF( ITX(JTYPE,I).EQ.JSTRING ) THEN
            CW = STMT(ITX(JSTA,I):ITX(JEND,I))
            CALL TXTOHL(CW,IBUF(INDZ+ISIZE+1),NBLA)
            I = I+1
            ISIZE = ISIZE+2
            GOTO 822
         ELSE IF( STMT(ITX(JSTA,I):ITX(JEND,I)).EQ.',' ) THEN
            I = I+1
            GOTO 822
         ENDIF
         I = I-1
      ELSE IF( STMT(KSTA:KEND).EQ.'CLASS' .OR.
     +    STMT(KSTA:KEND).EQ.'NOTCLASS' ) THEN
         IBUF(IND20+7) = 1
         IF( STMT(KSTA:KSTA).EQ.'N' ) THEN
            KW = -6
         ELSE
            KW = 6
         ENDIF
         I = I+2
         DO 34 J=1,32
  34     NCLASS(J)=0
         CALL STRNUM(I,NUMS,NNU)
         K = 3
828      IF(K.GE.NNU) GOTO 829
         IF(NUMS(K+1).EQ.0) THEN
            ILOW = NUMS(K+2)
            IHIGH= ILOW
         ELSE IF(NUMS(K+1).EQ.1) THEN
            ILOW = NUMS(K+2)
            IHIGH= 30
         ELSE IF(NUMS(K+1).EQ.1) THEN
            ILOW = 1
            IHIGH= NUMS(K+2)
         ELSE
*           interval
            ILOW = NUMS(K+2)
            IHIGH= NUMS(K+3)
            K = K+1
         END IF
         DO 39 L=ILOW,IHIGH
   39    NCLASS(L)=1
         K = K+2
         GOTO 828
829      CONTINUE
         CALL FCLPA(ICLW,NCLASS)
         IBUF(INDZ+ISIZE+1) = KW
         IBUF(INDZ+ISIZE+2) = ICLW
         ISIZE = ISIZE + 2
      ELSE IF( STMT(KSTA:KEND).EQ.'BEFOREDATE' .OR.
     +    STMT(KSTA:KEND).EQ.'AFTERDATE' ) THEN
         IBUF(IND20+7) = 1
         IF( STMT(KSTA:KSTA).EQ.'A' ) THEN
            KW = -8
         ELSE
            KW = 8
         ENDIF
         I = I+2
         IDATE=ITX(JVAL,I)
         ITIM =IDATE
         IF(IABS(IDATE).LT.10000000) THEN
*           translate noon of the day to UNIX time
            CALL TIMUYH(3,IDATE,120000,ITIM)
         END IF
         IBUF(INDZ+ISIZE+1) = KW
         IBUF(INDZ+ISIZE+2) = ITIM
         ISIZE = ISIZE+2
      ELSE IF( STMT(KSTA:KEND).EQ.'STOPMB' .OR.
     +    STMT(KSTA:KEND).EQ.'STOPSEC' ) THEN
         IF( STMT(KEND-1:KEND).EQ.'MB' ) THEN
            IX = 4
         ELSE
            IX = 5
         ENDIF
         I = I+2
         IF(ITX(JTYPE,I).EQ.JREAL) THEN
            IW=RTX(JVAL,I)
            IF(FLOAT(IW).LT.RTX(JVAL,I)) IW=IW+1
         ELSE
            IW=ITX(JVAL,I)
         END IF
         IBUF(IND20+IX)=IW
      END IF
      I = I+1
      IF( I.LE.NTX ) GOTO 20
*
      NORMES = 'SELECT statement stored for '//DANAME
      GOTO 100
*
*     ------------------------------------------------------------------
*     error - prepare error message in ERRMES
*     ------------------------------------------------------------------
*
   90 CONTINUE
      NB=LENB(ERRMES)
      NT=LEN(ERRMES)
      IF(NB.EQ.0) THEN
         ERRMES='Error at '
         NB=11
      ELSE IF(NB+11.LE.NT) THEN
         ERRMES(NB+1:NB+11)='; error at:'
         NB=NB+11
      ELSE
         GOTO 100
      END IF
      IF(NB.GE.NT) GOTO 100
      ERRMES(NB+1:)=STMT(1:ITX(JEND,NTX))
      GOTO 100
*
   95 ERRMES='No buffer space to store SELECT parameters'
      GOTO 100
*
  100 RETURN
      END
