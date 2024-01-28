/*
 * screen.c
 *
 *  Created on: Jul 20, 2022
 *      Author: EVA
 */
#include "main.h"

int flag_screen=1;
int flag_fresh_screen=1;
float ref_Isq_last,Usrms_last,I1drms_last,PF_last;
extern int flag_power_start;
extern float sinphi;
int flag_screen_dark=1;
void Screen_Print(){
	Screen_Fresh_Detect();
	if(flag_screen==1){
		while(time_Tim1>5*20);

			printf("CLR(0);\r\n");

		while(time_Tim1<45*20);//40ms
		//Mode
		if(Mode==2){
			printf("DC16(15,10,'Mode:CR%.3f',16);\r\n",Rin_set);
		}else if(Mode==3){
			printf("DC16(15,10,'Mode:CP%.2fW',16);\r\n",Power_set);
		}else if(Mode==4){
			printf("DC16(15,10,'Mode:CS%.2fVA',16);\r\n",Spower_set);
		}else{
			printf("DC16(15,10,'Mode:CC%.3fA',16);\r\n",I1rms_set);
		}
		while(time_Tim1<85*20);//40ms
		//PF
		if(choose_inductance_capacity==-1)
			printf("DC16(15,30,'PF: %.3f C',16);\r\n",PF_set);
		else {
			printf("DC16(15,30,'PF: %.3f L',16);\r\n",PF_set);
		}
		while(time_Tim1<125*20);//40ms
//		Show U1I1
		printf("DC16(15,60,'U1: %.2fV',16);\r\n",U1rms_screen);
		while(time_Tim1<165*20);//40ms
		printf("DC16(15,80,'I1: %.3fA',16);\r\n",I1rms_screen);
		while(time_Tim1<205*20);//40ms
//		Power
		printf("DC16(15,100,'P:%.2fW',16);\r\n",U1rms_screen*I1rms_screen*PF_set);
		while(time_Tim1<245*20);//40ms
		printf("DC16(15,120,'Q:%.2fvar',16);\r\n",U1rms_screen*I1rms_screen*sinphi);
		while(time_Tim1<285*20);//40ms

		if(flag_Protect==1){

			printf("DCV16(5,140,'U1 Overvoltage',1);\r\n");
		}else if(flag_Protect==2){

			printf("DCV16(5,140,'Loss Resistance',1);\r\n");
		}
		while(time_Tim1<365*20);//40ms

		if(flag_screen_dark==1){
			printf("BL(200);\r\n");
		}else {
			printf("BL(0);\r\n");
		}
		while(time_Tim1<405*20);//40ms
		flag_screen=0;
		flag_fresh_screen=0;
	}
}
void Screen_Fresh_Detect(){
	if(ref_Isqrms-ref_Isq_last>0.005f||ref_Isqrms-ref_Isq_last<-0.005f){
		flag_fresh_screen=1;
		ref_Isq_last=ref_Isqrms;
	}
	if(U1rms_screen-Usrms_last>0.5f||U1rms_screen-Usrms_last<-0.5f){
		flag_fresh_screen=1;
		Usrms_last=U1rms_screen;
	}
	if(I1rms_screen-I1drms_last>0.02f||I1rms_screen-I1drms_last<-0.02f){
		flag_fresh_screen=1;
		I1drms_last=I1rms_screen;
	}
	if(PF_set-PF_last>0.005f||PF_set-PF_last<-0.005f){
		flag_fresh_screen=1;
		PF_last=PF_set;
	}
}
//extern int time_Tim1;
void Screen_Clock(){
	if(time_Tim1==1){
		flag_screen=1;
	}
}

