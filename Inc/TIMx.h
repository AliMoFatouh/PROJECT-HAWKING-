/*
 * TIMx.h
 *
 *  Created on: Oct 5, 2026
 *      Author: alimohamed2252006
 */

#ifndef TIMX_H_
#define TIMX_H_

#include <stdint.h>

void TIM2_init();
void TIM3_init();
void TIM3_DISABLE();
void TIM3_ENABLE();

void wait(uint32_t ms);

#endif /* TIMX_H_ */
