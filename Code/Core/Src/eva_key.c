/*
 * eva_key.c
 *
 *  Created on: Jul 25, 2022
 *      Author: EVA
 */
#include "main.h"

void Key_Clock(){
	if(time_Tim1%(4000)==0){
		Key_Detect();
	}
}

extern int choose_inductance_capacity;
/*Key_Detect
 * 按键识别
 * PE2 K1Up 增加PF
 * PE3 K1Down 减小PF
 * PE4 K1Left 感性
 * PE5 K1Right 容性
 * PD3 K2Up 增加设定量
 * PD2 K2Down 减小设定量
 * PD1 K2Left 一键归为额定工况
 * PD0 K2Right
 * */
extern int flag_power_start;
extern int flag_screen_dark;
void Key_Detect(){
	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_2)== GPIO_PIN_RESET){
		PF_set+=0.01f;
	}
	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_3)== GPIO_PIN_RESET){
		PF_set-=0.01f;
	}
	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_5)== GPIO_PIN_RESET){
		choose_inductance_capacity=1;
		flag_fresh_screen=1;
	}
	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_4)== GPIO_PIN_RESET){
		choose_inductance_capacity=-1;
		flag_fresh_screen=1;
	}
	if(Mode==2){
		if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3)== GPIO_PIN_RESET){
			Rin_set+=0.5;
		}
		if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2)== GPIO_PIN_RESET){
			Rin_set-=0.5;
		}
	}else if(Mode==3){
		if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3)== GPIO_PIN_RESET){
			Power_set+=0.5;
		}
		if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2)== GPIO_PIN_RESET){
			Power_set-=0.5;
		}
	}else if(Mode==4){
		if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3)== GPIO_PIN_RESET){
			Spower_set+=0.5;
		}
		if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2)== GPIO_PIN_RESET){
			Spower_set-=0.5;
		}
	}else{
		if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3)== GPIO_PIN_RESET){
			I1rms_set+=0.1;
		}
		if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2)== GPIO_PIN_RESET){
			I1rms_set-=0.1;
		}
	}

	if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_1)== GPIO_PIN_RESET){
		I1rms_set=2.0;PF_set=1;Mode=1;
	}
	if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_0)== GPIO_PIN_RESET){
		flag_screen_dark=1-flag_screen_dark;
	}
	flag_power_start=1-HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);

	Mode_Detect();
}

//Mode 为1或其他 则是CC，Mode为2，CR，为3，CP,为4，则为CS
extern int Mode;
void Mode_Detect(){

	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)== GPIO_PIN_RESET){
		Mode=2;
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)== GPIO_PIN_RESET){
			Mode=4;
		}
	}
	else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)== GPIO_PIN_RESET){
		Mode=3;
	}else Mode=1;
}
