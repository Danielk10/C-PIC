        LIST

;==========================================================================
; Build date : Jan 06 2020
;  MPASM PIC16F18446 processor include
;
;  (c) Copyright 1999-2020 Microchip Technology, All rights reserved
;==========================================================================

        NOLIST

;==========================================================================
;  This header file defines configurations, registers, and other useful
;  bits of information for the PIC16F18446 microcontroller.  These names
;  are taken to match the data sheets as closely as possible.
;
;  Note that the processor must be selected before this file is included.
;  The processor may be selected the following ways:
;
;       1. Command line switch:
;               C:\MPASM MYFILE.ASM /PIC16F18446
;       2. LIST directive in the source file
;               LIST   P=PIC16F18446
;       3. Processor Type entry in the MPASM full-screen interface
;       4. Setting the processor in the MPLAB Project Dialog
;==========================================================================

;==========================================================================
;
;       Verify Processor
;
;==========================================================================
        IFNDEF __16F18446
           MESSG "Processor-header file mismatch.  Verify selected processor."
        ENDIF



;==========================================================================
;
;       Register Definitions
;
;==========================================================================

W                EQU  H'0000'
F                EQU  H'0001'

;----- Register Files -----------------------------------------------------

;-----Bank0------------------
INDF0            EQU  H'0000'
INDF1            EQU  H'0001'
PCL              EQU  H'0002'
STATUS           EQU  H'0003'
FSR0             EQU  H'0004'
FSR0L            EQU  H'0004'
FSR0H            EQU  H'0005'
FSR1             EQU  H'0006'
FSR1L            EQU  H'0006'
FSR1H            EQU  H'0007'
BSR              EQU  H'0008'
WREG             EQU  H'0009'
PCLATH           EQU  H'000A'
INTCON           EQU  H'000B'
PORTA            EQU  H'000C'
PORTB            EQU  H'000D'
PORTC            EQU  H'000E'
TRISA            EQU  H'0012'
TRISB            EQU  H'0013'
TRISC            EQU  H'0014'
LATA             EQU  H'0018'
LATB             EQU  H'0019'
LATC             EQU  H'001A'

;-----Bank1------------------
ADLTH            EQU  H'008C'
ADLTHL           EQU  H'008C'
ADLTHH           EQU  H'008D'
ADUTH            EQU  H'008E'
ADUTHL           EQU  H'008E'
ADUTHH           EQU  H'008F'
ADERR            EQU  H'0090'
ADERRL           EQU  H'0090'
ADERRH           EQU  H'0091'
ADSTPT           EQU  H'0092'
ADSTPTL          EQU  H'0092'
ADSTPTH          EQU  H'0093'
ADFLTR           EQU  H'0094'
ADFLTRL          EQU  H'0094'
ADFLTRH          EQU  H'0095'
ADACC            EQU  H'0096'
ADACCL           EQU  H'0096'
ADACCH           EQU  H'0097'
ADACCU           EQU  H'0098'
ADCNT            EQU  H'0099'
ADRPT            EQU  H'009A'
ADPREV           EQU  H'009B'
ADPREVL          EQU  H'009B'
ADPREVH          EQU  H'009C'
ADRES            EQU  H'009D'
ADRESL           EQU  H'009D'
ADRESH           EQU  H'009E'
ADPCH            EQU  H'009F'

;-----Bank2------------------
ADACQ            EQU  H'010C'
ADACQL           EQU  H'010C'
ADACQH           EQU  H'010D'
ADCAP            EQU  H'010E'
ADPRE            EQU  H'010F'
ADPREL           EQU  H'010F'
ADPREH           EQU  H'0110'
ADCON0           EQU  H'0111'
ADCON1           EQU  H'0112'
ADCON2           EQU  H'0113'
ADCON3           EQU  H'0114'
ADSTAT           EQU  H'0115'
ADREF            EQU  H'0116'
ADACT            EQU  H'0117'
ADCLK            EQU  H'0118'
RC1REG           EQU  H'0119'
RCREG            EQU  H'0119'
RCREG1           EQU  H'0119'
TX1REG           EQU  H'011A'
TXREG            EQU  H'011A'
TXREG1           EQU  H'011A'
SP1BRG           EQU  H'011B'
SP1BRGL          EQU  H'011B'
SPBRG            EQU  H'011B'
SPBRG1           EQU  H'011B'
SPBRGL           EQU  H'011B'
SP1BRGH          EQU  H'011C'
SPBRGH           EQU  H'011C'
SPBRGH1          EQU  H'011C'
RC1STA           EQU  H'011D'
RCSTA            EQU  H'011D'
RCSTA1           EQU  H'011D'
TX1STA           EQU  H'011E'
TXSTA            EQU  H'011E'
TXSTA1           EQU  H'011E'
BAUD1CON         EQU  H'011F'
BAUDCON          EQU  H'011F'
BAUDCON1         EQU  H'011F'
BAUDCTL          EQU  H'011F'
BAUDCTL1         EQU  H'011F'

;-----Bank3------------------
SSP1BUF          EQU  H'018C'
SSP1ADD          EQU  H'018D'
SSP1MSK          EQU  H'018E'
SSP1STAT         EQU  H'018F'
SSP1CON1         EQU  H'0190'
SSP1CON2         EQU  H'0191'
SSP1CON3         EQU  H'0192'
SSP2BUF          EQU  H'0196'
SSP2ADD          EQU  H'0197'
SSP2MSK          EQU  H'0198'
SSP2STAT         EQU  H'0199'
SSP2CON1         EQU  H'019A'
SSP2CON2         EQU  H'019B'
SSP2CON3         EQU  H'019C'

;-----Bank4------------------
TMR1L            EQU  H'020C'
TMR1H            EQU  H'020D'
T1CON            EQU  H'020E'
TMR1CON          EQU  H'020E'
T1GCON           EQU  H'020F'
TMR1GCON         EQU  H'020F'
T1GATE           EQU  H'0210'
TMR1GATE         EQU  H'0210'
T1CLK            EQU  H'0211'
TMR1CLK          EQU  H'0211'
TMR3L            EQU  H'0212'
TMR3H            EQU  H'0213'
T3CON            EQU  H'0214'
TMR3CON          EQU  H'0214'
T3GCON           EQU  H'0215'
TMR3GCON         EQU  H'0215'
T3GATE           EQU  H'0216'
TMR3GATE         EQU  H'0216'
T3CLK            EQU  H'0217'
TMR3CLK          EQU  H'0217'
TMR5L            EQU  H'0218'
TMR5H            EQU  H'0219'
T5CON            EQU  H'021A'
TMR5CON          EQU  H'021A'
T5GCON           EQU  H'021B'
TMR5GCON         EQU  H'021B'
T5GATE           EQU  H'021C'
TMR5GATE         EQU  H'021C'
T5CLK            EQU  H'021D'
TMR5CLK          EQU  H'021D'
CCPTMRS0         EQU  H'021E'
CCPTMRS1         EQU  H'021F'

;-----Bank5------------------
T2TMR            EQU  H'028C'
TMR2             EQU  H'028C'
PR2              EQU  H'028D'
T2PR             EQU  H'028D'
T2CON            EQU  H'028E'
T2HLT            EQU  H'028F'
T2CLKCON         EQU  H'0290'
T2RST            EQU  H'0291'
T4TMR            EQU  H'0292'
TMR4             EQU  H'0292'
PR4              EQU  H'0293'
T4PR             EQU  H'0293'
T4CON            EQU  H'0294'
T4HLT            EQU  H'0295'
T4CLKCON         EQU  H'0296'
T4RST            EQU  H'0297'
T6TMR            EQU  H'0298'
TMR6             EQU  H'0298'
PR6              EQU  H'0299'
T6PR             EQU  H'0299'
T6CON            EQU  H'029A'
T6HLT            EQU  H'029B'
T6CLKCON         EQU  H'029C'
T6RST            EQU  H'029D'
ADCPCON0         EQU  H'029F'

;-----Bank6------------------
CCPR1            EQU  H'030C'
CCPR1L           EQU  H'030C'
CCPR1H           EQU  H'030D'
CCP1CON          EQU  H'030E'
CCP1CAP          EQU  H'030F'
CCPR2            EQU  H'0310'
CCPR2L           EQU  H'0310'
CCPR2H           EQU  H'0311'
CCP2CON          EQU  H'0312'
CCP2CAP          EQU  H'0313'
CCPR3            EQU  H'0314'
CCPR3L           EQU  H'0314'
CCPR3H           EQU  H'0315'
CCP3CON          EQU  H'0316'
CCP3CAP          EQU  H'0317'
CCPR4            EQU  H'0318'
CCPR4L           EQU  H'0318'
CCPR4H           EQU  H'0319'
CCP4CON          EQU  H'031A'
CCP4CAP          EQU  H'031B'

;-----Bank7------------------
PWM6DC           EQU  H'038C'
PWM6DCL          EQU  H'038C'
PWM6DCH          EQU  H'038D'
PWM6CON          EQU  H'038E'
PWM7DC           EQU  H'0390'
PWM7DCL          EQU  H'0390'
PWM7DCH          EQU  H'0391'
PWM7CON          EQU  H'0392'

;-----Bank9------------------
SMT1TMR          EQU  H'048C'
SMT1TMRL         EQU  H'048C'
SMT1TMRH         EQU  H'048D'
SMT1TMRU         EQU  H'048E'
SMT1CPR          EQU  H'048F'
SMT1CPRL         EQU  H'048F'
SMT1CPRH         EQU  H'0490'
SMT1CPRU         EQU  H'0491'
SMT1CPW          EQU  H'0492'
SMT1CPWL         EQU  H'0492'
SMT1CPWH         EQU  H'0493'
SMT1CPWU         EQU  H'0494'
SMT1PR           EQU  H'0495'
SMT1PRL          EQU  H'0495'
SMT1PRH          EQU  H'0496'
SMT1PRU          EQU  H'0497'
SMT1CON0         EQU  H'0498'
SMT1CON1         EQU  H'0499'
SMT1STAT         EQU  H'049A'
SMT1CLK          EQU  H'049B'
SMT1SIG          EQU  H'049C'
SMT1WIN          EQU  H'049D'

;-----Bank11------------------
NCO1ACC          EQU  H'058C'
NCO1ACCL         EQU  H'058C'
NCO1ACCH         EQU  H'058D'
NCO1ACCU         EQU  H'058E'
NCO1INC          EQU  H'058F'
NCO1INCL         EQU  H'058F'
NCO1INCH         EQU  H'0590'
NCO1INCU         EQU  H'0591'
NCO1CON          EQU  H'0592'
NCO1CLK          EQU  H'0593'
TMR0             EQU  H'059C'
TMR0L            EQU  H'059C'
PR0              EQU  H'059D'
TMR0H            EQU  H'059D'
T0CON0           EQU  H'059E'
T0CON1           EQU  H'059F'

;-----Bank12------------------
CWG1CLK          EQU  H'060C'
CWG1CLKCON       EQU  H'060C'
CWG1DAT          EQU  H'060D'
CWG1ISM          EQU  H'060D'
CWG1DBR          EQU  H'060E'
CWG1DBF          EQU  H'060F'
CWG1CON0         EQU  H'0610'
CWG1CON1         EQU  H'0611'
CWG1AS0          EQU  H'0612'
CWG1AS1          EQU  H'0613'
CWG1STR          EQU  H'0614'
CWG2CLK          EQU  H'0616'
CWG2CLKCON       EQU  H'0616'
CWG2DAT          EQU  H'0617'
CWG2ISM          EQU  H'0617'
CWG2DBR          EQU  H'0618'
CWG2DBF          EQU  H'0619'
CWG2CON0         EQU  H'061A'
CWG2CON1         EQU  H'061B'
CWG2AS0          EQU  H'061C'
CWG2AS1          EQU  H'061D'
CWG2STR          EQU  H'061E'

;-----Bank14------------------
PIR0             EQU  H'070C'
PIR1             EQU  H'070D'
PIR2             EQU  H'070E'
PIR3             EQU  H'070F'
PIR4             EQU  H'0710'
PIR5             EQU  H'0711'
PIR6             EQU  H'0712'
PIR7             EQU  H'0713'
PIR8             EQU  H'0714'
PIE0             EQU  H'0716'
PIE1             EQU  H'0717'
PIE2             EQU  H'0718'
PIE3             EQU  H'0719'
PIE4             EQU  H'071A'
PIE5             EQU  H'071B'
PIE6             EQU  H'071C'
PIE7             EQU  H'071D'
PIE8             EQU  H'071E'

;-----Bank15------------------
PMD0             EQU  H'0796'
PMD1             EQU  H'0797'
PMD2             EQU  H'0798'
PMD3             EQU  H'0799'
PMD4             EQU  H'079A'
PMD5             EQU  H'079B'
PMD6             EQU  H'079C'
PMD7             EQU  H'079D'

;-----Bank16------------------
WDTCON0          EQU  H'080C'
WDTCON1          EQU  H'080D'
WDTPSL           EQU  H'080E'
WDTPSH           EQU  H'080F'
WDTTMR           EQU  H'0810'
BORCON           EQU  H'0811'
VREGCON          EQU  H'0812'
PCON0            EQU  H'0813'
PCON1            EQU  H'0814'
NVMADR           EQU  H'081A'
NVMADRL          EQU  H'081A'
NVMADRH          EQU  H'081B'
NVMDAT           EQU  H'081C'
NVMDATL          EQU  H'081C'
NVMDATH          EQU  H'081D'
NVMCON1          EQU  H'081E'
NVMCON2          EQU  H'081F'

;-----Bank17------------------
CPUDOZE          EQU  H'088C'
OSCCON1          EQU  H'088D'
OSCCON2          EQU  H'088E'
OSCCON3          EQU  H'088F'
OSCSTAT          EQU  H'0890'
OSCEN            EQU  H'0891'
OSCTUNE          EQU  H'0892'
OSCFRQ           EQU  H'0893'
CLKRCON          EQU  H'0895'
CLKRCLK          EQU  H'0896'
MD1CON0          EQU  H'0897'
MD1CON1          EQU  H'0898'
MD1SRC           EQU  H'0899'
MD1CARL          EQU  H'089A'
MD1CARH          EQU  H'089B'

;-----Bank18------------------
FVRCON           EQU  H'090C'
DAC1CON0         EQU  H'090E'
DAC1CON1         EQU  H'090F'
ZCDCON           EQU  H'091F'

;-----Bank19------------------
CMOUT            EQU  H'098F'
CMSTAT           EQU  H'098F'
CM1CON0          EQU  H'0990'
CM1CON1          EQU  H'0991'
CM1NCH           EQU  H'0992'
CM1PCH           EQU  H'0993'
CM2CON0          EQU  H'0994'
CM2CON1          EQU  H'0995'
CM2NCH           EQU  H'0996'
CM2PCH           EQU  H'0997'

;-----Bank60------------------
CLCDATA          EQU  H'1E0F'
CLC1CON          EQU  H'1E10'
CLC1POL          EQU  H'1E11'
CLC1SEL0         EQU  H'1E12'
CLC1SEL1         EQU  H'1E13'
CLC1SEL2         EQU  H'1E14'
CLC1SEL3         EQU  H'1E15'
CLC1GLS0         EQU  H'1E16'
CLC1GLS1         EQU  H'1E17'
CLC1GLS2         EQU  H'1E18'
CLC1GLS3         EQU  H'1E19'
CLC2CON          EQU  H'1E1A'
CLC2POL          EQU  H'1E1B'
CLC2SEL0         EQU  H'1E1C'
CLC2SEL1         EQU  H'1E1D'
CLC2SEL2         EQU  H'1E1E'
CLC2SEL3         EQU  H'1E1F'
CLC2GLS0         EQU  H'1E20'
CLC2GLS1         EQU  H'1E21'
CLC2GLS2         EQU  H'1E22'
CLC2GLS3         EQU  H'1E23'
CLC3CON          EQU  H'1E24'
CLC3POL          EQU  H'1E25'
CLC3SEL0         EQU  H'1E26'
CLC3SEL1         EQU  H'1E27'
CLC3SEL2         EQU  H'1E28'
CLC3SEL3         EQU  H'1E29'
CLC3GLS0         EQU  H'1E2A'
CLC3GLS1         EQU  H'1E2B'
CLC3GLS2         EQU  H'1E2C'
CLC3GLS3         EQU  H'1E2D'
CLC4CON          EQU  H'1E2E'
CLC4POL          EQU  H'1E2F'
CLC4SEL0         EQU  H'1E30'
CLC4SEL1         EQU  H'1E31'
CLC4SEL2         EQU  H'1E32'
CLC4SEL3         EQU  H'1E33'
CLC4GLS0         EQU  H'1E34'
CLC4GLS1         EQU  H'1E35'
CLC4GLS2         EQU  H'1E36'
CLC4GLS3         EQU  H'1E37'

;-----Bank61------------------
PPSLOCK          EQU  H'1E8F'
INTPPS           EQU  H'1E90'
T0CKIPPS         EQU  H'1E91'
T1CKIPPS         EQU  H'1E92'
T1GPPS           EQU  H'1E93'
T3CKIPPS         EQU  H'1E94'
T3GPPS           EQU  H'1E95'
T5CKIPPS         EQU  H'1E96'
T5GPPS           EQU  H'1E97'
T2INPPS          EQU  H'1E9C'
T4INPPS          EQU  H'1E9D'
T6INPPS          EQU  H'1E9E'
CCP1PPS          EQU  H'1EA1'
CCP2PPS          EQU  H'1EA2'
CCP3PPS          EQU  H'1EA3'
CCP4PPS          EQU  H'1EA4'
SMT1WINPPS       EQU  H'1EA9'
SMT1SIGPPS       EQU  H'1EAA'
CWG1PPS          EQU  H'1EB1'
CWG2PPS          EQU  H'1EB2'
MDCARLPPS        EQU  H'1EB8'
MDCARHPPS        EQU  H'1EB9'
MDSRCPPS         EQU  H'1EBA'
CLCIN0PPS        EQU  H'1EBB'
CLCIN1PPS        EQU  H'1EBC'
CLCIN2PPS        EQU  H'1EBD'
CLCIN3PPS        EQU  H'1EBE'
ADACTPPS         EQU  H'1EC3'
SSP1CLKPPS       EQU  H'1EC5'
SSP1DATPPS       EQU  H'1EC6'
SSP1SSPPS        EQU  H'1EC7'
SSP2CLKPPS       EQU  H'1EC8'
SSP2DATPPS       EQU  H'1EC9'
SSP2SSPPS        EQU  H'1ECA'
RX1DTPPS         EQU  H'1ECB'
RX1PPS           EQU  H'1ECB'
RXPPS            EQU  H'1ECB'
CK1PPS           EQU  H'1ECC'
CKPPS            EQU  H'1ECC'
TX1CKPPS         EQU  H'1ECC'

;-----Bank62------------------
RA0PPS           EQU  H'1F10'
RA1PPS           EQU  H'1F11'
RA2PPS           EQU  H'1F12'
RA4PPS           EQU  H'1F14'
RA5PPS           EQU  H'1F15'
RB4PPS           EQU  H'1F1C'
RB5PPS           EQU  H'1F1D'
RB6PPS           EQU  H'1F1E'
RB7PPS           EQU  H'1F1F'
RC0PPS           EQU  H'1F20'
RC1PPS           EQU  H'1F21'
RC2PPS           EQU  H'1F22'
RC3PPS           EQU  H'1F23'
RC4PPS           EQU  H'1F24'
RC5PPS           EQU  H'1F25'
RC6PPS           EQU  H'1F26'
RC7PPS           EQU  H'1F27'
ANSELA           EQU  H'1F38'
WPUA             EQU  H'1F39'
ODCONA           EQU  H'1F3A'
SLRCONA          EQU  H'1F3B'
INLVLA           EQU  H'1F3C'
IOCAP            EQU  H'1F3D'
IOCAN            EQU  H'1F3E'
IOCAF            EQU  H'1F3F'
ANSELB           EQU  H'1F43'
WPUB             EQU  H'1F44'
ODCONB           EQU  H'1F45'
SLRCONB          EQU  H'1F46'
INLVLB           EQU  H'1F47'
IOCBP            EQU  H'1F48'
IOCBN            EQU  H'1F49'
IOCBF            EQU  H'1F4A'
ANSELC           EQU  H'1F4E'
WPUC             EQU  H'1F4F'
ODCONC           EQU  H'1F50'
SLRCONC          EQU  H'1F51'
INLVLC           EQU  H'1F52'
IOCCP            EQU  H'1F53'
IOCCN            EQU  H'1F54'
IOCCF            EQU  H'1F55'

;-----Bank63------------------
STATUS_SHAD      EQU  H'1FE4'
WREG_SHAD        EQU  H'1FE5'
BSR_SHAD         EQU  H'1FE6'
PCLATH_SHAD      EQU  H'1FE7'
FSR0L_SHAD       EQU  H'1FE8'
FSR0_SHAD        EQU  H'1FE8'
FSR0H_SHAD       EQU  H'1FE9'
FSR1L_SHAD       EQU  H'1FEA'
FSR1H_SHAD       EQU  H'1FEB'
STKPTR           EQU  H'1FED'
TOSL             EQU  H'1FEE'
TOSH             EQU  H'1FEF'

;----- STATUS Bits -----------------------------------------------------
C                EQU  H'0000'
DC               EQU  H'0001'
Z                EQU  H'0002'
NOT_PD           EQU  H'0003'
NOT_TO           EQU  H'0004'


;----- BSR Bits -----------------------------------------------------
BSR0             EQU  H'0000'
BSR1             EQU  H'0001'
BSR2             EQU  H'0002'
BSR3             EQU  H'0003'
BSR4             EQU  H'0004'
BSR5             EQU  H'0005'


;----- INTCON Bits -----------------------------------------------------
INTEDG           EQU  H'0000'
PEIE             EQU  H'0006'
GIE              EQU  H'0007'


;----- PORTA Bits -----------------------------------------------------
RA0              EQU  H'0000'
RA1              EQU  H'0001'
RA2              EQU  H'0002'
RA3              EQU  H'0003'
RA4              EQU  H'0004'
RA5              EQU  H'0005'


;----- PORTB Bits -----------------------------------------------------
RB4              EQU  H'0004'
RB5              EQU  H'0005'
RB6              EQU  H'0006'
RB7              EQU  H'0007'


;----- PORTC Bits -----------------------------------------------------
RC0              EQU  H'0000'
RC1              EQU  H'0001'
RC2              EQU  H'0002'
RC3              EQU  H'0003'
RC4              EQU  H'0004'
RC5              EQU  H'0005'
RC6              EQU  H'0006'
RC7              EQU  H'0007'


;----- TRISA Bits -----------------------------------------------------
TRISA0           EQU  H'0000'
TRISA1           EQU  H'0001'
TRISA2           EQU  H'0002'
TRISA3           EQU  H'0003'
TRISA4           EQU  H'0004'
TRISA5           EQU  H'0005'


;----- TRISB Bits -----------------------------------------------------
TRISB4           EQU  H'0004'
TRISB5           EQU  H'0005'
TRISB6           EQU  H'0006'
TRISB7           EQU  H'0007'


;----- TRISC Bits -----------------------------------------------------
TRISC0           EQU  H'0000'
TRISC1           EQU  H'0001'
TRISC2           EQU  H'0002'
TRISC3           EQU  H'0003'
TRISC4           EQU  H'0004'
TRISC5           EQU  H'0005'
TRISC6           EQU  H'0006'
TRISC7           EQU  H'0007'


;----- LATA Bits -----------------------------------------------------
LATA0            EQU  H'0000'
LATA1            EQU  H'0001'
LATA2            EQU  H'0002'
LATA3            EQU  H'0003'
LATA4            EQU  H'0004'
LATA5            EQU  H'0005'


;----- LATB Bits -----------------------------------------------------
LATB4            EQU  H'0004'
LATB5            EQU  H'0005'
LATB6            EQU  H'0006'
LATB7            EQU  H'0007'


;----- LATC Bits -----------------------------------------------------
LATC0            EQU  H'0000'
LATC1            EQU  H'0001'
LATC2            EQU  H'0002'
LATC3            EQU  H'0003'
LATC4            EQU  H'0004'
LATC5            EQU  H'0005'
LATC6            EQU  H'0006'
LATC7            EQU  H'0007'


;----- ADLTHL Bits -----------------------------------------------------
ADLTH0           EQU  H'0000'
ADLTH1           EQU  H'0001'
ADLTH2           EQU  H'0002'
ADLTH3           EQU  H'0003'
ADLTH4           EQU  H'0004'
ADLTH5           EQU  H'0005'
ADLTH6           EQU  H'0006'
ADLTH7           EQU  H'0007'


LTH0             EQU  H'0000'
LTH1             EQU  H'0001'
LTH2             EQU  H'0002'
LTH3             EQU  H'0003'
LTH4             EQU  H'0004'
LTH5             EQU  H'0005'
LTH6             EQU  H'0006'
LTH7             EQU  H'0007'


