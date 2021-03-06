	COMPLEX*16 FUNCTION BG(IREA,L,Q2,W,A,B,IH,J)
	IMPLICIT REAL*8 (A-Z)
	COMPLEX*16 AP,AM,BP,BM,CP,CM
cc 	COMPLEX*16 I/(0.d0,1.d0)/
	INTEGER NI,IH, IREAL, L	, J, I, IREA, IADD
	COMMON /KIN/Q,K
	COMMON /NI/NI
	COMMON
     *  /BP/  BP,BM
     *  /AP/  AP,AM
     *  /CP/  CP,CM
     *  /XMINUIT/ XMINUIT
	DIMENSION XMINUIT(500) 
	DIMENSION AP(0:10),AM(0:10),BP(0:10),BM(0:10),CP(0:10),CM(0:10)
	DATA MP/.938D0/,MN/.9395/,MPIP/.1395D0/,MPIN/.1349D0/

*	if(A.eq.0.d0)then
*	  BG=(0.d0,0.d0)
*	  return
*        endif
        
	IF(IREA.EQ.1)THEN
	  MPI=MPIN
	WTHR=MP+MPI
	ELSE
	  MPI=MPIP
	WTHR=MN+MPI
	END IF

	Q=DSQRT(((W**2-MP**2+MPI**2)/(2.*W))**2-MPI**2)

c
c	Define real smooth background multipolarity NI
c       background has correct threshold behaviour; assume scale factor 0.35 to impose unitarity constraint
c     
	BGS =  (Q**L)/((Q**2 + (0.35)**2)**(L/2.))
c
c       background amplitudes have monopole and dipole behaviour with same 
c       scale factors 

	BGS = BGS*(A/((1.+(Q**2)/.71)**1) + B/((1.+(Q**2)/.71)**2))  
        BG =  BGS* (1.D0, 0.D0)

c   use imagninary background for A1+, B1+

c        if(L.eq.1.and.J.eq.3.and.IH.eq.1) then
c	BGI =  (Q**L)/((Q**2 + (0.35)**2)**(L/2.))
c
c	BGI = BGI*(xminuit(91)/((1.+(Q**2)/1.5)**1) + 
c     *         xminuit(96)/((1.+(Q**2)/1.5)**2))  
c        BG = BG + BGI* (0.D0, 1.D0)
c        endif         
c        if(L.eq.1.and.J.eq.3.and.IH.eq.3) then
c	BGI =  (Q**L)/((Q**2 + (0.35)**2)**(L/2.))
c
c	BGI = BGI*(xminuit(92)/((1.+(Q**2)/1.5)**1) + 
c     *         xminuit(97)/((1.+(Q**2)/1.5)**2))  
c        BG = BG + BGI* (0.D0, 1.D0)
c        endif         
	RETURN
	END




	COMPLEX*16 FUNCTION RES(IREA,W,W0,Q2,GAMMA0,X,L,J,A,IISO)
	IMPLICIT REAL*8 (A - Z)
	COMPLEX*16 QETA,GAMMATOT,Q0ETA
	INTEGER IREA,L,J,IISO
	COMMON /KIN/Q,K
	COMPLEX*16 I/(0.D0,1.D0)/
	DATA MP/0.938D0/
	if(A.eq.0.d0)then
	  res=(0.d0,0.d0)
	  return
	end if

	IF((IREA.EQ.1).OR.(IREA.EQ.2))MPI=0.1349D0
	IF((IREA.EQ.3).OR.(IREA.EQ.4))MPI=0.1395D0

	K=(W**2-MP**2)/(2.*W)
	K0=(W0**2-MP**2)/(2.*W0)
	Q=DSQRT(((W**2-MP**2+MPI**2)/(2.*W))**2-MPI**2)
	Q0=DSQRT(((W0**2-MP**2+MPI**2)/(2.*W0))**2-MPI**2)
	GAMMA=GAMMA0*((Q/Q0)**(2.*L+1))*(((Q0**2+X**2)/(Q**2+X**2))**L)
	GAMMAGAM=GAMMA0*((K/K0)**(2.*J))*(((K0**2+X**2)/(K**2+X**2))**J)

	IF((L.EQ.0).AND.(DABS(W0-1.55D0).LE..05))THEN
	  XMETA=.5488D0
	   QET=((W**2-MP**2+XMETA**2)/(2.*W))**2-XMETA**2
	    IF(QET.GE.0.D0)THEN
	      QETA=DCMPLX(DSQRT(QET),0.D0)
	     ELSE
	       QETA=DCMPLX(0.D0,DSQRT(-QET))
	    END IF
	   Q0ETA=DSQRT(((W0**2-MP**2+XMETA**2)/(2.*W0))**2-XMETA**2)

cccc	  gamma=gamma*.4/.55

	  GAMMATOT=GAMMA0*(.55*(QETA/Q0ETA)+.4*(Q/Q0)+.05)
	ELSE
	GAMMATOT=GAMMA
	END IF
	RES=A*DSQRT(K0*Q0/(Q*K))*W0*DSQRT(GAMMA*GAMMAGAM)
     *  /(W0**2-W**2-I*W0*GAMMATOT)

c        if (w.gt.1.2.and.w.lt.1.3) then
c          print *, w,w0,l,j,iiso,a
c          print *,w,k,k0,q,q0,gamma,gammagam,gammatot,res
c        endif

C	Branch into channels 
	IF(IREA.EQ.1)THEN
	  IF(IISO.EQ.1)THEN
C	I=1/2 RESONANCE
	    RES=-RES/DSQRT(2.D0)
	  ELSE
