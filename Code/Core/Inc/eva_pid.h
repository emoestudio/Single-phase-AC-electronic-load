/*
 * pid.h
 *
 *  Created on: Jul 7, 2021
 *      Author: 10161
 */

#ifndef INC_EVA_PID_H_
#define INC_EVA_PID_H_


typedef struct
{
    float REF;	  	//?????
    float ACTUAL;	//?????
    float err;			    //?????
    float err_last;		  	//????????
    float Kp,Ki,Kd;		  	//????????????
    float result;		    //pid????
    float integral;		  	//?????
    float max_output,min_output,initial_result;
    float max_output_integral,min_out_integral;
}pid_p;


void PID_Limit(pid_p *pid);
void PID_init(pid_p *pid,float kp,float ki, float kd,float max_output,float min_output, float initial_result,float Ts);
float PID_realize(pid_p *pid, float vref, float v_now);

#endif /* INC_EVA_PID_H_ */
