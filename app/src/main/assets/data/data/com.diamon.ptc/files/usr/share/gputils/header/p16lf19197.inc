        LIST

;==========================================================================
; Build date : Mar 21 2017
;  MPASM PIC16LF19197 processor include
; 
;  (c) Copyright 1999-2017 Microchip Technology, All rights reserved
;==========================================================================

        NOLIST

;==========================================================================
;  This header file defines configurations, registers, and other useful
;  bits of information for the PIC16LF19197 microcontroller.  These names
;  are taken to match the data sheets as closely as possible.
;
;  Note that the processor must be selected before this file is included.
;  The processor may be selected the following ways:
;
;       1. Command line switch:
;               C:\MPASM MYFILE.ASM /PIC16LF19197
;       2. LIST directive in the source file
;               LIST   P=PIC16LF19197
;       3. Processor Type entry in the MPASM full-screen interface
;       4. Setting the processor in the MPLAB Project Dialog
;==========================================================================
;;;; Begin: Added in gputils

;==========================================================================
;
;       Gputils Specific Revision History
;
;==========================================================================

;       13 May 2017  Added the _DEBUG_ON and _DEBUG_OFF config options.
;;;; End: Added in gputils

;==========================================================================
;
;       Verify Processor
;
;==========================================================================
        IFNDEF __16LF19197
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
PORTD            EQU  H'000F'
PORTE            EQU  H'0010'
PORTF            EQU  H'0011'
TRISA            EQU  H'0012'
TRISB            EQU  H'0013'
TRISC            EQU  H'0014'
TRISD            EQU  H'0015'
TRISE            EQU  H'0016'
TRISF            EQU  H'0017'
LATA             EQU  H'0018'
LATB             EQU  H'0019'
LATC             EQU  H'001A'
LATD             EQU  H'001B'
LATE             EQU  H'001C'
LATF             EQU  H'001D'
ADCPCON0         EQU  H'001F'

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

;-----Bank4------------------
TMR1             EQU  H'020C'
TMR1L            EQU  H'020C'
TMR1H            EQU  H'020D'
T1CON            EQU  H'020E'
PR1              EQU  H'020F'
T1GCON           EQU  H'020F'
T1GATE           EQU  H'0210'
TMR1GATE         EQU  H'0210'
T1CLK            EQU  H'0211'
TMR1CLK          EQU  H'0211'
CCPTMRS0         EQU  H'021E'

;-----Bank5------------------
T2TMR            EQU  H'028C'
TMR2             EQU  H'028C'
PR2              EQU  H'028D'
T2PR             EQU  H'028D'
T2CON            EQU  H'028E'
T2HLT            EQU  H'028F'
T2CLK            EQU  H'0290'
T2CLKCON         EQU  H'0290'
T2RST            EQU  H'0291'
T4TMR            EQU  H'0292'
TMR4             EQU  H'0292'
PR4              EQU  H'0293'
T4PR             EQU  H'0293'
T4CON            EQU  H'0294'
T4HLT            EQU  H'0295'
T4CLK            EQU  H'0296'
T4CLKCON         EQU  H'0296'
T4RST            EQU  H'0297'

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
PWM3DC           EQU  H'0314'
PWM3DCL          EQU  H'0314'
PWM3DCH          EQU  H'0315'
PWM3CON          EQU  H'0316'
PWM4DC           EQU  H'0318'
PWM4DCL          EQU  H'0318'
PWM4DCH          EQU  H'0319'
PWM4CON          EQU  H'031A'

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
TMR0             EQU  H'059C'
TMR0L            EQU  H'059C'
PR0              EQU  H'059D'
TMR0H            EQU  H'059D'
T0CON0           EQU  H'059E'
T0CON1           EQU  H'059F'

;-----Bank12------------------
CWG1CLKCON       EQU  H'060C'
CWG1ISM          EQU  H'060D'
CWG1DBR          EQU  H'060E'
CWG1DBF          EQU  H'060F'
CWG1CON0         EQU  H'0610'
CWG1CON1         EQU  H'0611'
CWG1AS0          EQU  H'0612'
CWG1AS1          EQU  H'0613'
CWG1STR          EQU  H'0614'

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

;-----Bank16------------------
WDTCON0          EQU  H'080C'
WDTCON1          EQU  H'080D'
WDTPSL           EQU  H'080E'
WDTPSH           EQU  H'080F'
WDTTMR           EQU  H'0810'
BORCON           EQU  H'0811'
PCON0            EQU  H'0813'
PCON1            EQU  H'0814'
NVMADRL          EQU  H'081A'
NVMADRH          EQU  H'081B'
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
ACTCON           EQU  H'0894'

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
CM1NSEL          EQU  H'0992'
CM1PSEL          EQU  H'0993'
CM2CON0          EQU  H'0994'
CM2CON1          EQU  H'0995'
CM2NSEL          EQU  H'0996'
CM2PSEL          EQU  H'0997'

;-----Bank20------------------
RC2REG           EQU  H'0A19'
RCREG2           EQU  H'0A19'
TX2REG           EQU  H'0A1A'
TXREG2           EQU  H'0A1A'
SP2BRG           EQU  H'0A1B'
SP2BRGL          EQU  H'0A1B'
SPBRG2           EQU  H'0A1B'
SP2BRGH          EQU  H'0A1C'
SPBRGH2          EQU  H'0A1C'
RC2STA           EQU  H'0A1D'
RCSTA2           EQU  H'0A1D'
TX2STA           EQU  H'0A1E'
TXSTA2           EQU  H'0A1E'
BAUD2CON         EQU  H'0A1F'
BAUDCON2         EQU  H'0A1F'
BAUDCTL2         EQU  H'0A1F'

;-----Bank24------------------
RTCCON           EQU  H'0C0C'
RTCCAL           EQU  H'0C0D'
ALRMCON          EQU  H'0C0E'
ALRMRPT          EQU  H'0C0F'
YEAR             EQU  H'0C10'
MONTH            EQU  H'0C11'
WEEKDAY          EQU  H'0C12'
DAY              EQU  H'0C13'
HOURS            EQU  H'0C14'
MINUTES          EQU  H'0C15'
SECONDS          EQU  H'0C16'
ALRMMTH          EQU  H'0C17'
ALRMWD           EQU  H'0C18'
ALRMDAY          EQU  H'0C19'
ALRMHR           EQU  H'0C1A'
ALRMMIN          EQU  H'0C1B'
ALRMSEC          EQU  H'0C1C'

;-----Bank25------------------
PORTG            EQU  H'0C8C'
PORTH            EQU  H'0C8D'
TRISG            EQU  H'0C8E'
TRISH            EQU  H'0C8F'
LATG             EQU  H'0C90'
LATH             EQU  H'0C91'

;-----Bank29------------------
VB0GPR           EQU  H'0E8C'
VB1GPR           EQU  H'0E8D'
VB2GPR           EQU  H'0E8E'
VB3GPR           EQU  H'0E8F'

;-----Bank58------------------
LCDCON           EQU  H'1D0C'
LCDPS            EQU  H'1D0D'
LCDSE0           EQU  H'1D0E'
LCDSE1           EQU  H'1D0F'
LCDSE2           EQU  H'1D10'
LCDSE3           EQU  H'1D11'
LCDSE4           EQU  H'1D12'
LCDSE5           EQU  H'1D13'
LCDVCON1         EQU  H'1D14'
LCDVCON2         EQU  H'1D15'
LCDREF           EQU  H'1D16'
LCDRL            EQU  H'1D17'
LCDDATA0         EQU  H'1D18'
LCDDATA1         EQU  H'1D19'
LCDDATA2         EQU  H'1D1A'
LCDDATA3         EQU  H'1D1B'
LCDDATA4         EQU  H'1D1C'
LCDDATA5         EQU  H'1D1D'
LCDDATA6         EQU  H'1D1E'
LCDDATA7         EQU  H'1D1F'
LCDDATA8         EQU  H'1D20'
LCDDATA9         EQU  H'1D21'
LCDDATA10        EQU  H'1D22'
LCDDATA11        EQU  H'1D23'
LCDDATA12        EQU  H'1D24'
LCDDATA13        EQU  H'1D25'
LCDDATA14        EQU  H'1D26'
LCDDATA15        EQU  H'1D27'
LCDDATA16        EQU  H'1D28'
LCDDATA17        EQU  H'1D29'
LCDDATA18        EQU  H'1D2A'
LCDDATA19        EQU  H'1D2B'
LCDDATA20        EQU  H'1D2C'
LCDDATA21        EQU  H'1D2D'
LCDDATA22        EQU  H'1D2E'
LCDDATA23        EQU  H'1D2F'
LCDDATA24        EQU  H'1D30'
LCDDATA25        EQU  H'1D31'
LCDDATA26        EQU  H'1D32'
LCDDATA27        EQU  H'1D33'
LCDDATA28        EQU  H'1D34'
LCDDATA29        EQU  H'1D35'
LCDDATA30        EQU  H'1D36'
LCDDATA31        EQU  H'1D37'
LCDDATA32        EQU  H'1D38'
LCDDATA33        EQU  H'1D39'
LCDDATA34        EQU  H'1D3A'
LCDDATA35        EQU  H'1D3B'
LCDDATA36        EQU  H'1D3C'
LCDDATA37        EQU  H'1D3D'
LCDDATA38        EQU  H'1D3E'
LCDDATA39        EQU  H'1D3F'
LCDDATA40        EQU  H'1D40'
LCDDATA41        EQU  H'1D41'
LCDDATA42        EQU  H'1D42'
LCDDATA43        EQU  H'1D43'
LCDDATA44        EQU  H'1D44'
LCDDATA45        EQU  H'1D45'
LCDDATA46        EQU  H'1D46'
LCDDATA47        EQU  H'1D47'

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
RF0PPS           EQU  H'1E38'
RF1PPS           EQU  H'1E39'
RF2PPS           EQU  H'1E3A'
RF3PPS           EQU  H'1E3B'
RF4PPS           EQU  H'1E3C'
RF5PPS           EQU  H'1E3D'
RF6PPS           EQU  H'1E3E'
RF7PPS           EQU  H'1E3F'
RG0PPS           EQU  H'1E40'
RG1PPS           EQU  H'1E41'
RG2PPS           EQU  H'1E42'
RG3PPS           EQU  H'1E43'
RG4PPS           EQU  H'1E44'
RG6PPS           EQU  H'1E46'
RG7PPS           EQU  H'1E47'
RH0PPS           EQU  H'1E48'
RH1PPS           EQU  H'1E49'
RH2PPS           EQU  H'1E4A'
RH3PPS           EQU  H'1E4B'
ANSELF           EQU  H'1E50'
WPUF             EQU  H'1E51'
ODCONF           EQU  H'1E52'
SLRCONF          EQU  H'1E53'
INLVLF           EQU  H'1E54'
HIDRVF           EQU  H'1E55'
ANSELG           EQU  H'1E5B'
WPUG             EQU  H'1E5C'
ODCONG           EQU  H'1E5D'
SLRCONG          EQU  H'1E5E'
INLVLG           EQU  H'1E5F'
IOCGP            EQU  H'1E60'
IOCGN            EQU  H'1E61'
IOCGF            EQU  H'1E62'
WPUH             EQU  H'1E67'
ODCONH           EQU  H'1E68'
SLRCONH          EQU  H'1E69'
INLVLH           EQU  H'1E6A'

;-----Bank61------------------
PPSLOCK          EQU  H'1E8F'
INTPPS           EQU  H'1E90'
T0CKIPPS         EQU  H'1E91'
T1CKIPPS         EQU  H'1E92'
T1GPPS           EQU  H'1E93'
T2INPPS          EQU  H'1E9C'
T4INPPS          EQU  H'1E9D'
CCP1PPS          EQU  H'1EA1'
CCP2PPS          EQU  H'1EA2'
SMT1WINPPS       EQU  H'1EA9'
SMT1SIGPPS       EQU  H'1EAA'
CWG1PPS          EQU  H'1EB1'
CLCIN0PPS        EQU  H'1EBB'
CLCIN1PPS        EQU  H'1EBC'
CLCIN2PPS        EQU  H'1EBD'
CLCIN3PPS        EQU  H'1EBE'
ADACTPPS         EQU  H'1EC3'
SSP1CLKPPS       EQU  H'1EC5'
SSP1DATPPS       EQU  H'1EC6'
SSP1SSPPS        EQU  H'1EC7'
RX1PPS           EQU  H'1ECB'
TX1PPS           EQU  H'1ECC'
RX2PPS           EQU  H'1ECD'
TX2PPS           EQU  H'1ECE'

;-----Bank62------------------
RA0PPS           EQU  H'1F10'
RA1PPS           EQU  H'1F11'
RA2PPS           EQU  H'1F12'
RA3PPS           EQU  H'1F13'
RA4PPS           EQU  H'1F14'
RA5PPS           EQU  H'1F15'
RA6PPS           EQU  H'1F16'
RA7PPS           EQU  H'1F17'
RB0PPS           EQU  H'1F18'
RB1PPS           EQU  H'1F19'
RB2PPS           EQU  H'1F1A'
RB3PPS           EQU  H'1F1B'
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
RD0PPS           EQU  H'1F28'
RD1PPS           EQU  H'1F29'
RD2PPS           EQU  H'1F2A'
RD3PPS           EQU  H'1F2B'
RD4PPS           EQU  H'1F2C'
RD5PPS           EQU  H'1F2D'
RD6PPS           EQU  H'1F2E'
RD7PPS           EQU  H'1F2F'
RE0PPS           EQU  H'1F30'
RE1PPS           EQU  H'1F31'
RE3PPS           EQU  H'1F33'
RE4PPS           EQU  H'1F34'
RE5PPS           EQU  H'1F35'
RE6PPS           EQU  H'1F36'
RE7PPS           EQU  H'1F37'
ANSELA           EQU  H'1F38'
WPUA             EQU  H'1F39'
ODCONA           EQU  H'1F3A'
SLRCONA          EQU  H'1F3B'
INLVLA           EQU  H'1F3C'
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
ANSELD           EQU  H'1F59'
WPUD             EQU  H'1F5A'
ODCOND           EQU  H'1F5B'
SLRCOND          EQU  H'1F5C'
INLVLD           EQU  H'1F5D'
ANSELE           EQU  H'1F64'
WPUE             EQU  H'1F65'
ODCONE           EQU  H'1F66'
SLRCONE          EQU  H'1F67'
INLVLE           EQU  H'1F68'
IOCEP            EQU  H'1F69'
IOCEN            EQU  H'1F6A'
IOCEF            EQU  H'1F6B'

;-----Bank63------------------
STATUS_SHAD      EQU  H'1FE4'
WREG_SHAD        EQU  H'1FE5'
BSR_SHAD         EQU  H'1FE6'
PCLATH_SHAD      EQU  H'1FE7'
FSR0L_SHAD       EQU  H'1FE8'
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
RA6              EQU  H'0006'
RA7              EQU  H'0007'


;----- PORTB Bits -----------------------------------------------------
RB0              EQU  H'0000'
RB1              EQU  H'0001'
RB2              EQU  H'0002'
RB3              EQU  H'0003'
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


;----- PORTD Bits -----------------------------------------------------
RD0              EQU  H'0000'
RD1              EQU  H'0001'
RD2              EQU  H'0002'
RD3              EQU  H'0003'
RD4              EQU  H'0004'
RD5              EQU  H'0005'
RD6              EQU  H'0006'
RD7              EQU  H'0007'


;----- PORTE Bits -----------------------------------------------------
RE0              EQU  H'0000'
RE1              EQU  H'0001'
RE3              EQU  H'0003'
RE4              EQU  H'0004'
RE5              EQU  H'0005'
RE6              EQU  H'0006'
RE7              EQU  H'0007'


;----- PORTF Bits -----------------------------------------------------
RF0              EQU  H'0000'
RF1              EQU  H'0001'
RF2              EQU  H'0002'
RF3              EQU  H'0003'
RF4              EQU  H'0004'
RF5              EQU  H'0005'
RF6              EQU  H'0006'
RF7              EQU  H'0007'


;----- TRISA Bits -----------------------------------------------------
TRISA0           EQU  H'0000'
TRISA1           EQU  H'0001'
TRISA2           EQU  H'0002'
TRISA3           EQU  H'0003'
TRISA4           EQU  H'0004'
TRISA6           EQU  H'0006'
TRISA7           EQU  H'0007'