C	I=3/2 RESONANCE
	    RES=RES*DSQRT(2.D0)
	  END IF
	END IF


	RETURN
	END

	COMPLEX*16 FUNCTION H1R(IREA,Q2,W,THETA)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 BP,BM, X
	COMMON /BP/BP,BM
	DIMENSION BP(0:10),BM(0:10)
	DATA PI/3.141592654D0/
	THE=THETA*PI/180.
	Y=DCOS(THE)
	H1R=(0.D0,0.D0)
C	DO L=1,5
C	  X=BP(L)-BM(L+1)
C	  X=X*(D2P(L,Y)-D2P(L+1,Y))
C	  H1R=X+H1R
C	END DO
	DO L=2,4
	H1R=H1R+(BP(L)-BP(L-1)-BM(L+1)+BM(L))*D2P(L,Y)
	END DO
	H1R=H1R*DSIN(THE)*DCOS(THE/2.D0)/DSQRT(2.D0)

	RETURN
	END






	COMPLEX*16 FUNCTION H2R(IREA,Q2,W,THETA)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 X,AP,AM
	COMMON /AP/  AP,AM
	DIMENSION AP(0:10),AM(0:10)
	DATA PI/3.141592654D0/
	THE=THETA*PI/180.
	Y=DCOS(THE)
	H2R=(0.D0,0.D0)
C	DO L=0,4
C	  X=AP(L)-AM(L+1)
C	  X=X*(DP(L,Y)-DP(L+1,Y))
C	  H2R=H2R+X
C	END DO

	DO L=1,4
	H2R=H2R+(AP(L)-AM(L+1)+AM(L)-AP(L-1))*DP(L,Y)
	END DO
	H2R=H2R*DCOS(THE/2.)*DSQRT(2.D0)
	RETURN
	END





	COMPLEX*16 FUNCTION H3R(IREA,Q2,W,THETA)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 BP,BM,X
	COMMON /BP/BP,BM
	DIMENSION BP(0:10),BM(0:10)
	DATA PI/3.141592654D0/
	THE=THETA*PI/180.
	Y=DCOS(THE)
	H3R=(0.D0,0.D0)
C	DO L=1,5
C	  X=BP(L)+BM(L+1)
C	  X=X*(D2P(L,Y)+D2P(L+1,Y))
C	  H3R=H3R+X
C	END DO

	DO L=2,4
	H3R=H3R+(BP(L)+BM(L+1)+BP(L-1)+BM(L))*D2P(L,Y)
	END DO
	H3R=H3R*DSIN(THE)*DSIN(THE/2.)/DSQRT(2.D0)
	RETURN
	END



	COMPLEX*16 FUNCTION H4R(IREA,Q2,W,THETA)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 X,AP,AM
	COMMON /AP/ AP,AM
	DIMENSION AP(0:10),AM(0:10)
	DATA PI/3.141592654D0/
	THE=THETA*PI/180.
	Y=DCOS(THE)
	H4R=(0.D0,0.D0)
C	DO L=0,5
C	  X=AP(L)+AM(L+1)
C	  X=X*(DP(L,Y)+DP(L+1,Y))
C	  H4R=H4R+X
C	END DO
	DO L=1,4
	H4R=H4R+(AP(L)+AM(L+1)+AM(L)+AP(L-1))*DP(L,Y)
	END DO
	H4R=H4R*DSIN(THE/2.)*DSQRT(2.D0)
	RETURN
	END




	COMPLEX*16 FUNCTION H5R(IREA,Q2,W,THETA)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 CP,CM,X
	COMMON /CP/ CP,CM
	DIMENSION CP(0:10),CM(0:10)
	DATA PI/3.141592654D0/
	THE=THETA*PI/180.
	Y=DCOS(THE)
	H5R=(0.D0,0.D0)
C	DO L=0,5
C	  X=CP(L)-CM(L+1)
C	  X=X*(DP(L,Y)-DP(L+1,Y))
C	  H5R=H5R+X
C	END DO
	DO L=1,4
	H5R=H5R+(CP(L)-CM(L+1)+CM(L)-CP(L-1))*DP(L,Y)
	END DO
	H5R=H5R*DCOS(THE/2.)*DSQRT(2.D0)
	RETURN
	END




	COMPLEX*16 FUNCTION H6R(IREA,Q2,W,THETA)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 X,CP,CM
	COMMON /CP/ CP,CM
	DIMENSION CP(0:10),CM(0:10)
	DATA PI/3.141592654D0/
	THE=THETA*PI/180.
	Y=DCOS(THE)
	H6R=(0.D0,0.D0)
C	DO L=0,5
C	  X=CP(L)+CM(L+1)
C	  X=X*(DP(L,Y)+DP(L+1,Y))
C	 H6R=H6R+X
C	END DO
	DO L=1,4
	H6R=H6R+(CP(L)+CM(L+1)+CM(L)+CP(L-1))*DP(L,Y)
	END DO
	H6R=H6R*DSIN(THE/2.)*DSQRT(2.D0)
	RETURN
	END



C	COMPUTE AMPLITUDES

	SUBROUTINE APRES(IREA,Q2,W)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 BG, RES,AP,AM, dum
	COMMON /AP/AP,AM
	COMMON /XMINUIT/XMINUIT
	DIMENSION XMINUIT (500)
	DIMENSION AP(0:10),AM(0:10)
c	DATA AP/11*(0.D0,0.D0)/
	IF(IREA.EQ.1)THEN
	X7=XMINUIT(28)
	X8=XMINUIT(30)
	X9=XMINUIT(32)
	XX7=XMINUIT(118)
	XX8=XMINUIT(120)
	XX9=XMINUIT(122)
	ELSE
	X7=XMINUIT(29)
	X8=XMINUIT(31)
	X9=XMINUIT(33)
	XX7=XMINUIT(119)
	XX8=XMINUIT(121)
	XX9=XMINUIT(123)
	END IF
