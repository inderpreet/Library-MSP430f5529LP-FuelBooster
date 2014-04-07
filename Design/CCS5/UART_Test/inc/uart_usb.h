/*
 * uart_usb.h
 *
 *  Created on: 07-Apr-2014
 *      Author: Inderpreet Singh
 */

#ifndef UART_USB_H_
#define UART_USB_H_

#define ENTER_LPM __bis_SR_register(LPM3_bits + GIE)       // Enter LPM3, interrupts enabled

void initUSBUart(void);


#endif /* UART_USB_H_ */
