/*
 * homework4.h
 *
 *  Created on:
 *      Author: Stephen Hurd
 */

#ifndef HOMEWORK4_H_
#define HOMEWORK4_H_

// This function initializes the board by turning off the Watchdog Timer.
void initBoard();
bool charFSM(char rChar);
void UART_initmodule();
void UART_enableModule();
void GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PIN2);
void GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PIN3);

// TODO: Define any constants that are local to homework.c using #define


#endif /* HOMEWORK4_H_ */
