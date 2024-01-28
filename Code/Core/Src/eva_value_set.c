/*
 * eva_value_set.c
 *
 *  Created on: 2022年7月28日
 *      Author: EVA
 */
#include "eva_value_set.h"
#include "main.h"

int choose_inductance_capacity = 1;//电感为1电容为-1
float sinphi=0,cosphi=0;
float I1_ref = 2.0f;
int Mode=1;//Mode 为1或其他 则是CC，Mode为2，CR，为3，CP
float I1rms_set=2, Rin_set=15,Power_set=60,I1rms_set_fix,Spower_set=60;

void Control_Value_Set(){
	//感性容性校正不一样
	if(choose_inductance_capacity==1){
		if(PF_set<0.5f){
			cosphi=PF_set*1.01776f-0.01942f;
		}else if(PF_set<0.9f){
			cosphi=PF_set*1.027f-0.0261f;
		}
		else {
			cosphi=PF_set*1.0191f-0.0173f;
		}
	}else {
		//容性
		cosphi=0.0516*PF_set*PF_set+0.9808f*PF_set-0.0322;
	}
	//拟合关系
//	cosphi=PF_set;
	//不同模式电流参考值不一样
	if(Mode==2){
		I1rms_set_fix = U1rms_screen/Rin_set;
	}else if(Mode==3){
		I1rms_set_fix =Power_set/U1rms_screen/PF_set;
	}else if(Mode==4){
		I1rms_set_fix =Spower_set/U1rms_screen;
	}else{
		I1rms_set_fix=(I1rms_set-2)*1.15f+2;
	}

	if(choose_inductance_capacity==1){
		if(PF_set<0.5){
			I1_ref = I1rms_set_fix+0.03545f-0.05f*PF_set;
		}else if(PF_set<0.62){
			I1_ref = I1rms_set_fix+0.016f;
		}else if(PF_set<0.82){
			I1_ref = I1rms_set_fix+0.0702f-0.0858f*PF_set;
		}else{
			I1_ref = I1rms_set_fix;
		}
	}else {
		//Mode1容性
		if(PF_set<0.64){
			I1_ref = I1rms_set_fix+0.0816f-0.10592f*PF_set;
		}else{
			I1_ref = I1rms_set_fix+0.0338f-0.03748f*PF_set;
		}

	}
		ref_I1d=I1_ref*Sqrt2*cosphi;
		arm_sqrt_f32(1-cosphi*cosphi, &sinphi);
		ref_I1q=I1_ref*Sqrt2*sinphi*choose_inductance_capacity;

}