;----- TRISB Bits -----------------------------------------------------
TRISB0           EQU  H'0000'
TRISB1           EQU  H'0001'
TRISB2           EQU  H'0002'
TRISB3           EQU  H'0003'
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


;----- TRISD Bits -----------------------------------------------------
TRISD0           EQU  H'0000'
TRISD1           EQU  H'0001'
TRISD2           EQU  H'0002'
TRISD3           EQU  H'0003'
TRISD4           EQU  H'0004'
TRISD5           EQU  H'0005'
TRISD6           EQU  H'0006'
TRISD7           EQU  H'0007'


;----- TRISE Bits -----------------------------------------------------
TRISE0           EQU  H'0000'
TRISE1           EQU  H'0001'
TRISE3           EQU  H'0003'
TRISE4           EQU  H'0004'
TRISE5           EQU  H'0005'
TRISE6           EQU  H'0006'
TRISE7           EQU  H'0007'


;----- TRISF Bits -----------------------------------------------------
TRISF0           EQU  H'0000'
TRISF1           EQU  H'0001'
TRISF2           EQU  H'0002'
TRISF3           EQU  H'0003'
TRISF4           EQU  H'0004'
TRISF5           EQU  H'0005'
TRISF6           EQU  H'0006'
TRISF7           EQU  H'0007'


;----- LATA Bits -----------------------------------------------------
LATA0            EQU  H'0000'
LATA1            EQU  H'0001'
LATA2            EQU  H'0002'
LATA3            EQU  H'0003'
LATA4            EQU  H'0004'
LATA6            EQU  H'0006'
LATA7            EQU  H'0007'


;----- LATB Bits -----------------------------------------------------
LATB0            EQU  H'0000'
LATB1            EQU  H'0001'
LATB2            EQU  H'0002'
LATB3            EQU  H'0003'
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


;----- LATD Bits -----------------------------------------------------
LATD0            EQU  H'0000'
LATD1            EQU  H'0001'
LATD2            EQU  H'0002'
LATD3            EQU  H'0003'
LATD4            EQU  H'0004'
LATD5            EQU  H'0005'
LATD6            EQU  H'0006'
LATD7            EQU  H'0007'


;----- LATE Bits -----------------------------------------------------
LATE0            EQU  H'0000'
LATE1            EQU  H'0001'
LATE3            EQU  H'0003'
LATE4            EQU  H'0004'
LATE5            EQU  H'0005'
LATE6            EQU  H'0006'
LATE7            EQU  H'0007'


;----- LATF Bits -----------------------------------------------------
LATF0            EQU  H'0000'
LATF1            EQU  H'0001'
LATF2            EQU  H'0002'
LATF3            EQU  H'0003'
LATF4            EQU  H'0004'
LATF5            EQU  H'0005'
LATF6            EQU  H'0006'
LATF7            EQU  H'0007'


;----- ADCPCON0 Bits -----------------------------------------------------
ADCPRDY          EQU  H'0000'
ADCPON           EQU  H'0007'


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
GO               EQU  H'0000'
FM               EQU  H'0002'
CS_ADCON0        EQU  H'0004'
CONT             EQU  H'0006'
ON_ADCON0        EQU  H'0007'

ADGO             EQU  H'0000'
ADFM             EQU  H'0002'
ADCS             EQU  H'0004'
ADCONT           EQU  H'0006'
ADON             EQU  H'0007'

DONE             EQU  H'0000'

GO_NOT_DONE      EQU  H'0000'


;----- ADCON1 Bits -----------------------------------------------------
DSEN             EQU  H'0000'
GPOL_ADCON1      EQU  H'0005'
IPEN             EQU  H'0006'
PPOL             EQU  H'0007'

ADDSEN           EQU  H'0000'
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


STAT0            EQU  H'0000'
STAT1            EQU  H'0001'
STAT2            EQU  H'0002'


;----- ADREF Bits -----------------------------------------------------
PREF0            EQU  H'0000'
PREF1            EQU  H'0001'

ADPREF0          EQU  H'0000'
ADPREF1          EQU  H'0001'


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


CS0              EQU  H'0000'
CS1              EQU  H'0001'
CS2              EQU  H'0002'
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


;----- TMR1L Bits -----------------------------------------------------
TMR1L0           EQU  H'0000'
TMR1L1           EQU  H'0001'
TMR1L2           EQU  H'0002'
TMR1L3           EQU  H'0003'
TMR1L4           EQU  H'0004'
TMR1L5           EQU  H'0005'
TMR1L6           EQU  H'0006'
TMR1L7           EQU  H'0007'


TMR10            EQU  H'0000'
TMR11            EQU  H'0001'
TMR12            EQU  H'0002'
TMR13            EQU  H'0003'
TMR14            EQU  H'0004'
TMR15            EQU  H'0005'
TMR16            EQU  H'0006'
TMR17            EQU  H'0007'


;----- TMR1H Bits -----------------------------------------------------
TMR1H0           EQU  H'0000'
TMR1H1           EQU  H'0001'
TMR1H2           EQU  H'0002'
TMR1H3           EQU  H'0003'
TMR1H4           EQU  H'0004'
TMR1H5           EQU  H'0005'
TMR1H6           EQU  H'0006'
TMR1H7           EQU  H'0007'


TMR18            EQU  H'0000'
TMR19            EQU  H'0001'
TMR110           EQU  H'0002'
TMR111           EQU  H'0003'
TMR112           EQU  H'0004'
TMR113           EQU  H'0005'
TMR114           EQU  H'0006'
TMR115           EQU  H'0007'


;----- T1CON Bits -----------------------------------------------------
ON_T1CON         EQU  H'0000'
RD16             EQU  H'0001'
NOT_SYNC         EQU  H'0002'

TMR1ON           EQU  H'0000'
T1RD16           EQU  H'0001'
NOT_T1SYNC       EQU  H'0002'
T1CKPS0          EQU  H'0004'
T1CKPS1          EQU  H'0005'

CKPS0            EQU  H'0004'
CKPS1            EQU  H'0005'


;----- PR1 Bits -----------------------------------------------------
GVAL             EQU  H'0002'
GGO_NOT_DONE     EQU  H'0003'
GSPM             EQU  H'0004'
GTM              EQU  H'0005'
GPOL_PR1         EQU  H'0006'
GE               EQU  H'0007'

T1GVAL           EQU  H'0002'
T1GGO_NOT_DONE   EQU  H'0003'
T1GSPM           EQU  H'0004'
T1GTM            EQU  H'0005'
T1GPOL           EQU  H'0006'
T1GE             EQU  H'0007'

T1GGO            EQU  H'0003'


;----- T1GCON Bits -----------------------------------------------------
GVAL             EQU  H'0002'
GGO_NOT_DONE     EQU  H'0003'
GSPM             EQU  H'0004'
GTM              EQU  H'0005'
GPOL_T1GCON      EQU  H'0006'
GE               EQU  H'0007'

T1GVAL           EQU  H'0002'
T1GGO_NOT_DONE   EQU  H'0003'
T1GSPM           EQU  H'0004'
T1GTM            EQU  H'0005'
T1GPOL           EQU  H'0006'
T1GE             EQU  H'0007'

T1GGO            EQU  H'0003'


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

CS0              EQU  H'0000'
CS1              EQU  H'0001'
CS2              EQU  H'0002'
CS3              EQU  H'0003'


;----- TMR1CLK Bits -----------------------------------------------------
T1CS0            EQU  H'0000'
T1CS1            EQU  H'0001'
T1CS2            EQU  H'0002'
T1CS3            EQU  H'0003'

CS0              EQU  H'0000'
CS1              EQU  H'0001'
CS2              EQU  H'0002'
CS3              EQU  H'0003'


;----- CCPTMRS0 Bits -----------------------------------------------------
C1TSEL0          EQU  H'0000'
C1TSEL1          EQU  H'0001'
C2TSEL0          EQU  H'0002'
C2TSEL1          EQU  H'0003'
P3TSEL0          EQU  H'0004'
P3TSEL1          EQU  H'0005'
P4TSEL0          EQU  H'0006'
P4TSEL1          EQU  H'0007'


;----- T2CON Bits -----------------------------------------------------
ON_T2CON         EQU  H'0007'

T2ON             EQU  H'0007'

T2OUTPS0         EQU  H'0000'
T2OUTPS1         EQU  H'0001'
T2OUTPS2         EQU  H'0002'
T2OUTPS3         EQU  H'0003'
T2CKPS0          EQU  H'0004'
T2CKPS1          EQU  H'0005'
T2CKPS2          EQU  H'0006'

OUTPS0           EQU  H'0000'
OUTPS1           EQU  H'0001'
OUTPS2           EQU  H'0002'
OUTPS3           EQU  H'0003'
CKPS0            EQU  H'0004'
CKPS1            EQU  H'0005'
CKPS2            EQU  H'0006'
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


;----- T2CLK Bits -----------------------------------------------------
CS0              EQU  H'0000'
CS1              EQU  H'0001'
CS2              EQU  H'0002'
CS3              EQU  H'0003'


T2CS0            EQU  H'0000'
T2CS1            EQU  H'0001'
T2CS2            EQU  H'0002'
T2CS3            EQU  H'0003'


;----- T2CLKCON Bits -----------------------------------------------------
CS0              EQU  H'0000'
CS1              EQU  H'0001'
CS2              EQU  H'0002'
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

T4ON             EQU  H'0007'

T4OUTPS0         EQU  H'0000'
T4OUTPS1         EQU  H'0001'
T4OUTPS2         EQU  H'0002'
T4OUTPS3         EQU  H'0003'
T4CKPS0          EQU  H'0004'
T4CKPS1          EQU  H'0005'
T4CKPS2          EQU  H'0006'

OUTPS0           EQU  H'0000'
OUTPS1           EQU  H'0001'
OUTPS2           EQU  H'0002'
OUTPS3           EQU  H'0003'
CKPS0            EQU  H'0004'
CKPS1            EQU  H'0005'
CKPS2            EQU  H'0006'
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


;----- T4CLK Bits -----------------------------------------------------
CS0              EQU  H'0000'
CS1              EQU  H'0001'
CS2              EQU  H'0002'
CS3              EQU  H'0003'


T4CS0            EQU  H'0000'
T4CS1            EQU  H'0001'
T4CS2            EQU  H'0002'
T4CS3            EQU  H'0003'


;----- T4CLKCON Bits -----------------------------------------------------
CS0              EQU  H'0000'
CS1              EQU  H'0001'
CS2              EQU  H'0002'
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


;----- CCP1CON Bits -----------------------------------------------------
FMT              EQU  H'0004'
OUT_CCP1CON      EQU  H'0005'
OE               EQU  H'0006'
EN               EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'
MODE3            EQU  H'0003'

CCP1FMT          EQU  H'0004'
CCP1OUT          EQU  H'0005'
CCP1OE           EQU  H'0006'
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
OE               EQU  H'0006'
EN               EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'
MODE3            EQU  H'0003'

CCP2FMT          EQU  H'0004'
CCP2OUT          EQU  H'0005'
CCP2OE           EQU  H'0006'
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


;----- PWM3DCL Bits -----------------------------------------------------
DC0              EQU  H'0006'
DC1              EQU  H'0007'

PWM3DC0          EQU  H'0006'
PWM3DC1          EQU  H'0007'

PWMPW0           EQU  H'0006'
PWMPW1           EQU  H'0007'


;----- PWM3DCH Bits -----------------------------------------------------
DC2              EQU  H'0000'
DC3              EQU  H'0001'
DC4              EQU  H'0002'
DC5              EQU  H'0003'
DC6              EQU  H'0004'
DC7              EQU  H'0005'
DC8              EQU  H'0006'
DC9              EQU  H'0007'

PWM3DC2          EQU  H'0000'
PWM3DC3          EQU  H'0001'
PWM3DC4          EQU  H'0002'
PWM3DC5          EQU  H'0003'
PWM3DC6          EQU  H'0004'
PWM3DC7          EQU  H'0005'
PWM3DC8          EQU  H'0006'
PWM3DC9          EQU  H'0007'

PWMPW2           EQU  H'0000'
PWMPW3           EQU  H'0001'
PWMPW4           EQU  H'0002'
PWMPW5           EQU  H'0003'
PWMPW6           EQU  H'0004'
PWMPW7           EQU  H'0005'
PWMPW8           EQU  H'0006'
PWMPW9           EQU  H'0007'


;----- PWM3CON Bits -----------------------------------------------------
POL_PWM3CON      EQU  H'0004'
OUT_PWM3CON      EQU  H'0005'
EN               EQU  H'0007'

PWM3POL          EQU  H'0004'
PWM3OUT          EQU  H'0005'
PWM3EN           EQU  H'0007'


;----- PWM4DCL Bits -----------------------------------------------------
DC0              EQU  H'0006'
DC1              EQU  H'0007'

PWM4DC0          EQU  H'0006'
PWM4DC1          EQU  H'0007'

PWMPW0           EQU  H'0006'
PWMPW1           EQU  H'0007'


;----- PWM4DCH Bits -----------------------------------------------------
DC2              EQU  H'0000'
DC3              EQU  H'0001'
DC4              EQU  H'0002'
DC5              EQU  H'0003'
DC6              EQU  H'0004'
DC7              EQU  H'0005'
DC8              EQU  H'0006'
DC9              EQU  H'0007'

PWM4DC2          EQU  H'0000'
PWM4DC3          EQU  H'0001'
PWM4DC4          EQU  H'0002'
PWM4DC5          EQU  H'0003'
PWM4DC6          EQU  H'0004'
PWM4DC7          EQU  H'0005'
PWM4DC8          EQU  H'0006'
PWM4DC9          EQU  H'0007'

PWMPW2           EQU  H'0000'
PWMPW3           EQU  H'0001'
PWMPW4           EQU  H'0002'
PWMPW5           EQU  H'0003'
PWMPW6           EQU  H'0004'
PWMPW7           EQU  H'0005'
PWMPW8           EQU  H'0006'
PWMPW9           EQU  H'0007'


;----- PWM4CON Bits -----------------------------------------------------
POL_PWM4CON      EQU  H'0004'
OUT_PWM4CON      EQU  H'0005'
EN               EQU  H'0007'

PWM4POL          EQU  H'0004'
PWM4OUT          EQU  H'0005'
PWM4EN           EQU  H'0007'


;----- SMT1TMRL Bits -----------------------------------------------------
SMT1TMR0         EQU  H'0000'
SMT1TMR1         EQU  H'0001'
SMT1TMR2         EQU  H'0002'
SMT1TMR3         EQU  H'0003'
SMT1TMR4         EQU  H'0004'
SMT1TMR5         EQU  H'0005'
SMT1TMR6         EQU  H'0006'
SMT1TMR7         EQU  H'0007'


;----- SMT1TMRH Bits -----------------------------------------------------
SMT1TMR8         EQU  H'0000'
SMT1TMR9         EQU  H'0001'
SMT1TMR10        EQU  H'0002'
SMT1TMR11        EQU  H'0003'
SMT1TMR12        EQU  H'0004'
SMT1TMR13        EQU  H'0005'
SMT1TMR14        EQU  H'0006'
SMT1TMR15        EQU  H'0007'


;----- SMT1TMRU Bits -----------------------------------------------------
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
SMT1PR0          EQU  H'0000'
SMT1PR1          EQU  H'0001'
SMT1PR2          EQU  H'0002'
SMT1PR3          EQU  H'0003'
SMT1PR4          EQU  H'0004'
SMT1PR5          EQU  H'0005'
SMT1PR6          EQU  H'0006'
SMT1PR7          EQU  H'0007'


;----- SMT1PRH Bits -----------------------------------------------------
SMT1PR8          EQU  H'0000'
SMT1PR9          EQU  H'0001'
SMT1PR10         EQU  H'0002'
SMT1PR11         EQU  H'0003'
SMT1PR12         EQU  H'0004'
SMT1PR13         EQU  H'0005'
SMT1PR14         EQU  H'0006'
SMT1PR15         EQU  H'0007'


;----- SMT1PRU Bits -----------------------------------------------------
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

SMT1PS0          EQU  H'0000'
SMT1PS1          EQU  H'0001'
SMT1EN           EQU  H'0007'


;----- SMT1CON1 Bits -----------------------------------------------------
REPEAT           EQU  H'0006'
SMT1GO           EQU  H'0007'

