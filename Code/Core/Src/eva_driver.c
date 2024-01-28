/*
 * eva_PWM.c
 *
 *  Created on: Jul 25, 2022
 *      Author: EVA
 */
#include "main.h"

void PWM_Output(){
	//    	开环测试
//	    	DdR=0.5,DqR=0;
//	DdI=0.5;DqI=0;
	//占空比Park逆变换
	arm_inv_park_f32(DdR,DqR,&DalphaR,&DbetaR,sin_thetas,cos_thetas);
	//单极性倍频输出
	D1R=(1+DalphaR)*0.5f;
	D2R=(1-DalphaR)*0.5f;
	TIM1->CCR1=Tim1_ARR*D1R;
	TIM1->CCR2=Tim1_ARR*D2R;
	//占空比Park逆变换
	arm_inv_park_f32(DdI,DqI,&DalphaI,&DbetaI,sin_thetas,cos_thetas);
	//单极性倍频输出
	D3I=(1+DalphaI)*0.5f;
	D4I=(1-DalphaI)*0.5f;
	TIM8->CCR1=Tim8_ARR*D3I;
	TIM8->CCR2=Tim8_ARR*D4I;
}