C	S11(1550)
	AP(0)=RES(IREA,W,xminuit(66),Q2,.150D0,.35D0,0,1,xminuit(1),1)
C	S31(1620)
        AP(0)=AP(0)+
     +    RES(IREA,W,xminuit(68),Q2,.14D0,.35D0,0,1,xminuit(2),3)
C	S11(1650)
        AP(0)=AP(0)+
     +    RES(IREA,W,xminuit(67),Q2,.15D0,.35D0,0,1,xminuit(3),1)
C	P33(1232)
	AP(1)=RES(IREA,W,xminuit(72),Q2,xminuit(99),.185D0,1,1,
     1    xminuit(4),3)
C	F37(1950)
	AP(3)=RES(IREA,W,1.95D0,Q2,.34D0,.35D0,3,3,X6,3)

	AP(0) = AP(0) + BG(IREA,0,Q2,W,X7,XX7,1,1)
	AP(1) = AP(1) + BG(IREA,1,Q2,W,X8,XX8,1,3)
	AP(2) =         BG(IREA,2,Q2,W,X9,XX9,1,5)
        
c        print *, w
c        dum = res(irea,w,xminuit(72),q2,xminuit(99),.185D0,1,1,
c     1  xminuit(4),-3)
c        print *, bg(irea,1,q2,w,x8,xx8,1,3)
c        print *, ''
	RETURN
	END


	SUBROUTINE AMRES(IREA,Q2,W)
	IMPLICIT REAL*8(A-H,O-Z)
	COMPLEX*16 BG, RES,AM,AP
	COMMON /AP/AP,AM
	COMMON /XMINUIT/XMINUIT
	DIMENSION XMINUIT (500)
	DIMENSION AM(0:10),AP(0:10)
c	DATA AM/11*(0.D0,0.D0)/
	IF(IREA.EQ.1)THEN
	X7=XMINUIT(34)
	X8=XMINUIT(36)
	XX7=XMINUIT(124)
	XX8=XMINUIT(126)
	ELSE
	X7=XMINUIT(35)
	X8=XMINUIT(37)
	XX7=XMINUIT(125)
	XX8=XMINUIT(127)
	END IF
C	P11(1440)
	AM(1)=RES(IREA,W,xminuit(71),Q2,.30D0,.35D0,1,1,xminuit(7),1)
C	P11(1700)
	AM(1)=AM(1)+RES(IREA,W,1.7D0,Q2,.11D0,.35D0,1,1,xminuit(8),1)
C	P31(1910)
	AM(1)=AM(1)+RES(IREA,W,1.91D0,Q2,.225D0,.35D0,1,1,xminuit(9),3)
C	D13(1520)
	AM(2)=RES(IREA,W,xminuit(69),Q2,.125D0,.35D0,2,1,xminuit(10),1)
C	D33(1650)
      AM(2)=AM(2)+RES(IREA,W,xminuit(65),Q2,.25D0,.35D0,2,1,XMINUIT(5),3)
C	F15(1688)
	AM(3)=RES(IREA,W,xminuit(70),Q2,.125D0,.35D0,3,2,xminuit(11),1)
C	F35(1910)
	AM(3)=AM(3)+RES(IREA,W,1.91D0,Q2,.4D0,.35D0,3,2,xminuit(12),3)
	AM(1)=AM(1)+BG(IREA,1,Q2,W,X7,XX7,1,1)
	AM(2)=AM(2)+BG(IREA,2,Q2,W,X8,XX8,1,3)
	RETURN
	END


	SUBROUTINE BPRES(IREA,Q2,W)
	IMPLICIT REAL*8(A-H,O-Z)
	COMPLEX*16 RES,BG, BP,BM
	COMMON/BP/BP,BM,/XMINUIT/XMINUIT
	DIMENSION XMINUIT (500)
	DIMENSION BP(0:10),BM(0:10)
c	DATA BP/11*(0.D0,0.D0)/
	X3=XMINUIT(15)
	IF(IREA.EQ.1)THEN
	X4=XMINUIT(38)
	X5=XMINUIT(40)
	XX4=XMINUIT(128)
	XX5=XMINUIT(130)
	ELSE
	X4=XMINUIT(39)
	X5=XMINUIT(41)
	XX4=XMINUIT(129)
	XX5=XMINUIT(131)
	END IF
C	P33(1232)
	BP(1)=RES(IREA,W,xminuit(72),Q2,xminuit(99),.185D0,1,1,
     1  xminuit(13),3)
C	F37(1950)
	BP(3)=RES(IREA,W,1.950D0,Q2,.34D0,.350D0,3,3,xminuit(15),3)
	BP(1)=BP(1) + BG(IREA,1,Q2,W,X4,XX4,3,3)
	BP(2)= BG(IREA,2,Q2,W,X5,XX5,3,5)
	RETURN
	END


	SUBROUTINE BMRES(IREA,Q2,W)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 RES,BG, BM,BP
	COMMON /BP/BP,BM,/XMINUIT/XMINUIT
	DIMENSION XMINUIT (500)
	DIMENSION BM(0:10),BP(0:10)
c	DATA BM/11*(0.D0,0.D0)/
	IF(IREA.EQ.1)THEN
	  X4=XMINUIT(42)
	  XX4=XMINUIT(132)
	ELSE
	  X4=XMINUIT(43)
	  XX4=XMINUIT(133)
	END IF
C	D13(1525)
	BM(2)=RES(IREA,W,xminuit(69),Q2,.125D0,.350D0,2,1,xminuit(16),1)
C	D33(1650)
	BM(2)=BM(2)+RES(IREA,W,xminuit(65),Q2,.25D0,.35D0,2,1,XMINUIT(14),3)
