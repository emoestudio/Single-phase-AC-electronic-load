/*
 * clock_Timer.c
 *
 *  Created on: Jul 25, 2022
 *      Author: EVA
 */
#include "main.h"

int time_Tim1=0;
void Clock_Timer(){
	time_Tim1++;
	if(time_Tim1>Control_Frequency){
		time_Tim1-=Control_Frequency;
	}
}
