;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.0 #9615 (MINGW32)
;--------------------------------------------------------
	.module pong
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _printWinner
	.globl _strcpy
	.globl _printf
	.globl _P7_7
	.globl _P7_6
	.globl _P7_5
	.globl _P7_4
	.globl _P7_3
	.globl _P7_2
	.globl _P7_1
	.globl _P7_0
	.globl _SPIF
	.globl _WCOL
	.globl _MODF
	.globl _RXOVRN
	.globl _NSSMD1
	.globl _NSSMD0
	.globl _TXBMT
	.globl _SPIEN
	.globl _P6_7
	.globl _P6_6
	.globl _P6_5
	.globl _P6_4
	.globl _P6_3
	.globl _P6_2
	.globl _P6_1
	.globl _P6_0
	.globl _AD2EN
	.globl _AD2TM
	.globl _AD2INT
	.globl _AD2BUSY
	.globl _AD2CM2
	.globl _AD2CM1
	.globl _AD2CM0
	.globl _AD2WINT
	.globl _AD0EN
	.globl _AD0TM
	.globl _AD0INT
	.globl _AD0BUSY
	.globl _AD0CM1
	.globl _AD0CM0
	.globl _AD0WINT
	.globl _AD0LJST
	.globl _P5_7
	.globl _P5_6
	.globl _P5_5
	.globl _P5_4
	.globl _P5_3
	.globl _P5_2
	.globl _P5_1
	.globl _P5_0
	.globl _CF
	.globl _CR
	.globl _CCF5
	.globl _CCF4
	.globl _CCF3
	.globl _CCF2
	.globl _CCF1
	.globl _CCF0
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _P4_7
	.globl _P4_6
	.globl _P4_5
	.globl _P4_4
	.globl _P4_3
	.globl _P4_2
	.globl _P4_1
	.globl _P4_0
	.globl _TF4
	.globl _EXF4
	.globl _EXEN4
	.globl _TR4
	.globl _CT4
	.globl _CPRL4
	.globl _TF3
	.globl _EXF3
	.globl _EXEN3
	.globl _TR3
	.globl _CT3
	.globl _CPRL3
	.globl _TF2
	.globl _EXF2
	.globl _EXEN2
	.globl _TR2
	.globl _CT2
	.globl _CPRL2
	.globl _MAC0HO
	.globl _MAC0Z
	.globl _MAC0SO
	.globl _MAC0N
	.globl _BUSY
	.globl _ENSMB
	.globl _STA
	.globl _STO
	.globl _SI
	.globl _AA
	.globl _SMBFTE
	.globl _SMBTOE
	.globl _PT2
	.globl _PS
	.globl _PS0
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ET2
	.globl _ES
	.globl _ES0
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _S1MODE
	.globl _MCE1
	.globl _REN1
	.globl _TB81
	.globl _RB81
	.globl _TI1
	.globl _RI1
	.globl _SM00
	.globl _SM10
	.globl _SM20
	.globl _REN
	.globl _REN0
	.globl _TB80
	.globl _RB80
	.globl _TI
	.globl _TI0
	.globl _RI
	.globl _RI0
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _FLHBUSY
	.globl _CP1EN
	.globl _CP1OUT
	.globl _CP1RIF
	.globl _CP1FIF
	.globl _CP1HYP1
	.globl _CP1HYP0
	.globl _CP1HYN1
	.globl _CP1HYN0
	.globl _CP0EN
	.globl _CP0OUT
	.globl _CP0RIF
	.globl _CP0FIF
	.globl _CP0HYP1
	.globl _CP0HYP0
	.globl _CP0HYN1
	.globl _CP0HYN0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _MAC0RND
	.globl _MAC0ACC
	.globl _MAC0A
	.globl _RCAP4
	.globl _TMR4
	.globl _DAC1
	.globl _RCAP3
	.globl _TMR3
	.globl _PCA0CP5
	.globl _PCA0CP4
	.globl _PCA0CP3
	.globl _PCA0CP2
	.globl _PCA0CP1
	.globl _PCA0CP0
	.globl _PCA0
	.globl _DAC0
	.globl _ADC0LT
	.globl _ADC0GT
	.globl _ADC0
	.globl _RCAP2
	.globl _TMR2
	.globl _TMR1
	.globl _TMR0
	.globl _P7
	.globl _P6
	.globl _XBR2
	.globl _XBR1
	.globl _XBR0
	.globl _P5
	.globl _P4
	.globl _FLACL
	.globl _P1MDIN
	.globl _P3MDOUT
	.globl _P2MDOUT
	.globl _P1MDOUT
	.globl _P0MDOUT
	.globl _CCH0LC
	.globl _CCH0TN
	.globl _CCH0CN
	.globl _P7MDOUT
	.globl _P6MDOUT
	.globl _P5MDOUT
	.globl _P4MDOUT
	.globl _CCH0MA
	.globl _CLKSEL
	.globl _SFRPGCN
	.globl _PLL0FLT
	.globl _PLL0MUL
	.globl _PLL0DIV
	.globl _OSCXCN
	.globl _OSCICL
	.globl _OSCICN
	.globl _PLL0CN
	.globl _FLSTAT
	.globl _MAC0RNDH
	.globl _MAC0RNDL
	.globl _MAC0CF
	.globl _MAC0AH
	.globl _MAC0AL
	.globl _MAC0STA
	.globl _MAC0OVR
	.globl _MAC0ACC3
	.globl _MAC0ACC2
	.globl _MAC0ACC1
	.globl _MAC0ACC0
	.globl _MAC0BH
	.globl _MAC0BL
	.globl _ADC2CN
	.globl _TMR4H
	.globl _TMR4L
	.globl _RCAP4H
	.globl _RCAP4L
	.globl _TMR4CF
	.globl _TMR4CN
	.globl _ADC2LT
	.globl _ADC2GT
	.globl _ADC2
	.globl _ADC2CF
	.globl _AMX2SL
	.globl _AMX2CF
	.globl _CPT1MD
	.globl _CPT1CN
	.globl _DAC1CN
	.globl _DAC1H
	.globl _DAC1L
	.globl _TMR3H
	.globl _TMR3L
	.globl _RCAP3H
	.globl _RCAP3L
	.globl _TMR3CF
	.globl _TMR3CN
	.globl _SBUF1
	.globl _SCON1
	.globl _CPT0MD
	.globl _CPT0CN
	.globl _PCA0CPH1
	.globl _PCA0CPL1
	.globl _PCA0CPH0
	.globl _PCA0CPL0
	.globl _PCA0H
	.globl _PCA0L
	.globl _SPI0CN
	.globl _RSTSRC
	.globl _PCA0CPH4
	.globl _PCA0CPL4
	.globl _PCA0CPH3
	.globl _PCA0CPL3
	.globl _PCA0CPH2
	.globl _PCA0CPL2
	.globl _ADC0CN
	.globl _PCA0CPH5
	.globl _PCA0CPL5
	.globl _PCA0CPM5
	.globl _PCA0CPM4
	.globl _PCA0CPM3
	.globl _PCA0CPM2
	.globl _PCA0CPM1
	.globl _PCA0CPM0
	.globl _PCA0MD
	.globl _PCA0CN
	.globl _DAC0CN
	.globl _DAC0H
	.globl _DAC0L
	.globl _REF0CN
	.globl _SMB0CR
	.globl _TH2
	.globl _TMR2H
	.globl _TL2
	.globl _TMR2L
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _TMR2CF
	.globl _TMR2CN
	.globl _ADC0LTH
	.globl _ADC0LTL
	.globl _ADC0GTH
	.globl _ADC0GTL
	.globl _SMB0ADR
	.globl _SMB0DAT
	.globl _SMB0STA
	.globl _SMB0CN
	.globl _ADC0H
	.globl _ADC0L
	.globl _ADC0CF
	.globl _AMX0SL
	.globl _AMX0CF
	.globl _SADEN0
	.globl _FLSCL
	.globl _SADDR0
	.globl _EMI0CF
	.globl __XPAGE
	.globl _EMI0CN
	.globl _EMI0TC
	.globl _SPI0CKR
	.globl _SPI0DAT
	.globl _SPI0CFG
	.globl _SBUF
	.globl _SBUF0
	.globl _SCON
	.globl _SCON0
	.globl _SSTA0
	.globl _PSCTL
	.globl _CKCON
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _WDTCN
	.globl _EIP2
	.globl _EIP1
	.globl _B
	.globl _EIE2
	.globl _EIE1
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _PSBANK
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _P1
	.globl _PCON
	.globl _SFRLAST
	.globl _SFRNEXT
	.globl _SFRPAGE
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _velY
	.globl _velX
	.globl _ballY
	.globl _ballX
	.globl _player2Pos
	.globl _player1Pos
	.globl _score2
	.globl _score1
	.globl _screenHeight
	.globl _screenWidth
	.globl _pixel
	.globl _putchar
	.globl _getchar
	.globl _main
	.globl _SYSCLK_INIT
	.globl _PORT_INIT
	.globl _UART0_INIT
	.globl _updateBall
	.globl _updatePositions
	.globl _printPlayers
	.globl _printBorder
	.globl _updateScore
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
G$P0$0$0 == 0x0080
_P0	=	0x0080
G$SP$0$0 == 0x0081
_SP	=	0x0081
G$DPL$0$0 == 0x0082
_DPL	=	0x0082
G$DPH$0$0 == 0x0083
_DPH	=	0x0083
G$SFRPAGE$0$0 == 0x0084
_SFRPAGE	=	0x0084
G$SFRNEXT$0$0 == 0x0085
_SFRNEXT	=	0x0085
G$SFRLAST$0$0 == 0x0086
_SFRLAST	=	0x0086
G$PCON$0$0 == 0x0087
_PCON	=	0x0087
G$P1$0$0 == 0x0090
_P1	=	0x0090
G$P2$0$0 == 0x00a0
_P2	=	0x00a0
G$IE$0$0 == 0x00a8
_IE	=	0x00a8
G$P3$0$0 == 0x00b0
_P3	=	0x00b0
G$PSBANK$0$0 == 0x00b1
_PSBANK	=	0x00b1
G$IP$0$0 == 0x00b8
_IP	=	0x00b8
G$PSW$0$0 == 0x00d0
_PSW	=	0x00d0
G$ACC$0$0 == 0x00e0
_ACC	=	0x00e0
G$EIE1$0$0 == 0x00e6
_EIE1	=	0x00e6
G$EIE2$0$0 == 0x00e7
_EIE2	=	0x00e7
G$B$0$0 == 0x00f0
_B	=	0x00f0
G$EIP1$0$0 == 0x00f6
_EIP1	=	0x00f6
G$EIP2$0$0 == 0x00f7
_EIP2	=	0x00f7
G$WDTCN$0$0 == 0x00ff
_WDTCN	=	0x00ff
G$TCON$0$0 == 0x0088
_TCON	=	0x0088
G$TMOD$0$0 == 0x0089
_TMOD	=	0x0089
G$TL0$0$0 == 0x008a
_TL0	=	0x008a
G$TL1$0$0 == 0x008b
_TL1	=	0x008b
G$TH0$0$0 == 0x008c
_TH0	=	0x008c
G$TH1$0$0 == 0x008d
_TH1	=	0x008d
G$CKCON$0$0 == 0x008e
_CKCON	=	0x008e
G$PSCTL$0$0 == 0x008f
_PSCTL	=	0x008f
G$SSTA0$0$0 == 0x0091
_SSTA0	=	0x0091
G$SCON0$0$0 == 0x0098
_SCON0	=	0x0098
G$SCON$0$0 == 0x0098
_SCON	=	0x0098
G$SBUF0$0$0 == 0x0099
_SBUF0	=	0x0099
G$SBUF$0$0 == 0x0099
_SBUF	=	0x0099
G$SPI0CFG$0$0 == 0x009a
_SPI0CFG	=	0x009a
G$SPI0DAT$0$0 == 0x009b
_SPI0DAT	=	0x009b
G$SPI0CKR$0$0 == 0x009d
_SPI0CKR	=	0x009d
G$EMI0TC$0$0 == 0x00a1
_EMI0TC	=	0x00a1
G$EMI0CN$0$0 == 0x00a2
_EMI0CN	=	0x00a2
G$_XPAGE$0$0 == 0x00a2
__XPAGE	=	0x00a2
G$EMI0CF$0$0 == 0x00a3
_EMI0CF	=	0x00a3
G$SADDR0$0$0 == 0x00a9
_SADDR0	=	0x00a9
G$FLSCL$0$0 == 0x00b7
_FLSCL	=	0x00b7
G$SADEN0$0$0 == 0x00b9
_SADEN0	=	0x00b9
G$AMX0CF$0$0 == 0x00ba
_AMX0CF	=	0x00ba
G$AMX0SL$0$0 == 0x00bb
_AMX0SL	=	0x00bb
G$ADC0CF$0$0 == 0x00bc
_ADC0CF	=	0x00bc
G$ADC0L$0$0 == 0x00be
_ADC0L	=	0x00be
G$ADC0H$0$0 == 0x00bf
_ADC0H	=	0x00bf
G$SMB0CN$0$0 == 0x00c0
_SMB0CN	=	0x00c0
G$SMB0STA$0$0 == 0x00c1
_SMB0STA	=	0x00c1
G$SMB0DAT$0$0 == 0x00c2
_SMB0DAT	=	0x00c2
G$SMB0ADR$0$0 == 0x00c3
_SMB0ADR	=	0x00c3
G$ADC0GTL$0$0 == 0x00c4
_ADC0GTL	=	0x00c4
G$ADC0GTH$0$0 == 0x00c5
_ADC0GTH	=	0x00c5
G$ADC0LTL$0$0 == 0x00c6
_ADC0LTL	=	0x00c6
G$ADC0LTH$0$0 == 0x00c7
_ADC0LTH	=	0x00c7
G$TMR2CN$0$0 == 0x00c8
_TMR2CN	=	0x00c8
G$TMR2CF$0$0 == 0x00c9
_TMR2CF	=	0x00c9
G$RCAP2L$0$0 == 0x00ca
_RCAP2L	=	0x00ca
G$RCAP2H$0$0 == 0x00cb
_RCAP2H	=	0x00cb
G$TMR2L$0$0 == 0x00cc
_TMR2L	=	0x00cc
G$TL2$0$0 == 0x00cc
_TL2	=	0x00cc
G$TMR2H$0$0 == 0x00cd
_TMR2H	=	0x00cd
G$TH2$0$0 == 0x00cd
_TH2	=	0x00cd
G$SMB0CR$0$0 == 0x00cf
_SMB0CR	=	0x00cf
G$REF0CN$0$0 == 0x00d1
_REF0CN	=	0x00d1
G$DAC0L$0$0 == 0x00d2
_DAC0L	=	0x00d2
G$DAC0H$0$0 == 0x00d3
_DAC0H	=	0x00d3
G$DAC0CN$0$0 == 0x00d4
_DAC0CN	=	0x00d4
G$PCA0CN$0$0 == 0x00d8
_PCA0CN	=	0x00d8
G$PCA0MD$0$0 == 0x00d9
_PCA0MD	=	0x00d9
G$PCA0CPM0$0$0 == 0x00da
_PCA0CPM0	=	0x00da
G$PCA0CPM1$0$0 == 0x00db
_PCA0CPM1	=	0x00db
G$PCA0CPM2$0$0 == 0x00dc
_PCA0CPM2	=	0x00dc
G$PCA0CPM3$0$0 == 0x00dd
_PCA0CPM3	=	0x00dd
G$PCA0CPM4$0$0 == 0x00de
_PCA0CPM4	=	0x00de
G$PCA0CPM5$0$0 == 0x00df
_PCA0CPM5	=	0x00df
G$PCA0CPL5$0$0 == 0x00e1
_PCA0CPL5	=	0x00e1
G$PCA0CPH5$0$0 == 0x00e2
_PCA0CPH5	=	0x00e2
G$ADC0CN$0$0 == 0x00e8
_ADC0CN	=	0x00e8
G$PCA0CPL2$0$0 == 0x00e9
_PCA0CPL2	=	0x00e9
G$PCA0CPH2$0$0 == 0x00ea
_PCA0CPH2	=	0x00ea
G$PCA0CPL3$0$0 == 0x00eb
_PCA0CPL3	=	0x00eb
G$PCA0CPH3$0$0 == 0x00ec
_PCA0CPH3	=	0x00ec
G$PCA0CPL4$0$0 == 0x00ed
_PCA0CPL4	=	0x00ed
G$PCA0CPH4$0$0 == 0x00ee
_PCA0CPH4	=	0x00ee
G$RSTSRC$0$0 == 0x00ef
_RSTSRC	=	0x00ef
G$SPI0CN$0$0 == 0x00f8
_SPI0CN	=	0x00f8
G$PCA0L$0$0 == 0x00f9
_PCA0L	=	0x00f9
G$PCA0H$0$0 == 0x00fa
_PCA0H	=	0x00fa
G$PCA0CPL0$0$0 == 0x00fb
_PCA0CPL0	=	0x00fb
G$PCA0CPH0$0$0 == 0x00fc
_PCA0CPH0	=	0x00fc
G$PCA0CPL1$0$0 == 0x00fd
_PCA0CPL1	=	0x00fd
G$PCA0CPH1$0$0 == 0x00fe
_PCA0CPH1	=	0x00fe
G$CPT0CN$0$0 == 0x0088
_CPT0CN	=	0x0088
G$CPT0MD$0$0 == 0x0089
_CPT0MD	=	0x0089
G$SCON1$0$0 == 0x0098
_SCON1	=	0x0098
G$SBUF1$0$0 == 0x0099
_SBUF1	=	0x0099
G$TMR3CN$0$0 == 0x00c8
_TMR3CN	=	0x00c8
G$TMR3CF$0$0 == 0x00c9
_TMR3CF	=	0x00c9
G$RCAP3L$0$0 == 0x00ca
_RCAP3L	=	0x00ca
G$RCAP3H$0$0 == 0x00cb
_RCAP3H	=	0x00cb
G$TMR3L$0$0 == 0x00cc
_TMR3L	=	0x00cc
G$TMR3H$0$0 == 0x00cd
_TMR3H	=	0x00cd
G$DAC1L$0$0 == 0x00d2
_DAC1L	=	0x00d2
G$DAC1H$0$0 == 0x00d3
_DAC1H	=	0x00d3
G$DAC1CN$0$0 == 0x00d4
_DAC1CN	=	0x00d4
G$CPT1CN$0$0 == 0x0088
_CPT1CN	=	0x0088
G$CPT1MD$0$0 == 0x0089
_CPT1MD	=	0x0089
G$AMX2CF$0$0 == 0x00ba
_AMX2CF	=	0x00ba
G$AMX2SL$0$0 == 0x00bb
_AMX2SL	=	0x00bb
G$ADC2CF$0$0 == 0x00bc
_ADC2CF	=	0x00bc
G$ADC2$0$0 == 0x00be
_ADC2	=	0x00be
G$ADC2GT$0$0 == 0x00c4
_ADC2GT	=	0x00c4
G$ADC2LT$0$0 == 0x00c6
_ADC2LT	=	0x00c6
G$TMR4CN$0$0 == 0x00c8
_TMR4CN	=	0x00c8
G$TMR4CF$0$0 == 0x00c9
_TMR4CF	=	0x00c9
G$RCAP4L$0$0 == 0x00ca
_RCAP4L	=	0x00ca
G$RCAP4H$0$0 == 0x00cb
_RCAP4H	=	0x00cb
G$TMR4L$0$0 == 0x00cc
_TMR4L	=	0x00cc
G$TMR4H$0$0 == 0x00cd
_TMR4H	=	0x00cd
G$ADC2CN$0$0 == 0x00e8
_ADC2CN	=	0x00e8
G$MAC0BL$0$0 == 0x0091
_MAC0BL	=	0x0091
G$MAC0BH$0$0 == 0x0092
_MAC0BH	=	0x0092
G$MAC0ACC0$0$0 == 0x0093
_MAC0ACC0	=	0x0093
G$MAC0ACC1$0$0 == 0x0094
_MAC0ACC1	=	0x0094
G$MAC0ACC2$0$0 == 0x0095
_MAC0ACC2	=	0x0095
G$MAC0ACC3$0$0 == 0x0096
_MAC0ACC3	=	0x0096
G$MAC0OVR$0$0 == 0x0097
_MAC0OVR	=	0x0097
G$MAC0STA$0$0 == 0x00c0
_MAC0STA	=	0x00c0
G$MAC0AL$0$0 == 0x00c1
_MAC0AL	=	0x00c1
G$MAC0AH$0$0 == 0x00c2
_MAC0AH	=	0x00c2
G$MAC0CF$0$0 == 0x00c3
_MAC0CF	=	0x00c3
G$MAC0RNDL$0$0 == 0x00ce
_MAC0RNDL	=	0x00ce
G$MAC0RNDH$0$0 == 0x00cf
_MAC0RNDH	=	0x00cf
G$FLSTAT$0$0 == 0x0088
_FLSTAT	=	0x0088
G$PLL0CN$0$0 == 0x0089
_PLL0CN	=	0x0089
G$OSCICN$0$0 == 0x008a
_OSCICN	=	0x008a
G$OSCICL$0$0 == 0x008b
_OSCICL	=	0x008b
G$OSCXCN$0$0 == 0x008c
_OSCXCN	=	0x008c
G$PLL0DIV$0$0 == 0x008d
_PLL0DIV	=	0x008d
G$PLL0MUL$0$0 == 0x008e
_PLL0MUL	=	0x008e
G$PLL0FLT$0$0 == 0x008f
_PLL0FLT	=	0x008f
G$SFRPGCN$0$0 == 0x0096
_SFRPGCN	=	0x0096
G$CLKSEL$0$0 == 0x0097
_CLKSEL	=	0x0097
G$CCH0MA$0$0 == 0x009a
_CCH0MA	=	0x009a
G$P4MDOUT$0$0 == 0x009c
_P4MDOUT	=	0x009c
G$P5MDOUT$0$0 == 0x009d
_P5MDOUT	=	0x009d
G$P6MDOUT$0$0 == 0x009e
_P6MDOUT	=	0x009e
G$P7MDOUT$0$0 == 0x009f
_P7MDOUT	=	0x009f
G$CCH0CN$0$0 == 0x00a1
_CCH0CN	=	0x00a1
G$CCH0TN$0$0 == 0x00a2
_CCH0TN	=	0x00a2
G$CCH0LC$0$0 == 0x00a3
_CCH0LC	=	0x00a3
G$P0MDOUT$0$0 == 0x00a4
_P0MDOUT	=	0x00a4
G$P1MDOUT$0$0 == 0x00a5
_P1MDOUT	=	0x00a5
G$P2MDOUT$0$0 == 0x00a6
_P2MDOUT	=	0x00a6
G$P3MDOUT$0$0 == 0x00a7
_P3MDOUT	=	0x00a7
G$P1MDIN$0$0 == 0x00ad
_P1MDIN	=	0x00ad
G$FLACL$0$0 == 0x00b7
_FLACL	=	0x00b7
G$P4$0$0 == 0x00c8
_P4	=	0x00c8
G$P5$0$0 == 0x00d8
_P5	=	0x00d8
G$XBR0$0$0 == 0x00e1
_XBR0	=	0x00e1
G$XBR1$0$0 == 0x00e2
_XBR1	=	0x00e2
G$XBR2$0$0 == 0x00e3
_XBR2	=	0x00e3
G$P6$0$0 == 0x00e8
_P6	=	0x00e8
G$P7$0$0 == 0x00f8
_P7	=	0x00f8
G$TMR0$0$0 == 0x8c8a
_TMR0	=	0x8c8a
G$TMR1$0$0 == 0x8d8b
_TMR1	=	0x8d8b
G$TMR2$0$0 == 0xcdcc
_TMR2	=	0xcdcc
G$RCAP2$0$0 == 0xcbca
_RCAP2	=	0xcbca
G$ADC0$0$0 == 0xbfbe
_ADC0	=	0xbfbe
G$ADC0GT$0$0 == 0xc5c4
_ADC0GT	=	0xc5c4
G$ADC0LT$0$0 == 0xc7c6
_ADC0LT	=	0xc7c6
G$DAC0$0$0 == 0xd3d2
_DAC0	=	0xd3d2
G$PCA0$0$0 == 0xfaf9
_PCA0	=	0xfaf9
G$PCA0CP0$0$0 == 0xfcfb
_PCA0CP0	=	0xfcfb
G$PCA0CP1$0$0 == 0xfefd
_PCA0CP1	=	0xfefd
G$PCA0CP2$0$0 == 0xeae9
_PCA0CP2	=	0xeae9
G$PCA0CP3$0$0 == 0xeceb
_PCA0CP3	=	0xeceb
G$PCA0CP4$0$0 == 0xeeed
_PCA0CP4	=	0xeeed
G$PCA0CP5$0$0 == 0xe2e1
_PCA0CP5	=	0xe2e1
G$TMR3$0$0 == 0xcdcc
_TMR3	=	0xcdcc
G$RCAP3$0$0 == 0xcbca
_RCAP3	=	0xcbca
G$DAC1$0$0 == 0xd3d2
_DAC1	=	0xd3d2
G$TMR4$0$0 == 0xcdcc
_TMR4	=	0xcdcc
G$RCAP4$0$0 == 0xcbca
_RCAP4	=	0xcbca
G$MAC0A$0$0 == 0xc2c1
_MAC0A	=	0xc2c1
G$MAC0ACC$0$0 == 0x96959493
_MAC0ACC	=	0x96959493
G$MAC0RND$0$0 == 0xcfce
_MAC0RND	=	0xcfce
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
G$P0_0$0$0 == 0x0080
_P0_0	=	0x0080
G$P0_1$0$0 == 0x0081
_P0_1	=	0x0081
G$P0_2$0$0 == 0x0082
_P0_2	=	0x0082
G$P0_3$0$0 == 0x0083
_P0_3	=	0x0083
G$P0_4$0$0 == 0x0084
_P0_4	=	0x0084
G$P0_5$0$0 == 0x0085
_P0_5	=	0x0085
G$P0_6$0$0 == 0x0086
_P0_6	=	0x0086
G$P0_7$0$0 == 0x0087
_P0_7	=	0x0087
G$IT0$0$0 == 0x0088
_IT0	=	0x0088
G$IE0$0$0 == 0x0089
_IE0	=	0x0089
G$IT1$0$0 == 0x008a
_IT1	=	0x008a
G$IE1$0$0 == 0x008b
_IE1	=	0x008b
G$TR0$0$0 == 0x008c
_TR0	=	0x008c
G$TF0$0$0 == 0x008d
_TF0	=	0x008d
G$TR1$0$0 == 0x008e
_TR1	=	0x008e
G$TF1$0$0 == 0x008f
_TF1	=	0x008f
G$CP0HYN0$0$0 == 0x0088
_CP0HYN0	=	0x0088
G$CP0HYN1$0$0 == 0x0089
_CP0HYN1	=	0x0089
G$CP0HYP0$0$0 == 0x008a
_CP0HYP0	=	0x008a
G$CP0HYP1$0$0 == 0x008b
_CP0HYP1	=	0x008b
G$CP0FIF$0$0 == 0x008c
_CP0FIF	=	0x008c
G$CP0RIF$0$0 == 0x008d
_CP0RIF	=	0x008d
G$CP0OUT$0$0 == 0x008e
_CP0OUT	=	0x008e
G$CP0EN$0$0 == 0x008f
_CP0EN	=	0x008f
G$CP1HYN0$0$0 == 0x0088
_CP1HYN0	=	0x0088
G$CP1HYN1$0$0 == 0x0089
_CP1HYN1	=	0x0089
G$CP1HYP0$0$0 == 0x008a
_CP1HYP0	=	0x008a
G$CP1HYP1$0$0 == 0x008b
_CP1HYP1	=	0x008b
G$CP1FIF$0$0 == 0x008c
_CP1FIF	=	0x008c
G$CP1RIF$0$0 == 0x008d
_CP1RIF	=	0x008d
G$CP1OUT$0$0 == 0x008e
_CP1OUT	=	0x008e
G$CP1EN$0$0 == 0x008f
_CP1EN	=	0x008f
G$FLHBUSY$0$0 == 0x0088
_FLHBUSY	=	0x0088
G$P1_0$0$0 == 0x0090
_P1_0	=	0x0090
G$P1_1$0$0 == 0x0091
_P1_1	=	0x0091
G$P1_2$0$0 == 0x0092
_P1_2	=	0x0092
G$P1_3$0$0 == 0x0093
_P1_3	=	0x0093
G$P1_4$0$0 == 0x0094
_P1_4	=	0x0094
G$P1_5$0$0 == 0x0095
_P1_5	=	0x0095
G$P1_6$0$0 == 0x0096
_P1_6	=	0x0096
G$P1_7$0$0 == 0x0097
_P1_7	=	0x0097
G$RI0$0$0 == 0x0098
_RI0	=	0x0098
G$RI$0$0 == 0x0098
_RI	=	0x0098
G$TI0$0$0 == 0x0099
_TI0	=	0x0099
G$TI$0$0 == 0x0099
_TI	=	0x0099
G$RB80$0$0 == 0x009a
_RB80	=	0x009a
G$TB80$0$0 == 0x009b
_TB80	=	0x009b
G$REN0$0$0 == 0x009c
_REN0	=	0x009c
G$REN$0$0 == 0x009c
_REN	=	0x009c
G$SM20$0$0 == 0x009d
_SM20	=	0x009d
G$SM10$0$0 == 0x009e
_SM10	=	0x009e
G$SM00$0$0 == 0x009f
_SM00	=	0x009f
G$RI1$0$0 == 0x0098
_RI1	=	0x0098
G$TI1$0$0 == 0x0099
_TI1	=	0x0099
G$RB81$0$0 == 0x009a
_RB81	=	0x009a
G$TB81$0$0 == 0x009b
_TB81	=	0x009b
G$REN1$0$0 == 0x009c
_REN1	=	0x009c
G$MCE1$0$0 == 0x009d
_MCE1	=	0x009d
G$S1MODE$0$0 == 0x009f
_S1MODE	=	0x009f
G$P2_0$0$0 == 0x00a0
_P2_0	=	0x00a0
G$P2_1$0$0 == 0x00a1
_P2_1	=	0x00a1
G$P2_2$0$0 == 0x00a2
_P2_2	=	0x00a2
G$P2_3$0$0 == 0x00a3
_P2_3	=	0x00a3
G$P2_4$0$0 == 0x00a4
_P2_4	=	0x00a4
G$P2_5$0$0 == 0x00a5
_P2_5	=	0x00a5
G$P2_6$0$0 == 0x00a6
_P2_6	=	0x00a6
G$P2_7$0$0 == 0x00a7
_P2_7	=	0x00a7
G$EX0$0$0 == 0x00a8
_EX0	=	0x00a8
G$ET0$0$0 == 0x00a9
_ET0	=	0x00a9
G$EX1$0$0 == 0x00aa
_EX1	=	0x00aa
G$ET1$0$0 == 0x00ab
_ET1	=	0x00ab
G$ES0$0$0 == 0x00ac
_ES0	=	0x00ac
G$ES$0$0 == 0x00ac
_ES	=	0x00ac
G$ET2$0$0 == 0x00ad
_ET2	=	0x00ad
G$EA$0$0 == 0x00af
_EA	=	0x00af
G$P3_0$0$0 == 0x00b0
_P3_0	=	0x00b0
G$P3_1$0$0 == 0x00b1
_P3_1	=	0x00b1
G$P3_2$0$0 == 0x00b2
_P3_2	=	0x00b2
G$P3_3$0$0 == 0x00b3
_P3_3	=	0x00b3
G$P3_4$0$0 == 0x00b4
_P3_4	=	0x00b4
G$P3_5$0$0 == 0x00b5
_P3_5	=	0x00b5
G$P3_6$0$0 == 0x00b6
_P3_6	=	0x00b6
G$P3_7$0$0 == 0x00b7
_P3_7	=	0x00b7
G$PX0$0$0 == 0x00b8
_PX0	=	0x00b8
G$PT0$0$0 == 0x00b9
_PT0	=	0x00b9
G$PX1$0$0 == 0x00ba
_PX1	=	0x00ba
G$PT1$0$0 == 0x00bb
_PT1	=	0x00bb
G$PS0$0$0 == 0x00bc
_PS0	=	0x00bc
G$PS$0$0 == 0x00bc
_PS	=	0x00bc
G$PT2$0$0 == 0x00bd
_PT2	=	0x00bd
G$SMBTOE$0$0 == 0x00c0
_SMBTOE	=	0x00c0
G$SMBFTE$0$0 == 0x00c1
_SMBFTE	=	0x00c1
G$AA$0$0 == 0x00c2
_AA	=	0x00c2
G$SI$0$0 == 0x00c3
_SI	=	0x00c3
G$STO$0$0 == 0x00c4
_STO	=	0x00c4
G$STA$0$0 == 0x00c5
_STA	=	0x00c5
G$ENSMB$0$0 == 0x00c6
_ENSMB	=	0x00c6
G$BUSY$0$0 == 0x00c7
_BUSY	=	0x00c7
G$MAC0N$0$0 == 0x00c0
_MAC0N	=	0x00c0
G$MAC0SO$0$0 == 0x00c1
_MAC0SO	=	0x00c1
G$MAC0Z$0$0 == 0x00c2
_MAC0Z	=	0x00c2
G$MAC0HO$0$0 == 0x00c3
_MAC0HO	=	0x00c3
G$CPRL2$0$0 == 0x00c8
_CPRL2	=	0x00c8
G$CT2$0$0 == 0x00c9
_CT2	=	0x00c9
G$TR2$0$0 == 0x00ca
_TR2	=	0x00ca
G$EXEN2$0$0 == 0x00cb
_EXEN2	=	0x00cb
G$EXF2$0$0 == 0x00ce
_EXF2	=	0x00ce
G$TF2$0$0 == 0x00cf
_TF2	=	0x00cf
G$CPRL3$0$0 == 0x00c8
_CPRL3	=	0x00c8
G$CT3$0$0 == 0x00c9
_CT3	=	0x00c9
G$TR3$0$0 == 0x00ca
_TR3	=	0x00ca
G$EXEN3$0$0 == 0x00cb
_EXEN3	=	0x00cb
G$EXF3$0$0 == 0x00ce
_EXF3	=	0x00ce
G$TF3$0$0 == 0x00cf
_TF3	=	0x00cf
G$CPRL4$0$0 == 0x00c8
_CPRL4	=	0x00c8
G$CT4$0$0 == 0x00c9
_CT4	=	0x00c9
G$TR4$0$0 == 0x00ca
_TR4	=	0x00ca
G$EXEN4$0$0 == 0x00cb
_EXEN4	=	0x00cb
G$EXF4$0$0 == 0x00ce
_EXF4	=	0x00ce
G$TF4$0$0 == 0x00cf
_TF4	=	0x00cf
G$P4_0$0$0 == 0x00c8
_P4_0	=	0x00c8
G$P4_1$0$0 == 0x00c9
_P4_1	=	0x00c9
G$P4_2$0$0 == 0x00ca
_P4_2	=	0x00ca
G$P4_3$0$0 == 0x00cb
_P4_3	=	0x00cb
G$P4_4$0$0 == 0x00cc
_P4_4	=	0x00cc
G$P4_5$0$0 == 0x00cd
_P4_5	=	0x00cd
G$P4_6$0$0 == 0x00ce
_P4_6	=	0x00ce
G$P4_7$0$0 == 0x00cf
_P4_7	=	0x00cf
G$P$0$0 == 0x00d0
_P	=	0x00d0
G$F1$0$0 == 0x00d1
_F1	=	0x00d1
G$OV$0$0 == 0x00d2
_OV	=	0x00d2
G$RS0$0$0 == 0x00d3
_RS0	=	0x00d3
G$RS1$0$0 == 0x00d4
_RS1	=	0x00d4
G$F0$0$0 == 0x00d5
_F0	=	0x00d5
G$AC$0$0 == 0x00d6
_AC	=	0x00d6
G$CY$0$0 == 0x00d7
_CY	=	0x00d7
G$CCF0$0$0 == 0x00d8
_CCF0	=	0x00d8
G$CCF1$0$0 == 0x00d9
_CCF1	=	0x00d9
G$CCF2$0$0 == 0x00da
_CCF2	=	0x00da
G$CCF3$0$0 == 0x00db
_CCF3	=	0x00db
G$CCF4$0$0 == 0x00dc
_CCF4	=	0x00dc
G$CCF5$0$0 == 0x00dd
_CCF5	=	0x00dd
G$CR$0$0 == 0x00de
_CR	=	0x00de
G$CF$0$0 == 0x00df
_CF	=	0x00df
G$P5_0$0$0 == 0x00d8
_P5_0	=	0x00d8
G$P5_1$0$0 == 0x00d9
_P5_1	=	0x00d9
G$P5_2$0$0 == 0x00da
_P5_2	=	0x00da
G$P5_3$0$0 == 0x00db
_P5_3	=	0x00db
G$P5_4$0$0 == 0x00dc
_P5_4	=	0x00dc
G$P5_5$0$0 == 0x00dd
_P5_5	=	0x00dd
G$P5_6$0$0 == 0x00de
_P5_6	=	0x00de
G$P5_7$0$0 == 0x00df
_P5_7	=	0x00df
G$AD0LJST$0$0 == 0x00e8
_AD0LJST	=	0x00e8
G$AD0WINT$0$0 == 0x00e9
_AD0WINT	=	0x00e9
G$AD0CM0$0$0 == 0x00ea
_AD0CM0	=	0x00ea
G$AD0CM1$0$0 == 0x00eb
_AD0CM1	=	0x00eb
G$AD0BUSY$0$0 == 0x00ec
_AD0BUSY	=	0x00ec
G$AD0INT$0$0 == 0x00ed
_AD0INT	=	0x00ed
G$AD0TM$0$0 == 0x00ee
_AD0TM	=	0x00ee
G$AD0EN$0$0 == 0x00ef
_AD0EN	=	0x00ef
G$AD2WINT$0$0 == 0x00e8
_AD2WINT	=	0x00e8
G$AD2CM0$0$0 == 0x00e9
_AD2CM0	=	0x00e9
G$AD2CM1$0$0 == 0x00ea
_AD2CM1	=	0x00ea
G$AD2CM2$0$0 == 0x00eb
_AD2CM2	=	0x00eb
G$AD2BUSY$0$0 == 0x00ec
_AD2BUSY	=	0x00ec
G$AD2INT$0$0 == 0x00ed
_AD2INT	=	0x00ed
G$AD2TM$0$0 == 0x00ee
_AD2TM	=	0x00ee
G$AD2EN$0$0 == 0x00ef
_AD2EN	=	0x00ef
G$P6_0$0$0 == 0x00e8
_P6_0	=	0x00e8
G$P6_1$0$0 == 0x00e9
_P6_1	=	0x00e9
G$P6_2$0$0 == 0x00ea
_P6_2	=	0x00ea
G$P6_3$0$0 == 0x00eb
_P6_3	=	0x00eb
G$P6_4$0$0 == 0x00ec
_P6_4	=	0x00ec
G$P6_5$0$0 == 0x00ed
_P6_5	=	0x00ed
G$P6_6$0$0 == 0x00ee
_P6_6	=	0x00ee
G$P6_7$0$0 == 0x00ef
_P6_7	=	0x00ef
G$SPIEN$0$0 == 0x00f8
_SPIEN	=	0x00f8
G$TXBMT$0$0 == 0x00f9
_TXBMT	=	0x00f9
G$NSSMD0$0$0 == 0x00fa
_NSSMD0	=	0x00fa
G$NSSMD1$0$0 == 0x00fb
_NSSMD1	=	0x00fb
G$RXOVRN$0$0 == 0x00fc
_RXOVRN	=	0x00fc
G$MODF$0$0 == 0x00fd
_MODF	=	0x00fd
G$WCOL$0$0 == 0x00fe
_WCOL	=	0x00fe
G$SPIF$0$0 == 0x00ff
_SPIF	=	0x00ff
G$P7_0$0$0 == 0x00f8
_P7_0	=	0x00f8
G$P7_1$0$0 == 0x00f9
_P7_1	=	0x00f9
G$P7_2$0$0 == 0x00fa
_P7_2	=	0x00fa
G$P7_3$0$0 == 0x00fb
_P7_3	=	0x00fb
G$P7_4$0$0 == 0x00fc
_P7_4	=	0x00fc
G$P7_5$0$0 == 0x00fd
_P7_5	=	0x00fd
G$P7_6$0$0 == 0x00fe
_P7_6	=	0x00fe
G$P7_7$0$0 == 0x00ff
_P7_7	=	0x00ff
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
G$pixel$0$0==.
_pixel::
	.ds 1
