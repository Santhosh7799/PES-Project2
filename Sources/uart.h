/*
 * uart.h
 *
 *  Created on: Oct 20, 2017
 *      Author: srikant
 */

#ifndef SOURCES_UART_H_
#define SOURCES_UART_H_


#include<stdio.h>
#include<stdint.h>
#include <MKL25Z4.h>
#include "CircBuf.h"
typedef enum{
	UART_Success,
	UART_Null_Error
}UART_Stat;

void UART_configure();
UART_Stat UART_receive(uint8_t *a);
UART_Stat UART_Send(uint8_t* ch);
UART_Stat UART_send_n(uint8_t *str, uint8_t length);
UART_Stat UART_receive_n(uint8_t *str, uint8_t length);
void UART0_IRQHandler (void);

typedef struct{
	uint8_t Alphabets;
	uint8_t Numerics;
	uint8_t punctuations;
	uint8_t Misc;
}stats;

#endif /* SOURCES_UART_H_ */
