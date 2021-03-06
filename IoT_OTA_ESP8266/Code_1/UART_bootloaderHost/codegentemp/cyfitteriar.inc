;
; File Name: cyfitteriar.inc
; 
; PSoC Creator  4.2
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2017 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar_trm.inc

/* LCD_Char_LCDPort */
LCD_Char_LCDPort__0__DM__MASK EQU 0x07
LCD_Char_LCDPort__0__DM__SHIFT EQU 0
LCD_Char_LCDPort__0__DR EQU CYREG_PRT0_DR
LCD_Char_LCDPort__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
LCD_Char_LCDPort__0__HSIOM_MASK EQU 0x0000000F
LCD_Char_LCDPort__0__HSIOM_SHIFT EQU 0
LCD_Char_LCDPort__0__INTCFG EQU CYREG_PRT0_INTCFG
LCD_Char_LCDPort__0__INTSTAT EQU CYREG_PRT0_INTSTAT
LCD_Char_LCDPort__0__MASK EQU 0x01
LCD_Char_LCDPort__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
LCD_Char_LCDPort__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
LCD_Char_LCDPort__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
LCD_Char_LCDPort__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
LCD_Char_LCDPort__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
LCD_Char_LCDPort__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
LCD_Char_LCDPort__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
LCD_Char_LCDPort__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
LCD_Char_LCDPort__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
LCD_Char_LCDPort__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
LCD_Char_LCDPort__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
LCD_Char_LCDPort__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
LCD_Char_LCDPort__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
LCD_Char_LCDPort__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
LCD_Char_LCDPort__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
LCD_Char_LCDPort__0__PC EQU CYREG_PRT0_PC
LCD_Char_LCDPort__0__PC2 EQU CYREG_PRT0_PC2
LCD_Char_LCDPort__0__PORT EQU 0
LCD_Char_LCDPort__0__PS EQU CYREG_PRT0_PS
LCD_Char_LCDPort__0__SHIFT EQU 0
LCD_Char_LCDPort__1__DM__MASK EQU 0x38
LCD_Char_LCDPort__1__DM__SHIFT EQU 3
LCD_Char_LCDPort__1__DR EQU CYREG_PRT0_DR
LCD_Char_LCDPort__1__HSIOM EQU CYREG_HSIOM_PORT_SEL0
LCD_Char_LCDPort__1__HSIOM_MASK EQU 0x000000F0
LCD_Char_LCDPort__1__HSIOM_SHIFT EQU 4
LCD_Char_LCDPort__1__INTCFG EQU CYREG_PRT0_INTCFG
LCD_Char_LCDPort__1__INTSTAT EQU CYREG_PRT0_INTSTAT
LCD_Char_LCDPort__1__MASK EQU 0x02
LCD_Char_LCDPort__1__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
LCD_Char_LCDPort__1__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
LCD_Char_LCDPort__1__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
LCD_Char_LCDPort__1__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
LCD_Char_LCDPort__1__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
LCD_Char_LCDPort__1__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
LCD_Char_LCDPort__1__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
LCD_Char_LCDPort__1__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
LCD_Char_LCDPort__1__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
LCD_Char_LCDPort__1__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
LCD_Char_LCDPort__1__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
LCD_Char_LCDPort__1__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
LCD_Char_LCDPort__1__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
LCD_Char_LCDPort__1__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
LCD_Char_LCDPort__1__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
LCD_Char_LCDPort__1__PC EQU CYREG_PRT0_PC
LCD_Char_LCDPort__1__PC2 EQU CYREG_PRT0_PC2
LCD_Char_LCDPort__1__PORT EQU 0
LCD_Char_LCDPort__1__PS EQU CYREG_PRT0_PS
LCD_Char_LCDPort__1__SHIFT EQU 1
LCD_Char_LCDPort__2__DM__MASK EQU 0x1C0
LCD_Char_LCDPort__2__DM__SHIFT EQU 6
LCD_Char_LCDPort__2__DR EQU CYREG_PRT0_DR
LCD_Char_LCDPort__2__HSIOM EQU CYREG_HSIOM_PORT_SEL0
LCD_Char_LCDPort__2__HSIOM_MASK EQU 0x00000F00
LCD_Char_LCDPort__2__HSIOM_SHIFT EQU 8
LCD_Char_LCDPort__2__INTCFG EQU CYREG_PRT0_INTCFG
LCD_Char_LCDPort__2__INTSTAT EQU CYREG_PRT0_INTSTAT
LCD_Char_LCDPort__2__MASK EQU 0x04
LCD_Char_LCDPort__2__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
LCD_Char_LCDPort__2__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
LCD_Char_LCDPort__2__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
LCD_Char_LCDPort__2__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
LCD_Char_LCDPort__2__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
LCD_Char_LCDPort__2__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
LCD_Char_LCDPort__2__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
LCD_Char_LCDPort__2__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
LCD_Char_LCDPort__2__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
LCD_Char_LCDPort__2__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
LCD_Char_LCDPort__2__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
LCD_Char_LCDPort__2__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
LCD_Char_LCDPort__2__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
LCD_Char_LCDPort__2__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
LCD_Char_LCDPort__2__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
LCD_Char_LCDPort__2__PC EQU CYREG_PRT0_PC
LCD_Char_LCDPort__2__PC2 EQU CYREG_PRT0_PC2
LCD_Char_LCDPort__2__PORT EQU 0
LCD_Char_LCDPort__2__PS EQU CYREG_PRT0_PS
LCD_Char_LCDPort__2__SHIFT EQU 2
LCD_Char_LCDPort__3__DM__MASK EQU 0xE00
LCD_Char_LCDPort__3__DM__SHIFT EQU 9
LCD_Char_LCDPort__3__DR EQU CYREG_PRT0_DR
LCD_Char_LCDPort__3__HSIOM EQU CYREG_HSIOM_PORT_SEL0
LCD_Char_LCDPort__3__HSIOM_MASK EQU 0x0000F000
LCD_Char_LCDPort__3__HSIOM_SHIFT EQU 12
LCD_Char_LCDPort__3__INTCFG EQU CYREG_PRT0_INTCFG
LCD_Char_LCDPort__3__INTSTAT EQU CYREG_PRT0_INTSTAT
LCD_Char_LCDPort__3__MASK EQU 0x08
LCD_Char_LCDPort__3__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
LCD_Char_LCDPort__3__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
LCD_Char_LCDPort__3__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
LCD_Char_LCDPort__3__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
LCD_Char_LCDPort__3__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
LCD_Char_LCDPort__3__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
LCD_Char_LCDPort__3__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
LCD_Char_LCDPort__3__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
LCD_Char_LCDPort__3__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
LCD_Char_LCDPort__3__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
LCD_Char_LCDPort__3__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
LCD_Char_LCDPort__3__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
LCD_Char_LCDPort__3__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
LCD_Char_LCDPort__3__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
LCD_Char_LCDPort__3__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
LCD_Char_LCDPort__3__PC EQU CYREG_PRT0_PC
LCD_Char_LCDPort__3__PC2 EQU CYREG_PRT0_PC2
LCD_Char_LCDPort__3__PORT EQU 0
LCD_Char_LCDPort__3__PS EQU CYREG_PRT0_PS
LCD_Char_LCDPort__3__SHIFT EQU 3
LCD_Char_LCDPort__4__DM__MASK EQU 0x7000
LCD_Char_LCDPort__4__DM__SHIFT EQU 12
LCD_Char_LCDPort__4__DR EQU CYREG_PRT0_DR
LCD_Char_LCDPort__4__HSIOM EQU CYREG_HSIOM_PORT_SEL0
LCD_Char_LCDPort__4__HSIOM_MASK EQU 0x000F0000
LCD_Char_LCDPort__4__HSIOM_SHIFT EQU 16
LCD_Char_LCDPort__4__INTCFG EQU CYREG_PRT0_INTCFG
LCD_Char_LCDPort__4__INTSTAT EQU CYREG_PRT0_INTSTAT
LCD_Char_LCDPort__4__MASK EQU 0x10
LCD_Char_LCDPort__4__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
LCD_Char_LCDPort__4__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
LCD_Char_LCDPort__4__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
LCD_Char_LCDPort__4__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
LCD_Char_LCDPort__4__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
LCD_Char_LCDPort__4__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
LCD_Char_LCDPort__4__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
LCD_Char_LCDPort__4__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
LCD_Char_LCDPort__4__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
LCD_Char_LCDPort__4__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
LCD_Char_LCDPort__4__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
LCD_Char_LCDPort__4__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
LCD_Char_LCDPort__4__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
LCD_Char_LCDPort__4__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
LCD_Char_LCDPort__4__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
LCD_Char_LCDPort__4__PC EQU CYREG_PRT0_PC
LCD_Char_LCDPort__4__PC2 EQU CYREG_PRT0_PC2
LCD_Char_LCDPort__4__PORT EQU 0
LCD_Char_LCDPort__4__PS EQU CYREG_PRT0_PS
LCD_Char_LCDPort__4__SHIFT EQU 4
LCD_Char_LCDPort__5__DM__MASK EQU 0x38000
LCD_Char_LCDPort__5__DM__SHIFT EQU 15
LCD_Char_LCDPort__5__DR EQU CYREG_PRT0_DR
LCD_Char_LCDPort__5__HSIOM EQU CYREG_HSIOM_PORT_SEL0
LCD_Char_LCDPort__5__HSIOM_MASK EQU 0x00F00000
LCD_Char_LCDPort__5__HSIOM_SHIFT EQU 20
LCD_Char_LCDPort__5__INTCFG EQU CYREG_PRT0_INTCFG
LCD_Char_LCDPort__5__INTSTAT EQU CYREG_PRT0_INTSTAT
LCD_Char_LCDPort__5__MASK EQU 0x20
LCD_Char_LCDPort__5__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
LCD_Char_LCDPort__5__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
LCD_Char_LCDPort__5__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
LCD_Char_LCDPort__5__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
LCD_Char_LCDPort__5__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
LCD_Char_LCDPort__5__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
LCD_Char_LCDPort__5__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
LCD_Char_LCDPort__5__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
LCD_Char_LCDPort__5__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
LCD_Char_LCDPort__5__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
LCD_Char_LCDPort__5__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
LCD_Char_LCDPort__5__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
LCD_Char_LCDPort__5__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
LCD_Char_LCDPort__5__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
LCD_Char_LCDPort__5__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
LCD_Char_LCDPort__5__PC EQU CYREG_PRT0_PC
LCD_Char_LCDPort__5__PC2 EQU CYREG_PRT0_PC2
LCD_Char_LCDPort__5__PORT EQU 0
LCD_Char_LCDPort__5__PS EQU CYREG_PRT0_PS
LCD_Char_LCDPort__5__SHIFT EQU 5
LCD_Char_LCDPort__6__DM__MASK EQU 0x1C0000
LCD_Char_LCDPort__6__DM__SHIFT EQU 18
LCD_Char_LCDPort__6__DR EQU CYREG_PRT0_DR
LCD_Char_LCDPort__6__HSIOM EQU CYREG_HSIOM_PORT_SEL0
LCD_Char_LCDPort__6__HSIOM_MASK EQU 0x0F000000
LCD_Char_LCDPort__6__HSIOM_SHIFT EQU 24
LCD_Char_LCDPort__6__INTCFG EQU CYREG_PRT0_INTCFG
LCD_Char_LCDPort__6__INTSTAT EQU CYREG_PRT0_INTSTAT
LCD_Char_LCDPort__6__MASK EQU 0x40
LCD_Char_LCDPort__6__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
LCD_Char_LCDPort__6__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
LCD_Char_LCDPort__6__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
LCD_Char_LCDPort__6__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
LCD_Char_LCDPort__6__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
LCD_Char_LCDPort__6__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
LCD_Char_LCDPort__6__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
LCD_Char_LCDPort__6__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
LCD_Char_LCDPort__6__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
LCD_Char_LCDPort__6__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
LCD_Char_LCDPort__6__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
LCD_Char_LCDPort__6__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
LCD_Char_LCDPort__6__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
LCD_Char_LCDPort__6__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
LCD_Char_LCDPort__6__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
LCD_Char_LCDPort__6__PC EQU CYREG_PRT0_PC
LCD_Char_LCDPort__6__PC2 EQU CYREG_PRT0_PC2
LCD_Char_LCDPort__6__PORT EQU 0
LCD_Char_LCDPort__6__PS EQU CYREG_PRT0_PS
LCD_Char_LCDPort__6__SHIFT EQU 6
LCD_Char_LCDPort__DR EQU CYREG_PRT0_DR
LCD_Char_LCDPort__INTCFG EQU CYREG_PRT0_INTCFG
LCD_Char_LCDPort__INTSTAT EQU CYREG_PRT0_INTSTAT
LCD_Char_LCDPort__MASK EQU 0x7F
LCD_Char_LCDPort__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
LCD_Char_LCDPort__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
LCD_Char_LCDPort__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
LCD_Char_LCDPort__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
LCD_Char_LCDPort__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
LCD_Char_LCDPort__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
LCD_Char_LCDPort__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
LCD_Char_LCDPort__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
LCD_Char_LCDPort__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
LCD_Char_LCDPort__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
LCD_Char_LCDPort__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
LCD_Char_LCDPort__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
LCD_Char_LCDPort__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
LCD_Char_LCDPort__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
LCD_Char_LCDPort__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
LCD_Char_LCDPort__PC EQU CYREG_PRT0_PC
LCD_Char_LCDPort__PC2 EQU CYREG_PRT0_PC2
LCD_Char_LCDPort__PORT EQU 0
LCD_Char_LCDPort__PS EQU CYREG_PRT0_PS
LCD_Char_LCDPort__SHIFT EQU 0