G$screenWidth$0$0==.
_screenWidth::
	.ds 1
G$screenHeight$0$0==.
_screenHeight::
	.ds 1
G$score1$0$0==.
_score1::
	.ds 1
G$score2$0$0==.
_score2::
	.ds 1
G$player1Pos$0$0==.
_player1Pos::
	.ds 1
G$player2Pos$0$0==.
_player2Pos::
	.ds 1
G$ballX$0$0==.
_ballX::
	.ds 1
G$ballY$0$0==.
_ballY::
	.ds 1
G$velX$0$0==.
_velX::
	.ds 1
G$velY$0$0==.
_velY::
	.ds 1
Lpong.updateBall$str$1$56==.
_updateBall_str_1_56:
	.ds 20
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	C$pong.c$39$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:39: char pixel = '\333';
	mov	_pixel,#0xdb
	C$pong.c$41$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:41: char screenWidth = 80;
	mov	_screenWidth,#0x50
	C$pong.c$42$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:42: char screenHeight = 25;
	mov	_screenHeight,#0x19
	C$pong.c$44$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:44: char score1 = 0;
	mov	_score1,#0x00
	C$pong.c$45$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:45: char score2 = 0;
	mov	_score2,#0x00
	C$pong.c$47$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:47: char player1Pos = 10;
	mov	_player1Pos,#0x0a
	C$pong.c$49$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:49: char player2Pos = 10;
	mov	_player2Pos,#0x0a
	C$pong.c$51$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:51: char ballX = 40;
	mov	_ballX,#0x28
	C$pong.c$52$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:52: char ballY = 13;
	mov	_ballY,#0x0d
	C$pong.c$54$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:54: char velX = 0;
	mov	_velX,#0x00
	C$pong.c$55$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:55: char velY = 0;
	mov	_velY,#0x00
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'putchar'
;------------------------------------------------------------
;c                         Allocated to registers r7 
;------------------------------------------------------------
	G$putchar$0$0 ==.
	C$putget.h$20$0$0 ==.