;----- ADLTHH Bits -----------------------------------------------------
ADLTH8           EQU  H'0000'
ADLTH9           EQU  H'0001'
ADLTH10          EQU  H'0002'
ADLTH11          EQU  H'0003'
ADLTH12          EQU  H'0004'
ADLTH13          EQU  H'0005'
ADLTH14          EQU  H'0006'
ADLTH15          EQU  H'0007'


LTH8             EQU  H'0000'
LTH9             EQU  H'0001'
LTH10            EQU  H'0002'
LTH11            EQU  H'0003'
LTH12            EQU  H'0004'
LTH13            EQU  H'0005'
LTH14            EQU  H'0006'
LTH15            EQU  H'0007'


;----- ADUTHL Bits -----------------------------------------------------
ADUTH0           EQU  H'0000'
ADUTH1           EQU  H'0001'
ADUTH2           EQU  H'0002'
ADUTH3           EQU  H'0003'
ADUTH4           EQU  H'0004'
ADUTH5           EQU  H'0005'
ADUTH6           EQU  H'0006'
ADUTH7           EQU  H'0007'


UTH0             EQU  H'0000'
UTH1             EQU  H'0001'
UTH2             EQU  H'0002'
UTH3             EQU  H'0003'
UTH4             EQU  H'0004'
UTH5             EQU  H'0005'
UTH6             EQU  H'0006'
UTH7             EQU  H'0007'


;----- ADUTHH Bits -----------------------------------------------------
ADUTH8           EQU  H'0000'
ADUTH9           EQU  H'0001'
ADUTH10          EQU  H'0002'
ADUTH11          EQU  H'0003'
ADUTH12          EQU  H'0004'
ADUTH13          EQU  H'0005'
ADUTH14          EQU  H'0006'
ADUTH15          EQU  H'0007'


UTH8             EQU  H'0000'
UTH9             EQU  H'0001'
UTH10            EQU  H'0002'
UTH11            EQU  H'0003'
UTH12            EQU  H'0004'
UTH13            EQU  H'0005'
UTH14            EQU  H'0006'
UTH15            EQU  H'0007'


;----- ADERRL Bits -----------------------------------------------------
ADERR0           EQU  H'0000'
ADERR1           EQU  H'0001'
ADERR2           EQU  H'0002'
ADERR3           EQU  H'0003'
ADERR4           EQU  H'0004'
ADERR5           EQU  H'0005'
ADERR6           EQU  H'0006'
ADERR7           EQU  H'0007'


ERR0             EQU  H'0000'
ERR1             EQU  H'0001'
ERR2             EQU  H'0002'
ERR3             EQU  H'0003'
ERR4             EQU  H'0004'
ERR5             EQU  H'0005'
ERR6             EQU  H'0006'
ERR7             EQU  H'0007'


;----- ADERRH Bits -----------------------------------------------------
ADERR8           EQU  H'0000'
ADERR9           EQU  H'0001'
ADERR10          EQU  H'0002'
ADERR11          EQU  H'0003'
ADERR12          EQU  H'0004'
ADERR13          EQU  H'0005'
ADERR14          EQU  H'0006'
ADERR15          EQU  H'0007'


ERR8             EQU  H'0000'
ERR9             EQU  H'0001'
ERR10            EQU  H'0002'
ERR11            EQU  H'0003'
ERR12            EQU  H'0004'
ERR13            EQU  H'0005'
ERR14            EQU  H'0006'
ERR15            EQU  H'0007'


;----- ADSTPTL Bits -----------------------------------------------------
ADSTPT0          EQU  H'0000'
ADSTPT1          EQU  H'0001'
ADSTPT2          EQU  H'0002'
ADSTPT3          EQU  H'0003'
ADSTPT4          EQU  H'0004'
ADSTPT5          EQU  H'0005'
ADSTPT6          EQU  H'0006'
ADSTPT7          EQU  H'0007'


STPT0            EQU  H'0000'
STPT1            EQU  H'0001'
STPT2            EQU  H'0002'
STPT3            EQU  H'0003'
STPT4            EQU  H'0004'
STPT5            EQU  H'0005'
STPT6            EQU  H'0006'
STPT7            EQU  H'0007'


;----- ADSTPTH Bits -----------------------------------------------------
ADSTPT8          EQU  H'0000'
ADSTPT9          EQU  H'0001'
ADSTPT10         EQU  H'0002'
ADSTPT11         EQU  H'0003'
ADSTPT12         EQU  H'0004'
ADSTPT13         EQU  H'0005'
ADSTPT14         EQU  H'0006'
ADSTPT15         EQU  H'0007'


STPT8            EQU  H'0000'
STPT9            EQU  H'0001'
STPT10           EQU  H'0002'
STPT11           EQU  H'0003'
STPT12           EQU  H'0004'
STPT13           EQU  H'0005'
STPT15           EQU  H'0006'
STPT16           EQU  H'0007'


;----- ADFLTRL Bits -----------------------------------------------------
ADFLTR0          EQU  H'0000'
ADFLTR1          EQU  H'0001'
ADFLTR2          EQU  H'0002'
ADFLTR3          EQU  H'0003'
ADFLTR4          EQU  H'0004'
ADFLTR5          EQU  H'0005'
ADFLTR6          EQU  H'0006'
ADFLTR7          EQU  H'0007'


FLTR0            EQU  H'0000'
FLTR1            EQU  H'0001'
FLTR2            EQU  H'0002'
FLTR3            EQU  H'0003'
FLTR4            EQU  H'0004'
FLTR5            EQU  H'0005'
FLTR6            EQU  H'0006'
FLTR7            EQU  H'0007'


;----- ADFLTRH Bits -----------------------------------------------------
ADFLTR8          EQU  H'0000'
ADFLTR9          EQU  H'0001'
ADFLTR10         EQU  H'0002'
ADFLTR11         EQU  H'0003'
ADFLTR12         EQU  H'0004'
ADFLTR13         EQU  H'0005'
ADFLTR14         EQU  H'0006'
ADFLTR15         EQU  H'0007'


FLTR8            EQU  H'0000'
FLTR9            EQU  H'0001'
FLTR10           EQU  H'0002'
FLTR11           EQU  H'0003'
FLTR12           EQU  H'0004'
FLTR13           EQU  H'0005'
FLTR14           EQU  H'0006'
FLTR15           EQU  H'0007'


;----- ADACCL Bits -----------------------------------------------------
ADACC0           EQU  H'0000'
ADACC1           EQU  H'0001'
ADACC2           EQU  H'0002'
ADACC3           EQU  H'0003'
ADACC4           EQU  H'0004'
ADACC5           EQU  H'0005'
ADACC6           EQU  H'0006'
ADACC7           EQU  H'0007'


ACC0             EQU  H'0000'
ACC1             EQU  H'0001'
ACC2             EQU  H'0002'
ACC3             EQU  H'0003'
ACC4             EQU  H'0004'
ACC5             EQU  H'0005'
ACC6             EQU  H'0006'
ACC7             EQU  H'0007'


;----- ADACCH Bits -----------------------------------------------------
ADACC8           EQU  H'0000'
ADACC9           EQU  H'0001'
ADACC10          EQU  H'0002'
ADACC11          EQU  H'0003'
ADACC12          EQU  H'0004'
ADACC13          EQU  H'0005'
ADACC14          EQU  H'0006'
ADACC15          EQU  H'0007'


ACC8             EQU  H'0000'
ACC9             EQU  H'0001'
ACC10            EQU  H'0002'
ACC11            EQU  H'0003'
ACC12            EQU  H'0004'
ACC13            EQU  H'0005'
ACC14            EQU  H'0006'
ACC15            EQU  H'0007'


;----- ADACCU Bits -----------------------------------------------------
ADACC16          EQU  H'0000'
ADACC17          EQU  H'0001'
ADACC18          EQU  H'0002'
ADACC19          EQU  H'0003'
ADACC20          EQU  H'0004'
ADACC21          EQU  H'0005'
ADACC22          EQU  H'0006'
ADACC23          EQU  H'0007'


ACC16            EQU  H'0000'
ACC17            EQU  H'0001'
ACC18            EQU  H'0002'
ACC19            EQU  H'0003'
ACC20            EQU  H'0004'
ACC21            EQU  H'0005'
ACC22            EQU  H'0006'
ACC23            EQU  H'0007'


;----- ADCNT Bits -----------------------------------------------------
ADCNT0           EQU  H'0000'
ADCNT1           EQU  H'0001'
ADCNT2           EQU  H'0002'
ADCNT3           EQU  H'0003'
ADCNT4           EQU  H'0004'
ADCNT5           EQU  H'0005'
ADCNT6           EQU  H'0006'
ADCNT7           EQU  H'0007'


CNT0             EQU  H'0000'
CNT1             EQU  H'0001'
CNT2             EQU  H'0002'
CNT3             EQU  H'0003'
CNT4             EQU  H'0004'
CNT5             EQU  H'0005'
CNT6             EQU  H'0006'
CNT7             EQU  H'0007'


;----- ADRPT Bits -----------------------------------------------------
ADRPT0           EQU  H'0000'
ADRPT1           EQU  H'0001'
ADRPT2           EQU  H'0002'
ADRPT3           EQU  H'0003'
ADRPT4           EQU  H'0004'
ADRPT5           EQU  H'0005'
ADRPT6           EQU  H'0006'
ADRPT7           EQU  H'0007'


RPT0             EQU  H'0000'
RPT1             EQU  H'0001'
RPT2             EQU  H'0002'
RPT3             EQU  H'0003'
RPT4             EQU  H'0004'
RPT5             EQU  H'0005'
RPT6             EQU  H'0006'
RPT7             EQU  H'0007'


;----- ADPREVL Bits -----------------------------------------------------
ADPREV0          EQU  H'0000'
ADPREV1          EQU  H'0001'
ADPREV2          EQU  H'0002'
ADPREV3          EQU  H'0003'
ADPREV4          EQU  H'0004'
ADPREV5          EQU  H'0005'
ADPREV6          EQU  H'0006'
ADPREV7          EQU  H'0007'


PREV0            EQU  H'0000'
PREV1            EQU  H'0001'
PREV2            EQU  H'0002'
PREV3            EQU  H'0003'
PREV4            EQU  H'0004'
PREV5            EQU  H'0005'
PREV6            EQU  H'0006'
PREV7            EQU  H'0007'


;----- ADPREVH Bits -----------------------------------------------------
ADPREV8          EQU  H'0000'
ADPREV9          EQU  H'0001'
ADPREV10         EQU  H'0002'
ADPREV11         EQU  H'0003'
ADPREV12         EQU  H'0004'
ADPREV13         EQU  H'0005'
ADPREV14         EQU  H'0006'
ADPREV15         EQU  H'0007'


PREV8            EQU  H'0000'
PREV9            EQU  H'0001'
PREV10           EQU  H'0002'
PREV11           EQU  H'0003'
PREV12           EQU  H'0004'
PREV13           EQU  H'0005'
PREV14           EQU  H'0006'
PREV15           EQU  H'0007'


;----- ADRESL Bits -----------------------------------------------------
ADRES0           EQU  H'0000'
ADRES1           EQU  H'0001'
ADRES2           EQU  H'0002'
ADRES3           EQU  H'0003'
ADRES4           EQU  H'0004'
ADRES5           EQU  H'0005'
ADRES6           EQU  H'0006'
ADRES7           EQU  H'0007'


RES0             EQU  H'0000'
RES1             EQU  H'0001'
RES2             EQU  H'0002'
RES3             EQU  H'0003'
RES4             EQU  H'0004'
RES5             EQU  H'0005'
RES6             EQU  H'0006'
RES7             EQU  H'0007'


;----- ADRESH Bits -----------------------------------------------------
ADRES8           EQU  H'0000'
ADRES9           EQU  H'0001'
ADRES10          EQU  H'0002'
ADRES11          EQU  H'0003'
ADRES12          EQU  H'0004'
ADRES13          EQU  H'0005'
ADRES14          EQU  H'0006'
ADRES15          EQU  H'0007'


RES8             EQU  H'0000'
RES9             EQU  H'0001'
RES10            EQU  H'0002'
RES11            EQU  H'0003'
RES12            EQU  H'0004'
RES13            EQU  H'0005'
RES14            EQU  H'0006'
RES15            EQU  H'0007'


;----- ADPCH Bits -----------------------------------------------------
ADPCH0           EQU  H'0000'
ADPCH1           EQU  H'0001'
ADPCH2           EQU  H'0002'
ADPCH3           EQU  H'0003'
ADPCH4           EQU  H'0004'
ADPCH5           EQU  H'0005'


PCH0             EQU  H'0000'
PCH1             EQU  H'0001'
PCH2             EQU  H'0002'
PCH3             EQU  H'0003'
PCH4             EQU  H'0004'
PCH5             EQU  H'0005'


;----- ADACQL Bits -----------------------------------------------------
ADACQ0           EQU  H'0000'
ADACQ1           EQU  H'0001'
ADACQ2           EQU  H'0002'
ADACQ3           EQU  H'0003'
ADACQ4           EQU  H'0004'
ADACQ5           EQU  H'0005'
ADACQ6           EQU  H'0006'
ADACQ7           EQU  H'0007'


ACQ0             EQU  H'0000'
ACQ1             EQU  H'0001'
ACQ2             EQU  H'0002'
ACQ3             EQU  H'0003'
ACQ4             EQU  H'0004'
ACQ5             EQU  H'0005'
ACQ6             EQU  H'0006'
ACQ7             EQU  H'0007'


;----- ADACQH Bits -----------------------------------------------------
ADACQ8           EQU  H'0000'
ADACQ9           EQU  H'0001'
ADACQ10          EQU  H'0002'
ADACQ11          EQU  H'0003'
ADACQ12          EQU  H'0004'


ACQ8             EQU  H'0000'
ACQ9             EQU  H'0001'
ACQ10            EQU  H'0002'
ACQ11            EQU  H'0003'
ACQ12            EQU  H'0004'


;----- ADCAP Bits -----------------------------------------------------
ADCAP0           EQU  H'0000'
ADCAP1           EQU  H'0001'
ADCAP2           EQU  H'0002'
ADCAP3           EQU  H'0003'
ADCAP4           EQU  H'0004'


CAP0             EQU  H'0000'
CAP1             EQU  H'0001'
CAP2             EQU  H'0002'
CAP3             EQU  H'0003'
CAP4             EQU  H'0004'


;----- ADPREL Bits -----------------------------------------------------
PRE0             EQU  H'0000'
PRE1             EQU  H'0001'
PRE2             EQU  H'0002'
PRE3             EQU  H'0003'
PRE4             EQU  H'0004'
PRE5             EQU  H'0005'
PRE6             EQU  H'0006'
PRE7             EQU  H'0007'


ADPRE0           EQU  H'0000'
ADPRE1           EQU  H'0001'
ADPRE2           EQU  H'0002'
ADPRE3           EQU  H'0003'
ADPRE4           EQU  H'0004'
ADPRE5           EQU  H'0005'
ADPRE6           EQU  H'0006'
ADPRE7           EQU  H'0007'


;----- ADPREH Bits -----------------------------------------------------
PRE8             EQU  H'0000'
PRE9             EQU  H'0001'
PRE10            EQU  H'0002'
PRE11            EQU  H'0003'
PRE12            EQU  H'0004'


ADPRE8           EQU  H'0000'
ADPRE9           EQU  H'0001'
ADPRE10          EQU  H'0002'
ADPRE11          EQU  H'0003'
ADPRE12          EQU  H'0004'


;----- ADCON0 Bits -----------------------------------------------------
GO_ADCON0        EQU  H'0000'
CS               EQU  H'0004'
CONT             EQU  H'0006'
ON_ADCON0        EQU  H'0007'

ADGO             EQU  H'0000'
ADCS             EQU  H'0004'
ADCONT           EQU  H'0006'
ADON             EQU  H'0007'

DONE             EQU  H'0000'
FM0              EQU  H'0002'
FM1              EQU  H'0003'

GO_NOT_DONE      EQU  H'0000'
ADFM0            EQU  H'0002'
ADFM1            EQU  H'0003'


;----- ADCON1 Bits -----------------------------------------------------
DSEN             EQU  H'0000'
GBOE             EQU  H'0003'
GAOE             EQU  H'0004'
GPOL_ADCON1      EQU  H'0005'
IPEN             EQU  H'0006'
PPOL             EQU  H'0007'

ADDSEN           EQU  H'0000'
ADGBOE           EQU  H'0003'
ADGAOE           EQU  H'0004'
ADGPOL           EQU  H'0005'
ADIPEN           EQU  H'0006'
ADPPOL           EQU  H'0007'


;----- ADCON2 Bits -----------------------------------------------------
ACLR             EQU  H'0003'
PSIS             EQU  H'0007'

ADMD0            EQU  H'0000'
ADMD1            EQU  H'0001'
ADMD2            EQU  H'0002'
ADACLR           EQU  H'0003'
ADCRS0           EQU  H'0004'
ADCRS1           EQU  H'0005'
ADCRS2           EQU  H'0006'
ADPSIS           EQU  H'0007'


MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'
CRS0             EQU  H'0004'
CRS1             EQU  H'0005'
CRS2             EQU  H'0006'


MD0              EQU  H'0000'
MD1              EQU  H'0001'
MD2              EQU  H'0002'



;----- ADCON3 Bits -----------------------------------------------------
SOI              EQU  H'0003'

ADTMD0           EQU  H'0000'
ADTMD1           EQU  H'0001'
ADTMD2           EQU  H'0002'
ADSOI            EQU  H'0003'
ADCALC0          EQU  H'0004'
ADCALC1          EQU  H'0005'
ADCALC2          EQU  H'0006'


TMD0             EQU  H'0000'
TMD1             EQU  H'0001'
TMD2             EQU  H'0002'
CALC0            EQU  H'0004'
CALC1            EQU  H'0005'
CALC2            EQU  H'0006'


;----- ADSTAT Bits -----------------------------------------------------
MATH             EQU  H'0004'
LTHR             EQU  H'0005'
UTHR             EQU  H'0006'
OV               EQU  H'0007'

ADSTAT0          EQU  H'0000'
ADSTAT1          EQU  H'0001'
ADSTAT2          EQU  H'0002'
ADMATH           EQU  H'0004'
ADLTHR           EQU  H'0005'
ADUTHR           EQU  H'0006'
ADAOV            EQU  H'0007'

ADOV             EQU  H'0007'

STAT0            EQU  H'0000'
STAT1            EQU  H'0001'
STAT2            EQU  H'0002'


;----- ADREF Bits -----------------------------------------------------
PREF0            EQU  H'0000'
PREF1            EQU  H'0001'
PREF2            EQU  H'0002'
PREF3            EQU  H'0003'
NREF0            EQU  H'0004'
NREF1            EQU  H'0005'
NREF2            EQU  H'0006'
NREF3            EQU  H'0007'

ADPREF0          EQU  H'0000'
ADPREF1          EQU  H'0001'
ADPREF2          EQU  H'0002'
ADPREF3          EQU  H'0003'
ADNREF0          EQU  H'0004'
ADNREF1          EQU  H'0005'
ADNREF2          EQU  H'0006'
ADNREF3          EQU  H'0007'


;----- ADACT Bits -----------------------------------------------------
ADACT0           EQU  H'0000'
ADACT1           EQU  H'0001'
ADACT2           EQU  H'0002'
ADACT3           EQU  H'0003'
ADACT4           EQU  H'0004'


ACT0             EQU  H'0000'
ACT1             EQU  H'0001'
ACT2             EQU  H'0002'
ACT3             EQU  H'0003'
ACT4             EQU  H'0004'


;----- ADCLK Bits -----------------------------------------------------
ADCS0            EQU  H'0000'
ADCS1            EQU  H'0001'
ADCS2            EQU  H'0002'
ADCS3            EQU  H'0003'
ADCS4            EQU  H'0004'
ADCS5            EQU  H'0005'


CS0_ADCLK        EQU  H'0000'
CS1_ADCLK        EQU  H'0001'
CS2_ADCLK        EQU  H'0002'
CS3              EQU  H'0003'
CS4              EQU  H'0004'
CS5              EQU  H'0005'


;----- RC1STA Bits -----------------------------------------------------
RX9D             EQU  H'0000'
OERR             EQU  H'0001'
FERR             EQU  H'0002'
ADDEN            EQU  H'0003'
CREN             EQU  H'0004'
SREN             EQU  H'0005'
RX9              EQU  H'0006'
SPEN             EQU  H'0007'


;----- RCSTA Bits -----------------------------------------------------
RX9D             EQU  H'0000'
OERR             EQU  H'0001'
FERR             EQU  H'0002'
ADDEN            EQU  H'0003'
CREN             EQU  H'0004'
SREN             EQU  H'0005'
RX9              EQU  H'0006'
SPEN             EQU  H'0007'


;----- RCSTA1 Bits -----------------------------------------------------
RX9D             EQU  H'0000'
OERR             EQU  H'0001'
FERR             EQU  H'0002'
ADDEN            EQU  H'0003'
CREN             EQU  H'0004'
SREN             EQU  H'0005'
RX9              EQU  H'0006'
SPEN             EQU  H'0007'


;----- TX1STA Bits -----------------------------------------------------
TX9D             EQU  H'0000'
TRMT             EQU  H'0001'
BRGH             EQU  H'0002'
SENDB            EQU  H'0003'
SYNC_TX1STA      EQU  H'0004'
TXEN             EQU  H'0005'
TX9              EQU  H'0006'
CSRC             EQU  H'0007'


;----- TXSTA Bits -----------------------------------------------------
TX9D             EQU  H'0000'
TRMT             EQU  H'0001'
BRGH             EQU  H'0002'
SENDB            EQU  H'0003'
SYNC_TXSTA       EQU  H'0004'
TXEN             EQU  H'0005'
TX9              EQU  H'0006'
CSRC             EQU  H'0007'


;----- TXSTA1 Bits -----------------------------------------------------
TX9D             EQU  H'0000'
TRMT             EQU  H'0001'
BRGH             EQU  H'0002'
SENDB            EQU  H'0003'
SYNC_TXSTA1      EQU  H'0004'
TXEN             EQU  H'0005'
TX9              EQU  H'0006'
CSRC             EQU  H'0007'


;----- BAUD1CON Bits -----------------------------------------------------
ABDEN            EQU  H'0000'
WUE              EQU  H'0001'
BRG16            EQU  H'0003'
SCKP             EQU  H'0004'
RCIDL            EQU  H'0006'
ABDOVF           EQU  H'0007'


;----- BAUDCON Bits -----------------------------------------------------
ABDEN            EQU  H'0000'
WUE              EQU  H'0001'
BRG16            EQU  H'0003'
SCKP             EQU  H'0004'
RCIDL            EQU  H'0006'
ABDOVF           EQU  H'0007'


;----- BAUDCON1 Bits -----------------------------------------------------
ABDEN            EQU  H'0000'
WUE              EQU  H'0001'
BRG16            EQU  H'0003'
SCKP             EQU  H'0004'
RCIDL            EQU  H'0006'
ABDOVF           EQU  H'0007'


;----- BAUDCTL Bits -----------------------------------------------------
ABDEN            EQU  H'0000'
WUE              EQU  H'0001'
BRG16            EQU  H'0003'
SCKP             EQU  H'0004'
RCIDL            EQU  H'0006'
ABDOVF           EQU  H'0007'


;----- BAUDCTL1 Bits -----------------------------------------------------
ABDEN            EQU  H'0000'
WUE              EQU  H'0001'
BRG16            EQU  H'0003'
SCKP             EQU  H'0004'
RCIDL            EQU  H'0006'
ABDOVF           EQU  H'0007'


;----- SSP1MSK Bits -----------------------------------------------------
MSK0             EQU  H'0000'
MSK1             EQU  H'0001'
MSK2             EQU  H'0002'
MSK3             EQU  H'0003'
MSK4             EQU  H'0004'
MSK5             EQU  H'0005'
MSK6             EQU  H'0006'
MSK7             EQU  H'0007'


;----- SSP1STAT Bits -----------------------------------------------------
BF               EQU  H'0000'
UA               EQU  H'0001'
R_NOT_W          EQU  H'0002'
S                EQU  H'0003'
P                EQU  H'0004'
D_NOT_A          EQU  H'0005'
CKE              EQU  H'0006'
SMP              EQU  H'0007'

R_W              EQU  H'0002'
D_A              EQU  H'0005'

NOT_W            EQU  H'0002'
NOT_A            EQU  H'0005'

NOT_WRITE        EQU  H'0002'
NOT_ADDRESS      EQU  H'0005'

READ_WRITE       EQU  H'0002'
DATA_ADDRESS     EQU  H'0005'

I2C_READ         EQU  H'0002'
I2C_START        EQU  H'0003'
I2C_STOP         EQU  H'0004'
I2C_DAT          EQU  H'0005'


;----- SSP1CON1 Bits -----------------------------------------------------
CKP              EQU  H'0004'
SSPEN            EQU  H'0005'
SSPOV            EQU  H'0006'
WCOL             EQU  H'0007'