MODE0            EQU  H'0000'
MODE1            EQU  H'0001'
MODE2            EQU  H'0002'
MODE3            EQU  H'0003'


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
T016BIT          EQU  H'0004'
T0OUT            EQU  H'0005'
T0OE             EQU  H'0006'
T0EN             EQU  H'0007'

T0OUTPS0         EQU  H'0000'
T0OUTPS1         EQU  H'0001'
T0OUTPS2         EQU  H'0002'
T0OUTPS3         EQU  H'0003'


;----- T0CON1 Bits -----------------------------------------------------
T0ASYNC          EQU  H'0004'

T0CKPS0          EQU  H'0000'
T0CKPS1          EQU  H'0001'
T0CKPS2          EQU  H'0002'
T0CKPS3          EQU  H'0003'
T0CS0            EQU  H'0005'
T0CS1            EQU  H'0006'
T0CS2            EQU  H'0007'

T0PS0            EQU  H'0000'
T0PS1            EQU  H'0001'
T0PS2            EQU  H'0002'
T0PS3            EQU  H'0003'



;----- CWG1CLKCON Bits -----------------------------------------------------
CS_CWG1CLKCON    EQU  H'0000'

CWG1CS           EQU  H'0000'


;----- CWG1ISM Bits -----------------------------------------------------
CWG1ISM0         EQU  H'0000'
CWG1ISM1         EQU  H'0001'
CWG1ISM2         EQU  H'0002'
CWG1ISM3         EQU  H'0003'


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
LSAC1            EQU  H'0003'
LSBD0            EQU  H'0004'
LSBD1            EQU  H'0005'

CWG1REN          EQU  H'0006'
CWG1SHUTDOWN     EQU  H'0007'

CWG1LSAC0        EQU  H'0002'
CWG1LSAC1        EQU  H'0003'
CWG1LSBD0        EQU  H'0004'
CWG1LSBD1        EQU  H'0005'


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
TX1IF            EQU  H'0004'
RC1IF            EQU  H'0005'
TX2IF            EQU  H'0006'
RC2IF            EQU  H'0007'


;----- PIR4 Bits -----------------------------------------------------
TMR1IF           EQU  H'0000'
TMR2IF           EQU  H'0001'
TMR4IF           EQU  H'0003'


;----- PIR5 Bits -----------------------------------------------------
TMR1GIF          EQU  H'0000'
CLC1IF           EQU  H'0004'
CLC2IF           EQU  H'0005'
CLC3IF           EQU  H'0006'
CLC4IF           EQU  H'0007'


;----- PIR6 Bits -----------------------------------------------------
CCP1IF           EQU  H'0000'
CCP2IF           EQU  H'0001'
CRIF             EQU  H'0007'


;----- PIR7 Bits -----------------------------------------------------
CWG1IF           EQU  H'0000'
NVMIF            EQU  H'0005'


;----- PIR8 Bits -----------------------------------------------------
SMT1IF           EQU  H'0000'
SMT1PRAIF        EQU  H'0001'
SMT1PWAIF        EQU  H'0002'
RTCCIF           EQU  H'0006'
LCDIF            EQU  H'0007'


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
TX1IE            EQU  H'0004'
RC1IE            EQU  H'0005'
TX2IE            EQU  H'0006'
RC2IE            EQU  H'0007'


;----- PIE4 Bits -----------------------------------------------------
TMR1IE           EQU  H'0000'
TMR2IE           EQU  H'0001'
TMR4IE           EQU  H'0003'


;----- PIE5 Bits -----------------------------------------------------
TMR1GIE          EQU  H'0000'
CLC1IE           EQU  H'0004'
CLC2IE           EQU  H'0005'
CLC3IE           EQU  H'0006'
CLC4IE           EQU  H'0007'


;----- PIE6 Bits -----------------------------------------------------
CCP1IE           EQU  H'0000'
CCP2IE           EQU  H'0001'
CRIE             EQU  H'0007'


;----- PIE7 Bits -----------------------------------------------------
CWG1IE           EQU  H'0000'
NVMIE            EQU  H'0005'


;----- PIE8 Bits -----------------------------------------------------
SMT1IE           EQU  H'0000'
SMT1PRAIE        EQU  H'0001'
SMT1PWAIE        EQU  H'0002'
RTCCIE           EQU  H'0006'
LCDIE            EQU  H'0007'


;----- PMD0 Bits -----------------------------------------------------
IOCMD            EQU  H'0000'
NVMMD            EQU  H'0002'
ACTMD            EQU  H'0005'
FVRMD            EQU  H'0006'
SYSCMD           EQU  H'0007'


;----- PMD1 Bits -----------------------------------------------------
TMR0MD           EQU  H'0000'
TMR1MD           EQU  H'0001'
TMR2MD           EQU  H'0002'
TMR4MD           EQU  H'0004'


;----- PMD2 Bits -----------------------------------------------------
ZCDMD            EQU  H'0000'
CMP1MD           EQU  H'0001'
CMP2MD           EQU  H'0002'
ADCMD            EQU  H'0005'
DACMD            EQU  H'0006'
RTCCMD           EQU  H'0007'


;----- PMD3 Bits -----------------------------------------------------
CCP1MD           EQU  H'0000'
CCP2MD           EQU  H'0001'
CCP3MD           EQU  H'0002'
CCP4MD           EQU  H'0003'


;----- PMD4 Bits -----------------------------------------------------
CWG1MD           EQU  H'0000'
MSSP1MD          EQU  H'0004'
UART1MD          EQU  H'0006'
UART2MD          EQU  H'0007'


;----- PMD5 Bits -----------------------------------------------------
CLC1MD           EQU  H'0001'
CLC2MD           EQU  H'0002'
CLC3MD           EQU  H'0003'
CLC4MD           EQU  H'0004'
LCDMD            EQU  H'0005'
SMT1MD           EQU  H'0006'


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
VBATBOR          EQU  H'0000'
MEMV             EQU  H'0001'


;----- NVMADRL Bits -----------------------------------------------------
NVMADR0          EQU  H'0000'
NVMADR1          EQU  H'0001'
NVMADR2          EQU  H'0002'
NVMADR3          EQU  H'0003'
NVMADR4          EQU  H'0004'
NVMADR5          EQU  H'0005'
NVMADR6          EQU  H'0006'
NVMADR7          EQU  H'0007'


;----- NVMADRH Bits -----------------------------------------------------
NVMADR8          EQU  H'0000'
NVMADR9          EQU  H'0001'
NVMADR10         EQU  H'0002'
NVMADR11         EQU  H'0003'
NVMADR12         EQU  H'0004'
NVMADR13         EQU  H'0005'
NVMADR14         EQU  H'0006'


;----- NVMDATL Bits -----------------------------------------------------
NVMDAT0          EQU  H'0000'
NVMDAT1          EQU  H'0001'
NVMDAT2          EQU  H'0002'
NVMDAT3          EQU  H'0003'
NVMDAT4          EQU  H'0004'
NVMDAT5          EQU  H'0005'
NVMDAT6          EQU  H'0006'
NVMDAT7          EQU  H'0007'


;----- NVMDATH Bits -----------------------------------------------------
NVMDAT8          EQU  H'0000'
NVMDAT9          EQU  H'0001'
NVMDAT10         EQU  H'0002'
NVMDAT11         EQU  H'0003'
NVMDAT12         EQU  H'0004'
NVMDAT13         EQU  H'0005'


;----- NVMCON1 Bits -----------------------------------------------------
RD               EQU  H'0000'
WR               EQU  H'0001'
WREN             EQU  H'0002'
WRERR            EQU  H'0003'
FREE             EQU  H'0004'
LWLO             EQU  H'0005'
NVMREGS          EQU  H'0006'


;----- CPUDOZE Bits -----------------------------------------------------
DOZE0            EQU  H'0000'
DOZE1            EQU  H'0001'
DOZE2            EQU  H'0002'
DOE              EQU  H'0004'
ROI              EQU  H'0005'
DOZEN            EQU  H'0006'
IDLEN            EQU  H'0007'



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
TUN0             EQU  H'0000'
TUN1             EQU  H'0001'
TUN2             EQU  H'0002'
TUN3             EQU  H'0003'
TUN4             EQU  H'0004'
TUN5             EQU  H'0005'


;----- OSCFRQ Bits -----------------------------------------------------
HFFRQ0           EQU  H'0000'
HFFRQ1           EQU  H'0001'
HFFRQ2           EQU  H'0002'


;----- ACTCON Bits -----------------------------------------------------
ACTORS           EQU  H'0001'
ACTLOCK          EQU  H'0003'
ACTUD            EQU  H'0006'
ACTEN            EQU  H'0007'


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
OE2              EQU  H'0004'
OE1              EQU  H'0005'
EN               EQU  H'0007'

DAC1PSS0         EQU  H'0002'
DAC1PSS1         EQU  H'0003'
DAC1OE2          EQU  H'0004'
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
ON_CM1CON0       EQU  H'0007'

C1SYNC           EQU  H'0000'
C1HYS            EQU  H'0001'
C1POL            EQU  H'0004'
C1OUT_CM1CON0    EQU  H'0006'
C1ON             EQU  H'0007'


;----- CM1CON1 Bits -----------------------------------------------------
INTN_CM1CON1     EQU  H'0000'
INTP_CM1CON1     EQU  H'0001'

C1INTN           EQU  H'0000'
C1INTP           EQU  H'0001'


;----- CM1NSEL Bits -----------------------------------------------------
NCH0             EQU  H'0000'
NCH1             EQU  H'0001'
NCH2             EQU  H'0002'


C1NCH0           EQU  H'0000'
C1NCH1           EQU  H'0001'
C1NCH2           EQU  H'0002'


;----- CM1PSEL Bits -----------------------------------------------------
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
ON_CM2CON0       EQU  H'0007'

C2SYNC           EQU  H'0000'
C2HYS            EQU  H'0001'
C2POL            EQU  H'0004'
C2OUT_CM2CON0    EQU  H'0006'
C2ON             EQU  H'0007'


;----- CM2CON1 Bits -----------------------------------------------------
INTN_CM2CON1     EQU  H'0000'
INTP_CM2CON1     EQU  H'0001'

C2INTN           EQU  H'0000'
C2INTP           EQU  H'0001'


;----- CM2NSEL Bits -----------------------------------------------------
NCH0             EQU  H'0000'
NCH1             EQU  H'0001'
NCH2             EQU  H'0002'


C2NCH0           EQU  H'0000'
C2NCH1           EQU  H'0001'
C2NCH2           EQU  H'0002'


;----- CM2PSEL Bits -----------------------------------------------------
PCH0             EQU  H'0000'
PCH1             EQU  H'0001'
PCH2             EQU  H'0002'


C2PCH0           EQU  H'0000'
C2PCH1           EQU  H'0001'
C2PCH2           EQU  H'0002'


;----- RC2STA Bits -----------------------------------------------------
RX9D             EQU  H'0000'
OERR             EQU  H'0001'
FERR             EQU  H'0002'
ADDEN            EQU  H'0003'
CREN             EQU  H'0004'
SREN             EQU  H'0005'
RX9              EQU  H'0006'
SPEN             EQU  H'0007'


;----- RCSTA2 Bits -----------------------------------------------------
RX9D             EQU  H'0000'
OERR             EQU  H'0001'
FERR             EQU  H'0002'
ADDEN            EQU  H'0003'
CREN             EQU  H'0004'
SREN             EQU  H'0005'
RX9              EQU  H'0006'
SPEN             EQU  H'0007'


;----- TX2STA Bits -----------------------------------------------------
TX9D             EQU  H'0000'
TRMT             EQU  H'0001'
BRGH             EQU  H'0002'
SENDB            EQU  H'0003'
SYNC_TX2STA      EQU  H'0004'
TXEN             EQU  H'0005'
TX9              EQU  H'0006'
CSRC             EQU  H'0007'


;----- TXSTA2 Bits -----------------------------------------------------
TX9D             EQU  H'0000'
TRMT             EQU  H'0001'
BRGH             EQU  H'0002'
SENDB            EQU  H'0003'
SYNC_TXSTA2      EQU  H'0004'
TXEN             EQU  H'0005'
TX9              EQU  H'0006'
CSRC             EQU  H'0007'


;----- BAUD2CON Bits -----------------------------------------------------
ABDEN            EQU  H'0000'
WUE              EQU  H'0001'
BRG16            EQU  H'0003'
SCKP             EQU  H'0004'
RCIDL            EQU  H'0006'
ABDOVF           EQU  H'0007'


;----- BAUDCON2 Bits -----------------------------------------------------
ABDEN            EQU  H'0000'
WUE              EQU  H'0001'
BRG16            EQU  H'0003'
SCKP             EQU  H'0004'
RCIDL            EQU  H'0006'
ABDOVF           EQU  H'0007'


;----- BAUDCTL2 Bits -----------------------------------------------------
ABDEN            EQU  H'0000'
WUE              EQU  H'0001'
BRG16            EQU  H'0003'
SCKP             EQU  H'0004'
RCIDL            EQU  H'0006'
ABDOVF           EQU  H'0007'


;----- RTCCON Bits -----------------------------------------------------
HALFSEC          EQU  H'0003'
RTCSYNC          EQU  H'0004'
RTCWREN          EQU  H'0005'
RTCEN            EQU  H'0007'

RTCCLKSEL0       EQU  H'0000'
RTCCLKSEL1       EQU  H'0001'


;----- RTCCAL Bits -----------------------------------------------------
CAL0             EQU  H'0000'
CAL1             EQU  H'0001'
CAL2             EQU  H'0002'
CAL3             EQU  H'0003'
CAL4             EQU  H'0004'
CAL5             EQU  H'0005'
CAL6             EQU  H'0006'
CAL7             EQU  H'0007'


;----- ALRMCON Bits -----------------------------------------------------
CHIME            EQU  H'0006'
ALRMEN           EQU  H'0007'

AMASK0           EQU  H'0002'
AMASK1           EQU  H'0003'
AMASK2           EQU  H'0004'
AMASK3           EQU  H'0005'


;----- ALRMRPT Bits -----------------------------------------------------
ARPT0            EQU  H'0000'
ARPT1            EQU  H'0001'
ARPT2            EQU  H'0002'
ARPT3            EQU  H'0003'
ARPT4            EQU  H'0004'
ARPT5            EQU  H'0005'
ARPT6            EQU  H'0006'
ARPT7            EQU  H'0007'


;----- YEAR Bits -----------------------------------------------------
YEARL0           EQU  H'0000'
YEARL1           EQU  H'0001'
YEARL2           EQU  H'0002'
YEARL3           EQU  H'0003'
YEARH0           EQU  H'0004'
YEARH1           EQU  H'0005'
YEARH2           EQU  H'0006'
YEARH3           EQU  H'0007'


;----- MONTH Bits -----------------------------------------------------
MONTHL0          EQU  H'0000'
MONTHL1          EQU  H'0001'
MONTHL2          EQU  H'0002'
MONTHL3          EQU  H'0003'
MONTHH           EQU  H'0004'


;----- WEEKDAY Bits -----------------------------------------------------
WDAY0            EQU  H'0000'
WDAY1            EQU  H'0001'
WDAY2            EQU  H'0002'


;----- DAY Bits -----------------------------------------------------
DAYL0            EQU  H'0000'
DAYL1            EQU  H'0001'
DAYL2            EQU  H'0002'
DAYL3            EQU  H'0003'
DAYH0            EQU  H'0004'
DAYH1            EQU  H'0005'


;----- HOURS Bits -----------------------------------------------------
HRL0             EQU  H'0000'
HRL1             EQU  H'0001'
HRL2             EQU  H'0002'
HRL3             EQU  H'0003'
HRH0             EQU  H'0004'
HRH1             EQU  H'0005'


;----- MINUTES Bits -----------------------------------------------------
MINL0            EQU  H'0000'
MINL1            EQU  H'0001'
MINL2            EQU  H'0002'
MINL3            EQU  H'0003'
MINH0            EQU  H'0004'
MINH1            EQU  H'0005'
MINH2            EQU  H'0006'


;----- SECONDS Bits -----------------------------------------------------
SECL0            EQU  H'0000'
SECL1            EQU  H'0001'
SECL2            EQU  H'0002'
SECL3            EQU  H'0003'
SECH0            EQU  H'0004'
SECH1            EQU  H'0005'
SECH2            EQU  H'0006'


;----- ALRMMTH Bits -----------------------------------------------------
MTHALRMH0        EQU  H'0004'

