/*
 * USART.c
 *
 *  Created on: Oct 5, 2026
 *      Author: alimohamed2252006
 */

#include "stm32f446xx.h"
#include "USART.h"

void USART_init(){

	RCC->APB1ENR |= (1<<17); //ENABLE USART2

	/*
	 * TX - PINA2
	 * RX - PINA3
	 * ALTERNATE FUNCTION
	 *
	 */
	GPIOA->MODER |= (0x2<<4);//pin2 AF
	GPIOA->MODER |= (0x2<<6);//pin3 AF
	GPIOA->AFR[0] |= (0x7<<8);//AF7 -- USART pin2
	GPIOA->AFR[0] |= (0x7<<12);//AF7 -- USART pin3

}


void USART_TRANSMIT(char c){

	//Turn On Peripheral AND TE bit has to be set
	USART2->USART_CR1 |= (1<<13); // USART enable
	USART2->USART_CR1 |= (1<<3); // TRANSMITTER ENABLE

		USART_SET_BAUD_RATE();

	//DATA LENGTH
	USART2->USART_CR1 &= ~(1<<12);	//M bit for 8 bit length data frame

	//Set Stop Bits
	USART2->USART_CR2 &= ~(0x3<<12); // 00-forces 1 STOP BIT

	while(1){
		if((USART2->USART_SR & 0x80)){ // TXE=1 Data Register Empty

				USART2->USART_DR = c; // 8-bits of ASCII c

			break;

		}
	}



	return;
}

void USART_SET_BAUD_RATE(){

	/*
	 * AIM == 115200 Baud Rate
	 *
	 * 					  Clock_Frequency
	 * BAUD RATE =  ------------------------
	 * 				8 * (2-OVERS) * USARTDIV
	 *
	 * 				Clock_Frequency == 16Mhz
	 * 				OVERS == 0 --> 16xSamplings (Handled by Hardware)
	 * 				USARTDIV == MANTISSA||FRACTION
	 * 						 == 8.6806
	 *
	 */

	//USART2->USART_CR1 keep the sampling as 16

	//Baud rate Generator Register Mantissa | fraction
	USART2->USART_BRR = ((0x8) << 4)  | 0xB; // 8.6806


	return;
}