SSPM0            EQU  H'0000'
SSPM1            EQU  H'0001'
SSPM2            EQU  H'0002'
SSPM3            EQU  H'0003'


;----- SSP1CON2 Bits -----------------------------------------------------
SEN              EQU  H'0000'
RSEN             EQU  H'0001'
PEN              EQU  H'0002'
RCEN             EQU  H'0003'
ACKEN            EQU  H'0004'
ACKDT            EQU  H'0005'
ACKSTAT          EQU  H'0006'
GCEN             EQU  H'0007'


ADMSK1           EQU  H'0001'
ADMSK2           EQU  H'0002'
ADMSK3           EQU  H'0003'
ADMSK4           EQU  H'0004'
ADMSK5           EQU  H'0005'


;----- SSP1CON3 Bits -----------------------------------------------------
DHEN             EQU  H'0000'
AHEN             EQU  H'0001'
SBCDE            EQU  H'0002'
SDAHT            EQU  H'0003'
BOEN             EQU  H'0004'
SCIE             EQU  H'0005'
PCIE             EQU  H'0006'
ACKTIM           EQU  H'0007'


;----- SSP2MSK Bits -----------------------------------------------------
MSK0             EQU  H'0000'
MSK1             EQU  H'0001'
MSK2             EQU  H'0002'
MSK3             EQU  H'0003'
MSK4             EQU  H'0004'
MSK5             EQU  H'0005'
MSK6             EQU  H'0006'
MSK7             EQU  H'0007'


;----- SSP2STAT Bits -----------------------------------------------------
BF               EQU  H'0000'
UA               EQU  H'0001'
R_NOT_W          EQU  H'0002'
S                EQU  H'0003'
P                EQU  H'0004'
D_NOT_A          EQU  H'0005'
CKE              EQU  H'0006'
SMP              EQU  H'0007'

R_W              EQU  H'0002'
D_A              EQU  H'0005'

NOT_W            EQU  H'0002'
NOT_A            EQU  H'0005'

NOT_WRITE        EQU  H'0002'
NOT_ADDRESS      EQU  H'0005'

READ_WRITE       EQU  H'0002'
DATA_ADDRESS     EQU  H'0005'

I2C_READ         EQU  H'0002'
I2C_START        EQU  H'0003'
I2C_STOP         EQU  H'0004'
I2C_DAT          EQU  H'0005'


;----- SSP2CON1 Bits -----------------------------------------------------
CKP              EQU  H'0004'
SSPEN            EQU  H'0005'
SSPOV            EQU  H'0006'
WCOL             EQU  H'0007'

SSPM0            EQU  H'0000'
SSPM1            EQU  H'0001'
SSPM2            EQU  H'0002'
SSPM3            EQU  H'0003'


;----- SSP2CON2 Bits -----------------------------------------------------
SEN              EQU  H'0000'
RSEN             EQU  H'0001'
PEN              EQU  H'0002'
RCEN             EQU  H'0003'
ACKEN            EQU  H'0004'
ACKDT            EQU  H'0005'
ACKSTAT          EQU  H'0006'
GCEN             EQU  H'0007'


ADMSK1           EQU  H'0001'
ADMSK2           EQU  H'0002'
ADMSK3           EQU  H'0003'
ADMSK4           EQU  H'0004'
ADMSK5           EQU  H'0005'


;----- SSP2CON3 Bits -----------------------------------------------------
DHEN             EQU  H'0000'
AHEN             EQU  H'0001'
SBCDE            EQU  H'0002'
SDAHT            EQU  H'0003'
BOEN             EQU  H'0004'
SCIE             EQU  H'0005'
PCIE             EQU  H'0006'
ACKTIM           EQU  H'0007'


;----- TMR1L Bits -----------------------------------------------------
TMR1L0           EQU  H'0000'
TMR1L1           EQU  H'0001'
TMR1L2           EQU  H'0002'
TMR1L3           EQU  H'0003'
TMR1L4           EQU  H'0004'
TMR1L5           EQU  H'0005'
TMR1L6           EQU  H'0006'
TMR1L7           EQU  H'0007'


;----- TMR1H Bits -----------------------------------------------------
TMR1H0           EQU  H'0000'
TMR1H1           EQU  H'0001'
TMR1H2           EQU  H'0002'
TMR1H3           EQU  H'0003'
TMR1H4           EQU  H'0004'
TMR1H5           EQU  H'0005'
TMR1H6           EQU  H'0006'
TMR1H7           EQU  H'0007'


;----- T1CON Bits -----------------------------------------------------
ON_T1CON         EQU  H'0000'
RD16             EQU  H'0001'
NOT_SYNC         EQU  H'0002'

TMR1ON           EQU  H'0000'
T1RD16           EQU  H'0001'
NOT_T1SYNC       EQU  H'0002'
T1CKPS0          EQU  H'0004'
T1CKPS1          EQU  H'0005'

CKPS0_T1CON      EQU  H'0004'
CKPS1_T1CON      EQU  H'0005'


;----- TMR1CON Bits -----------------------------------------------------
ON_TMR1CON       EQU  H'0000'
RD16             EQU  H'0001'
NOT_SYNC         EQU  H'0002'

TMR1ON           EQU  H'0000'
T1RD16           EQU  H'0001'
NOT_T1SYNC       EQU  H'0002'
T1CKPS0          EQU  H'0004'
T1CKPS1          EQU  H'0005'

CKPS0_TMR1CON    EQU  H'0004'
CKPS1_TMR1CON    EQU  H'0005'


;----- T1GCON Bits -----------------------------------------------------
GVAL             EQU  H'0002'
GGO              EQU  H'0003'
GSPM             EQU  H'0004'
GTM              EQU  H'0005'
GPOL_T1GCON      EQU  H'0006'
GE               EQU  H'0007'

T1GVAL           EQU  H'0002'
T1GGO            EQU  H'0003'
T1GSPM           EQU  H'0004'
T1GTM            EQU  H'0005'
T1GPOL           EQU  H'0006'
T1GE             EQU  H'0007'

NOT_DONE         EQU  H'0003'

NOT_T1DONE       EQU  H'0003'


;----- TMR1GCON Bits -----------------------------------------------------
GVAL             EQU  H'0002'
GGO              EQU  H'0003'
GSPM             EQU  H'0004'
GTM              EQU  H'0005'
GPOL_TMR1GCON    EQU  H'0006'
GE               EQU  H'0007'

T1GVAL           EQU  H'0002'
T1GGO            EQU  H'0003'
T1GSPM           EQU  H'0004'
T1GTM            EQU  H'0005'
T1GPOL           EQU  H'0006'
T1GE             EQU  H'0007'

NOT_DONE         EQU  H'0003'

NOT_T1DONE       EQU  H'0003'


;----- T1GATE Bits -----------------------------------------------------
GSS0             EQU  H'0000'
GSS1             EQU  H'0001'
GSS2             EQU  H'0002'
GSS3             EQU  H'0003'
GSS4             EQU  H'0004'

T1GSS0           EQU  H'0000'
T1GSS1           EQU  H'0001'
T1GSS2           EQU  H'0002'
T1GSS3           EQU  H'0003'
T1GSS4           EQU  H'0004'


;----- TMR1GATE Bits -----------------------------------------------------
GSS0             EQU  H'0000'
GSS1             EQU  H'0001'
GSS2             EQU  H'0002'
GSS3             EQU  H'0003'
GSS4             EQU  H'0004'

T1GSS0           EQU  H'0000'
T1GSS1           EQU  H'0001'
T1GSS2           EQU  H'0002'
T1GSS3           EQU  H'0003'
T1GSS4           EQU  H'0004'


;----- T1CLK Bits -----------------------------------------------------
T1CS0            EQU  H'0000'
T1CS1            EQU  H'0001'
T1CS2            EQU  H'0002'
T1CS3            EQU  H'0003'
T1CS4            EQU  H'0004'

CS0_T1CLK        EQU  H'0000'
CS1_T1CLK        EQU  H'0001'
CS2_T1CLK        EQU  H'0002'
CS3              EQU  H'0003'
CS4              EQU  H'0004'


;----- TMR1CLK Bits -----------------------------------------------------
T1CS0            EQU  H'0000'
T1CS1            EQU  H'0001'
T1CS2            EQU  H'0002'
T1CS3            EQU  H'0003'
T1CS4            EQU  H'0004'

CS0_TMR1CLK      EQU  H'0000'
CS1_TMR1CLK      EQU  H'0001'
CS2_TMR1CLK      EQU  H'0002'
CS3              EQU  H'0003'
CS4              EQU  H'0004'


;----- TMR3L Bits -----------------------------------------------------
TMR3L0           EQU  H'0000'
TMR3L1           EQU  H'0001'
TMR3L2           EQU  H'0002'
TMR3L3           EQU  H'0003'
TMR3L4           EQU  H'0004'
TMR3L5           EQU  H'0005'
TMR3L6           EQU  H'0006'
TMR3L7           EQU  H'0007'


;----- TMR3H Bits -----------------------------------------------------
TMR3H0           EQU  H'0000'
TMR3H1           EQU  H'0001'
TMR3H2           EQU  H'0002'
TMR3H3           EQU  H'0003'
TMR3H4           EQU  H'0004'
TMR3H5           EQU  H'0005'
TMR3H6           EQU  H'0006'
TMR3H7           EQU  H'0007'


;----- T3CON Bits -----------------------------------------------------
ON_T3CON         EQU  H'0000'
RD16             EQU  H'0001'
NOT_SYNC         EQU  H'0002'

TMR3ON           EQU  H'0000'
T3RD16           EQU  H'0001'
NOT_T3SYNC       EQU  H'0002'
T3CKPS0          EQU  H'0004'
T3CKPS1          EQU  H'0005'

CKPS0_T3CON      EQU  H'0004'
CKPS1_T3CON      EQU  H'0005'


;----- TMR3CON Bits -----------------------------------------------------
ON_TMR3CON       EQU  H'0000'
RD16             EQU  H'0001'
NOT_SYNC         EQU  H'0002'

TMR3ON           EQU  H'0000'
T3RD16           EQU  H'0001'
NOT_T3SYNC       EQU  H'0002'
T3CKPS0          EQU  H'0004'
T3CKPS1          EQU  H'0005'

CKPS0_TMR3CON    EQU  H'0004'
CKPS1_TMR3CON    EQU  H'0005'


;----- T3GCON Bits -----------------------------------------------------
GVAL             EQU  H'0002'
GGO              EQU  H'0003'
GSPM             EQU  H'0004'
GTM              EQU  H'0005'
GPOL_T3GCON      EQU  H'0006'
GE               EQU  H'0007'

T3GVAL           EQU  H'0002'
T3GGO            EQU  H'0003'
T3GSPM           EQU  H'0004'
T3GTM            EQU  H'0005'
T3GPOL           EQU  H'0006'
T3GE             EQU  H'0007'

NOT_DONE         EQU  H'0003'

NOT_T3DONE       EQU  H'0003'


;----- TMR3GCON Bits -----------------------------------------------------
GVAL             EQU  H'0002'
GGO              EQU  H'0003'
GSPM             EQU  H'0004'
GTM              EQU  H'0005'
GPOL_TMR3GCON    EQU  H'0006'
GE               EQU  H'0007'

T3GVAL           EQU  H'0002'
T3GGO            EQU  H'0003'
T3GSPM           EQU  H'0004'
T3GTM            EQU  H'0005'
T3GPOL           EQU  H'0006'
T3GE             EQU  H'0007'

NOT_DONE         EQU  H'0003'

NOT_T3DONE       EQU  H'0003'


;----- T3GATE Bits -----------------------------------------------------
GSS0             EQU  H'0000'
GSS1             EQU  H'0001'
GSS2             EQU  H'0002'
GSS3             EQU  H'0003'
GSS4             EQU  H'0004'

T3GSS0           EQU  H'0000'
T3GSS1           EQU  H'0001'
T3GSS2           EQU  H'0002'
T3GSS3           EQU  H'0003'
T3GSS4           EQU  H'0004'


;----- TMR3GATE Bits -----------------------------------------------------
GSS0             EQU  H'0000'
GSS1             EQU  H'0001'
GSS2             EQU  H'0002'
GSS3             EQU  H'0003'
GSS4             EQU  H'0004'

T3GSS0           EQU  H'0000'
T3GSS1           EQU  H'0001'
T3GSS2           EQU  H'0002'
T3GSS3           EQU  H'0003'
T3GSS4           EQU  H'0004'


;----- T3CLK Bits -----------------------------------------------------
T3CS0            EQU  H'0000'
T3CS1            EQU  H'0001'
T3CS2            EQU  H'0002'
T3CS3            EQU  H'0003'
T3CS4            EQU  H'0004'

CS0_T3CLK        EQU  H'0000'
CS1_T3CLK        EQU  H'0001'
CS2_T3CLK        EQU  H'0002'
CS3              EQU  H'0003'
CS4              EQU  H'0004'


;----- TMR3CLK Bits -----------------------------------------------------
T3CS0            EQU  H'0000'
T3CS1            EQU  H'0001'
T3CS2            EQU  H'0002'
T3CS3            EQU  H'0003'
T3CS4            EQU  H'0004'

CS0_TMR3CLK      EQU  H'0000'
CS1_TMR3CLK      EQU  H'0001'
CS2_TMR3CLK      EQU  H'0002'
CS3              EQU  H'0003'
CS4              EQU  H'0004'


;----- TMR5L Bits -----------------------------------------------------
TMR5L0           EQU  H'0000'
TMR5L1           EQU  H'0001'
TMR5L2           EQU  H'0002'
TMR5L3           EQU  H'0003'
TMR5L4           EQU  H'0004'
TMR5L5           EQU  H'0005'
TMR5L6           EQU  H'0006'
TMR5L7           EQU  H'0007'


;----- TMR5H Bits -----------------------------------------------------
TMR5H0           EQU  H'0000'
TMR5H1           EQU  H'0001'
TMR5H2           EQU  H'0002'
TMR5H3           EQU  H'0003'
TMR5H4           EQU  H'0004'
TMR5H5           EQU  H'0005'
TMR5H6           EQU  H'0006'
TMR5H7           EQU  H'0007'


;----- T5CON Bits -----------------------------------------------------
ON_T5CON         EQU  H'0000'
RD16             EQU  H'0001'
NOT_SYNC         EQU  H'0002'

TMR5ON           EQU  H'0000'
T5RD16           EQU  H'0001'
NOT_T5SYNC       EQU  H'0002'
T5CKPS0          EQU  H'0004'
T5CKPS1          EQU  H'0005'

CKPS0_T5CON      EQU  H'0004'
CKPS1_T5CON      EQU  H'0005'


;----- TMR5CON Bits -----------------------------------------------------
ON_TMR5CON       EQU  H'0000'
RD16             EQU  H'0001'
NOT_SYNC         EQU  H'0002'

TMR5ON           EQU  H'0000'
T5RD16           EQU  H'0001'
NOT_T5SYNC       EQU  H'0002'
T5CKPS0          EQU  H'0004'
T5CKPS1          EQU  H'0005'

CKPS0_TMR5CON    EQU  H'0004'
CKPS1_TMR5CON    EQU  H'0005'


;----- T5GCON Bits -----------------------------------------------------
GVAL             EQU  H'0002'
GGO              EQU  H'0003'
GSPM             EQU  H'0004'
GTM              EQU  H'0005'
GPOL_T5GCON      EQU  H'0006'
GE               EQU  H'0007'

T5GVAL           EQU  H'0002'
T5GGO            EQU  H'0003'
T5GSPM           EQU  H'0004'
T5GTM            EQU  H'0005'
T5GPOL           EQU  H'0006'
T5GE             EQU  H'0007'

NOT_DONE         EQU  H'0003'

NOT_T5DONE       EQU  H'0003'


;----- TMR5GCON Bits -----------------------------------------------------
GVAL             EQU  H'0002'
GGO              EQU  H'0003'
GSPM             EQU  H'0004'
GTM              EQU  H'0005'
GPOL_TMR5GCON    EQU  H'0006'
GE               EQU  H'0007'

T5GVAL           EQU  H'0002'
T5GGO            EQU  H'0003'
T5GSPM           EQU  H'0004'
T5GTM            EQU  H'0005'
T5GPOL           EQU  H'0006'
T5GE             EQU  H'0007'

NOT_DONE         EQU  H'0003'

NOT_T5DONE       EQU  H'0003'


;----- T5GATE Bits -----------------------------------------------------
GSS0             EQU  H'0000'
GSS1             EQU  H'0001'
GSS2             EQU  H'0002'
GSS3             EQU  H'0003'
GSS4             EQU  H'0004'

T5GSS0           EQU  H'0000'
T5GSS1           EQU  H'0001'
T5GSS2           EQU  H'0002'
T5GSS3           EQU  H'0003'
T5GSS4           EQU  H'0004'


;----- TMR5GATE Bits -----------------------------------------------------
GSS0             EQU  H'0000'
GSS1             EQU  H'0001'
GSS2             EQU  H'0002'
GSS3             EQU  H'0003'
GSS4             EQU  H'0004'

T5GSS0           EQU  H'0000'
T5GSS1           EQU  H'0001'
T5GSS2           EQU  H'0002'
T5GSS3           EQU  H'0003'
T5GSS4           EQU  H'0004'


;----- T5CLK Bits -----------------------------------------------------
T5CS0            EQU  H'0000'
T5CS1            EQU  H'0001'
T5CS2            EQU  H'0002'
T5CS3            EQU  H'0003'
T5CS4            EQU  H'0004'

CS0_T5CLK        EQU  H'0000'
CS1_T5CLK        EQU  H'0001'
CS2_T5CLK        EQU  H'0002'
CS3              EQU  H'0003'
CS4              EQU  H'0004'


;----- TMR5CLK Bits -----------------------------------------------------
T5CS0            EQU  H'0000'
T5CS1            EQU  H'0001'
T5CS2            EQU  H'0002'
T5CS3            EQU  H'0003'
T5CS4            EQU  H'0004'

CS0_TMR5CLK      EQU  H'0000'
CS1_TMR5CLK      EQU  H'0001'
CS2_TMR5CLK      EQU  H'0002'
CS3              EQU  H'0003'
CS4              EQU  H'0004'


;----- T2CON Bits -----------------------------------------------------
ON_T2CON         EQU  H'0007'

OUTPS0           EQU  H'0000'
OUTPS1           EQU  H'0001'
OUTPS2           EQU  H'0002'
OUTPS3           EQU  H'0003'
CKPS0_T2CON      EQU  H'0004'
CKPS1_T2CON      EQU  H'0005'
CKPS2_T2CON      EQU  H'0006'

T2ON             EQU  H'0007'

T2OUTPS0         EQU  H'0000'
T2OUTPS1         EQU  H'0001'
T2OUTPS2         EQU  H'0002'
T2OUTPS3         EQU  H'0003'
T2CKPS0          EQU  H'0004'
T2CKPS1          EQU  H'0005'
T2CKPS2          EQU  H'0006'
TMR2ON           EQU  H'0007'


;----- T2HLT Bits -----------------------------------------------------
CKSYNC           EQU  H'0005'
CKPOL            EQU  H'0006'
PSYNC            EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'
MODE3            EQU  H'0003'
MODE4            EQU  H'0004'

T2CKSYNC         EQU  H'0005'
T2CKPOL          EQU  H'0006'
T2PSYNC          EQU  H'0007'

T2MODE0          EQU  H'0000'
T2MODE1          EQU  H'0001'
T2MODE2          EQU  H'0002'
T2MODE3          EQU  H'0003'
T2MODE4          EQU  H'0004'


;----- T2CLKCON Bits -----------------------------------------------------
CS0_T2CLKCON     EQU  H'0000'
CS1_T2CLKCON     EQU  H'0001'
CS2_T2CLKCON     EQU  H'0002'
CS3              EQU  H'0003'


T2CS0            EQU  H'0000'
T2CS1            EQU  H'0001'
T2CS2            EQU  H'0002'
T2CS3            EQU  H'0003'


;----- T2RST Bits -----------------------------------------------------
RSEL0            EQU  H'0000'
RSEL1            EQU  H'0001'
RSEL2            EQU  H'0002'
RSEL3            EQU  H'0003'
RSEL4            EQU  H'0004'


T2RSEL0          EQU  H'0000'
T2RSEL1          EQU  H'0001'
T2RSEL2          EQU  H'0002'
T2RSEL3          EQU  H'0003'
T2RSEL4          EQU  H'0004'


;----- T4CON Bits -----------------------------------------------------
ON_T4CON         EQU  H'0007'

OUTPS0           EQU  H'0000'
OUTPS1           EQU  H'0001'
OUTPS2           EQU  H'0002'
OUTPS3           EQU  H'0003'
CKPS0_T4CON      EQU  H'0004'
CKPS1_T4CON      EQU  H'0005'
CKPS2_T4CON      EQU  H'0006'

T4ON             EQU  H'0007'

T4OUTPS0         EQU  H'0000'
T4OUTPS1         EQU  H'0001'
T4OUTPS2         EQU  H'0002'
T4OUTPS3         EQU  H'0003'
T4CKPS0          EQU  H'0004'
T4CKPS1          EQU  H'0005'
T4CKPS2          EQU  H'0006'
TMR4ON           EQU  H'0007'


;----- T4HLT Bits -----------------------------------------------------
CKSYNC           EQU  H'0005'
CKPOL            EQU  H'0006'
PSYNC            EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'
MODE3            EQU  H'0003'
MODE4            EQU  H'0004'

T4CKSYNC         EQU  H'0005'
T4CKPOL          EQU  H'0006'
T4PSYNC          EQU  H'0007'

T4MODE0          EQU  H'0000'
T4MODE1          EQU  H'0001'
T4MODE2          EQU  H'0002'
T4MODE3          EQU  H'0003'
T4MODE4          EQU  H'0004'


;----- T4CLKCON Bits -----------------------------------------------------
CS0_T4CLKCON     EQU  H'0000'
CS1_T4CLKCON     EQU  H'0001'
CS2_T4CLKCON     EQU  H'0002'
CS3              EQU  H'0003'


T4CS0            EQU  H'0000'
T4CS1            EQU  H'0001'
T4CS2            EQU  H'0002'
T4CS3            EQU  H'0003'


;----- T4RST Bits -----------------------------------------------------
RSEL0            EQU  H'0000'
RSEL1            EQU  H'0001'
RSEL2            EQU  H'0002'
RSEL3            EQU  H'0003'
RSEL4            EQU  H'0004'


T4RSEL0          EQU  H'0000'
T4RSEL1          EQU  H'0001'
T4RSEL2          EQU  H'0002'
T4RSEL3          EQU  H'0003'
T4RSEL4          EQU  H'0004'


;----- T6CON Bits -----------------------------------------------------
ON_T6CON         EQU  H'0007'

OUTPS0           EQU  H'0000'
OUTPS1           EQU  H'0001'
OUTPS2           EQU  H'0002'
OUTPS3           EQU  H'0003'
CKPS0_T6CON      EQU  H'0004'
CKPS1_T6CON      EQU  H'0005'
CKPS2_T6CON      EQU  H'0006'

T6ON             EQU  H'0007'

T6OUTPS0         EQU  H'0000'
T6OUTPS1         EQU  H'0001'
T6OUTPS2         EQU  H'0002'
T6OUTPS3         EQU  H'0003'
T6CKPS0          EQU  H'0004'
T6CKPS1          EQU  H'0005'
T6CKPS2          EQU  H'0006'
TMR6ON           EQU  H'0007'


;----- T6HLT Bits -----------------------------------------------------
CKSYNC           EQU  H'0005'
CKPOL            EQU  H'0006'
PSYNC            EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'
MODE3            EQU  H'0003'
MODE4            EQU  H'0004'

T6CKSYNC         EQU  H'0005'
T6CKPOL          EQU  H'0006'
T6PSYNC          EQU  H'0007'

T6MODE0          EQU  H'0000'
T6MODE1          EQU  H'0001'
T6MODE2          EQU  H'0002'
T6MODE3          EQU  H'0003'
T6MODE4          EQU  H'0004'


;----- T6CLKCON Bits -----------------------------------------------------
CS0_T6CLKCON     EQU  H'0000'
CS1_T6CLKCON     EQU  H'0001'
CS2_T6CLKCON     EQU  H'0002'
CS3              EQU  H'0003'


T6CS0            EQU  H'0000'
T6CS1            EQU  H'0001'
T6CS2            EQU  H'0002'
T6CS3            EQU  H'0003'


;----- T6RST Bits -----------------------------------------------------
RSEL0            EQU  H'0000'
RSEL1            EQU  H'0001'
RSEL2            EQU  H'0002'
RSEL3            EQU  H'0003'
RSEL4            EQU  H'0004'


T6RSEL0          EQU  H'0000'
T6RSEL1          EQU  H'0001'
T6RSEL2          EQU  H'0002'
T6RSEL3          EQU  H'0003'
T6RSEL4          EQU  H'0004'


