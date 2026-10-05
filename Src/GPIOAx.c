/*
 * GPIOAx.c
 *
 *  Created on: Oct 5, 2026
 *      Author: alimohamed2252006
 */

#include "stm32f446xx.h"
#include "GPIOAx.h"


void GPIOA_init(){


	RCC->AHB1ENR |= (1 << 0); // enable GPIOA

	/*
	 *
	 * GPIOA
	 *
	 */
	///GPIOA
	GPIOA->MODER |= (1<<2); //OUTPUT MODE GPIOA PIN1
	/*GPIOA->MODER |= (0<<0);*/ //PIN0 GPIOA INPUT BY DEFAULT
	GPIOA->PUPDR |= (1<<0); //ACTIVATE PULL UP GPIOA PIN 0
	//GPIOA->USART2

}