C	F15(1680)
	BM(3)=RES(IREA,W,xminuit(70),Q2,.125D0,.350D0,3,2,xminuit(17),1)
C	F35(1910)
	BM(3)=BM(3)+RES(IREA,W,1.910D0,Q2,.4D0,.350D0,3,2,xminuit(18),3)
	BM(2)=BM(2)+BG(IREA,2,Q2,W,X4,XX4,3,3)
	RETURN
	END



	SUBROUTINE CPRES(IREA,Q2,W)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 RES, BG, CP(0:10),CM(0:10)
	COMMON /CP/CP,CM,/XMINUIT/XMINUIT
	DIMENSION XMINUIT (500)
c	DATA CP/11*(0.D0,0.D0)/
	IF(IREA.EQ.1)THEN
	  X6=XMINUIT(44)
	  X7=XMINUIT(46)
	  X8=XMINUIT(48)
	  XX6=XMINUIT(134)
	  XX7=XMINUIT(136)
	  XX8=XMINUIT(138)
	ELSE
	  X6=XMINUIT(45)
	  X7=XMINUIT(47)
	  X8=XMINUIT(49)
	  XX6=XMINUIT(135)
	  XX7=XMINUIT(137)
	  XX8=XMINUIT(139)
	END IF
C	S11(1535)
	CP(0)=RES(IREA,W,xminuit(66),Q2,.150D0,.35D0,0,1,xminuit(19),1)
C	S31(1620)
	CP(0)=CP(0)+RES(IREA,W,xminuit(68),Q2,.14D0,.35D0,0,1,xminuit(20),3)
C	S11(1650)
	CP(0)=CP(0)+RES(IREA,W,xminuit(67),Q2,.15D0,.35D0,0,1,xminuit(21),1)
C	P33(1232)
	CP(1)=RES(IREA,W,xminuit(72),Q2,xminuit(99),.185D0,1,1,
     1  xminuit(22),3)
C	F37(1950)
	CP(3)=RES(IREA,W,1.950D0,Q2,.34D0,.350D0,3,3,XMINUIT(63),3)
	CP(0)=CP(0)+BG(IREA,0,Q2,W,X6,XX6,0,1)
	CP(1)=CP(1)+BG(IREA,1,Q2,W,X7,XX7,0,3)
	CP(2)=BG(IREA,2,Q2,W,X8,XX8,0,5)
	RETURN
	END


	SUBROUTINE CMRES(IREA,Q2,W)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 RES, BG, CP(0:10),CM(0:10)
	COMMON /CP/CP,CM,/XMINUIT/XMINUIT
	DIMENSION XMINUIT (500)
c	DATA CM/11*(0.D0,0.D0)/
	IF(IREA.EQ.1)THEN
	  X5=XMINUIT(50)
	  X6=XMINUIT(52)
	  XX5=XMINUIT(140)
	  XX6=XMINUIT(142)
	ELSE
	  X5=XMINUIT(51)
	  X6=XMINUIT(53)
	  XX5=XMINUIT(141)
	  XX6=XMINUIT(143)
	END IF
C	P11(1440)
	CM(1)=RES(IREA,W,xminuit(71),Q2,.30D0,.35D0,1,1,xminuit(24),1)
C	P11(1700)
	CM(1)=CM(1)+RES(IREA,W,1.7D0,Q2,.09D0,.35D0,1,1,xminuit(25),1)
C	P31(1910)
	CM(1)=CM(1)+RES(IREA,W,1.91D0,Q2,.225D0,.35D0,1,1,xminuit(26),3)
C	D13(1520)
	CM(2)=RES(IREA,W,xminuit(69),Q2,.125D0,.35D0,2,1,xminuit(27),1)
C	D33(1650)
	CM(2)=CM(2)+RES(IREA,W,xminuit(65),Q2,.25D0,.35D0,2,1,XMINUIT(23),3)
C	F15(1680)
	CM(3)=RES(IREA,W,xminuit(70),Q2,.125D0,.350D0,3,2,XMINUIT(61),1)
C	F35(1910)
	CM(3)=CM(3)+RES(IREA,W,1.910D0,Q2,.4D0,.350D0,3,2,XMINUIT(62),3)
	CM(1)=CM(1)+BG(IREA,1,Q2,W,X5,XX5,0,1)
	CM(2)=CM(2)+BG(IREA,2,Q2,W,X6,XX6,0,3)
	RETURN
	END






	REAL*8 FUNCTION P(L,X)
	IMPLICIT REAL*8 (A-Z)
	INTEGER N,L
C
C          P
C       =====
C
C
C  P RECHNET DAS LEGENDREPOLYNOM VOM GRADE L AN DER STELLE X AUS.
C
	P0=1.D0
	IF(L.EQ.0)GOTO 3
	P1=X
	IF(L.EQ.1)GOTO 4
	DO 1 N=1,L-1
	P2=(2*N+1.D0)/(N+1)
	P2=P2*X*P1-P0*(N/(N+1.))
	P=P2
	P0=P1
1	P1=P2
 	RETURN
3	P=P0
	RETURN
4	P=P1
	RETURN
	END





	REAL*8 FUNCTION RL(L,Z)
	IMPLICIT REAL*8 (A-Z)
	INTEGER L
C    
C
C         RL
C        ====
C
	IF(L.EQ.0)GOTO1
	RL=QL(L-1,Z)-QL(L+1,Z)
	RL=RL/(2.*L+1)
	RETURN