;----- ADCPCON0 Bits -----------------------------------------------------
CPRDY            EQU  H'0000'
CPON             EQU  H'0007'


;----- CCP1CON Bits -----------------------------------------------------
FMT              EQU  H'0004'
OUT_CCP1CON      EQU  H'0005'
EN               EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'
MODE3            EQU  H'0003'

CCP1FMT          EQU  H'0004'
CCP1OUT          EQU  H'0005'
CCP1EN           EQU  H'0007'

CCP1MODE0        EQU  H'0000'
CCP1MODE1        EQU  H'0001'
CCP1MODE2        EQU  H'0002'
CCP1MODE3        EQU  H'0003'


;----- CCP1CAP Bits -----------------------------------------------------
CTS0             EQU  H'0000'
CTS1             EQU  H'0001'
CTS2             EQU  H'0002'


CCP1CTS0         EQU  H'0000'
CCP1CTS1         EQU  H'0001'
CCP1CTS2         EQU  H'0002'


;----- CCP2CON Bits -----------------------------------------------------
FMT              EQU  H'0004'
OUT_CCP2CON      EQU  H'0005'
EN               EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'
MODE3            EQU  H'0003'

CCP2FMT          EQU  H'0004'
CCP2OUT          EQU  H'0005'
CCP2EN           EQU  H'0007'

CCP2MODE0        EQU  H'0000'
CCP2MODE1        EQU  H'0001'
CCP2MODE2        EQU  H'0002'
CCP2MODE3        EQU  H'0003'


;----- CCP2CAP Bits -----------------------------------------------------
CTS0             EQU  H'0000'
CTS1             EQU  H'0001'
CTS2             EQU  H'0002'


CCP2CTS0         EQU  H'0000'
CCP2CTS1         EQU  H'0001'
CCP2CTS2         EQU  H'0002'


;----- CCP3CON Bits -----------------------------------------------------
FMT              EQU  H'0004'
OUT_CCP3CON      EQU  H'0005'
EN               EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'
MODE3            EQU  H'0003'

CCP3FMT          EQU  H'0004'
CCP3OUT          EQU  H'0005'
CCP3EN           EQU  H'0007'

CCP3MODE0        EQU  H'0000'
CCP3MODE1        EQU  H'0001'
CCP3MODE2        EQU  H'0002'
CCP3MODE3        EQU  H'0003'


;----- CCP3CAP Bits -----------------------------------------------------
CTS0             EQU  H'0000'
CTS1             EQU  H'0001'
CTS2             EQU  H'0002'


CCP3CTS0         EQU  H'0000'
CCP3CTS1         EQU  H'0001'
CCP3CTS2         EQU  H'0002'


;----- CCP4CON Bits -----------------------------------------------------
FMT              EQU  H'0004'
OUT_CCP4CON      EQU  H'0005'
EN               EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'
MODE3            EQU  H'0003'

CCP4FMT          EQU  H'0004'
CCP4OUT          EQU  H'0005'
CCP4EN           EQU  H'0007'

CCP4MODE0        EQU  H'0000'
CCP4MODE1        EQU  H'0001'
CCP4MODE2        EQU  H'0002'
CCP4MODE3        EQU  H'0003'


;----- CCP4CAP Bits -----------------------------------------------------
CTS0             EQU  H'0000'
CTS1             EQU  H'0001'
CTS2             EQU  H'0002'


CCP4CTS0         EQU  H'0000'
CCP4CTS1         EQU  H'0001'
CCP4CTS2         EQU  H'0002'


;----- PWM6DCL Bits -----------------------------------------------------
DC0              EQU  H'0006'
DC1              EQU  H'0007'

PWM6DC0          EQU  H'0006'
PWM6DC1          EQU  H'0007'

PWMPW0           EQU  H'0006'
PWMPW1           EQU  H'0007'


;----- PWM6DCH Bits -----------------------------------------------------
DC2              EQU  H'0000'
DC3              EQU  H'0001'
DC4              EQU  H'0002'
DC5              EQU  H'0003'
DC6              EQU  H'0004'
DC7              EQU  H'0005'
DC8              EQU  H'0006'
DC9              EQU  H'0007'

PWM6DC2          EQU  H'0000'
PWM6DC3          EQU  H'0001'
PWM6DC4          EQU  H'0002'
PWM6DC5          EQU  H'0003'
PWM6DC6          EQU  H'0004'
PWM6DC7          EQU  H'0005'
PWM6DC8          EQU  H'0006'
PWM6DC9          EQU  H'0007'

PWMPW2           EQU  H'0000'
PWMPW3           EQU  H'0001'
PWMPW4           EQU  H'0002'
PWMPW5           EQU  H'0003'
PWMPW6           EQU  H'0004'
PWMPW7           EQU  H'0005'
PWMPW8           EQU  H'0006'
PWMPW9           EQU  H'0007'


;----- PWM6CON Bits -----------------------------------------------------
POL_PWM6CON      EQU  H'0004'
OUT_PWM6CON      EQU  H'0005'
EN               EQU  H'0007'

PWM6POL          EQU  H'0004'
PWM6OUT          EQU  H'0005'
PWM6EN           EQU  H'0007'


;----- PWM7DCL Bits -----------------------------------------------------
DC0              EQU  H'0006'
DC1              EQU  H'0007'

PWM7DC0          EQU  H'0006'
PWM7DC1          EQU  H'0007'

PWMPW0           EQU  H'0006'
PWMPW1           EQU  H'0007'


;----- PWM7DCH Bits -----------------------------------------------------
DC2              EQU  H'0000'
DC3              EQU  H'0001'
DC4              EQU  H'0002'
DC5              EQU  H'0003'
DC6              EQU  H'0004'
DC7              EQU  H'0005'
DC8              EQU  H'0006'
DC9              EQU  H'0007'

PWM7DC2          EQU  H'0000'
PWM7DC3          EQU  H'0001'
PWM7DC4          EQU  H'0002'
PWM7DC5          EQU  H'0003'
PWM7DC6          EQU  H'0004'
PWM7DC7          EQU  H'0005'
PWM7DC8          EQU  H'0006'
PWM7DC9          EQU  H'0007'

PWMPW2           EQU  H'0000'
PWMPW3           EQU  H'0001'
PWMPW4           EQU  H'0002'
PWMPW5           EQU  H'0003'
PWMPW6           EQU  H'0004'
PWMPW7           EQU  H'0005'
PWMPW8           EQU  H'0006'
PWMPW9           EQU  H'0007'


;----- PWM7CON Bits -----------------------------------------------------
POL_PWM7CON      EQU  H'0004'
OUT_PWM7CON      EQU  H'0005'
EN               EQU  H'0007'

PWM7POL          EQU  H'0004'
PWM7OUT          EQU  H'0005'
PWM7EN           EQU  H'0007'


;----- SMT1TMRL Bits -----------------------------------------------------
;TMR0             EQU  H'0000'
TMR1             EQU  H'0001'
;TMR2             EQU  H'0002'
TMR3             EQU  H'0003'
;TMR4             EQU  H'0004'
TMR5             EQU  H'0005'
;TMR6             EQU  H'0006'
TMR7             EQU  H'0007'


SMT1TMR0         EQU  H'0000'
SMT1TMR1         EQU  H'0001'
SMT1TMR2         EQU  H'0002'
SMT1TMR3         EQU  H'0003'
SMT1TMR4         EQU  H'0004'
SMT1TMR5         EQU  H'0005'
SMT1TMR6         EQU  H'0006'
SMT1TMR7         EQU  H'0007'


;----- SMT1TMRH Bits -----------------------------------------------------
TMR8             EQU  H'0000'
TMR9             EQU  H'0001'
TMR10            EQU  H'0002'
TMR11            EQU  H'0003'
TMR12            EQU  H'0004'
TMR13            EQU  H'0005'
TMR14            EQU  H'0006'
TMR15            EQU  H'0007'


SMT1TMR8         EQU  H'0000'
SMT1TMR9         EQU  H'0001'
SMT1TMR10        EQU  H'0002'
SMT1TMR11        EQU  H'0003'
SMT1TMR12        EQU  H'0004'
SMT1TMR13        EQU  H'0005'
SMT1TMR14        EQU  H'0006'
SMT1TMR15        EQU  H'0007'


;----- SMT1TMRU Bits -----------------------------------------------------
TMR16            EQU  H'0000'
TMR17            EQU  H'0001'
TMR18            EQU  H'0002'
TMR19            EQU  H'0003'
TMR20            EQU  H'0004'
TMR21            EQU  H'0005'
TMR22            EQU  H'0006'
TMR23            EQU  H'0007'


SMT1TMR16        EQU  H'0000'
SMT1TMR17        EQU  H'0001'
SMT1TMR18        EQU  H'0002'
SMT1TMR19        EQU  H'0003'
SMT1TMR20        EQU  H'0004'
SMT1TMR21        EQU  H'0005'
SMT1TMR22        EQU  H'0006'
SMT1TMR23        EQU  H'0007'


;----- SMT1CPRL Bits -----------------------------------------------------
CPR0             EQU  H'0000'
CPR1             EQU  H'0001'
CPR2             EQU  H'0002'
CPR3             EQU  H'0003'
CPR4             EQU  H'0004'
CPR5             EQU  H'0005'
CPR6             EQU  H'0006'
CPR7             EQU  H'0007'


SMT1CPR0         EQU  H'0000'
SMT1CPR1         EQU  H'0001'
SMT1CPR2         EQU  H'0002'
SMT1CPR3         EQU  H'0003'
SMT1CPR4         EQU  H'0004'
SMT1CPR5         EQU  H'0005'
SMT1CPR6         EQU  H'0006'
SMT1CPR7         EQU  H'0007'


;----- SMT1CPRH Bits -----------------------------------------------------
CPR8             EQU  H'0000'
CPR9             EQU  H'0001'
CPR10            EQU  H'0002'
CPR11            EQU  H'0003'
CPR12            EQU  H'0004'
CPR13            EQU  H'0005'
CPR14            EQU  H'0006'
CPR15            EQU  H'0007'

SMT1CPR8         EQU  H'0000'
SMT1CPR9         EQU  H'0001'
SMT1CPR10        EQU  H'0002'
SMT1CPR11        EQU  H'0003'
SMT1CPR12        EQU  H'0004'
SMT1CPR13        EQU  H'0005'
SMT1CPR14        EQU  H'0006'
SMT1CPR15        EQU  H'0007'



;----- SMT1CPRU Bits -----------------------------------------------------
CPR16            EQU  H'0000'
CPR17            EQU  H'0001'
CPR18            EQU  H'0002'
CPR19            EQU  H'0003'
CPR20            EQU  H'0004'
CPR21            EQU  H'0005'
CPR22            EQU  H'0006'
CPR23            EQU  H'0007'

SMT1CPR16        EQU  H'0000'
SMT1CPR17        EQU  H'0001'
SMT1CPR18        EQU  H'0002'
SMT1CPR19        EQU  H'0003'
SMT1CPR20        EQU  H'0004'
SMT1CPR21        EQU  H'0005'
SMT1CPR22        EQU  H'0006'
SMT1CPR23        EQU  H'0007'



;----- SMT1CPWL Bits -----------------------------------------------------
CPW0             EQU  H'0000'
CPW1             EQU  H'0001'
CPW2             EQU  H'0002'
CPW3             EQU  H'0003'
CPW4             EQU  H'0004'
CPW5             EQU  H'0005'
CPW6             EQU  H'0006'
CPW7             EQU  H'0007'


SMT1CPW0         EQU  H'0000'
SMT1CPW1         EQU  H'0001'
SMT1CPW2         EQU  H'0002'
SMT1CPW3         EQU  H'0003'
SMT1CPW4         EQU  H'0004'
SMT1CPW5         EQU  H'0005'
SMT1CPW6         EQU  H'0006'
SMT1CPW7         EQU  H'0007'


;----- SMT1CPWH Bits -----------------------------------------------------
CPW8             EQU  H'0000'
CPW9             EQU  H'0001'
CPW10            EQU  H'0002'
CPW11            EQU  H'0003'
CPW12            EQU  H'0004'
CPW13            EQU  H'0005'
CPW14            EQU  H'0006'
CPW15            EQU  H'0007'


SMT1CPW8         EQU  H'0000'
SMT1CPW9         EQU  H'0001'
SMT1CPW10        EQU  H'0002'
SMT1CPW11        EQU  H'0003'
SMT1CPW12        EQU  H'0004'
SMT1CPW13        EQU  H'0005'
SMT1CPW14        EQU  H'0006'
SMT1CPW15        EQU  H'0007'


;----- SMT1CPWU Bits -----------------------------------------------------
CPW16            EQU  H'0000'
CPW17            EQU  H'0001'
CPW18            EQU  H'0002'
CPW19            EQU  H'0003'
CPW20            EQU  H'0004'
CPW21            EQU  H'0005'
CPW22            EQU  H'0006'
CPW23            EQU  H'0007'


SMT1CPW16        EQU  H'0000'
SMT1CPW17        EQU  H'0001'
SMT1CPW18        EQU  H'0002'
SMT1CPW19        EQU  H'0003'
SMT1CPW20        EQU  H'0004'
SMT1CPW21        EQU  H'0005'
SMT1CPW22        EQU  H'0006'
SMT1CPW23        EQU  H'0007'


;----- SMT1PRL Bits -----------------------------------------------------
;PR0              EQU  H'0000'
PR1              EQU  H'0001'
;PR2              EQU  H'0002'
PR3              EQU  H'0003'
;PR4              EQU  H'0004'
PR5              EQU  H'0005'
;PR6              EQU  H'0006'
PR7              EQU  H'0007'


SMT1PR0          EQU  H'0000'
SMT1PR1          EQU  H'0001'
SMT1PR2          EQU  H'0002'
SMT1PR3          EQU  H'0003'
SMT1PR4          EQU  H'0004'
SMT1PR5          EQU  H'0005'
SMT1PR6          EQU  H'0006'
SMT1PR7          EQU  H'0007'


;----- SMT1PRH Bits -----------------------------------------------------
PR8              EQU  H'0000'
PR9              EQU  H'0001'
PR10             EQU  H'0002'
PR11             EQU  H'0003'
PR12             EQU  H'0004'
PR13             EQU  H'0005'
PR14             EQU  H'0006'
PR15             EQU  H'0007'


SMT1PR8          EQU  H'0000'
SMT1PR9          EQU  H'0001'
SMT1PR10         EQU  H'0002'
SMT1PR11         EQU  H'0003'
SMT1PR12         EQU  H'0004'
SMT1PR13         EQU  H'0005'
SMT1PR14         EQU  H'0006'
SMT1PR15         EQU  H'0007'


;----- SMT1PRU Bits -----------------------------------------------------
PR16             EQU  H'0000'
PR17             EQU  H'0001'
PR18             EQU  H'0002'
PR19             EQU  H'0003'
PR20             EQU  H'0004'
PR21             EQU  H'0005'
PR22             EQU  H'0006'
PR23             EQU  H'0007'


SMT1PR16         EQU  H'0000'
SMT1PR17         EQU  H'0001'
SMT1PR18         EQU  H'0002'
SMT1PR19         EQU  H'0003'
SMT1PR20         EQU  H'0004'
SMT1PR21         EQU  H'0005'
SMT1PR22         EQU  H'0006'
SMT1PR23         EQU  H'0007'


;----- SMT1CON0 Bits -----------------------------------------------------
CPOL             EQU  H'0002'
SPOL             EQU  H'0003'
WPOL             EQU  H'0004'
STP              EQU  H'0005'
EN               EQU  H'0007'

SMT1CPOL         EQU  H'0002'
SMT1SPOL         EQU  H'0003'
SMT1WOL          EQU  H'0004'
SMT1STP          EQU  H'0005'
SMT1EN           EQU  H'0007'

PS0              EQU  H'0000'
PS1              EQU  H'0001'

SMT1PS0          EQU  H'0000'
SMT1PS1          EQU  H'0001'


;----- SMT1CON1 Bits -----------------------------------------------------
REPEAT           EQU  H'0006'
GO_SMT1CON1      EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'
MODE3            EQU  H'0003'
SMT1REPEAT       EQU  H'0006'
SMT1GO           EQU  H'0007'



;----- SMT1STAT Bits -----------------------------------------------------
AS               EQU  H'0000'
WS               EQU  H'0001'
TS               EQU  H'0002'
RST              EQU  H'0005'
CPWUP            EQU  H'0006'
CPRUP            EQU  H'0007'

SMT1AS           EQU  H'0000'
SMT1WS           EQU  H'0001'
SMT1TS           EQU  H'0002'
SMT1RESET        EQU  H'0005'
SMT1CPWUP        EQU  H'0006'
SMT1CPRUP        EQU  H'0007'

SMT1RST          EQU  H'0005'


;----- SMT1CLK Bits -----------------------------------------------------
CSEL0            EQU  H'0000'
CSEL1            EQU  H'0001'
CSEL2            EQU  H'0002'


SMT1CSEL0        EQU  H'0000'
SMT1CSEL1        EQU  H'0001'
SMT1CSEL2        EQU  H'0002'


;----- SMT1SIG Bits -----------------------------------------------------
SSEL0            EQU  H'0000'
SSEL1            EQU  H'0001'
SSEL2            EQU  H'0002'
SSEL3            EQU  H'0003'
SSEL4            EQU  H'0004'


SMT1SSEL0        EQU  H'0000'
SMT1SSEL1        EQU  H'0001'
SMT1SSEL2        EQU  H'0002'
SMT1SSEL3        EQU  H'0003'
SMT1SSEL4        EQU  H'0004'


;----- SMT1WIN Bits -----------------------------------------------------
WSEL0            EQU  H'0000'
WSEL1            EQU  H'0001'
WSEL2            EQU  H'0002'
WSEL3            EQU  H'0003'
WSEL4            EQU  H'0004'


SMT1WSEL0        EQU  H'0000'
SMT1WSEL1        EQU  H'0001'
SMT1WSEL2        EQU  H'0002'
SMT1WSEL3        EQU  H'0003'
SMT1WSEL4        EQU  H'0004'


;----- NCO1ACCL Bits -----------------------------------------------------
NCO1ACC0         EQU  H'0000'
NCO1ACC1         EQU  H'0001'
NCO1ACC2         EQU  H'0002'
NCO1ACC3         EQU  H'0003'
NCO1ACC4         EQU  H'0004'
NCO1ACC5         EQU  H'0005'
NCO1ACC6         EQU  H'0006'
NCO1ACC7         EQU  H'0007'

ACC0             EQU  H'0000'
ACC1             EQU  H'0001'
ACC2             EQU  H'0002'
ACC3             EQU  H'0003'
ACC4             EQU  H'0004'
ACC5             EQU  H'0005'
ACC6             EQU  H'0006'
ACC7             EQU  H'0007'



;----- NCO1ACCH Bits -----------------------------------------------------
NCO1ACC8         EQU  H'0000'
NCO1ACC9         EQU  H'0001'
NCO1ACC10        EQU  H'0002'
NCO1ACC11        EQU  H'0003'
NCO1ACC12        EQU  H'0004'
NCO1ACC13        EQU  H'0005'
NCO1ACC14        EQU  H'0006'
NCO1ACC15        EQU  H'0007'

ACC8             EQU  H'0000'
ACC9             EQU  H'0001'
ACC10            EQU  H'0002'
ACC11            EQU  H'0003'
ACC12            EQU  H'0004'
ACC13            EQU  H'0005'
ACC14            EQU  H'0006'
ACC15            EQU  H'0007'



;----- NCO1ACCU Bits -----------------------------------------------------
NCO1ACC16        EQU  H'0000'
NCO1ACC17        EQU  H'0001'
NCO1ACC18        EQU  H'0002'
NCO1ACC19        EQU  H'0003'

ACC16            EQU  H'0000'
ACC17            EQU  H'0001'
ACC18            EQU  H'0002'
ACC19            EQU  H'0003'



;----- NCO1INCL Bits -----------------------------------------------------
NCO1INC0         EQU  H'0000'
NCO1INC1         EQU  H'0001'
NCO1INC2         EQU  H'0002'
NCO1INC3         EQU  H'0003'
NCO1INC4         EQU  H'0004'
NCO1INC5         EQU  H'0005'
NCO1INC6         EQU  H'0006'
NCO1INC7         EQU  H'0007'

INC0             EQU  H'0000'
INC1             EQU  H'0001'
INC2             EQU  H'0002'
INC3             EQU  H'0003'
INC4             EQU  H'0004'
INC5             EQU  H'0005'
INC6             EQU  H'0006'
INC7             EQU  H'0007'



;----- NCO1INCH Bits -----------------------------------------------------
NCO1INC8         EQU  H'0000'
NCO1INC9         EQU  H'0001'
NCO1INC10        EQU  H'0002'
NCO1INC11        EQU  H'0003'
NCO1INC12        EQU  H'0004'
NCO1INC13        EQU  H'0005'
NCO1INC14        EQU  H'0006'
NCO1INC15        EQU  H'0007'

INC8             EQU  H'0000'
INC9             EQU  H'0001'
INC10            EQU  H'0002'
INC11            EQU  H'0003'
INC12            EQU  H'0004'
INC13            EQU  H'0005'
INC14            EQU  H'0006'
INC15            EQU  H'0007'



;----- NCO1INCU Bits -----------------------------------------------------
NCO1INC16        EQU  H'0000'
NCO1INC17        EQU  H'0001'
NCO1INC18        EQU  H'0002'
NCO1INC19        EQU  H'0003'

INC16            EQU  H'0000'
INC17            EQU  H'0001'
INC18            EQU  H'0002'
INC19            EQU  H'0003'



;----- NCO1CON Bits -----------------------------------------------------
PFM              EQU  H'0000'
POL_NCO1CON      EQU  H'0004'
OUT_NCO1CON      EQU  H'0005'
EN               EQU  H'0007'

NCO1PFM          EQU  H'0000'
NCO1POL          EQU  H'0004'
NCO1OUT          EQU  H'0005'
NCO1EN           EQU  H'0007'


;----- NCO1CLK Bits -----------------------------------------------------
CKS0             EQU  H'0000'
CKS1             EQU  H'0001'
CKS2             EQU  H'0002'
CKS3             EQU  H'0003'
PWS0             EQU  H'0005'
PWS1             EQU  H'0006'
PWS2             EQU  H'0007'


NCO1CKS0         EQU  H'0000'
NCO1CKS1         EQU  H'0001'
NCO1CKS2         EQU  H'0002'
NCO1CKS3         EQU  H'0003'
NCO1PWS0         EQU  H'0005'
NCO1PWS1         EQU  H'0006'
NCO1PWS2         EQU  H'0007'


;----- TMR0 Bits -----------------------------------------------------
TMR0L0           EQU  H'0000'
TMR0L1           EQU  H'0001'
TMR0L2           EQU  H'0002'
TMR0L3           EQU  H'0003'
TMR0L4           EQU  H'0004'
TMR0L5           EQU  H'0005'
TMR0L6           EQU  H'0006'
TMR0L7           EQU  H'0007'


;----- TMR0L Bits -----------------------------------------------------
TMR0L0           EQU  H'0000'
TMR0L1           EQU  H'0001'
TMR0L2           EQU  H'0002'
TMR0L3           EQU  H'0003'
TMR0L4           EQU  H'0004'
TMR0L5           EQU  H'0005'
TMR0L6           EQU  H'0006'
TMR0L7           EQU  H'0007'


;----- PR0 Bits -----------------------------------------------------
TMR0H0           EQU  H'0000'
TMR0H1           EQU  H'0001'
TMR0H2           EQU  H'0002'
TMR0H3           EQU  H'0003'
TMR0H4           EQU  H'0004'
TMR0H5           EQU  H'0005'
TMR0H6           EQU  H'0006'
TMR0H7           EQU  H'0007'

T0PR0            EQU  H'0000'
T0PR1            EQU  H'0001'
T0PR2            EQU  H'0002'
T0PR3            EQU  H'0003'
T0PR4            EQU  H'0004'
T0PR5            EQU  H'0005'
T0PR6            EQU  H'0006'
T0PR7            EQU  H'0007'



;----- TMR0H Bits -----------------------------------------------------
TMR0H0           EQU  H'0000'
TMR0H1           EQU  H'0001'
TMR0H2           EQU  H'0002'
TMR0H3           EQU  H'0003'
TMR0H4           EQU  H'0004'
TMR0H5           EQU  H'0005'
TMR0H6           EQU  H'0006'
TMR0H7           EQU  H'0007'

T0PR0            EQU  H'0000'
T0PR1            EQU  H'0001'
T0PR2            EQU  H'0002'
T0PR3            EQU  H'0003'
T0PR4            EQU  H'0004'
T0PR5            EQU  H'0005'
T0PR6            EQU  H'0006'
T0PR7            EQU  H'0007'



;----- T0CON0 Bits -----------------------------------------------------
MD16             EQU  H'0004'
OUT_T0CON0       EQU  H'0005'
EN               EQU  H'0007'