;	C:\Users\John\Documents\MPS\lab1\/putget.h:20: void putchar(char c)
;	-----------------------------------------
;	 function putchar
;	-----------------------------------------
_putchar:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r7,dpl
	C$putget.h$22$1$15 ==.
;	C:\Users\John\Documents\MPS\lab1\/putget.h:22: while(!TI0); 
00101$:
	C$putget.h$23$1$15 ==.
;	C:\Users\John\Documents\MPS\lab1\/putget.h:23: TI0=0;
	jbc	_TI0,00112$
	sjmp	00101$
00112$:
	C$putget.h$24$1$15 ==.
;	C:\Users\John\Documents\MPS\lab1\/putget.h:24: SBUF0 = c;
	mov	_SBUF0,r7
	C$putget.h$25$1$15 ==.
	XG$putchar$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'getchar'
;------------------------------------------------------------
;c                         Allocated to registers 
;------------------------------------------------------------
	G$getchar$0$0 ==.
	C$putget.h$30$1$15 ==.
;	C:\Users\John\Documents\MPS\lab1\/putget.h:30: char getchar(void)
;	-----------------------------------------
;	 function getchar
;	-----------------------------------------
_getchar:
	C$putget.h$33$1$17 ==.
;	C:\Users\John\Documents\MPS\lab1\/putget.h:33: while(!RI0);
00101$:
	C$putget.h$34$1$17 ==.
