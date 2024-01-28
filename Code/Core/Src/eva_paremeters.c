/*
 * ParemetersOfACDCSinglePhase.c
 *
 *  Created on: 2022年7月14日
 *      Author: EVA
 */


#include <eva_pid.h>
#include <eva_queue.h>
#include "arm_math.h"
/*LCR电路参数*/
float L1=890e-6,Cdc=2000e-6;
float Xs=2*PI*50*890e-6;
/*ADC采样后真实的电路参数*/
float U1,Is,Udc,I1;
SqQueue U1_queue={{},0,0},Is_queue={{},0,0},I1_queue={{},0,0};
float U1rms_screen,I1rms_screen,PF_set=1;
/*DQ变换参数*/
float U1d,U1q,Isd,Isq,I1d,I1q;
float sin_thetas,cos_thetas;
/*占空比调制比等参数*/
float UId,UIq;
float DdR,DqR,DalphaR,DbetaR,D1R,D2R;
float DdI=0,DqI=0,DalphaI,DbetaI,D3I,D4I;//占空比的dq轴值


