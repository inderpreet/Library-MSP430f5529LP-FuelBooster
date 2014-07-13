/* 
* Description: This file is part of the repo for the TI MSP430F5529 USB Launch Pad
* 
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
* https://github.com/inderpreet/MSP430f5529_USB_LAUNCHPAD
*
*/
// ----------------------------------------------------------------------------

#include <stdio.h>
#include "bq27510.h"
#include <Wire.h>

#define mySerial Serial1
// Global Variables
int iVoltage 	= 0;
int iCurrent 	= 0;
int iTemp 		= 0;
int iSOC 		= 0; 
int iDCAP 		= 0;
int iRCAP 		= 0;
unsigned int uiTTE = 0;
unsigned int uiTTF = 0;

//int CHARGE_PIN A5;
//int EN_PIN     P1.6;
//int PG_PIN P3.2

// Function for printing data
// Comment out anything you don't want
void printStuff(void){
	// Temperature
	//mySerial.print(" Temp ");
	//mySerial.print(iTemp);
	// Voltage
	mySerial.print(" V ");
	mySerial.print(iVoltage);
	// Current
	mySerial.print(" I ");
	mySerial.print(iCurrent);
	// State of Charge
	//mySerial.print(" SOC ");
	//mySerial.print(iSOC);
	// RCAP
	//mySerial.print(" RCAP ");
	//mySerial.print(iRCAP);
	// DCAP
	//mySerial.print(" DCAP ");
	//mySerial.print(iDCAP);
	// Time to Empty
	//mySerial.print(" TTE ");
	//mySerial.print(uiTTE);
	// Time to Full
	//mySerial.print(" TTF ");
	//mySerial.print(uiTTF);

        mySerial.print("\r");
}

// Function to access the data on the Fuel Gauge via I2C
// Function forked from code posted by Peter Oakes at the element14 forums
int getValue(int port, int cmd){
	int tmp1=0;
	int tmp2 = 0;
	int response = 0;
	Wire.beginTransmission(port);
	Wire.write(byte(cmd));
	Wire.endTransmission(true);
	// according to all the demos, first reading is unstable so ignore it ??
	// Seems yo have to do this twice to get it to work, if you dont is gets screwed up
	Wire.beginTransmission(port);
	Wire.write(byte(cmd));
	// request 2 bytes from slave device port
	response = Wire.requestFrom(port, 2);   
	Wire.endTransmission(true);
	while(Wire.available()){    // slave may send less than requested
		tmp1 = Wire.read() ;
		tmp2 = Wire.read() ;
	}
  return transBytes2Int(tmp2, tmp1);
}

/**
  * @brief  Translate two bytes into an integer
  * @param  
  * @retval The calculation results
  */
unsigned int transBytes2Int(unsigned char msb, unsigned char lsb){
    unsigned int tmp;
    tmp = ((msb << 8) & 0xFF00);
    return ((unsigned int)(tmp + lsb) & 0x0000FFFF);
}

// Run Once Loop
void setup(void){
	Wire.begin();        // join i2c bus (address optional for master)
	mySerial.begin(9600);  // start serial for output
        mySerial.println("\nFuel Booster Pack Demo");
        mySerial.println("By: Inderpreet Singh");
}

// Run forever Loop
void loop(void){
	iTemp  = getValue(bq27510_ADR, bq27510CMD_TEMP_LSB )/ 10 - 273;
	iVoltage = getValue(bq27510_ADR, bq27510CMD_VOLT_LSB );
	iCurrent = getValue(bq27510_ADR, bq27510CMD_AI_LSB);
	iSOC = getValue(bq27510_ADR, bq27510CMD_SOC_LSB);
	iDCAP = getValue(bq27510_ADR, bq27510CMD_DCAP_LSB);
	iRCAP = getValue(bq27510_ADR, bq27510CMD_RM_LSB);
	uiTTE = getValue(bq27510_ADR, bq27510CMD_TTE_LSB);
	uiTTF = getValue(bq27510_ADR, bq27510CMD_TTF_LSB);
        printStuff();
        delay(2000);
}