MTHALRML0        EQU  H'0000'
MTHALRML1        EQU  H'0001'
MTHALRML2        EQU  H'0002'
MTHALRML3        EQU  H'0003'


;----- ALRMWD Bits -----------------------------------------------------
WDALRM0          EQU  H'0000'
WDALRM1          EQU  H'0001'
WDALRM2          EQU  H'0002'


;----- ALRMDAY Bits -----------------------------------------------------
DAYALRML0        EQU  H'0000'
DAYALRML1        EQU  H'0001'
DAYALRML2        EQU  H'0002'
DAYALRML3        EQU  H'0003'
DAYALRMH0        EQU  H'0004'
DAYALRMH1        EQU  H'0005'


;----- ALRMHR Bits -----------------------------------------------------
HRALRML0         EQU  H'0000'
HRALRML1         EQU  H'0001'
HRALRML2         EQU  H'0002'
HRALRML3         EQU  H'0003'
HRALRMH0         EQU  H'0004'
HRALRMH1         EQU  H'0005'


;----- ALRMMIN Bits -----------------------------------------------------
MINALRML0        EQU  H'0000'
MINALRML1        EQU  H'0001'
MINALRML2        EQU  H'0002'
MINALRML3        EQU  H'0003'
MINALRMH0        EQU  H'0004'
MINALRMH1        EQU  H'0005'
MINALRMH2        EQU  H'0006'


;----- ALRMSEC Bits -----------------------------------------------------
SECALRML0        EQU  H'0000'
SECALRML1        EQU  H'0001'
SECALRML2        EQU  H'0002'
SECALRML3        EQU  H'0003'
SECALRMH0        EQU  H'0004'
SECALRMH1        EQU  H'0005'
SECALRMH2        EQU  H'0006'


;----- PORTG Bits -----------------------------------------------------
RG0              EQU  H'0000'
RG1              EQU  H'0001'
RG2              EQU  H'0002'
RG3              EQU  H'0003'
RG4              EQU  H'0004'
RG5              EQU  H'0005'
RG6              EQU  H'0006'
RG7              EQU  H'0007'


;----- PORTH Bits -----------------------------------------------------
RH0              EQU  H'0000'
RH1              EQU  H'0001'
RH2              EQU  H'0002'
RH3              EQU  H'0003'


;----- TRISG Bits -----------------------------------------------------
TRISG0           EQU  H'0000'
TRISG1           EQU  H'0001'
TRISG2           EQU  H'0002'
TRISG3           EQU  H'0003'
TRISG4           EQU  H'0004'
TRISG6           EQU  H'0006'
TRISG7           EQU  H'0007'


;----- TRISH Bits -----------------------------------------------------
TRISH0           EQU  H'0000'
TRISH1           EQU  H'0001'
TRISH2           EQU  H'0002'
TRISH3           EQU  H'0003'


;----- LATG Bits -----------------------------------------------------
LATG0            EQU  H'0000'
LATG1            EQU  H'0001'
LATG2            EQU  H'0002'
LATG3            EQU  H'0003'
LATG4            EQU  H'0004'
LATG6            EQU  H'0006'
LATG7            EQU  H'0007'


;----- LATH Bits -----------------------------------------------------
LATH0            EQU  H'0000'
LATH1            EQU  H'0001'
LATH2            EQU  H'0002'
LATH3            EQU  H'0003'


;----- VB0GPR Bits -----------------------------------------------------
VB0GPR0          EQU  H'0000'
VB0GPR1          EQU  H'0001'
VB0GPR2          EQU  H'0002'
VB0GPR3          EQU  H'0003'
VB0GPR4          EQU  H'0004'
VB0GPR5          EQU  H'0005'
VB0GPR6          EQU  H'0006'
VB0GPR7          EQU  H'0007'


;----- VB1GPR Bits -----------------------------------------------------
VB1GPR0          EQU  H'0000'
VB1GPR1          EQU  H'0001'
VB1GPR2          EQU  H'0002'
VB1GPR3          EQU  H'0003'
VB1GPR4          EQU  H'0004'
VB1GPR5          EQU  H'0005'
VB1GPR6          EQU  H'0006'
VB1GPR7          EQU  H'0007'


;----- VB2GPR Bits -----------------------------------------------------
VB2GPR0          EQU  H'0000'
VB2GPR1          EQU  H'0001'
VB2GPR2          EQU  H'0002'
VB2GPR3          EQU  H'0003'
VB2GPR4          EQU  H'0004'
VB2GPR5          EQU  H'0005'
VB2GPR6          EQU  H'0006'
VB2GPR7          EQU  H'0007'


;----- VB3GPR Bits -----------------------------------------------------
VB3GPR0          EQU  H'0000'
VB3GPR1          EQU  H'0001'
VB3GPR2          EQU  H'0002'
VB3GPR3          EQU  H'0003'
VB3GPR4          EQU  H'0004'
VB3GPR5          EQU  H'0005'
VB3GPR6          EQU  H'0006'
VB3GPR7          EQU  H'0007'


;----- LCDCON Bits -----------------------------------------------------
CS_LCDCON        EQU  H'0004'
WERR             EQU  H'0005'
SLPEN            EQU  H'0006'
LCDEN            EQU  H'0007'

LMUX0            EQU  H'0000'
LMUX1            EQU  H'0001'
LMUX2            EQU  H'0002'
LMUX3            EQU  H'0003'


;----- LCDPS Bits -----------------------------------------------------
WA               EQU  H'0004'
LCDA             EQU  H'0005'
WFT              EQU  H'0007'

LP0              EQU  H'0000'
LP1              EQU  H'0001'
LP2              EQU  H'0002'
LP3              EQU  H'0003'


;----- LCDSE0 Bits -----------------------------------------------------
SE00             EQU  H'0000'
SE01             EQU  H'0001'
SE02             EQU  H'0002'
SE03             EQU  H'0003'
SE04             EQU  H'0004'
SE05             EQU  H'0005'
SE06             EQU  H'0006'
SE07             EQU  H'0007'


;----- LCDSE1 Bits -----------------------------------------------------
SE08             EQU  H'0000'
SE09             EQU  H'0001'
SE10             EQU  H'0002'
SE11             EQU  H'0003'
SE12             EQU  H'0004'
SE13             EQU  H'0005'
SE14             EQU  H'0006'
SE15             EQU  H'0007'


;----- LCDSE2 Bits -----------------------------------------------------
SE16             EQU  H'0000'
SE17             EQU  H'0001'
SE18             EQU  H'0002'
SE19             EQU  H'0003'
SE20             EQU  H'0004'
SE21             EQU  H'0005'
SE22             EQU  H'0006'
SE23             EQU  H'0007'


;----- LCDSE3 Bits -----------------------------------------------------
SE24             EQU  H'0000'
SE25             EQU  H'0001'
SE26             EQU  H'0002'
SE27             EQU  H'0003'
SE28             EQU  H'0004'
SE29             EQU  H'0005'
SE30             EQU  H'0006'
SE31             EQU  H'0007'


;----- LCDSE4 Bits -----------------------------------------------------
SE32             EQU  H'0000'
SE33             EQU  H'0001'
SE34             EQU  H'0002'
SE35             EQU  H'0003'
SE36             EQU  H'0004'
SE37             EQU  H'0005'
SE38             EQU  H'0006'
SE39             EQU  H'0007'


;----- LCDSE5 Bits -----------------------------------------------------
SE40             EQU  H'0000'
SE41             EQU  H'0001'
SE42             EQU  H'0002'
SE43             EQU  H'0003'
SE44             EQU  H'0004'
SE45             EQU  H'0005'
SE46             EQU  H'0006'
SE47             EQU  H'0007'


;----- LCDVCON1 Bits -----------------------------------------------------
EN5V             EQU  H'0006'
LPEN             EQU  H'0007'

BIAS0            EQU  H'0000'
BIAS1            EQU  H'0001'
BIAS2            EQU  H'0002'


;----- LCDVCON2 Bits -----------------------------------------------------
CPWDT            EQU  H'0007'

LCDVSRC0         EQU  H'0000'
LCDVSRC1         EQU  H'0001'
LCDVSRC2         EQU  H'0002'
LCDVSRC3         EQU  H'0003'


;----- LCDREF Bits -----------------------------------------------------
LCDCST0          EQU  H'0000'
LCDCST1          EQU  H'0001'
LCDCST2          EQU  H'0002'


;----- LCDRL Bits -----------------------------------------------------
LCDIRI           EQU  H'0003'

LRLAT0           EQU  H'0000'
LRLAT1           EQU  H'0001'
LRLAT2           EQU  H'0002'
LRLBP0           EQU  H'0004'
LRLBP1           EQU  H'0005'
LRLAP0           EQU  H'0006'
LRLAP1           EQU  H'0007'


;----- LCDDATA0 Bits -----------------------------------------------------
S00C0            EQU  H'0000'
S01C0            EQU  H'0001'
S02C0            EQU  H'0002'
S03C0            EQU  H'0003'
S04C0            EQU  H'0004'
S05C0            EQU  H'0005'
S06C0            EQU  H'0006'
S07C0            EQU  H'0007'


;----- LCDDATA1 Bits -----------------------------------------------------
S08C0            EQU  H'0000'
S09C0            EQU  H'0001'
S10C0            EQU  H'0002'
S11C0            EQU  H'0003'
S12C0            EQU  H'0004'
S13C0            EQU  H'0005'
S14C0            EQU  H'0006'
S15C0            EQU  H'0007'


;----- LCDDATA2 Bits -----------------------------------------------------
S16C0            EQU  H'0000'
S17C0            EQU  H'0001'
S18C0            EQU  H'0002'
S19C0            EQU  H'0003'
S20C0            EQU  H'0004'
S21C0            EQU  H'0005'
S22C0            EQU  H'0006'
S23C0            EQU  H'0007'


;----- LCDDATA3 Bits -----------------------------------------------------
S24C0            EQU  H'0000'
S25C0            EQU  H'0001'
S26C0            EQU  H'0002'
S27C0            EQU  H'0003'
S28C0            EQU  H'0004'
S29C0            EQU  H'0005'
S30C0            EQU  H'0006'
S31C0            EQU  H'0007'


;----- LCDDATA4 Bits -----------------------------------------------------
S32C0            EQU  H'0000'
S33C0            EQU  H'0001'
S34C0            EQU  H'0002'
S35C0            EQU  H'0003'
S36C0            EQU  H'0004'
S37C0            EQU  H'0005'
S38C0            EQU  H'0006'
S39C0            EQU  H'0007'


;----- LCDDATA5 Bits -----------------------------------------------------
S40C0            EQU  H'0000'
S41C0            EQU  H'0001'
S42C0            EQU  H'0002'
S43C0            EQU  H'0003'
S44C0            EQU  H'0004'
S45C0            EQU  H'0005'


;----- LCDDATA6 Bits -----------------------------------------------------
S00C1            EQU  H'0000'
S01C1            EQU  H'0001'
S02C1            EQU  H'0002'
S03C1            EQU  H'0003'
S04C1            EQU  H'0004'
S05C1            EQU  H'0005'
S06C1            EQU  H'0006'
S07C1            EQU  H'0007'


;----- LCDDATA7 Bits -----------------------------------------------------
S08C1            EQU  H'0000'
S09C1            EQU  H'0001'
S10C1            EQU  H'0002'
S11C1            EQU  H'0003'
S12C1            EQU  H'0004'
S13C1            EQU  H'0005'
S14C1            EQU  H'0006'
S15C1            EQU  H'0007'


;----- LCDDATA8 Bits -----------------------------------------------------
S16C1            EQU  H'0000'
S17C1            EQU  H'0001'
S18C1            EQU  H'0002'
S19C1            EQU  H'0003'
S20C1            EQU  H'0004'
S21C1            EQU  H'0005'
S22C1            EQU  H'0006'
S23C1            EQU  H'0007'


;----- LCDDATA9 Bits -----------------------------------------------------
S24C1            EQU  H'0000'
S25C1            EQU  H'0001'
S26C1            EQU  H'0002'
S27C1            EQU  H'0003'
S28C1            EQU  H'0004'
S29C1            EQU  H'0005'
S30C1            EQU  H'0006'
S31C1            EQU  H'0007'


;----- LCDDATA10 Bits -----------------------------------------------------
S32C1            EQU  H'0000'
S33C1            EQU  H'0001'
S34C1            EQU  H'0002'
S35C1            EQU  H'0003'
S36C1            EQU  H'0004'
S37C1            EQU  H'0005'
S38C1            EQU  H'0006'
S39C1            EQU  H'0007'


;----- LCDDATA11 Bits -----------------------------------------------------
S40C1            EQU  H'0000'
S41C1            EQU  H'0001'
S42C1            EQU  H'0002'
S43C1            EQU  H'0003'
S44C1            EQU  H'0004'
S45C1            EQU  H'0005'


;----- LCDDATA12 Bits -----------------------------------------------------
S00C2            EQU  H'0000'
S01C2            EQU  H'0001'
S02C2            EQU  H'0002'
S03C2            EQU  H'0003'
S04C2            EQU  H'0004'
S05C2            EQU  H'0005'
S06C2            EQU  H'0006'
S07C2            EQU  H'0007'


;----- LCDDATA13 Bits -----------------------------------------------------
S08C2            EQU  H'0000'
S09C2            EQU  H'0001'
S10C2            EQU  H'0002'
S11C2            EQU  H'0003'
S12C2            EQU  H'0004'
S13C2            EQU  H'0005'
S14C2            EQU  H'0006'
S15C2            EQU  H'0007'


;----- LCDDATA14 Bits -----------------------------------------------------
S16C2            EQU  H'0000'
S17C2            EQU  H'0001'
S18C2            EQU  H'0002'
S19C2            EQU  H'0003'
S20C2            EQU  H'0004'
S21C2            EQU  H'0005'
S22C2            EQU  H'0006'
S23C2            EQU  H'0007'


;----- LCDDATA15 Bits -----------------------------------------------------
S24C2            EQU  H'0000'
S25C2            EQU  H'0001'
S26C2            EQU  H'0002'
S27C2            EQU  H'0003'
S28C2            EQU  H'0004'
S29C2            EQU  H'0005'
S30C2            EQU  H'0006'
S31C2            EQU  H'0007'


;----- LCDDATA16 Bits -----------------------------------------------------
S32C2            EQU  H'0000'
S33C2            EQU  H'0001'
S34C2            EQU  H'0002'
S35C2            EQU  H'0003'
S36C2            EQU  H'0004'
S37C2            EQU  H'0005'
S38C2            EQU  H'0006'
S39C2            EQU  H'0007'


;----- LCDDATA17 Bits -----------------------------------------------------
S40C2            EQU  H'0000'
S41C2            EQU  H'0001'
S42C2            EQU  H'0002'
S43C2            EQU  H'0003'
S44C2            EQU  H'0004'
S45C2            EQU  H'0005'


;----- LCDDATA18 Bits -----------------------------------------------------
S00C3            EQU  H'0000'
S01C3            EQU  H'0001'
S02C3            EQU  H'0002'
S03C3            EQU  H'0003'
S04C3            EQU  H'0004'
S05C3            EQU  H'0005'
S06C3            EQU  H'0006'
S07C3            EQU  H'0007'


;----- LCDDATA19 Bits -----------------------------------------------------
S08C3            EQU  H'0000'
S09C3            EQU  H'0001'
S10C3            EQU  H'0002'
S11C3            EQU  H'0003'
S12C3            EQU  H'0004'
S13C3            EQU  H'0005'
S14C3            EQU  H'0006'
S15C3            EQU  H'0007'


;----- LCDDATA20 Bits -----------------------------------------------------
S16C3            EQU  H'0000'
S17C3            EQU  H'0001'
S18C3            EQU  H'0002'
S19C3            EQU  H'0003'
S20C3            EQU  H'0004'
S21C3            EQU  H'0005'
S22C3            EQU  H'0006'
S23C3            EQU  H'0007'


;----- LCDDATA21 Bits -----------------------------------------------------
S24C3            EQU  H'0000'
S25C3            EQU  H'0001'
S26C3            EQU  H'0002'
S27C3            EQU  H'0003'
S28C3            EQU  H'0004'
S29C3            EQU  H'0005'
S30C3            EQU  H'0006'
S31C3            EQU  H'0007'