1	RL=0.D0
	RETURN
	END





	REAL*8 FUNCTION DP(N,X)
	IMPLICIT REAL*8  (A-Z)
	INTEGER N,M
	DP0=0.D0
	DP1=1.D0
	IF(N.EQ.0)GOTO1
	IF(N.EQ.1)GOTO2
	IF(N.LE.4)THEN
	  IF(N.EQ.2)THEN
	    DP=3.D0*X
	    RETURN
	  END IF
	  IF(N.EQ.3)THEN
	    DP=0.5D0*(15.*X*X-3.)
	    RETURN
	  END IF
	  IF(N.EQ.4)THEN
	    DP=0.5D0*(35.*X*X*X-15.*X)
	    RETURN
	  END IF
	END IF
	DO10 M=2,N
	DP2=((2.*M-1)/M)*(P(M-1,X)+X*DP1)-((M-1.)/M)*DP0
	DP0=DP1
	DP1=DP2
10	CONTINUE
	DP=DP2
	RETURN
1	DP=DP0
	RETURN
2	DP=DP1
	RETURN
	END






	REAL*8 FUNCTION D2P(N,X)
	IMPLICIT REAL*8 (A-Z)
	INTEGER M,N
	D2P0=0.D0
	D2P1=0.D0
	IF(N.EQ.1)GOTO1
	IF(N.EQ.0)GOTO1
	IF(N.LE.4)THEN
	  IF(N.EQ.2)THEN
	    D2P=3.D0
	    RETURN
	  END IF
	  IF(N.EQ.3)THEN
	    D2P=15.*X
	    RETURN
	  END IF
	  IF(N.EQ.4)THEN
	    D2P=0.5D0*(105.*X*X-15.D0)
	    RETURN
	  END IF
	END IF
	DO10 M=2,N
	Y=((2.*M-1)/M)*(2.*DP(M-1,X)+X*D2P1)-((M-1.)/M)*D2P0
	D2P0=D2P1
10	D2P1=Y
	D2P=Y
	RETURN
1	D2P=0.D0
	RETURN
	END







	REAL*8 FUNCTION QL(L,X)
	REAL*8 X
	REAL*8 Q0,Q1,Q2,Y
	Y=X
	Q0=Y+1.D0
	Q1=Y-1.D0
	Q0=Q0/Q1
	Q0=.5D0*DLOG(Q0)
	Q1=X*Q0-1.D0
	IF(L.EQ.0)THEN
	  QL=Q0
	  RETURN
	END IF
	IF(L.EQ.1)THEN
	  QL=Q1
	  RETURN
	ELSE
	 DO J=2,L
	  Q2=(1./J)*((2.*J-1.)*X*Q1-(J-1.)*Q0)
	  Q0=Q1
	  Q1=Q2
	 END DO
	 QL=Q2
	 RETURN
	END IF
	END

C	Calculate the amplitudes
C
	SUBROUTINE APERES(Q2,W)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 RESE,APE(0:10),AME(0:10)
	COMMON /APE/APE,AME
	COMMON /XMINUIT/XMINUIT
	DIMENSION XMINUIT (500)
c	DATA APE/11*(0.D0,0.D0)/
	X1=XMINUIT(1)
	X3=XMINUIT(54)
C	S11(1550)
	APE(0)=RESE(W,1.534D0,Q2,.100d0,.35D0,0,1,-X1/SQRT(2./3.),1)

	APE(0)=APE(0)+BGE(0,Q2,W,X3)
	APE(1)=BGE(1,Q2,W,XMINUIT(56))
	RETURN
	END


	SUBROUTINE AMERES(Q2,W)
	IMPLICIT REAL*8(A-H,O-Z)
	COMPLEX*16 RESE,AME(0:10),APE(0:10)
	COMMON /APE/APE,AME
	COMMON /XMINUIT/XMINUIT
	DIMENSION XMINUIT (500)
c	DATA AME/11*(0.D0,0.D0)/
	X1=XMINUIT(8)
	X3=XMINUIT(25)
c
C	P11(1710) Check the factor sqrt(2./3.)
c
	AME(1)=RESE(W,1.710D0,Q2,.110d0,.35D0,0,1,-X1/SQRT(2./3.),1)
	AME(1)=AME(1)+BGE(1,Q2,W,XMINUIT(57))
	RETURN
	END


	SUBROUTINE BPERES(Q2,W)
	IMPLICIT REAL*8(A-H,O-Z)
	COMPLEX*16 BPE(0:10),BME(0:10)

	COMMON/BPE/BPE,BME,/XMINUIT/XMINUIT
	DIMENSION XMINUIT (500)
c	DATA BPE/11*(0.D0,0.D0)/
	BPE(1)=BGE(1,Q2,W,XMINUIT(58))
	RETURN
	END


	SUBROUTINE BMERES(Q2,W)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 BME(0:10),BPE(0:10)
	COMMON /BPE/BPE,BME,/XMINUIT/XMINUIT
	DIMENSION XMINUIT (500)
c	DATA BME/11*(0.D0,0.D0)/
	RETURN
	END



	SUBROUTINE CPERES(Q2,W)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 RESE,CPE(0:10),CME(0:10)
	COMMON /CPE/CPE,CME,/XMINUIT/XMINUIT
	DIMENSION XMINUIT (500)
c	DATA CPE/11*(0.D0,0.D0)/
	X1=XMINUIT(19)
	X3=XMINUIT(55)
	CPE(0)=RESE(W,1.534D0,Q2,XMINUIT(74),.35D0,0,1,-X1/SQRT(2./3.),1)
	CPE(0)=CPE(0)+BGE(0,Q2,W,X3)
	CPE(1)=BGE(1,Q2,W,XMINUIT(59))
	RETURN
	END


	SUBROUTINE CMERES(Q2,W)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 RESE,CPE(0:10),CME(0:10)
	COMMON /CPE/CPE,CME,/XMINUIT/XMINUIT
	DIMENSION XMINUIT (500)