;	C:\Users\John\Documents\MPS\lab1\/putget.h:34: RI0 =0;
	jbc	_RI0,00112$
	sjmp	00101$
00112$:
	C$putget.h$35$1$17 ==.
;	C:\Users\John\Documents\MPS\lab1\/putget.h:35: c = SBUF0;
	mov	a,_SBUF0
	C$putget.h$38$1$17 ==.
;	C:\Users\John\Documents\MPS\lab1\/putget.h:38: return SBUF0;
	mov	dpl,_SBUF0
	C$putget.h$39$1$17 ==.
	XG$getchar$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;input                     Allocated to registers 
;octal                     Allocated to registers 
;------------------------------------------------------------
	G$main$0$0 ==.
	C$pong.c$60$1$17 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:60: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	C$pong.c$66$1$48 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:66: WDTCN = 0xDE;                       // Disable the watchdog timer
	mov	_WDTCN,#0xde
	C$pong.c$67$1$48 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:67: WDTCN = 0xAD;
	mov	_WDTCN,#0xad
	C$pong.c$69$1$48 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:69: PORT_INIT();                        // Initialize the Crossbar and GPIO
	lcall	_PORT_INIT
	C$pong.c$70$1$48 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:70: SYSCLK_INIT();                      // Initialize the oscillator
	lcall	_SYSCLK_INIT
	C$pong.c$71$1$48 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:71: UART0_INIT();                       // Initialize UART0
	lcall	_UART0_INIT
	C$pong.c$73$1$48 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:73: SFRPAGE = UART0_PAGE;               // Direct output to UART0
	mov	_SFRPAGE,#0x00
	C$pong.c$75$1$48 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:75: printBorder();
	lcall	_printBorder
	C$pong.c$76$1$48 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:76: updateScore();
	lcall	_updateScore
	C$pong.c$78$1$48 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:78: while(1)