;----- LCDDATA22 Bits -----------------------------------------------------
S32C3            EQU  H'0000'
S33C3            EQU  H'0001'
S34C3            EQU  H'0002'
S35C3            EQU  H'0003'
S36C3            EQU  H'0004'
S37C3            EQU  H'0005'
S38C3            EQU  H'0006'
S39C3            EQU  H'0007'


;----- LCDDATA23 Bits -----------------------------------------------------
S40C3            EQU  H'0000'
S41C3            EQU  H'0001'
S42C3            EQU  H'0002'
S43C3            EQU  H'0003'
S44C3            EQU  H'0004'
S45C3            EQU  H'0005'


;----- LCDDATA24 Bits -----------------------------------------------------
S00C4            EQU  H'0000'
S01C4            EQU  H'0001'
S02C4            EQU  H'0002'
S03C4            EQU  H'0003'
S04C4            EQU  H'0004'
S05C4            EQU  H'0005'
S06C4            EQU  H'0006'
S07C4            EQU  H'0007'


;----- LCDDATA25 Bits -----------------------------------------------------
S08C4            EQU  H'0000'
S09C4            EQU  H'0001'
S10C4            EQU  H'0002'
S11C4            EQU  H'0003'
S12C4            EQU  H'0004'
S13C4            EQU  H'0005'
S14C4            EQU  H'0006'
S15C4            EQU  H'0007'


;----- LCDDATA26 Bits -----------------------------------------------------
S16C4            EQU  H'0000'
S17C4            EQU  H'0001'
S18C4            EQU  H'0002'
S19C4            EQU  H'0003'
S20C4            EQU  H'0004'
S21C4            EQU  H'0005'
S22C4            EQU  H'0006'
S23C4            EQU  H'0007'


;----- LCDDATA27 Bits -----------------------------------------------------
S24C4            EQU  H'0000'
S25C4            EQU  H'0001'
S26C4            EQU  H'0002'
S27C4            EQU  H'0003'
S28C4            EQU  H'0004'
S29C4            EQU  H'0005'
S30C4            EQU  H'0006'
S31C4            EQU  H'0007'


;----- LCDDATA28 Bits -----------------------------------------------------
S32C4            EQU  H'0000'
S33C4            EQU  H'0001'
S34C4            EQU  H'0002'
S35C4            EQU  H'0003'
S36C4            EQU  H'0004'
S37C4            EQU  H'0005'
S38C4            EQU  H'0006'
S39C4            EQU  H'0007'


;----- LCDDATA29 Bits -----------------------------------------------------
S40C4            EQU  H'0000'
S41C4            EQU  H'0001'
S42C4            EQU  H'0002'
S43C4            EQU  H'0003'
S44C4            EQU  H'0004'
S45C4            EQU  H'0005'


;----- LCDDATA30 Bits -----------------------------------------------------
S00C5            EQU  H'0000'
S01C5            EQU  H'0001'
S02C5            EQU  H'0002'
S03C5            EQU  H'0003'
S04C5            EQU  H'0004'
S05C5            EQU  H'0005'
S06C5            EQU  H'0006'
S07C5            EQU  H'0007'


;----- LCDDATA31 Bits -----------------------------------------------------
S08C5            EQU  H'0000'
S09C5            EQU  H'0001'
S10C5            EQU  H'0002'
S11C5            EQU  H'0003'
S12C5            EQU  H'0004'
S13C5            EQU  H'0005'
S14C5            EQU  H'0006'
S15C5            EQU  H'0007'


;----- LCDDATA32 Bits -----------------------------------------------------
S16C5            EQU  H'0000'
S17C5            EQU  H'0001'
S18C5            EQU  H'0002'
S19C5            EQU  H'0003'
S20C5            EQU  H'0004'
S21C5            EQU  H'0005'
S22C5            EQU  H'0006'
S23C5            EQU  H'0007'


;----- LCDDATA33 Bits -----------------------------------------------------
S24C5            EQU  H'0000'
S25C5            EQU  H'0001'
S26C5            EQU  H'0002'
S27C5            EQU  H'0003'
S28C5            EQU  H'0004'
S29C5            EQU  H'0005'
S30C5            EQU  H'0006'
S31C5            EQU  H'0007'


;----- LCDDATA34 Bits -----------------------------------------------------
S32C5            EQU  H'0000'
S33C5            EQU  H'0001'
S34C5            EQU  H'0002'
S35C5            EQU  H'0003'
S36C5            EQU  H'0004'
S37C5            EQU  H'0005'
S38C5            EQU  H'0006'
S39C5            EQU  H'0007'


;----- LCDDATA35 Bits -----------------------------------------------------
S40C5            EQU  H'0000'
S41C5            EQU  H'0001'
S42C5            EQU  H'0002'
S43C5            EQU  H'0003'
S44C5            EQU  H'0004'
S45C5            EQU  H'0005'


;----- LCDDATA36 Bits -----------------------------------------------------
S00C6            EQU  H'0000'
S01C6            EQU  H'0001'
S02C6            EQU  H'0002'
S03C6            EQU  H'0003'
S04C6            EQU  H'0004'
S05C6            EQU  H'0005'
S06C6            EQU  H'0006'
S07C6            EQU  H'0007'


;----- LCDDATA37 Bits -----------------------------------------------------
S08C6            EQU  H'0000'
S09C6            EQU  H'0001'
S10C6            EQU  H'0002'
S11C6            EQU  H'0003'
S12C6            EQU  H'0004'
S13C6            EQU  H'0005'
S14C6            EQU  H'0006'
S15C6            EQU  H'0007'


;----- LCDDATA38 Bits -----------------------------------------------------
S16C6            EQU  H'0000'
S17C6            EQU  H'0001'
S18C6            EQU  H'0002'
S19C6            EQU  H'0003'
S20C6            EQU  H'0004'
S21C6            EQU  H'0005'
S22C6            EQU  H'0006'
S23C6            EQU  H'0007'


;----- LCDDATA39 Bits -----------------------------------------------------
S24C6            EQU  H'0000'
S25C6            EQU  H'0001'
S26C6            EQU  H'0002'
S27C6            EQU  H'0003'
S28C6            EQU  H'0004'
S29C6            EQU  H'0005'
S30C6            EQU  H'0006'
S31C6            EQU  H'0007'


;----- LCDDATA40 Bits -----------------------------------------------------
S32C6            EQU  H'0000'
S33C6            EQU  H'0001'
S34C6            EQU  H'0002'
S35C6            EQU  H'0003'
S36C6            EQU  H'0004'
S37C6            EQU  H'0005'
S38C6            EQU  H'0006'
S39C6            EQU  H'0007'


;----- LCDDATA41 Bits -----------------------------------------------------
S40C6            EQU  H'0000'
S41C6            EQU  H'0001'
S42C6            EQU  H'0002'
S43C6            EQU  H'0003'
S44C6            EQU  H'0004'
S45C6            EQU  H'0005'


;----- LCDDATA42 Bits -----------------------------------------------------
S00C7            EQU  H'0000'
S01C7            EQU  H'0001'
S02C7            EQU  H'0002'
S03C7            EQU  H'0003'
S04C7            EQU  H'0004'
S05C7            EQU  H'0005'
S06C7            EQU  H'0006'
S07C7            EQU  H'0007'


;----- LCDDATA43 Bits -----------------------------------------------------
S08C7            EQU  H'0000'
S09C7            EQU  H'0001'
S10C7            EQU  H'0002'
S11C7            EQU  H'0003'
S12C7            EQU  H'0004'
S13C7            EQU  H'0005'
S14C7            EQU  H'0006'
S15C7            EQU  H'0007'


;----- LCDDATA44 Bits -----------------------------------------------------
S16C7            EQU  H'0000'
S17C7            EQU  H'0001'
S18C7            EQU  H'0002'
S19C7            EQU  H'0003'
S20C7            EQU  H'0004'
S21C7            EQU  H'0005'
S22C7            EQU  H'0006'
S23C7            EQU  H'0007'


;----- LCDDATA45 Bits -----------------------------------------------------
S24C7            EQU  H'0000'
S25C7            EQU  H'0001'
S26C7            EQU  H'0002'
S27C7            EQU  H'0003'
S28C7            EQU  H'0004'
S29C7            EQU  H'0005'
S30C7            EQU  H'0006'
S31C7            EQU  H'0007'


;----- LCDDATA46 Bits -----------------------------------------------------
S32C7            EQU  H'0000'
S33C7            EQU  H'0001'
S34C7            EQU  H'0002'
S35C7            EQU  H'0003'
S36C7            EQU  H'0004'
S37C7            EQU  H'0005'
S38C7            EQU  H'0006'
S39C7            EQU  H'0007'


;----- LCDDATA47 Bits -----------------------------------------------------
S40C7            EQU  H'0000'
S41C7            EQU  H'0001'
S42C7            EQU  H'0002'
S43C7            EQU  H'0003'
S44C7            EQU  H'0004'
S45C7            EQU  H'0005'


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
LC1D1S6          EQU  H'0006'
LC1D1S7          EQU  H'0007'



D1S0             EQU  H'0000'
D1S1             EQU  H'0001'
D1S2             EQU  H'0002'
D1S3             EQU  H'0003'
D1S4             EQU  H'0004'
D1S5             EQU  H'0005'
D1S6             EQU  H'0006'
D1S7             EQU  H'0007'


;----- CLC1SEL1 Bits -----------------------------------------------------
LC1D2S0          EQU  H'0000'
LC1D2S1          EQU  H'0001'
LC1D2S2          EQU  H'0002'
LC1D2S3          EQU  H'0003'
LC1D2S4          EQU  H'0004'
LC1D2S5          EQU  H'0005'
LC1D2S6          EQU  H'0006'
LC1D2S7          EQU  H'0007'



D2S0             EQU  H'0000'
D2S1             EQU  H'0001'
D2S2             EQU  H'0002'
D2S3             EQU  H'0003'
D2S4             EQU  H'0004'
D2S5             EQU  H'0005'
D2S6             EQU  H'0006'
D2S7             EQU  H'0007'


;----- CLC1SEL2 Bits -----------------------------------------------------
LC1D3S0          EQU  H'0000'
LC1D3S1          EQU  H'0001'
LC1D3S2          EQU  H'0002'
LC1D3S3          EQU  H'0003'
LC1D3S4          EQU  H'0004'
LC1D3S5          EQU  H'0005'
LC1D3S6          EQU  H'0006'
LC1D3S7          EQU  H'0007'



D3S0             EQU  H'0000'
D3S1             EQU  H'0001'
D3S2             EQU  H'0002'
D3S3             EQU  H'0003'
D3S4             EQU  H'0004'
D3S5             EQU  H'0005'
D3S6             EQU  H'0006'
D3S7             EQU  H'0007'


;----- CLC1SEL3 Bits -----------------------------------------------------
LC1D4S0          EQU  H'0000'
LC1D4S1          EQU  H'0001'
LC1D4S2          EQU  H'0002'
LC1D4S3          EQU  H'0003'
LC1D4S4          EQU  H'0004'
LC1D4S5          EQU  H'0005'
LC1D4S6          EQU  H'0006'
LC1D4S7          EQU  H'0007'



D4S0             EQU  H'0000'
D4S1             EQU  H'0001'
D4S2             EQU  H'0002'
D4S3             EQU  H'0003'
D4S4             EQU  H'0004'
D4S5             EQU  H'0005'
D4S6             EQU  H'0006'
D4S7             EQU  H'0007'


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
LC2D1S6          EQU  H'0006'
LC2D1S7          EQU  H'0007'



D1S0             EQU  H'0000'
D1S1             EQU  H'0001'
D1S2             EQU  H'0002'
D1S3             EQU  H'0003'
D1S4             EQU  H'0004'
D1S5             EQU  H'0005'
D1S6             EQU  H'0006'
D1S7             EQU  H'0007'


;----- CLC2SEL1 Bits -----------------------------------------------------
LC2D2S0          EQU  H'0000'
LC2D2S1          EQU  H'0001'
LC2D2S2          EQU  H'0002'
LC2D2S3          EQU  H'0003'
LC2D2S4          EQU  H'0004'
LC2D2S5          EQU  H'0005'
LC2D2S6          EQU  H'0006'
LC2D2S7          EQU  H'0007'



D2S0             EQU  H'0000'
D2S1             EQU  H'0001'
D2S2             EQU  H'0002'
D2S3             EQU  H'0003'
D2S4             EQU  H'0004'
D2S5             EQU  H'0005'
D2S6             EQU  H'0006'
D2S7             EQU  H'0007'


;----- CLC2SEL2 Bits -----------------------------------------------------
LC2D3S0          EQU  H'0000'
LC2D3S1          EQU  H'0001'
LC2D3S2          EQU  H'0002'
LC2D3S3          EQU  H'0003'
LC2D3S4          EQU  H'0004'
LC2D3S5          EQU  H'0005'
LC2D3S6          EQU  H'0006'
LC2D3S7          EQU  H'0007'



D3S0             EQU  H'0000'
D3S1             EQU  H'0001'
D3S2             EQU  H'0002'
D3S3             EQU  H'0003'
D3S4             EQU  H'0004'
D3S5             EQU  H'0005'
D3S6             EQU  H'0006'
D3S7             EQU  H'0007'


;----- CLC2SEL3 Bits -----------------------------------------------------
LC2D4S0          EQU  H'0000'
LC2D4S1          EQU  H'0001'
LC2D4S2          EQU  H'0002'
LC2D4S3          EQU  H'0003'
LC2D4S4          EQU  H'0004'
LC2D4S5          EQU  H'0005'
LC2D4S6          EQU  H'0006'
LC2D4S7          EQU  H'0007'



D4S0             EQU  H'0000'
D4S1             EQU  H'0001'
D4S2             EQU  H'0002'
D4S3             EQU  H'0003'
D4S4             EQU  H'0004'
D4S5             EQU  H'0005'
D4S6             EQU  H'0006'
D4S7             EQU  H'0007'


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
LC3D1S6          EQU  H'0006'
LC3D1S7          EQU  H'0007'



D1S0             EQU  H'0000'
D1S1             EQU  H'0001'
D1S2             EQU  H'0002'
D1S3             EQU  H'0003'
D1S4             EQU  H'0004'
D1S5             EQU  H'0005'
D1S6             EQU  H'0006'
D1S7             EQU  H'0007'


;----- CLC3SEL1 Bits -----------------------------------------------------
LC3D2S0          EQU  H'0000'
LC3D2S1          EQU  H'0001'
LC3D2S2          EQU  H'0002'
LC3D2S3          EQU  H'0003'
LC3D2S4          EQU  H'0004'
LC3D2S5          EQU  H'0005'
LC3D2S6          EQU  H'0006'
LC3D2S7          EQU  H'0007'



D2S0             EQU  H'0000'
D2S1             EQU  H'0001'
D2S2             EQU  H'0002'
D2S3             EQU  H'0003'
D2S4             EQU  H'0004'
D2S5             EQU  H'0005'
D2S6             EQU  H'0006'
D2S7             EQU  H'0007'


;----- CLC3SEL2 Bits -----------------------------------------------------
LC3D3S0          EQU  H'0000'
LC3D3S1          EQU  H'0001'
LC3D3S2          EQU  H'0002'
LC3D3S3          EQU  H'0003'
LC3D3S4          EQU  H'0004'
LC3D3S5          EQU  H'0005'
LC3D3S6          EQU  H'0006'
LC3D3S7          EQU  H'0007'



D3S0             EQU  H'0000'
D3S1             EQU  H'0001'
D3S2             EQU  H'0002'
D3S3             EQU  H'0003'
D3S4             EQU  H'0004'
D3S5             EQU  H'0005'
D3S6             EQU  H'0006'
D3S7             EQU  H'0007'


;----- CLC3SEL3 Bits -----------------------------------------------------
LC3D4S0          EQU  H'0000'
LC3D4S1          EQU  H'0001'
LC3D4S2          EQU  H'0002'
LC3D4S3          EQU  H'0003'
LC3D4S4          EQU  H'0004'
LC3D4S5          EQU  H'0005'
LC3D4S6          EQU  H'0006'
LC3D4S7          EQU  H'0007'



D4S0             EQU  H'0000'
D4S1             EQU  H'0001'
D4S2             EQU  H'0002'
D4S3             EQU  H'0003'
D4S4             EQU  H'0004'
D4S5             EQU  H'0005'
D4S6             EQU  H'0006'
D4S7             EQU  H'0007'


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
LC4D1S6          EQU  H'0006'
LC4D1S7          EQU  H'0007'