c	DATA CME/11*(0.D0,0.D0)/
	X1=XMINUIT(25)
c
C	P11(1710) Check the factor sqrt(2./3.)
c
	CME(1)=RESE(W,1.710D0,Q2,.110d0,.35D0,0,1,-X1/SQRT(2./3.),1)
	CME(1)=CME(1)+BGE(1,Q2,W,XMINUIT(60))
	RETURN
	END

	REAL*8 FUNCTION BGE(L,Q2,W,A)
	IMPLICIT REAL*8 (A-Z)
	INTEGER L
	DATA MP/.938D0/,MPI/.5488D0/
	if(A.eq.0.d0)then
	  Bge=0.d0
	  return
	end if

	
	Q=DSQRT(((W**2-MP**2+MPI**2)/(2.*W))**2-MPI**2)
	BGE=A*(Q**L)/((Q**2+.35D0**2)**(L/2.))
	BGE=BGE/((1.+(Q**2)/.71))
	RETURN
	END




	COMPLEX*16 FUNCTION RESE(W,W0,Q2,GAMEMA0,X,L,J,A,IISO)
	IMPLICIT REAL*8 (A - Z)
	INTEGER L,J,IISO
	COMPLEX*16 I/(0.D0,1.D0)/
	DATA MP/0.938D0/
	if(A.eq.0.d0)then
	  rese=(0.d0,0.d0)
	  return
	end if

	MPI=.5488D0


	K=(W**2-MP**2)/(2.*W)
	K0=(W0**2-MP**2)/(2.*W0)
	Q=DSQRT(((W**2-MP**2+MPI**2)/(2.*W))**2-MPI**2)
	Q0=DSQRT(((W0**2-MP**2+MPI**2)/(2.*W0))**2-MPI**2)
	XMPI=.1395
	QMPI=DSQRT(((W**2-MP**2+XMPI**2)/(2.*W))**2-XMPI**2)
	Q0MPI=DSQRT(((W0**2-MP**2+XMPI**2)/(2.*W0))**2-XMPI**2)
	GAMEMA=GAMEMA0*.55*(Q/Q0)/.4
	GAMEMAGAME=GAMEMA0*((K/K0)**(2.*J))*(((K0**2+X**2)/(K**2+X**2))**J)
	GAMMATOT=GAMEMA0*(.55*DABS(Q/Q0)+.4*DABS(QMPI/Q0MPI)+.05)
	RESE=A*DSQRT(K0*Q0/(Q*K))*W0*DSQRT(GAMEMA*GAMEMAGAME)
     *  /(W0**2-W**2-I*W0*GAMMATOT)
	rese=rese*dsqrt(q0mpi/q0)
	RETURN
	END

	COMPLEX*16 FUNCTION H1RE(Q2,W,THETA)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 X,BPE,BME
	COMMON /BPE/BPE,BME
	DIMENSION BPE(0:10),BME(0:10)
	DATA PI/3.141592654D0/
	THE=THETA*PI/180.
	Y=DCOS(THE)
	H1RE=(0.D0,0.D0)
	DO L=1,5
	  X=BPE(L)-BME(L+1)
	  X=X*(D2P(L,Y)-D2P(L+1,Y))
	  H1RE=X+H1RE
	END DO
	DO L=2,4
	H1RE=H1RE+(BPE(L)-BPE(L-1)-BME(L+1)+BME(L))*D2P(L,Y)
	END DO
	H1RE=H1RE*DSIN(THE)*DCOS(THE/2.D0)/DSQRT(2.D0)
	RETURN
	END






	COMPLEX*16 FUNCTION H2RE(Q2,W,THETA)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 X,APE,AME
	COMMON /APE/  APE,AME
	DIMENSION APE(0:10),AME(0:10)
	DATA PI/3.141592654D0/
	THE=THETA*PI/180.
	Y=DCOS(THE)
	H2RE=(0.D0,0.D0)
	DO L=0,4
	  X=APE(L)-AME(L+1)
	  X=X*(DP(L,Y)-DP(L+1,Y))
	  H2RE=H2RE+X
	END DO

	DO L=1,4
	H2RE=H2RE+(APE(L)-AME(L+1)+AME(L)-APE(L-1))*DP(L,Y)
	END DO
	H2RE=H2RE*DCOS(THE/2.)*DSQRT(2.D0)
	RETURN
	END





	COMPLEX*16 FUNCTION H3RE(Q2,W,THETA)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 BPE,BME,X
	COMMON /BPE/BPE,BME
	DIMENSION BPE(0:10),BME(0:10)
	DATA PI/3.141592654D0/
	THE=THETA*PI/180.
	Y=DCOS(THE)
	H3RE=(0.D0,0.D0)
	DO L=1,5
	  X=BPE(L)+BME(L+1)
	  X=X*(D2P(L,Y)+D2P(L+1,Y))
	  H3RE=H3RE+X
	END DO

	DO L=2,4
	H3RE=H3RE+(BPE(L)+BME(L+1)+BPE(L-1)+BME(L))*D2P(L,Y)
	END DO
	H3RE=H3RE*DSIN(THE)*DSIN(THE/2.)/DSQRT(2.D0)
	RETURN
	END



	COMPLEX*16 FUNCTION H4RE(Q2,W,THETA)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 X,APE,AME
	COMMON /APE/ APE,AME
	DIMENSION APE(0:10),AME(0:10)
	DATA PI/3.141592654D0/
	THE=THETA*PI/180.
	Y=DCOS(THE)
	H4RE=(0.D0,0.D0)
	DO L=0,5
	  X=APE(L)+AME(L+1)
	  X=X*(DP(L,Y)+DP(L+1,Y))
	  H4RE=H4RE+X
	END DO
	DO L=1,4
	H4RE=H4RE+(APE(L)+AME(L+1)+AME(L)+APE(L-1))*DP(L,Y)
	END DO
	H4RE=H4RE*DSIN(THE/2.)*DSQRT(2.D0)
	RETURN
	END




	COMPLEX*16 FUNCTION H5RE(Q2,W,THETA)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 CPE,CME,X
	COMMON /CPE/ CPE,CME
	DIMENSION CPE(0:10),CME(0:10)
	DATA PI/3.141592654D0/
	THE=THETA*PI/180.
	Y=DCOS(THE)
	H5RE=(0.D0,0.D0)
	DO L=0,5
	  X=CPE(L)-CME(L+1)
	  X=X*(DP(L,Y)-DP(L+1,Y))
	  H5RE=H5RE+X
	END DO
	DO L=1,4
	H5RE=H5RE+(CPE(L)-CME(L+1)+CME(L)-CPE(L-1))*DP(L,Y)
	END DO
	H5RE=H5RE*DCOS(THE/2.)*DSQRT(2.D0)
	RETURN
	END




	COMPLEX*16 FUNCTION H6RE(Q2,W,THETA)
	IMPLICIT REAL*8 (A-H,O-Z)
	COMPLEX*16 X,CPE,CME
	COMMON /CPE/ CPE,CME
	DIMENSION CPE(0:10),CME(0:10)
	DATA PI/3.141592654D0/
	THE=THETA*PI/180.
	Y=DCOS(THE)
	H6RE=(0.D0,0.D0)
	DO L=0,5
	  X=CPE(L)+CME(L+1)
	  X=X*(DP(L,Y)+DP(L+1,Y))
	 H6RE=H6RE+X
	END DO
	DO L=1,4
	H6RE=H6RE+(CPE(L)+CME(L+1)+CME(L)+CPE(L-1))*DP(L,Y)
	END DO
	H6RE=H6RE*DSIN(THE/2.)*DSQRT(2.D0)
	RETURN
	END


	REAL*8 FUNCTION HBORN(I,IREA,Q2,W,THETA)
	IMPLICIT REAL*8 (A - Z)
	COMMON /MAG/ SWITCH,SCHALTER
	INTEGER I,IREA,SWITCH,SCHALTER,J
	DIMENSION M(6,6),A(6)
	DATA MP/.938279D0/,MPIN/.134964D0/,MPIP/.1395688D0/,
     *  PI/3.1415926535897932D0/,MUEPNEU/2.793D0/,MUENNEU/1.913D0/

	IF((IREA.EQ.1).OR.(IREA.EQ.2))THEN
	  MPI=MPIN
	ELSE
	  MPI=MPIP
	END IF



	SIGMA=W**2-MP**2
	BETA=SIGMA+Q2/2.D0
	K0=(SIGMA-Q2)/(2.*W)
	K=DSQRT(K0**2+Q2)
	Q0=(SIGMA+MPI**2)/(2.*W)
	Q=Q0**2-MPI**2
	Q=DSQRT(Q)
	NUE=-(W+MP)
	OMEGA=W-MP
	E1=-NUE-K0
	E2=-NUE-Q0
	G1=-W+MP+K0
	S=W**2
	T=2.D0*Q*K*DCOS(THETA*PI/180.)-2.D0*Q0*K0+MPI**2-Q2
	U=S-2.D0*BETA-(T-MPI**2)
	G2=-W+MP+Q0
	ER=DSQRT(4.*PI/137)
	GR=(2.*MP/MPI)*DSQRT(4.*PI*0.081)

