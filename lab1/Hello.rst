                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module Hello
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _printf
                                     12 	.globl _P7_7
                                     13 	.globl _P7_6
                                     14 	.globl _P7_5
                                     15 	.globl _P7_4
                                     16 	.globl _P7_3
                                     17 	.globl _P7_2
                                     18 	.globl _P7_1
                                     19 	.globl _P7_0
                                     20 	.globl _SPIF
                                     21 	.globl _WCOL
                                     22 	.globl _MODF
                                     23 	.globl _RXOVRN
                                     24 	.globl _NSSMD1
                                     25 	.globl _NSSMD0
                                     26 	.globl _TXBMT
                                     27 	.globl _SPIEN
                                     28 	.globl _P6_7
                                     29 	.globl _P6_6
                                     30 	.globl _P6_5
                                     31 	.globl _P6_4
                                     32 	.globl _P6_3
                                     33 	.globl _P6_2
                                     34 	.globl _P6_1
                                     35 	.globl _P6_0
                                     36 	.globl _AD2EN
                                     37 	.globl _AD2TM
                                     38 	.globl _AD2INT
                                     39 	.globl _AD2BUSY
                                     40 	.globl _AD2CM2
                                     41 	.globl _AD2CM1
                                     42 	.globl _AD2CM0
                                     43 	.globl _AD2WINT
                                     44 	.globl _AD0EN
                                     45 	.globl _AD0TM
                                     46 	.globl _AD0INT
                                     47 	.globl _AD0BUSY
                                     48 	.globl _AD0CM1
                                     49 	.globl _AD0CM0
                                     50 	.globl _AD0WINT
                                     51 	.globl _AD0LJST
                                     52 	.globl _P5_7
                                     53 	.globl _P5_6
                                     54 	.globl _P5_5
                                     55 	.globl _P5_4
                                     56 	.globl _P5_3
                                     57 	.globl _P5_2
                                     58 	.globl _P5_1
                                     59 	.globl _P5_0
                                     60 	.globl _CF
                                     61 	.globl _CR
                                     62 	.globl _CCF5
                                     63 	.globl _CCF4
                                     64 	.globl _CCF3
                                     65 	.globl _CCF2
                                     66 	.globl _CCF1
                                     67 	.globl _CCF0
                                     68 	.globl _CY
                                     69 	.globl _AC
                                     70 	.globl _F0
                                     71 	.globl _RS1
                                     72 	.globl _RS0
                                     73 	.globl _OV
                                     74 	.globl _F1
                                     75 	.globl _P
                                     76 	.globl _P4_7
                                     77 	.globl _P4_6
                                     78 	.globl _P4_5
                                     79 	.globl _P4_4
                                     80 	.globl _P4_3
                                     81 	.globl _P4_2
                                     82 	.globl _P4_1
                                     83 	.globl _P4_0
                                     84 	.globl _TF4
                                     85 	.globl _EXF4
                                     86 	.globl _EXEN4
                                     87 	.globl _TR4
                                     88 	.globl _CT4
                                     89 	.globl _CPRL4
                                     90 	.globl _TF3
                                     91 	.globl _EXF3
                                     92 	.globl _EXEN3
                                     93 	.globl _TR3
                                     94 	.globl _CT3
                                     95 	.globl _CPRL3
                                     96 	.globl _TF2
                                     97 	.globl _EXF2
                                     98 	.globl _EXEN2
                                     99 	.globl _TR2
                                    100 	.globl _CT2
                                    101 	.globl _CPRL2
                                    102 	.globl _MAC0HO
                                    103 	.globl _MAC0Z
                                    104 	.globl _MAC0SO
                                    105 	.globl _MAC0N
                                    106 	.globl _BUSY
                                    107 	.globl _ENSMB
                                    108 	.globl _STA
                                    109 	.globl _STO
                                    110 	.globl _SI
                                    111 	.globl _AA
                                    112 	.globl _SMBFTE
                                    113 	.globl _SMBTOE
                                    114 	.globl _PT2
                                    115 	.globl _PS
                                    116 	.globl _PS0
                                    117 	.globl _PT1
                                    118 	.globl _PX1
                                    119 	.globl _PT0
                                    120 	.globl _PX0
                                    121 	.globl _P3_7
                                    122 	.globl _P3_6
                                    123 	.globl _P3_5
                                    124 	.globl _P3_4
                                    125 	.globl _P3_3
                                    126 	.globl _P3_2
                                    127 	.globl _P3_1
                                    128 	.globl _P3_0
                                    129 	.globl _EA
                                    130 	.globl _ET2
                                    131 	.globl _ES
                                    132 	.globl _ES0
                                    133 	.globl _ET1
                                    134 	.globl _EX1
                                    135 	.globl _ET0
                                    136 	.globl _EX0
                                    137 	.globl _P2_7
                                    138 	.globl _P2_6
                                    139 	.globl _P2_5
                                    140 	.globl _P2_4
                                    141 	.globl _P2_3
                                    142 	.globl _P2_2
                                    143 	.globl _P2_1
                                    144 	.globl _P2_0
                                    145 	.globl _S1MODE
                                    146 	.globl _MCE1
                                    147 	.globl _REN1
                                    148 	.globl _TB81
                                    149 	.globl _RB81
                                    150 	.globl _TI1
                                    151 	.globl _RI1
                                    152 	.globl _SM00
                                    153 	.globl _SM10
                                    154 	.globl _SM20
                                    155 	.globl _REN
                                    156 	.globl _REN0
                                    157 	.globl _TB80
                                    158 	.globl _RB80
                                    159 	.globl _TI
                                    160 	.globl _TI0
                                    161 	.globl _RI
                                    162 	.globl _RI0
                                    163 	.globl _P1_7
                                    164 	.globl _P1_6
                                    165 	.globl _P1_5
                                    166 	.globl _P1_4
                                    167 	.globl _P1_3
                                    168 	.globl _P1_2
                                    169 	.globl _P1_1
                                    170 	.globl _P1_0
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
                           000090   859 G$P1_0$0$0 == 0x0090
                           000090   860 _P1_0	=	0x0090
                           000091   861 G$P1_1$0$0 == 0x0091
                           000091   862 _P1_1	=	0x0091
                           000092   863 G$P1_2$0$0 == 0x0092
                           000092   864 _P1_2	=	0x0092
                           000093   865 G$P1_3$0$0 == 0x0093
                           000093   866 _P1_3	=	0x0093
                           000094   867 G$P1_4$0$0 == 0x0094
                           000094   868 _P1_4	=	0x0094
                           000095   869 G$P1_5$0$0 == 0x0095
                           000095   870 _P1_5	=	0x0095
                           000096   871 G$P1_6$0$0 == 0x0096
                           000096   872 _P1_6	=	0x0096
                           000097   873 G$P1_7$0$0 == 0x0097
                           000097   874 _P1_7	=	0x0097
                           000098   875 G$RI0$0$0 == 0x0098
                           000098   876 _RI0	=	0x0098
                           000098   877 G$RI$0$0 == 0x0098
                           000098   878 _RI	=	0x0098
                           000099   879 G$TI0$0$0 == 0x0099
                           000099   880 _TI0	=	0x0099
                           000099   881 G$TI$0$0 == 0x0099
                           000099   882 _TI	=	0x0099
                           00009A   883 G$RB80$0$0 == 0x009a
                           00009A   884 _RB80	=	0x009a
                           00009B   885 G$TB80$0$0 == 0x009b
                           00009B   886 _TB80	=	0x009b
                           00009C   887 G$REN0$0$0 == 0x009c
                           00009C   888 _REN0	=	0x009c
                           00009C   889 G$REN$0$0 == 0x009c
                           00009C   890 _REN	=	0x009c
                           00009D   891 G$SM20$0$0 == 0x009d
                           00009D   892 _SM20	=	0x009d
                           00009E   893 G$SM10$0$0 == 0x009e
                           00009E   894 _SM10	=	0x009e
                           00009F   895 G$SM00$0$0 == 0x009f
                           00009F   896 _SM00	=	0x009f
                           000098   897 G$RI1$0$0 == 0x0098
                           000098   898 _RI1	=	0x0098
                           000099   899 G$TI1$0$0 == 0x0099
                           000099   900 _TI1	=	0x0099
                           00009A   901 G$RB81$0$0 == 0x009a
                           00009A   902 _RB81	=	0x009a
                           00009B   903 G$TB81$0$0 == 0x009b
                           00009B   904 _TB81	=	0x009b
                           00009C   905 G$REN1$0$0 == 0x009c
                           00009C   906 _REN1	=	0x009c
                           00009D   907 G$MCE1$0$0 == 0x009d
                           00009D   908 _MCE1	=	0x009d
                           00009F   909 G$S1MODE$0$0 == 0x009f
                           00009F   910 _S1MODE	=	0x009f
                           0000A0   911 G$P2_0$0$0 == 0x00a0
                           0000A0   912 _P2_0	=	0x00a0
                           0000A1   913 G$P2_1$0$0 == 0x00a1
                           0000A1   914 _P2_1	=	0x00a1
                           0000A2   915 G$P2_2$0$0 == 0x00a2
                           0000A2   916 _P2_2	=	0x00a2
                           0000A3   917 G$P2_3$0$0 == 0x00a3
                           0000A3   918 _P2_3	=	0x00a3
                           0000A4   919 G$P2_4$0$0 == 0x00a4
                           0000A4   920 _P2_4	=	0x00a4
                           0000A5   921 G$P2_5$0$0 == 0x00a5
                           0000A5   922 _P2_5	=	0x00a5
                           0000A6   923 G$P2_6$0$0 == 0x00a6
                           0000A6   924 _P2_6	=	0x00a6
                           0000A7   925 G$P2_7$0$0 == 0x00a7
                           0000A7   926 _P2_7	=	0x00a7
                           0000A8   927 G$EX0$0$0 == 0x00a8
                           0000A8   928 _EX0	=	0x00a8
                           0000A9   929 G$ET0$0$0 == 0x00a9
                           0000A9   930 _ET0	=	0x00a9
                           0000AA   931 G$EX1$0$0 == 0x00aa
                           0000AA   932 _EX1	=	0x00aa
                           0000AB   933 G$ET1$0$0 == 0x00ab
                           0000AB   934 _ET1	=	0x00ab
                           0000AC   935 G$ES0$0$0 == 0x00ac
                           0000AC   936 _ES0	=	0x00ac
                           0000AC   937 G$ES$0$0 == 0x00ac
                           0000AC   938 _ES	=	0x00ac
                           0000AD   939 G$ET2$0$0 == 0x00ad
                           0000AD   940 _ET2	=	0x00ad
                           0000AF   941 G$EA$0$0 == 0x00af
                           0000AF   942 _EA	=	0x00af
                           0000B0   943 G$P3_0$0$0 == 0x00b0
                           0000B0   944 _P3_0	=	0x00b0
                           0000B1   945 G$P3_1$0$0 == 0x00b1
                           0000B1   946 _P3_1	=	0x00b1
                           0000B2   947 G$P3_2$0$0 == 0x00b2
                           0000B2   948 _P3_2	=	0x00b2
                           0000B3   949 G$P3_3$0$0 == 0x00b3
                           0000B3   950 _P3_3	=	0x00b3
                           0000B4   951 G$P3_4$0$0 == 0x00b4
                           0000B4   952 _P3_4	=	0x00b4
                           0000B5   953 G$P3_5$0$0 == 0x00b5
                           0000B5   954 _P3_5	=	0x00b5
                           0000B6   955 G$P3_6$0$0 == 0x00b6
                           0000B6   956 _P3_6	=	0x00b6
                           0000B7   957 G$P3_7$0$0 == 0x00b7
                           0000B7   958 _P3_7	=	0x00b7
                           0000B8   959 G$PX0$0$0 == 0x00b8
                           0000B8   960 _PX0	=	0x00b8
                           0000B9   961 G$PT0$0$0 == 0x00b9
                           0000B9   962 _PT0	=	0x00b9
                           0000BA   963 G$PX1$0$0 == 0x00ba
                           0000BA   964 _PX1	=	0x00ba
                           0000BB   965 G$PT1$0$0 == 0x00bb
                           0000BB   966 _PT1	=	0x00bb
                           0000BC   967 G$PS0$0$0 == 0x00bc
                           0000BC   968 _PS0	=	0x00bc
                           0000BC   969 G$PS$0$0 == 0x00bc
                           0000BC   970 _PS	=	0x00bc
                           0000BD   971 G$PT2$0$0 == 0x00bd
                           0000BD   972 _PT2	=	0x00bd
                           0000C0   973 G$SMBTOE$0$0 == 0x00c0
                           0000C0   974 _SMBTOE	=	0x00c0
                           0000C1   975 G$SMBFTE$0$0 == 0x00c1
                           0000C1   976 _SMBFTE	=	0x00c1
                           0000C2   977 G$AA$0$0 == 0x00c2
                           0000C2   978 _AA	=	0x00c2
                           0000C3   979 G$SI$0$0 == 0x00c3
                           0000C3   980 _SI	=	0x00c3
                           0000C4   981 G$STO$0$0 == 0x00c4
                           0000C4   982 _STO	=	0x00c4
                           0000C5   983 G$STA$0$0 == 0x00c5
                           0000C5   984 _STA	=	0x00c5
                           0000C6   985 G$ENSMB$0$0 == 0x00c6
                           0000C6   986 _ENSMB	=	0x00c6
                           0000C7   987 G$BUSY$0$0 == 0x00c7
                           0000C7   988 _BUSY	=	0x00c7
                           0000C0   989 G$MAC0N$0$0 == 0x00c0
                           0000C0   990 _MAC0N	=	0x00c0
                           0000C1   991 G$MAC0SO$0$0 == 0x00c1
                           0000C1   992 _MAC0SO	=	0x00c1
                           0000C2   993 G$MAC0Z$0$0 == 0x00c2
                           0000C2   994 _MAC0Z	=	0x00c2
                           0000C3   995 G$MAC0HO$0$0 == 0x00c3
                           0000C3   996 _MAC0HO	=	0x00c3
                           0000C8   997 G$CPRL2$0$0 == 0x00c8
                           0000C8   998 _CPRL2	=	0x00c8
                           0000C9   999 G$CT2$0$0 == 0x00c9
                           0000C9  1000 _CT2	=	0x00c9
                           0000CA  1001 G$TR2$0$0 == 0x00ca
                           0000CA  1002 _TR2	=	0x00ca
                           0000CB  1003 G$EXEN2$0$0 == 0x00cb
                           0000CB  1004 _EXEN2	=	0x00cb
                           0000CE  1005 G$EXF2$0$0 == 0x00ce
                           0000CE  1006 _EXF2	=	0x00ce
                           0000CF  1007 G$TF2$0$0 == 0x00cf
                           0000CF  1008 _TF2	=	0x00cf
                           0000C8  1009 G$CPRL3$0$0 == 0x00c8
                           0000C8  1010 _CPRL3	=	0x00c8
                           0000C9  1011 G$CT3$0$0 == 0x00c9
                           0000C9  1012 _CT3	=	0x00c9
                           0000CA  1013 G$TR3$0$0 == 0x00ca
                           0000CA  1014 _TR3	=	0x00ca
                           0000CB  1015 G$EXEN3$0$0 == 0x00cb
                           0000CB  1016 _EXEN3	=	0x00cb
                           0000CE  1017 G$EXF3$0$0 == 0x00ce
                           0000CE  1018 _EXF3	=	0x00ce
                           0000CF  1019 G$TF3$0$0 == 0x00cf
                           0000CF  1020 _TF3	=	0x00cf
                           0000C8  1021 G$CPRL4$0$0 == 0x00c8
                           0000C8  1022 _CPRL4	=	0x00c8
                           0000C9  1023 G$CT4$0$0 == 0x00c9
                           0000C9  1024 _CT4	=	0x00c9
                           0000CA  1025 G$TR4$0$0 == 0x00ca
                           0000CA  1026 _TR4	=	0x00ca
                           0000CB  1027 G$EXEN4$0$0 == 0x00cb
                           0000CB  1028 _EXEN4	=	0x00cb
                           0000CE  1029 G$EXF4$0$0 == 0x00ce
                           0000CE  1030 _EXF4	=	0x00ce
                           0000CF  1031 G$TF4$0$0 == 0x00cf
                           0000CF  1032 _TF4	=	0x00cf
                           0000C8  1033 G$P4_0$0$0 == 0x00c8
                           0000C8  1034 _P4_0	=	0x00c8
                           0000C9  1035 G$P4_1$0$0 == 0x00c9
                           0000C9  1036 _P4_1	=	0x00c9
                           0000CA  1037 G$P4_2$0$0 == 0x00ca
                           0000CA  1038 _P4_2	=	0x00ca
                           0000CB  1039 G$P4_3$0$0 == 0x00cb
                           0000CB  1040 _P4_3	=	0x00cb
                           0000CC  1041 G$P4_4$0$0 == 0x00cc
                           0000CC  1042 _P4_4	=	0x00cc
                           0000CD  1043 G$P4_5$0$0 == 0x00cd
                           0000CD  1044 _P4_5	=	0x00cd
                           0000CE  1045 G$P4_6$0$0 == 0x00ce
                           0000CE  1046 _P4_6	=	0x00ce
                           0000CF  1047 G$P4_7$0$0 == 0x00cf
                           0000CF  1048 _P4_7	=	0x00cf
                           0000D0  1049 G$P$0$0 == 0x00d0
                           0000D0  1050 _P	=	0x00d0
                           0000D1  1051 G$F1$0$0 == 0x00d1
                           0000D1  1052 _F1	=	0x00d1
                           0000D2  1053 G$OV$0$0 == 0x00d2
                           0000D2  1054 _OV	=	0x00d2
                           0000D3  1055 G$RS0$0$0 == 0x00d3
                           0000D3  1056 _RS0	=	0x00d3
                           0000D4  1057 G$RS1$0$0 == 0x00d4
                           0000D4  1058 _RS1	=	0x00d4
                           0000D5  1059 G$F0$0$0 == 0x00d5
                           0000D5  1060 _F0	=	0x00d5
                           0000D6  1061 G$AC$0$0 == 0x00d6
                           0000D6  1062 _AC	=	0x00d6
                           0000D7  1063 G$CY$0$0 == 0x00d7
                           0000D7  1064 _CY	=	0x00d7
                           0000D8  1065 G$CCF0$0$0 == 0x00d8
                           0000D8  1066 _CCF0	=	0x00d8
                           0000D9  1067 G$CCF1$0$0 == 0x00d9
                           0000D9  1068 _CCF1	=	0x00d9
                           0000DA  1069 G$CCF2$0$0 == 0x00da
                           0000DA  1070 _CCF2	=	0x00da
                           0000DB  1071 G$CCF3$0$0 == 0x00db
                           0000DB  1072 _CCF3	=	0x00db
                           0000DC  1073 G$CCF4$0$0 == 0x00dc
                           0000DC  1074 _CCF4	=	0x00dc
                           0000DD  1075 G$CCF5$0$0 == 0x00dd
                           0000DD  1076 _CCF5	=	0x00dd
                           0000DE  1077 G$CR$0$0 == 0x00de
                           0000DE  1078 _CR	=	0x00de
                           0000DF  1079 G$CF$0$0 == 0x00df
                           0000DF  1080 _CF	=	0x00df
                           0000D8  1081 G$P5_0$0$0 == 0x00d8
                           0000D8  1082 _P5_0	=	0x00d8
                           0000D9  1083 G$P5_1$0$0 == 0x00d9
                           0000D9  1084 _P5_1	=	0x00d9
                           0000DA  1085 G$P5_2$0$0 == 0x00da
                           0000DA  1086 _P5_2	=	0x00da
                           0000DB  1087 G$P5_3$0$0 == 0x00db
                           0000DB  1088 _P5_3	=	0x00db
                           0000DC  1089 G$P5_4$0$0 == 0x00dc
                           0000DC  1090 _P5_4	=	0x00dc
                           0000DD  1091 G$P5_5$0$0 == 0x00dd
                           0000DD  1092 _P5_5	=	0x00dd
                           0000DE  1093 G$P5_6$0$0 == 0x00de
                           0000DE  1094 _P5_6	=	0x00de
                           0000DF  1095 G$P5_7$0$0 == 0x00df
                           0000DF  1096 _P5_7	=	0x00df
                           0000E8  1097 G$AD0LJST$0$0 == 0x00e8
                           0000E8  1098 _AD0LJST	=	0x00e8
                           0000E9  1099 G$AD0WINT$0$0 == 0x00e9
                           0000E9  1100 _AD0WINT	=	0x00e9
                           0000EA  1101 G$AD0CM0$0$0 == 0x00ea
                           0000EA  1102 _AD0CM0	=	0x00ea
                           0000EB  1103 G$AD0CM1$0$0 == 0x00eb
                           0000EB  1104 _AD0CM1	=	0x00eb
                           0000EC  1105 G$AD0BUSY$0$0 == 0x00ec
                           0000EC  1106 _AD0BUSY	=	0x00ec
                           0000ED  1107 G$AD0INT$0$0 == 0x00ed
                           0000ED  1108 _AD0INT	=	0x00ed
                           0000EE  1109 G$AD0TM$0$0 == 0x00ee
                           0000EE  1110 _AD0TM	=	0x00ee
                           0000EF  1111 G$AD0EN$0$0 == 0x00ef
                           0000EF  1112 _AD0EN	=	0x00ef
                           0000E8  1113 G$AD2WINT$0$0 == 0x00e8
                           0000E8  1114 _AD2WINT	=	0x00e8
                           0000E9  1115 G$AD2CM0$0$0 == 0x00e9
                           0000E9  1116 _AD2CM0	=	0x00e9
                           0000EA  1117 G$AD2CM1$0$0 == 0x00ea
                           0000EA  1118 _AD2CM1	=	0x00ea
                           0000EB  1119 G$AD2CM2$0$0 == 0x00eb
                           0000EB  1120 _AD2CM2	=	0x00eb
                           0000EC  1121 G$AD2BUSY$0$0 == 0x00ec
                           0000EC  1122 _AD2BUSY	=	0x00ec
                           0000ED  1123 G$AD2INT$0$0 == 0x00ed
                           0000ED  1124 _AD2INT	=	0x00ed
                           0000EE  1125 G$AD2TM$0$0 == 0x00ee
                           0000EE  1126 _AD2TM	=	0x00ee
                           0000EF  1127 G$AD2EN$0$0 == 0x00ef
                           0000EF  1128 _AD2EN	=	0x00ef
                           0000E8  1129 G$P6_0$0$0 == 0x00e8
                           0000E8  1130 _P6_0	=	0x00e8
                           0000E9  1131 G$P6_1$0$0 == 0x00e9
                           0000E9  1132 _P6_1	=	0x00e9
                           0000EA  1133 G$P6_2$0$0 == 0x00ea
                           0000EA  1134 _P6_2	=	0x00ea
                           0000EB  1135 G$P6_3$0$0 == 0x00eb
                           0000EB  1136 _P6_3	=	0x00eb
                           0000EC  1137 G$P6_4$0$0 == 0x00ec
                           0000EC  1138 _P6_4	=	0x00ec
                           0000ED  1139 G$P6_5$0$0 == 0x00ed
                           0000ED  1140 _P6_5	=	0x00ed
                           0000EE  1141 G$P6_6$0$0 == 0x00ee
                           0000EE  1142 _P6_6	=	0x00ee
                           0000EF  1143 G$P6_7$0$0 == 0x00ef
                           0000EF  1144 _P6_7	=	0x00ef
                           0000F8  1145 G$SPIEN$0$0 == 0x00f8
                           0000F8  1146 _SPIEN	=	0x00f8
                           0000F9  1147 G$TXBMT$0$0 == 0x00f9
                           0000F9  1148 _TXBMT	=	0x00f9
                           0000FA  1149 G$NSSMD0$0$0 == 0x00fa
                           0000FA  1150 _NSSMD0	=	0x00fa
                           0000FB  1151 G$NSSMD1$0$0 == 0x00fb
                           0000FB  1152 _NSSMD1	=	0x00fb
                           0000FC  1153 G$RXOVRN$0$0 == 0x00fc
                           0000FC  1154 _RXOVRN	=	0x00fc
                           0000FD  1155 G$MODF$0$0 == 0x00fd
                           0000FD  1156 _MODF	=	0x00fd
                           0000FE  1157 G$WCOL$0$0 == 0x00fe
                           0000FE  1158 _WCOL	=	0x00fe
                           0000FF  1159 G$SPIF$0$0 == 0x00ff
                           0000FF  1160 _SPIF	=	0x00ff
                           0000F8  1161 G$P7_0$0$0 == 0x00f8
                           0000F8  1162 _P7_0	=	0x00f8
                           0000F9  1163 G$P7_1$0$0 == 0x00f9
                           0000F9  1164 _P7_1	=	0x00f9
                           0000FA  1165 G$P7_2$0$0 == 0x00fa
                           0000FA  1166 _P7_2	=	0x00fa
                           0000FB  1167 G$P7_3$0$0 == 0x00fb
                           0000FB  1168 _P7_3	=	0x00fb
                           0000FC  1169 G$P7_4$0$0 == 0x00fc
                           0000FC  1170 _P7_4	=	0x00fc
                           0000FD  1171 G$P7_5$0$0 == 0x00fd
                           0000FD  1172 _P7_5	=	0x00fd
                           0000FE  1173 G$P7_6$0$0 == 0x00fe
                           0000FE  1174 _P7_6	=	0x00fe
                           0000FF  1175 G$P7_7$0$0 == 0x00ff
                           0000FF  1176 _P7_7	=	0x00ff
                                   1177 ;--------------------------------------------------------
                                   1178 ; overlayable register banks
                                   1179 ;--------------------------------------------------------
                                   1180 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                       1181 	.ds 8
                                   1182 ;--------------------------------------------------------
                                   1183 ; internal ram data
                                   1184 ;--------------------------------------------------------
                                   1185 	.area DSEG    (DATA)
                                   1186 ;--------------------------------------------------------
                                   1187 ; overlayable items in internal ram 
                                   1188 ;--------------------------------------------------------
                                   1189 	.area	OSEG    (OVR,DATA)
                                   1190 	.area	OSEG    (OVR,DATA)
                                   1191 	.area	OSEG    (OVR,DATA)
                                   1192 	.area	OSEG    (OVR,DATA)
                                   1193 ;--------------------------------------------------------
                                   1194 ; Stack segment in internal ram 
                                   1195 ;--------------------------------------------------------
                                   1196 	.area	SSEG
      00003C                       1197 __start__stack:
      00003C                       1198 	.ds	1
                                   1199 
                                   1200 ;--------------------------------------------------------
                                   1201 ; indirectly addressable internal ram data
                                   1202 ;--------------------------------------------------------
                                   1203 	.area ISEG    (DATA)
                                   1204 ;--------------------------------------------------------
                                   1205 ; absolute internal ram data
                                   1206 ;--------------------------------------------------------
                                   1207 	.area IABS    (ABS,DATA)
                                   1208 	.area IABS    (ABS,DATA)
                                   1209 ;--------------------------------------------------------
                                   1210 ; bit data
                                   1211 ;--------------------------------------------------------
                                   1212 	.area BSEG    (BIT)
                                   1213 ;--------------------------------------------------------
                                   1214 ; paged external ram data
                                   1215 ;--------------------------------------------------------
                                   1216 	.area PSEG    (PAG,XDATA)
                                   1217 ;--------------------------------------------------------
                                   1218 ; external ram data
                                   1219 ;--------------------------------------------------------
                                   1220 	.area XSEG    (XDATA)
                                   1221 ;--------------------------------------------------------
                                   1222 ; absolute external ram data
                                   1223 ;--------------------------------------------------------
                                   1224 	.area XABS    (ABS,XDATA)
                                   1225 ;--------------------------------------------------------
                                   1226 ; external initialized ram data
                                   1227 ;--------------------------------------------------------
                                   1228 	.area XISEG   (XDATA)
                                   1229 	.area HOME    (CODE)
                                   1230 	.area GSINIT0 (CODE)
                                   1231 	.area GSINIT1 (CODE)
                                   1232 	.area GSINIT2 (CODE)
                                   1233 	.area GSINIT3 (CODE)
                                   1234 	.area GSINIT4 (CODE)
                                   1235 	.area GSINIT5 (CODE)
                                   1236 	.area GSINIT  (CODE)
                                   1237 	.area GSFINAL (CODE)
                                   1238 	.area CSEG    (CODE)
                                   1239 ;--------------------------------------------------------
                                   1240 ; interrupt vector 
                                   1241 ;--------------------------------------------------------
                                   1242 	.area HOME    (CODE)
      000000                       1243 __interrupt_vect:
      000000 02 00 06         [24] 1244 	ljmp	__sdcc_gsinit_startup
                                   1245 ;--------------------------------------------------------
                                   1246 ; global & static initialisations
                                   1247 ;--------------------------------------------------------
                                   1248 	.area HOME    (CODE)
                                   1249 	.area GSINIT  (CODE)
                                   1250 	.area GSFINAL (CODE)
                                   1251 	.area GSINIT  (CODE)
                                   1252 	.globl __sdcc_gsinit_startup
                                   1253 	.globl __sdcc_program_startup
                                   1254 	.globl __start__stack
                                   1255 	.globl __mcs51_genXINIT
                                   1256 	.globl __mcs51_genXRAMCLEAR
                                   1257 	.globl __mcs51_genRAMCLEAR
                                   1258 	.area GSFINAL (CODE)
      00005F 02 00 03         [24] 1259 	ljmp	__sdcc_program_startup
                                   1260 ;--------------------------------------------------------
                                   1261 ; Home
                                   1262 ;--------------------------------------------------------
                                   1263 	.area HOME    (CODE)
                                   1264 	.area HOME    (CODE)
      000003                       1265 __sdcc_program_startup:
      000003 02 00 7B         [24] 1266 	ljmp	_main
                                   1267 ;	return from main will return to caller
                                   1268 ;--------------------------------------------------------
                                   1269 ; code
                                   1270 ;--------------------------------------------------------
                                   1271 	.area CSEG    (CODE)
                                   1272 ;------------------------------------------------------------
                                   1273 ;Allocation info for local variables in function 'putchar'
                                   1274 ;------------------------------------------------------------
                                   1275 ;c                         Allocated to registers r7 
                                   1276 ;------------------------------------------------------------
                           000000  1277 	G$putchar$0$0 ==.
                           000000  1278 	C$putget.h$20$0$0 ==.
                                   1279 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\/putget.h:20: void putchar(char c)
                                   1280 ;	-----------------------------------------
                                   1281 ;	 function putchar
                                   1282 ;	-----------------------------------------
      000062                       1283 _putchar:
                           000007  1284 	ar7 = 0x07
                           000006  1285 	ar6 = 0x06
                           000005  1286 	ar5 = 0x05
                           000004  1287 	ar4 = 0x04
                           000003  1288 	ar3 = 0x03
                           000002  1289 	ar2 = 0x02
                           000001  1290 	ar1 = 0x01
                           000000  1291 	ar0 = 0x00
      000062 AF 82            [24] 1292 	mov	r7,dpl
                           000002  1293 	C$putget.h$22$1$15 ==.
                                   1294 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\/putget.h:22: while(!TI0); 
      000064                       1295 00101$:
                           000002  1296 	C$putget.h$23$1$15 ==.
                                   1297 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\/putget.h:23: TI0=0;
      000064 10 99 02         [24] 1298 	jbc	_TI0,00112$
      000067 80 FB            [24] 1299 	sjmp	00101$
      000069                       1300 00112$:
                           000007  1301 	C$putget.h$24$1$15 ==.
                                   1302 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\/putget.h:24: SBUF0 = c;
      000069 8F 99            [24] 1303 	mov	_SBUF0,r7
                           000009  1304 	C$putget.h$25$1$15 ==.
                           000009  1305 	XG$putchar$0$0 ==.
      00006B 22               [24] 1306 	ret
                                   1307 ;------------------------------------------------------------
                                   1308 ;Allocation info for local variables in function 'getchar'
                                   1309 ;------------------------------------------------------------
                                   1310 ;c                         Allocated to registers 
                                   1311 ;------------------------------------------------------------
                           00000A  1312 	G$getchar$0$0 ==.
                           00000A  1313 	C$putget.h$30$1$15 ==.
                                   1314 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\/putget.h:30: char getchar(void)
                                   1315 ;	-----------------------------------------
                                   1316 ;	 function getchar
                                   1317 ;	-----------------------------------------
      00006C                       1318 _getchar:
                           00000A  1319 	C$putget.h$33$1$17 ==.
                                   1320 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\/putget.h:33: while(!RI0);
      00006C                       1321 00101$:
                           00000A  1322 	C$putget.h$34$1$17 ==.
                                   1323 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\/putget.h:34: RI0 =0;
      00006C 10 98 02         [24] 1324 	jbc	_RI0,00112$
      00006F 80 FB            [24] 1325 	sjmp	00101$
      000071                       1326 00112$:
                           00000F  1327 	C$putget.h$35$1$17 ==.
                                   1328 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\/putget.h:35: c = SBUF0;
      000071 85 99 82         [24] 1329 	mov	dpl,_SBUF0
                           000012  1330 	C$putget.h$37$1$17 ==.
                                   1331 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\/putget.h:37: putchar(c);    // echo to terminal
      000074 12 00 62         [24] 1332 	lcall	_putchar
                           000015  1333 	C$putget.h$38$1$17 ==.
                                   1334 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\/putget.h:38: return SBUF0;
      000077 85 99 82         [24] 1335 	mov	dpl,_SBUF0
                           000018  1336 	C$putget.h$39$1$17 ==.
                           000018  1337 	XG$getchar$0$0 ==.
      00007A 22               [24] 1338 	ret
                                   1339 ;------------------------------------------------------------
                                   1340 ;Allocation info for local variables in function 'main'
                                   1341 ;------------------------------------------------------------
                                   1342 ;choice                    Allocated to registers r7 
                                   1343 ;------------------------------------------------------------
                           000019  1344 	G$main$0$0 ==.
                           000019  1345 	C$Hello.c$36$1$17 ==.
                                   1346 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:36: void main(void)
                                   1347 ;	-----------------------------------------
                                   1348 ;	 function main
                                   1349 ;	-----------------------------------------
      00007B                       1350 _main:
                           000019  1351 	C$Hello.c$40$1$23 ==.
                                   1352 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:40: WDTCN = 0xDE;                       // Disable the watchdog timer
      00007B 75 FF DE         [24] 1353 	mov	_WDTCN,#0xde
                           00001C  1354 	C$Hello.c$41$1$23 ==.
                                   1355 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:41: WDTCN = 0xAD;
      00007E 75 FF AD         [24] 1356 	mov	_WDTCN,#0xad
                           00001F  1357 	C$Hello.c$43$1$23 ==.
                                   1358 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:43: PORT_INIT();                        // Initialize the Crossbar and GPIO
      000081 12 02 A9         [24] 1359 	lcall	_PORT_INIT
                           000022  1360 	C$Hello.c$44$1$23 ==.
                                   1361 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:44: SYSCLK_INIT();                      // Initialize the oscillator
      000084 12 02 53         [24] 1362 	lcall	_SYSCLK_INIT
                           000025  1363 	C$Hello.c$45$1$23 ==.
                                   1364 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:45: UART0_INIT();                       // Initialize UART0
      000087 12 02 C0         [24] 1365 	lcall	_UART0_INIT
                           000028  1366 	C$Hello.c$47$1$23 ==.
                                   1367 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:47: SFRPAGE = UART0_PAGE;               // Direct output to UART0
      00008A 75 84 00         [24] 1368 	mov	_SFRPAGE,#0x00
                           00002B  1369 	C$Hello.c$50$1$23 ==.
                                   1370 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:50: printf("\033[33;44m");              // Yellow text; blue background
      00008D 74 23            [12] 1371 	mov	a,#___str_0
      00008F C0 E0            [24] 1372 	push	acc
      000091 74 09            [12] 1373 	mov	a,#(___str_0 >> 8)
      000093 C0 E0            [24] 1374 	push	acc
      000095 74 80            [12] 1375 	mov	a,#0x80
      000097 C0 E0            [24] 1376 	push	acc
      000099 12 03 08         [24] 1377 	lcall	_printf
      00009C 15 81            [12] 1378 	dec	sp
      00009E 15 81            [12] 1379 	dec	sp
      0000A0 15 81            [12] 1380 	dec	sp
                           000040  1381 	C$Hello.c$51$1$23 ==.
                                   1382 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:51: printf("\033[2J");                  // Erase screen & move cursor to home position
      0000A2 74 2C            [12] 1383 	mov	a,#___str_1
      0000A4 C0 E0            [24] 1384 	push	acc
      0000A6 74 09            [12] 1385 	mov	a,#(___str_1 >> 8)
      0000A8 C0 E0            [24] 1386 	push	acc
      0000AA 74 80            [12] 1387 	mov	a,#0x80
      0000AC C0 E0            [24] 1388 	push	acc
      0000AE 12 03 08         [24] 1389 	lcall	_printf
      0000B1 15 81            [12] 1390 	dec	sp
      0000B3 15 81            [12] 1391 	dec	sp
      0000B5 15 81            [12] 1392 	dec	sp
                           000055  1393 	C$Hello.c$52$1$23 ==.
                                   1394 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:52: printf("\033[33;44m");              // Yellow text; blue background (twice for escape bug)
      0000B7 74 23            [12] 1395 	mov	a,#___str_0
      0000B9 C0 E0            [24] 1396 	push	acc
      0000BB 74 09            [12] 1397 	mov	a,#(___str_0 >> 8)
      0000BD C0 E0            [24] 1398 	push	acc
      0000BF 74 80            [12] 1399 	mov	a,#0x80
      0000C1 C0 E0            [24] 1400 	push	acc
      0000C3 12 03 08         [24] 1401 	lcall	_printf
      0000C6 15 81            [12] 1402 	dec	sp
      0000C8 15 81            [12] 1403 	dec	sp
      0000CA 15 81            [12] 1404 	dec	sp
                           00006A  1405 	C$Hello.c$55$1$23 ==.
                                   1406 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:55: printf("\033[12;0H");               // Position cursor to print unprintables
      0000CC 74 31            [12] 1407 	mov	a,#___str_2
      0000CE C0 E0            [24] 1408 	push	acc
      0000D0 74 09            [12] 1409 	mov	a,#(___str_2 >> 8)
      0000D2 C0 E0            [24] 1410 	push	acc
      0000D4 74 80            [12] 1411 	mov	a,#0x80
      0000D6 C0 E0            [24] 1412 	push	acc
      0000D8 12 03 08         [24] 1413 	lcall	_printf
      0000DB 15 81            [12] 1414 	dec	sp
      0000DD 15 81            [12] 1415 	dec	sp
      0000DF 15 81            [12] 1416 	dec	sp
                           00007F  1417 	C$Hello.c$56$1$23 ==.
                                   1418 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:56: printf("\033[s");                   // Store current location
      0000E1 74 39            [12] 1419 	mov	a,#___str_3
      0000E3 C0 E0            [24] 1420 	push	acc
      0000E5 74 09            [12] 1421 	mov	a,#(___str_3 >> 8)
      0000E7 C0 E0            [24] 1422 	push	acc
      0000E9 74 80            [12] 1423 	mov	a,#0x80
      0000EB C0 E0            [24] 1424 	push	acc
      0000ED 12 03 08         [24] 1425 	lcall	_printf
      0000F0 15 81            [12] 1426 	dec	sp
      0000F2 15 81            [12] 1427 	dec	sp
      0000F4 15 81            [12] 1428 	dec	sp
                           000094  1429 	C$Hello.c$59$1$23 ==.
                                   1430 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:59: printf("\033[2;25H");               // Position cursor to print instructions
      0000F6 74 3D            [12] 1431 	mov	a,#___str_4
      0000F8 C0 E0            [24] 1432 	push	acc
      0000FA 74 09            [12] 1433 	mov	a,#(___str_4 >> 8)
      0000FC C0 E0            [24] 1434 	push	acc
      0000FE 74 80            [12] 1435 	mov	a,#0x80
      000100 C0 E0            [24] 1436 	push	acc
      000102 12 03 08         [24] 1437 	lcall	_printf
      000105 15 81            [12] 1438 	dec	sp
      000107 15 81            [12] 1439 	dec	sp
      000109 15 81            [12] 1440 	dec	sp
                           0000A9  1441 	C$Hello.c$60$1$23 ==.
                                   1442 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:60: printf("Type <ESC> to end the program.\n\n\r");
      00010B 74 45            [12] 1443 	mov	a,#___str_5
      00010D C0 E0            [24] 1444 	push	acc
      00010F 74 09            [12] 1445 	mov	a,#(___str_5 >> 8)
      000111 C0 E0            [24] 1446 	push	acc
      000113 74 80            [12] 1447 	mov	a,#0x80
      000115 C0 E0            [24] 1448 	push	acc
      000117 12 03 08         [24] 1449 	lcall	_printf
      00011A 15 81            [12] 1450 	dec	sp
      00011C 15 81            [12] 1451 	dec	sp
      00011E 15 81            [12] 1452 	dec	sp
                           0000BE  1453 	C$Hello.c$63$1$23 ==.
                                   1454 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:63: printf("\033[6;0H");                // Position cursor to print Keyboard character info
      000120 74 67            [12] 1455 	mov	a,#___str_6
      000122 C0 E0            [24] 1456 	push	acc
      000124 74 09            [12] 1457 	mov	a,#(___str_6 >> 8)
      000126 C0 E0            [24] 1458 	push	acc
      000128 74 80            [12] 1459 	mov	a,#0x80
      00012A C0 E0            [24] 1460 	push	acc
      00012C 12 03 08         [24] 1461 	lcall	_printf
      00012F 15 81            [12] 1462 	dec	sp
      000131 15 81            [12] 1463 	dec	sp
      000133 15 81            [12] 1464 	dec	sp
                           0000D3  1465 	C$Hello.c$64$1$23 ==.
                                   1466 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:64: printf("The keyboard character is  .");
      000135 74 6E            [12] 1467 	mov	a,#___str_7
      000137 C0 E0            [24] 1468 	push	acc
      000139 74 09            [12] 1469 	mov	a,#(___str_7 >> 8)
      00013B C0 E0            [24] 1470 	push	acc
      00013D 74 80            [12] 1471 	mov	a,#0x80
      00013F C0 E0            [24] 1472 	push	acc
      000141 12 03 08         [24] 1473 	lcall	_printf
      000144 15 81            [12] 1474 	dec	sp
      000146 15 81            [12] 1475 	dec	sp
      000148 15 81            [12] 1476 	dec	sp
                           0000E8  1477 	C$Hello.c$66$1$23 ==.
                                   1478 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:66: printf("\033[12;25r");              // Set scrollable region
      00014A 74 8B            [12] 1479 	mov	a,#___str_8
      00014C C0 E0            [24] 1480 	push	acc
      00014E 74 09            [12] 1481 	mov	a,#(___str_8 >> 8)
      000150 C0 E0            [24] 1482 	push	acc
      000152 74 80            [12] 1483 	mov	a,#0x80
      000154 C0 E0            [24] 1484 	push	acc
      000156 12 03 08         [24] 1485 	lcall	_printf
      000159 15 81            [12] 1486 	dec	sp
      00015B 15 81            [12] 1487 	dec	sp
      00015D 15 81            [12] 1488 	dec	sp
                           0000FD  1489 	C$Hello.c$68$2$24 ==.
                                   1490 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:68: while(1)
      00015F                       1491 00107$:
                           0000FD  1492 	C$Hello.c$71$2$24 ==.
                                   1493 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:71: printf("\033[6;27H");           // Position cursor where keyboard character is to be displayed
      00015F 74 94            [12] 1494 	mov	a,#___str_9
      000161 C0 E0            [24] 1495 	push	acc
      000163 74 09            [12] 1496 	mov	a,#(___str_9 >> 8)
      000165 C0 E0            [24] 1497 	push	acc
      000167 74 80            [12] 1498 	mov	a,#0x80
      000169 C0 E0            [24] 1499 	push	acc
      00016B 12 03 08         [24] 1500 	lcall	_printf
      00016E 15 81            [12] 1501 	dec	sp
      000170 15 81            [12] 1502 	dec	sp
      000172 15 81            [12] 1503 	dec	sp
                           000112  1504 	C$Hello.c$72$2$24 ==.
                                   1505 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:72: printf("\033[37m");             // White text
      000174 74 9C            [12] 1506 	mov	a,#___str_10
      000176 C0 E0            [24] 1507 	push	acc
      000178 74 09            [12] 1508 	mov	a,#(___str_10 >> 8)
      00017A C0 E0            [24] 1509 	push	acc
      00017C 74 80            [12] 1510 	mov	a,#0x80
      00017E C0 E0            [24] 1511 	push	acc
      000180 12 03 08         [24] 1512 	lcall	_printf
      000183 15 81            [12] 1513 	dec	sp
      000185 15 81            [12] 1514 	dec	sp
      000187 15 81            [12] 1515 	dec	sp
                           000127  1516 	C$Hello.c$74$2$24 ==.
                                   1517 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:74: choice = getchar();
      000189 12 00 6C         [24] 1518 	lcall	_getchar
      00018C AF 82            [24] 1519 	mov	r7,dpl
                           00012C  1520 	C$Hello.c$76$2$24 ==.
                                   1521 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:76: P1 |= 0x40;                     // Turn green LED on (alert user program is on)
      00018E 43 90 40         [24] 1522 	orl	_P1,#0x40
                           00012F  1523 	C$Hello.c$79$2$24 ==.
                                   1524 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:79: if (choice == '\033'){
      000191 BF 1B 03         [24] 1525 	cjne	r7,#0x1b,00102$
                           000132  1526 	C$Hello.c$80$3$25 ==.
                                   1527 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:80: return;
      000194 02 02 52         [24] 1528 	ljmp	00109$
      000197                       1529 00102$:
                           000135  1530 	C$Hello.c$84$2$24 ==.
                                   1531 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:84: if (!(choice >= '\040' && choice <= '\176')){ 
      000197 BF 20 00         [24] 1532 	cjne	r7,#0x20,00122$
      00019A                       1533 00122$:
      00019A 40 05            [24] 1534 	jc	00103$
      00019C EF               [12] 1535 	mov	a,r7
      00019D 24 81            [12] 1536 	add	a,#0xff - 0x7e
      00019F 50 BE            [24] 1537 	jnc	00107$
      0001A1                       1538 00103$:
                           00013F  1539 	C$Hello.c$85$3$26 ==.
                                   1540 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:85: printf("\033[5;33;44m");        // Blinking text; yellow text; blue background
      0001A1 C0 07            [24] 1541 	push	ar7
      0001A3 74 A2            [12] 1542 	mov	a,#___str_11
      0001A5 C0 E0            [24] 1543 	push	acc
      0001A7 74 09            [12] 1544 	mov	a,#(___str_11 >> 8)
      0001A9 C0 E0            [24] 1545 	push	acc
      0001AB 74 80            [12] 1546 	mov	a,#0x80
      0001AD C0 E0            [24] 1547 	push	acc
      0001AF 12 03 08         [24] 1548 	lcall	_printf
      0001B2 15 81            [12] 1549 	dec	sp
      0001B4 15 81            [12] 1550 	dec	sp
      0001B6 15 81            [12] 1551 	dec	sp
                           000156  1552 	C$Hello.c$86$3$26 ==.
                                   1553 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:86: printf("\033[u");               // Position cursor to print Keyboard character info (using saved location)
      0001B8 74 AD            [12] 1554 	mov	a,#___str_12
      0001BA C0 E0            [24] 1555 	push	acc
      0001BC 74 09            [12] 1556 	mov	a,#(___str_12 >> 8)
      0001BE C0 E0            [24] 1557 	push	acc
      0001C0 74 80            [12] 1558 	mov	a,#0x80
      0001C2 C0 E0            [24] 1559 	push	acc
      0001C4 12 03 08         [24] 1560 	lcall	_printf
      0001C7 15 81            [12] 1561 	dec	sp
      0001C9 15 81            [12] 1562 	dec	sp
      0001CB 15 81            [12] 1563 	dec	sp
                           00016B  1564 	C$Hello.c$93$3$26 ==.
                                   1565 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:93: printf("The keyboard character $%02X is \033[4m'not printable'\033[0;5;33;44m.\n\r", choice);
      0001CD 7E 00            [12] 1566 	mov	r6,#0x00
      0001CF C0 06            [24] 1567 	push	ar6
      0001D1 74 B1            [12] 1568 	mov	a,#___str_13
      0001D3 C0 E0            [24] 1569 	push	acc
      0001D5 74 09            [12] 1570 	mov	a,#(___str_13 >> 8)
      0001D7 C0 E0            [24] 1571 	push	acc
      0001D9 74 80            [12] 1572 	mov	a,#0x80
      0001DB C0 E0            [24] 1573 	push	acc
      0001DD 12 03 08         [24] 1574 	lcall	_printf
      0001E0 E5 81            [12] 1575 	mov	a,sp
      0001E2 24 FB            [12] 1576 	add	a,#0xfb
      0001E4 F5 81            [12] 1577 	mov	sp,a
                           000184  1578 	C$Hello.c$95$3$26 ==.
                                   1579 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:95: printf("\007");                 // Sound bell
      0001E6 74 F4            [12] 1580 	mov	a,#___str_14
      0001E8 C0 E0            [24] 1581 	push	acc
      0001EA 74 09            [12] 1582 	mov	a,#(___str_14 >> 8)
      0001EC C0 E0            [24] 1583 	push	acc
      0001EE 74 80            [12] 1584 	mov	a,#0x80
      0001F0 C0 E0            [24] 1585 	push	acc
      0001F2 12 03 08         [24] 1586 	lcall	_printf
      0001F5 15 81            [12] 1587 	dec	sp
      0001F7 15 81            [12] 1588 	dec	sp
      0001F9 15 81            [12] 1589 	dec	sp
                           000199  1590 	C$Hello.c$98$3$26 ==.
                                   1591 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:98: printf("\033[0m");              // Clear formatting
      0001FB 74 F6            [12] 1592 	mov	a,#___str_15
      0001FD C0 E0            [24] 1593 	push	acc
      0001FF 74 09            [12] 1594 	mov	a,#(___str_15 >> 8)
      000201 C0 E0            [24] 1595 	push	acc
      000203 74 80            [12] 1596 	mov	a,#0x80
      000205 C0 E0            [24] 1597 	push	acc
      000207 12 03 08         [24] 1598 	lcall	_printf
      00020A 15 81            [12] 1599 	dec	sp
      00020C 15 81            [12] 1600 	dec	sp
      00020E 15 81            [12] 1601 	dec	sp
                           0001AE  1602 	C$Hello.c$99$3$26 ==.
                                   1603 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:99: printf("\033[33;44m");          // Yellow text; blue background
      000210 74 23            [12] 1604 	mov	a,#___str_0
      000212 C0 E0            [24] 1605 	push	acc
      000214 74 09            [12] 1606 	mov	a,#(___str_0 >> 8)
      000216 C0 E0            [24] 1607 	push	acc
      000218 74 80            [12] 1608 	mov	a,#0x80
      00021A C0 E0            [24] 1609 	push	acc
      00021C 12 03 08         [24] 1610 	lcall	_printf
      00021F 15 81            [12] 1611 	dec	sp
      000221 15 81            [12] 1612 	dec	sp
      000223 15 81            [12] 1613 	dec	sp
                           0001C3  1614 	C$Hello.c$102$3$26 ==.
                                   1615 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:102: printf("\033[s");               // Overwrite saved cursor info
      000225 74 39            [12] 1616 	mov	a,#___str_3
      000227 C0 E0            [24] 1617 	push	acc
      000229 74 09            [12] 1618 	mov	a,#(___str_3 >> 8)
      00022B C0 E0            [24] 1619 	push	acc
      00022D 74 80            [12] 1620 	mov	a,#0x80
      00022F C0 E0            [24] 1621 	push	acc
      000231 12 03 08         [24] 1622 	lcall	_printf
      000234 15 81            [12] 1623 	dec	sp
      000236 15 81            [12] 1624 	dec	sp
      000238 15 81            [12] 1625 	dec	sp
                           0001D8  1626 	C$Hello.c$106$3$26 ==.
                                   1627 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:106: printf("\033[6;27H ");          // Move cursor and print space in the printable character location
      00023A 74 FB            [12] 1628 	mov	a,#___str_16
      00023C C0 E0            [24] 1629 	push	acc
      00023E 74 09            [12] 1630 	mov	a,#(___str_16 >> 8)
      000240 C0 E0            [24] 1631 	push	acc
      000242 74 80            [12] 1632 	mov	a,#0x80
      000244 C0 E0            [24] 1633 	push	acc
      000246 12 03 08         [24] 1634 	lcall	_printf
      000249 15 81            [12] 1635 	dec	sp
      00024B 15 81            [12] 1636 	dec	sp
      00024D 15 81            [12] 1637 	dec	sp
      00024F 02 01 5F         [24] 1638 	ljmp	00107$
      000252                       1639 00109$:
                           0001F0  1640 	C$Hello.c$114$1$23 ==.
                           0001F0  1641 	XG$main$0$0 ==.
      000252 22               [24] 1642 	ret
                                   1643 ;------------------------------------------------------------
                                   1644 ;Allocation info for local variables in function 'SYSCLK_INIT'
                                   1645 ;------------------------------------------------------------
                                   1646 ;i                         Allocated to registers r5 r6 
                                   1647 ;SFRPAGE_SAVE              Allocated to registers r7 
                                   1648 ;------------------------------------------------------------
                           0001F1  1649 	G$SYSCLK_INIT$0$0 ==.
                           0001F1  1650 	C$Hello.c$122$1$23 ==.
                                   1651 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:122: void SYSCLK_INIT(void)
                                   1652 ;	-----------------------------------------
                                   1653 ;	 function SYSCLK_INIT
                                   1654 ;	-----------------------------------------
      000253                       1655 _SYSCLK_INIT:
                           0001F1  1656 	C$Hello.c$127$1$28 ==.
                                   1657 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:127: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
      000253 AF 84            [24] 1658 	mov	r7,_SFRPAGE
                           0001F3  1659 	C$Hello.c$129$1$28 ==.
                                   1660 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:129: SFRPAGE = CONFIG_PAGE;
      000255 75 84 0F         [24] 1661 	mov	_SFRPAGE,#0x0f
                           0001F6  1662 	C$Hello.c$130$1$28 ==.
                                   1663 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:130: OSCXCN  = 0x67;                     // Start ext osc with 22.1184MHz crystal
      000258 75 8C 67         [24] 1664 	mov	_OSCXCN,#0x67
                           0001F9  1665 	C$Hello.c$131$1$28 ==.
                                   1666 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:131: for(i=0; i < 256; i++);             // Wait for the oscillator to start up
      00025B 7D 00            [12] 1667 	mov	r5,#0x00
      00025D 7E 01            [12] 1668 	mov	r6,#0x01
      00025F                       1669 00111$:
      00025F 1D               [12] 1670 	dec	r5
      000260 BD FF 01         [24] 1671 	cjne	r5,#0xff,00141$
      000263 1E               [12] 1672 	dec	r6
      000264                       1673 00141$:
      000264 ED               [12] 1674 	mov	a,r5
      000265 4E               [12] 1675 	orl	a,r6
      000266 70 F7            [24] 1676 	jnz	00111$
                           000206  1677 	C$Hello.c$132$1$28 ==.
                                   1678 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:132: while(!(OSCXCN & 0x80));
      000268                       1679 00102$:
      000268 E5 8C            [12] 1680 	mov	a,_OSCXCN
      00026A 30 E7 FB         [24] 1681 	jnb	acc.7,00102$
                           00020B  1682 	C$Hello.c$133$1$28 ==.
                                   1683 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:133: CLKSEL  = 0x01;
      00026D 75 97 01         [24] 1684 	mov	_CLKSEL,#0x01
                           00020E  1685 	C$Hello.c$134$1$28 ==.
                                   1686 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:134: OSCICN  = 0x00;
      000270 75 8A 00         [24] 1687 	mov	_OSCICN,#0x00
                           000211  1688 	C$Hello.c$136$1$28 ==.
                                   1689 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:136: SFRPAGE = CONFIG_PAGE;
      000273 75 84 0F         [24] 1690 	mov	_SFRPAGE,#0x0f
                           000214  1691 	C$Hello.c$137$1$28 ==.
                                   1692 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:137: PLL0CN  = 0x04;
      000276 75 89 04         [24] 1693 	mov	_PLL0CN,#0x04
                           000217  1694 	C$Hello.c$138$1$28 ==.
                                   1695 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:138: SFRPAGE = LEGACY_PAGE;
      000279 75 84 00         [24] 1696 	mov	_SFRPAGE,#0x00
                           00021A  1697 	C$Hello.c$139$1$28 ==.
                                   1698 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:139: FLSCL   = 0x10;
      00027C 75 B7 10         [24] 1699 	mov	_FLSCL,#0x10
                           00021D  1700 	C$Hello.c$140$1$28 ==.
                                   1701 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:140: SFRPAGE = CONFIG_PAGE;
      00027F 75 84 0F         [24] 1702 	mov	_SFRPAGE,#0x0f
                           000220  1703 	C$Hello.c$141$1$28 ==.
                                   1704 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:141: PLL0CN |= 0x01;
      000282 43 89 01         [24] 1705 	orl	_PLL0CN,#0x01
                           000223  1706 	C$Hello.c$142$1$28 ==.
                                   1707 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:142: PLL0DIV = 0x04;
      000285 75 8D 04         [24] 1708 	mov	_PLL0DIV,#0x04
                           000226  1709 	C$Hello.c$143$1$28 ==.
                                   1710 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:143: PLL0FLT = 0x01;
      000288 75 8F 01         [24] 1711 	mov	_PLL0FLT,#0x01
                           000229  1712 	C$Hello.c$144$1$28 ==.
                                   1713 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:144: PLL0MUL = 0x09;
      00028B 75 8E 09         [24] 1714 	mov	_PLL0MUL,#0x09
                           00022C  1715 	C$Hello.c$145$1$28 ==.
                                   1716 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:145: for(i=0; i < 256; i++);
      00028E 7D 00            [12] 1717 	mov	r5,#0x00
      000290 7E 01            [12] 1718 	mov	r6,#0x01
      000292                       1719 00114$:
      000292 1D               [12] 1720 	dec	r5
      000293 BD FF 01         [24] 1721 	cjne	r5,#0xff,00144$
      000296 1E               [12] 1722 	dec	r6
      000297                       1723 00144$:
      000297 ED               [12] 1724 	mov	a,r5
      000298 4E               [12] 1725 	orl	a,r6
      000299 70 F7            [24] 1726 	jnz	00114$
                           000239  1727 	C$Hello.c$146$1$28 ==.
                                   1728 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:146: PLL0CN |= 0x02;
      00029B 43 89 02         [24] 1729 	orl	_PLL0CN,#0x02
                           00023C  1730 	C$Hello.c$147$1$28 ==.
                                   1731 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:147: while(!(PLL0CN & 0x10));
      00029E                       1732 00106$:
      00029E E5 89            [12] 1733 	mov	a,_PLL0CN
      0002A0 30 E4 FB         [24] 1734 	jnb	acc.4,00106$
                           000241  1735 	C$Hello.c$148$1$28 ==.
                                   1736 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:148: CLKSEL  = 0x02;
      0002A3 75 97 02         [24] 1737 	mov	_CLKSEL,#0x02
                           000244  1738 	C$Hello.c$150$1$28 ==.
                                   1739 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:150: SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
      0002A6 8F 84            [24] 1740 	mov	_SFRPAGE,r7
                           000246  1741 	C$Hello.c$151$1$28 ==.
                           000246  1742 	XG$SYSCLK_INIT$0$0 ==.
      0002A8 22               [24] 1743 	ret
                                   1744 ;------------------------------------------------------------
                                   1745 ;Allocation info for local variables in function 'PORT_INIT'
                                   1746 ;------------------------------------------------------------
                                   1747 ;SFRPAGE_SAVE              Allocated to registers r7 
                                   1748 ;------------------------------------------------------------
                           000247  1749 	G$PORT_INIT$0$0 ==.
                           000247  1750 	C$Hello.c$159$1$28 ==.
                                   1751 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:159: void PORT_INIT(void)
                                   1752 ;	-----------------------------------------
                                   1753 ;	 function PORT_INIT
                                   1754 ;	-----------------------------------------
      0002A9                       1755 _PORT_INIT:
                           000247  1756 	C$Hello.c$163$1$30 ==.
                                   1757 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:163: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
      0002A9 AF 84            [24] 1758 	mov	r7,_SFRPAGE
                           000249  1759 	C$Hello.c$165$1$30 ==.
                                   1760 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:165: SFRPAGE  = CONFIG_PAGE;
      0002AB 75 84 0F         [24] 1761 	mov	_SFRPAGE,#0x0f
                           00024C  1762 	C$Hello.c$166$1$30 ==.
                                   1763 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:166: XBR0     = 0x04;                    // Enable UART0
      0002AE 75 E1 04         [24] 1764 	mov	_XBR0,#0x04
                           00024F  1765 	C$Hello.c$167$1$30 ==.
                                   1766 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:167: XBR1     = 0x00;
      0002B1 75 E2 00         [24] 1767 	mov	_XBR1,#0x00
                           000252  1768 	C$Hello.c$168$1$30 ==.
                                   1769 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:168: XBR2     = 0x40;                    // Enable Crossbar and weak pull-up
      0002B4 75 E3 40         [24] 1770 	mov	_XBR2,#0x40
                           000255  1771 	C$Hello.c$169$1$30 ==.
                                   1772 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:169: P0MDOUT |= 0x01;                    // Set TX0 on P0.0 pin to push-pull
      0002B7 43 A4 01         [24] 1773 	orl	_P0MDOUT,#0x01
                           000258  1774 	C$Hello.c$170$1$30 ==.
                                   1775 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:170: P1MDOUT |= 0x40;                    // Set green LED output P1.6 to push-pull
      0002BA 43 A5 40         [24] 1776 	orl	_P1MDOUT,#0x40
                           00025B  1777 	C$Hello.c$172$1$30 ==.
                                   1778 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:172: SFRPAGE  = SFRPAGE_SAVE;            // Restore SFR page
      0002BD 8F 84            [24] 1779 	mov	_SFRPAGE,r7
                           00025D  1780 	C$Hello.c$173$1$30 ==.
                           00025D  1781 	XG$PORT_INIT$0$0 ==.
      0002BF 22               [24] 1782 	ret
                                   1783 ;------------------------------------------------------------
                                   1784 ;Allocation info for local variables in function 'UART0_INIT'
                                   1785 ;------------------------------------------------------------
                                   1786 ;SFRPAGE_SAVE              Allocated to registers r7 
                                   1787 ;------------------------------------------------------------
                           00025E  1788 	G$UART0_INIT$0$0 ==.
                           00025E  1789 	C$Hello.c$181$1$30 ==.
                                   1790 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:181: void UART0_INIT(void)
                                   1791 ;	-----------------------------------------
                                   1792 ;	 function UART0_INIT
                                   1793 ;	-----------------------------------------
      0002C0                       1794 _UART0_INIT:
                           00025E  1795 	C$Hello.c$185$1$32 ==.
                                   1796 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:185: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
      0002C0 AF 84            [24] 1797 	mov	r7,_SFRPAGE
                           000260  1798 	C$Hello.c$187$1$32 ==.
                                   1799 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:187: SFRPAGE = TIMER01_PAGE;
      0002C2 75 84 00         [24] 1800 	mov	_SFRPAGE,#0x00
                           000263  1801 	C$Hello.c$188$1$32 ==.
                                   1802 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:188: TMOD   &= ~0xF0;
      0002C5 53 89 0F         [24] 1803 	anl	_TMOD,#0x0f
                           000266  1804 	C$Hello.c$189$1$32 ==.
                                   1805 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:189: TMOD   |=  0x20;                    // Timer1, Mode 2, 8-bit reload
      0002C8 43 89 20         [24] 1806 	orl	_TMOD,#0x20
                           000269  1807 	C$Hello.c$190$1$32 ==.
                                   1808 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:190: TH1     = -(SYSCLK/BAUDRATE/16);    // Set Timer1 reload baudrate value T1 Hi Byte
      0002CB 75 8D E5         [24] 1809 	mov	_TH1,#0xe5
                           00026C  1810 	C$Hello.c$191$1$32 ==.
                                   1811 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:191: CKCON  |= 0x10;                     // Timer1 uses SYSCLK as time base
      0002CE 43 8E 10         [24] 1812 	orl	_CKCON,#0x10
                           00026F  1813 	C$Hello.c$192$1$32 ==.
                                   1814 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:192: TL1     = TH1;
      0002D1 85 8D 8B         [24] 1815 	mov	_TL1,_TH1
                           000272  1816 	C$Hello.c$193$1$32 ==.
                                   1817 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:193: TR1     = 1;                        // Start Timer1
      0002D4 D2 8E            [12] 1818 	setb	_TR1
                           000274  1819 	C$Hello.c$195$1$32 ==.
                                   1820 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:195: SFRPAGE = UART0_PAGE;
      0002D6 75 84 00         [24] 1821 	mov	_SFRPAGE,#0x00
                           000277  1822 	C$Hello.c$196$1$32 ==.
                                   1823 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:196: SCON0   = 0x50;                     // Mode 1, 8-bit UART, enable RX
      0002D9 75 98 50         [24] 1824 	mov	_SCON0,#0x50
                           00027A  1825 	C$Hello.c$197$1$32 ==.
                                   1826 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:197: SSTA0   = 0x10;                     // SMOD0 = 1
      0002DC 75 91 10         [24] 1827 	mov	_SSTA0,#0x10
                           00027D  1828 	C$Hello.c$198$1$32 ==.
                                   1829 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:198: TI0     = 1;                        // Indicate TX0 ready
      0002DF D2 99            [12] 1830 	setb	_TI0
                           00027F  1831 	C$Hello.c$200$1$32 ==.
                                   1832 ;	C:\Users\Alex\Documents\GitHub\mps\lab1\Hello.c:200: SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
      0002E1 8F 84            [24] 1833 	mov	_SFRPAGE,r7
                           000281  1834 	C$Hello.c$201$1$32 ==.
                           000281  1835 	XG$UART0_INIT$0$0 ==.
      0002E3 22               [24] 1836 	ret
                                   1837 	.area CSEG    (CODE)
                                   1838 	.area CONST   (CODE)
                           000000  1839 FHello$__str_0$0$0 == .
      000923                       1840 ___str_0:
      000923 1B                    1841 	.db 0x1b
      000924 5B 33 33 3B 34 34 6D  1842 	.ascii "[33;44m"
      00092B 00                    1843 	.db 0x00
                           000009  1844 FHello$__str_1$0$0 == .
      00092C                       1845 ___str_1:
      00092C 1B                    1846 	.db 0x1b
      00092D 5B 32 4A              1847 	.ascii "[2J"
      000930 00                    1848 	.db 0x00
                           00000E  1849 FHello$__str_2$0$0 == .
      000931                       1850 ___str_2:
      000931 1B                    1851 	.db 0x1b
      000932 5B 31 32 3B 30 48     1852 	.ascii "[12;0H"
      000938 00                    1853 	.db 0x00
                           000016  1854 FHello$__str_3$0$0 == .
      000939                       1855 ___str_3:
      000939 1B                    1856 	.db 0x1b
      00093A 5B 73                 1857 	.ascii "[s"
      00093C 00                    1858 	.db 0x00
                           00001A  1859 FHello$__str_4$0$0 == .
      00093D                       1860 ___str_4:
      00093D 1B                    1861 	.db 0x1b
      00093E 5B 32 3B 32 35 48     1862 	.ascii "[2;25H"
      000944 00                    1863 	.db 0x00
                           000022  1864 FHello$__str_5$0$0 == .
      000945                       1865 ___str_5:
      000945 54 79 70 65 20 3C 45  1866 	.ascii "Type <ESC> to end the program."
             53 43 3E 20 74 6F 20
             65 6E 64 20 74 68 65
             20 70 72 6F 67 72 61
             6D 2E
      000963 0A                    1867 	.db 0x0a
      000964 0A                    1868 	.db 0x0a
      000965 0D                    1869 	.db 0x0d
      000966 00                    1870 	.db 0x00
                           000044  1871 FHello$__str_6$0$0 == .
      000967                       1872 ___str_6:
      000967 1B                    1873 	.db 0x1b
      000968 5B 36 3B 30 48        1874 	.ascii "[6;0H"
      00096D 00                    1875 	.db 0x00
                           00004B  1876 FHello$__str_7$0$0 == .
      00096E                       1877 ___str_7:
      00096E 54 68 65 20 6B 65 79  1878 	.ascii "The keyboard character is  ."
             62 6F 61 72 64 20 63
             68 61 72 61 63 74 65
             72 20 69 73 20 20 2E
      00098A 00                    1879 	.db 0x00
                           000068  1880 FHello$__str_8$0$0 == .
      00098B                       1881 ___str_8:
      00098B 1B                    1882 	.db 0x1b
      00098C 5B 31 32 3B 32 35 72  1883 	.ascii "[12;25r"
      000993 00                    1884 	.db 0x00
                           000071  1885 FHello$__str_9$0$0 == .
      000994                       1886 ___str_9:
      000994 1B                    1887 	.db 0x1b
      000995 5B 36 3B 32 37 48     1888 	.ascii "[6;27H"
      00099B 00                    1889 	.db 0x00
                           000079  1890 FHello$__str_10$0$0 == .
      00099C                       1891 ___str_10:
      00099C 1B                    1892 	.db 0x1b
      00099D 5B 33 37 6D           1893 	.ascii "[37m"
      0009A1 00                    1894 	.db 0x00
                           00007F  1895 FHello$__str_11$0$0 == .
      0009A2                       1896 ___str_11:
      0009A2 1B                    1897 	.db 0x1b
      0009A3 5B 35 3B 33 33 3B 34  1898 	.ascii "[5;33;44m"
             34 6D
      0009AC 00                    1899 	.db 0x00
                           00008A  1900 FHello$__str_12$0$0 == .
      0009AD                       1901 ___str_12:
      0009AD 1B                    1902 	.db 0x1b
      0009AE 5B 75                 1903 	.ascii "[u"
      0009B0 00                    1904 	.db 0x00
                           00008E  1905 FHello$__str_13$0$0 == .
      0009B1                       1906 ___str_13:
      0009B1 54 68 65 20 6B 65 79  1907 	.ascii "The keyboard character $%02X is "
             62 6F 61 72 64 20 63
             68 61 72 61 63 74 65
             72 20 24 25 30 32 58
             20 69 73 20
      0009D1 1B                    1908 	.db 0x1b
      0009D2 5B 34 6D 27 6E 6F 74  1909 	.ascii "[4m'not printable'"
             20 70 72 69 6E 74 61
             62 6C 65 27
      0009E4 1B                    1910 	.db 0x1b
      0009E5 5B 30 3B 35 3B 33 33  1911 	.ascii "[0;5;33;"
             3B
      0009ED 34 34 6D 2E           1912 	.ascii "44m."
      0009F1 0A                    1913 	.db 0x0a
      0009F2 0D                    1914 	.db 0x0d
      0009F3 00                    1915 	.db 0x00
                           0000D1  1916 FHello$__str_14$0$0 == .
      0009F4                       1917 ___str_14:
      0009F4 07                    1918 	.db 0x07
      0009F5 00                    1919 	.db 0x00
                           0000D3  1920 FHello$__str_15$0$0 == .
      0009F6                       1921 ___str_15:
      0009F6 1B                    1922 	.db 0x1b
      0009F7 5B 30 6D              1923 	.ascii "[0m"
      0009FA 00                    1924 	.db 0x00
                           0000D8  1925 FHello$__str_16$0$0 == .
      0009FB                       1926 ___str_16:
      0009FB 1B                    1927 	.db 0x1b
      0009FC 5B 36 3B 32 37 48 20  1928 	.ascii "[6;27H "
      000A03 00                    1929 	.db 0x00
                                   1930 	.area XINIT   (CODE)
                                   1931 	.area CABS    (ABS,CODE)
