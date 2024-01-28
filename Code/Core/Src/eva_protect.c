/*
 * eva_protect.c
 *
 *  Created on: Jul 25, 2022
 *      Author: EVA
 */
#include "main.h"

int flag_power_start=0;

int flag_Protect=0;
int time_U1rms_over = 0;
void System_Protect(void){
	if(flag_Start_Running==1&&ad5_avg_flag==1&&flag_Protect==0&&flag_power_start==1){
			if(thetas<0.03f+PI/2&&thetas>-0.03f+PI/2){
				PID_init(&pid_Udc,0.016f, 0.25f,0,0.95,-0.95,0.4,Control_Time);
				PID_init(&pid_I1d,8,950,0,15,-15,0,Control_Time);
				PID_init(&pid_I1q,8,950,0,15,-15,0,Control_Time);
				//整流开关打开
				HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
				HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
				HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_1);
				HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_2);
				//逆变器打开
				HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);
				HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_2);
				HAL_TIMEx_PWMN_Start(&htim8,TIM_CHANNEL_1);
				HAL_TIMEx_PWMN_Start(&htim8,TIM_CHANNEL_2);

				flag_Start_Running=2;
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
			}
		  }
	if(flag_power_start==0){
		  flag_Protect=0;
		  flag_Start_Running=0;
		  flag_PLL=0;
		  thetas=0;
		  HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
		  HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
		  HAL_TIMEx_PWMN_Stop(&htim1,TIM_CHANNEL_1);
		  HAL_TIMEx_PWMN_Stop(&htim1,TIM_CHANNEL_2);

	}
	if(U1rms_screen>35||Udc>60){
		if(U1rms_screen>35){
			  flag_Protect=1;
		}
		else if(Udc>60){
			  flag_Protect=2;
		}
		  HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
		  HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
		  HAL_TIMEx_PWMN_Stop(&htim1,TIM_CHANNEL_1);
		  HAL_TIMEx_PWMN_Stop(&htim1,TIM_CHANNEL_2);
//		  HAL_TIM_PWM_Stop(&htim8, TIM_CHANNEL_1);
//		  HAL_TIM_PWM_Stop(&htim8, TIM_CHANNEL_2);
//		  HAL_TIMEx_PWMN_Stop(&htim8,TIM_CHANNEL_1);
//		  HAL_TIMEx_PWMN_Stop(&htim8,TIM_CHANNEL_2);

	}
	if(U1rms_screen<32&&Udc<45&&flag_Protect!=0){
		  flag_Protect=0;
		  flag_Start_Running=0;
		  flag_PLL=0;
	}
}
