/*
 * USART.h
 *
 *  Created on: Oct 5, 2026
 *      Author: alimohamed2252006
 */

#ifndef USART_H_
#define USART_H_

#include <stdint.h>


void USART_init();

void USART_TRANSMIT(char c);
void USART_SET_BAUD_RATE();

#endif /* USART_H_ */