/* Pin */
Pin__0__DM__MASK EQU 0x38000
Pin__0__DM__SHIFT EQU 15
Pin__0__DR EQU CYREG_PRT2_DR
Pin__0__HSIOM EQU CYREG_HSIOM_PORT_SEL2
Pin__0__HSIOM_MASK EQU 0x00F00000
Pin__0__HSIOM_SHIFT EQU 20
Pin__0__INTCFG EQU CYREG_PRT2_INTCFG
Pin__0__INTSTAT EQU CYREG_PRT2_INTSTAT
Pin__0__MASK EQU 0x20
Pin__0__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
Pin__0__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
Pin__0__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
Pin__0__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
Pin__0__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
Pin__0__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
Pin__0__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
Pin__0__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
Pin__0__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
Pin__0__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
Pin__0__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
Pin__0__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
Pin__0__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
Pin__0__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
Pin__0__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
Pin__0__PC EQU CYREG_PRT2_PC
Pin__0__PC2 EQU CYREG_PRT2_PC2
Pin__0__PORT EQU 2
Pin__0__PS EQU CYREG_PRT2_PS
Pin__0__SHIFT EQU 5
Pin__DR EQU CYREG_PRT2_DR
Pin__INTCFG EQU CYREG_PRT2_INTCFG
Pin__INTSTAT EQU CYREG_PRT2_INTSTAT
Pin__MASK EQU 0x20
Pin__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
Pin__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
Pin__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
Pin__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
Pin__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
Pin__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
Pin__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
Pin__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
Pin__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
Pin__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
Pin__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
Pin__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
Pin__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
Pin__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
Pin__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
Pin__PC EQU CYREG_PRT2_PC
Pin__PC2 EQU CYREG_PRT2_PC2
Pin__PORT EQU 2
Pin__PS EQU CYREG_PRT2_PS
Pin__SHIFT EQU 5
Pin_Switch__0__DM__MASK EQU 0xE00000
Pin_Switch__0__DM__SHIFT EQU 21
Pin_Switch__0__DR EQU CYREG_PRT0_DR
Pin_Switch__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
Pin_Switch__0__HSIOM_MASK EQU 0xF0000000
Pin_Switch__0__HSIOM_SHIFT EQU 28
Pin_Switch__0__INTCFG EQU CYREG_PRT0_INTCFG
Pin_Switch__0__INTSTAT EQU CYREG_PRT0_INTSTAT
Pin_Switch__0__MASK EQU 0x80
Pin_Switch__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Pin_Switch__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Pin_Switch__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Pin_Switch__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Pin_Switch__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Pin_Switch__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Pin_Switch__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Pin_Switch__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Pin_Switch__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Pin_Switch__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Pin_Switch__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Pin_Switch__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Pin_Switch__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Pin_Switch__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Pin_Switch__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Pin_Switch__0__PC EQU CYREG_PRT0_PC
Pin_Switch__0__PC2 EQU CYREG_PRT0_PC2
Pin_Switch__0__PORT EQU 0
Pin_Switch__0__PS EQU CYREG_PRT0_PS
Pin_Switch__0__SHIFT EQU 7
Pin_Switch__DR EQU CYREG_PRT0_DR
Pin_Switch__INTCFG EQU CYREG_PRT0_INTCFG
Pin_Switch__INTSTAT EQU CYREG_PRT0_INTSTAT
Pin_Switch__MASK EQU 0x80
Pin_Switch__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Pin_Switch__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Pin_Switch__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Pin_Switch__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Pin_Switch__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Pin_Switch__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Pin_Switch__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Pin_Switch__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Pin_Switch__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Pin_Switch__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Pin_Switch__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Pin_Switch__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Pin_Switch__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Pin_Switch__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Pin_Switch__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Pin_Switch__PC EQU CYREG_PRT0_PC
Pin_Switch__PC2 EQU CYREG_PRT0_PC2
Pin_Switch__PORT EQU 0
Pin_Switch__PS EQU CYREG_PRT0_PS
Pin_Switch__SHIFT EQU 7