C	SWITCH DIENT ZUM EIN BZW AUSSCHALTEN DER MAGN BORNTERME
C
C	SWITCH=1   ===>  AUS
C	      =0   ===>  EIN
	MUEN=MUENNEU
	MUEP=MUEPNEU


C	BERECHNUNG DER FORMFAKTOREN
C
	FPI=(1+Q2/.5)**-1

	GEP=1.D0/(1.+3.04*Q2+1.54*Q2*Q2+.068*Q2*Q2*Q2)

	CAP=Q2/(4.*MP*MP)

	F1P=GEP*(1.D0+MUEP*CAP)/(1.D0+CAP)
	F1N=GEP*CAP*(-MUEN)/(1.D0+CAP)
	if(switch.eq.0)then
	F2P=(1./(2.*MP))*GEP*(MUEP-1.D0)/(1.D0+CAP)
	F2N=(1./(2.*MP))*GEP*(-MUEN)/(1.D0+CAP)
       	else
	f2p=0.d0
	f2n=0.d0
	end if


	IF(I.EQ.1)THEN
	M(1,1)=-4.D0*OMEGA*E1
	M(1,2)=BETA*(Q2+2.*NUE*(Q0-K0)-(T-MPI**2))
	M(1,3)=-2.*E1*OMEGA**2+(E1-K0)*(T-MPI**2)+Q2*(-NUE+2.*(Q0-K0))
	M(1,4)=-2.*E1*OMEGA**2-(E1-K0)*(T-MPI**2)-Q2*(-NUE+2.*(Q0-K0))
C	Q2 FAELLT WEG !
	M(1,5)=-(Q2+2.*NUE*(Q0-K0)-(T-MPI**2))
	M(1,6)=-4.*Q2*E1
	HI=G1*DSQRT(E1*E2)/(8.*PI*W)
	END IF

	IF(I.EQ.3)THEN
	M(3,1)=0.D0
	M(3,2)=-BETA
	M(3,3)=NUE
	M(3,4)=-M(3,3)
