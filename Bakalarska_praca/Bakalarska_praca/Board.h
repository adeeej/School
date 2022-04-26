#ifndef BOARD_H_
#define BOARD_H_

#ifndef F_CPU
#define F_CPU 12000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
/************************** MACROS ****************************/
#define sbi(x,y) x |= _BV(y)		// set bit (1<<y) [log. 1]
#define cbi(x,y) x &= ~(_BV(y))		// clear bit - using bitwise AND operator [log. 0]
#define tbi(x,y) x ^= _BV(y)		// toggle bit - using bitwise XOR operator
/**************************************************************/

/************************** RGB ****************************/
#define R_LED PORTC2
#define G_LED PORTC1
#define B_LED PORTC3

enum Colour {
	red, green, blue, purple
};
/***********************************************************/

/************************** BUTTON ****************************/
#define BTN PORTD2
/**************************************************************/

/************************** BUZZER ****************************/
#define BUZZ PORTB1
/**************************************************************/

/************************** BATTERY ****************************/
#define BATT_MEAS_EN PORTD7
#define BATT PORTC0
/**************************************************************/

/************************** UART ****************************/
#define HTX PORTD1
#define HRX PORTD0

#define BAUDERATE 115200
#define UBRR_VALUE ((F_CPU / (BAUDERATE * 8L)) -1)  //   8....51  ,  16.....25  12.....12
/***************************************************************/

enum externInt{		// EICRA
	low,			// 00
	change,			// 01
	fall,			// 10
	rising			// 11
};

#endif /* BOARD_H_ */