/* Rx */
Rx__0__DM__MASK EQU 0x1C0
Rx__0__DM__SHIFT EQU 6
Rx__0__DR EQU CYREG_PRT2_DR
Rx__0__HSIOM EQU CYREG_HSIOM_PORT_SEL2
Rx__0__HSIOM_MASK EQU 0x00000F00
Rx__0__HSIOM_SHIFT EQU 8
Rx__0__INTCFG EQU CYREG_PRT2_INTCFG
Rx__0__INTSTAT EQU CYREG_PRT2_INTSTAT
Rx__0__MASK EQU 0x04
Rx__0__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
Rx__0__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
Rx__0__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
Rx__0__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
Rx__0__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
Rx__0__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
Rx__0__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
Rx__0__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
Rx__0__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
Rx__0__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
Rx__0__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
Rx__0__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
Rx__0__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
Rx__0__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
Rx__0__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
Rx__0__PC EQU CYREG_PRT2_PC
Rx__0__PC2 EQU CYREG_PRT2_PC2
Rx__0__PORT EQU 2
Rx__0__PS EQU CYREG_PRT2_PS
Rx__0__SHIFT EQU 2
Rx__DR EQU CYREG_PRT2_DR
Rx__INTCFG EQU CYREG_PRT2_INTCFG
Rx__INTSTAT EQU CYREG_PRT2_INTSTAT
Rx__MASK EQU 0x04
Rx__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
Rx__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
Rx__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
Rx__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
Rx__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
Rx__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
Rx__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
Rx__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
Rx__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
Rx__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
Rx__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
Rx__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
Rx__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
Rx__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
Rx__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
Rx__PC EQU CYREG_PRT2_PC
Rx__PC2 EQU CYREG_PRT2_PC2
Rx__PORT EQU 2
Rx__PS EQU CYREG_PRT2_PS
Rx__SHIFT EQU 2

