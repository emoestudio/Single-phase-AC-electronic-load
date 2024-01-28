/*
 * ControlTimer.h
 *
 *  Created on: Jul 4, 2022
 *      Author: EVA
 */

#ifndef INC_EVA_TIMER_EXTI_H_
#define INC_EVA_TIMER_EXTI_H_
#include "stm32f4xx_hal.h"
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void PLL_Success_Detect(void);
void System_Protect(void);
void Key_Detect();
#endif /* INC_EVA_TIMER_EXTI_H_ */
