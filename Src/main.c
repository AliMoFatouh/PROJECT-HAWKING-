/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Hanafy, Ali Mohamed Fattouh
 * @brief          : PROJECT HAWKING
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2026 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/*
 *
 * Main Header Files
 *
 */
#include <stdint.h>
#include "stm32f446xx.h"

/*
 *
 * Driver Files
 *
 */
#include "TIMx.h"
#include "USART.h"
#include "GPIOAx.h"
#include "morse_decode.h"



#define HIGH 1
#define LOW 0


#define DOT_TIME 150
#define SPACE_TIME 2000
#define NEXT_CHAR_TIME 500



int main(void){


	tree_init();
	GPIOA_init();
	TIM2_init();
	TIM3_init();
	USART_init();
	uint8_t TRANSMIT_lock_ON = LOW;

	while(1){// -- POLLING

		/*
		 * ERROR ALARM? [low to high]
		 */
		if(char_i > 4 && TRANSMIT_lock_ON == LOW){

			USART_TRANSMIT('3');
			wait(500);//penalty
			reset_string();
		}
		/*
		 * Text Display [low to high]
		 */
		if(char_i > 0 && TRANSMIT_lock_ON == LOW){

			if( TIM3->CNT >= NEXT_CHAR_TIME ){
				MORSE_ENTRY_SEQUENCE[char_i] = '\0';
				char c = decode_morse_code(&root,0);
				USART_TRANSMIT(c);
				if(c == '2'){
					wait(500); //penalty
				}
				reset_string();
			}
		}
		/*
		 * SEND SPACE
		 */
		if( TIM3->CNT >= SPACE_TIME && TRANSMIT_lock_ON == LOW ){
				USART_TRANSMIT(' ');
				TIM3_DISABLE();
		 }
		/*
		 * BUTTON PRESSED! from LOW
		 */
		if(!(GPIOA->IDR & 1)){
				wait(25); // Solve_Debounce
				if(!(GPIOA->IDR & 1)){

					GPIOA->ODR |= (1<<1); //HIGH for A1 OUTPUT HIGH GPIOA PIN 1
					if(TRANSMIT_lock_ON == LOW){

						TIM3_DISABLE();
						TIM3_ENABLE();
						USART_TRANSMIT('1'); //BEEP
						TRANSMIT_lock_ON = HIGH;
						}
					}

		}else{
						/*
						 * BUTTON RELEASED! from HIGH
						 */
							if(TRANSMIT_lock_ON == HIGH){

								if(TIM3->CNT <= DOT_TIME){//DOT 20-150ms
										MORSE_ENTRY_SEQUENCE[char_i++] = '.';
										USART_TRANSMIT('.');
								}else{//DASH >=150ms
										MORSE_ENTRY_SEQUENCE[char_i++] = '-';
										USART_TRANSMIT('-');
								}

							    TIM3_DISABLE();
								TIM3_ENABLE();
								USART_TRANSMIT('0'); //NO-BEEP
								TRANSMIT_lock_ON = LOW;
							}

							GPIOA->ODR &= ~(1<<1); //LOW for A1 OUTPUT HIGH GPIOA PIN 1
				}//__else__ [button released]

	}//__while__





	return 0;

}//__main__