/* Tx */
Tx__0__DM__MASK EQU 0xE00
Tx__0__DM__SHIFT EQU 9
Tx__0__DR EQU CYREG_PRT1_DR
Tx__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
Tx__0__HSIOM_MASK EQU 0x0000F000
Tx__0__HSIOM_SHIFT EQU 12
Tx__0__INTCFG EQU CYREG_PRT1_INTCFG
Tx__0__INTSTAT EQU CYREG_PRT1_INTSTAT
Tx__0__MASK EQU 0x08
Tx__0__OUT_SEL EQU CYREG_UDB_PA1_CFG10
Tx__0__OUT_SEL_SHIFT EQU 6
Tx__0__OUT_SEL_VAL EQU 3
Tx__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
Tx__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
Tx__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
Tx__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
Tx__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
Tx__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
Tx__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
Tx__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
Tx__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
Tx__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
Tx__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
Tx__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
Tx__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
Tx__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
Tx__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
Tx__0__PC EQU CYREG_PRT1_PC
Tx__0__PC2 EQU CYREG_PRT1_PC2
Tx__0__PORT EQU 1
Tx__0__PS EQU CYREG_PRT1_PS
Tx__0__SHIFT EQU 3
Tx__DR EQU CYREG_PRT1_DR
Tx__INTCFG EQU CYREG_PRT1_INTCFG
Tx__INTSTAT EQU CYREG_PRT1_INTSTAT
Tx__MASK EQU 0x08
Tx__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
Tx__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
Tx__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
Tx__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
Tx__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
Tx__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
Tx__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
Tx__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
Tx__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
Tx__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
Tx__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
Tx__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
Tx__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
Tx__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
Tx__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
Tx__PC EQU CYREG_PRT1_PC
Tx__PC2 EQU CYREG_PRT1_PC2
Tx__PORT EQU 1
Tx__PS EQU CYREG_PRT1_PS
Tx__SHIFT EQU 3