T0MD16           EQU  H'0004'
T0OUT            EQU  H'0005'
T0EN             EQU  H'0007'

OUTPS0           EQU  H'0000'
OUTPS1           EQU  H'0001'
OUTPS2           EQU  H'0002'
OUTPS3           EQU  H'0003'
T016BIT          EQU  H'0004'


;----- T0CON1 Bits -----------------------------------------------------
ASYNC            EQU  H'0004'

CKPS0_T0CON1     EQU  H'0000'
CKPS1_T0CON1     EQU  H'0001'
CKPS2_T0CON1     EQU  H'0002'
CKPS3            EQU  H'0003'
T0ASYNC          EQU  H'0004'
CS0_T0CON1       EQU  H'0005'
CS1_T0CON1       EQU  H'0006'
CS2_T0CON1       EQU  H'0007'


T0CKPS0          EQU  H'0000'
T0CKPS1          EQU  H'0001'
T0CKPS2          EQU  H'0002'
T0CKPS3          EQU  H'0003'
T0CS0            EQU  H'0005'
T0CS1            EQU  H'0006'
T0CS2            EQU  H'0007'


;----- CWG1CLK Bits -----------------------------------------------------
CLK              EQU  H'0000'

CWG1CS           EQU  H'0000'


;----- CWG1CLKCON Bits -----------------------------------------------------
CLK              EQU  H'0000'

CWG1CS           EQU  H'0000'


;----- CWG1DAT Bits -----------------------------------------------------
CWG1DAT0         EQU  H'0000'
CWG1DAT1         EQU  H'0001'
CWG1DAT2         EQU  H'0002'
CWG1DAT3         EQU  H'0003'


;----- CWG1ISM Bits -----------------------------------------------------
CWG1DAT0         EQU  H'0000'
CWG1DAT1         EQU  H'0001'
CWG1DAT2         EQU  H'0002'
CWG1DAT3         EQU  H'0003'


;----- CWG1DBR Bits -----------------------------------------------------
DBR0             EQU  H'0000'
DBR1             EQU  H'0001'
DBR2             EQU  H'0002'
DBR3             EQU  H'0003'
DBR4             EQU  H'0004'
DBR5             EQU  H'0005'


CWG1DBR0         EQU  H'0000'
CWG1DBR1         EQU  H'0001'
CWG1DBR2         EQU  H'0002'
CWG1DBR3         EQU  H'0003'
CWG1DBR4         EQU  H'0004'
CWG1DBR5         EQU  H'0005'


;----- CWG1DBF Bits -----------------------------------------------------
DBF0             EQU  H'0000'
DBF1             EQU  H'0001'
DBF2             EQU  H'0002'
DBF3             EQU  H'0003'
DBF4             EQU  H'0004'
DBF5             EQU  H'0005'


CWG1DBF0         EQU  H'0000'
CWG1DBF1         EQU  H'0001'
CWG1DBF2         EQU  H'0002'
CWG1DBF3         EQU  H'0003'
CWG1DBF4         EQU  H'0004'
CWG1DBF5         EQU  H'0005'


;----- CWG1CON0 Bits -----------------------------------------------------
LD               EQU  H'0006'
EN               EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'
G1EN             EQU  H'0007'

CWG1LD           EQU  H'0006'
CWG1EN           EQU  H'0007'

CWG1MODE0        EQU  H'0000'
CWG1MODE1        EQU  H'0001'
CWG1MODE2        EQU  H'0002'


;----- CWG1CON1 Bits -----------------------------------------------------
POLA             EQU  H'0000'
POLB             EQU  H'0001'
POLC             EQU  H'0002'
POLD             EQU  H'0003'
IN               EQU  H'0005'

CWG1POLA         EQU  H'0000'
CWG1POLB         EQU  H'0001'
CWG1POLC         EQU  H'0002'
CWG1POLD         EQU  H'0003'
CWG1IN           EQU  H'0005'


;----- CWG1AS0 Bits -----------------------------------------------------
REN              EQU  H'0006'
SHUTDOWN         EQU  H'0007'

LSAC0            EQU  H'0002'
LSCA1            EQU  H'0003'
LSDB0            EQU  H'0004'
LSDB1            EQU  H'0005'

CWG1REN          EQU  H'0006'
CWG1SHUTDOWN     EQU  H'0007'

CWG1LSAC0        EQU  H'0002'
CWG1LSAC1        EQU  H'0003'
CWG1LSDB0        EQU  H'0004'
CWG1LSDB1        EQU  H'0005'


;----- CWG1AS1 Bits -----------------------------------------------------
AS0E             EQU  H'0000'
AS1E             EQU  H'0001'
AS2E             EQU  H'0002'
AS3E             EQU  H'0003'
AS4E             EQU  H'0004'
AS5E             EQU  H'0005'
AS6E             EQU  H'0006'


;----- CWG1STR Bits -----------------------------------------------------
STRA             EQU  H'0000'
STRB             EQU  H'0001'
STRC             EQU  H'0002'
STRD             EQU  H'0003'
OVRA             EQU  H'0004'
OVRB             EQU  H'0005'
OVRC             EQU  H'0006'
OVRD             EQU  H'0007'

CWG1STRA         EQU  H'0000'
CWG1STRB         EQU  H'0001'
CWG1STRC         EQU  H'0002'
CWG1STRD         EQU  H'0003'
CWG1OVRA         EQU  H'0004'
CWG1OVRB         EQU  H'0005'
CWG1OVRC         EQU  H'0006'
CWG1OVRD         EQU  H'0007'


;----- CWG2CLK Bits -----------------------------------------------------
CLK              EQU  H'0000'

CWG2CS           EQU  H'0000'


;----- CWG2CLKCON Bits -----------------------------------------------------
CLK              EQU  H'0000'

CWG2CS           EQU  H'0000'


;----- CWG2DAT Bits -----------------------------------------------------
CWG2DAT0         EQU  H'0000'
CWG2DAT1         EQU  H'0001'
CWG2DAT2         EQU  H'0002'
CWG2DAT3         EQU  H'0003'


;----- CWG2ISM Bits -----------------------------------------------------
CWG2DAT0         EQU  H'0000'
CWG2DAT1         EQU  H'0001'
CWG2DAT2         EQU  H'0002'
CWG2DAT3         EQU  H'0003'


;----- CWG2DBR Bits -----------------------------------------------------
DBR0             EQU  H'0000'
DBR1             EQU  H'0001'
DBR2             EQU  H'0002'
DBR3             EQU  H'0003'
DBR4             EQU  H'0004'
DBR5             EQU  H'0005'


CWG2DBR0         EQU  H'0000'
CWG2DBR1         EQU  H'0001'
CWG2DBR2         EQU  H'0002'
CWG2DBR3         EQU  H'0003'
CWG2DBR4         EQU  H'0004'
CWG2DBR5         EQU  H'0005'


;----- CWG2DBF Bits -----------------------------------------------------
DBF0             EQU  H'0000'
DBF1             EQU  H'0001'
DBF2             EQU  H'0002'
DBF3             EQU  H'0003'
DBF4             EQU  H'0004'
DBF5             EQU  H'0005'


CWG2DBF0         EQU  H'0000'
CWG2DBF1         EQU  H'0001'
CWG2DBF2         EQU  H'0002'
CWG2DBF3         EQU  H'0003'
CWG2DBF4         EQU  H'0004'
CWG2DBF5         EQU  H'0005'


;----- CWG2CON0 Bits -----------------------------------------------------
LD               EQU  H'0006'
EN               EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'
G2EN             EQU  H'0007'

CWG2LD           EQU  H'0006'
CWG2EN           EQU  H'0007'

CWG2MODE0        EQU  H'0000'
CWG2MODE1        EQU  H'0001'
CWG2MODE2        EQU  H'0002'


;----- CWG2CON1 Bits -----------------------------------------------------
POLA             EQU  H'0000'
POLB             EQU  H'0001'
POLC             EQU  H'0002'
POLD             EQU  H'0003'
IN               EQU  H'0005'

CWG2POLA         EQU  H'0000'
CWG2POLB         EQU  H'0001'
CWG2POLC         EQU  H'0002'
CWG2POLD         EQU  H'0003'
CWG2IN           EQU  H'0005'


;----- CWG2AS0 Bits -----------------------------------------------------
REN              EQU  H'0006'
SHUTDOWN         EQU  H'0007'

LSAC0            EQU  H'0002'
LSCA1            EQU  H'0003'
LSDB0            EQU  H'0004'
LSDB1            EQU  H'0005'

CWG2REN          EQU  H'0006'
CWG2SHUTDOWN     EQU  H'0007'

CWG2LSAC0        EQU  H'0002'
CWG2LSAC1        EQU  H'0003'
CWG2LSDB0        EQU  H'0004'
CWG2LSDB1        EQU  H'0005'


;----- CWG2AS1 Bits -----------------------------------------------------
AS0E             EQU  H'0000'
AS1E             EQU  H'0001'
AS2E             EQU  H'0002'
AS3E             EQU  H'0003'
AS4E             EQU  H'0004'
AS5E             EQU  H'0005'
AS6E             EQU  H'0006'


;----- CWG2STR Bits -----------------------------------------------------
STRA             EQU  H'0000'
STRB             EQU  H'0001'
STRC             EQU  H'0002'
STRD             EQU  H'0003'
OVRA             EQU  H'0004'
OVRB             EQU  H'0005'
OVRC             EQU  H'0006'
OVRD             EQU  H'0007'

CWG2STRA         EQU  H'0000'
CWG2STRB         EQU  H'0001'
CWG2STRC         EQU  H'0002'
CWG2STRD         EQU  H'0003'
CWG2OVRA         EQU  H'0004'
CWG2OVRB         EQU  H'0005'
CWG2OVRC         EQU  H'0006'
CWG2OVRD         EQU  H'0007'


;----- PIR0 Bits -----------------------------------------------------
INTF             EQU  H'0000'
IOCIF            EQU  H'0004'
TMR0IF           EQU  H'0005'


;----- PIR1 Bits -----------------------------------------------------
ADIF             EQU  H'0000'
ADTIF            EQU  H'0001'
CSWIF            EQU  H'0006'
OSFIF            EQU  H'0007'


;----- PIR2 Bits -----------------------------------------------------
C1IF             EQU  H'0000'
C2IF             EQU  H'0001'
ZCDIF            EQU  H'0006'


;----- PIR3 Bits -----------------------------------------------------
SSP1IF           EQU  H'0000'
BCL1IF           EQU  H'0001'
SSP2IF           EQU  H'0002'
BCL2IF           EQU  H'0003'
TX1IF            EQU  H'0004'
RC1IF            EQU  H'0005'


;----- PIR4 Bits -----------------------------------------------------
TMR1IF           EQU  H'0000'
TMR2IF           EQU  H'0001'
TMR3IF           EQU  H'0002'
TMR4IF           EQU  H'0003'
TMR5IF           EQU  H'0004'
TMR6IF           EQU  H'0005'


;----- PIR5 Bits -----------------------------------------------------
TMR1GIF          EQU  H'0000'
TMR3GIF          EQU  H'0001'
TMR5GIF          EQU  H'0002'
CLC1IF           EQU  H'0004'
CLC2IF           EQU  H'0005'
CLC3IF           EQU  H'0006'
CLC4IF           EQU  H'0007'


;----- PIR6 Bits -----------------------------------------------------
CCP1IF           EQU  H'0000'
CCP2IF           EQU  H'0001'
CCP3IF           EQU  H'0002'
CCP4IF           EQU  H'0003'


;----- PIR7 Bits -----------------------------------------------------
CWG1IF           EQU  H'0000'
CWG2IF           EQU  H'0001'
NCO1IF           EQU  H'0004'
NVMIF            EQU  H'0005'


;----- PIR8 Bits -----------------------------------------------------
SMT1IF           EQU  H'0000'
SMT1PRAIF        EQU  H'0001'
SMT1PWAIF        EQU  H'0002'


;----- PIE0 Bits -----------------------------------------------------
INTE             EQU  H'0000'
IOCIE            EQU  H'0004'
TMR0IE           EQU  H'0005'


;----- PIE1 Bits -----------------------------------------------------
ADIE             EQU  H'0000'
ADTIE            EQU  H'0001'
CSWIE            EQU  H'0006'
OSFIE            EQU  H'0007'


;----- PIE2 Bits -----------------------------------------------------
C1IE             EQU  H'0000'
C2IE             EQU  H'0001'
ZCDIE            EQU  H'0006'


;----- PIE3 Bits -----------------------------------------------------
SSP1IE           EQU  H'0000'
BCL1IE           EQU  H'0001'
SSP2IE           EQU  H'0002'
BCL2IE           EQU  H'0003'
TX1IE            EQU  H'0004'
RC1IE            EQU  H'0005'


;----- PIE4 Bits -----------------------------------------------------
TMR1IE           EQU  H'0000'
TMR2IE           EQU  H'0001'
TMR3IE           EQU  H'0002'
TMR4IE           EQU  H'0003'
TMR5IE           EQU  H'0004'
TMR6IE           EQU  H'0005'


;----- PIE5 Bits -----------------------------------------------------
TMR1GIE          EQU  H'0000'
TMR3GIE          EQU  H'0001'
TMR5GIE          EQU  H'0002'
CLC1IE           EQU  H'0004'
CLC2IE           EQU  H'0005'
CLC3IE           EQU  H'0006'
CLC4IE           EQU  H'0007'


;----- PIE6 Bits -----------------------------------------------------
CCP1IE           EQU  H'0000'
CCP2IE           EQU  H'0001'
CCP3IE           EQU  H'0002'
CCP4IE           EQU  H'0003'


;----- PIE7 Bits -----------------------------------------------------
CWG1IE           EQU  H'0000'
CWG2IE           EQU  H'0001'
NCO1IE           EQU  H'0004'
NVMIE            EQU  H'0005'

NCOIE            EQU  H'0004'


;----- PIE8 Bits -----------------------------------------------------
SMT1IE           EQU  H'0000'
SMT1PRAIE        EQU  H'0001'
SMT1PWAIE        EQU  H'0002'


;----- PMD0 Bits -----------------------------------------------------
IOCMD            EQU  H'0000'
CLKRMD           EQU  H'0001'
NVMMD            EQU  H'0002'
FVRMD            EQU  H'0006'
SYSCMD           EQU  H'0007'


;----- PMD1 Bits -----------------------------------------------------
TMR0MD           EQU  H'0000'
TMR1MD           EQU  H'0001'
TMR2MD           EQU  H'0002'
TMR3MD           EQU  H'0003'
TMR4MD           EQU  H'0004'
TMR5MD           EQU  H'0005'
TMR6MD           EQU  H'0006'


;----- PMD2 Bits -----------------------------------------------------
NCO1MD           EQU  H'0007'


;----- PMD3 Bits -----------------------------------------------------
ZCDMD            EQU  H'0000'
CMP1MD           EQU  H'0001'
CMP2MD           EQU  H'0002'
ADCMD            EQU  H'0005'
DAC1MD           EQU  H'0006'


;----- PMD4 Bits -----------------------------------------------------
CCP1MD           EQU  H'0000'
CCP2MD           EQU  H'0001'
CCP3MD           EQU  H'0002'
CCP4MD           EQU  H'0003'
PWM6MD           EQU  H'0005'
PWM7MD           EQU  H'0006'


;----- PMD5 Bits -----------------------------------------------------
CWG1MD           EQU  H'0005'
CWG2MD           EQU  H'0006'


;----- PMD6 Bits -----------------------------------------------------
MSSP1MD          EQU  H'0000'
MSSP2MD          EQU  H'0001'
U1MD             EQU  H'0004'


;----- PMD7 Bits -----------------------------------------------------
DSM1MD           EQU  H'0000'
CLC1MD           EQU  H'0001'
CLC2MD           EQU  H'0002'
CLC3MD           EQU  H'0003'
CLC4MD           EQU  H'0004'
SMT1MD           EQU  H'0005'


;----- WDTCON0 Bits -----------------------------------------------------
SEN              EQU  H'0000'

SWDTEN           EQU  H'0000'

WDTSEN           EQU  H'0000'

WDTPS0           EQU  H'0001'
WDTPS1           EQU  H'0002'
WDTPS2           EQU  H'0003'
WDTPS3           EQU  H'0004'
WDTPS4           EQU  H'0005'


;----- WDTCON1 Bits -----------------------------------------------------
WINDOW0          EQU  H'0000'
WINDOW1          EQU  H'0001'
WINDOW2          EQU  H'0002'


WDTWINDOW0       EQU  H'0000'
WDTWINDOW1       EQU  H'0001'
WDTWINDOW2       EQU  H'0002'
WDTCS0           EQU  H'0004'
WDTCS1           EQU  H'0005'
WDTCS2           EQU  H'0006'


;----- WDTPSL Bits -----------------------------------------------------
PSCNT0           EQU  H'0000'
PSCNT1           EQU  H'0001'
PSCNT2           EQU  H'0002'
PSCNT3           EQU  H'0003'
PSCNT4           EQU  H'0004'
PSCNT5           EQU  H'0005'
PSCNT6           EQU  H'0006'
PSCNT7           EQU  H'0007'


WDTPSCNT0        EQU  H'0000'
WDTPSCNT1        EQU  H'0001'
WDTPSCNT2        EQU  H'0002'
WDTPSCNT3        EQU  H'0003'
WDTPSCNT4        EQU  H'0004'
WDTPSCNT5        EQU  H'0005'
WDTPSCNT6        EQU  H'0006'
WDTPSCNT7        EQU  H'0007'


;----- WDTPSH Bits -----------------------------------------------------
PSCNT8           EQU  H'0000'
PSCNT9           EQU  H'0001'
PSCNT10          EQU  H'0002'
PSCNT11          EQU  H'0003'
PSCNT12          EQU  H'0004'
PSCNT13          EQU  H'0005'
PSCNT14          EQU  H'0006'
PSCNT15          EQU  H'0007'


WDTPSCNT8        EQU  H'0000'
WDTPSCNT9        EQU  H'0001'
WDTPSCNT10       EQU  H'0002'
WDTPSCNT11       EQU  H'0003'
WDTPSCNT12       EQU  H'0004'
WDTPSCNT13       EQU  H'0005'
WDTPSCNT14       EQU  H'0006'
WDTPSCNT15       EQU  H'0007'


;----- WDTTMR Bits -----------------------------------------------------
PSCNT16          EQU  H'0000'
PSCNT17          EQU  H'0001'
STATE            EQU  H'0002'

WDTPSCNT16       EQU  H'0000'
WDTPSCNT17       EQU  H'0001'
WDTSTATE         EQU  H'0002'
WDTTMR0          EQU  H'0003'
WDTTMR1          EQU  H'0004'
WDTTMR2          EQU  H'0005'
WDTTMR3          EQU  H'0006'


;----- BORCON Bits -----------------------------------------------------
BORRDY           EQU  H'0000'
SBOREN           EQU  H'0007'


;----- VREGCON Bits -----------------------------------------------------
VREGPM           EQU  H'0001'


;----- PCON0 Bits -----------------------------------------------------
NOT_BOR          EQU  H'0000'
NOT_POR          EQU  H'0001'
NOT_RI           EQU  H'0002'
NOT_RMCLR        EQU  H'0003'
NOT_RWDT         EQU  H'0004'
NOT_WDTWV        EQU  H'0005'
STKUNF           EQU  H'0006'
STKOVF           EQU  H'0007'


;----- PCON1 Bits -----------------------------------------------------
NOT_MEMV         EQU  H'0001'


;----- NVMADRL Bits -----------------------------------------------------
NVMADRL0         EQU  H'0000'
NVMADRL1         EQU  H'0001'
NVMADRL2         EQU  H'0002'
NVMADRL3         EQU  H'0003'
NVMADRL4         EQU  H'0004'
NVMADRL5         EQU  H'0005'
NVMADRL6         EQU  H'0006'
NVMADRL7         EQU  H'0007'


;----- NVMADRH Bits -----------------------------------------------------
NVMADRH0         EQU  H'0000'
NVMADRH1         EQU  H'0001'
NVMADRH2         EQU  H'0002'
NVMADRH3         EQU  H'0003'
NVMADRH4         EQU  H'0004'
NVMADRH5         EQU  H'0005'
NVMADRH6         EQU  H'0006'


;----- NVMDATL Bits -----------------------------------------------------
NVMDATL0         EQU  H'0000'
NVMDATL1         EQU  H'0001'
NVMDATL2         EQU  H'0002'
NVMDATL3         EQU  H'0003'
NVMDATL4         EQU  H'0004'
NVMDATL5         EQU  H'0005'
NVMDATL6         EQU  H'0006'
NVMDATL7         EQU  H'0007'


;----- NVMDATH Bits -----------------------------------------------------
NVMDATH0         EQU  H'0000'
NVMDATH1         EQU  H'0001'
NVMDATH2         EQU  H'0002'
NVMDATH3         EQU  H'0003'
NVMDATH4         EQU  H'0004'
NVMDATH5         EQU  H'0005'


;----- NVMCON1 Bits -----------------------------------------------------
RD               EQU  H'0000'
WR               EQU  H'0001'
WREN             EQU  H'0002'
WRERR            EQU  H'0003'
FREE             EQU  H'0004'
LWLO             EQU  H'0005'
NVMREGS          EQU  H'0006'


;----- CPUDOZE Bits -----------------------------------------------------
DOE              EQU  H'0004'
ROI              EQU  H'0005'
DOZEN            EQU  H'0006'
IDLEN            EQU  H'0007'

DOZE0            EQU  H'0000'
DOZE1            EQU  H'0001'
DOZE2            EQU  H'0002'


;----- OSCCON1 Bits -----------------------------------------------------
NDIV0            EQU  H'0000'
NDIV1            EQU  H'0001'
NDIV2            EQU  H'0002'
NDIV3            EQU  H'0003'
NOSC0            EQU  H'0004'
NOSC1            EQU  H'0005'
NOSC2            EQU  H'0006'


;----- OSCCON2 Bits -----------------------------------------------------
CDIV0            EQU  H'0000'
CDIV1            EQU  H'0001'
CDIV2            EQU  H'0002'
CDIV3            EQU  H'0003'
COSC0            EQU  H'0004'
COSC1            EQU  H'0005'
COSC2            EQU  H'0006'


;----- OSCCON3 Bits -----------------------------------------------------
NOSCR            EQU  H'0003'
ORDY             EQU  H'0004'
SOSCPWR          EQU  H'0006'
CSWHOLD          EQU  H'0007'


;----- OSCSTAT Bits -----------------------------------------------------
PLLR             EQU  H'0000'
ADOR             EQU  H'0002'
SOR              EQU  H'0003'
LFOR             EQU  H'0004'
MFOR             EQU  H'0005'
HFOR             EQU  H'0006'
EXTOR            EQU  H'0007'


;----- OSCEN Bits -----------------------------------------------------
ADOEN            EQU  H'0002'
SOSCEN           EQU  H'0003'
LFOEN            EQU  H'0004'
MFOEN            EQU  H'0005'
HFOEN            EQU  H'0006'
EXTOEN           EQU  H'0007'


;----- OSCTUNE Bits -----------------------------------------------------
HFTUN0           EQU  H'0000'
HFTUN1           EQU  H'0001'
HFTUN2           EQU  H'0002'
HFTUN3           EQU  H'0003'
HFTUN4           EQU  H'0004'
HFTUN5           EQU  H'0005'


;----- OSCFRQ Bits -----------------------------------------------------
HFFRQ0           EQU  H'0000'
HFFRQ1           EQU  H'0001'
HFFRQ2           EQU  H'0002'


;----- CLKRCON Bits -----------------------------------------------------
CLKREN           EQU  H'0007'

CLKRDIV0         EQU  H'0000'
CLKRDIV1         EQU  H'0001'
CLKRDIV2         EQU  H'0002'
CLKRDC0          EQU  H'0003'
CLKRDC1          EQU  H'0004'


;----- CLKRCLK Bits -----------------------------------------------------
CLKRCLK0         EQU  H'0000'
CLKRCLK1         EQU  H'0001'
CLKRCLK2         EQU  H'0002'
CLKRCLK3         EQU  H'0003'


;----- MD1CON0 Bits -----------------------------------------------------
BIT              EQU  H'0000'
OPOL             EQU  H'0004'
OUT_MD1CON0      EQU  H'0005'
EN               EQU  H'0007'

MD1BIT           EQU  H'0000'
MD1OPOL          EQU  H'0004'
MD1OUT           EQU  H'0005'
MD1EN            EQU  H'0007'


;----- MD1CON1 Bits -----------------------------------------------------
CLSYNC           EQU  H'0000'
CLPOL            EQU  H'0001'
CHSYNC           EQU  H'0004'
CHPOL            EQU  H'0005'

MD1CLSYNC        EQU  H'0000'
MD1CLPOL         EQU  H'0001'
MD1CHSYNC        EQU  H'0004'
MD1CHPOL         EQU  H'0005'


