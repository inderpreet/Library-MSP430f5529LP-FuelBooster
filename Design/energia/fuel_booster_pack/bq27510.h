/* 
* Description: This file is part of the repo for the TI MSP430F5529 USB Launch Pad
* Its the library of commands for the Fuel Gauge IC
* --
* Copyright (C) 2014 Inderpreet Singh(er.inderpreet@gmail.com), 
			  Thought Process Designs
* Web      :  http://google.com/+InderpreetSingh
*		 	  http://embeddedcode.wordpress.com
*
* This software may be distributed and modified under the terms of the GNU
* General Public License version 2 (GPL2) as published by the Free Software
* Foundation and appearing in the file LICENSE.TXT included in the packaging of
* this file. Please note that GPL2 Section 2[b] requires that all works based
* on this software must also be made publicly available under the terms of
* the GPL2 ("Copyleft").
*
* We put a lot of time and effort into our project and hence this copyright 
* notice ensures that people contribute as well as each contribution is 
* acknowledged. Please retain this original notice and if you make changes
* please document them below along with your details.
*
* The latest copy of this project/library can be found at: 
* https://github.com/inderpreet/
*
*/
// ----------------------------------------------------------------------------
#ifndef BQ27510_H
#define BQ27510_H

#define bq27510CMD_CNTL_LSB  0x00
#define bq27510CMD_CNTL_MSB  0x01
#define bq27510CMD_AR_LSB    0x02
#define bq27510CMD_AR_MSB    0x03
#define bq27510CMD_ARTTE_LSB 0x04
#define bq27510CMD_ARTTE_MSB 0x05
#define bq27510CMD_TEMP_LSB  0x06
#define bq27510CMD_TEMP_MSB  0x07
#define bq27510CMD_VOLT_LSB  0x08
#define bq27510CMD_VOLT_MSB  0x09
#define bq27510CMD_FLAGS_LSB 0x0A
#define bq27510CMD_FLAGS_MSB 0x0B
#define bq27510CMD_NAC_LSB   0x0C
#define bq27510CMD_NAC_MSB   0x0D
#define bq27510CMD_FAC_LSB   0x0E
#define bq27510CMD_FAC_MSB   0x0F
#define bq27510CMD_RM_LSB    0x10
#define bq27510CMD_RM_MSB    0x11
#define bq27510CMD_FCC_LSB   0x12
#define bq27510CMD_FCC_MSB   0x13
#define bq27510CMD_AI_LSB    0x14
#define bq27510CMD_AI_MSB    0x15
#define bq27510CMD_TTE_LSB   0x16
#define bq27510CMD_TTE_MSB   0x17
#define bq27510CMD_TTF_LSB   0x18
#define bq27510CMD_TTF_MSB   0x19
#define bq27510CMD_SI_LSB    0x18
#define bq27510CMD_SI_MSB    0x19
#define bq27510CMD_STTE_LSB  0x1A
#define bq27510CMD_STTE_MSB  0x1B
#define bq27510CMD_SOH_LSB   0x1C
#define bq27510CMD_SOH_MSB   0x1D
#define bq27510CMD_CC_LSB    0x1E
#define bq27510CMD_CC_MSB    0x1F
#define bq27510CMD_SOC_LSB   0x20
#define bq27510CMD_SOC_MSB   0x21
#define bq27510CMD_INSC_LSB  0x22
#define bq27510CMD_INSC_MSB  0x23
#define bq27510CMD_ITLT_LSB  0x28
#define bq27510CMD_ITLT_MSB  0x29
#define bq27510CMD_RS_LSB    0x2A
#define bq27510CMD_RS_MSB    0x2B
#define bq27510CMD_OPC_LSB   0x2C
#define bq27510CMD_OPC_MSB   0x2D
#define bq27510CMD_DCAP_LSB  0x2E
#define bq27510CMD_DCAP_MSB  0x2F

#define bq27510_ADR      0x55
#endif