/* UART_BUART */
UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_02
UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_UDB_W16_CTL_02
UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_UDB_W16_CTL_02
UART_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_UDB_W16_CTL_02
UART_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_UDB_W16_CTL_02
UART_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG EQU CYREG_UDB_W16_MSK_02
UART_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_UDB_W16_MSK_02
UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_UDB_W16_MSK_02
UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_UDB_W16_MSK_02
UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_02
UART_BUART_sRX_RxBitCounter__CONTROL_REG EQU CYREG_UDB_W8_CTL_02
UART_BUART_sRX_RxBitCounter__CONTROL_ST_REG EQU CYREG_UDB_CAT16_CTL_ST_02
UART_BUART_sRX_RxBitCounter__COUNT_REG EQU CYREG_UDB_W8_CTL_02
UART_BUART_sRX_RxBitCounter__COUNT_ST_REG EQU CYREG_UDB_CAT16_CTL_ST_02
UART_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_02
UART_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_02
UART_BUART_sRX_RxBitCounter__PERIOD_REG EQU CYREG_UDB_W8_MSK_02
UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_02
UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG EQU CYREG_UDB_W16_ST_02
UART_BUART_sRX_RxBitCounter_ST__MASK_REG EQU CYREG_UDB_W8_MSK_02
UART_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_02
UART_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_02
UART_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_02
UART_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG EQU CYREG_UDB_CAT16_CTL_ST_02
UART_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG EQU CYREG_UDB_CAT16_CTL_ST_02
UART_BUART_sRX_RxBitCounter_ST__STATUS_REG EQU CYREG_UDB_W8_ST_02
UART_BUART_sRX_RxShifter_u0__16BIT_A0_REG EQU CYREG_UDB_W16_A0_02
UART_BUART_sRX_RxShifter_u0__16BIT_A1_REG EQU CYREG_UDB_W16_A1_02
UART_BUART_sRX_RxShifter_u0__16BIT_D0_REG EQU CYREG_UDB_W16_D0_02
UART_BUART_sRX_RxShifter_u0__16BIT_D1_REG EQU CYREG_UDB_W16_D1_02
UART_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_02
UART_BUART_sRX_RxShifter_u0__16BIT_F0_REG EQU CYREG_UDB_W16_F0_02
UART_BUART_sRX_RxShifter_u0__16BIT_F1_REG EQU CYREG_UDB_W16_F1_02
UART_BUART_sRX_RxShifter_u0__A0_A1_REG EQU CYREG_UDB_CAT16_A_02
UART_BUART_sRX_RxShifter_u0__A0_REG EQU CYREG_UDB_W8_A0_02
UART_BUART_sRX_RxShifter_u0__A1_REG EQU CYREG_UDB_W8_A1_02
UART_BUART_sRX_RxShifter_u0__D0_D1_REG EQU CYREG_UDB_CAT16_D_02
UART_BUART_sRX_RxShifter_u0__D0_REG EQU CYREG_UDB_W8_D0_02
UART_BUART_sRX_RxShifter_u0__D1_REG EQU CYREG_UDB_W8_D1_02
UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_02
UART_BUART_sRX_RxShifter_u0__F0_F1_REG EQU CYREG_UDB_CAT16_F_02
UART_BUART_sRX_RxShifter_u0__F0_REG EQU CYREG_UDB_W8_F0_02
UART_BUART_sRX_RxShifter_u0__F1_REG EQU CYREG_UDB_W8_F1_02
UART_BUART_sRX_RxShifter_u0__MSK_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_02
UART_BUART_sRX_RxShifter_u0__PER_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_02
UART_BUART_sRX_RxSts__3__MASK EQU 0x08
UART_BUART_sRX_RxSts__3__POS EQU 3
UART_BUART_sRX_RxSts__4__MASK EQU 0x10
UART_BUART_sRX_RxSts__4__POS EQU 4
UART_BUART_sRX_RxSts__5__MASK EQU 0x20
UART_BUART_sRX_RxSts__5__POS EQU 5
UART_BUART_sRX_RxSts__MASK EQU 0x38
UART_BUART_sRX_RxSts__MASK_REG EQU CYREG_UDB_W8_MSK_03
UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_03
UART_BUART_sRX_RxSts__STATUS_REG EQU CYREG_UDB_W8_ST_03
UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG EQU CYREG_UDB_W16_A0_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG EQU CYREG_UDB_W16_A1_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG EQU CYREG_UDB_W16_D0_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG EQU CYREG_UDB_W16_D1_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG EQU CYREG_UDB_W16_F0_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG EQU CYREG_UDB_W16_F1_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__32BIT_A0_REG EQU CYREG_UDB_W32_A0_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__32BIT_A1_REG EQU CYREG_UDB_W32_A1_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__32BIT_D0_REG EQU CYREG_UDB_W32_D0_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__32BIT_D1_REG EQU CYREG_UDB_W32_D1_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__32BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W32_ACTL_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__32BIT_F0_REG EQU CYREG_UDB_W32_F0_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__32BIT_F1_REG EQU CYREG_UDB_W32_F1_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG EQU CYREG_UDB_CAT16_A_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG EQU CYREG_UDB_W8_A0_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG EQU CYREG_UDB_W8_A1_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG EQU CYREG_UDB_CAT16_D_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG EQU CYREG_UDB_W8_D0_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG EQU CYREG_UDB_W8_D1_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG EQU CYREG_UDB_CAT16_F_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG EQU CYREG_UDB_W8_F0_00
UART_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG EQU CYREG_UDB_W8_F1_00
UART_BUART_sTX_TxShifter_u0__16BIT_A0_REG EQU CYREG_UDB_W16_A0_01
UART_BUART_sTX_TxShifter_u0__16BIT_A1_REG EQU CYREG_UDB_W16_A1_01
UART_BUART_sTX_TxShifter_u0__16BIT_D0_REG EQU CYREG_UDB_W16_D0_01
UART_BUART_sTX_TxShifter_u0__16BIT_D1_REG EQU CYREG_UDB_W16_D1_01
UART_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_01
UART_BUART_sTX_TxShifter_u0__16BIT_F0_REG EQU CYREG_UDB_W16_F0_01
UART_BUART_sTX_TxShifter_u0__16BIT_F1_REG EQU CYREG_UDB_W16_F1_01
UART_BUART_sTX_TxShifter_u0__A0_A1_REG EQU CYREG_UDB_CAT16_A_01
UART_BUART_sTX_TxShifter_u0__A0_REG EQU CYREG_UDB_W8_A0_01
UART_BUART_sTX_TxShifter_u0__A1_REG EQU CYREG_UDB_W8_A1_01
UART_BUART_sTX_TxShifter_u0__D0_D1_REG EQU CYREG_UDB_CAT16_D_01
UART_BUART_sTX_TxShifter_u0__D0_REG EQU CYREG_UDB_W8_D0_01
UART_BUART_sTX_TxShifter_u0__D1_REG EQU CYREG_UDB_W8_D1_01
UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_01
UART_BUART_sTX_TxShifter_u0__F0_F1_REG EQU CYREG_UDB_CAT16_F_01
UART_BUART_sTX_TxShifter_u0__F0_REG EQU CYREG_UDB_W8_F0_01
UART_BUART_sTX_TxShifter_u0__F1_REG EQU CYREG_UDB_W8_F1_01
UART_BUART_sTX_TxSts__0__MASK EQU 0x01
UART_BUART_sTX_TxSts__0__POS EQU 0
UART_BUART_sTX_TxSts__1__MASK EQU 0x02
UART_BUART_sTX_TxSts__1__POS EQU 1
UART_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_01
UART_BUART_sTX_TxSts__16BIT_STATUS_REG EQU CYREG_UDB_W16_ST_01
UART_BUART_sTX_TxSts__2__MASK EQU 0x04
UART_BUART_sTX_TxSts__2__POS EQU 2
UART_BUART_sTX_TxSts__3__MASK EQU 0x08
UART_BUART_sTX_TxSts__3__POS EQU 3
UART_BUART_sTX_TxSts__MASK EQU 0x0F
UART_BUART_sTX_TxSts__MASK_REG EQU CYREG_UDB_W8_MSK_01
UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_01
UART_BUART_sTX_TxSts__STATUS_REG EQU CYREG_UDB_W8_ST_01