D1S0             EQU  H'0000'
D1S1             EQU  H'0001'
D1S2             EQU  H'0002'
D1S3             EQU  H'0003'
D1S4             EQU  H'0004'
D1S5             EQU  H'0005'
D1S6             EQU  H'0006'
D1S7             EQU  H'0007'


;----- CLC4SEL1 Bits -----------------------------------------------------
LC4D2S0          EQU  H'0000'
LC4D2S1          EQU  H'0001'
LC4D2S2          EQU  H'0002'
LC4D2S3          EQU  H'0003'
LC4D2S4          EQU  H'0004'
LC4D2S5          EQU  H'0005'
LC4D2S6          EQU  H'0006'
LC4D2S7          EQU  H'0007'



D2S0             EQU  H'0000'
D2S1             EQU  H'0001'
D2S2             EQU  H'0002'
D2S3             EQU  H'0003'
D2S4             EQU  H'0004'
D2S5             EQU  H'0005'
D2S6             EQU  H'0006'
D2S7             EQU  H'0007'


;----- CLC4SEL2 Bits -----------------------------------------------------
LC4D3S0          EQU  H'0000'
LC4D3S1          EQU  H'0001'
LC4D3S2          EQU  H'0002'
LC4D3S3          EQU  H'0003'
LC4D3S4          EQU  H'0004'
LC4D3S5          EQU  H'0005'
LC4D3S6          EQU  H'0006'
LC4D3S7          EQU  H'0007'



D3S0             EQU  H'0000'
D3S1             EQU  H'0001'
D3S2             EQU  H'0002'
D3S3             EQU  H'0003'
D3S4             EQU  H'0004'
D3S5             EQU  H'0005'
D3S6             EQU  H'0006'
D3S7             EQU  H'0007'


;----- CLC4SEL3 Bits -----------------------------------------------------
LC4D4S0          EQU  H'0000'
LC4D4S1          EQU  H'0001'
LC4D4S2          EQU  H'0002'
LC4D4S3          EQU  H'0003'
LC4D4S4          EQU  H'0004'
LC4D4S5          EQU  H'0005'
LC4D4S6          EQU  H'0006'
LC4D4S7          EQU  H'0007'



D4S0             EQU  H'0000'
D4S1             EQU  H'0001'
D4S2             EQU  H'0002'
D4S3             EQU  H'0003'
D4S4             EQU  H'0004'
D4S5             EQU  H'0005'
D4S6             EQU  H'0006'
D4S7             EQU  H'0007'


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


;----- RF0PPS Bits -----------------------------------------------------
RF0PPS0          EQU  H'0000'
RF0PPS1          EQU  H'0001'
RF0PPS2          EQU  H'0002'
RF0PPS3          EQU  H'0003'
RF0PPS4          EQU  H'0004'
RF0PPS5          EQU  H'0005'


;----- RF1PPS Bits -----------------------------------------------------
RF1PPS0          EQU  H'0000'
RF1PPS1          EQU  H'0001'
RF1PPS2          EQU  H'0002'
RF1PPS3          EQU  H'0003'
RF1PPS4          EQU  H'0004'
RF1PPS5          EQU  H'0005'


;----- RF2PPS Bits -----------------------------------------------------
RF2PPS0          EQU  H'0000'
RF2PPS1          EQU  H'0001'
RF2PPS2          EQU  H'0002'
RF2PPS3          EQU  H'0003'
RF2PPS4          EQU  H'0004'
RF2PPS5          EQU  H'0005'


;----- RF3PPS Bits -----------------------------------------------------
RF3PPS0          EQU  H'0000'
RF3PPS1          EQU  H'0001'
RF3PPS2          EQU  H'0002'
RF3PPS3          EQU  H'0003'
RF3PPS4          EQU  H'0004'
RF3PPS5          EQU  H'0005'


;----- RF4PPS Bits -----------------------------------------------------
RF4PPS0          EQU  H'0000'
RF4PPS1          EQU  H'0001'
RF4PPS2          EQU  H'0002'
RF4PPS3          EQU  H'0003'
RF4PPS4          EQU  H'0004'
RF4PPS5          EQU  H'0005'


;----- RF5PPS Bits -----------------------------------------------------
RF5PPS0          EQU  H'0000'
RF5PPS1          EQU  H'0001'
RF5PPS2          EQU  H'0002'
RF5PPS3          EQU  H'0003'
RF5PPS4          EQU  H'0004'
RF5PPS5          EQU  H'0005'


;----- RF6PPS Bits -----------------------------------------------------
RF6PPS0          EQU  H'0000'
RF6PPS1          EQU  H'0001'
RF6PPS2          EQU  H'0002'
RF6PPS3          EQU  H'0003'
RF6PPS4          EQU  H'0004'
RF6PPS5          EQU  H'0005'


;----- RF7PPS Bits -----------------------------------------------------
RF7PPS0          EQU  H'0000'
RF7PPS1          EQU  H'0001'
RF7PPS2          EQU  H'0002'
RF7PPS3          EQU  H'0003'
RF7PPS4          EQU  H'0004'
RF7PPS5          EQU  H'0005'


;----- RG0PPS Bits -----------------------------------------------------
RG0PPS0          EQU  H'0000'
RG0PPS1          EQU  H'0001'
RG0PPS2          EQU  H'0002'
RG0PPS3          EQU  H'0003'
RG0PPS4          EQU  H'0004'
RG0PPS5          EQU  H'0005'


;----- RG1PPS Bits -----------------------------------------------------
RG1PPS0          EQU  H'0000'
RG1PPS1          EQU  H'0001'
RG1PPS2          EQU  H'0002'
RG1PPS3          EQU  H'0003'
RG1PPS4          EQU  H'0004'
RG1PPS5          EQU  H'0005'


;----- RG2PPS Bits -----------------------------------------------------
RG2PPS0          EQU  H'0000'
RG2PPS1          EQU  H'0001'
RG2PPS2          EQU  H'0002'
RG2PPS3          EQU  H'0003'
RG2PPS4          EQU  H'0004'
RG2PPS5          EQU  H'0005'


;----- RG3PPS Bits -----------------------------------------------------
RG3PPS0          EQU  H'0000'
RG3PPS1          EQU  H'0001'
RG3PPS2          EQU  H'0002'
RG3PPS3          EQU  H'0003'
RG3PPS4          EQU  H'0004'
RG3PPS5          EQU  H'0005'


;----- RG4PPS Bits -----------------------------------------------------
RG4PPS0          EQU  H'0000'
RG4PPS1          EQU  H'0001'
RG4PPS2          EQU  H'0002'
RG4PPS3          EQU  H'0003'
RG4PPS4          EQU  H'0004'
RG4PPS5          EQU  H'0005'


;----- RG6PPS Bits -----------------------------------------------------
RG6PPS0          EQU  H'0000'
RG6PPS1          EQU  H'0001'
RG6PPS2          EQU  H'0002'
RG6PPS3          EQU  H'0003'
RG6PPS4          EQU  H'0004'
RG6PPS5          EQU  H'0005'


;----- RG7PPS Bits -----------------------------------------------------
RG7PPS0          EQU  H'0000'
RG7PPS1          EQU  H'0001'
RG7PPS2          EQU  H'0002'
RG7PPS3          EQU  H'0003'
RG7PPS4          EQU  H'0004'
RG7PPS5          EQU  H'0005'


;----- RH0PPS Bits -----------------------------------------------------
RH0PPS0          EQU  H'0000'
RH0PPS1          EQU  H'0001'
RH0PPS2          EQU  H'0002'
RH0PPS3          EQU  H'0003'
RH0PPS4          EQU  H'0004'
RH0PPS5          EQU  H'0005'


;----- RH1PPS Bits -----------------------------------------------------
RH1PPS0          EQU  H'0000'
RH1PPS1          EQU  H'0001'
RH1PPS2          EQU  H'0002'
RH1PPS3          EQU  H'0003'
RH1PPS4          EQU  H'0004'
RH1PPS5          EQU  H'0005'


;----- RH2PPS Bits -----------------------------------------------------
RH2PPS0          EQU  H'0000'
RH2PPS1          EQU  H'0001'
RH2PPS2          EQU  H'0002'
RH2PPS3          EQU  H'0003'
RH2PPS4          EQU  H'0004'
RH2PPS5          EQU  H'0005'


;----- RH3PPS Bits -----------------------------------------------------
RH3PPS0          EQU  H'0000'
RH3PPS1          EQU  H'0001'
RH3PPS2          EQU  H'0002'
RH3PPS3          EQU  H'0003'
RH3PPS4          EQU  H'0004'
RH3PPS5          EQU  H'0005'


;----- ANSELF Bits -----------------------------------------------------
ANSF0            EQU  H'0000'
ANSF1            EQU  H'0001'
ANSF2            EQU  H'0002'
ANSF3            EQU  H'0003'
ANSF4            EQU  H'0004'
ANSF5            EQU  H'0005'
ANSF6            EQU  H'0006'
ANSF7            EQU  H'0007'


;----- WPUF Bits -----------------------------------------------------
WPUF0            EQU  H'0000'
WPUF1            EQU  H'0001'
WPUF2            EQU  H'0002'
WPUF3            EQU  H'0003'
WPUF4            EQU  H'0004'
WPUF5            EQU  H'0005'
WPUF6            EQU  H'0006'
WPUF7            EQU  H'0007'


;----- ODCONF Bits -----------------------------------------------------
ODCF0            EQU  H'0000'
ODCF1            EQU  H'0001'
ODCF2            EQU  H'0002'
ODCF3            EQU  H'0003'
ODCF4            EQU  H'0004'
ODCF5            EQU  H'0005'
ODCF6            EQU  H'0006'
ODCF7            EQU  H'0007'


;----- SLRCONF Bits -----------------------------------------------------
SLRF0            EQU  H'0000'
SLRF1            EQU  H'0001'
SLRF2            EQU  H'0002'
SLRF3            EQU  H'0003'
SLRF4            EQU  H'0004'
SLRF5            EQU  H'0005'
SLRF6            EQU  H'0006'
SLRF7            EQU  H'0007'


;----- INLVLF Bits -----------------------------------------------------
INLVLF0          EQU  H'0000'
INLVLF1          EQU  H'0001'
INLVLF2          EQU  H'0002'
INLVLF3          EQU  H'0003'
INLVLF4          EQU  H'0004'
INLVLF5          EQU  H'0005'
INLVLF6          EQU  H'0006'
INLVLF7          EQU  H'0007'


;----- HIDRVF Bits -----------------------------------------------------
HIDF7            EQU  H'0007'


;----- ANSELG Bits -----------------------------------------------------
ANSG0            EQU  H'0000'
ANSG1            EQU  H'0001'
ANSG2            EQU  H'0002'
ANSG3            EQU  H'0003'
ANSG4            EQU  H'0004'
ANSG6            EQU  H'0006'
ANSG7            EQU  H'0007'


;----- WPUG Bits -----------------------------------------------------
WPUG0            EQU  H'0000'
WPUG1            EQU  H'0001'
WPUG2            EQU  H'0002'
WPUG3            EQU  H'0003'
WPUG4            EQU  H'0004'
WPUG5            EQU  H'0005'
WPUG6            EQU  H'0006'
WPUG7            EQU  H'0007'


;----- ODCONG Bits -----------------------------------------------------
ODCG0            EQU  H'0000'
ODCG1            EQU  H'0001'
ODCG2            EQU  H'0002'
ODCG3            EQU  H'0003'
ODCG4            EQU  H'0004'
ODCG6            EQU  H'0006'
ODCG7            EQU  H'0007'


;----- SLRCONG Bits -----------------------------------------------------
SLRG0            EQU  H'0000'
SLRG1            EQU  H'0001'
SLRG2            EQU  H'0002'
SLRG3            EQU  H'0003'
SLRG4            EQU  H'0004'
SLRG6            EQU  H'0006'
SLRG7            EQU  H'0007'


;----- INLVLG Bits -----------------------------------------------------
INLVLG0          EQU  H'0000'
INLVLG1          EQU  H'0001'
INLVLG2          EQU  H'0002'
INLVLG3          EQU  H'0003'
INLVLG4          EQU  H'0004'
INLVLG5          EQU  H'0005'
INLVLG6          EQU  H'0006'
INLVLG7          EQU  H'0007'


;----- IOCGP Bits -----------------------------------------------------
IOCGP5           EQU  H'0005'


;----- IOCGN Bits -----------------------------------------------------
IOCGN5           EQU  H'0005'


;----- IOCGF Bits -----------------------------------------------------
IOCGF5           EQU  H'0005'


;----- WPUH Bits -----------------------------------------------------
WPUH0            EQU  H'0000'
WPUH1            EQU  H'0001'
WPUH2            EQU  H'0002'
WPUH3            EQU  H'0003'


;----- ODCONH Bits -----------------------------------------------------
ODCH0            EQU  H'0000'
ODCH1            EQU  H'0001'
ODCH2            EQU  H'0002'
ODCH3            EQU  H'0003'


;----- SLRCONH Bits -----------------------------------------------------
SLRH0            EQU  H'0000'
SLRH1            EQU  H'0001'
SLRH2            EQU  H'0002'
SLRH3            EQU  H'0003'


;----- INLVLH Bits -----------------------------------------------------
INLVLH0          EQU  H'0000'
INLVLH1          EQU  H'0001'
INLVLH2          EQU  H'0002'
INLVLH3          EQU  H'0003'


;----- PPSLOCK Bits -----------------------------------------------------
PPSLOCKED        EQU  H'0000'


;----- INTPPS Bits -----------------------------------------------------
INTPPS0          EQU  H'0000'
INTPPS1          EQU  H'0001'
INTPPS2          EQU  H'0002'
INTPPS3          EQU  H'0003'
INTPPS4          EQU  H'0004'
INTPPS5          EQU  H'0005'


;----- T0CKIPPS Bits -----------------------------------------------------
T0CKIPPS0        EQU  H'0000'
T0CKIPPS1        EQU  H'0001'
T0CKIPPS2        EQU  H'0002'
T0CKIPPS3        EQU  H'0003'
T0CKIPPS4        EQU  H'0004'
T0CKIPPS5        EQU  H'0005'


;----- T1CKIPPS Bits -----------------------------------------------------
T1CKIPPS0        EQU  H'0000'
T1CKIPPS1        EQU  H'0001'
T1CKIPPS2        EQU  H'0002'
T1CKIPPS3        EQU  H'0003'
T1CKIPPS4        EQU  H'0004'
T1CKIPPS5        EQU  H'0005'


;----- T1GPPS Bits -----------------------------------------------------
T1GPPS0          EQU  H'0000'
T1GPPS1          EQU  H'0001'
T1GPPS2          EQU  H'0002'
T1GPPS3          EQU  H'0003'
T1GPPS4          EQU  H'0004'
T1GPPS5          EQU  H'0005'


;----- T2INPPS Bits -----------------------------------------------------
T2INPPS0         EQU  H'0000'
T2INPPS1         EQU  H'0001'
T2INPPS2         EQU  H'0002'
T2INPPS3         EQU  H'0003'
T2INPPS4         EQU  H'0004'
T2INPPS5         EQU  H'0005'


;----- T4INPPS Bits -----------------------------------------------------
T4INPPS0         EQU  H'0000'
T4INPPS1         EQU  H'0001'
T4INPPS2         EQU  H'0002'
T4INPPS3         EQU  H'0003'
T4INPPS4         EQU  H'0004'
T4INPPS5         EQU  H'0005'


;----- CCP1PPS Bits -----------------------------------------------------
CCP1PPS0         EQU  H'0000'
CCP1PPS1         EQU  H'0001'
CCP1PPS2         EQU  H'0002'
CCP1PPS3         EQU  H'0003'
CCP1PPS4         EQU  H'0004'
CCP1PPS5         EQU  H'0005'


;----- CCP2PPS Bits -----------------------------------------------------
CCP2PPS0         EQU  H'0000'
CCP2PPS1         EQU  H'0001'
CCP2PPS2         EQU  H'0002'
CCP2PPS3         EQU  H'0003'
CCP2PPS4         EQU  H'0004'
CCP2PPS5         EQU  H'0005'


;----- SMT1WINPPS Bits -----------------------------------------------------
SMT1WINPPS0      EQU  H'0000'
SMT1WINPPS1      EQU  H'0001'
SMT1WINPPS2      EQU  H'0002'
SMT1WINPPS3      EQU  H'0003'
SMT1WINPPS4      EQU  H'0004'
SMT1WINPPS5      EQU  H'0005'


