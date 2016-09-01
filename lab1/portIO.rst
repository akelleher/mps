                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW32)
                                      4 ;--------------------------------------------------------
                                      5 	.module portIO
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _printf
                                     12 	.globl _P2_7
                                     13 	.globl _P2_6
                                     14 	.globl _P2_5
                                     15 	.globl _P2_4
                                     16 	.globl _P2_3
                                     17 	.globl _P2_2
                                     18 	.globl _P2_1
                                     19 	.globl _P2_0
                                     20 	.globl _P1_7
                                     21 	.globl _P1_6
                                     22 	.globl _P1_5
                                     23 	.globl _P1_4
                                     24 	.globl _P1_3
                                     25 	.globl _P1_2
                                     26 	.globl _P1_1
                                     27 	.globl _P1_0
                                     28 	.globl _P7_7
                                     29 	.globl _P7_6
                                     30 	.globl _P7_5
                                     31 	.globl _P7_4
                                     32 	.globl _P7_3
                                     33 	.globl _P7_2
                                     34 	.globl _P7_1
                                     35 	.globl _P7_0
                                     36 	.globl _SPIF
                                     37 	.globl _WCOL
                                     38 	.globl _MODF
                                     39 	.globl _RXOVRN
                                     40 	.globl _NSSMD1
                                     41 	.globl _NSSMD0
                                     42 	.globl _TXBMT
                                     43 	.globl _SPIEN
                                     44 	.globl _P6_7
                                     45 	.globl _P6_6
                                     46 	.globl _P6_5
                                     47 	.globl _P6_4
                                     48 	.globl _P6_3
                                     49 	.globl _P6_2
                                     50 	.globl _P6_1
                                     51 	.globl _P6_0
                                     52 	.globl _AD2EN
                                     53 	.globl _AD2TM
                                     54 	.globl _AD2INT
                                     55 	.globl _AD2BUSY
                                     56 	.globl _AD2CM2
                                     57 	.globl _AD2CM1
                                     58 	.globl _AD2CM0
                                     59 	.globl _AD2WINT
                                     60 	.globl _AD0EN
                                     61 	.globl _AD0TM
                                     62 	.globl _AD0INT
                                     63 	.globl _AD0BUSY
                                     64 	.globl _AD0CM1
                                     65 	.globl _AD0CM0
                                     66 	.globl _AD0WINT
                                     67 	.globl _AD0LJST
                                     68 	.globl _P5_7
                                     69 	.globl _P5_6
                                     70 	.globl _P5_5
                                     71 	.globl _P5_4
                                     72 	.globl _P5_3
                                     73 	.globl _P5_2
                                     74 	.globl _P5_1
                                     75 	.globl _P5_0
                                     76 	.globl _CF
                                     77 	.globl _CR
                                     78 	.globl _CCF5
                                     79 	.globl _CCF4
                                     80 	.globl _CCF3
                                     81 	.globl _CCF2
                                     82 	.globl _CCF1
                                     83 	.globl _CCF0
                                     84 	.globl _CY
                                     85 	.globl _AC
                                     86 	.globl _F0
                                     87 	.globl _RS1
                                     88 	.globl _RS0
                                     89 	.globl _OV
                                     90 	.globl _F1
                                     91 	.globl _P
                                     92 	.globl _P4_7
                                     93 	.globl _P4_6
                                     94 	.globl _P4_5
                                     95 	.globl _P4_4
                                     96 	.globl _P4_3
                                     97 	.globl _P4_2
                                     98 	.globl _P4_1
                                     99 	.globl _P4_0
                                    100 	.globl _TF4
                                    101 	.globl _EXF4
                                    102 	.globl _EXEN4
                                    103 	.globl _TR4
                                    104 	.globl _CT4
                                    105 	.globl _CPRL4
                                    106 	.globl _TF3
                                    107 	.globl _EXF3
                                    108 	.globl _EXEN3
                                    109 	.globl _TR3
                                    110 	.globl _CT3
                                    111 	.globl _CPRL3
                                    112 	.globl _TF2
                                    113 	.globl _EXF2
                                    114 	.globl _EXEN2
                                    115 	.globl _TR2
                                    116 	.globl _CT2
                                    117 	.globl _CPRL2
                                    118 	.globl _MAC0HO
                                    119 	.globl _MAC0Z
                                    120 	.globl _MAC0SO
                                    121 	.globl _MAC0N
                                    122 	.globl _BUSY
                                    123 	.globl _ENSMB
                                    124 	.globl _STA
                                    125 	.globl _STO
                                    126 	.globl _SI
                                    127 	.globl _AA
                                    128 	.globl _SMBFTE
                                    129 	.globl _SMBTOE
                                    130 	.globl _PT2
                                    131 	.globl _PS
                                    132 	.globl _PS0
                                    133 	.globl _PT1
                                    134 	.globl _PX1
                                    135 	.globl _PT0
                                    136 	.globl _PX0
                                    137 	.globl _P3_7
                                    138 	.globl _P3_6
                                    139 	.globl _P3_5
                                    140 	.globl _P3_4
                                    141 	.globl _P3_3
                                    142 	.globl _P3_2
                                    143 	.globl _P3_1
                                    144 	.globl _P3_0
                                    145 	.globl _EA
                                    146 	.globl _ET2
                                    147 	.globl _ES
                                    148 	.globl _ES0
                                    149 	.globl _ET1
                                    150 	.globl _EX1
                                    151 	.globl _ET0
                                    152 	.globl _EX0
                                    153 	.globl _S1MODE
                                    154 	.globl _MCE1
                                    155 	.globl _REN1
                                    156 	.globl _TB81
                                    157 	.globl _RB81
                                    158 	.globl _TI1
                                    159 	.globl _RI1
                                    160 	.globl _SM00
                                    161 	.globl _SM10
                                    162 	.globl _SM20
                                    163 	.globl _REN
                                    164 	.globl _REN0
                                    165 	.globl _TB80
                                    166 	.globl _RB80
                                    167 	.globl _TI
                                    168 	.globl _TI0
                                    169 	.globl _RI
                                    170 	.globl _RI0
                                    171 	.globl _FLHBUSY
                                    172 	.globl _CP1EN
                                    173 	.globl _CP1OUT
                                    174 	.globl _CP1RIF
                                    175 	.globl _CP1FIF
                                    176 	.globl _CP1HYP1
                                    177 	.globl _CP1HYP0
                                    178 	.globl _CP1HYN1
                                    179 	.globl _CP1HYN0
                                    180 	.globl _CP0EN
                                    181 	.globl _CP0OUT
                                    182 	.globl _CP0RIF
                                    183 	.globl _CP0FIF
                                    184 	.globl _CP0HYP1
                                    185 	.globl _CP0HYP0
                                    186 	.globl _CP0HYN1
                                    187 	.globl _CP0HYN0
                                    188 	.globl _TF1
                                    189 	.globl _TR1
                                    190 	.globl _TF0
                                    191 	.globl _TR0
                                    192 	.globl _IE1
                                    193 	.globl _IT1
                                    194 	.globl _IE0
                                    195 	.globl _IT0
                                    196 	.globl _P0_7
                                    197 	.globl _P0_6
                                    198 	.globl _P0_5
                                    199 	.globl _P0_4
                                    200 	.globl _P0_3
                                    201 	.globl _P0_2
                                    202 	.globl _P0_1
                                    203 	.globl _P0_0
                                    204 	.globl _MAC0RND
                                    205 	.globl _MAC0ACC
                                    206 	.globl _MAC0A
                                    207 	.globl _RCAP4
                                    208 	.globl _TMR4
                                    209 	.globl _DAC1
                                    210 	.globl _RCAP3
                                    211 	.globl _TMR3
                                    212 	.globl _PCA0CP5
                                    213 	.globl _PCA0CP4
                                    214 	.globl _PCA0CP3
                                    215 	.globl _PCA0CP2
                                    216 	.globl _PCA0CP1
                                    217 	.globl _PCA0CP0
                                    218 	.globl _PCA0
                                    219 	.globl _DAC0
                                    220 	.globl _ADC0LT
                                    221 	.globl _ADC0GT
                                    222 	.globl _ADC0
                                    223 	.globl _RCAP2
                                    224 	.globl _TMR2
                                    225 	.globl _TMR1
                                    226 	.globl _TMR0
                                    227 	.globl _P7
                                    228 	.globl _P6
                                    229 	.globl _XBR2
                                    230 	.globl _XBR1
                                    231 	.globl _XBR0
                                    232 	.globl _P5
                                    233 	.globl _P4
                                    234 	.globl _FLACL
                                    235 	.globl _P1MDIN
                                    236 	.globl _P3MDOUT
                                    237 	.globl _P2MDOUT
                                    238 	.globl _P1MDOUT
                                    239 	.globl _P0MDOUT
                                    240 	.globl _CCH0LC
                                    241 	.globl _CCH0TN
                                    242 	.globl _CCH0CN
                                    243 	.globl _P7MDOUT
                                    244 	.globl _P6MDOUT
                                    245 	.globl _P5MDOUT
                                    246 	.globl _P4MDOUT
                                    247 	.globl _CCH0MA
                                    248 	.globl _CLKSEL
                                    249 	.globl _SFRPGCN
                                    250 	.globl _PLL0FLT
                                    251 	.globl _PLL0MUL
                                    252 	.globl _PLL0DIV
                                    253 	.globl _OSCXCN
                                    254 	.globl _OSCICL
                                    255 	.globl _OSCICN
                                    256 	.globl _PLL0CN
                                    257 	.globl _FLSTAT
                                    258 	.globl _MAC0RNDH
                                    259 	.globl _MAC0RNDL
                                    260 	.globl _MAC0CF
                                    261 	.globl _MAC0AH
                                    262 	.globl _MAC0AL
                                    263 	.globl _MAC0STA
                                    264 	.globl _MAC0OVR
                                    265 	.globl _MAC0ACC3
                                    266 	.globl _MAC0ACC2
                                    267 	.globl _MAC0ACC1
                                    268 	.globl _MAC0ACC0
                                    269 	.globl _MAC0BH
                                    270 	.globl _MAC0BL
                                    271 	.globl _ADC2CN
                                    272 	.globl _TMR4H
                                    273 	.globl _TMR4L
                                    274 	.globl _RCAP4H
                                    275 	.globl _RCAP4L
                                    276 	.globl _TMR4CF
                                    277 	.globl _TMR4CN
                                    278 	.globl _ADC2LT
                                    279 	.globl _ADC2GT
                                    280 	.globl _ADC2
                                    281 	.globl _ADC2CF
                                    282 	.globl _AMX2SL
                                    283 	.globl _AMX2CF
                                    284 	.globl _CPT1MD
                                    285 	.globl _CPT1CN
                                    286 	.globl _DAC1CN
                                    287 	.globl _DAC1H
                                    288 	.globl _DAC1L
                                    289 	.globl _TMR3H
                                    290 	.globl _TMR3L
                                    291 	.globl _RCAP3H
                                    292 	.globl _RCAP3L
                                    293 	.globl _TMR3CF
                                    294 	.globl _TMR3CN
                                    295 	.globl _SBUF1
                                    296 	.globl _SCON1
                                    297 	.globl _CPT0MD
                                    298 	.globl _CPT0CN
                                    299 	.globl _PCA0CPH1
                                    300 	.globl _PCA0CPL1
                                    301 	.globl _PCA0CPH0
                                    302 	.globl _PCA0CPL0
                                    303 	.globl _PCA0H
                                    304 	.globl _PCA0L
                                    305 	.globl _SPI0CN
                                    306 	.globl _RSTSRC
                                    307 	.globl _PCA0CPH4
                                    308 	.globl _PCA0CPL4
                                    309 	.globl _PCA0CPH3
                                    310 	.globl _PCA0CPL3
                                    311 	.globl _PCA0CPH2
                                    312 	.globl _PCA0CPL2
                                    313 	.globl _ADC0CN
                                    314 	.globl _PCA0CPH5
                                    315 	.globl _PCA0CPL5
                                    316 	.globl _PCA0CPM5
                                    317 	.globl _PCA0CPM4
                                    318 	.globl _PCA0CPM3
                                    319 	.globl _PCA0CPM2
                                    320 	.globl _PCA0CPM1
                                    321 	.globl _PCA0CPM0
                                    322 	.globl _PCA0MD
                                    323 	.globl _PCA0CN
                                    324 	.globl _DAC0CN
                                    325 	.globl _DAC0H
                                    326 	.globl _DAC0L
                                    327 	.globl _REF0CN
                                    328 	.globl _SMB0CR
                                    329 	.globl _TH2
                                    330 	.globl _TMR2H
                                    331 	.globl _TL2
                                    332 	.globl _TMR2L
                                    333 	.globl _RCAP2H
                                    334 	.globl _RCAP2L
                                    335 	.globl _TMR2CF
                                    336 	.globl _TMR2CN
                                    337 	.globl _ADC0LTH
                                    338 	.globl _ADC0LTL
                                    339 	.globl _ADC0GTH
                                    340 	.globl _ADC0GTL
                                    341 	.globl _SMB0ADR
                                    342 	.globl _SMB0DAT
                                    343 	.globl _SMB0STA
                                    344 	.globl _SMB0CN
                                    345 	.globl _ADC0H
                                    346 	.globl _ADC0L
                                    347 	.globl _ADC0CF
                                    348 	.globl _AMX0SL
                                    349 	.globl _AMX0CF
                                    350 	.globl _SADEN0
                                    351 	.globl _FLSCL
                                    352 	.globl _SADDR0
                                    353 	.globl _EMI0CF
                                    354 	.globl __XPAGE
                                    355 	.globl _EMI0CN
                                    356 	.globl _EMI0TC
                                    357 	.globl _SPI0CKR
                                    358 	.globl _SPI0DAT
                                    359 	.globl _SPI0CFG
                                    360 	.globl _SBUF
                                    361 	.globl _SBUF0
                                    362 	.globl _SCON
                                    363 	.globl _SCON0
                                    364 	.globl _SSTA0
                                    365 	.globl _PSCTL
                                    366 	.globl _CKCON
                                    367 	.globl _TH1
                                    368 	.globl _TH0
                                    369 	.globl _TL1
                                    370 	.globl _TL0
                                    371 	.globl _TMOD
                                    372 	.globl _TCON
                                    373 	.globl _WDTCN
                                    374 	.globl _EIP2
                                    375 	.globl _EIP1
                                    376 	.globl _B
                                    377 	.globl _EIE2
                                    378 	.globl _EIE1
                                    379 	.globl _ACC
                                    380 	.globl _PSW
                                    381 	.globl _IP
                                    382 	.globl _PSBANK
                                    383 	.globl _P3
                                    384 	.globl _IE
                                    385 	.globl _P2
                                    386 	.globl _P1
                                    387 	.globl _PCON
                                    388 	.globl _SFRLAST
                                    389 	.globl _SFRNEXT
                                    390 	.globl _SFRPAGE
                                    391 	.globl _DPH
                                    392 	.globl _DPL
                                    393 	.globl _SP
                                    394 	.globl _P0
                                    395 	.globl _putchar
                                    396 	.globl _getchar
                                    397 	.globl _main
                                    398 	.globl _SYSCLK_INIT
                                    399 	.globl _PORT_INIT
                                    400 	.globl _UART0_INIT
                                    401 ;--------------------------------------------------------
                                    402 ; special function registers
                                    403 ;--------------------------------------------------------
                                    404 	.area RSEG    (ABS,DATA)
      000000                        405 	.org 0x0000
                           000080   406 G$P0$0$0 == 0x0080
                           000080   407 _P0	=	0x0080
                           000081   408 G$SP$0$0 == 0x0081
                           000081   409 _SP	=	0x0081
                           000082   410 G$DPL$0$0 == 0x0082
                           000082   411 _DPL	=	0x0082
                           000083   412 G$DPH$0$0 == 0x0083
                           000083   413 _DPH	=	0x0083
                           000084   414 G$SFRPAGE$0$0 == 0x0084
                           000084   415 _SFRPAGE	=	0x0084
                           000085   416 G$SFRNEXT$0$0 == 0x0085
                           000085   417 _SFRNEXT	=	0x0085
                           000086   418 G$SFRLAST$0$0 == 0x0086
                           000086   419 _SFRLAST	=	0x0086
                           000087   420 G$PCON$0$0 == 0x0087
                           000087   421 _PCON	=	0x0087
                           000090   422 G$P1$0$0 == 0x0090
                           000090   423 _P1	=	0x0090
                           0000A0   424 G$P2$0$0 == 0x00a0
                           0000A0   425 _P2	=	0x00a0
                           0000A8   426 G$IE$0$0 == 0x00a8
                           0000A8   427 _IE	=	0x00a8
                           0000B0   428 G$P3$0$0 == 0x00b0
                           0000B0   429 _P3	=	0x00b0
                           0000B1   430 G$PSBANK$0$0 == 0x00b1
                           0000B1   431 _PSBANK	=	0x00b1
                           0000B8   432 G$IP$0$0 == 0x00b8
                           0000B8   433 _IP	=	0x00b8
                           0000D0   434 G$PSW$0$0 == 0x00d0
                           0000D0   435 _PSW	=	0x00d0
                           0000E0   436 G$ACC$0$0 == 0x00e0
                           0000E0   437 _ACC	=	0x00e0
                           0000E6   438 G$EIE1$0$0 == 0x00e6
                           0000E6   439 _EIE1	=	0x00e6
                           0000E7   440 G$EIE2$0$0 == 0x00e7
                           0000E7   441 _EIE2	=	0x00e7
                           0000F0   442 G$B$0$0 == 0x00f0
                           0000F0   443 _B	=	0x00f0
                           0000F6   444 G$EIP1$0$0 == 0x00f6
                           0000F6   445 _EIP1	=	0x00f6
                           0000F7   446 G$EIP2$0$0 == 0x00f7
                           0000F7   447 _EIP2	=	0x00f7
                           0000FF   448 G$WDTCN$0$0 == 0x00ff
                           0000FF   449 _WDTCN	=	0x00ff
                           000088   450 G$TCON$0$0 == 0x0088
                           000088   451 _TCON	=	0x0088
                           000089   452 G$TMOD$0$0 == 0x0089
                           000089   453 _TMOD	=	0x0089
                           00008A   454 G$TL0$0$0 == 0x008a
                           00008A   455 _TL0	=	0x008a
                           00008B   456 G$TL1$0$0 == 0x008b
                           00008B   457 _TL1	=	0x008b
                           00008C   458 G$TH0$0$0 == 0x008c
                           00008C   459 _TH0	=	0x008c
                           00008D   460 G$TH1$0$0 == 0x008d
                           00008D   461 _TH1	=	0x008d
                           00008E   462 G$CKCON$0$0 == 0x008e
                           00008E   463 _CKCON	=	0x008e
                           00008F   464 G$PSCTL$0$0 == 0x008f
                           00008F   465 _PSCTL	=	0x008f
                           000091   466 G$SSTA0$0$0 == 0x0091
                           000091   467 _SSTA0	=	0x0091
                           000098   468 G$SCON0$0$0 == 0x0098
                           000098   469 _SCON0	=	0x0098
                           000098   470 G$SCON$0$0 == 0x0098
                           000098   471 _SCON	=	0x0098
                           000099   472 G$SBUF0$0$0 == 0x0099
                           000099   473 _SBUF0	=	0x0099
                           000099   474 G$SBUF$0$0 == 0x0099
                           000099   475 _SBUF	=	0x0099
                           00009A   476 G$SPI0CFG$0$0 == 0x009a
                           00009A   477 _SPI0CFG	=	0x009a
                           00009B   478 G$SPI0DAT$0$0 == 0x009b
                           00009B   479 _SPI0DAT	=	0x009b
                           00009D   480 G$SPI0CKR$0$0 == 0x009d
                           00009D   481 _SPI0CKR	=	0x009d
                           0000A1   482 G$EMI0TC$0$0 == 0x00a1
                           0000A1   483 _EMI0TC	=	0x00a1
                           0000A2   484 G$EMI0CN$0$0 == 0x00a2
                           0000A2   485 _EMI0CN	=	0x00a2
                           0000A2   486 G$_XPAGE$0$0 == 0x00a2
                           0000A2   487 __XPAGE	=	0x00a2
                           0000A3   488 G$EMI0CF$0$0 == 0x00a3
                           0000A3   489 _EMI0CF	=	0x00a3
                           0000A9   490 G$SADDR0$0$0 == 0x00a9
                           0000A9   491 _SADDR0	=	0x00a9
                           0000B7   492 G$FLSCL$0$0 == 0x00b7
                           0000B7   493 _FLSCL	=	0x00b7
                           0000B9   494 G$SADEN0$0$0 == 0x00b9
                           0000B9   495 _SADEN0	=	0x00b9
                           0000BA   496 G$AMX0CF$0$0 == 0x00ba
                           0000BA   497 _AMX0CF	=	0x00ba
                           0000BB   498 G$AMX0SL$0$0 == 0x00bb
                           0000BB   499 _AMX0SL	=	0x00bb
                           0000BC   500 G$ADC0CF$0$0 == 0x00bc
                           0000BC   501 _ADC0CF	=	0x00bc
                           0000BE   502 G$ADC0L$0$0 == 0x00be
                           0000BE   503 _ADC0L	=	0x00be
                           0000BF   504 G$ADC0H$0$0 == 0x00bf
                           0000BF   505 _ADC0H	=	0x00bf
                           0000C0   506 G$SMB0CN$0$0 == 0x00c0
                           0000C0   507 _SMB0CN	=	0x00c0
                           0000C1   508 G$SMB0STA$0$0 == 0x00c1
                           0000C1   509 _SMB0STA	=	0x00c1
                           0000C2   510 G$SMB0DAT$0$0 == 0x00c2
                           0000C2   511 _SMB0DAT	=	0x00c2
                           0000C3   512 G$SMB0ADR$0$0 == 0x00c3
                           0000C3   513 _SMB0ADR	=	0x00c3
                           0000C4   514 G$ADC0GTL$0$0 == 0x00c4
                           0000C4   515 _ADC0GTL	=	0x00c4
                           0000C5   516 G$ADC0GTH$0$0 == 0x00c5
                           0000C5   517 _ADC0GTH	=	0x00c5
                           0000C6   518 G$ADC0LTL$0$0 == 0x00c6
                           0000C6   519 _ADC0LTL	=	0x00c6
                           0000C7   520 G$ADC0LTH$0$0 == 0x00c7
                           0000C7   521 _ADC0LTH	=	0x00c7
                           0000C8   522 G$TMR2CN$0$0 == 0x00c8
                           0000C8   523 _TMR2CN	=	0x00c8
                           0000C9   524 G$TMR2CF$0$0 == 0x00c9
                           0000C9   525 _TMR2CF	=	0x00c9
                           0000CA   526 G$RCAP2L$0$0 == 0x00ca
                           0000CA   527 _RCAP2L	=	0x00ca
                           0000CB   528 G$RCAP2H$0$0 == 0x00cb
                           0000CB   529 _RCAP2H	=	0x00cb
                           0000CC   530 G$TMR2L$0$0 == 0x00cc
                           0000CC   531 _TMR2L	=	0x00cc
                           0000CC   532 G$TL2$0$0 == 0x00cc
                           0000CC   533 _TL2	=	0x00cc
                           0000CD   534 G$TMR2H$0$0 == 0x00cd
                           0000CD   535 _TMR2H	=	0x00cd
                           0000CD   536 G$TH2$0$0 == 0x00cd
                           0000CD   537 _TH2	=	0x00cd
                           0000CF   538 G$SMB0CR$0$0 == 0x00cf
                           0000CF   539 _SMB0CR	=	0x00cf
                           0000D1   540 G$REF0CN$0$0 == 0x00d1
                           0000D1   541 _REF0CN	=	0x00d1
                           0000D2   542 G$DAC0L$0$0 == 0x00d2
                           0000D2   543 _DAC0L	=	0x00d2
                           0000D3   544 G$DAC0H$0$0 == 0x00d3
                           0000D3   545 _DAC0H	=	0x00d3
                           0000D4   546 G$DAC0CN$0$0 == 0x00d4
                           0000D4   547 _DAC0CN	=	0x00d4
                           0000D8   548 G$PCA0CN$0$0 == 0x00d8
                           0000D8   549 _PCA0CN	=	0x00d8
                           0000D9   550 G$PCA0MD$0$0 == 0x00d9
                           0000D9   551 _PCA0MD	=	0x00d9
                           0000DA   552 G$PCA0CPM0$0$0 == 0x00da
                           0000DA   553 _PCA0CPM0	=	0x00da
                           0000DB   554 G$PCA0CPM1$0$0 == 0x00db
                           0000DB   555 _PCA0CPM1	=	0x00db
                           0000DC   556 G$PCA0CPM2$0$0 == 0x00dc
                           0000DC   557 _PCA0CPM2	=	0x00dc
                           0000DD   558 G$PCA0CPM3$0$0 == 0x00dd
                           0000DD   559 _PCA0CPM3	=	0x00dd
                           0000DE   560 G$PCA0CPM4$0$0 == 0x00de
                           0000DE   561 _PCA0CPM4	=	0x00de
                           0000DF   562 G$PCA0CPM5$0$0 == 0x00df
                           0000DF   563 _PCA0CPM5	=	0x00df
                           0000E1   564 G$PCA0CPL5$0$0 == 0x00e1
                           0000E1   565 _PCA0CPL5	=	0x00e1
                           0000E2   566 G$PCA0CPH5$0$0 == 0x00e2
                           0000E2   567 _PCA0CPH5	=	0x00e2
                           0000E8   568 G$ADC0CN$0$0 == 0x00e8
                           0000E8   569 _ADC0CN	=	0x00e8
                           0000E9   570 G$PCA0CPL2$0$0 == 0x00e9
                           0000E9   571 _PCA0CPL2	=	0x00e9
                           0000EA   572 G$PCA0CPH2$0$0 == 0x00ea
                           0000EA   573 _PCA0CPH2	=	0x00ea
                           0000EB   574 G$PCA0CPL3$0$0 == 0x00eb
                           0000EB   575 _PCA0CPL3	=	0x00eb
                           0000EC   576 G$PCA0CPH3$0$0 == 0x00ec
                           0000EC   577 _PCA0CPH3	=	0x00ec
                           0000ED   578 G$PCA0CPL4$0$0 == 0x00ed
                           0000ED   579 _PCA0CPL4	=	0x00ed
                           0000EE   580 G$PCA0CPH4$0$0 == 0x00ee
                           0000EE   581 _PCA0CPH4	=	0x00ee
                           0000EF   582 G$RSTSRC$0$0 == 0x00ef
                           0000EF   583 _RSTSRC	=	0x00ef
                           0000F8   584 G$SPI0CN$0$0 == 0x00f8
                           0000F8   585 _SPI0CN	=	0x00f8
                           0000F9   586 G$PCA0L$0$0 == 0x00f9
                           0000F9   587 _PCA0L	=	0x00f9
                           0000FA   588 G$PCA0H$0$0 == 0x00fa
                           0000FA   589 _PCA0H	=	0x00fa
                           0000FB   590 G$PCA0CPL0$0$0 == 0x00fb
                           0000FB   591 _PCA0CPL0	=	0x00fb
                           0000FC   592 G$PCA0CPH0$0$0 == 0x00fc
                           0000FC   593 _PCA0CPH0	=	0x00fc
                           0000FD   594 G$PCA0CPL1$0$0 == 0x00fd
                           0000FD   595 _PCA0CPL1	=	0x00fd
                           0000FE   596 G$PCA0CPH1$0$0 == 0x00fe
                           0000FE   597 _PCA0CPH1	=	0x00fe
                           000088   598 G$CPT0CN$0$0 == 0x0088
                           000088   599 _CPT0CN	=	0x0088
                           000089   600 G$CPT0MD$0$0 == 0x0089
                           000089   601 _CPT0MD	=	0x0089
                           000098   602 G$SCON1$0$0 == 0x0098
                           000098   603 _SCON1	=	0x0098
                           000099   604 G$SBUF1$0$0 == 0x0099
                           000099   605 _SBUF1	=	0x0099
                           0000C8   606 G$TMR3CN$0$0 == 0x00c8
                           0000C8   607 _TMR3CN	=	0x00c8
                           0000C9   608 G$TMR3CF$0$0 == 0x00c9
                           0000C9   609 _TMR3CF	=	0x00c9
                           0000CA   610 G$RCAP3L$0$0 == 0x00ca
                           0000CA   611 _RCAP3L	=	0x00ca
                           0000CB   612 G$RCAP3H$0$0 == 0x00cb
                           0000CB   613 _RCAP3H	=	0x00cb
                           0000CC   614 G$TMR3L$0$0 == 0x00cc
                           0000CC   615 _TMR3L	=	0x00cc
                           0000CD   616 G$TMR3H$0$0 == 0x00cd
                           0000CD   617 _TMR3H	=	0x00cd
                           0000D2   618 G$DAC1L$0$0 == 0x00d2
                           0000D2   619 _DAC1L	=	0x00d2
                           0000D3   620 G$DAC1H$0$0 == 0x00d3
                           0000D3   621 _DAC1H	=	0x00d3
                           0000D4   622 G$DAC1CN$0$0 == 0x00d4
                           0000D4   623 _DAC1CN	=	0x00d4
                           000088   624 G$CPT1CN$0$0 == 0x0088
                           000088   625 _CPT1CN	=	0x0088
                           000089   626 G$CPT1MD$0$0 == 0x0089
                           000089   627 _CPT1MD	=	0x0089
                           0000BA   628 G$AMX2CF$0$0 == 0x00ba
                           0000BA   629 _AMX2CF	=	0x00ba
                           0000BB   630 G$AMX2SL$0$0 == 0x00bb
                           0000BB   631 _AMX2SL	=	0x00bb
                           0000BC   632 G$ADC2CF$0$0 == 0x00bc
                           0000BC   633 _ADC2CF	=	0x00bc
                           0000BE   634 G$ADC2$0$0 == 0x00be
                           0000BE   635 _ADC2	=	0x00be
                           0000C4   636 G$ADC2GT$0$0 == 0x00c4
                           0000C4   637 _ADC2GT	=	0x00c4
                           0000C6   638 G$ADC2LT$0$0 == 0x00c6
                           0000C6   639 _ADC2LT	=	0x00c6
                           0000C8   640 G$TMR4CN$0$0 == 0x00c8
                           0000C8   641 _TMR4CN	=	0x00c8
                           0000C9   642 G$TMR4CF$0$0 == 0x00c9
                           0000C9   643 _TMR4CF	=	0x00c9
                           0000CA   644 G$RCAP4L$0$0 == 0x00ca
                           0000CA   645 _RCAP4L	=	0x00ca
                           0000CB   646 G$RCAP4H$0$0 == 0x00cb
                           0000CB   647 _RCAP4H	=	0x00cb
                           0000CC   648 G$TMR4L$0$0 == 0x00cc
                           0000CC   649 _TMR4L	=	0x00cc
                           0000CD   650 G$TMR4H$0$0 == 0x00cd
                           0000CD   651 _TMR4H	=	0x00cd
                           0000E8   652 G$ADC2CN$0$0 == 0x00e8
                           0000E8   653 _ADC2CN	=	0x00e8
                           000091   654 G$MAC0BL$0$0 == 0x0091
                           000091   655 _MAC0BL	=	0x0091
                           000092   656 G$MAC0BH$0$0 == 0x0092
                           000092   657 _MAC0BH	=	0x0092
                           000093   658 G$MAC0ACC0$0$0 == 0x0093
                           000093   659 _MAC0ACC0	=	0x0093
                           000094   660 G$MAC0ACC1$0$0 == 0x0094
                           000094   661 _MAC0ACC1	=	0x0094
                           000095   662 G$MAC0ACC2$0$0 == 0x0095
                           000095   663 _MAC0ACC2	=	0x0095
                           000096   664 G$MAC0ACC3$0$0 == 0x0096
                           000096   665 _MAC0ACC3	=	0x0096
                           000097   666 G$MAC0OVR$0$0 == 0x0097
                           000097   667 _MAC0OVR	=	0x0097
                           0000C0   668 G$MAC0STA$0$0 == 0x00c0
                           0000C0   669 _MAC0STA	=	0x00c0
                           0000C1   670 G$MAC0AL$0$0 == 0x00c1
                           0000C1   671 _MAC0AL	=	0x00c1
                           0000C2   672 G$MAC0AH$0$0 == 0x00c2
                           0000C2   673 _MAC0AH	=	0x00c2
                           0000C3   674 G$MAC0CF$0$0 == 0x00c3
                           0000C3   675 _MAC0CF	=	0x00c3
                           0000CE   676 G$MAC0RNDL$0$0 == 0x00ce
                           0000CE   677 _MAC0RNDL	=	0x00ce
                           0000CF   678 G$MAC0RNDH$0$0 == 0x00cf
                           0000CF   679 _MAC0RNDH	=	0x00cf
                           000088   680 G$FLSTAT$0$0 == 0x0088
                           000088   681 _FLSTAT	=	0x0088
                           000089   682 G$PLL0CN$0$0 == 0x0089
                           000089   683 _PLL0CN	=	0x0089
                           00008A   684 G$OSCICN$0$0 == 0x008a
                           00008A   685 _OSCICN	=	0x008a
                           00008B   686 G$OSCICL$0$0 == 0x008b
                           00008B   687 _OSCICL	=	0x008b
                           00008C   688 G$OSCXCN$0$0 == 0x008c
                           00008C   689 _OSCXCN	=	0x008c
                           00008D   690 G$PLL0DIV$0$0 == 0x008d
                           00008D   691 _PLL0DIV	=	0x008d
                           00008E   692 G$PLL0MUL$0$0 == 0x008e
                           00008E   693 _PLL0MUL	=	0x008e
                           00008F   694 G$PLL0FLT$0$0 == 0x008f
                           00008F   695 _PLL0FLT	=	0x008f
                           000096   696 G$SFRPGCN$0$0 == 0x0096
                           000096   697 _SFRPGCN	=	0x0096
                           000097   698 G$CLKSEL$0$0 == 0x0097
                           000097   699 _CLKSEL	=	0x0097
                           00009A   700 G$CCH0MA$0$0 == 0x009a
                           00009A   701 _CCH0MA	=	0x009a
                           00009C   702 G$P4MDOUT$0$0 == 0x009c
                           00009C   703 _P4MDOUT	=	0x009c
                           00009D   704 G$P5MDOUT$0$0 == 0x009d
                           00009D   705 _P5MDOUT	=	0x009d
                           00009E   706 G$P6MDOUT$0$0 == 0x009e
                           00009E   707 _P6MDOUT	=	0x009e
                           00009F   708 G$P7MDOUT$0$0 == 0x009f
                           00009F   709 _P7MDOUT	=	0x009f
                           0000A1   710 G$CCH0CN$0$0 == 0x00a1
                           0000A1   711 _CCH0CN	=	0x00a1
                           0000A2   712 G$CCH0TN$0$0 == 0x00a2
                           0000A2   713 _CCH0TN	=	0x00a2
                           0000A3   714 G$CCH0LC$0$0 == 0x00a3
                           0000A3   715 _CCH0LC	=	0x00a3
                           0000A4   716 G$P0MDOUT$0$0 == 0x00a4
                           0000A4   717 _P0MDOUT	=	0x00a4
                           0000A5   718 G$P1MDOUT$0$0 == 0x00a5
                           0000A5   719 _P1MDOUT	=	0x00a5
                           0000A6   720 G$P2MDOUT$0$0 == 0x00a6
                           0000A6   721 _P2MDOUT	=	0x00a6
                           0000A7   722 G$P3MDOUT$0$0 == 0x00a7
                           0000A7   723 _P3MDOUT	=	0x00a7
                           0000AD   724 G$P1MDIN$0$0 == 0x00ad
                           0000AD   725 _P1MDIN	=	0x00ad
                           0000B7   726 G$FLACL$0$0 == 0x00b7
                           0000B7   727 _FLACL	=	0x00b7
                           0000C8   728 G$P4$0$0 == 0x00c8
                           0000C8   729 _P4	=	0x00c8
                           0000D8   730 G$P5$0$0 == 0x00d8
                           0000D8   731 _P5	=	0x00d8
                           0000E1   732 G$XBR0$0$0 == 0x00e1
                           0000E1   733 _XBR0	=	0x00e1
                           0000E2   734 G$XBR1$0$0 == 0x00e2
                           0000E2   735 _XBR1	=	0x00e2
                           0000E3   736 G$XBR2$0$0 == 0x00e3
                           0000E3   737 _XBR2	=	0x00e3
                           0000E8   738 G$P6$0$0 == 0x00e8
                           0000E8   739 _P6	=	0x00e8
                           0000F8   740 G$P7$0$0 == 0x00f8
                           0000F8   741 _P7	=	0x00f8
                           008C8A   742 G$TMR0$0$0 == 0x8c8a
                           008C8A   743 _TMR0	=	0x8c8a
                           008D8B   744 G$TMR1$0$0 == 0x8d8b
                           008D8B   745 _TMR1	=	0x8d8b
                           00CDCC   746 G$TMR2$0$0 == 0xcdcc
                           00CDCC   747 _TMR2	=	0xcdcc
                           00CBCA   748 G$RCAP2$0$0 == 0xcbca
                           00CBCA   749 _RCAP2	=	0xcbca
                           00BFBE   750 G$ADC0$0$0 == 0xbfbe
                           00BFBE   751 _ADC0	=	0xbfbe
                           00C5C4   752 G$ADC0GT$0$0 == 0xc5c4
                           00C5C4   753 _ADC0GT	=	0xc5c4
                           00C7C6   754 G$ADC0LT$0$0 == 0xc7c6
                           00C7C6   755 _ADC0LT	=	0xc7c6
                           00D3D2   756 G$DAC0$0$0 == 0xd3d2
                           00D3D2   757 _DAC0	=	0xd3d2
                           00FAF9   758 G$PCA0$0$0 == 0xfaf9
                           00FAF9   759 _PCA0	=	0xfaf9
                           00FCFB   760 G$PCA0CP0$0$0 == 0xfcfb
                           00FCFB   761 _PCA0CP0	=	0xfcfb
                           00FEFD   762 G$PCA0CP1$0$0 == 0xfefd
                           00FEFD   763 _PCA0CP1	=	0xfefd
                           00EAE9   764 G$PCA0CP2$0$0 == 0xeae9
                           00EAE9   765 _PCA0CP2	=	0xeae9
                           00ECEB   766 G$PCA0CP3$0$0 == 0xeceb
                           00ECEB   767 _PCA0CP3	=	0xeceb
                           00EEED   768 G$PCA0CP4$0$0 == 0xeeed
                           00EEED   769 _PCA0CP4	=	0xeeed
                           00E2E1   770 G$PCA0CP5$0$0 == 0xe2e1
                           00E2E1   771 _PCA0CP5	=	0xe2e1
                           00CDCC   772 G$TMR3$0$0 == 0xcdcc
                           00CDCC   773 _TMR3	=	0xcdcc
                           00CBCA   774 G$RCAP3$0$0 == 0xcbca
                           00CBCA   775 _RCAP3	=	0xcbca
                           00D3D2   776 G$DAC1$0$0 == 0xd3d2
                           00D3D2   777 _DAC1	=	0xd3d2
                           00CDCC   778 G$TMR4$0$0 == 0xcdcc
                           00CDCC   779 _TMR4	=	0xcdcc
                           00CBCA   780 G$RCAP4$0$0 == 0xcbca
                           00CBCA   781 _RCAP4	=	0xcbca
                           00C2C1   782 G$MAC0A$0$0 == 0xc2c1
                           00C2C1   783 _MAC0A	=	0xc2c1
                           96959493   784 G$MAC0ACC$0$0 == 0x96959493
                           96959493   785 _MAC0ACC	=	0x96959493
                           00CFCE   786 G$MAC0RND$0$0 == 0xcfce
                           00CFCE   787 _MAC0RND	=	0xcfce
                                    788 ;--------------------------------------------------------
                                    789 ; special function bits
                                    790 ;--------------------------------------------------------
                                    791 	.area RSEG    (ABS,DATA)
      000000                        792 	.org 0x0000
                           000080   793 G$P0_0$0$0 == 0x0080
                           000080   794 _P0_0	=	0x0080
                           000081   795 G$P0_1$0$0 == 0x0081
                           000081   796 _P0_1	=	0x0081
                           000082   797 G$P0_2$0$0 == 0x0082
                           000082   798 _P0_2	=	0x0082
                           000083   799 G$P0_3$0$0 == 0x0083
                           000083   800 _P0_3	=	0x0083
                           000084   801 G$P0_4$0$0 == 0x0084
                           000084   802 _P0_4	=	0x0084
                           000085   803 G$P0_5$0$0 == 0x0085
                           000085   804 _P0_5	=	0x0085
                           000086   805 G$P0_6$0$0 == 0x0086
                           000086   806 _P0_6	=	0x0086
                           000087   807 G$P0_7$0$0 == 0x0087
                           000087   808 _P0_7	=	0x0087
                           000088   809 G$IT0$0$0 == 0x0088
                           000088   810 _IT0	=	0x0088
                           000089   811 G$IE0$0$0 == 0x0089
                           000089   812 _IE0	=	0x0089
                           00008A   813 G$IT1$0$0 == 0x008a
                           00008A   814 _IT1	=	0x008a
                           00008B   815 G$IE1$0$0 == 0x008b
                           00008B   816 _IE1	=	0x008b
                           00008C   817 G$TR0$0$0 == 0x008c
                           00008C   818 _TR0	=	0x008c
                           00008D   819 G$TF0$0$0 == 0x008d
                           00008D   820 _TF0	=	0x008d
                           00008E   821 G$TR1$0$0 == 0x008e
                           00008E   822 _TR1	=	0x008e
                           00008F   823 G$TF1$0$0 == 0x008f
                           00008F   824 _TF1	=	0x008f
                           000088   825 G$CP0HYN0$0$0 == 0x0088
                           000088   826 _CP0HYN0	=	0x0088
                           000089   827 G$CP0HYN1$0$0 == 0x0089
                           000089   828 _CP0HYN1	=	0x0089
                           00008A   829 G$CP0HYP0$0$0 == 0x008a
                           00008A   830 _CP0HYP0	=	0x008a
                           00008B   831 G$CP0HYP1$0$0 == 0x008b
                           00008B   832 _CP0HYP1	=	0x008b
                           00008C   833 G$CP0FIF$0$0 == 0x008c
                           00008C   834 _CP0FIF	=	0x008c
                           00008D   835 G$CP0RIF$0$0 == 0x008d
                           00008D   836 _CP0RIF	=	0x008d
                           00008E   837 G$CP0OUT$0$0 == 0x008e
                           00008E   838 _CP0OUT	=	0x008e
                           00008F   839 G$CP0EN$0$0 == 0x008f
                           00008F   840 _CP0EN	=	0x008f
                           000088   841 G$CP1HYN0$0$0 == 0x0088
                           000088   842 _CP1HYN0	=	0x0088
                           000089   843 G$CP1HYN1$0$0 == 0x0089
                           000089   844 _CP1HYN1	=	0x0089
                           00008A   845 G$CP1HYP0$0$0 == 0x008a
                           00008A   846 _CP1HYP0	=	0x008a
                           00008B   847 G$CP1HYP1$0$0 == 0x008b
                           00008B   848 _CP1HYP1	=	0x008b
                           00008C   849 G$CP1FIF$0$0 == 0x008c
                           00008C   850 _CP1FIF	=	0x008c
                           00008D   851 G$CP1RIF$0$0 == 0x008d
                           00008D   852 _CP1RIF	=	0x008d
                           00008E   853 G$CP1OUT$0$0 == 0x008e
                           00008E   854 _CP1OUT	=	0x008e
                           00008F   855 G$CP1EN$0$0 == 0x008f
                           00008F   856 _CP1EN	=	0x008f
                           000088   857 G$FLHBUSY$0$0 == 0x0088
                           000088   858 _FLHBUSY	=	0x0088
                           000098   859 G$RI0$0$0 == 0x0098
                           000098   860 _RI0	=	0x0098
                           000098   861 G$RI$0$0 == 0x0098
                           000098   862 _RI	=	0x0098
                           000099   863 G$TI0$0$0 == 0x0099
                           000099   864 _TI0	=	0x0099
                           000099   865 G$TI$0$0 == 0x0099
                           000099   866 _TI	=	0x0099
                           00009A   867 G$RB80$0$0 == 0x009a
                           00009A   868 _RB80	=	0x009a
                           00009B   869 G$TB80$0$0 == 0x009b
                           00009B   870 _TB80	=	0x009b
                           00009C   871 G$REN0$0$0 == 0x009c
                           00009C   872 _REN0	=	0x009c
                           00009C   873 G$REN$0$0 == 0x009c
                           00009C   874 _REN	=	0x009c
                           00009D   875 G$SM20$0$0 == 0x009d
                           00009D   876 _SM20	=	0x009d
                           00009E   877 G$SM10$0$0 == 0x009e
                           00009E   878 _SM10	=	0x009e
                           00009F   879 G$SM00$0$0 == 0x009f
                           00009F   880 _SM00	=	0x009f
                           000098   881 G$RI1$0$0 == 0x0098
                           000098   882 _RI1	=	0x0098
                           000099   883 G$TI1$0$0 == 0x0099
                           000099   884 _TI1	=	0x0099
                           00009A   885 G$RB81$0$0 == 0x009a
                           00009A   886 _RB81	=	0x009a
                           00009B   887 G$TB81$0$0 == 0x009b
                           00009B   888 _TB81	=	0x009b
                           00009C   889 G$REN1$0$0 == 0x009c
                           00009C   890 _REN1	=	0x009c
                           00009D   891 G$MCE1$0$0 == 0x009d
                           00009D   892 _MCE1	=	0x009d
                           00009F   893 G$S1MODE$0$0 == 0x009f
                           00009F   894 _S1MODE	=	0x009f
                           0000A8   895 G$EX0$0$0 == 0x00a8
                           0000A8   896 _EX0	=	0x00a8
                           0000A9   897 G$ET0$0$0 == 0x00a9
                           0000A9   898 _ET0	=	0x00a9
                           0000AA   899 G$EX1$0$0 == 0x00aa
                           0000AA   900 _EX1	=	0x00aa
                           0000AB   901 G$ET1$0$0 == 0x00ab
                           0000AB   902 _ET1	=	0x00ab
                           0000AC   903 G$ES0$0$0 == 0x00ac
                           0000AC   904 _ES0	=	0x00ac
                           0000AC   905 G$ES$0$0 == 0x00ac
                           0000AC   906 _ES	=	0x00ac
                           0000AD   907 G$ET2$0$0 == 0x00ad
                           0000AD   908 _ET2	=	0x00ad
                           0000AF   909 G$EA$0$0 == 0x00af
                           0000AF   910 _EA	=	0x00af
                           0000B0   911 G$P3_0$0$0 == 0x00b0
                           0000B0   912 _P3_0	=	0x00b0
                           0000B1   913 G$P3_1$0$0 == 0x00b1
                           0000B1   914 _P3_1	=	0x00b1
                           0000B2   915 G$P3_2$0$0 == 0x00b2
                           0000B2   916 _P3_2	=	0x00b2
                           0000B3   917 G$P3_3$0$0 == 0x00b3
                           0000B3   918 _P3_3	=	0x00b3
                           0000B4   919 G$P3_4$0$0 == 0x00b4
                           0000B4   920 _P3_4	=	0x00b4
                           0000B5   921 G$P3_5$0$0 == 0x00b5
                           0000B5   922 _P3_5	=	0x00b5
                           0000B6   923 G$P3_6$0$0 == 0x00b6
                           0000B6   924 _P3_6	=	0x00b6
                           0000B7   925 G$P3_7$0$0 == 0x00b7
                           0000B7   926 _P3_7	=	0x00b7
                           0000B8   927 G$PX0$0$0 == 0x00b8
                           0000B8   928 _PX0	=	0x00b8
                           0000B9   929 G$PT0$0$0 == 0x00b9
                           0000B9   930 _PT0	=	0x00b9
                           0000BA   931 G$PX1$0$0 == 0x00ba
                           0000BA   932 _PX1	=	0x00ba
                           0000BB   933 G$PT1$0$0 == 0x00bb
                           0000BB   934 _PT1	=	0x00bb
                           0000BC   935 G$PS0$0$0 == 0x00bc
                           0000BC   936 _PS0	=	0x00bc
                           0000BC   937 G$PS$0$0 == 0x00bc
                           0000BC   938 _PS	=	0x00bc
                           0000BD   939 G$PT2$0$0 == 0x00bd
                           0000BD   940 _PT2	=	0x00bd
                           0000C0   941 G$SMBTOE$0$0 == 0x00c0
                           0000C0   942 _SMBTOE	=	0x00c0
                           0000C1   943 G$SMBFTE$0$0 == 0x00c1
                           0000C1   944 _SMBFTE	=	0x00c1
                           0000C2   945 G$AA$0$0 == 0x00c2
                           0000C2   946 _AA	=	0x00c2
                           0000C3   947 G$SI$0$0 == 0x00c3
                           0000C3   948 _SI	=	0x00c3
                           0000C4   949 G$STO$0$0 == 0x00c4
                           0000C4   950 _STO	=	0x00c4
                           0000C5   951 G$STA$0$0 == 0x00c5
                           0000C5   952 _STA	=	0x00c5
                           0000C6   953 G$ENSMB$0$0 == 0x00c6
                           0000C6   954 _ENSMB	=	0x00c6
                           0000C7   955 G$BUSY$0$0 == 0x00c7
                           0000C7   956 _BUSY	=	0x00c7
                           0000C0   957 G$MAC0N$0$0 == 0x00c0
                           0000C0   958 _MAC0N	=	0x00c0
                           0000C1   959 G$MAC0SO$0$0 == 0x00c1
                           0000C1   960 _MAC0SO	=	0x00c1
                           0000C2   961 G$MAC0Z$0$0 == 0x00c2
                           0000C2   962 _MAC0Z	=	0x00c2
                           0000C3   963 G$MAC0HO$0$0 == 0x00c3
                           0000C3   964 _MAC0HO	=	0x00c3
                           0000C8   965 G$CPRL2$0$0 == 0x00c8
                           0000C8   966 _CPRL2	=	0x00c8
                           0000C9   967 G$CT2$0$0 == 0x00c9
                           0000C9   968 _CT2	=	0x00c9
                           0000CA   969 G$TR2$0$0 == 0x00ca
                           0000CA   970 _TR2	=	0x00ca
                           0000CB   971 G$EXEN2$0$0 == 0x00cb
                           0000CB   972 _EXEN2	=	0x00cb
                           0000CE   973 G$EXF2$0$0 == 0x00ce
                           0000CE   974 _EXF2	=	0x00ce
                           0000CF   975 G$TF2$0$0 == 0x00cf
                           0000CF   976 _TF2	=	0x00cf
                           0000C8   977 G$CPRL3$0$0 == 0x00c8
                           0000C8   978 _CPRL3	=	0x00c8
                           0000C9   979 G$CT3$0$0 == 0x00c9
                           0000C9   980 _CT3	=	0x00c9
                           0000CA   981 G$TR3$0$0 == 0x00ca
                           0000CA   982 _TR3	=	0x00ca
                           0000CB   983 G$EXEN3$0$0 == 0x00cb
                           0000CB   984 _EXEN3	=	0x00cb
                           0000CE   985 G$EXF3$0$0 == 0x00ce
                           0000CE   986 _EXF3	=	0x00ce
                           0000CF   987 G$TF3$0$0 == 0x00cf
                           0000CF   988 _TF3	=	0x00cf
                           0000C8   989 G$CPRL4$0$0 == 0x00c8
                           0000C8   990 _CPRL4	=	0x00c8
                           0000C9   991 G$CT4$0$0 == 0x00c9
                           0000C9   992 _CT4	=	0x00c9
                           0000CA   993 G$TR4$0$0 == 0x00ca
                           0000CA   994 _TR4	=	0x00ca
                           0000CB   995 G$EXEN4$0$0 == 0x00cb
                           0000CB   996 _EXEN4	=	0x00cb
                           0000CE   997 G$EXF4$0$0 == 0x00ce
                           0000CE   998 _EXF4	=	0x00ce
                           0000CF   999 G$TF4$0$0 == 0x00cf
                           0000CF  1000 _TF4	=	0x00cf
                           0000C8  1001 G$P4_0$0$0 == 0x00c8
                           0000C8  1002 _P4_0	=	0x00c8
                           0000C9  1003 G$P4_1$0$0 == 0x00c9
                           0000C9  1004 _P4_1	=	0x00c9
                           0000CA  1005 G$P4_2$0$0 == 0x00ca
                           0000CA  1006 _P4_2	=	0x00ca
                           0000CB  1007 G$P4_3$0$0 == 0x00cb
                           0000CB  1008 _P4_3	=	0x00cb
                           0000CC  1009 G$P4_4$0$0 == 0x00cc
                           0000CC  1010 _P4_4	=	0x00cc
                           0000CD  1011 G$P4_5$0$0 == 0x00cd
                           0000CD  1012 _P4_5	=	0x00cd
                           0000CE  1013 G$P4_6$0$0 == 0x00ce
                           0000CE  1014 _P4_6	=	0x00ce
                           0000CF  1015 G$P4_7$0$0 == 0x00cf
                           0000CF  1016 _P4_7	=	0x00cf
                           0000D0  1017 G$P$0$0 == 0x00d0
                           0000D0  1018 _P	=	0x00d0
                           0000D1  1019 G$F1$0$0 == 0x00d1
                           0000D1  1020 _F1	=	0x00d1
                           0000D2  1021 G$OV$0$0 == 0x00d2
                           0000D2  1022 _OV	=	0x00d2
                           0000D3  1023 G$RS0$0$0 == 0x00d3
                           0000D3  1024 _RS0	=	0x00d3
                           0000D4  1025 G$RS1$0$0 == 0x00d4
                           0000D4  1026 _RS1	=	0x00d4
                           0000D5  1027 G$F0$0$0 == 0x00d5
                           0000D5  1028 _F0	=	0x00d5
                           0000D6  1029 G$AC$0$0 == 0x00d6
                           0000D6  1030 _AC	=	0x00d6
                           0000D7  1031 G$CY$0$0 == 0x00d7
                           0000D7  1032 _CY	=	0x00d7
                           0000D8  1033 G$CCF0$0$0 == 0x00d8
                           0000D8  1034 _CCF0	=	0x00d8
                           0000D9  1035 G$CCF1$0$0 == 0x00d9
                           0000D9  1036 _CCF1	=	0x00d9
                           0000DA  1037 G$CCF2$0$0 == 0x00da
                           0000DA  1038 _CCF2	=	0x00da
                           0000DB  1039 G$CCF3$0$0 == 0x00db
                           0000DB  1040 _CCF3	=	0x00db
                           0000DC  1041 G$CCF4$0$0 == 0x00dc
                           0000DC  1042 _CCF4	=	0x00dc
                           0000DD  1043 G$CCF5$0$0 == 0x00dd
                           0000DD  1044 _CCF5	=	0x00dd
                           0000DE  1045 G$CR$0$0 == 0x00de
                           0000DE  1046 _CR	=	0x00de
                           0000DF  1047 G$CF$0$0 == 0x00df
                           0000DF  1048 _CF	=	0x00df
                           0000D8  1049 G$P5_0$0$0 == 0x00d8
                           0000D8  1050 _P5_0	=	0x00d8
                           0000D9  1051 G$P5_1$0$0 == 0x00d9
                           0000D9  1052 _P5_1	=	0x00d9
                           0000DA  1053 G$P5_2$0$0 == 0x00da
                           0000DA  1054 _P5_2	=	0x00da
                           0000DB  1055 G$P5_3$0$0 == 0x00db
                           0000DB  1056 _P5_3	=	0x00db
                           0000DC  1057 G$P5_4$0$0 == 0x00dc
                           0000DC  1058 _P5_4	=	0x00dc
                           0000DD  1059 G$P5_5$0$0 == 0x00dd
                           0000DD  1060 _P5_5	=	0x00dd
                           0000DE  1061 G$P5_6$0$0 == 0x00de
                           0000DE  1062 _P5_6	=	0x00de
                           0000DF  1063 G$P5_7$0$0 == 0x00df
                           0000DF  1064 _P5_7	=	0x00df
                           0000E8  1065 G$AD0LJST$0$0 == 0x00e8
                           0000E8  1066 _AD0LJST	=	0x00e8
                           0000E9  1067 G$AD0WINT$0$0 == 0x00e9
                           0000E9  1068 _AD0WINT	=	0x00e9
                           0000EA  1069 G$AD0CM0$0$0 == 0x00ea
                           0000EA  1070 _AD0CM0	=	0x00ea
                           0000EB  1071 G$AD0CM1$0$0 == 0x00eb
                           0000EB  1072 _AD0CM1	=	0x00eb
                           0000EC  1073 G$AD0BUSY$0$0 == 0x00ec
                           0000EC  1074 _AD0BUSY	=	0x00ec
                           0000ED  1075 G$AD0INT$0$0 == 0x00ed
                           0000ED  1076 _AD0INT	=	0x00ed
                           0000EE  1077 G$AD0TM$0$0 == 0x00ee
                           0000EE  1078 _AD0TM	=	0x00ee
                           0000EF  1079 G$AD0EN$0$0 == 0x00ef
                           0000EF  1080 _AD0EN	=	0x00ef
                           0000E8  1081 G$AD2WINT$0$0 == 0x00e8
                           0000E8  1082 _AD2WINT	=	0x00e8
                           0000E9  1083 G$AD2CM0$0$0 == 0x00e9
                           0000E9  1084 _AD2CM0	=	0x00e9
                           0000EA  1085 G$AD2CM1$0$0 == 0x00ea
                           0000EA  1086 _AD2CM1	=	0x00ea
                           0000EB  1087 G$AD2CM2$0$0 == 0x00eb
                           0000EB  1088 _AD2CM2	=	0x00eb
                           0000EC  1089 G$AD2BUSY$0$0 == 0x00ec
                           0000EC  1090 _AD2BUSY	=	0x00ec
                           0000ED  1091 G$AD2INT$0$0 == 0x00ed
                           0000ED  1092 _AD2INT	=	0x00ed
                           0000EE  1093 G$AD2TM$0$0 == 0x00ee
                           0000EE  1094 _AD2TM	=	0x00ee
                           0000EF  1095 G$AD2EN$0$0 == 0x00ef
                           0000EF  1096 _AD2EN	=	0x00ef
                           0000E8  1097 G$P6_0$0$0 == 0x00e8
                           0000E8  1098 _P6_0	=	0x00e8
                           0000E9  1099 G$P6_1$0$0 == 0x00e9
                           0000E9  1100 _P6_1	=	0x00e9
                           0000EA  1101 G$P6_2$0$0 == 0x00ea
                           0000EA  1102 _P6_2	=	0x00ea
                           0000EB  1103 G$P6_3$0$0 == 0x00eb
                           0000EB  1104 _P6_3	=	0x00eb
                           0000EC  1105 G$P6_4$0$0 == 0x00ec
                           0000EC  1106 _P6_4	=	0x00ec
                           0000ED  1107 G$P6_5$0$0 == 0x00ed
                           0000ED  1108 _P6_5	=	0x00ed
                           0000EE  1109 G$P6_6$0$0 == 0x00ee
                           0000EE  1110 _P6_6	=	0x00ee
                           0000EF  1111 G$P6_7$0$0 == 0x00ef
                           0000EF  1112 _P6_7	=	0x00ef
                           0000F8  1113 G$SPIEN$0$0 == 0x00f8
                           0000F8  1114 _SPIEN	=	0x00f8
                           0000F9  1115 G$TXBMT$0$0 == 0x00f9
                           0000F9  1116 _TXBMT	=	0x00f9
                           0000FA  1117 G$NSSMD0$0$0 == 0x00fa
                           0000FA  1118 _NSSMD0	=	0x00fa
                           0000FB  1119 G$NSSMD1$0$0 == 0x00fb
                           0000FB  1120 _NSSMD1	=	0x00fb
                           0000FC  1121 G$RXOVRN$0$0 == 0x00fc
                           0000FC  1122 _RXOVRN	=	0x00fc
                           0000FD  1123 G$MODF$0$0 == 0x00fd
                           0000FD  1124 _MODF	=	0x00fd
                           0000FE  1125 G$WCOL$0$0 == 0x00fe
                           0000FE  1126 _WCOL	=	0x00fe
                           0000FF  1127 G$SPIF$0$0 == 0x00ff
                           0000FF  1128 _SPIF	=	0x00ff
                           0000F8  1129 G$P7_0$0$0 == 0x00f8
                           0000F8  1130 _P7_0	=	0x00f8
                           0000F9  1131 G$P7_1$0$0 == 0x00f9
                           0000F9  1132 _P7_1	=	0x00f9
                           0000FA  1133 G$P7_2$0$0 == 0x00fa
                           0000FA  1134 _P7_2	=	0x00fa
                           0000FB  1135 G$P7_3$0$0 == 0x00fb
                           0000FB  1136 _P7_3	=	0x00fb
                           0000FC  1137 G$P7_4$0$0 == 0x00fc
                           0000FC  1138 _P7_4	=	0x00fc
                           0000FD  1139 G$P7_5$0$0 == 0x00fd
                           0000FD  1140 _P7_5	=	0x00fd
                           0000FE  1141 G$P7_6$0$0 == 0x00fe
                           0000FE  1142 _P7_6	=	0x00fe
                           0000FF  1143 G$P7_7$0$0 == 0x00ff
                           0000FF  1144 _P7_7	=	0x00ff
                           000090  1145 G$P1_0$0$0 == 0x0090
                           000090  1146 _P1_0	=	0x0090
                           000091  1147 G$P1_1$0$0 == 0x0091
                           000091  1148 _P1_1	=	0x0091
                           000092  1149 G$P1_2$0$0 == 0x0092
                           000092  1150 _P1_2	=	0x0092
                           000093  1151 G$P1_3$0$0 == 0x0093
                           000093  1152 _P1_3	=	0x0093
                           000094  1153 G$P1_4$0$0 == 0x0094
                           000094  1154 _P1_4	=	0x0094
                           000095  1155 G$P1_5$0$0 == 0x0095
                           000095  1156 _P1_5	=	0x0095
                           000096  1157 G$P1_6$0$0 == 0x0096
                           000096  1158 _P1_6	=	0x0096
                           000097  1159 G$P1_7$0$0 == 0x0097
                           000097  1160 _P1_7	=	0x0097
                           0000A0  1161 G$P2_0$0$0 == 0x00a0
                           0000A0  1162 _P2_0	=	0x00a0
                           0000A1  1163 G$P2_1$0$0 == 0x00a1
                           0000A1  1164 _P2_1	=	0x00a1
                           0000A2  1165 G$P2_2$0$0 == 0x00a2
                           0000A2  1166 _P2_2	=	0x00a2
                           0000A3  1167 G$P2_3$0$0 == 0x00a3
                           0000A3  1168 _P2_3	=	0x00a3
                           0000A4  1169 G$P2_4$0$0 == 0x00a4
                           0000A4  1170 _P2_4	=	0x00a4
                           0000A5  1171 G$P2_5$0$0 == 0x00a5
                           0000A5  1172 _P2_5	=	0x00a5
                           0000A6  1173 G$P2_6$0$0 == 0x00a6
                           0000A6  1174 _P2_6	=	0x00a6
                           0000A7  1175 G$P2_7$0$0 == 0x00a7
                           0000A7  1176 _P2_7	=	0x00a7
                                   1177 ;--------------------------------------------------------
                                   1178 ; overlayable register banks
                                   1179 ;--------------------------------------------------------
                                   1180 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                       1181 	.ds 8
                                   1182 ;--------------------------------------------------------
                                   1183 ; internal ram data
                                   1184 ;--------------------------------------------------------
                                   1185 	.area DSEG    (DATA)
                           000000  1186 LportIO.main$sloc0$1$0==.
      000022                       1187 _main_sloc0_1_0:
      000022                       1188 	.ds 2
                           000002  1189 LportIO.main$sloc1$1$0==.
      000024                       1190 _main_sloc1_1_0:
      000024                       1191 	.ds 2
                           000004  1192 LportIO.main$sloc2$1$0==.
      000026                       1193 _main_sloc2_1_0:
      000026                       1194 	.ds 2
                           000006  1195 LportIO.main$sloc3$1$0==.
      000028                       1196 _main_sloc3_1_0:
      000028                       1197 	.ds 2
                           000008  1198 LportIO.main$sloc4$1$0==.
      00002A                       1199 _main_sloc4_1_0:
      00002A                       1200 	.ds 2
                           00000A  1201 LportIO.main$sloc5$1$0==.
      00002C                       1202 _main_sloc5_1_0:
      00002C                       1203 	.ds 2
                           00000C  1204 LportIO.main$sloc6$1$0==.
      00002E                       1205 _main_sloc6_1_0:
      00002E                       1206 	.ds 2
                           00000E  1207 LportIO.main$sloc7$1$0==.
      000030                       1208 _main_sloc7_1_0:
      000030                       1209 	.ds 2
                           000010  1210 LportIO.main$sloc8$1$0==.
      000032                       1211 _main_sloc8_1_0:
      000032                       1212 	.ds 2
                           000012  1213 LportIO.main$sloc9$1$0==.
      000034                       1214 _main_sloc9_1_0:
      000034                       1215 	.ds 2
                           000014  1216 LportIO.main$sloc10$1$0==.
      000036                       1217 _main_sloc10_1_0:
      000036                       1218 	.ds 2
                           000016  1219 LportIO.main$sloc11$1$0==.
      000038                       1220 _main_sloc11_1_0:
      000038                       1221 	.ds 2
                           000018  1222 LportIO.main$sloc12$1$0==.
      00003A                       1223 _main_sloc12_1_0:
      00003A                       1224 	.ds 2
                           00001A  1225 LportIO.main$sloc13$1$0==.
      00003C                       1226 _main_sloc13_1_0:
      00003C                       1227 	.ds 2
                                   1228 ;--------------------------------------------------------
                                   1229 ; overlayable items in internal ram 
                                   1230 ;--------------------------------------------------------
                                   1231 	.area	OSEG    (OVR,DATA)
                                   1232 	.area	OSEG    (OVR,DATA)
                                   1233 	.area	OSEG    (OVR,DATA)
                                   1234 	.area	OSEG    (OVR,DATA)
                                   1235 ;--------------------------------------------------------
                                   1236 ; Stack segment in internal ram 
                                   1237 ;--------------------------------------------------------
                                   1238 	.area	SSEG
      000058                       1239 __start__stack:
      000058                       1240 	.ds	1
                                   1241 
                                   1242 ;--------------------------------------------------------
                                   1243 ; indirectly addressable internal ram data
                                   1244 ;--------------------------------------------------------
                                   1245 	.area ISEG    (DATA)
                                   1246 ;--------------------------------------------------------
                                   1247 ; absolute internal ram data
                                   1248 ;--------------------------------------------------------
                                   1249 	.area IABS    (ABS,DATA)
                                   1250 	.area IABS    (ABS,DATA)
                                   1251 ;--------------------------------------------------------
                                   1252 ; bit data
                                   1253 ;--------------------------------------------------------
                                   1254 	.area BSEG    (BIT)
                                   1255 ;--------------------------------------------------------
                                   1256 ; paged external ram data
                                   1257 ;--------------------------------------------------------
                                   1258 	.area PSEG    (PAG,XDATA)
                                   1259 ;--------------------------------------------------------
                                   1260 ; external ram data
                                   1261 ;--------------------------------------------------------
                                   1262 	.area XSEG    (XDATA)
                                   1263 ;--------------------------------------------------------
                                   1264 ; absolute external ram data
                                   1265 ;--------------------------------------------------------
                                   1266 	.area XABS    (ABS,XDATA)
                                   1267 ;--------------------------------------------------------
                                   1268 ; external initialized ram data
                                   1269 ;--------------------------------------------------------
                                   1270 	.area XISEG   (XDATA)
                                   1271 	.area HOME    (CODE)
                                   1272 	.area GSINIT0 (CODE)
                                   1273 	.area GSINIT1 (CODE)
                                   1274 	.area GSINIT2 (CODE)
                                   1275 	.area GSINIT3 (CODE)
                                   1276 	.area GSINIT4 (CODE)
                                   1277 	.area GSINIT5 (CODE)
                                   1278 	.area GSINIT  (CODE)
                                   1279 	.area GSFINAL (CODE)
                                   1280 	.area CSEG    (CODE)
                                   1281 ;--------------------------------------------------------
                                   1282 ; interrupt vector 
                                   1283 ;--------------------------------------------------------
                                   1284 	.area HOME    (CODE)
      000000                       1285 __interrupt_vect:
      000000 02 00 06         [24] 1286 	ljmp	__sdcc_gsinit_startup
                                   1287 ;--------------------------------------------------------
                                   1288 ; global & static initialisations
                                   1289 ;--------------------------------------------------------
                                   1290 	.area HOME    (CODE)
                                   1291 	.area GSINIT  (CODE)
                                   1292 	.area GSFINAL (CODE)
                                   1293 	.area GSINIT  (CODE)
                                   1294 	.globl __sdcc_gsinit_startup
                                   1295 	.globl __sdcc_program_startup
                                   1296 	.globl __start__stack
                                   1297 	.globl __mcs51_genXINIT
                                   1298 	.globl __mcs51_genXRAMCLEAR
                                   1299 	.globl __mcs51_genRAMCLEAR
                                   1300 	.area GSFINAL (CODE)
      00005F 02 00 03         [24] 1301 	ljmp	__sdcc_program_startup
                                   1302 ;--------------------------------------------------------
                                   1303 ; Home
                                   1304 ;--------------------------------------------------------
                                   1305 	.area HOME    (CODE)
                                   1306 	.area HOME    (CODE)
      000003                       1307 __sdcc_program_startup:
      000003 02 00 7B         [24] 1308 	ljmp	_main
                                   1309 ;	return from main will return to caller
                                   1310 ;--------------------------------------------------------
                                   1311 ; code
                                   1312 ;--------------------------------------------------------
                                   1313 	.area CSEG    (CODE)
                                   1314 ;------------------------------------------------------------
                                   1315 ;Allocation info for local variables in function 'putchar'
                                   1316 ;------------------------------------------------------------
                                   1317 ;c                         Allocated to registers r7 
                                   1318 ;------------------------------------------------------------
                           000000  1319 	G$putchar$0$0 ==.
                           000000  1320 	C$putget.h$20$0$0 ==.
                                   1321 ;	C:\Users\John\Documents\MPS\lab1\/putget.h:20: void putchar(char c)
                                   1322 ;	-----------------------------------------
                                   1323 ;	 function putchar
                                   1324 ;	-----------------------------------------
      000062                       1325 _putchar:
                           000007  1326 	ar7 = 0x07
                           000006  1327 	ar6 = 0x06
                           000005  1328 	ar5 = 0x05
                           000004  1329 	ar4 = 0x04
                           000003  1330 	ar3 = 0x03
                           000002  1331 	ar2 = 0x02
                           000001  1332 	ar1 = 0x01
                           000000  1333 	ar0 = 0x00
      000062 AF 82            [24] 1334 	mov	r7,dpl
                           000002  1335 	C$putget.h$22$1$15 ==.
                                   1336 ;	C:\Users\John\Documents\MPS\lab1\/putget.h:22: while(!TI0); 
      000064                       1337 00101$:
                           000002  1338 	C$putget.h$23$1$15 ==.
                                   1339 ;	C:\Users\John\Documents\MPS\lab1\/putget.h:23: TI0=0;
      000064 10 99 02         [24] 1340 	jbc	_TI0,00112$
      000067 80 FB            [24] 1341 	sjmp	00101$
      000069                       1342 00112$:
                           000007  1343 	C$putget.h$24$1$15 ==.
                                   1344 ;	C:\Users\John\Documents\MPS\lab1\/putget.h:24: SBUF0 = c;
      000069 8F 99            [24] 1345 	mov	_SBUF0,r7
                           000009  1346 	C$putget.h$25$1$15 ==.
                           000009  1347 	XG$putchar$0$0 ==.
      00006B 22               [24] 1348 	ret
                                   1349 ;------------------------------------------------------------
                                   1350 ;Allocation info for local variables in function 'getchar'
                                   1351 ;------------------------------------------------------------
                                   1352 ;c                         Allocated to registers 
                                   1353 ;------------------------------------------------------------
                           00000A  1354 	G$getchar$0$0 ==.
                           00000A  1355 	C$putget.h$30$1$15 ==.
                                   1356 ;	C:\Users\John\Documents\MPS\lab1\/putget.h:30: char getchar(void)
                                   1357 ;	-----------------------------------------
                                   1358 ;	 function getchar
                                   1359 ;	-----------------------------------------
      00006C                       1360 _getchar:
                           00000A  1361 	C$putget.h$33$1$17 ==.
                                   1362 ;	C:\Users\John\Documents\MPS\lab1\/putget.h:33: while(!RI0);
      00006C                       1363 00101$:
                           00000A  1364 	C$putget.h$34$1$17 ==.
                                   1365 ;	C:\Users\John\Documents\MPS\lab1\/putget.h:34: RI0 =0;
      00006C 10 98 02         [24] 1366 	jbc	_RI0,00112$
      00006F 80 FB            [24] 1367 	sjmp	00101$
      000071                       1368 00112$:
                           00000F  1369 	C$putget.h$35$1$17 ==.
                                   1370 ;	C:\Users\John\Documents\MPS\lab1\/putget.h:35: c = SBUF0;
      000071 85 99 82         [24] 1371 	mov	dpl,_SBUF0
                           000012  1372 	C$putget.h$37$1$17 ==.
                                   1373 ;	C:\Users\John\Documents\MPS\lab1\/putget.h:37: putchar(c);    // echo to terminal
      000074 12 00 62         [24] 1374 	lcall	_putchar
                           000015  1375 	C$putget.h$38$1$17 ==.
                                   1376 ;	C:\Users\John\Documents\MPS\lab1\/putget.h:38: return SBUF0;
      000077 85 99 82         [24] 1377 	mov	dpl,_SBUF0
                           000018  1378 	C$putget.h$39$1$17 ==.
                           000018  1379 	XG$getchar$0$0 ==.
      00007A 22               [24] 1380 	ret
                                   1381 ;------------------------------------------------------------
                                   1382 ;Allocation info for local variables in function 'main'
                                   1383 ;------------------------------------------------------------
                                   1384 ;choice                    Allocated with name '_main_choice_1_23'
                                   1385 ;sloc0                     Allocated with name '_main_sloc0_1_0'
                                   1386 ;sloc1                     Allocated with name '_main_sloc1_1_0'
                                   1387 ;sloc2                     Allocated with name '_main_sloc2_1_0'
                                   1388 ;sloc3                     Allocated with name '_main_sloc3_1_0'
                                   1389 ;sloc4                     Allocated with name '_main_sloc4_1_0'
                                   1390 ;sloc5                     Allocated with name '_main_sloc5_1_0'
                                   1391 ;sloc6                     Allocated with name '_main_sloc6_1_0'
                                   1392 ;sloc7                     Allocated with name '_main_sloc7_1_0'
                                   1393 ;sloc8                     Allocated with name '_main_sloc8_1_0'
                                   1394 ;sloc9                     Allocated with name '_main_sloc9_1_0'
                                   1395 ;sloc10                    Allocated with name '_main_sloc10_1_0'
                                   1396 ;sloc11                    Allocated with name '_main_sloc11_1_0'
                                   1397 ;sloc12                    Allocated with name '_main_sloc12_1_0'
                                   1398 ;sloc13                    Allocated with name '_main_sloc13_1_0'
                                   1399 ;------------------------------------------------------------
                           000019  1400 	G$main$0$0 ==.
                           000019  1401 	C$portIO.c$51$1$17 ==.
                                   1402 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:51: void main(void)
                                   1403 ;	-----------------------------------------
                                   1404 ;	 function main
                                   1405 ;	-----------------------------------------
      00007B                       1406 _main:
                           000019  1407 	C$portIO.c$55$1$23 ==.
                                   1408 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:55: WDTCN = 0xDE;                       // Disable the watchdog timer
      00007B 75 FF DE         [24] 1409 	mov	_WDTCN,#0xde
                           00001C  1410 	C$portIO.c$56$1$23 ==.
                                   1411 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:56: WDTCN = 0xAD;
      00007E 75 FF AD         [24] 1412 	mov	_WDTCN,#0xad
                           00001F  1413 	C$portIO.c$58$1$23 ==.
                                   1414 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:58: PORT_INIT();                        // Initialize the Crossbar and GPIO
      000081 12 02 1A         [24] 1415 	lcall	_PORT_INIT
                           000022  1416 	C$portIO.c$59$1$23 ==.
                                   1417 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:59: SYSCLK_INIT();                      // Initialize the oscillator
      000084 12 01 C4         [24] 1418 	lcall	_SYSCLK_INIT
                           000025  1419 	C$portIO.c$60$1$23 ==.
                                   1420 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:60: UART0_INIT();                       // Initialize UART0
      000087 12 02 39         [24] 1421 	lcall	_UART0_INIT
                           000028  1422 	C$portIO.c$62$1$23 ==.
                                   1423 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:62: SFRPAGE = UART0_PAGE;               // Direct output to UART0
      00008A 75 84 00         [24] 1424 	mov	_SFRPAGE,#0x00
                           00002B  1425 	C$portIO.c$65$1$23 ==.
                                   1426 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:65: printf("\033[33;44m");              // Yellow text; blue background
      00008D 74 9C            [12] 1427 	mov	a,#___str_0
      00008F C0 E0            [24] 1428 	push	acc
      000091 74 08            [12] 1429 	mov	a,#(___str_0 >> 8)
      000093 C0 E0            [24] 1430 	push	acc
      000095 74 80            [12] 1431 	mov	a,#0x80
      000097 C0 E0            [24] 1432 	push	acc
      000099 12 02 81         [24] 1433 	lcall	_printf
      00009C 15 81            [12] 1434 	dec	sp
      00009E 15 81            [12] 1435 	dec	sp
      0000A0 15 81            [12] 1436 	dec	sp
                           000040  1437 	C$portIO.c$66$1$23 ==.
                                   1438 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:66: printf("\033[2J");                  // Erase screen & move cursor to home position
      0000A2 74 A5            [12] 1439 	mov	a,#___str_1
      0000A4 C0 E0            [24] 1440 	push	acc
      0000A6 74 08            [12] 1441 	mov	a,#(___str_1 >> 8)
      0000A8 C0 E0            [24] 1442 	push	acc
      0000AA 74 80            [12] 1443 	mov	a,#0x80
      0000AC C0 E0            [24] 1444 	push	acc
      0000AE 12 02 81         [24] 1445 	lcall	_printf
      0000B1 15 81            [12] 1446 	dec	sp
      0000B3 15 81            [12] 1447 	dec	sp
      0000B5 15 81            [12] 1448 	dec	sp
                           000055  1449 	C$portIO.c$68$1$23 ==.
                                   1450 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:68: printf("Hello World!\n\r");
      0000B7 74 AA            [12] 1451 	mov	a,#___str_2
      0000B9 C0 E0            [24] 1452 	push	acc
      0000BB 74 08            [12] 1453 	mov	a,#(___str_2 >> 8)
      0000BD C0 E0            [24] 1454 	push	acc
      0000BF 74 80            [12] 1455 	mov	a,#0x80
      0000C1 C0 E0            [24] 1456 	push	acc
      0000C3 12 02 81         [24] 1457 	lcall	_printf
      0000C6 15 81            [12] 1458 	dec	sp
      0000C8 15 81            [12] 1459 	dec	sp
      0000CA 15 81            [12] 1460 	dec	sp
                           00006A  1461 	C$portIO.c$70$1$23 ==.
                                   1462 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:70: while(1){
      0000CC                       1463 00102$:
                           00006A  1464 	C$portIO.c$71$2$24 ==.
                                   1465 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:71: P2 = P1;  //Copy input to output
      0000CC 85 90 A0         [24] 1466 	mov	_P2,_P1
                           00006D  1467 	C$portIO.c$72$2$24 ==.
                                   1468 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:72: printf("p1: %X\tp2: %X\tp1_b: %u%u%u%u %u%u%u%u\tp2_b: %u%u%u%u %u%u%u%u\n\r",P1,P2, P1_7, P1_6, P1_5, P1_4, P1_3, P1_2, P1_1, P1_0, P2_7, P2_6, P2_5, P2_4, P2_3, P2_2, P2_1, P2_0);
      0000CF A2 A0            [12] 1469 	mov	c,_P2_0
      0000D1 E4               [12] 1470 	clr	a
      0000D2 33               [12] 1471 	rlc	a
      0000D3 FE               [12] 1472 	mov	r6,a
      0000D4 7F 00            [12] 1473 	mov	r7,#0x00
      0000D6 A2 A1            [12] 1474 	mov	c,_P2_1
      0000D8 E4               [12] 1475 	clr	a
      0000D9 33               [12] 1476 	rlc	a
      0000DA FC               [12] 1477 	mov	r4,a
      0000DB 7D 00            [12] 1478 	mov	r5,#0x00
      0000DD A2 A2            [12] 1479 	mov	c,_P2_2
      0000DF E4               [12] 1480 	clr	a
      0000E0 33               [12] 1481 	rlc	a
      0000E1 FA               [12] 1482 	mov	r2,a
      0000E2 7B 00            [12] 1483 	mov	r3,#0x00
      0000E4 A2 A3            [12] 1484 	mov	c,_P2_3
      0000E6 E4               [12] 1485 	clr	a
      0000E7 33               [12] 1486 	rlc	a
      0000E8 F5 22            [12] 1487 	mov	_main_sloc0_1_0,a
      0000EA 75 23 00         [24] 1488 	mov	(_main_sloc0_1_0 + 1),#0x00
      0000ED A2 A4            [12] 1489 	mov	c,_P2_4
      0000EF E4               [12] 1490 	clr	a
      0000F0 33               [12] 1491 	rlc	a
      0000F1 F5 24            [12] 1492 	mov	_main_sloc1_1_0,a
      0000F3 75 25 00         [24] 1493 	mov	(_main_sloc1_1_0 + 1),#0x00
      0000F6 A2 A5            [12] 1494 	mov	c,_P2_5
      0000F8 E4               [12] 1495 	clr	a
      0000F9 33               [12] 1496 	rlc	a
      0000FA F5 26            [12] 1497 	mov	_main_sloc2_1_0,a
      0000FC 75 27 00         [24] 1498 	mov	(_main_sloc2_1_0 + 1),#0x00
      0000FF A2 A6            [12] 1499 	mov	c,_P2_6
      000101 E4               [12] 1500 	clr	a
      000102 33               [12] 1501 	rlc	a
      000103 F5 28            [12] 1502 	mov	_main_sloc3_1_0,a
      000105 75 29 00         [24] 1503 	mov	(_main_sloc3_1_0 + 1),#0x00
      000108 A2 A7            [12] 1504 	mov	c,_P2_7
      00010A E4               [12] 1505 	clr	a
      00010B 33               [12] 1506 	rlc	a
      00010C F5 2A            [12] 1507 	mov	_main_sloc4_1_0,a
      00010E 75 2B 00         [24] 1508 	mov	(_main_sloc4_1_0 + 1),#0x00
      000111 A2 90            [12] 1509 	mov	c,_P1_0
      000113 E4               [12] 1510 	clr	a
      000114 33               [12] 1511 	rlc	a
      000115 F5 2C            [12] 1512 	mov	_main_sloc5_1_0,a
      000117 75 2D 00         [24] 1513 	mov	(_main_sloc5_1_0 + 1),#0x00
      00011A A2 91            [12] 1514 	mov	c,_P1_1
      00011C E4               [12] 1515 	clr	a
      00011D 33               [12] 1516 	rlc	a
      00011E F5 2E            [12] 1517 	mov	_main_sloc6_1_0,a
      000120 75 2F 00         [24] 1518 	mov	(_main_sloc6_1_0 + 1),#0x00
      000123 A2 92            [12] 1519 	mov	c,_P1_2
      000125 E4               [12] 1520 	clr	a
      000126 33               [12] 1521 	rlc	a
      000127 F5 30            [12] 1522 	mov	_main_sloc7_1_0,a
      000129 75 31 00         [24] 1523 	mov	(_main_sloc7_1_0 + 1),#0x00
      00012C A2 93            [12] 1524 	mov	c,_P1_3
      00012E E4               [12] 1525 	clr	a
      00012F 33               [12] 1526 	rlc	a
      000130 F5 32            [12] 1527 	mov	_main_sloc8_1_0,a
      000132 75 33 00         [24] 1528 	mov	(_main_sloc8_1_0 + 1),#0x00
      000135 A2 94            [12] 1529 	mov	c,_P1_4
      000137 E4               [12] 1530 	clr	a
      000138 33               [12] 1531 	rlc	a
      000139 F5 34            [12] 1532 	mov	_main_sloc9_1_0,a
      00013B 75 35 00         [24] 1533 	mov	(_main_sloc9_1_0 + 1),#0x00
      00013E A2 95            [12] 1534 	mov	c,_P1_5
      000140 E4               [12] 1535 	clr	a
      000141 33               [12] 1536 	rlc	a
      000142 F5 36            [12] 1537 	mov	_main_sloc10_1_0,a
      000144 75 37 00         [24] 1538 	mov	(_main_sloc10_1_0 + 1),#0x00
      000147 A2 96            [12] 1539 	mov	c,_P1_6
      000149 E4               [12] 1540 	clr	a
      00014A 33               [12] 1541 	rlc	a
      00014B F5 38            [12] 1542 	mov	_main_sloc11_1_0,a
      00014D 75 39 00         [24] 1543 	mov	(_main_sloc11_1_0 + 1),#0x00
      000150 A2 97            [12] 1544 	mov	c,_P1_7
      000152 E4               [12] 1545 	clr	a
      000153 33               [12] 1546 	rlc	a
      000154 F5 3A            [12] 1547 	mov	_main_sloc12_1_0,a
      000156 75 3B 00         [24] 1548 	mov	(_main_sloc12_1_0 + 1),#0x00
      000159 85 A0 3C         [24] 1549 	mov	_main_sloc13_1_0,_P2
      00015C 75 3D 00         [24] 1550 	mov	(_main_sloc13_1_0 + 1),#0x00
      00015F A8 90            [24] 1551 	mov	r0,_P1
      000161 79 00            [12] 1552 	mov	r1,#0x00
      000163 C0 06            [24] 1553 	push	ar6
      000165 C0 07            [24] 1554 	push	ar7
      000167 C0 04            [24] 1555 	push	ar4
      000169 C0 05            [24] 1556 	push	ar5
      00016B C0 02            [24] 1557 	push	ar2
      00016D C0 03            [24] 1558 	push	ar3
      00016F C0 22            [24] 1559 	push	_main_sloc0_1_0
      000171 C0 23            [24] 1560 	push	(_main_sloc0_1_0 + 1)
      000173 C0 24            [24] 1561 	push	_main_sloc1_1_0
      000175 C0 25            [24] 1562 	push	(_main_sloc1_1_0 + 1)
      000177 C0 26            [24] 1563 	push	_main_sloc2_1_0
      000179 C0 27            [24] 1564 	push	(_main_sloc2_1_0 + 1)
      00017B C0 28            [24] 1565 	push	_main_sloc3_1_0
      00017D C0 29            [24] 1566 	push	(_main_sloc3_1_0 + 1)
      00017F C0 2A            [24] 1567 	push	_main_sloc4_1_0
      000181 C0 2B            [24] 1568 	push	(_main_sloc4_1_0 + 1)
      000183 C0 2C            [24] 1569 	push	_main_sloc5_1_0
      000185 C0 2D            [24] 1570 	push	(_main_sloc5_1_0 + 1)
      000187 C0 2E            [24] 1571 	push	_main_sloc6_1_0
      000189 C0 2F            [24] 1572 	push	(_main_sloc6_1_0 + 1)
      00018B C0 30            [24] 1573 	push	_main_sloc7_1_0
      00018D C0 31            [24] 1574 	push	(_main_sloc7_1_0 + 1)
      00018F C0 32            [24] 1575 	push	_main_sloc8_1_0
      000191 C0 33            [24] 1576 	push	(_main_sloc8_1_0 + 1)
      000193 C0 34            [24] 1577 	push	_main_sloc9_1_0
      000195 C0 35            [24] 1578 	push	(_main_sloc9_1_0 + 1)
      000197 C0 36            [24] 1579 	push	_main_sloc10_1_0
      000199 C0 37            [24] 1580 	push	(_main_sloc10_1_0 + 1)
      00019B C0 38            [24] 1581 	push	_main_sloc11_1_0
      00019D C0 39            [24] 1582 	push	(_main_sloc11_1_0 + 1)
      00019F C0 3A            [24] 1583 	push	_main_sloc12_1_0
      0001A1 C0 3B            [24] 1584 	push	(_main_sloc12_1_0 + 1)
      0001A3 C0 3C            [24] 1585 	push	_main_sloc13_1_0
      0001A5 C0 3D            [24] 1586 	push	(_main_sloc13_1_0 + 1)
      0001A7 C0 00            [24] 1587 	push	ar0
      0001A9 C0 01            [24] 1588 	push	ar1
      0001AB 74 B9            [12] 1589 	mov	a,#___str_3
      0001AD C0 E0            [24] 1590 	push	acc
      0001AF 74 08            [12] 1591 	mov	a,#(___str_3 >> 8)
      0001B1 C0 E0            [24] 1592 	push	acc
      0001B3 74 80            [12] 1593 	mov	a,#0x80
      0001B5 C0 E0            [24] 1594 	push	acc
      0001B7 12 02 81         [24] 1595 	lcall	_printf
      0001BA E5 81            [12] 1596 	mov	a,sp
      0001BC 24 D9            [12] 1597 	add	a,#0xd9
      0001BE F5 81            [12] 1598 	mov	sp,a
      0001C0 02 00 CC         [24] 1599 	ljmp	00102$
                           000161  1600 	C$portIO.c$74$1$23 ==.
                           000161  1601 	XG$main$0$0 ==.
      0001C3 22               [24] 1602 	ret
                                   1603 ;------------------------------------------------------------
                                   1604 ;Allocation info for local variables in function 'SYSCLK_INIT'
                                   1605 ;------------------------------------------------------------
                                   1606 ;i                         Allocated to registers r5 r6 
                                   1607 ;SFRPAGE_SAVE              Allocated to registers r7 
                                   1608 ;------------------------------------------------------------
                           000162  1609 	G$SYSCLK_INIT$0$0 ==.
                           000162  1610 	C$portIO.c$82$1$23 ==.
                                   1611 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:82: void SYSCLK_INIT(void)
                                   1612 ;	-----------------------------------------
                                   1613 ;	 function SYSCLK_INIT
                                   1614 ;	-----------------------------------------
      0001C4                       1615 _SYSCLK_INIT:
                           000162  1616 	C$portIO.c$87$1$26 ==.
                                   1617 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:87: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
      0001C4 AF 84            [24] 1618 	mov	r7,_SFRPAGE
                           000164  1619 	C$portIO.c$89$1$26 ==.
                                   1620 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:89: SFRPAGE = CONFIG_PAGE;
      0001C6 75 84 0F         [24] 1621 	mov	_SFRPAGE,#0x0f
                           000167  1622 	C$portIO.c$90$1$26 ==.
                                   1623 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:90: OSCXCN  = 0x67;                     // Start ext osc with 22.1184MHz crystal
      0001C9 75 8C 67         [24] 1624 	mov	_OSCXCN,#0x67
                           00016A  1625 	C$portIO.c$91$1$26 ==.
                                   1626 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:91: for(i=0; i < 256; i++);             // Wait for the oscillator to start up
      0001CC 7D 00            [12] 1627 	mov	r5,#0x00
      0001CE 7E 01            [12] 1628 	mov	r6,#0x01
      0001D0                       1629 00111$:
      0001D0 1D               [12] 1630 	dec	r5
      0001D1 BD FF 01         [24] 1631 	cjne	r5,#0xff,00141$
      0001D4 1E               [12] 1632 	dec	r6
      0001D5                       1633 00141$:
      0001D5 ED               [12] 1634 	mov	a,r5
      0001D6 4E               [12] 1635 	orl	a,r6
      0001D7 70 F7            [24] 1636 	jnz	00111$
                           000177  1637 	C$portIO.c$92$1$26 ==.
                                   1638 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:92: while(!(OSCXCN & 0x80));
      0001D9                       1639 00102$:
      0001D9 E5 8C            [12] 1640 	mov	a,_OSCXCN
      0001DB 30 E7 FB         [24] 1641 	jnb	acc.7,00102$
                           00017C  1642 	C$portIO.c$93$1$26 ==.
                                   1643 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:93: CLKSEL  = 0x01;
      0001DE 75 97 01         [24] 1644 	mov	_CLKSEL,#0x01
                           00017F  1645 	C$portIO.c$94$1$26 ==.
                                   1646 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:94: OSCICN  = 0x00;
      0001E1 75 8A 00         [24] 1647 	mov	_OSCICN,#0x00
                           000182  1648 	C$portIO.c$96$1$26 ==.
                                   1649 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:96: SFRPAGE = CONFIG_PAGE;
      0001E4 75 84 0F         [24] 1650 	mov	_SFRPAGE,#0x0f
                           000185  1651 	C$portIO.c$97$1$26 ==.
                                   1652 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:97: PLL0CN  = 0x04;
      0001E7 75 89 04         [24] 1653 	mov	_PLL0CN,#0x04
                           000188  1654 	C$portIO.c$98$1$26 ==.
                                   1655 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:98: SFRPAGE = LEGACY_PAGE;
      0001EA 75 84 00         [24] 1656 	mov	_SFRPAGE,#0x00
                           00018B  1657 	C$portIO.c$99$1$26 ==.
                                   1658 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:99: FLSCL   = 0x10;
      0001ED 75 B7 10         [24] 1659 	mov	_FLSCL,#0x10
                           00018E  1660 	C$portIO.c$100$1$26 ==.
                                   1661 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:100: SFRPAGE = CONFIG_PAGE;
      0001F0 75 84 0F         [24] 1662 	mov	_SFRPAGE,#0x0f
                           000191  1663 	C$portIO.c$101$1$26 ==.
                                   1664 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:101: PLL0CN |= 0x01;
      0001F3 43 89 01         [24] 1665 	orl	_PLL0CN,#0x01
                           000194  1666 	C$portIO.c$102$1$26 ==.
                                   1667 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:102: PLL0DIV = 0x04;
      0001F6 75 8D 04         [24] 1668 	mov	_PLL0DIV,#0x04
                           000197  1669 	C$portIO.c$103$1$26 ==.
                                   1670 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:103: PLL0FLT = 0x01;
      0001F9 75 8F 01         [24] 1671 	mov	_PLL0FLT,#0x01
                           00019A  1672 	C$portIO.c$104$1$26 ==.
                                   1673 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:104: PLL0MUL = 0x09;
      0001FC 75 8E 09         [24] 1674 	mov	_PLL0MUL,#0x09
                           00019D  1675 	C$portIO.c$105$1$26 ==.
                                   1676 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:105: for(i=0; i < 256; i++);
      0001FF 7D 00            [12] 1677 	mov	r5,#0x00
      000201 7E 01            [12] 1678 	mov	r6,#0x01
      000203                       1679 00114$:
      000203 1D               [12] 1680 	dec	r5
      000204 BD FF 01         [24] 1681 	cjne	r5,#0xff,00144$
      000207 1E               [12] 1682 	dec	r6
      000208                       1683 00144$:
      000208 ED               [12] 1684 	mov	a,r5
      000209 4E               [12] 1685 	orl	a,r6
      00020A 70 F7            [24] 1686 	jnz	00114$
                           0001AA  1687 	C$portIO.c$106$1$26 ==.
                                   1688 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:106: PLL0CN |= 0x02;
      00020C 43 89 02         [24] 1689 	orl	_PLL0CN,#0x02
                           0001AD  1690 	C$portIO.c$107$1$26 ==.
                                   1691 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:107: while(!(PLL0CN & 0x10));
      00020F                       1692 00106$:
      00020F E5 89            [12] 1693 	mov	a,_PLL0CN
      000211 30 E4 FB         [24] 1694 	jnb	acc.4,00106$
                           0001B2  1695 	C$portIO.c$108$1$26 ==.
                                   1696 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:108: CLKSEL  = 0x02;
      000214 75 97 02         [24] 1697 	mov	_CLKSEL,#0x02
                           0001B5  1698 	C$portIO.c$110$1$26 ==.
                                   1699 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:110: SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
      000217 8F 84            [24] 1700 	mov	_SFRPAGE,r7
                           0001B7  1701 	C$portIO.c$111$1$26 ==.
                           0001B7  1702 	XG$SYSCLK_INIT$0$0 ==.
      000219 22               [24] 1703 	ret
                                   1704 ;------------------------------------------------------------
                                   1705 ;Allocation info for local variables in function 'PORT_INIT'
                                   1706 ;------------------------------------------------------------
                                   1707 ;SFRPAGE_SAVE              Allocated to registers r7 
                                   1708 ;------------------------------------------------------------
                           0001B8  1709 	G$PORT_INIT$0$0 ==.
                           0001B8  1710 	C$portIO.c$119$1$26 ==.
                                   1711 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:119: void PORT_INIT(void)
                                   1712 ;	-----------------------------------------
                                   1713 ;	 function PORT_INIT
                                   1714 ;	-----------------------------------------
      00021A                       1715 _PORT_INIT:
                           0001B8  1716 	C$portIO.c$123$1$28 ==.
                                   1717 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:123: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
      00021A AF 84            [24] 1718 	mov	r7,_SFRPAGE
                           0001BA  1719 	C$portIO.c$125$1$28 ==.
                                   1720 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:125: SFRPAGE  = CONFIG_PAGE;
      00021C 75 84 0F         [24] 1721 	mov	_SFRPAGE,#0x0f
                           0001BD  1722 	C$portIO.c$126$1$28 ==.
                                   1723 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:126: XBR0     = 0x04;                    // Enable UART0
      00021F 75 E1 04         [24] 1724 	mov	_XBR0,#0x04
                           0001C0  1725 	C$portIO.c$127$1$28 ==.
                                   1726 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:127: XBR1     = 0x00;
      000222 75 E2 00         [24] 1727 	mov	_XBR1,#0x00
                           0001C3  1728 	C$portIO.c$128$1$28 ==.
                                   1729 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:128: XBR2     = 0x40;                    // Enable Crossbar and weak pull-up
      000225 75 E3 40         [24] 1730 	mov	_XBR2,#0x40
                           0001C6  1731 	C$portIO.c$129$1$28 ==.
                                   1732 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:129: P0MDOUT |= 0x01;                    // Set TX0 on P0.0 pin to push-pull    
      000228 43 A4 01         [24] 1733 	orl	_P0MDOUT,#0x01
                           0001C9  1734 	C$portIO.c$133$1$28 ==.
                                   1735 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:133: P1MDOUT = 0x00;                     // Set all port 1 pins to open drain (input)
      00022B 75 A5 00         [24] 1736 	mov	_P1MDOUT,#0x00
                           0001CC  1737 	C$portIO.c$134$1$28 ==.
                                   1738 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:134: P1 = 0xFF;							// Set port 1 pins for input
      00022E 75 90 FF         [24] 1739 	mov	_P1,#0xff
                           0001CF  1740 	C$portIO.c$137$1$28 ==.
                                   1741 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:137: P2MDOUT |= 0xFF;                    // Set all port 2 pins to push-pull (output)
      000231 E5 A6            [12] 1742 	mov	a,_P2MDOUT
      000233 75 A6 FF         [24] 1743 	mov	_P2MDOUT,#0xff
                           0001D4  1744 	C$portIO.c$140$1$28 ==.
                                   1745 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:140: SFRPAGE  = SFRPAGE_SAVE;            // Restore SFR page
      000236 8F 84            [24] 1746 	mov	_SFRPAGE,r7
                           0001D6  1747 	C$portIO.c$141$1$28 ==.
                           0001D6  1748 	XG$PORT_INIT$0$0 ==.
      000238 22               [24] 1749 	ret
                                   1750 ;------------------------------------------------------------
                                   1751 ;Allocation info for local variables in function 'UART0_INIT'
                                   1752 ;------------------------------------------------------------
                                   1753 ;SFRPAGE_SAVE              Allocated to registers r7 
                                   1754 ;------------------------------------------------------------
                           0001D7  1755 	G$UART0_INIT$0$0 ==.
                           0001D7  1756 	C$portIO.c$149$1$28 ==.
                                   1757 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:149: void UART0_INIT(void)
                                   1758 ;	-----------------------------------------
                                   1759 ;	 function UART0_INIT
                                   1760 ;	-----------------------------------------
      000239                       1761 _UART0_INIT:
                           0001D7  1762 	C$portIO.c$153$1$30 ==.
                                   1763 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:153: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
      000239 AF 84            [24] 1764 	mov	r7,_SFRPAGE
                           0001D9  1765 	C$portIO.c$155$1$30 ==.
                                   1766 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:155: SFRPAGE = TIMER01_PAGE;
      00023B 75 84 00         [24] 1767 	mov	_SFRPAGE,#0x00
                           0001DC  1768 	C$portIO.c$156$1$30 ==.
                                   1769 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:156: TMOD   &= ~0xF0;
      00023E 53 89 0F         [24] 1770 	anl	_TMOD,#0x0f
                           0001DF  1771 	C$portIO.c$157$1$30 ==.
                                   1772 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:157: TMOD   |=  0x20;                    // Timer1, Mode 2, 8-bit reload
      000241 43 89 20         [24] 1773 	orl	_TMOD,#0x20
                           0001E2  1774 	C$portIO.c$158$1$30 ==.
                                   1775 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:158: TH1     = -(SYSCLK/BAUDRATE/16);    // Set Timer1 reload baudrate value T1 Hi Byte
      000244 75 8D E5         [24] 1776 	mov	_TH1,#0xe5
                           0001E5  1777 	C$portIO.c$159$1$30 ==.
                                   1778 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:159: CKCON  |= 0x10;                     // Timer1 uses SYSCLK as time base
      000247 43 8E 10         [24] 1779 	orl	_CKCON,#0x10
                           0001E8  1780 	C$portIO.c$160$1$30 ==.
                                   1781 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:160: TL1     = TH1;
      00024A 85 8D 8B         [24] 1782 	mov	_TL1,_TH1
                           0001EB  1783 	C$portIO.c$161$1$30 ==.
                                   1784 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:161: TR1     = 1;                        // Start Timer1
      00024D D2 8E            [12] 1785 	setb	_TR1
                           0001ED  1786 	C$portIO.c$163$1$30 ==.
                                   1787 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:163: SFRPAGE = UART0_PAGE;
      00024F 75 84 00         [24] 1788 	mov	_SFRPAGE,#0x00
                           0001F0  1789 	C$portIO.c$164$1$30 ==.
                                   1790 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:164: SCON0   = 0x50;                     // Mode 1, 8-bit UART, enable RX
      000252 75 98 50         [24] 1791 	mov	_SCON0,#0x50
                           0001F3  1792 	C$portIO.c$165$1$30 ==.
                                   1793 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:165: SSTA0   = 0x10;                     // SMOD0 = 1
      000255 75 91 10         [24] 1794 	mov	_SSTA0,#0x10
                           0001F6  1795 	C$portIO.c$166$1$30 ==.
                                   1796 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:166: TI0     = 1;                        // Indicate TX0 ready
      000258 D2 99            [12] 1797 	setb	_TI0
                           0001F8  1798 	C$portIO.c$168$1$30 ==.
                                   1799 ;	C:\Users\John\Documents\MPS\lab1\portIO.c:168: SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
      00025A 8F 84            [24] 1800 	mov	_SFRPAGE,r7
                           0001FA  1801 	C$portIO.c$169$1$30 ==.
                           0001FA  1802 	XG$UART0_INIT$0$0 ==.
      00025C 22               [24] 1803 	ret
                                   1804 	.area CSEG    (CODE)
                                   1805 	.area CONST   (CODE)
                           000000  1806 FportIO$__str_0$0$0 == .
      00089C                       1807 ___str_0:
      00089C 1B                    1808 	.db 0x1b
      00089D 5B 33 33 3B 34 34 6D  1809 	.ascii "[33;44m"
      0008A4 00                    1810 	.db 0x00
                           000009  1811 FportIO$__str_1$0$0 == .
      0008A5                       1812 ___str_1:
      0008A5 1B                    1813 	.db 0x1b
      0008A6 5B 32 4A              1814 	.ascii "[2J"
      0008A9 00                    1815 	.db 0x00
                           00000E  1816 FportIO$__str_2$0$0 == .
      0008AA                       1817 ___str_2:
      0008AA 48 65 6C 6C 6F 20 57  1818 	.ascii "Hello World!"
             6F 72 6C 64 21
      0008B6 0A                    1819 	.db 0x0a
      0008B7 0D                    1820 	.db 0x0d
      0008B8 00                    1821 	.db 0x00
                           00001D  1822 FportIO$__str_3$0$0 == .
      0008B9                       1823 ___str_3:
      0008B9 70 31 3A 20 25 58     1824 	.ascii "p1: %X"
      0008BF 09                    1825 	.db 0x09
      0008C0 70 32 3A 20 25 58     1826 	.ascii "p2: %X"
      0008C6 09                    1827 	.db 0x09
      0008C7 70 31 5F 62 3A 20 25  1828 	.ascii "p1_b: %u%u%u%u %u%u%u%u"
             75 25 75 25 75 25 75
             20 25 75 25 75 25 75
             25 75
      0008DE 09                    1829 	.db 0x09
      0008DF 70 32 5F 62 3A 20 25  1830 	.ascii "p2_b: %u%u%u%u %u%u%u%"
             75 25 75 25 75 25 75
             20 25 75 25 75 25 75
             25
      0008F5 75                    1831 	.ascii "u"
      0008F6 0A                    1832 	.db 0x0a
      0008F7 0D                    1833 	.db 0x0d
      0008F8 00                    1834 	.db 0x00
                                   1835 	.area XINIT   (CODE)
                                   1836 	.area CABS    (ABS,CODE)