;----- MD1SRC Bits -----------------------------------------------------
MS0              EQU  H'0000'
MS1              EQU  H'0001'
MS2              EQU  H'0002'
MS3              EQU  H'0003'
MS4              EQU  H'0004'


MD1MS0           EQU  H'0000'
MD1MS1           EQU  H'0001'
MD1MS2           EQU  H'0002'
MD1MS3           EQU  H'0003'
MD1MS4           EQU  H'0004'


;----- MD1CARL Bits -----------------------------------------------------
CL0              EQU  H'0000'
CL1              EQU  H'0001'
CL2              EQU  H'0002'
CL3              EQU  H'0003'


MD1CL0           EQU  H'0000'
MD1CL1           EQU  H'0001'
MD1CL2           EQU  H'0002'
MD1CL3           EQU  H'0003'


;----- MD1CARH Bits -----------------------------------------------------
CH0              EQU  H'0000'
CH1              EQU  H'0001'
CH2              EQU  H'0002'
CH3              EQU  H'0003'


MD1CH0           EQU  H'0000'
MD1CH1           EQU  H'0001'
MD1CH2           EQU  H'0002'
MD1CH3           EQU  H'0003'


;----- FVRCON Bits -----------------------------------------------------
TSRNG            EQU  H'0004'
TSEN             EQU  H'0005'
FVRRDY           EQU  H'0006'
FVREN            EQU  H'0007'

ADFVR0           EQU  H'0000'
ADFVR1           EQU  H'0001'
CDAFVR0          EQU  H'0002'
CDAFVR1          EQU  H'0003'


;----- DAC1CON0 Bits -----------------------------------------------------
NSS              EQU  H'0000'
OE1              EQU  H'0005'
EN               EQU  H'0007'

DAC1NSS          EQU  H'0000'
DAC1PSS0         EQU  H'0002'
DAC1PSS1         EQU  H'0003'
DAC1OE1          EQU  H'0005'
DAC1EN           EQU  H'0007'

PSS0             EQU  H'0002'
PSS1             EQU  H'0003'


;----- DAC1CON1 Bits -----------------------------------------------------
DAC1R0           EQU  H'0000'
DAC1R1           EQU  H'0001'
DAC1R2           EQU  H'0002'
DAC1R3           EQU  H'0003'
DAC1R4           EQU  H'0004'


;----- ZCDCON Bits -----------------------------------------------------
ZCDINTN          EQU  H'0000'
ZCDINTP          EQU  H'0001'
ZCDPOL           EQU  H'0004'
ZCDOUT           EQU  H'0005'
ZCDSEN           EQU  H'0007'


;----- CMOUT Bits -----------------------------------------------------
MC1OUT           EQU  H'0000'
MC2OUT           EQU  H'0001'

C1OUT_CMOUT      EQU  H'0000'
C2OUT_CMOUT      EQU  H'0001'


;----- CMSTAT Bits -----------------------------------------------------
MC1OUT           EQU  H'0000'
MC2OUT           EQU  H'0001'

C1OUT_CMSTAT     EQU  H'0000'
C2OUT_CMSTAT     EQU  H'0001'


;----- CM1CON0 Bits -----------------------------------------------------
SYNC_CM1CON0     EQU  H'0000'
HYS              EQU  H'0001'
POL_CM1CON0      EQU  H'0004'
OUT_CM1CON0      EQU  H'0006'
EN               EQU  H'0007'

C1SYNC           EQU  H'0000'
C1HYS            EQU  H'0001'
C1POL            EQU  H'0004'
C1OUT_CM1CON0    EQU  H'0006'
C1EN             EQU  H'0007'


;----- CM1CON1 Bits -----------------------------------------------------
INTN_CM1CON1     EQU  H'0000'
INTP_CM1CON1     EQU  H'0001'

C1INTN           EQU  H'0000'
C1INTP           EQU  H'0001'


;----- CM1NCH Bits -----------------------------------------------------
NCH0             EQU  H'0000'
NCH1             EQU  H'0001'
NCH2             EQU  H'0002'

C1NCH0           EQU  H'0000'
C1NCH1           EQU  H'0001'
C1NCH2           EQU  H'0002'


;----- CM1PCH Bits -----------------------------------------------------
PCH0             EQU  H'0000'
PCH1             EQU  H'0001'
PCH2             EQU  H'0002'

C1PCH0           EQU  H'0000'
C1PCH1           EQU  H'0001'
C1PCH2           EQU  H'0002'


;----- CM2CON0 Bits -----------------------------------------------------
SYNC_CM2CON0     EQU  H'0000'
HYS              EQU  H'0001'
POL_CM2CON0      EQU  H'0004'
OUT_CM2CON0      EQU  H'0006'
EN               EQU  H'0007'

C2SYNC           EQU  H'0000'
C2HYS            EQU  H'0001'
C2POL            EQU  H'0004'
C2OUT_CM2CON0    EQU  H'0006'
C2EN             EQU  H'0007'


;----- CM2CON1 Bits -----------------------------------------------------
INTN_CM2CON1     EQU  H'0000'
INTP_CM2CON1     EQU  H'0001'

C2INTN           EQU  H'0000'
C2INTP           EQU  H'0001'


;----- CM2NCH Bits -----------------------------------------------------
NCH0             EQU  H'0000'
NCH1             EQU  H'0001'
NCH2             EQU  H'0002'

C2NCH0           EQU  H'0000'
C2NCH1           EQU  H'0001'
C2NCH2           EQU  H'0002'


;----- CM2PCH Bits -----------------------------------------------------
PCH0             EQU  H'0000'
PCH1             EQU  H'0001'
PCH2             EQU  H'0002'

C2PCH0           EQU  H'0000'
C2PCH1           EQU  H'0001'
C2PCH2           EQU  H'0002'


;----- CLCDATA Bits -----------------------------------------------------
MLC1OUT          EQU  H'0000'
MLC2OUT          EQU  H'0001'
MLC3OUT          EQU  H'0002'
MLC4OUT          EQU  H'0003'


;----- CLC1CON Bits -----------------------------------------------------
LC1INTN          EQU  H'0003'
LC1INTP          EQU  H'0004'
LC1OUT           EQU  H'0005'
LC1EN            EQU  H'0007'

LC1MODE0         EQU  H'0000'
LC1MODE1         EQU  H'0001'
LC1MODE2         EQU  H'0002'

INTN_CLC1CON     EQU  H'0003'
INTP_CLC1CON     EQU  H'0004'
OUT_CLC1CON      EQU  H'0005'
EN               EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'


;----- CLC1POL Bits -----------------------------------------------------
LC1G1POL         EQU  H'0000'
LC1G2POL         EQU  H'0001'
LC1G3POL         EQU  H'0002'
LC1G4POL         EQU  H'0003'
LC1POL           EQU  H'0007'

G1POL            EQU  H'0000'
G2POL            EQU  H'0001'
G3POL            EQU  H'0002'
G4POL            EQU  H'0003'
POL_CLC1POL      EQU  H'0007'


;----- CLC1SEL0 Bits -----------------------------------------------------
LC1D1S0          EQU  H'0000'
LC1D1S1          EQU  H'0001'
LC1D1S2          EQU  H'0002'
LC1D1S3          EQU  H'0003'
LC1D1S4          EQU  H'0004'
LC1D1S5          EQU  H'0005'



D1S0             EQU  H'0000'
D1S1             EQU  H'0001'
D1S2             EQU  H'0002'
D1S3             EQU  H'0003'
D1S4             EQU  H'0004'
D1S5             EQU  H'0005'


;----- CLC1SEL1 Bits -----------------------------------------------------
LC1D2S0          EQU  H'0000'
LC1D2S1          EQU  H'0001'
LC1D2S2          EQU  H'0002'
LC1D2S3          EQU  H'0003'
LC1D2S4          EQU  H'0004'
LC1D2S5          EQU  H'0005'



D2S0             EQU  H'0000'
D2S1             EQU  H'0001'
D2S2             EQU  H'0002'
D2S3             EQU  H'0003'
D2S4             EQU  H'0004'
D2S5             EQU  H'0005'


;----- CLC1SEL2 Bits -----------------------------------------------------
LC1D3S0          EQU  H'0000'
LC1D3S1          EQU  H'0001'
LC1D3S2          EQU  H'0002'
LC1D3S3          EQU  H'0003'
LC1D3S4          EQU  H'0004'
LC1D3S5          EQU  H'0005'



D3S0             EQU  H'0000'
D3S1             EQU  H'0001'
D3S2             EQU  H'0002'
D3S3             EQU  H'0003'
D3S4             EQU  H'0004'
D3S5             EQU  H'0005'


;----- CLC1SEL3 Bits -----------------------------------------------------
LC1D4S0          EQU  H'0000'
LC1D4S1          EQU  H'0001'
LC1D4S2          EQU  H'0002'
LC1D4S3          EQU  H'0003'
LC1D4S4          EQU  H'0004'
LC1D4S5          EQU  H'0005'



D4S0             EQU  H'0000'
D4S1             EQU  H'0001'
D4S2             EQU  H'0002'
D4S3             EQU  H'0003'
D4S4             EQU  H'0004'
D4S5             EQU  H'0005'


;----- CLC1GLS0 Bits -----------------------------------------------------
LC1G1D1N         EQU  H'0000'
LC1G1D1T         EQU  H'0001'
LC1G1D2N         EQU  H'0002'
LC1G1D2T         EQU  H'0003'
LC1G1D3N         EQU  H'0004'
LC1G1D3T         EQU  H'0005'
LC1G1D4N         EQU  H'0006'
LC1G1D4T         EQU  H'0007'

D1N              EQU  H'0000'
D1T              EQU  H'0001'
D2N              EQU  H'0002'
D2T              EQU  H'0003'
D3N              EQU  H'0004'
D3T              EQU  H'0005'
D4N              EQU  H'0006'
D4T              EQU  H'0007'


;----- CLC1GLS1 Bits -----------------------------------------------------
LC1G2D1N         EQU  H'0000'
LC1G2D1T         EQU  H'0001'
LC1G2D2N         EQU  H'0002'
LC1G2D2T         EQU  H'0003'
LC1G2D3N         EQU  H'0004'
LC1G2D3T         EQU  H'0005'
LC1G2D4N         EQU  H'0006'
LC1G2D4T         EQU  H'0007'

D1N              EQU  H'0000'
D1T              EQU  H'0001'
D2N              EQU  H'0002'
D2T              EQU  H'0003'
D3N              EQU  H'0004'
D3T              EQU  H'0005'
D4N              EQU  H'0006'
D4T              EQU  H'0007'


;----- CLC1GLS2 Bits -----------------------------------------------------
LC1G3D1N         EQU  H'0000'
LC1G3D1T         EQU  H'0001'
LC1G3D2N         EQU  H'0002'
LC1G3D2T         EQU  H'0003'
LC1G3D3N         EQU  H'0004'
LC1G3D3T         EQU  H'0005'
LC1G3D4N         EQU  H'0006'
LC1G3D4T         EQU  H'0007'

D1N              EQU  H'0000'
D1T              EQU  H'0001'
D2N              EQU  H'0002'
D2T              EQU  H'0003'
D3N              EQU  H'0004'
D3T              EQU  H'0005'
D4N              EQU  H'0006'
D4T              EQU  H'0007'


;----- CLC1GLS3 Bits -----------------------------------------------------
LC1G4D1N         EQU  H'0000'
LC1G4D1T         EQU  H'0001'
LC1G4D2N         EQU  H'0002'
LC1G4D2T         EQU  H'0003'
LC1G4D3N         EQU  H'0004'
LC1G4D3T         EQU  H'0005'
LC1G4D4N         EQU  H'0006'
LC1G4D4T         EQU  H'0007'

G4D1N            EQU  H'0000'
G4D1T            EQU  H'0001'
G4D2N            EQU  H'0002'
G4D2T            EQU  H'0003'
G4D3N            EQU  H'0004'
G4D3T            EQU  H'0005'
G4D4N            EQU  H'0006'
G4D4T            EQU  H'0007'


;----- CLC2CON Bits -----------------------------------------------------
LC2INTN          EQU  H'0003'
LC2INTP          EQU  H'0004'
LC2OUT           EQU  H'0005'
LC2EN            EQU  H'0007'

LC2MODE0         EQU  H'0000'
LC2MODE1         EQU  H'0001'
LC2MODE2         EQU  H'0002'

INTN_CLC2CON     EQU  H'0003'
INTP_CLC2CON     EQU  H'0004'
OUT_CLC2CON      EQU  H'0005'
EN               EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'


;----- CLC2POL Bits -----------------------------------------------------
LC2G1POL         EQU  H'0000'
LC2G2POL         EQU  H'0001'
LC2G3POL         EQU  H'0002'
LC2G4POL         EQU  H'0003'
LC2POL           EQU  H'0007'

G1POL            EQU  H'0000'
G2POL            EQU  H'0001'
G3POL            EQU  H'0002'
G4POL            EQU  H'0003'
POL_CLC2POL      EQU  H'0007'


;----- CLC2SEL0 Bits -----------------------------------------------------
LC2D1S0          EQU  H'0000'
LC2D1S1          EQU  H'0001'
LC2D1S2          EQU  H'0002'
LC2D1S3          EQU  H'0003'
LC2D1S4          EQU  H'0004'
LC2D1S5          EQU  H'0005'



D1S0             EQU  H'0000'
D1S1             EQU  H'0001'
D1S2             EQU  H'0002'
D1S3             EQU  H'0003'
D1S4             EQU  H'0004'
D1S5             EQU  H'0005'


;----- CLC2SEL1 Bits -----------------------------------------------------
LC2D2S0          EQU  H'0000'
LC2D2S1          EQU  H'0001'
LC2D2S2          EQU  H'0002'
LC2D2S3          EQU  H'0003'
LC2D2S4          EQU  H'0004'
LC2D2S5          EQU  H'0005'



D2S0             EQU  H'0000'
D2S1             EQU  H'0001'
D2S2             EQU  H'0002'
D2S3             EQU  H'0003'
D2S4             EQU  H'0004'
D2S5             EQU  H'0005'


;----- CLC2SEL2 Bits -----------------------------------------------------
LC2D3S0          EQU  H'0000'
LC2D3S1          EQU  H'0001'
LC2D3S2          EQU  H'0002'
LC2D3S3          EQU  H'0003'
LC2D3S4          EQU  H'0004'
LC2D3S5          EQU  H'0005'



D3S0             EQU  H'0000'
D3S1             EQU  H'0001'
D3S2             EQU  H'0002'
D3S3             EQU  H'0003'
D3S4             EQU  H'0004'
D3S5             EQU  H'0005'


;----- CLC2SEL3 Bits -----------------------------------------------------
LC2D4S0          EQU  H'0000'
LC2D4S1          EQU  H'0001'
LC2D4S2          EQU  H'0002'
LC2D4S3          EQU  H'0003'
LC2D4S4          EQU  H'0004'
LC2D4S5          EQU  H'0005'



D4S0             EQU  H'0000'
D4S1             EQU  H'0001'
D4S2             EQU  H'0002'
D4S3             EQU  H'0003'
D4S4             EQU  H'0004'
D4S5             EQU  H'0005'


;----- CLC2GLS0 Bits -----------------------------------------------------
LC2G1D1N         EQU  H'0000'
LC2G1D1T         EQU  H'0001'
LC2G1D2N         EQU  H'0002'
LC2G1D2T         EQU  H'0003'
LC2G1D3N         EQU  H'0004'
LC2G1D3T         EQU  H'0005'
LC2G1D4N         EQU  H'0006'
LC2G1D4T         EQU  H'0007'

D1N              EQU  H'0000'
D1T              EQU  H'0001'
D2N              EQU  H'0002'
D2T              EQU  H'0003'
D3N              EQU  H'0004'
D3T              EQU  H'0005'
D4N              EQU  H'0006'
D4T              EQU  H'0007'


;----- CLC2GLS1 Bits -----------------------------------------------------
LC2G2D1N         EQU  H'0000'
LC2G2D1T         EQU  H'0001'
LC2G2D2N         EQU  H'0002'
LC2G2D2T         EQU  H'0003'
LC2G2D3N         EQU  H'0004'
LC2G2D3T         EQU  H'0005'
LC2G2D4N         EQU  H'0006'
LC2G2D4T         EQU  H'0007'

D1N              EQU  H'0000'
D1T              EQU  H'0001'
D2N              EQU  H'0002'
D2T              EQU  H'0003'
D3N              EQU  H'0004'
D3T              EQU  H'0005'
D4N              EQU  H'0006'
D4T              EQU  H'0007'


;----- CLC2GLS2 Bits -----------------------------------------------------
LC2G3D1N         EQU  H'0000'
LC2G3D1T         EQU  H'0001'
LC2G3D2N         EQU  H'0002'
LC2G3D2T         EQU  H'0003'
LC2G3D3N         EQU  H'0004'
LC2G3D3T         EQU  H'0005'
LC2G3D4N         EQU  H'0006'
LC2G3D4T         EQU  H'0007'

D1N              EQU  H'0000'
D1T              EQU  H'0001'
D2N              EQU  H'0002'
D2T              EQU  H'0003'
D3N              EQU  H'0004'
D3T              EQU  H'0005'
D4N              EQU  H'0006'
D4T              EQU  H'0007'


;----- CLC2GLS3 Bits -----------------------------------------------------
LC2G4D1N         EQU  H'0000'
LC2G4D1T         EQU  H'0001'
LC2G4D2N         EQU  H'0002'
LC2G4D2T         EQU  H'0003'
LC2G4D3N         EQU  H'0004'
LC2G4D3T         EQU  H'0005'
LC2G4D4N         EQU  H'0006'
LC2G4D4T         EQU  H'0007'

G4D1N            EQU  H'0000'
G4D1T            EQU  H'0001'
G4D2N            EQU  H'0002'
G4D2T            EQU  H'0003'
G4D3N            EQU  H'0004'
G4D3T            EQU  H'0005'
G4D4N            EQU  H'0006'
G4D4T            EQU  H'0007'


;----- CLC3CON Bits -----------------------------------------------------
LC3INTN          EQU  H'0003'
LC3INTP          EQU  H'0004'
LC3OUT           EQU  H'0005'
LC3EN            EQU  H'0007'

LC3MODE0         EQU  H'0000'
LC3MODE1         EQU  H'0001'
LC3MODE2         EQU  H'0002'

INTN_CLC3CON     EQU  H'0003'
INTP_CLC3CON     EQU  H'0004'
OUT_CLC3CON      EQU  H'0005'
EN               EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'


;----- CLC3POL Bits -----------------------------------------------------
LC3G1POL         EQU  H'0000'
LC3G2POL         EQU  H'0001'
LC3G3POL         EQU  H'0002'
LC3G4POL         EQU  H'0003'
LC3POL           EQU  H'0007'

G1POL            EQU  H'0000'
G2POL            EQU  H'0001'
G3POL            EQU  H'0002'
G4POL            EQU  H'0003'
POL_CLC3POL      EQU  H'0007'


;----- CLC3SEL0 Bits -----------------------------------------------------
LC3D1S0          EQU  H'0000'
LC3D1S1          EQU  H'0001'
LC3D1S2          EQU  H'0002'
LC3D1S3          EQU  H'0003'
LC3D1S4          EQU  H'0004'
LC3D1S5          EQU  H'0005'



D1S0             EQU  H'0000'
D1S1             EQU  H'0001'
D1S2             EQU  H'0002'
D1S3             EQU  H'0003'
D1S4             EQU  H'0004'
D1S5             EQU  H'0005'


;----- CLC3SEL1 Bits -----------------------------------------------------
LC3D2S0          EQU  H'0000'
LC3D2S1          EQU  H'0001'
LC3D2S2          EQU  H'0002'
LC3D2S3          EQU  H'0003'
LC3D2S4          EQU  H'0004'
LC3D2S5          EQU  H'0005'



D2S0             EQU  H'0000'
D2S1             EQU  H'0001'
D2S2             EQU  H'0002'
D2S3             EQU  H'0003'
D2S4             EQU  H'0004'
D2S5             EQU  H'0005'


;----- CLC3SEL2 Bits -----------------------------------------------------
LC3D3S0          EQU  H'0000'
LC3D3S1          EQU  H'0001'
LC3D3S2          EQU  H'0002'
LC3D3S3          EQU  H'0003'
LC3D3S4          EQU  H'0004'
LC3D3S5          EQU  H'0005'



D3S0             EQU  H'0000'
D3S1             EQU  H'0001'
D3S2             EQU  H'0002'
D3S3             EQU  H'0003'
D3S4             EQU  H'0004'
D3S5             EQU  H'0005'


;----- CLC3SEL3 Bits -----------------------------------------------------
LC3D4S0          EQU  H'0000'
LC3D4S1          EQU  H'0001'
LC3D4S2          EQU  H'0002'
LC3D4S3          EQU  H'0003'
LC3D4S4          EQU  H'0004'
LC3D4S5          EQU  H'0005'



D4S0             EQU  H'0000'
D4S1             EQU  H'0001'
D4S2             EQU  H'0002'
D4S3             EQU  H'0003'
D4S4             EQU  H'0004'
D4S5             EQU  H'0005'


;----- CLC3GLS0 Bits -----------------------------------------------------
LC3G1D1N         EQU  H'0000'
LC3G1D1T         EQU  H'0001'
LC3G1D2N         EQU  H'0002'
LC3G1D2T         EQU  H'0003'
LC3G1D3N         EQU  H'0004'
LC3G1D3T         EQU  H'0005'
LC3G1D4N         EQU  H'0006'
LC3G1D4T         EQU  H'0007'

D1N              EQU  H'0000'
D1T              EQU  H'0001'
D2N              EQU  H'0002'
D2T              EQU  H'0003'
D3N              EQU  H'0004'
D3T              EQU  H'0005'
D4N              EQU  H'0006'
D4T              EQU  H'0007'


;----- CLC3GLS1 Bits -----------------------------------------------------
LC3G2D1N         EQU  H'0000'
LC3G2D1T         EQU  H'0001'
LC3G2D2N         EQU  H'0002'
LC3G2D2T         EQU  H'0003'
LC3G2D3N         EQU  H'0004'
LC3G2D3T         EQU  H'0005'
LC3G2D4N         EQU  H'0006'
LC3G2D4T         EQU  H'0007'

D1N              EQU  H'0000'
D1T              EQU  H'0001'
D2N              EQU  H'0002'
D2T              EQU  H'0003'
D3N              EQU  H'0004'
D3T              EQU  H'0005'
D4N              EQU  H'0006'
D4T              EQU  H'0007'


;----- CLC3GLS2 Bits -----------------------------------------------------
LC3G3D1N         EQU  H'0000'
LC3G3D1T         EQU  H'0001'
LC3G3D2N         EQU  H'0002'
LC3G3D2T         EQU  H'0003'
LC3G3D3N         EQU  H'0004'
LC3G3D3T         EQU  H'0005'
LC3G3D4N         EQU  H'0006'
LC3G3D4T         EQU  H'0007'

D1N              EQU  H'0000'
D1T              EQU  H'0001'
D2N              EQU  H'0002'
D2T              EQU  H'0003'
D3N              EQU  H'0004'
D3T              EQU  H'0005'
D4N              EQU  H'0006'
D4T              EQU  H'0007'


;----- CLC3GLS3 Bits -----------------------------------------------------
LC3G4D1N         EQU  H'0000'
LC3G4D1T         EQU  H'0001'
LC3G4D2N         EQU  H'0002'
LC3G4D2T         EQU  H'0003'
LC3G4D3N         EQU  H'0004'
LC3G4D3T         EQU  H'0005'
LC3G4D4N         EQU  H'0006'
LC3G4D4T         EQU  H'0007'

G4D1N            EQU  H'0000'
G4D1T            EQU  H'0001'
G4D2N            EQU  H'0002'
G4D2T            EQU  H'0003'
G4D3N            EQU  H'0004'
G4D3T            EQU  H'0005'
G4D4N            EQU  H'0006'
G4D4T            EQU  H'0007'


;----- CLC4CON Bits -----------------------------------------------------
LC4INTN          EQU  H'0003'
LC4INTP          EQU  H'0004'
LC4OUT           EQU  H'0005'
LC4EN            EQU  H'0007'

LC4MODE0         EQU  H'0000'
LC4MODE1         EQU  H'0001'
LC4MODE2         EQU  H'0002'

INTN_CLC4CON     EQU  H'0003'
INTP_CLC4CON     EQU  H'0004'
OUT_CLC4CON      EQU  H'0005'
EN               EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'


;----- CLC4POL Bits -----------------------------------------------------
LC4G1POL         EQU  H'0000'
LC4G2POL         EQU  H'0001'
LC4G3POL         EQU  H'0002'
LC4G4POL         EQU  H'0003'
LC4POL           EQU  H'0007'

G1POL            EQU  H'0000'
G2POL            EQU  H'0001'
G3POL            EQU  H'0002'
G4POL            EQU  H'0003'
POL_CLC4POL      EQU  H'0007'


