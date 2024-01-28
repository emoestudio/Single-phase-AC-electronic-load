/*
 * eva_pll.c
 *
 *  Created on: Jul 25, 2022
 *      Author: EVA
 */


#include "main.h"

float ws,fs,thetas;
pid_p PLL;
int time_Point_PLL =10;
int flag_PLL=0;
int flag_Start_Running=0;



void PLL_Realize(){
	//    	PLL锁相，先得角速度再积分，角度大于2pi则减
	//    	ws加一个滤波器，滤出高频分量，用2kHz滤波器 4us
	    	ws=0.9f*ws+0.1f*PID_realize(&PLL,0,-U1q);
	    	thetas+=ws*Control_Time;
	    	if(thetas>=2*PI){thetas-=2*PI;}
	//    	判断PLL锁相锁成功没有，每1/50s检测一次，设定裕度为0.5，检测10次，如果都通过就锁相成功
	//    	如果锁相成功，则初始化电压电流环，并且打开开关。要在过零点打开开关
	    	PLL_Success_Detect();
}

void PLL_Success_Detect(void){
	//判断PLL锁相锁成功没有，每1/50s检测一次，设定裕度为0.5，检测10次，如果都通过就锁相成功
	//如果锁相成功，则初始化电压电流环，并且打开开关。要在过零点打开开关
	if(time_Point_PLL>=Control_Frequency)
		time_Point_PLL-=Control_Frequency;
	if(flag_Start_Running==0){
		if(flag_PLL<10){
			if(time_Tim1==time_Point_PLL){
				if((U1q<0.2||U1q>-0.2)&&(U1d>5||U1d<-5)){
					time_Point_PLL+=400;
					flag_PLL+=1;
				}
				else{
					flag_PLL-=5;
					if(flag_PLL<0)
						flag_PLL=0;
				}
			}
		}
		else{
			flag_Start_Running=1;
		}
	}


}