00102$:
	C$pong.c$80$2$49 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:80: updateBall();
	lcall	_updateBall
	C$pong.c$81$2$49 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:81: input = getchar();
	lcall	_getchar
	C$pong.c$82$2$49 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:82: updatePositions(input);
	lcall	_updatePositions
	sjmp	00102$
	C$pong.c$84$1$48 ==.
	XG$main$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'SYSCLK_INIT'
;------------------------------------------------------------
;i                         Allocated to registers r5 r6 
;SFRPAGE_SAVE              Allocated to registers r7 
;------------------------------------------------------------
	G$SYSCLK_INIT$0$0 ==.
	C$pong.c$92$1$48 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:92: void SYSCLK_INIT(void)
;	-----------------------------------------
;	 function SYSCLK_INIT
;	-----------------------------------------
_SYSCLK_INIT:
	C$pong.c$97$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:97: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
	mov	r7,_SFRPAGE
	C$pong.c$99$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:99: SFRPAGE = CONFIG_PAGE;
	mov	_SFRPAGE,#0x0f
	C$pong.c$100$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:100: OSCXCN  = 0x67;                     // Start ext osc with 22.1184MHz crystal
	mov	_OSCXCN,#0x67
	C$pong.c$101$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:101: for(i=0; i < 256; i++);             // Wait for the oscillator to start up
	mov	r5,#0x00
	mov	r6,#0x01