C	Q2 FAELLT WEG !!
	M(3,5)=1.D0
	M(3,6)=0.D0
	HI=E2*DSQRT(G1*G2)/(8.*PI*W)
	END IF

	IF(I.EQ.5)THEN
	M(5,1)=2.*E1
	M(5,2)=BETA*(2.*Q0-K0)+(2.*W-3.*K0/2.)*(T-MPI**2)
	M(5,3)=E1*OMEGA-NUE*(2.*Q0-K0)+(T-MPI**2)
	M(5,4)=E1*OMEGA+NUE*(2.*Q0-K0)-(T-MPI**2)
C	Q2 FAELLT WEG !
	M(5,5)=-(2.*Q0-K0)+K0*(T-MPI**2)/Q2
	M(5,6)=-2.*OMEGA*E1
	HI=-G1*DSQRT(E1*E2)/(8.*PI*W)
	END IF

	IF(I.NE.3)THEN
	  DO J=1,6
	    M(I,J)=M(I,J)/(2.*K*K)
	  END DO
	END IF



	IF((IREA.EQ.1).OR.(IREA.EQ.2))THEN
	  IF(IREA.EQ.1)THEN
	    XIREA=F1P
	    XIREA2=F2P
	  ELSE
	    XIREA=F1N
	    XIREA2=F2N
	  END IF
	
	  A(1)=-ER*GR*XIREA*(1./(MP**2-S)+1./(MP**2-U))
	  A(2)=-2.*A(1)/(T-MPI**2)
	  A(3)=ER*GR*XIREA2*(1./(MP**2-S)-1./(MP**2-U))
	  A(4)=ER*GR*XIREA2*(1./(MP**2-S)+1./(MP**2-U))
	  A(5)=Q2*ER*GR*XIREA*(1./(MP**2-S)-1./(MP**2-U))/(T-MPI**2)
	  A(6)=0.D0
	  IF(IREA.EQ.2)THEN
	    DO J=1,5
	      A(J)=-A(J)
	    END DO
	  END IF
	END IF
	IF((IREA.EQ.3).OR.(IREA.EQ.4))THEN
	  IF(IREA.EQ.3)THEN
	    XIREA1=F1P
	    XIREA2=F1N
	    XIREA3=F2P
	    XIREA4=F2N
	  ELSE
	    XIREA1=F1N
	    XIREA2=F1P
	    XIREA3=F2N
	    XIREA4=F2P
	  END IF

	  A(1)=-ER*GR*(XIREA1/(MP**2-S)+XIREA2/(MP**2-U))
	  A(2)=-A(1)*2.D0/(T-MPI**2)
	  A(3)=ER*GR*(XIREA3/(MP**2-S)-XIREA4/(MP**2-U))
	  A(4)=ER*GR*(XIREA3/(MP**2-S)+XIREA4/(MP**2-U))
	  A(5)=ER*GR*(XIREA1/(MP**2-S)-XIREA2/(MP**2-U))*Q2/(T-MPI**2)
	IF(IREA.EQ.3)THEN
	A(5)=A(5)+2.*ER*GR*(FPI-F1P+F1N)/(T-MPI**2)
	ELSE
	A(5)=A(5)-2.*ER*GR*(FPI-F1P+F1N)/(T-MPI**2)
	END IF
	  A(6)=0.D0
	  DO J=1,5
	    A(J)=A(J)*DSQRT(2.D0)
	    IF(IREA.EQ.3)A(J)=-A(J)
	  END DO
	END IF

	HBORN=0.D0
	DO J=1,6
	  HBORN=HBORN+A(J)*M(I,J)
	END DO


	HBORN=HBORN*HI*19.732857D0
	RETURN
	END





	REAL*8 FUNCTION HIBORN(I,IREA,Q2,W,THETA)
	IMPLICIT REAL*8 (A - Z)
	INTEGER I,IREA
	DATA PI/3.1415926535897932D0/
	THE=THETA*PI/180.
	IF(I.EQ.1)THEN
	  HIBORN=DSIN(THE)*DCOS(THE/2.D0)*(HBORN(3,IREA,Q2,W,THETA)-
     *    HBORN(3,IREA,Q2,-W,THETA))
	END IF
	IF(I.EQ.2)THEN
	  HIBORN=DCOS(THE/2.D0)*(-HBORN(1,IREA,Q2,W,THETA)-
     *    HBORN(1,IREA,Q2,-W,THETA))
	END IF
	IF(I.EQ.3)THEN
	  HIBORN=DSIN(THE)*DSIN(THE/2.)*(-HBORN(3,IREA,Q2,W,THETA)
     *    -HBORN(3,IREA,Q2,-W,THETA))
	END IF
	IF(I.EQ.4)THEN
	  HIBORN=DSIN(THE/2.D0)*(HBORN(1,IREA,Q2,W,THETA)-
     *      HBORN(1,IREA,Q2,-W,THETA))
	END IF
	IF(I.EQ.5)THEN
	  IF(Q2.EQ.0.D0)THEN
	    HIBORN=0.D0
	  ELSE
	 HIBORN=2.*DCOS(THE/2.D0)*DSQRT(Q2)*(-HBORN(5,IREA,Q2,W,THETA)
     *     -HBORN(5,IREA,Q2,-W,THETA))
	  END IF
	END IF
	IF(I.EQ.6)THEN
	  IF(Q2.EQ.0.D0)THEN
	    HIBORN=0.D0
	  ELSE
	  HIBORN=2.*DSIN(THE/2.D0)*DSQRT(Q2)*(HBORN(5,IREA,Q2,W,THETA)-
     *     HBORN(5,IREA,Q2,-W,THETA))
	  END IF
	END IF
	HIBORN=HIBORN/DSQRT(2.D0)
	RETURN
	END
