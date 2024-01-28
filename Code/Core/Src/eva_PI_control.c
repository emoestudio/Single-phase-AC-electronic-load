/*
 * eva_PI_control.c
 *
 *  Created on: Jul 25, 2022
 *      Author: EVA
 */
#include "main.h"

pid_p pid_Udc,pid_I1d,pid_I1q;
/*控制设计*/
float ref_Udc=48,ref_I1d=2.824,ref_Isqrms=0,ref_I1q=0.02;


void PI_Control(){
	//逆变电压环
	DdI=1-PID_realize(&pid_Udc,ref_Udc,Udc);



	UId=PID_realize(&pid_I1d,ref_I1d,I1d);
	UIq=PID_realize(&pid_I1q,ref_I1q,I1q);
	//前馈和限制
	DdR=(U1d+I1q*Xs-UId)/Udc;
	DqR=(U1q-I1d*Xs-UIq)/Udc;
//    限制DdDq
//	    	if(Dd>0.8)Dd=0.8;
//	    	else if (Dd<-0.8) Dd=-0.8;
//	    	if(Dq>0.8)Dq=0.8;
//	    	else if (Dq<-0.8) Dq=-0.8;

//    	开环测试
//    	D3d=0.5;D3q=0;
}