;----- SMT1SIGPPS Bits -----------------------------------------------------
SMT1SIGPPS0      EQU  H'0000'
SMT1SIGPPS1      EQU  H'0001'
SMT1SIGPPS2      EQU  H'0002'
SMT1SIGPPS3      EQU  H'0003'
SMT1SIGPPS4      EQU  H'0004'
SMT1SIGPPS5      EQU  H'0005'


;----- CWG1PPS Bits -----------------------------------------------------
CWG1PPS0         EQU  H'0000'
CWG1PPS1         EQU  H'0001'
CWG1PPS2         EQU  H'0002'
CWG1PPS3         EQU  H'0003'
CWG1PPS4         EQU  H'0004'
CWG1PPS5         EQU  H'0005'


;----- CLCIN0PPS Bits -----------------------------------------------------
CLCIN0PPS0       EQU  H'0000'
CLCIN0PPS1       EQU  H'0001'
CLCIN0PPS2       EQU  H'0002'
CLCIN0PPS3       EQU  H'0003'
CLCIN0PPS4       EQU  H'0004'
CLCIN0PPS5       EQU  H'0005'


;----- CLCIN1PPS Bits -----------------------------------------------------
CLCIN1PPS0       EQU  H'0000'
CLCIN1PPS1       EQU  H'0001'
CLCIN1PPS2       EQU  H'0002'
CLCIN1PPS3       EQU  H'0003'
CLCIN1PPS4       EQU  H'0004'
CLCIN1PPS5       EQU  H'0005'


;----- CLCIN2PPS Bits -----------------------------------------------------
CLCIN2PPS0       EQU  H'0000'
CLCIN2PPS1       EQU  H'0001'
CLCIN2PPS2       EQU  H'0002'
CLCIN2PPS3       EQU  H'0003'
CLCIN2PPS4       EQU  H'0004'
CLCIN2PPS5       EQU  H'0005'


;----- CLCIN3PPS Bits -----------------------------------------------------
CLCIN3PPS0       EQU  H'0000'
CLCIN3PPS1       EQU  H'0001'
CLCIN3PPS2       EQU  H'0002'
CLCIN3PPS3       EQU  H'0003'
CLCIN3PPS4       EQU  H'0004'
CLCIN3PPS5       EQU  H'0005'


;----- ADACTPPS Bits -----------------------------------------------------
ADACTPPS0        EQU  H'0000'
ADACTPPS1        EQU  H'0001'
ADACTPPS2        EQU  H'0002'
ADACTPPS3        EQU  H'0003'
ADACTPPS4        EQU  H'0004'
ADACTPPS5        EQU  H'0005'


;----- SSP1CLKPPS Bits -----------------------------------------------------
SSP1CLKPPS0      EQU  H'0000'
SSP1CLKPPS1      EQU  H'0001'
SSP1CLKPPS2      EQU  H'0002'
SSP1CLKPPS3      EQU  H'0003'
SSP1CLKPPS4      EQU  H'0004'
SSP1CLKPPS5      EQU  H'0005'


;----- SSP1DATPPS Bits -----------------------------------------------------
SSP1DATPPS0      EQU  H'0000'
SSP1DATPPS1      EQU  H'0001'
SSP1DATPPS2      EQU  H'0002'
SSP1DATPPS3      EQU  H'0003'
SSP1DATPPS4      EQU  H'0004'
SSP1DATPPS5      EQU  H'0005'


;----- SSP1SSPPS Bits -----------------------------------------------------
SSP1SSPPS0       EQU  H'0000'
SSP1SSPPS1       EQU  H'0001'
SSP1SSPPS2       EQU  H'0002'
SSP1SSPPS3       EQU  H'0003'
SSP1SSPPS4       EQU  H'0004'
SSP1SSPPS5       EQU  H'0005'


;----- RX1PPS Bits -----------------------------------------------------
RX1PPS0          EQU  H'0000'
RX1PPS1          EQU  H'0001'
RX1PPS2          EQU  H'0002'
RX1PPS3          EQU  H'0003'
RX1PPS4          EQU  H'0004'
RX1PPS5          EQU  H'0005'


;----- TX1PPS Bits -----------------------------------------------------
TX1PPS0          EQU  H'0000'
TX1PPS1          EQU  H'0001'
TX1PPS2          EQU  H'0002'
TX1PPS3          EQU  H'0003'
TX1PPS4          EQU  H'0004'
TX1PPS5          EQU  H'0005'


;----- RX2PPS Bits -----------------------------------------------------
RX2PPS0          EQU  H'0000'
RX2PPS1          EQU  H'0001'
RX2PPS2          EQU  H'0002'
RX2PPS3          EQU  H'0003'
RX2PPS4          EQU  H'0004'
RX2PPS5          EQU  H'0005'


;----- TX2PPS Bits -----------------------------------------------------
TX2PPS0          EQU  H'0000'
TX2PPS1          EQU  H'0001'
TX2PPS2          EQU  H'0002'
TX2PPS3          EQU  H'0003'
TX2PPS4          EQU  H'0004'
TX2PPS5          EQU  H'0005'


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


;----- RA3PPS Bits -----------------------------------------------------
RA3PPS0          EQU  H'0000'
RA3PPS1          EQU  H'0001'
RA3PPS2          EQU  H'0002'
RA3PPS3          EQU  H'0003'
RA3PPS4          EQU  H'0004'
RA3PPS5          EQU  H'0005'


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


;----- RA6PPS Bits -----------------------------------------------------
RA6PPS0          EQU  H'0000'
RA6PPS1          EQU  H'0001'
RA6PPS2          EQU  H'0002'
RA6PPS3          EQU  H'0003'
RA6PPS4          EQU  H'0004'
RA6PPS5          EQU  H'0005'


;----- RA7PPS Bits -----------------------------------------------------
RA7PPS0          EQU  H'0000'
RA7PPS1          EQU  H'0001'
RA7PPS2          EQU  H'0002'
RA7PPS3          EQU  H'0003'
RA7PPS4          EQU  H'0004'
RA7PPS5          EQU  H'0005'


;----- RB0PPS Bits -----------------------------------------------------
RB0PPS0          EQU  H'0000'
RB0PPS1          EQU  H'0001'
RB0PPS2          EQU  H'0002'
RB0PPS3          EQU  H'0003'
RB0PPS4          EQU  H'0004'
RB0PPS5          EQU  H'0005'


;----- RB1PPS Bits -----------------------------------------------------
RB1PPS0          EQU  H'0000'
RB1PPS1          EQU  H'0001'
RB1PPS2          EQU  H'0002'
RB1PPS3          EQU  H'0003'
RB1PPS4          EQU  H'0004'
RB1PPS5          EQU  H'0005'


;----- RB2PPS Bits -----------------------------------------------------
RB2PPS0          EQU  H'0000'
RB2PPS1          EQU  H'0001'
RB2PPS2          EQU  H'0002'
RB2PPS3          EQU  H'0003'
RB2PPS4          EQU  H'0004'
RB2PPS5          EQU  H'0005'


;----- RB3PPS Bits -----------------------------------------------------
RB3PPS0          EQU  H'0000'
RB3PPS1          EQU  H'0001'
RB3PPS2          EQU  H'0002'
RB3PPS3          EQU  H'0003'
RB3PPS4          EQU  H'0004'
RB3PPS5          EQU  H'0005'


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


;----- RD0PPS Bits -----------------------------------------------------
RD0PPS0          EQU  H'0000'
RD0PPS1          EQU  H'0001'
RD0PPS2          EQU  H'0002'
RD0PPS3          EQU  H'0003'
RD0PPS4          EQU  H'0004'
RD0PPS5          EQU  H'0005'


;----- RD1PPS Bits -----------------------------------------------------
RD1PPS0          EQU  H'0000'
RD1PPS1          EQU  H'0001'
RD1PPS2          EQU  H'0002'
RD1PPS3          EQU  H'0003'
RD1PPS4          EQU  H'0004'
RD1PPS5          EQU  H'0005'


;----- RD2PPS Bits -----------------------------------------------------
RD2PPS0          EQU  H'0000'
RD2PPS1          EQU  H'0001'
RD2PPS2          EQU  H'0002'
RD2PPS3          EQU  H'0003'
RD2PPS4          EQU  H'0004'
RD2PPS5          EQU  H'0005'


;----- RD3PPS Bits -----------------------------------------------------
RD3PPS0          EQU  H'0000'
RD3PPS1          EQU  H'0001'
RD3PPS2          EQU  H'0002'
RD3PPS3          EQU  H'0003'
RD3PPS4          EQU  H'0004'
RD3PPS5          EQU  H'0005'


;----- RD4PPS Bits -----------------------------------------------------
RD4PPS0          EQU  H'0000'
RD4PPS1          EQU  H'0001'
RD4PPS2          EQU  H'0002'
RD4PPS3          EQU  H'0003'
RD4PPS4          EQU  H'0004'
RD4PPS5          EQU  H'0005'


;----- RD5PPS Bits -----------------------------------------------------
RD5PPS0          EQU  H'0000'
RD5PPS1          EQU  H'0001'
RD5PPS2          EQU  H'0002'
RD5PPS3          EQU  H'0003'
RD5PPS4          EQU  H'0004'
RD5PPS5          EQU  H'0005'


;----- RD6PPS Bits -----------------------------------------------------
RD6PPS0          EQU  H'0000'
RD6PPS1          EQU  H'0001'
RD6PPS2          EQU  H'0002'
RD6PPS3          EQU  H'0003'
RD6PPS4          EQU  H'0004'
RD6PPS5          EQU  H'0005'


;----- RD7PPS Bits -----------------------------------------------------
RD7PPS0          EQU  H'0000'
RD7PPS1          EQU  H'0001'
RD7PPS2          EQU  H'0002'
RD7PPS3          EQU  H'0003'
RD7PPS4          EQU  H'0004'
RD7PPS5          EQU  H'0005'


;----- RE0PPS Bits -----------------------------------------------------
RE0PPS0          EQU  H'0000'
RE0PPS1          EQU  H'0001'
RE0PPS2          EQU  H'0002'
RE0PPS3          EQU  H'0003'
RE0PPS4          EQU  H'0004'
RE0PPS5          EQU  H'0005'


;----- RE1PPS Bits -----------------------------------------------------
RE1PPS0          EQU  H'0000'
RE1PPS1          EQU  H'0001'
RE1PPS2          EQU  H'0002'
RE1PPS3          EQU  H'0003'
RE1PPS4          EQU  H'0004'
RE1PPS5          EQU  H'0005'


;----- RE3PPS Bits -----------------------------------------------------
RE3PPS0          EQU  H'0000'
RE3PPS1          EQU  H'0001'
RE3PPS2          EQU  H'0002'
RE3PPS3          EQU  H'0003'
RE3PPS4          EQU  H'0004'
RE3PPS5          EQU  H'0005'


;----- RE4PPS Bits -----------------------------------------------------
RE4PPS0          EQU  H'0000'
RE4PPS1          EQU  H'0001'
RE4PPS2          EQU  H'0002'
RE4PPS3          EQU  H'0003'
RE4PPS4          EQU  H'0004'
RE4PPS5          EQU  H'0005'


;----- RE5PPS Bits -----------------------------------------------------
RE5PPS0          EQU  H'0000'
RE5PPS1          EQU  H'0001'
RE5PPS2          EQU  H'0002'
RE5PPS3          EQU  H'0003'
RE5PPS4          EQU  H'0004'
RE5PPS5          EQU  H'0005'


;----- RE6PPS Bits -----------------------------------------------------
RE6PPS0          EQU  H'0000'
RE6PPS1          EQU  H'0001'
RE6PPS2          EQU  H'0002'
RE6PPS3          EQU  H'0003'
RE6PPS4          EQU  H'0004'
RE6PPS5          EQU  H'0005'


;----- RE7PPS Bits -----------------------------------------------------
RE7PPS0          EQU  H'0000'
RE7PPS1          EQU  H'0001'
RE7PPS2          EQU  H'0002'
RE7PPS3          EQU  H'0003'
RE7PPS4          EQU  H'0004'
RE7PPS5          EQU  H'0005'


;----- ANSELA Bits -----------------------------------------------------
ANSA0            EQU  H'0000'
ANSA1            EQU  H'0001'
ANSA2            EQU  H'0002'
ANSA3            EQU  H'0003'
ANSA4            EQU  H'0004'
ANSA6            EQU  H'0006'
ANSA7            EQU  H'0007'


;----- WPUA Bits -----------------------------------------------------
WPUA0            EQU  H'0000'
WPUA1            EQU  H'0001'
WPUA2            EQU  H'0002'
WPUA3            EQU  H'0003'
WPUA4            EQU  H'0004'
WPUA5            EQU  H'0005'
WPUA6            EQU  H'0006'
WPUA7            EQU  H'0007'


;----- ODCONA Bits -----------------------------------------------------
ODCA0            EQU  H'0000'
ODCA1            EQU  H'0001'
ODCA2            EQU  H'0002'
ODCA3            EQU  H'0003'
ODCA4            EQU  H'0004'
ODCA6            EQU  H'0006'
ODCA7            EQU  H'0007'


;----- SLRCONA Bits -----------------------------------------------------
SLRA0            EQU  H'0000'
SLRA1            EQU  H'0001'
SLRA2            EQU  H'0002'
SLRA3            EQU  H'0003'
SLRA4            EQU  H'0004'
SLRA6            EQU  H'0006'
SLRA7            EQU  H'0007'


;----- INLVLA Bits -----------------------------------------------------
INLVLA0          EQU  H'0000'
INLVLA1          EQU  H'0001'
INLVLA2          EQU  H'0002'
INLVLA3          EQU  H'0003'
INLVLA4          EQU  H'0004'
INLVLA5          EQU  H'0005'
INLVLA6          EQU  H'0006'
INLVLA7          EQU  H'0007'


;----- ANSELB Bits -----------------------------------------------------
ANSB0            EQU  H'0000'
ANSB1            EQU  H'0001'
ANSB2            EQU  H'0002'
ANSB3            EQU  H'0003'
ANSB4            EQU  H'0004'
ANSB5            EQU  H'0005'
ANSB6            EQU  H'0006'
ANSB7            EQU  H'0007'


;----- WPUB Bits -----------------------------------------------------
WPUB0            EQU  H'0000'
WPUB1            EQU  H'0001'
WPUB2            EQU  H'0002'
WPUB3            EQU  H'0003'
WPUB4            EQU  H'0004'
WPUB5            EQU  H'0005'
WPUB6            EQU  H'0006'
WPUB7            EQU  H'0007'


;----- ODCONB Bits -----------------------------------------------------
ODCB0            EQU  H'0000'
ODCB1            EQU  H'0001'
ODCB2            EQU  H'0002'
ODCB3            EQU  H'0003'
ODCB4            EQU  H'0004'
ODCB5            EQU  H'0005'
ODCB6            EQU  H'0006'
ODCB7            EQU  H'0007'


;----- SLRCONB Bits -----------------------------------------------------
SLRB0            EQU  H'0000'
SLRB1            EQU  H'0001'
SLRB2            EQU  H'0002'
SLRB3            EQU  H'0003'
SLRB4            EQU  H'0004'
SLRB5            EQU  H'0005'
SLRB6            EQU  H'0006'
SLRB7            EQU  H'0007'


;----- INLVLB Bits -----------------------------------------------------
INLVLB0          EQU  H'0000'
INLVLB1          EQU  H'0001'
INLVLB2          EQU  H'0002'
INLVLB3          EQU  H'0003'
INLVLB4          EQU  H'0004'
INLVLB5          EQU  H'0005'
INLVLB6          EQU  H'0006'
INLVLB7          EQU  H'0007'


;----- IOCBP Bits -----------------------------------------------------
IOCBP0           EQU  H'0000'
IOCBP1           EQU  H'0001'
IOCBP2           EQU  H'0002'
IOCBP3           EQU  H'0003'
IOCBP4           EQU  H'0004'
IOCBP5           EQU  H'0005'
IOCBP6           EQU  H'0006'
IOCBP7           EQU  H'0007'


;----- IOCBN Bits -----------------------------------------------------
IOCBN0           EQU  H'0000'
IOCBN1           EQU  H'0001'
IOCBN2           EQU  H'0002'
IOCBN3           EQU  H'0003'
IOCBN4           EQU  H'0004'
IOCBN5           EQU  H'0005'
IOCBN6           EQU  H'0006'
IOCBN7           EQU  H'0007'


