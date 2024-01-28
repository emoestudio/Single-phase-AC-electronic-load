/*
 * ControlTimer.c
 *
 *  Created on: 2022年7月5日
 *      Author: EVA
 */


/*
 * ControlTimer.c
 *
 *  Created on: Jul 4, 2022
 *      Author: EVA
 */

#include "main.h"





void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == htim2.Instance)
    {
//    	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET);
    	//记录一个定时器time,用两次time值相减可以得到对应的任意事件的两项
    	Clock_Timer();
    	Screen_Clock();
    	Key_Clock();
//    	进行ADC(3us)和进行数据的存储(2.2us)
//    	进行正弦运算注意角度是弧度制 1.8us
//    	对输入电压、输入电流、Io电流进行Park运算，这个100后续要变 1us
    	ADC_DAC_get_and_show();
    	PLL_Realize();
    	Control_Value_Set();
    	PI_Control();

    	//进行系统保护
    	System_Protect();
    	PWM_Output();
    }
}