/* UART_IntClock */
UART_IntClock__DIVIDER_MASK EQU 0x0000FFFF
UART_IntClock__ENABLE EQU CYREG_CLK_DIVIDER_A00
UART_IntClock__ENABLE_MASK EQU 0x80000000
UART_IntClock__MASK EQU 0x80000000
UART_IntClock__REGISTER EQU CYREG_CLK_DIVIDER_A00

/* UART_RXInternalInterrupt */
UART_RXInternalInterrupt__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
UART_RXInternalInterrupt__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
UART_RXInternalInterrupt__INTC_MASK EQU 0x01
UART_RXInternalInterrupt__INTC_NUMBER EQU 0
UART_RXInternalInterrupt__INTC_PRIOR_MASK EQU 0xC0
UART_RXInternalInterrupt__INTC_PRIOR_NUM EQU 3
UART_RXInternalInterrupt__INTC_PRIOR_REG EQU CYREG_CM0_IPR0
UART_RXInternalInterrupt__INTC_SET_EN_REG EQU CYREG_CM0_ISER
UART_RXInternalInterrupt__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

/* UART_TXInternalInterrupt */
UART_TXInternalInterrupt__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
UART_TXInternalInterrupt__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
UART_TXInternalInterrupt__INTC_MASK EQU 0x04
UART_TXInternalInterrupt__INTC_NUMBER EQU 2
UART_TXInternalInterrupt__INTC_PRIOR_MASK EQU 0xC00000
UART_TXInternalInterrupt__INTC_PRIOR_NUM EQU 3
UART_TXInternalInterrupt__INTC_PRIOR_REG EQU CYREG_CM0_IPR0
UART_TXInternalInterrupt__INTC_SET_EN_REG EQU CYREG_CM0_ISER
UART_TXInternalInterrupt__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