;----- IOCBF Bits -----------------------------------------------------
IOCBF0           EQU  H'0000'
IOCBF1           EQU  H'0001'
IOCBF2           EQU  H'0002'
IOCBF3           EQU  H'0003'
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


;----- ANSELD Bits -----------------------------------------------------
ANSD0            EQU  H'0000'
ANSD1            EQU  H'0001'
ANSD2            EQU  H'0002'
ANSD3            EQU  H'0003'
ANSD4            EQU  H'0004'
ANSD5            EQU  H'0005'
ANSD6            EQU  H'0006'
ANSD7            EQU  H'0007'


;----- WPUD Bits -----------------------------------------------------
WPUD0            EQU  H'0000'
WPUD1            EQU  H'0001'
WPUD2            EQU  H'0002'
WPUD3            EQU  H'0003'
WPUD4            EQU  H'0004'
WPUD5            EQU  H'0005'
WPUD6            EQU  H'0006'
WPUD7            EQU  H'0007'


;----- ODCOND Bits -----------------------------------------------------
ODCD0            EQU  H'0000'
ODCD1            EQU  H'0001'
ODCD2            EQU  H'0002'
ODCD3            EQU  H'0003'
ODCD4            EQU  H'0004'
ODCD5            EQU  H'0005'
ODCD6            EQU  H'0006'
ODCD7            EQU  H'0007'


;----- SLRCOND Bits -----------------------------------------------------
SLRD0            EQU  H'0000'
SLRD1            EQU  H'0001'
SLRD2            EQU  H'0002'
SLRD3            EQU  H'0003'
SLRD4            EQU  H'0004'
SLRD5            EQU  H'0005'
SLRD6            EQU  H'0006'
SLRD7            EQU  H'0007'


;----- INLVLD Bits -----------------------------------------------------
INLVLD0          EQU  H'0000'
INLVLD1          EQU  H'0001'
INLVLD2          EQU  H'0002'
INLVLD3          EQU  H'0003'
INLVLD4          EQU  H'0004'
INLVLD5          EQU  H'0005'
INLVLD6          EQU  H'0006'
INLVLD7          EQU  H'0007'


;----- ANSELE Bits -----------------------------------------------------
ANSE0            EQU  H'0000'
ANSE1            EQU  H'0001'
ANSE3            EQU  H'0003'
ANSE4            EQU  H'0004'
ANSE5            EQU  H'0005'
ANSE6            EQU  H'0006'
ANSE7            EQU  H'0007'


;----- WPUE Bits -----------------------------------------------------
WPUE0            EQU  H'0000'
WPUE1            EQU  H'0001'
WPUE3            EQU  H'0003'
WPUE4            EQU  H'0004'
WPUE5            EQU  H'0005'
WPUE6            EQU  H'0006'
WPUE7            EQU  H'0007'


;----- ODCONE Bits -----------------------------------------------------
ODCE0            EQU  H'0000'
ODCE1            EQU  H'0001'
ODCE3            EQU  H'0003'
ODCE4            EQU  H'0004'
ODCE5            EQU  H'0005'
ODCE6            EQU  H'0006'
ODCE7            EQU  H'0007'


;----- SLRCONE Bits -----------------------------------------------------
SLRE0            EQU  H'0000'
SLRE1            EQU  H'0001'
SLRE3            EQU  H'0003'
SLRE4            EQU  H'0004'
SLRE5            EQU  H'0005'
SLRE6            EQU  H'0006'
SLRE7            EQU  H'0007'


;----- INLVLE Bits -----------------------------------------------------
INLVLE0          EQU  H'0000'
INLVLE1          EQU  H'0001'
INLVLE3          EQU  H'0003'
INLVLE4          EQU  H'0004'
INLVLE5          EQU  H'0005'
INLVLE6          EQU  H'0006'
INLVLE7          EQU  H'0007'


;----- IOCEP Bits -----------------------------------------------------
IOCEP0           EQU  H'0000'
IOCEP1           EQU  H'0001'
IOCEP3           EQU  H'0003'
IOCEP4           EQU  H'0004'
IOCEP5           EQU  H'0005'
IOCEP6           EQU  H'0006'
IOCEP7           EQU  H'0007'


;----- IOCEN Bits -----------------------------------------------------
IOCEN0           EQU  H'0000'
IOCEN1           EQU  H'0001'
IOCEN3           EQU  H'0003'
IOCEN4           EQU  H'0004'
IOCEN5           EQU  H'0005'
IOCEN6           EQU  H'0006'
IOCEN7           EQU  H'0007'


;----- IOCEF Bits -----------------------------------------------------
IOCEF0           EQU  H'0000'
IOCEF1           EQU  H'0001'
IOCEF3           EQU  H'0003'
IOCEF4           EQU  H'0004'
IOCEF5           EQU  H'0005'
IOCEF6           EQU  H'0006'
IOCEF7           EQU  H'0007'


;----- STATUS_SHAD Bits -----------------------------------------------------
C_SHAD           EQU  H'0000'
DC_SHAD          EQU  H'0001'
Z_SHAD           EQU  H'0002'



;==========================================================================
;
;       RAM Definitions
;
;==========================================================================
       __MAXRAM  H'1FFF'
       __BADRAM  H'001E'
       __BADRAM  H'0193'-H'019F'
       __BADRAM  H'0212'-H'021D'
       __BADRAM  H'021F'
       __BADRAM  H'0298'-H'029F'
       __BADRAM  H'0317'
       __BADRAM  H'031B'-H'031F'
       __BADRAM  H'038C'-H'039F'
       __BADRAM  H'040C'-H'041F'
       __BADRAM  H'049E'-H'049F'
       __BADRAM  H'050C'-H'051F'
       __BADRAM  H'058C'-H'059B'
       __BADRAM  H'0615'-H'061F'
       __BADRAM  H'068C'-H'069F'
       __BADRAM  H'0715'
       __BADRAM  H'071F'
       __BADRAM  H'078C'-H'0795'
       __BADRAM  H'079C'-H'079F'
       __BADRAM  H'0812'
       __BADRAM  H'0815'-H'0819'
       __BADRAM  H'0895'-H'089F'
       __BADRAM  H'090D'
       __BADRAM  H'0910'-H'091E'
       __BADRAM  H'098C'-H'098E'
       __BADRAM  H'0998'-H'099F'
       __BADRAM  H'0A0C'-H'0A18'
       __BADRAM  H'0A8C'-H'0A9F'
       __BADRAM  H'0B0C'-H'0B1F'
       __BADRAM  H'0B8C'-H'0B9F'
       __BADRAM  H'0C1D'-H'0C1E'
       __BADRAM  H'0C1F'
       __BADRAM  H'0C92'-H'0C9F'
       __BADRAM  H'0D0C'-H'0D1F'
       __BADRAM  H'0D8C'-H'0D9F'
       __BADRAM  H'0E0C'-H'0E0E'
       __BADRAM  H'0E0F'-H'0E1F'
       __BADRAM  H'0E90'-H'0E9F'
       __BADRAM  H'0F0C'-H'0F1F'
       __BADRAM  H'0F8C'-H'0F9F'
       __BADRAM  H'100C'-H'101F'
       __BADRAM  H'108C'-H'109F'
       __BADRAM  H'110C'-H'111F'
       __BADRAM  H'118C'-H'119F'
       __BADRAM  H'120C'-H'121F'
       __BADRAM  H'128C'-H'129F'
       __BADRAM  H'130C'-H'131F'
       __BADRAM  H'138C'-H'139F'
       __BADRAM  H'140C'-H'141F'
       __BADRAM  H'148C'-H'149F'
       __BADRAM  H'150C'-H'151F'
       __BADRAM  H'158C'-H'159F'
       __BADRAM  H'160C'-H'161F'
       __BADRAM  H'168C'-H'169F'
       __BADRAM  H'170C'-H'171F'
       __BADRAM  H'178C'-H'179F'
       __BADRAM  H'180C'-H'181F'
       __BADRAM  H'188C'-H'189F'
       __BADRAM  H'190C'-H'191F'
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
       __BADRAM  H'1D48'-H'1D6F'
       __BADRAM  H'1D8C'-H'1D9F'
       __BADRAM  H'1DA0'-H'1DEF'
       __BADRAM  H'1E0C'-H'1E0E'
       __BADRAM  H'1E45'
       __BADRAM  H'1E4C'-H'1E4F'
       __BADRAM  H'1E56'-H'1E5A'
       __BADRAM  H'1E63'-H'1E66'
       __BADRAM  H'1E6B'-H'1E6F'
       __BADRAM  H'1E8C'-H'1E8E'
       __BADRAM  H'1E94'-H'1E9B'
       __BADRAM  H'1E9E'-H'1EA0'
       __BADRAM  H'1EA3'-H'1EA8'
       __BADRAM  H'1EAB'-H'1EB0'
       __BADRAM  H'1EB2'-H'1EBA'
       __BADRAM  H'1EBF'-H'1EC2'
       __BADRAM  H'1EC4'
       __BADRAM  H'1EC8'-H'1ECA'
       __BADRAM  H'1ECF'-H'1EEF'
       __BADRAM  H'1F0C'-H'1F0F'
       __BADRAM  H'1F32'
       __BADRAM  H'1F3D'-H'1F42'
       __BADRAM  H'1F4B'-H'1F4D'
       __BADRAM  H'1F56'-H'1F58'
       __BADRAM  H'1F5E'-H'1F63'
       __BADRAM  H'1F6C'-H'1F6F'
       __BADRAM  H'1F8C'-H'1F98'
       __BADRAM  H'1F99'-H'1F9C'
       __BADRAM  H'1F9D'-H'1F9F'
       __BADRAM  H'1FA0'-H'1FBF'
       __BADRAM  H'1FC0'-H'1FDF'
       __BADRAM  H'1FE0'-H'1FE2'
       __BADRAM  H'1FE3'
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
_FEXTOSC_OFF         EQU  H'3FF8'; Oscillator not enabled
_FEXTOSC_ECL         EQU  H'3FFD'; EC below 500kHz; PFM set to low power
_FEXTOSC_ECM         EQU  H'3FFE'; EC for 500kHz to 8MHz; PFM set to medium power
_FEXTOSC_ECH         EQU  H'3FFF'; EC above 8MHz; PFM set to high power

_RSTOSC_HFINT32      EQU  H'3F8F'; HFINTOSC with OSCFRQ= 32 MHz and CDIV = 1:1
_RSTOSC_HFINTPLL     EQU  H'3F9F'; HFINTOSC with 2x PLL, with OSCFRQ = 16 MHz and CDIV = 1:1 (FOSC = 32 MHz)
_RSTOSC_EXT4X        EQU  H'3FAF'; EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits
_RSTOSC_Reserved     EQU  H'3FBF'; Reserved
_RSTOSC_SOSC         EQU  H'3FCF'; SOSC
_RSTOSC_LFINT        EQU  H'3FDF'; LFINTOSC
_RSTOSC_HFINT1       EQU  H'3FEF'; HFINTOSC (1MHz)
_RSTOSC_EXT1X        EQU  H'3FFF'; EXTOSC operating per FEXTOSC bits

_CLKOUTEN_ON         EQU  H'3EFF'; CLKOUT function is enabled; FOSC/4 clock appears at OSC2
_CLKOUTEN_OFF        EQU  H'3FFF'; CLKOUT function is disabled; i/o or oscillator function on OSC2

_VBATEN_ON           EQU  H'3DFF'; VBAT functionality is enabled
_VBATEN_OFF          EQU  H'3FFF'; VBAT functionality is disabled

_LCDPEN_OFF          EQU  H'3BFF'; LCD Charge Pump is disabled.
_LCDPEN_ON           EQU  H'3FFF'; LCD Charge Pump is enabled

_CSWEN_OFF           EQU  H'37FF'; The NOSC and NDIV bits cannot be changed by user software
_CSWEN_ON            EQU  H'3FFF'; Writing to NOSC and NDIV is allowed

_FCMEN_OFF           EQU  H'1FFF'; FSCM timer disabled
_FCMEN_ON            EQU  H'3FFF'; FSCM timer enabled

;----- CONFIG2 Options --------------------------------------------------
_MCLRE_OFF           EQU  H'3FFE'; MCLR pin function is port defined function
_MCLRE_ON            EQU  H'3FFF'; MCLR pin is Master Clear function

_PWRTE_PWRT_1        EQU  H'3FF9'; PWRT set at 1 ms
_PWRTE_PWRT_16       EQU  H'3FFB'; PWRT set at 16 ms
_PWRTE_PWRT_64       EQU  H'3FFD'; PWRT set at 64 ms
_PWRTE_OFF           EQU  H'3FFF'; PWRT disable

_LPBOREN_ON          EQU  H'3FDF'; ULPBOR enabled
_LPBOREN_OFF         EQU  H'3FFF'; ULPBOR disabled

_BOREN_OFF           EQU  H'3F3F'; Brown-out reset disabled
_BOREN_SBOREN        EQU  H'3F7F'; Brown-out reset enabled according to SBOREN bit
_BOREN_NSLEEP        EQU  H'3FBF'; Brown-out Reset enabled while running, disabled in sleep; SBOREN is ignored
_BOREN_ON            EQU  H'3FFF'; Brown-out Reset Enabled, SBOREN bit is ignored

_BORV_HI             EQU  H'3DFF'; Brown-out Reset Voltage (VBOR) is set to 2.7V
_BORV_LO             EQU  H'3FFF'; Brown-out Reset Voltage (VBOR) set to 1.9V on LF, and 2.45V on F Devices

_ZCD_ON              EQU  H'3BFF'; Zero-cross detect circuit is always enabled
_ZCD_OFF             EQU  H'3FFF'; Zero-cross detect circuit is disabled at POR.

_PPS1WAY_OFF         EQU  H'37FF'; The PPSLOCK bit can be set and cleared repeatedly by software
_PPS1WAY_ON          EQU  H'3FFF'; The PPSLOCK bit can be cleared and set only once in software

_STVREN_OFF          EQU  H'2FFF'; Stack Overflow or Underflow will not cause a reset
_STVREN_ON           EQU  H'3FFF'; Stack Overflow or Underflow will cause a reset

;;;; Begin: Added in gputils
_DEBUG_ON            EQU  H'1FFF'; Background debugger enabled
_DEBUG_OFF           EQU  H'3FFF'; Background debugger disabled

;;;; End: Added in gputils
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
_WDTCCS_SC           EQU  H'3FFF'; Software Control

;----- CONFIG4 Options --------------------------------------------------
_BBSIZE_65536        EQU  H'3FF8'; Boot Block Size (Words) 65536
_BBSIZE_32768        EQU  H'3FF9'; Boot Block Size (Words) 32768
_BBSIZE_16384        EQU  H'3FFA'; Boot Block Size (Words) 16384
_BBSIZE_8192         EQU  H'3FFB'; Boot Block Size (Words) 8192
_BBSIZE_4096         EQU  H'3FFC'; Boot Block Size (Words) 4069
_BBSIZE_2048         EQU  H'3FFD'; Boot Block Size (Words) 2048
_BBSIZE_1024         EQU  H'3FFE'; Boot Block Size (Words) 1024
_BBSIZE_512          EQU  H'3FFF'; Boot Block Size (Words) 512

_BBEN_ON             EQU  H'3FF7'; Boot Block enabled
_BBEN_OFF            EQU  H'3FFF'; Boot Block disabled

_SAFEN_ON            EQU  H'3FEF'; SAF enabled
_SAFEN_OFF           EQU  H'3FFF'; SAF disabled

_WRTAPP_ON           EQU  H'3F7F'; Application Block write-protected
_WRTAPP_OFF          EQU  H'3FFF'; Application Block NOT write-protected

_WRTB_ON             EQU  H'3EFF'; Boot Block write-protected
_WRTB_OFF            EQU  H'3FFF'; Boot Block NOT write-protected

_WRTC_ON             EQU  H'3DFF'; Configuration Word write-protected
_WRTC_OFF            EQU  H'3FFF'; Configuration Words NOT write-protected

_WRTD_ON             EQU  H'3BFF'; Data EEPROM write-protected
_WRTD_OFF            EQU  H'3FFF'; Data EEPROM NOT write-protected

_WRTSAF_ON           EQU  H'37FF'; SAF write-protected
_WRTSAF_OFF          EQU  H'3FFF'; SAF NOT write-protected

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