;----- CLC4SEL0 Bits -----------------------------------------------------
LC4D1S0          EQU  H'0000'
LC4D1S1          EQU  H'0001'
LC4D1S2          EQU  H'0002'
LC4D1S3          EQU  H'0003'
LC4D1S4          EQU  H'0004'
LC4D1S5          EQU  H'0005'



D1S0             EQU  H'0000'
D1S1             EQU  H'0001'
D1S2             EQU  H'0002'
D1S3             EQU  H'0003'
D1S4             EQU  H'0004'
D1S5             EQU  H'0005'


;----- CLC4SEL1 Bits -----------------------------------------------------
LC4D2S0          EQU  H'0000'
LC4D2S1          EQU  H'0001'
LC4D2S2          EQU  H'0002'
LC4D2S3          EQU  H'0003'
LC4D2S4          EQU  H'0004'
LC4D2S5          EQU  H'0005'



D2S0             EQU  H'0000'
D2S1             EQU  H'0001'
D2S2             EQU  H'0002'
D2S3             EQU  H'0003'
D2S4             EQU  H'0004'
D2S5             EQU  H'0005'


;----- CLC4SEL2 Bits -----------------------------------------------------
LC4D3S0          EQU  H'0000'
LC4D3S1          EQU  H'0001'
LC4D3S2          EQU  H'0002'
LC4D3S3          EQU  H'0003'
LC4D3S4          EQU  H'0004'
LC4D3S5          EQU  H'0005'



D3S0             EQU  H'0000'
D3S1             EQU  H'0001'
D3S2             EQU  H'0002'
D3S3             EQU  H'0003'
D3S4             EQU  H'0004'
D3S5             EQU  H'0005'


;----- CLC4SEL3 Bits -----------------------------------------------------
LC4D4S0          EQU  H'0000'
LC4D4S1          EQU  H'0001'
LC4D4S2          EQU  H'0002'
LC4D4S3          EQU  H'0003'
LC4D4S4          EQU  H'0004'
LC4D4S5          EQU  H'0005'



D4S0             EQU  H'0000'
D4S1             EQU  H'0001'
D4S2             EQU  H'0002'
D4S3             EQU  H'0003'
D4S4             EQU  H'0004'
D4S5             EQU  H'0005'


;----- CLC4GLS0 Bits -----------------------------------------------------
LC4G1D1N         EQU  H'0000'
LC4G1D1T         EQU  H'0001'
LC4G1D2N         EQU  H'0002'
LC4G1D2T         EQU  H'0003'
LC4G1D3N         EQU  H'0004'
LC4G1D3T         EQU  H'0005'
LC4G1D4N         EQU  H'0006'
LC4G1D4T         EQU  H'0007'

D1N              EQU  H'0000'
D1T              EQU  H'0001'
D2N              EQU  H'0002'
D2T              EQU  H'0003'
D3N              EQU  H'0004'
D3T              EQU  H'0005'
D4N              EQU  H'0006'
D4T              EQU  H'0007'


;----- CLC4GLS1 Bits -----------------------------------------------------
LC4G2D1N         EQU  H'0000'
LC4G2D1T         EQU  H'0001'
LC4G2D2N         EQU  H'0002'
LC4G2D2T         EQU  H'0003'
LC4G2D3N         EQU  H'0004'
LC4G2D3T         EQU  H'0005'
LC4G2D4N         EQU  H'0006'
LC4G2D4T         EQU  H'0007'

D1N              EQU  H'0000'
D1T              EQU  H'0001'
D2N              EQU  H'0002'
D2T              EQU  H'0003'
D3N              EQU  H'0004'
D3T              EQU  H'0005'
D4N              EQU  H'0006'
D4T              EQU  H'0007'


;----- CLC4GLS2 Bits -----------------------------------------------------
LC4G3D1N         EQU  H'0000'
LC4G3D1T         EQU  H'0001'
LC4G3D2N         EQU  H'0002'
LC4G3D2T         EQU  H'0003'
LC4G3D3N         EQU  H'0004'
LC4G3D3T         EQU  H'0005'
LC4G3D4N         EQU  H'0006'
LC4G3D4T         EQU  H'0007'

D1N              EQU  H'0000'
D1T              EQU  H'0001'
D2N              EQU  H'0002'
D2T              EQU  H'0003'
D3N              EQU  H'0004'
D3T              EQU  H'0005'
D4N              EQU  H'0006'
D4T              EQU  H'0007'


;----- CLC4GLS3 Bits -----------------------------------------------------
LC4G4D1N         EQU  H'0000'
LC4G4D1T         EQU  H'0001'
LC4G4D2N         EQU  H'0002'
LC4G4D2T         EQU  H'0003'
LC4G4D3N         EQU  H'0004'
LC4G4D3T         EQU  H'0005'
LC4G4D4N         EQU  H'0006'
LC4G4D4T         EQU  H'0007'

G4D1N            EQU  H'0000'
G4D1T            EQU  H'0001'
G4D2N            EQU  H'0002'
G4D2T            EQU  H'0003'
G4D3N            EQU  H'0004'
G4D3T            EQU  H'0005'
G4D4N            EQU  H'0006'
G4D4T            EQU  H'0007'


;----- PPSLOCK Bits -----------------------------------------------------
PPSLOCKED        EQU  H'0000'


;----- INTPPS Bits -----------------------------------------------------
PORT             EQU  H'0003'


INTPPS0          EQU  H'0000'
INTPPS1          EQU  H'0001'
INTPPS2          EQU  H'0002'
INTPPS3          EQU  H'0003'


;----- T0CKIPPS Bits -----------------------------------------------------
PORT             EQU  H'0003'


T0CKIPPS0        EQU  H'0000'
T0CKIPPS1        EQU  H'0001'
T0CKIPPS2        EQU  H'0002'
T0CKIPPS3        EQU  H'0003'


;----- T1CKIPPS Bits -----------------------------------------------------
T1CKIPPS0        EQU  H'0000'
T1CKIPPS1        EQU  H'0001'
T1CKIPPS2        EQU  H'0002'
T1CKIPPS3        EQU  H'0003'
T1CKIPPS4        EQU  H'0004'


;----- T1GPPS Bits -----------------------------------------------------
T1GPPS0          EQU  H'0000'
T1GPPS1          EQU  H'0001'
T1GPPS2          EQU  H'0002'
T1GPPS3          EQU  H'0003'
T1GPPS4          EQU  H'0004'


;----- T3CKIPPS Bits -----------------------------------------------------
T3CKIPPS0        EQU  H'0000'
T3CKIPPS1        EQU  H'0001'
T3CKIPPS2        EQU  H'0002'
T3CKIPPS3        EQU  H'0003'
T3CKIPPS4        EQU  H'0004'


;----- T3GPPS Bits -----------------------------------------------------
T3GPPS0          EQU  H'0000'
T3GPPS1          EQU  H'0001'
T3GPPS2          EQU  H'0002'
T3GPPS3          EQU  H'0003'
T3GPPS4          EQU  H'0004'


;----- T5CKIPPS Bits -----------------------------------------------------
T5CKIPPS0        EQU  H'0000'
T5CKIPPS1        EQU  H'0001'
T5CKIPPS2        EQU  H'0002'
T5CKIPPS3        EQU  H'0003'
T5CKIPPS4        EQU  H'0004'


;----- T5GPPS Bits -----------------------------------------------------
T5GPPS0          EQU  H'0000'
T5GPPS1          EQU  H'0001'
T5GPPS2          EQU  H'0002'
T5GPPS3          EQU  H'0003'
T5GPPS4          EQU  H'0004'


;----- T2INPPS Bits -----------------------------------------------------
T2INPPS0         EQU  H'0000'
T2INPPS1         EQU  H'0001'
T2INPPS2         EQU  H'0002'
T2INPPS3         EQU  H'0003'
T2INPPS4         EQU  H'0004'


;----- T4INPPS Bits -----------------------------------------------------
T4INPPS0         EQU  H'0000'
T4INPPS1         EQU  H'0001'
T4INPPS2         EQU  H'0002'
T4INPPS3         EQU  H'0003'
T4INPPS4         EQU  H'0004'


;----- T6INPPS Bits -----------------------------------------------------
T6INPPS0         EQU  H'0000'
T6INPPS1         EQU  H'0001'
T6INPPS2         EQU  H'0002'
T6INPPS3         EQU  H'0003'
T6INPPS4         EQU  H'0004'


;----- CCP1PPS Bits -----------------------------------------------------
CCP1PPS0         EQU  H'0000'
CCP1PPS1         EQU  H'0001'
CCP1PPS2         EQU  H'0002'
CCP1PPS3         EQU  H'0003'
CCP1PPS4         EQU  H'0004'


;----- CCP2PPS Bits -----------------------------------------------------
CCP2PPS0         EQU  H'0000'
CCP2PPS1         EQU  H'0001'
CCP2PPS2         EQU  H'0002'
CCP2PPS3         EQU  H'0003'
CCP2PPS4         EQU  H'0004'


;----- CCP3PPS Bits -----------------------------------------------------
CCP3PPS0         EQU  H'0000'
CCP3PPS1         EQU  H'0001'
CCP3PPS2         EQU  H'0002'
CCP3PPS3         EQU  H'0003'
CCP3PPS4         EQU  H'0004'


;----- CCP4PPS Bits -----------------------------------------------------
CCP4PPS0         EQU  H'0000'
CCP4PPS1         EQU  H'0001'
CCP4PPS2         EQU  H'0002'
CCP4PPS3         EQU  H'0003'
CCP4PPS4         EQU  H'0004'


;----- SMT1WINPPS Bits -----------------------------------------------------
SMT1WINPPS0      EQU  H'0000'
SMT1WINPPS1      EQU  H'0001'
SMT1WINPPS2      EQU  H'0002'
SMT1WINPPS3      EQU  H'0003'
SMT1WINPPS4      EQU  H'0004'


;----- SMT1SIGPPS Bits -----------------------------------------------------
SMT1SIGPPS0      EQU  H'0000'
SMT1SIGPPS1      EQU  H'0001'
SMT1SIGPPS2      EQU  H'0002'
SMT1SIGPPS3      EQU  H'0003'
SMT1SIGPPS4      EQU  H'0004'


;----- CWG1PPS Bits -----------------------------------------------------
CWG1PPS0         EQU  H'0000'
CWG1PPS1         EQU  H'0001'
CWG1PPS2         EQU  H'0002'
CWG1PPS3         EQU  H'0003'
CWG1PPS4         EQU  H'0004'


;----- CWG2PPS Bits -----------------------------------------------------
CWG2PPS0         EQU  H'0000'
CWG2PPS1         EQU  H'0001'
CWG2PPS2         EQU  H'0002'
CWG2PPS3         EQU  H'0003'
CWG2PPS4         EQU  H'0004'


;----- MDCARLPPS Bits -----------------------------------------------------
MDCARLPPS0       EQU  H'0000'
MDCARLPPS1       EQU  H'0001'
MDCARLPPS2       EQU  H'0002'
MDCARLPPS3       EQU  H'0003'
MDCARLPPS4       EQU  H'0004'


;----- MDCARHPPS Bits -----------------------------------------------------
MDCARHPPS0       EQU  H'0000'
MDCARHPPS1       EQU  H'0001'
MDCARHPPS2       EQU  H'0002'
MDCARHPPS3       EQU  H'0003'
MDCARHPPS4       EQU  H'0004'


;----- MDSRCPPS Bits -----------------------------------------------------
MDSRCPPS0        EQU  H'0000'
MDSRCPPS1        EQU  H'0001'
MDSRCPPS2        EQU  H'0002'
MDSRCPPS3        EQU  H'0003'
MDSRCPPS4        EQU  H'0004'


;----- CLCIN0PPS Bits -----------------------------------------------------
CLCIN0PPS0       EQU  H'0000'
CLCIN0PPS1       EQU  H'0001'
CLCIN0PPS2       EQU  H'0002'
CLCIN0PPS3       EQU  H'0003'
CLCIN0PPS4       EQU  H'0004'


;----- CLCIN1PPS Bits -----------------------------------------------------
CLCIN1PPS0       EQU  H'0000'
CLCIN1PPS1       EQU  H'0001'
CLCIN1PPS2       EQU  H'0002'
CLCIN1PPS3       EQU  H'0003'
CLCIN1PPS4       EQU  H'0004'


;----- CLCIN2PPS Bits -----------------------------------------------------
CLCIN2PPS0       EQU  H'0000'
CLCIN2PPS1       EQU  H'0001'
CLCIN2PPS2       EQU  H'0002'
CLCIN2PPS3       EQU  H'0003'
CLCIN2PPS4       EQU  H'0004'


;----- CLCIN3PPS Bits -----------------------------------------------------
CLCIN3PPS0       EQU  H'0000'
CLCIN3PPS1       EQU  H'0001'
CLCIN3PPS2       EQU  H'0002'
CLCIN3PPS3       EQU  H'0003'
CLCIN3PPS4       EQU  H'0004'


;----- ADACTPPS Bits -----------------------------------------------------
ADACTPPS0        EQU  H'0000'
ADACTPPS1        EQU  H'0001'
ADACTPPS2        EQU  H'0002'
ADACTPPS3        EQU  H'0003'
ADACTPPS4        EQU  H'0004'


;----- SSP1CLKPPS Bits -----------------------------------------------------
SSP1CLKPPS0      EQU  H'0000'
SSP1CLKPPS1      EQU  H'0001'
SSP1CLKPPS2      EQU  H'0002'
SSP1CLKPPS3      EQU  H'0003'
SSP1CLKPPS4      EQU  H'0004'


;----- SSP1DATPPS Bits -----------------------------------------------------
SSP1DATPPS0      EQU  H'0000'
SSP1DATPPS1      EQU  H'0001'
SSP1DATPPS2      EQU  H'0002'
SSP1DATPPS3      EQU  H'0003'
SSP1DATPPS4      EQU  H'0004'


;----- SSP1SSPPS Bits -----------------------------------------------------
SSP1SSPPS0       EQU  H'0000'
SSP1SSPPS1       EQU  H'0001'
SSP1SSPPS2       EQU  H'0002'
SSP1SSPPS3       EQU  H'0003'
SSP1SSPPS4       EQU  H'0004'


;----- SSP2CLKPPS Bits -----------------------------------------------------
SSP2CLKPPS0      EQU  H'0000'
SSP2CLKPPS1      EQU  H'0001'
SSP2CLKPPS2      EQU  H'0002'
SSP2CLKPPS3      EQU  H'0003'
SSP2CLKPPS4      EQU  H'0004'


;----- SSP2DATPPS Bits -----------------------------------------------------
SSP2DATPPS0      EQU  H'0000'
SSP2DATPPS1      EQU  H'0001'
SSP2DATPPS2      EQU  H'0002'
SSP2DATPPS3      EQU  H'0003'
SSP2DATPPS4      EQU  H'0004'


;----- SSP2SSPPS Bits -----------------------------------------------------
SSP2SSPPS0       EQU  H'0000'
SSP2SSPPS1       EQU  H'0001'
SSP2SSPPS2       EQU  H'0002'
SSP2SSPPS3       EQU  H'0003'
SSP2SSPPS4       EQU  H'0004'


;----- RX1DTPPS Bits -----------------------------------------------------
RX1DTPPS0        EQU  H'0000'
RX1DTPPS1        EQU  H'0001'
RX1DTPPS2        EQU  H'0002'
RX1DTPPS3        EQU  H'0003'
RX1DTPPS4        EQU  H'0004'


;----- RX1PPS Bits -----------------------------------------------------
RX1DTPPS0        EQU  H'0000'
RX1DTPPS1        EQU  H'0001'
RX1DTPPS2        EQU  H'0002'
RX1DTPPS3        EQU  H'0003'
RX1DTPPS4        EQU  H'0004'


;----- RXPPS Bits -----------------------------------------------------
RX1DTPPS0        EQU  H'0000'
RX1DTPPS1        EQU  H'0001'
RX1DTPPS2        EQU  H'0002'
RX1DTPPS3        EQU  H'0003'
RX1DTPPS4        EQU  H'0004'


;----- CK1PPS Bits -----------------------------------------------------
TX1CKPPS0        EQU  H'0000'
TX1CKPPS1        EQU  H'0001'
TX1CKPPS2        EQU  H'0002'
TX1CKPPS3        EQU  H'0003'
TX1CKPPS4        EQU  H'0004'


;----- CKPPS Bits -----------------------------------------------------
TX1CKPPS0        EQU  H'0000'
TX1CKPPS1        EQU  H'0001'
TX1CKPPS2        EQU  H'0002'
TX1CKPPS3        EQU  H'0003'
TX1CKPPS4        EQU  H'0004'


;----- TX1CKPPS Bits -----------------------------------------------------
TX1CKPPS0        EQU  H'0000'
TX1CKPPS1        EQU  H'0001'
TX1CKPPS2        EQU  H'0002'
TX1CKPPS3        EQU  H'0003'
TX1CKPPS4        EQU  H'0004'


;----- RA0PPS Bits -----------------------------------------------------
RA0PPS0          EQU  H'0000'
RA0PPS1          EQU  H'0001'
RA0PPS2          EQU  H'0002'
RA0PPS3          EQU  H'0003'
RA0PPS4          EQU  H'0004'
RA0PPS5          EQU  H'0005'


;----- RA1PPS Bits -----------------------------------------------------
RA1PPS0          EQU  H'0000'
RA1PPS1          EQU  H'0001'
RA1PPS2          EQU  H'0002'
RA1PPS3          EQU  H'0003'
RA1PPS4          EQU  H'0004'
RA1PPS5          EQU  H'0005'


;----- RA2PPS Bits -----------------------------------------------------
RA2PPS0          EQU  H'0000'
RA2PPS1          EQU  H'0001'
RA2PPS2          EQU  H'0002'
RA2PPS3          EQU  H'0003'
RA2PPS4          EQU  H'0004'
RA2PPS5          EQU  H'0005'


;----- RA4PPS Bits -----------------------------------------------------
RA4PPS0          EQU  H'0000'
RA4PPS1          EQU  H'0001'
RA4PPS2          EQU  H'0002'
RA4PPS3          EQU  H'0003'
RA4PPS4          EQU  H'0004'
RA4PPS5          EQU  H'0005'


;----- RA5PPS Bits -----------------------------------------------------
RA5PPS0          EQU  H'0000'
RA5PPS1          EQU  H'0001'
RA5PPS2          EQU  H'0002'
RA5PPS3          EQU  H'0003'
RA5PPS4          EQU  H'0004'
RA5PPS5          EQU  H'0005'


;----- RB4PPS Bits -----------------------------------------------------
RB4PPS0          EQU  H'0000'
RB4PPS1          EQU  H'0001'
RB4PPS2          EQU  H'0002'
RB4PPS3          EQU  H'0003'
RB4PPS4          EQU  H'0004'
RB4PPS5          EQU  H'0005'


;----- RB5PPS Bits -----------------------------------------------------
RB5PPS0          EQU  H'0000'
RB5PPS1          EQU  H'0001'
RB5PPS2          EQU  H'0002'
RB5PPS3          EQU  H'0003'
RB5PPS4          EQU  H'0004'
RB5PPS5          EQU  H'0005'


;----- RB6PPS Bits -----------------------------------------------------
RB6PPS0          EQU  H'0000'
RB6PPS1          EQU  H'0001'
RB6PPS2          EQU  H'0002'
RB6PPS3          EQU  H'0003'
RB6PPS4          EQU  H'0004'
RB6PPS5          EQU  H'0005'


;----- RB7PPS Bits -----------------------------------------------------
RB7PPS0          EQU  H'0000'
RB7PPS1          EQU  H'0001'
RB7PPS2          EQU  H'0002'
RB7PPS3          EQU  H'0003'
RB7PPS4          EQU  H'0004'
RB7PPS5          EQU  H'0005'


;----- RC0PPS Bits -----------------------------------------------------
RC0PPS0          EQU  H'0000'
RC0PPS1          EQU  H'0001'
RC0PPS2          EQU  H'0002'
RC0PPS3          EQU  H'0003'
RC0PPS4          EQU  H'0004'
RC0PPS5          EQU  H'0005'


;----- RC1PPS Bits -----------------------------------------------------
RC1PPS0          EQU  H'0000'
RC1PPS1          EQU  H'0001'
RC1PPS2          EQU  H'0002'
RC1PPS3          EQU  H'0003'
RC1PPS4          EQU  H'0004'
RC1PPS5          EQU  H'0005'


;----- RC2PPS Bits -----------------------------------------------------
RC2PPS0          EQU  H'0000'
RC2PPS1          EQU  H'0001'
RC2PPS2          EQU  H'0002'
RC2PPS3          EQU  H'0003'
RC2PPS4          EQU  H'0004'
RC2PPS5          EQU  H'0005'


;----- RC3PPS Bits -----------------------------------------------------
RC3PPS0          EQU  H'0000'
RC3PPS1          EQU  H'0001'
RC3PPS2          EQU  H'0002'
RC3PPS3          EQU  H'0003'
RC3PPS4          EQU  H'0004'
RC3PPS5          EQU  H'0005'


;----- RC4PPS Bits -----------------------------------------------------
RC4PPS0          EQU  H'0000'
RC4PPS1          EQU  H'0001'
RC4PPS2          EQU  H'0002'
RC4PPS3          EQU  H'0003'
RC4PPS4          EQU  H'0004'
RC4PPS5          EQU  H'0005'


;----- RC5PPS Bits -----------------------------------------------------
RC5PPS0          EQU  H'0000'
RC5PPS1          EQU  H'0001'
RC5PPS2          EQU  H'0002'
RC5PPS3          EQU  H'0003'
RC5PPS4          EQU  H'0004'
RC5PPS5          EQU  H'0005'


;----- RC6PPS Bits -----------------------------------------------------
RC6PPS0          EQU  H'0000'
RC6PPS1          EQU  H'0001'
RC6PPS2          EQU  H'0002'
RC6PPS3          EQU  H'0003'
RC6PPS4          EQU  H'0004'
RC6PPS5          EQU  H'0005'


;----- RC7PPS Bits -----------------------------------------------------
RC7PPS0          EQU  H'0000'
RC7PPS1          EQU  H'0001'
RC7PPS2          EQU  H'0002'
RC7PPS3          EQU  H'0003'
RC7PPS4          EQU  H'0004'
RC7PPS5          EQU  H'0005'


;----- ANSELA Bits -----------------------------------------------------
ANSA0            EQU  H'0000'
ANSA1            EQU  H'0001'
ANSA2            EQU  H'0002'
ANSA4            EQU  H'0004'
ANSA5            EQU  H'0005'


;----- WPUA Bits -----------------------------------------------------
WPUA0            EQU  H'0000'
WPUA1            EQU  H'0001'
WPUA2            EQU  H'0002'
WPUA3            EQU  H'0003'
WPUA4            EQU  H'0004'
WPUA5            EQU  H'0005'


;----- ODCONA Bits -----------------------------------------------------
ODCA0            EQU  H'0000'
ODCA1            EQU  H'0001'
ODCA2            EQU  H'0002'
ODCA4            EQU  H'0004'
ODCA5            EQU  H'0005'


;----- SLRCONA Bits -----------------------------------------------------
SLRA0            EQU  H'0000'
SLRA1            EQU  H'0001'
SLRA2            EQU  H'0002'
SLRA4            EQU  H'0004'
SLRA5            EQU  H'0005'


;----- INLVLA Bits -----------------------------------------------------
INLVLA0          EQU  H'0000'
INLVLA1          EQU  H'0001'
INLVLA2          EQU  H'0002'
INLVLA3          EQU  H'0003'
INLVLA4          EQU  H'0004'
INLVLA5          EQU  H'0005'


;----- IOCAP Bits -----------------------------------------------------
IOCAP0           EQU  H'0000'
IOCAP1           EQU  H'0001'
IOCAP2           EQU  H'0002'
IOCAP3           EQU  H'0003'
IOCAP4           EQU  H'0004'
IOCAP5           EQU  H'0005'


;----- IOCAN Bits -----------------------------------------------------
IOCAN0           EQU  H'0000'
IOCAN1           EQU  H'0001'
IOCAN2           EQU  H'0002'
IOCAN3           EQU  H'0003'
IOCAN4           EQU  H'0004'
IOCAN5           EQU  H'0005'


;----- IOCAF Bits -----------------------------------------------------
IOCAF0           EQU  H'0000'
IOCAF1           EQU  H'0001'
IOCAF2           EQU  H'0002'
IOCAF3           EQU  H'0003'
IOCAF4           EQU  H'0004'
IOCAF5           EQU  H'0005'


;----- ANSELB Bits -----------------------------------------------------
ANSB4            EQU  H'0004'
ANSB5            EQU  H'0005'
ANSB6            EQU  H'0006'
ANSB7            EQU  H'0007'


;----- WPUB Bits -----------------------------------------------------
WPUB4            EQU  H'0004'
WPUB5            EQU  H'0005'
WPUB6            EQU  H'0006'
WPUB7            EQU  H'0007'