00111$:
	dec	r5
	cjne	r5,#0xff,00141$
	dec	r6
00141$:
	mov	a,r5
	orl	a,r6
	jnz	00111$
	C$pong.c$102$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:102: while(!(OSCXCN & 0x80));
00102$:
	mov	a,_OSCXCN
	jnb	acc.7,00102$
	C$pong.c$103$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:103: CLKSEL  = 0x01;
	mov	_CLKSEL,#0x01
	C$pong.c$104$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:104: OSCICN  = 0x00;
	mov	_OSCICN,#0x00
	C$pong.c$106$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:106: SFRPAGE = CONFIG_PAGE;
	mov	_SFRPAGE,#0x0f
	C$pong.c$107$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:107: PLL0CN  = 0x04;
	mov	_PLL0CN,#0x04
	C$pong.c$108$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:108: SFRPAGE = LEGACY_PAGE;
	mov	_SFRPAGE,#0x00
	C$pong.c$109$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:109: FLSCL   = 0x10;
	mov	_FLSCL,#0x10
	C$pong.c$110$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:110: SFRPAGE = CONFIG_PAGE;
	mov	_SFRPAGE,#0x0f
	C$pong.c$111$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:111: PLL0CN |= 0x01;
	orl	_PLL0CN,#0x01
	C$pong.c$112$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:112: PLL0DIV = 0x04;
	mov	_PLL0DIV,#0x04
	C$pong.c$113$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:113: PLL0FLT = 0x01;
	mov	_PLL0FLT,#0x01
	C$pong.c$114$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:114: PLL0MUL = 0x09;
	mov	_PLL0MUL,#0x09
	C$pong.c$115$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:115: for(i=0; i < 256; i++);
	mov	r5,#0x00
	mov	r6,#0x01
00114$:
	dec	r5
	cjne	r5,#0xff,00144$
	dec	r6
00144$:
	mov	a,r5
	orl	a,r6
	jnz	00114$
	C$pong.c$116$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:116: PLL0CN |= 0x02;
	orl	_PLL0CN,#0x02
	C$pong.c$117$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:117: while(!(PLL0CN & 0x10));
00106$:
	mov	a,_PLL0CN
	jnb	acc.4,00106$
	C$pong.c$118$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:118: CLKSEL  = 0x02;
	mov	_CLKSEL,#0x02
	C$pong.c$120$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:120: SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
	mov	_SFRPAGE,r7
	C$pong.c$121$1$51 ==.
	XG$SYSCLK_INIT$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'PORT_INIT'
;------------------------------------------------------------
;SFRPAGE_SAVE              Allocated to registers r7 
;------------------------------------------------------------
	G$PORT_INIT$0$0 ==.
	C$pong.c$129$1$51 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:129: void PORT_INIT(void)
;	-----------------------------------------
;	 function PORT_INIT
;	-----------------------------------------
_PORT_INIT:
	C$pong.c$133$1$53 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:133: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
	mov	r7,_SFRPAGE
	C$pong.c$135$1$53 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:135: SFRPAGE  = CONFIG_PAGE;
	mov	_SFRPAGE,#0x0f
	C$pong.c$136$1$53 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:136: XBR0     = 0x04;                    // Enable UART0
	mov	_XBR0,#0x04
	C$pong.c$137$1$53 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:137: XBR1     = 0x00;
	mov	_XBR1,#0x00
	C$pong.c$138$1$53 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:138: XBR2     = 0x40;                    // Enable Crossbar and weak pull-up
	mov	_XBR2,#0x40
	C$pong.c$139$1$53 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:139: P0MDOUT |= 0x01;                    // Set TX0 on P0.0 pin to push-pull
	orl	_P0MDOUT,#0x01
	C$pong.c$140$1$53 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:140: P1MDOUT |= 0x40;                    // Set green LED output P1.6 to push-pull
	orl	_P1MDOUT,#0x40
	C$pong.c$142$1$53 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:142: SFRPAGE  = SFRPAGE_SAVE;            // Restore SFR page
	mov	_SFRPAGE,r7
	C$pong.c$143$1$53 ==.
	XG$PORT_INIT$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART0_INIT'
;------------------------------------------------------------
;SFRPAGE_SAVE              Allocated to registers r7 
;------------------------------------------------------------
	G$UART0_INIT$0$0 ==.
	C$pong.c$151$1$53 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:151: void UART0_INIT(void)
