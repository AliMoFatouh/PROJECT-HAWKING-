/*
 * TIMx.c
 *
 *  Created on: Oct 5, 2026
 *      Author: alimohamed2252006
 */

#include "stm32f446xx.h"
#include "TIMx.h"

void TIM2_init(){
	RCC->APB1ENR |= (1<<0); // enable TIM2
}
void TIM3_DISABLE(){

	TIM3->CR1 &= ~(1<<0); //DISABLE TIM3

    TIM3->CNT = 0; //Let Count Start from 0

}
void TIM3_ENABLE(){
	TIM3->CR1 |= (1<<0); //ENABLE TIM

}
void TIM3_init(){
	RCC->APB1ENR |= (1<<1);   // enable TIM3
	TIM3->PSC = 15999;        // 1 kHz, 1 count = 1 ms
	TIM3->ARR = 0xFFFF;       // TIM3 is 16-bit
}

void wait(uint32_t ms){

	TIM2->CNT = 0; //Let Count Start from 0
	TIM2->PSC = 15999; //16Mhz -> 10kHz f prescalar
	TIM2->ARR =  (1*ms) - 1; //FINAL VALUE == ARR - 1

	/*
	 *
	 * 1000Counts/second
	 *
	 * 1 COUNT == 1 ms
	 *
	 */

	TIM2->CR1 |= (1<<0); //ENABLE TIM

	while(!(TIM2->SR & 0X01)){
		// WAIT -- POLLING ALGORITHM

		/*
		if((GPIOA->IDR & 1)){
			break;
		} //Button Released?!
		*/


	}
	TIM2->SR &= ~(1<<0); //Clear Status flag bit!

	TIM2->CR1 &= ~(1<<0); //DISABLE TIM

	return; //RETURN ONCE THE CLOCK IS COMPLETE

}