;----- ODCONB Bits -----------------------------------------------------
ODCB4            EQU  H'0004'
ODCB5            EQU  H'0005'
ODCB6            EQU  H'0006'
ODCB7            EQU  H'0007'


;----- SLRCONB Bits -----------------------------------------------------
SLRB4            EQU  H'0004'
SLRB5            EQU  H'0005'
SLRB6            EQU  H'0006'
SLRB7            EQU  H'0007'


;----- INLVLB Bits -----------------------------------------------------
INLVLB4          EQU  H'0004'
INLVLB5          EQU  H'0005'
INLVLB6          EQU  H'0006'
INLVLB7          EQU  H'0007'


;----- IOCBP Bits -----------------------------------------------------
IOCBP4           EQU  H'0004'
IOCBP5           EQU  H'0005'
IOCBP6           EQU  H'0006'
IOCBP7           EQU  H'0007'


;----- IOCBN Bits -----------------------------------------------------
IOCBN4           EQU  H'0004'
IOCBN5           EQU  H'0005'
IOCBN6           EQU  H'0006'
IOCBN7           EQU  H'0007'


;----- IOCBF Bits -----------------------------------------------------
IOCBF4           EQU  H'0004'
IOCBF5           EQU  H'0005'
IOCBF6           EQU  H'0006'
IOCBF7           EQU  H'0007'


;----- ANSELC Bits -----------------------------------------------------
ANSC0            EQU  H'0000'
ANSC1            EQU  H'0001'
ANSC2            EQU  H'0002'
ANSC3            EQU  H'0003'
ANSC4            EQU  H'0004'
ANSC5            EQU  H'0005'
ANSC6            EQU  H'0006'
ANSC7            EQU  H'0007'


;----- WPUC Bits -----------------------------------------------------
WPUC0            EQU  H'0000'
WPUC1            EQU  H'0001'
WPUC2            EQU  H'0002'
WPUC3            EQU  H'0003'
WPUC4            EQU  H'0004'
WPUC5            EQU  H'0005'
WPUC6            EQU  H'0006'
WPUC7            EQU  H'0007'


;----- ODCONC Bits -----------------------------------------------------
ODCC0            EQU  H'0000'
ODCC1            EQU  H'0001'
ODCC2            EQU  H'0002'
ODCC3            EQU  H'0003'
ODCC4            EQU  H'0004'
ODCC5            EQU  H'0005'
ODCC6            EQU  H'0006'
ODCC7            EQU  H'0007'


;----- SLRCONC Bits -----------------------------------------------------
SLRC0            EQU  H'0000'
SLRC1            EQU  H'0001'
SLRC2            EQU  H'0002'
SLRC3            EQU  H'0003'
SLRC4            EQU  H'0004'
SLRC5            EQU  H'0005'
SLRC6            EQU  H'0006'
SLRC7            EQU  H'0007'


;----- INLVLC Bits -----------------------------------------------------
INLVLC0          EQU  H'0000'
INLVLC1          EQU  H'0001'
INLVLC2          EQU  H'0002'
INLVLC3          EQU  H'0003'
INLVLC4          EQU  H'0004'
INLVLC5          EQU  H'0005'
INLVLC6          EQU  H'0006'
INLVLC7          EQU  H'0007'


;----- IOCCP Bits -----------------------------------------------------
IOCCP0           EQU  H'0000'
IOCCP1           EQU  H'0001'
IOCCP2           EQU  H'0002'
IOCCP3           EQU  H'0003'
IOCCP4           EQU  H'0004'
IOCCP5           EQU  H'0005'
IOCCP6           EQU  H'0006'
IOCCP7           EQU  H'0007'


;----- IOCCN Bits -----------------------------------------------------
IOCCN0           EQU  H'0000'
IOCCN1           EQU  H'0001'
IOCCN2           EQU  H'0002'
IOCCN3           EQU  H'0003'
IOCCN4           EQU  H'0004'
IOCCN5           EQU  H'0005'
IOCCN6           EQU  H'0006'
IOCCN7           EQU  H'0007'


;----- IOCCF Bits -----------------------------------------------------
IOCCF0           EQU  H'0000'
IOCCF1           EQU  H'0001'
IOCCF2           EQU  H'0002'
IOCCF3           EQU  H'0003'
IOCCF4           EQU  H'0004'
IOCCF5           EQU  H'0005'
IOCCF6           EQU  H'0006'
IOCCF7           EQU  H'0007'


;----- STKPTR Bits -----------------------------------------------------
STKPTR0          EQU  H'0000'
STKPTR1          EQU  H'0001'
STKPTR2          EQU  H'0002'
STKPTR3          EQU  H'0003'
STKPTR4          EQU  H'0004'


;----- TOSL Bits -----------------------------------------------------
TOSL0            EQU  H'0000'
TOSL1            EQU  H'0001'
TOSL2            EQU  H'0002'
TOSL3            EQU  H'0003'
TOSL4            EQU  H'0004'
TOSL5            EQU  H'0005'
TOSL6            EQU  H'0006'
TOSL7            EQU  H'0007'


;----- TOSH Bits -----------------------------------------------------
TOSH0            EQU  H'0000'
TOSH1            EQU  H'0001'
TOSH2            EQU  H'0002'
TOSH3            EQU  H'0003'
TOSH4            EQU  H'0004'
TOSH5            EQU  H'0005'
TOSH6            EQU  H'0006'
TOSH7            EQU  H'0007'



;==========================================================================
;
;       RAM Definitions
;
;==========================================================================
       __MAXRAM  H'1FFF'
       __BADRAM  H'000F'
       __BADRAM  H'0010'
       __BADRAM  H'0011'
       __BADRAM  H'0015'
       __BADRAM  H'0016'
       __BADRAM  H'0017'
       __BADRAM  H'001B'
       __BADRAM  H'001C'
       __BADRAM  H'001D'
       __BADRAM  H'001E'-H'001F'
       __BADRAM  H'0193'-H'0195'
       __BADRAM  H'019D'-H'019F'
       __BADRAM  H'029E'
       __BADRAM  H'031C'-H'031F'
       __BADRAM  H'038F'
       __BADRAM  H'0393'-H'039F'
       __BADRAM  H'040C'-H'041F'
       __BADRAM  H'049E'-H'049F'
       __BADRAM  H'050C'-H'051F'
       __BADRAM  H'0594'-H'059B'
       __BADRAM  H'0615'
       __BADRAM  H'061F'
       __BADRAM  H'068C'-H'069F'
       __BADRAM  H'0715'
       __BADRAM  H'071F'
       __BADRAM  H'078C'-H'0795'
       __BADRAM  H'079E'-H'079F'
       __BADRAM  H'0815'-H'0819'
       __BADRAM  H'0894'
       __BADRAM  H'089C'-H'089F'
       __BADRAM  H'090D'
       __BADRAM  H'0910'-H'091E'
       __BADRAM  H'098C'-H'098E'
       __BADRAM  H'0998'-H'099F'
       __BADRAM  H'0A0C'-H'0A1F'
       __BADRAM  H'0A8C'-H'0A9F'
       __BADRAM  H'0B0C'-H'0B1F'
       __BADRAM  H'0B8C'-H'0B9F'
       __BADRAM  H'0C0C'-H'0C1F'
       __BADRAM  H'0C8C'-H'0C9F'
       __BADRAM  H'0CC0'-H'0CEF'
       __BADRAM  H'0D0C'-H'0D1F'
       __BADRAM  H'0D20'-H'0D6F'
       __BADRAM  H'0D8C'-H'0D9F'
       __BADRAM  H'0DA0'-H'0DEF'
       __BADRAM  H'0E0C'-H'0E1F'
       __BADRAM  H'0E20'-H'0E6F'
       __BADRAM  H'0E8C'-H'0E9F'
       __BADRAM  H'0EA0'-H'0EEF'
       __BADRAM  H'0F0C'-H'0F1F'
       __BADRAM  H'0F20'-H'0F6F'
       __BADRAM  H'0F8C'-H'0F9F'
       __BADRAM  H'0FA0'-H'0FEF'
       __BADRAM  H'100C'-H'101F'
       __BADRAM  H'1020'-H'106F'
       __BADRAM  H'108C'-H'109F'
       __BADRAM  H'10A0'-H'10EF'
       __BADRAM  H'110C'-H'111F'
       __BADRAM  H'1120'-H'116F'
       __BADRAM  H'118C'-H'119F'
       __BADRAM  H'11A0'-H'11EF'
       __BADRAM  H'120C'-H'121F'
       __BADRAM  H'1220'-H'126F'
       __BADRAM  H'128C'-H'129F'
       __BADRAM  H'12A0'-H'12EF'
       __BADRAM  H'130C'-H'131F'
       __BADRAM  H'1320'-H'136F'
       __BADRAM  H'138C'-H'139F'
       __BADRAM  H'13A0'-H'13EF'
       __BADRAM  H'140C'-H'141F'
       __BADRAM  H'1420'-H'146F'
       __BADRAM  H'148C'-H'149F'
       __BADRAM  H'14A0'-H'14EF'
       __BADRAM  H'150C'-H'151F'
       __BADRAM  H'1520'-H'156F'
       __BADRAM  H'158C'-H'159F'
       __BADRAM  H'15A0'-H'15EF'
       __BADRAM  H'160C'-H'161F'
       __BADRAM  H'1620'-H'166F'
       __BADRAM  H'168C'-H'169F'
       __BADRAM  H'16A0'-H'16EF'
       __BADRAM  H'170C'-H'171F'
       __BADRAM  H'1720'-H'176F'
       __BADRAM  H'178C'-H'179F'
       __BADRAM  H'17A0'-H'17EF'
       __BADRAM  H'180C'-H'181F'
       __BADRAM  H'1820'-H'186F'
       __BADRAM  H'188C'-H'189F'
       __BADRAM  H'18A0'-H'18EF'
       __BADRAM  H'190C'-H'191F'
       __BADRAM  H'1920'-H'196F'
       __BADRAM  H'198C'-H'199F'
       __BADRAM  H'19A0'-H'19EF'
       __BADRAM  H'1A0C'-H'1A1F'
       __BADRAM  H'1A20'-H'1A6F'
       __BADRAM  H'1A8C'-H'1A9F'
       __BADRAM  H'1AA0'-H'1AEF'
       __BADRAM  H'1B0C'-H'1B1F'
       __BADRAM  H'1B20'-H'1B6F'
       __BADRAM  H'1B8C'-H'1B9F'
       __BADRAM  H'1BA0'-H'1BEF'
       __BADRAM  H'1C0C'-H'1C1F'
       __BADRAM  H'1C20'-H'1C6F'
       __BADRAM  H'1C8C'-H'1C9F'
       __BADRAM  H'1CA0'-H'1CEF'
       __BADRAM  H'1D0C'-H'1D1F'
       __BADRAM  H'1D20'-H'1D6F'
       __BADRAM  H'1D8C'-H'1D9F'
       __BADRAM  H'1DA0'-H'1DEF'
       __BADRAM  H'1E0C'-H'1E0E'
       __BADRAM  H'1E38'-H'1E6F'
       __BADRAM  H'1E8C'-H'1E8E'
       __BADRAM  H'1E98'-H'1E9B'
       __BADRAM  H'1E9F'-H'1EA0'
       __BADRAM  H'1EA5'-H'1EA8'
       __BADRAM  H'1EAB'-H'1EB0'
       __BADRAM  H'1EB3'-H'1EB7'
       __BADRAM  H'1EBF'-H'1EC2'
       __BADRAM  H'1EC4'
       __BADRAM  H'1ECD'-H'1EEF'
       __BADRAM  H'1F0C'-H'1F0F'
       __BADRAM  H'1F13'
       __BADRAM  H'1F16'-H'1F1B'
       __BADRAM  H'1F28'-H'1F37'
       __BADRAM  H'1F40'-H'1F42'
       __BADRAM  H'1F4B'-H'1F4D'
       __BADRAM  H'1F56'-H'1F6F'
       __BADRAM  H'1F8C'-H'1FB7'
       __BADRAM  H'1FB8'-H'1FE3'
       __BADRAM  H'1FEC'

;==========================================================================
;
;       Configuration Bits
;
;   NAME            Address
;   CONFIG1           8007h
;   CONFIG2           8008h
;   CONFIG3           8009h
;   CONFIG4           800Ah
;   CONFIG5           800Bh
;
;==========================================================================

; The following is an assignment of address values for all of the
; configuration registers for the purpose of table reads
_CONFIG1        EQU  H'8007'
_CONFIG2        EQU  H'8008'
_CONFIG3        EQU  H'8009'
_CONFIG4        EQU  H'800A'
_CONFIG5        EQU  H'800B'

;----- CONFIG1 Options --------------------------------------------------
_FEXTOSC_LP          EQU  H'3FF8'; LP (crystal oscillator) optimized for 32.768kHz; PFM set to low power
_FEXTOSC_XT          EQU  H'3FF9'; XT (crystal oscillator) above 500kHz, below 4MHz; PFM set to medium power
_FEXTOSC_HS          EQU  H'3FFA'; HS (crystal oscillator) above 4MHz; PFM set to high power
_FEXTOSC_RESERVED    EQU  H'3FFB'; Reserved
_FEXTOSC_OFF         EQU  H'3FFC'; Oscillator not enabled
_FEXTOSC_ECL         EQU  H'3FFD'; EC below 500kHz; PFM set to low power
_FEXTOSC_ECM         EQU  H'3FFE'; EC for 500kHz to 8MHz; PFM set to medium power
_FEXTOSC_ECH         EQU  H'3FFF'; EC above 8MHz; PFM set to high power

_RSTOSC_HFINT32      EQU  H'3F8F'; HFINTOSC with OSCFRQ= 32 MHz and CDIV = 1:1
_RSTOSC_HFINTPLL     EQU  H'3F9F'; HFINTOSC with 2x PLL, with OSCFRQ = 16 MHz and CDIV = 1:1 (FOSC = 32 MHz)
_RSTOSC_EXT4X        EQU  H'3FAF'; EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits
_RSTOSC_RESERVED     EQU  H'3FBF'; Reserved
_RSTOSC_SOSC         EQU  H'3FCF'; SOSC
_RSTOSC_LFINT        EQU  H'3FDF'; LFINTOSC
_RSTOSC_HFINT1       EQU  H'3FEF'; HFINTOSC (1MHz)
_RSTOSC_EXT1X        EQU  H'3FFF'; EXTOSC operating per FEXTOSC bits

_CLKOUTEN_ON         EQU  H'3EFF'; CLKOUT function is enabled; FOSC/4 clock appears at OSC2
_CLKOUTEN_OFF        EQU  H'3FFF'; CLKOUT function is disabled; i/o or oscillator function on OSC2

_CSWEN_OFF           EQU  H'37FF'; The NOSC and NDIV bits cannot be changed by user software
_CSWEN_ON            EQU  H'3FFF'; Writing to NOSC and NDIV is allowed

_FCMEN_OFF           EQU  H'1FFF'; FSCM timer disabled
_FCMEN_ON            EQU  H'3FFF'; FSCM timer enabled

;----- CONFIG2 Options --------------------------------------------------
_MCLRE_OFF           EQU  H'3FFE'; MCLR pin function is port defined function
_MCLRE_ON            EQU  H'3FFF'; MCLR pin is Master Clear function

_PWRTS_PWRT_1        EQU  H'3FF9'; PWRT set at 1 ms
_PWRTS_PWRT_16       EQU  H'3FFB'; PWRT set at 16 ms
_PWRTS_PWRT_64       EQU  H'3FFD'; PWRT set at 64 ms
_PWRTS_OFF           EQU  H'3FFF'; PWRT disabled

_LPBOREN_ON          EQU  H'3FDF'; ULPBOR enabled
_LPBOREN_OFF         EQU  H'3FFF'; ULPBOR disabled

_BOREN_OFF           EQU  H'3F3F'; Brown-out reset disabled
_BOREN_SBOREN        EQU  H'3F7F'; Brown-out reset enabled according to SBOREN bit
_BOREN_NSLEEP        EQU  H'3FBF'; Brown-out Reset enabled while running, disabled in sleep; SBOREN is ignored
_BOREN_ON            EQU  H'3FFF'; Brown-out Reset Enabled, SBOREN bit is ignored

_BORV_HI             EQU  H'3DFF'; Brown-out Reset Voltage (VBOR) is set to 2.7V
_BORV_LO             EQU  H'3FFF'; Brown-out Reset Voltage (VBOR) set to 2.45V

_ZCD_ON              EQU  H'3BFF'; Zero-cross detect circuit is always enabled
_ZCD_OFF             EQU  H'3FFF'; Zero-cross detect circuit is disabled at POR.

_ZCDDIS_ON           EQU  H'3BFF'; Zero-cross detect circuit is always enabled
_ZCDDIS_OFF          EQU  H'3FFF'; Zero-cross detect circuit is disabled at POR.

_PPS1WAY_OFF         EQU  H'37FF'; The PPSLOCK bit can be set and cleared repeatedly by software
_PPS1WAY_ON          EQU  H'3FFF'; The PPSLOCK bit can be cleared and set only once in software

_STVREN_OFF          EQU  H'2FFF'; Stack Overflow or Underflow will not cause a reset
_STVREN_ON           EQU  H'3FFF'; Stack Overflow or Underflow will cause a reset

;----- CONFIG3 Options --------------------------------------------------
_WDTCPS_WDTCPS_0     EQU  H'3FE0'; Divider ratio 1:32
_WDTCPS_WDTCPS_1     EQU  H'3FE1'; Divider ratio 1:64
_WDTCPS_WDTCPS_2     EQU  H'3FE2'; Divider ratio 1:128
_WDTCPS_WDTCPS_3     EQU  H'3FE3'; Divider ratio 1:256
_WDTCPS_WDTCPS_4     EQU  H'3FE4'; Divider ratio 1:512
_WDTCPS_WDTCPS_5     EQU  H'3FE5'; Divider ratio 1:1024
_WDTCPS_WDTCPS_6     EQU  H'3FE6'; Divider ratio 1:2048
_WDTCPS_WDTCPS_7     EQU  H'3FE7'; Divider ratio 1:4096
_WDTCPS_WDTCPS_8     EQU  H'3FE8'; Divider ratio 1:8192
_WDTCPS_WDTCPS_9     EQU  H'3FE9'; Divider ratio 1:16384
_WDTCPS_WDTCPS_10    EQU  H'3FEA'; Divider ratio 1:32768
_WDTCPS_WDTCPS_11    EQU  H'3FEB'; Divider ratio 1:65536
_WDTCPS_WDTCPS_12    EQU  H'3FEC'; Divider ratio 1:131072
_WDTCPS_WDTCPS_13    EQU  H'3FED'; Divider ratio 1:262144
_WDTCPS_WDTCPS_14    EQU  H'3FEE'; Divider ratio 1:524299
_WDTCPS_WDTCPS_15    EQU  H'3FEF'; Divider ratio 1:1048576
_WDTCPS_WDTCPS_16    EQU  H'3FF0'; Divider ratio 1:2097152
_WDTCPS_WDTCPS_17    EQU  H'3FF1'; Divider ratio 1:4194304
_WDTCPS_WDTCPS_18    EQU  H'3FF2'; Divider ratio 1:8388608
_WDTCPS_WDTCPS_19    EQU  H'3FF3'; Divider ratio 1:32
_WDTCPS_WDTCPS_20    EQU  H'3FF4'; Divider ratio 1:32
_WDTCPS_WDTCPS_21    EQU  H'3FF5'; Divider ratio 1:32
_WDTCPS_WDTCPS_22    EQU  H'3FF6'; Divider ratio 1:32
_WDTCPS_WDTCPS_23    EQU  H'3FF7'; Divider ratio 1:32
_WDTCPS_WDTCPS_24    EQU  H'3FF8'; Divider ratio 1:32
_WDTCPS_WDTCPS_25    EQU  H'3FF9'; Divider ratio 1:32
_WDTCPS_WDTCPS_26    EQU  H'3FFA'; Divider ratio 1:32
_WDTCPS_WDTCPS_27    EQU  H'3FFB'; Divider ratio 1:32
_WDTCPS_WDTCPS_28    EQU  H'3FFC'; Divider ratio 1:32
_WDTCPS_WDTCPS_29    EQU  H'3FFD'; Divider ratio 1:32
_WDTCPS_WDTCPS_30    EQU  H'3FFE'; Divider ratio 1:32
_WDTCPS_WDTCPS_31    EQU  H'3FFF'; Divider ratio 1:65536; software control of WDTPS

_WDTE_OFF            EQU  H'3F9F'; WDT Disabled, SWDTEN is ignored
_WDTE_SWDTEN         EQU  H'3FBF'; WDT enabled/disabled by SWDTEN bit in WDTCON0
_WDTE_NSLEEP         EQU  H'3FDF'; WDT enabled while sleep=0, suspended when sleep=1; SWDTEN ignored
_WDTE_ON             EQU  H'3FFF'; WDT enabled regardless of sleep; SWDTEN ignored

_WDTCWS_WDTCWS_0     EQU  H'38FF'; window delay = 87.5 percent of time; no software control; keyed access required
_WDTCWS_WDTCWS_1     EQU  H'39FF'; window delay = 75 percent of time; no software control; keyed access required
_WDTCWS_WDTCWS_2     EQU  H'3AFF'; window delay = 62.5 percent of time; no software control; keyed access required
_WDTCWS_WDTCWS_3     EQU  H'3BFF'; window delay = 50 percent of time; no software control; keyed access required
_WDTCWS_WDTCWS_4     EQU  H'3CFF'; window delay = 37.5 percent of time; no software control; keyed access required
_WDTCWS_WDTCWS_5     EQU  H'3DFF'; window delay = 25 percent of time; no software control; keyed access required
_WDTCWS_WDTCWS_6     EQU  H'3EFF'; window always open (100%); no software control; keyed access required
_WDTCWS_WDTCWS_7     EQU  H'3FFF'; window always open (100%); software control; keyed access not required

_WDTCCS_LFINTOSC     EQU  H'07FF'; WDT reference clock is the 31.0kHz LFINTOSC output
_WDTCCS_HFINTOSC     EQU  H'0FFF'; WDT reference clock is the 31.25 kHz HFINTOSC
_WDTCCS_SOSC         EQU  H'17FF'; WDT reference clock is the 32kHz secondary oscillator
_WDTCCS_SC           EQU  H'3FFF'; Software Control

;----- CONFIG4 Options --------------------------------------------------
_BBSIZE_BB64K        EQU  H'3FF8'; * half of user program memory
_BBSIZE_BB32K        EQU  H'3FF9'; * half of user program memory
_BBSIZE_BB16K        EQU  H'3FFA'; * half of user program memory
_BBSIZE_BB8K         EQU  H'3FFB'; 8192 words boot block size
_BBSIZE_BB4K         EQU  H'3FFC'; 4096 words boot block size
_BBSIZE_BB2K         EQU  H'3FFD'; 2048 words boot block size
_BBSIZE_BB1K         EQU  H'3FFE'; 1024 words boot block size
_BBSIZE_BB512        EQU  H'3FFF'; 512 words boot block size

_BBEN_ON             EQU  H'3FF7'; Boot Block enabled
_BBEN_OFF            EQU  H'3FFF'; Boot Block disabled

_SAFEN_ON            EQU  H'3FEF'; SAF enabled
_SAFEN_OFF           EQU  H'3FFF'; SAF disabled

_WRTAPP_ON           EQU  H'3F7F'; Application Block write protected
_WRTAPP_OFF          EQU  H'3FFF'; Application Block not write protected

_WRTB_ON             EQU  H'3EFF'; Boot Block write protected
_WRTB_OFF            EQU  H'3FFF'; Boot Block not write protected

_WRTC_ON             EQU  H'3DFF'; Configuration Register write protected
_WRTC_OFF            EQU  H'3FFF'; Configuration Register not write protected

_WRTD_ON             EQU  H'3BFF'; Data EEPROM write protected
_WRTD_OFF            EQU  H'3FFF'; Data EEPROM NOT write protected

_WRTSAF_ON           EQU  H'37FF'; SAF write protected
_WRTSAF_OFF          EQU  H'3FFF'; SAF not write protected

_LVP_OFF             EQU  H'1FFF'; High Voltage on MCLR/Vpp must be used for programming
_LVP_ON              EQU  H'3FFF'; Low Voltage programming enabled. MCLR/Vpp pin function is MCLR.

;----- CONFIG5 Options --------------------------------------------------
_CP_ON               EQU  H'3FFE'; UserNVM code protection enabled
_CP_OFF              EQU  H'3FFF'; UserNVM code protection disabled

;----- DEVID Equates --------------------------------------------------
_DEVID1          EQU  H'8006'

;----- IDLOC Equates --------------------------------------------------
_IDLOC0          EQU  H'8000'
_IDLOC1          EQU  H'8001'
_IDLOC2          EQU  H'8002'
_IDLOC3          EQU  H'8003'

        LIST