;	-----------------------------------------
;	 function UART0_INIT
;	-----------------------------------------
_UART0_INIT:
	C$pong.c$155$1$55 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:155: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
	mov	r7,_SFRPAGE
	C$pong.c$157$1$55 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:157: SFRPAGE = TIMER01_PAGE;
	mov	_SFRPAGE,#0x00
	C$pong.c$158$1$55 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:158: TMOD   &= ~0xF0;
	anl	_TMOD,#0x0f
	C$pong.c$159$1$55 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:159: TMOD   |=  0x20;                    // Timer1, Mode 2, 8-bit reload
	orl	_TMOD,#0x20
	C$pong.c$160$1$55 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:160: TH1     = -(SYSCLK/BAUDRATE/16);    // Set Timer1 reload baudrate value T1 Hi Byte
	mov	_TH1,#0xe5
	C$pong.c$161$1$55 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:161: CKCON  |= 0x10;                     // Timer1 uses SYSCLK as time base
	orl	_CKCON,#0x10
	C$pong.c$162$1$55 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:162: TL1     = TH1;
	mov	_TL1,_TH1
	C$pong.c$163$1$55 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:163: TR1     = 1;                        // Start Timer1
	setb	_TR1
	C$pong.c$165$1$55 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:165: SFRPAGE = UART0_PAGE;
	mov	_SFRPAGE,#0x00
	C$pong.c$166$1$55 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:166: SCON0   = 0x50;                     // Mode 1, 8-bit UART, enable RX
	mov	_SCON0,#0x50
	C$pong.c$167$1$55 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:167: SSTA0   = 0x10;                     // SMOD0 = 1
	mov	_SSTA0,#0x10
	C$pong.c$168$1$55 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:168: TI0     = 1;                        // Indicate TX0 ready
	setb	_TI0
	C$pong.c$170$1$55 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:170: SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
	mov	_SFRPAGE,r7
	C$pong.c$171$1$55 ==.
	XG$UART0_INIT$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'updateBall'