/* Miscellaneous */
CYDEV_BCLK__HFCLK__HZ EQU 24000000
CYDEV_BCLK__HFCLK__KHZ EQU 24000
CYDEV_BCLK__HFCLK__MHZ EQU 24
CYDEV_BCLK__SYSCLK__HZ EQU 24000000
CYDEV_BCLK__SYSCLK__KHZ EQU 24000
CYDEV_BCLK__SYSCLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 18
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x04C81193
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 18
CYDEV_CHIP_MEMBER_4D EQU 13
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 19
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 17
CYDEV_CHIP_MEMBER_4I EQU 23
CYDEV_CHIP_MEMBER_4J EQU 14
CYDEV_CHIP_MEMBER_4K EQU 15
CYDEV_CHIP_MEMBER_4L EQU 22
CYDEV_CHIP_MEMBER_4M EQU 21
CYDEV_CHIP_MEMBER_4N EQU 10
CYDEV_CHIP_MEMBER_4O EQU 7
CYDEV_CHIP_MEMBER_4P EQU 20
CYDEV_CHIP_MEMBER_4Q EQU 12
CYDEV_CHIP_MEMBER_4R EQU 8
CYDEV_CHIP_MEMBER_4S EQU 11
CYDEV_CHIP_MEMBER_4T EQU 9
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 16
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 24
CYDEV_CHIP_MEMBER_FM3 EQU 28
CYDEV_CHIP_MEMBER_FM4 EQU 29
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 25
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 26
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 27
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4A
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4A_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DFT_SELECT_CLK0 EQU 1
CYDEV_DFT_SELECT_CLK1 EQU 2
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_IMO_TRIMMED_BY_USB EQU 0
CYDEV_IMO_TRIMMED_BY_WCO EQU 0
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0400
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA EQU 5
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD EQU 5
CYDEV_VDDD_MV EQU 5000
CYDEV_WDT_GENERATE_ISR EQU 0
CYIPBLOCK_M0S8_CTBM_VERSION EQU 0
CYIPBLOCK_m0s8cpuss_VERSION EQU 0
CYIPBLOCK_m0s8csd_VERSION EQU 0
CYIPBLOCK_m0s8gpio2_VERSION EQU 0
CYIPBLOCK_m0s8hsiom4a_VERSION EQU 0
CYIPBLOCK_m0s8lcd_VERSION EQU 0
CYIPBLOCK_m0s8lpcomp_VERSION EQU 0
CYIPBLOCK_m0s8pclk_VERSION EQU 0
CYIPBLOCK_m0s8sar_VERSION EQU 0
CYIPBLOCK_m0s8scb_VERSION EQU 0
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 0
CYIPBLOCK_m0s8udbif_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 2
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */
