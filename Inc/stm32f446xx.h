/*
 * stm32f446xx.h
 *
 *  Created on: Oct 5, 2026
 *      Author: alimohamed2252006
 *
 *      COMMENT: Only the Used Registers are Included !
 */

#ifndef STM32F446XX_H_
#define STM32F446XX_H_

#include <stdint.h>

///MEMORY
#define AHB1_PERIPH_BASE 0x40020000U
#define APB1_PERIPH_BASE 0x40000000U
///PERIPHERALS
#define GPIOA_BASE 0x40020000U
#define TIM2_BASE 0x40000000U
#define TIM3_BASE 0x40000400U
#define USART2_BASE 0x40004400U

#define RCC_BASE 0x40023800U
///REGISTERS
typedef struct{

    volatile uint32_t CR;          // 0x00
    volatile uint32_t PLLCFGR;     // 0x04
    volatile uint32_t CFGR;        // 0x08
    volatile uint32_t CIR;         // 0x0C

    volatile uint32_t AHB1RSTR;    // 0x10
    volatile uint32_t AHB2RSTR;    // 0x14
    volatile uint32_t AHB3RSTR;    // 0x18

    uint32_t RESERVED0;            // 0x1C

    volatile uint32_t APB1RSTR;    // 0x20
    volatile uint32_t APB2RSTR;    // 0x24

    uint32_t RESERVED1;            // 0x28
    uint32_t RESERVED2;            // 0x2C

    volatile uint32_t AHB1ENR;     // 0x30 -- GPIOA
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;

     uint32_t RESERVED;

    volatile uint32_t APB1ENR;


}RCC_REG;

typedef struct
{
    volatile uint32_t MODER;       // 0x00
    volatile uint32_t OTYPER;      // 0x04
    volatile uint32_t OSPEEDR;     // 0x08
    volatile uint32_t PUPDR;       // 0x0C
    volatile uint32_t IDR;         // 0x10
    volatile uint32_t ODR;         // 0x14
    volatile uint32_t BSRR;        // 0x18
    volatile uint32_t LCKR;        // 0x1C
    volatile uint32_t AFR[2];      // 0x20, 0x24

} GPIOA_REG;

typedef struct
{
	volatile uint32_t CR1; /*WIL BE USED*/ //ENABLE THE CLOCK
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR; /* WILL BE USED */ //UIF - Status register UIF BIT 0
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;  // 0x20
	volatile uint32_t CNT; /* WILL BE USED */ //CLOCK
	volatile uint32_t PSC; /* WILL BE USED */ //PRESCALAR
	volatile uint32_t ARR; /* WILL BE USED */ //FINAL_VALUE


}TIM_REG;

typedef struct{

	volatile uint32_t USART_SR; // STATUS
	volatile uint32_t USART_DR; // DATA
	volatile uint32_t USART_BRR; // BAUD RATE CONFIGURATION
	volatile uint32_t USART_CR1; // CONF ->
	volatile uint32_t USART_CR2; // CONF ->
	volatile uint32_t USART_CR3; // CONF ->
	volatile uint32_t USART_GTPR; // __not used__

}USART2_REG;

#define RCC ((RCC_REG*) RCC_BASE)
#define GPIOA ((GPIOA_REG*) GPIOA_BASE)
#define TIM2 ((TIM_REG*) TIM2_BASE)
#define TIM3 ((TIM_REG*) TIM3_BASE)
#define USART2 ((USART2_REG*) USART2_BASE)


#endif /* STM32F446XX_H_ */
