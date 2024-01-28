/*
 * pid.c
 *
 *  Created on: Jul 7, 2021
 *      Author: 10161
 */


#include <eva_pid.h>
#include "main.h"


void PID_Limit(pid_p *pid)
{
	if(pid->result > pid->max_output)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET);
		pid->integral=pid->max_output_integral;
		pid->result =pid->max_output;
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_RESET);
	}
	else if(pid->result < pid->min_output){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET);
		pid->integral=pid->min_out_integral;
		pid->result=pid->min_output;
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_RESET);
	}
}

void PID_init(pid_p *pid,float kp,float ki, float kd,float max_output,float min_output, float initial_result,float Ts)
{
    //printf("PID_init begin \n");
    pid->REF= 0.0f;		  	// ????????
    pid->ACTUAL= 0.0f;			// adc?????
    pid->err= 0.0f;				    // ???????????
    pid->err_last=0.0f;			    // ??????
    pid->integral= 0.0f;			  	// ???
    pid->Kp= kp;				    // ????
    pid->Ki= ki*Ts;				    // ????
    pid->Kd= kd;				    // ????
    pid->result=0;
    //printf("PID_init end \n");
    pid->max_output=max_output;
    pid->min_output=min_output;
    pid->max_output_integral=pid->max_output/pid->Ki;
    pid->min_out_integral=pid->min_output/pid->Ki;
    pid->integral=initial_result/ki;
    pid->result = pid->Kp * pid->err + pid->Ki * pid->integral + pid->Kd * ( pid->err - pid->err_last);
    PID_Limit(pid);
}

float PID_realize(pid_p *pid, float vref, float v_now)
{

    pid->REF = vref;			// ???????
    pid->ACTUAL = v_now;	// ?????? = ADC_Value * 3.3f/ 4096
    pid->err =   pid->REF - pid->ACTUAL;	//????
    pid->result = pid->Kp * pid->err + pid->Ki * pid->integral + pid->Kd * ( pid->err - pid->err_last);
    pid->integral += pid->err;
    pid->err_last = pid->err;				//???????
    PID_Limit(pid);
    return pid->result;
}
