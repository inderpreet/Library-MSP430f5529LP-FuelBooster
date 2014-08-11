/*
* Description: This file is part of MSP430F5529 USB Starter Kit
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
* The latest copy of this project/library can be found at:
* https://github.com/inderpreet/
*
*/
// ----------------------------------------------------------------------------

/* Version 1.0
 * A simple demo for the the MSP430f5529 USB Starter Kit
 * Inderpreet Singh
 * March, 2014
 */

/*
******************************************************************************
*                                  INCLUDE FILES
******************************************************************************
*/

#include <msp430.h> 
/*
******************************************************************************
*                                  FUNCTION PROTOTYPES
******************************************************************************
*/
void initUART1();

/*
******************************************************************************
*                                  FUNCTION DEFINITIONS
******************************************************************************
*/

/**
  * @brief  Main function
  * @param  None
  * @retval None
  */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    initUART1();								// and setup for simple echo
    __bis_SR_register(LPM3_bits + GIE);       // Enter LPM3, interrupts enabled
      __no_operation();                         // For debugger
	return 0;
}
/**
  * @brief  Initialize the UART for 9600 baud with a RX interrupt
  * @param
  * @retval None
  */

void initUART1(){
	P4SEL = BIT4+BIT5;                        // P4.4,4.5 = USCI_A1 TXD/RXD
    UCA1CTL1 |= UCSWRST;                      // **Put state machine in reset**
    UCA1CTL1 |= UCSSEL_1;                     // CLK = ACLK
    UCA1BR0 = 0x03;                           // 32kHz/9600=3.41
    UCA1BR1 = 0x00;                           //
    UCA1MCTL = UCBRS_3+UCBRF_0;               // Modulation UCBRSx=3, UCBRFx=0
    UCA1CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
    UCA1IE |= UCRXIE;                         // Enable USCI_A1 RX interrupt
}

// Echo back RXed character but confirm TX buffer is ready first
#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
{
  switch(__even_in_range(UCA1IV,4))
  {
  case 0:break;                             // Vector 0 - no interrupt
  case 2:                                   // Vector 2 - RXIFG
    while (!(UCA1IFG&UCTXIFG));             // USCI_10 TX buffer ready?
    UCA1TXBUF = UCA1RXBUF;                  // TX -> RXed character
    break;
  case 4:break;                             // Vector 4 - TXIFG
  default: break;
  }
}