;------------------------------------------------------------
;str                       Allocated with name '_updateBall_str_1_56'
;lastX                     Allocated to registers 
;lastY                     Allocated to registers 
;tenthsX                   Allocated to registers r7 
;onesX                     Allocated to registers r6 
;tenthsY                   Allocated to registers r5 
;onesY                     Allocated to registers r4 
;------------------------------------------------------------
	G$updateBall$0$0 ==.
	C$pong.c$173$1$55 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:173: void updateBall(){
;	-----------------------------------------
;	 function updateBall
;	-----------------------------------------
_updateBall:
	C$pong.c$180$1$56 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:180: char tenthsX = '0'+(ballX/10);
	mov	b,#0x0a
	mov	a,_ballX
	div	ab
	add	a,#0x30
	mov	r7,a
	C$pong.c$181$1$56 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:181: char onesX = '0'+(ballX%10);
	mov	b,#0x0a
	mov	a,_ballX
	div	ab
	mov	r6,b
	mov	a,#0x30
	add	a,r6
	mov	r6,a
	C$pong.c$183$1$56 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:183: char tenthsY = '0'+(ballY/10);
	mov	b,#0x0a
	mov	a,_ballY
	div	ab
	add	a,#0x30
	mov	r5,a
	C$pong.c$184$1$56 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:184: char onesY = '0'+(ballY%10);
	mov	b,#0x0a
	mov	a,_ballY
	div	ab
	mov	r4,b
	mov	a,#0x30
	add	a,r4
	mov	r4,a
	C$pong.c$187$1$56 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:187: strcpy(str, "\033[__;__H");
	mov	_strcpy_PARM_2,#___str_0
	mov	(_strcpy_PARM_2 + 1),#(___str_0 >> 8)
	mov	(_strcpy_PARM_2 + 2),#0x80
	mov	dptr,#_updateBall_str_1_56
	mov	b,#0x40
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	lcall	_strcpy
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	C$pong.c$189$1$56 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:189: str[2] = tenthsY;
	mov	(_updateBall_str_1_56 + 0x0002),r5
	C$pong.c$190$1$56 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:190: str[3] = onesY;
	mov	(_updateBall_str_1_56 + 0x0003),r4
	C$pong.c$191$1$56 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:191: str[5] = tenthsX;
	mov	(_updateBall_str_1_56 + 0x0005),r7
	C$pong.c$192$1$56 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:192: str[6] = onesX;
	mov	(_updateBall_str_1_56 + 0x0006),r6
	C$pong.c$194$1$56 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:194: printf(str);
	mov	a,#_updateBall_str_1_56
	push	acc
	mov	a,#(_updateBall_str_1_56 >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	C$pong.c$195$1$56 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:195: printf("%c%c",pixel,pixel);
	mov	r6,_pixel
	mov	r7,#0x00
	push	ar6
	push	ar7
	push	ar6
	push	ar7
	mov	a,#___str_1
	push	acc
	mov	a,#(___str_1 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
	C$pong.c$197$1$56 ==.
	XG$updateBall$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'updatePositions'
;------------------------------------------------------------
;input                     Allocated to registers r7 
;------------------------------------------------------------
	G$updatePositions$0$0 ==.
	C$pong.c$199$1$56 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:199: void updatePositions(char input){
;	-----------------------------------------
;	 function updatePositions
;	-----------------------------------------
_updatePositions:
	mov	r7,dpl
	C$pong.c$200$1$58 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:200: if(input == '\167'){ //w
	cjne	r7,#0x77,00104$
	C$pong.c$201$2$59 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:201: player1Pos--;
	dec	_player1Pos
	C$pong.c$202$2$59 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:202: if(player1Pos<1){
	mov	a,#0x100 - 0x01
	add	a,_player1Pos
	jc	00104$
	C$pong.c$203$3$60 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:203: player1Pos = 1;
	mov	_player1Pos,#0x01
00104$:
	C$pong.c$207$1$58 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:207: if(input == '\163'){ //s
	cjne	r7,#0x73,00108$
	C$pong.c$208$2$61 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:208: player1Pos++;
	inc	_player1Pos
	C$pong.c$209$2$61 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:209: if(player1Pos>20){
	mov	a,_player1Pos
	add	a,#0xff - 0x14
	jnc	00108$
	C$pong.c$210$3$62 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:210: player1Pos = 20;
	mov	_player1Pos,#0x14
00108$:
	C$pong.c$214$1$58 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:214: if(input == '\157'){ //o
	cjne	r7,#0x6f,00112$
	C$pong.c$215$2$63 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:215: player2Pos--;
	dec	_player2Pos
	C$pong.c$216$2$63 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:216: if(player2Pos<1){
	mov	a,#0x100 - 0x01
	add	a,_player2Pos
	jc	00112$
	C$pong.c$217$3$64 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:217: player2Pos = 1;
	mov	_player2Pos,#0x01
00112$:
	C$pong.c$221$1$58 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:221: if(input == '\154'){ //l
	cjne	r7,#0x6c,00116$
	C$pong.c$222$2$65 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:222: player2Pos++;
	inc	_player2Pos
	C$pong.c$223$2$65 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:223: if(player2Pos>20){
	mov	a,_player2Pos
	add	a,#0xff - 0x14
	jnc	00116$
	C$pong.c$224$3$66 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:224: player2Pos = 20;
	mov	_player2Pos,#0x14
00116$:
	C$pong.c$228$1$58 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:228: printPlayers();
	lcall	_printPlayers
	C$pong.c$229$1$58 ==.
	XG$updatePositions$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'printPlayers'
;------------------------------------------------------------
;i                         Allocated to registers r7 
;------------------------------------------------------------
	G$printPlayers$0$0 ==.
	C$pong.c$232$1$58 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:232: void printPlayers(){
;	-----------------------------------------
;	 function printPlayers
;	-----------------------------------------
_printPlayers:
	C$pong.c$241$1$67 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:241: printf("\033[1;2H");
	mov	a,#___str_2
	push	acc
	mov	a,#(___str_2 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	C$pong.c$243$1$67 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:243: for( i = 1; i <= screenHeight; i++){ //5 is player size
	mov	r7,#0x01
00116$:
	clr	c
	mov	a,_screenHeight
	subb	a,r7
	jnc	00155$
	ljmp	00107$
00155$:
	C$pong.c$244$2$68 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:244: if(i != 1){
	cjne	r7,#0x01,00156$
	sjmp	00102$
00156$:
	C$pong.c$245$3$69 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:245: printf("\n");
	push	ar7
	mov	a,#___str_3
	push	acc
	mov	a,#(___str_3 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar7
00102$:
	C$pong.c$247$2$68 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:247: printf("\r");
	push	ar7
	mov	a,#___str_4
	push	acc
	mov	a,#(___str_4 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	C$pong.c$248$2$68 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:248: printf("\033[1C");
	mov	a,#___str_5
	push	acc
	mov	a,#(___str_5 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar7
	C$pong.c$249$2$68 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:249: if(i >= player1Pos && i <= player1Pos+5){
	clr	c
	mov	a,r7
	subb	a,_player1Pos
	jc	00104$
	mov	r5,_player1Pos
	mov	r6,#0x00
	mov	a,#0x05
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	ar3,r7
	mov	r4,#0x00
	clr	c
	mov	a,r5
	subb	a,r3
	mov	a,r6
	xrl	a,#0x80
	mov	b,r4
	xrl	b,#0x80
	subb	a,b
	jc	00104$
	C$pong.c$250$3$70 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:250: printf("%c",pixel);
	mov	r5,_pixel
	mov	r6,#0x00
	push	ar7
	push	ar5
	push	ar6
	mov	a,#___str_6
	push	acc
	mov	a,#(___str_6 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	pop	ar7
	sjmp	00117$
00104$:
	C$pong.c$252$3$71 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:252: printf(" ");
	push	ar7
	mov	a,#___str_7
	push	acc
	mov	a,#(___str_7 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar7
00117$:
	C$pong.c$243$1$67 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:243: for( i = 1; i <= screenHeight; i++){ //5 is player size
	inc	r7
	ljmp	00116$
00107$:
	C$pong.c$257$1$67 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:257: printf("\033[1;78H");
	mov	a,#___str_8
	push	acc
	mov	a,#(___str_8 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	C$pong.c$259$1$67 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:259: for( i = 1; i <= screenHeight; i++){ //5 is player size
	mov	r7,#0x01
00119$:
	clr	c
	mov	a,_screenHeight
	subb	a,r7
	jnc	00159$
	ljmp	00121$
00159$:
	C$pong.c$260$2$72 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:260: if(i != 1){
	cjne	r7,#0x01,00160$
	sjmp	00109$
00160$:
	C$pong.c$261$3$73 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:261: printf("\n");
	push	ar7
	mov	a,#___str_3
	push	acc
	mov	a,#(___str_3 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar7
00109$:
	C$pong.c$263$2$72 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:263: printf("\r");
	push	ar7
	mov	a,#___str_4
	push	acc
	mov	a,#(___str_4 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	C$pong.c$264$2$72 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:264: printf("\033[77C");
	mov	a,#___str_9
	push	acc
	mov	a,#(___str_9 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar7
	C$pong.c$265$2$72 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:265: if(i >= player2Pos && i <= player2Pos+5){
	clr	c
	mov	a,r7
	subb	a,_player2Pos
	jc	00111$
	mov	r5,_player2Pos
	mov	r6,#0x00
	mov	a,#0x05
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	ar3,r7
	mov	r4,#0x00
	clr	c
	mov	a,r5
	subb	a,r3
	mov	a,r6
	xrl	a,#0x80
	mov	b,r4
	xrl	b,#0x80
	subb	a,b
	jc	00111$
	C$pong.c$266$3$74 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:266: printf("%c",pixel);
	mov	r5,_pixel
	mov	r6,#0x00
	push	ar7
	push	ar5
	push	ar6
	mov	a,#___str_6
	push	acc
	mov	a,#(___str_6 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	pop	ar7
	sjmp	00120$
00111$:
	C$pong.c$268$3$75 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:268: printf(" ");
	push	ar7
	mov	a,#___str_7
	push	acc
	mov	a,#(___str_7 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar7
00120$:
	C$pong.c$259$1$67 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:259: for( i = 1; i <= screenHeight; i++){ //5 is player size
	inc	r7
	ljmp	00119$
00121$:
	C$pong.c$271$1$67 ==.
	XG$printPlayers$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'printBorder'
;------------------------------------------------------------
;i                         Allocated to registers 
;------------------------------------------------------------
	G$printBorder$0$0 ==.
	C$pong.c$273$1$67 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:273: void printBorder(){
;	-----------------------------------------
;	 function printBorder
;	-----------------------------------------
_printBorder:
	C$pong.c$276$1$76 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:276: printf("\033[37;40m");              // White text; black background
	mov	a,#___str_10
	push	acc
	mov	a,#(___str_10 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	C$pong.c$277$1$76 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:277: printf("\033[2J");                  // Erase screen & move cursor to home position
	mov	a,#___str_11
	push	acc
	mov	a,#(___str_11 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	C$pong.c$308$1$76 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:308: printf("\033[1;40H");
	mov	a,#___str_12
	push	acc
	mov	a,#(___str_12 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	C$pong.c$309$1$76 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:309: for(i = 1; i < screenHeight; i++){
	mov	r7,#0x01
00103$:
	clr	c
	mov	a,r7
	subb	a,_screenHeight
	jnc	00101$
	C$pong.c$310$2$77 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:310: printf("|\n\r");
	push	ar7
	mov	a,#___str_13
	push	acc
	mov	a,#(___str_13 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	C$pong.c$311$2$77 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:311: printf("\033[39C");
	mov	a,#___str_14
	push	acc
	mov	a,#(___str_14 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar7
	C$pong.c$309$1$76 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:309: for(i = 1; i < screenHeight; i++){
	inc	r7
	sjmp	00103$
00101$:
	C$pong.c$313$1$76 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:313: printf("|");
	mov	a,#___str_15
	push	acc
	mov	a,#(___str_15 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	C$pong.c$315$1$76 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:315: printPlayers();
	lcall	_printPlayers
	C$pong.c$318$1$76 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:318: printf("\033[?25l");
	mov	a,#___str_16
	push	acc
	mov	a,#(___str_16 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	C$pong.c$326$1$76 ==.
	XG$printBorder$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'updateScore'
;------------------------------------------------------------
	G$updateScore$0$0 ==.
	C$pong.c$328$1$76 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:328: void updateScore(){
;	-----------------------------------------
;	 function updateScore
;	-----------------------------------------
_updateScore:
	C$pong.c$330$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:330: printf("\033[2;35H");
	mov	a,#___str_17
	push	acc
	mov	a,#(___str_17 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	C$pong.c$331$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:331: printf("%c",score1);
	mov	r6,_score1
	mov	r7,#0x00
	push	ar6
	push	ar7
	mov	a,#___str_6
	push	acc
	mov	a,#(___str_6 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	C$pong.c$334$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:334: printf("\033[2;45H");
	mov	a,#___str_18
	push	acc
	mov	a,#(___str_18 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	C$pong.c$335$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:335: printf("%c",score2);
	mov	r6,_score2
	mov	r7,#0x00
	push	ar6
	push	ar7
	mov	a,#___str_6
	push	acc
	mov	a,#(___str_6 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	C$pong.c$336$1$78 ==.
	XG$updateScore$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'printWinner'
;------------------------------------------------------------
	G$printWinner$0$0 ==.
	C$pong.c$338$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:338: void printWinner(){
;	-----------------------------------------
;	 function printWinner
;	-----------------------------------------
_printWinner:
	C$pong.c$341$1$78 ==.
;	C:\Users\John\Documents\MPS\lab1\pong.c:341: }
	C$pong.c$341$1$78 ==.
	XG$printWinner$0$0 ==.
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
Fpong$__str_0$0$0 == .
___str_0:
	.db 0x1b
	.ascii "[__;__H"
	.db 0x00
Fpong$__str_1$0$0 == .
___str_1:
	.ascii "%c%c"
	.db 0x00
Fpong$__str_2$0$0 == .
___str_2:
	.db 0x1b
	.ascii "[1;2H"
	.db 0x00
Fpong$__str_3$0$0 == .
___str_3:
	.db 0x0a
	.db 0x00
Fpong$__str_4$0$0 == .
___str_4:
	.db 0x0d
	.db 0x00
Fpong$__str_5$0$0 == .
___str_5:
	.db 0x1b
	.ascii "[1C"
	.db 0x00
Fpong$__str_6$0$0 == .
___str_6:
	.ascii "%c"
	.db 0x00
Fpong$__str_7$0$0 == .
___str_7:
	.ascii " "
	.db 0x00
Fpong$__str_8$0$0 == .
___str_8:
	.db 0x1b
	.ascii "[1;78H"
	.db 0x00
Fpong$__str_9$0$0 == .
___str_9:
	.db 0x1b
	.ascii "[77C"
	.db 0x00
Fpong$__str_10$0$0 == .
___str_10:
	.db 0x1b
	.ascii "[37;40m"
	.db 0x00
Fpong$__str_11$0$0 == .
___str_11:
	.db 0x1b
	.ascii "[2J"
	.db 0x00
Fpong$__str_12$0$0 == .
___str_12:
	.db 0x1b
	.ascii "[1;40H"
	.db 0x00
Fpong$__str_13$0$0 == .
___str_13:
	.ascii "|"
	.db 0x0a
	.db 0x0d
	.db 0x00
Fpong$__str_14$0$0 == .
___str_14:
	.db 0x1b
	.ascii "[39C"
	.db 0x00
Fpong$__str_15$0$0 == .
___str_15:
	.ascii "|"
	.db 0x00
Fpong$__str_16$0$0 == .
___str_16:
	.db 0x1b
	.ascii "[?25l"
	.db 0x00
Fpong$__str_17$0$0 == .
___str_17:
	.db 0x1b
	.ascii "[2;35H"
	.db 0x00
Fpong$__str_18$0$0 == .
___str_18:
	.db 0x1b
	.ascii "[2;45H"
	.db 0x00
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
