/*
 * DIO_config.h
 *
 *  Created on: Oct 17, 2023
 *      Author: HP
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#include "DIO.h"

//#define output 1
//#define input 0


#define PORTA_PIN0 PIN_INPUT
#define PORTA_PIN1 PIN_INPUT
#define PORTA_PIN2 PIN_OUTPUT  // ENABLE
#define PORTA_PIN3 PIN_OUTPUT //RS
#define PORTA_PIN4 PIN_INPUT
#define PORTA_PIN5 PIN_INPUT
#define PORTA_PIN6 PIN_INPUT
#define PORTA_PIN7 PIN_INPUT

#define PORTB_PIN0 PIN_OUTPUT //D4
#define PORTB_PIN1 PIN_OUTPUT //D5
#define PORTB_PIN2 PIN_OUTPUT //D6
#define PORTB_PIN3 PIN_INPUT
#define PORTB_PIN4 PIN_OUTPUT //D7
#define PORTB_PIN5 PIN_INPUT
#define PORTB_PIN6 PIN_INPUT
#define PORTB_PIN7 PIN_INPUT

#define PORTC_PIN0 PIN_INPUT
#define PORTC_PIN1 PIN_INPUT
#define PORTC_PIN2 PIN_OUTPUT // ROW4
#define PORTC_PIN3 PIN_OUTPUT // ROW3
#define PORTC_PIN4 PIN_OUTPUT // ROW2
#define PORTC_PIN5 PIN_OUTPUT //ROW1
#define PORTC_PIN6 PIN_INPUT
#define PORTC_PIN7 PIN_INPUT


#define PORTD_PIN0 PIN_OUTPUT
#define PORTD_PIN1 PIN_OUTPUT
#define PORTD_PIN2 PIN_OUTPUT
#define PORTD_PIN3 PIN_INPUT //COLUMN4
#define PORTD_PIN4 PIN_OUTPUT
#define PORTD_PIN5 PIN_INPUT //COLUMN3
#define PORTD_PIN6 PIN_INPUT //COLUMN2
#define PORTD_PIN7 PIN_INPUT //COLUMN1


#endif /* DIO_CONFIG_H_ */