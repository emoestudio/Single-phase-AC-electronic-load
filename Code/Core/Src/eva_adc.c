/*
 * eva_adc.c
 *
 *  Created on: Jul 25, 2022
 *      Author: EVA
 */


#include "main.h"
uint32_t ADC_Value[ADC_num];
uint8_t i;
int ad1,ad2,ad3,ad4,ad5,ad6,ad7,ad8;

/*ADC采样后真实的电路参数*/
//float Isd_temp,Isq_temp;
float I1d_screen,I1q_screen;

void ADC_DAC_get_and_show()
{
	ADC_To_adx();
	ADC_ad5_avg_Get();
	ADC_Real_Value_Get();
	ADC_Queue_Save();
	ADC_Sine_Calculate();
	ADC_Park_Transform();
	ADC_Paremeters_Calc();
	HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 2048+100*I1);
}

void ADC_To_adx(){

	for(i = 0,ad1 =0,ad2=0,ad3=0,ad4=0,ad5=0,ad6=0,ad7=0,ad8=0; i< ADC_num;)
	{
			ad1 += ADC_Value[i++];
			ad2 += ADC_Value[i++];
			ad3 += ADC_Value[i++];
			ad4 += ADC_Value[i++];
			ad5 += ADC_Value[i++];
			ad6 += ADC_Value[i++];
			ad7 += ADC_Value[i++];
			ad8 += ADC_Value[i++];
	}
	ad1/=(ADC_num/8);
	ad2/=(ADC_num/8);
	ad3/=(ADC_num/8);
	ad4/=(ADC_num/8);
	ad5/=(ADC_num/8);
	ad6/=(ADC_num/8);
	ad7/=(ADC_num/8);
	ad8/=(ADC_num/8);

}



//在开始前控制进行输出电流采样
const int ADC5_AVG_NUM = 2000;//0.1s
const float ADC5_AVG_Weight = 50e-5;//=1/2000
float ad5_sum=0;
int ad5_avg=0;
int time=0;
int ad5_avg_flag=0;
void ADC_ad5_avg_Get(){
	if(ad5_avg_flag==0){
		time++;
		ad5_sum+=(ad5-ad6)*ADC5_AVG_Weight;
		if(time>=ADC5_AVG_NUM){
			ad5_avg_flag=1;
			ad5_avg=ad5_sum;
			time=0;
			ad5_sum=0;
		}
	}
}
void ADC_Real_Value_Get(){
	//	Us ad1-ad2 10kHz滤波器滤�??
	//	Us=0.8f*Us+0.2f*(ad1-ad2)/4096.0f*3.3f*18.292f*修正
		U1=0.8f*U1+0.2f*(ad1-ad2)*0.015032f;

	//	Is ad3-ad4 10kHz滤波器滤�??
	//	Is=0.8f*Is+0.2f*((ad3-ad3_avg)/4096.0f*3.3f)*1.6835f*1.19;
//		Is=0.8f*Is+0.2f*(ad3-ad4)*0.001614f;


	//	IoIV ad5-ad6 10kHz滤波 注意是负的！！！这个地方的符号要细致的看
	//	IoIV=0.8f*Is+0.2f*((ad5-ad6)/4096.0f*3.3f)*3.7037f*1.26;
		I1=0.8f*I1+0.2f*(ad5-ad6-ad5_avg)*-0.00343f;
	//	Udc ad7-ad8
		//对母线直流电压用4kHz的低通滤波器进行滤波，对�????50Hz幅�?�差0.9999，角�????1°不到，应该可用，如果不行就用8kHz
	//	Udc=0.95f*Udc+0.05f*(ad4-ad5)/4096.0f*3.3f*26.49989f;
		Udc=0.95f*Udc+0.05f*(ad7-ad8)*0.021350f-0.01f;
}
void ADC_Queue_Save(){
	enQueue(&U1_queue,U1);
//	enQueue(&Is_queue,Is);
	enQueue(&I1_queue,I1);
}
void ADC_Sine_Calculate(){
	//进行正弦运算 注意角度是弧度制 1.8us

	sin_thetas=arm_sin_f32(thetas);
	cos_thetas=arm_cos_f32(thetas);
}
void ADC_Park_Transform(){
	//对输入电压�?�输入电流�?�Io电流进行Park运算，这�??100后续要变 1us

	arm_park_f32(U1,U1_queue.data[(U1_queue.rear-100+maxsize)%maxsize],
			&U1d,&U1q,sin_thetas,cos_thetas);

	//Isd、Isq过滤波器



	arm_park_f32(I1,I1_queue.data[(I1_queue.rear-100+maxsize)%maxsize],
			&I1d,&I1q,sin_thetas,cos_thetas);
}

void ADC_Paremeters_Calc(){
	U1rms_screen=0.999f*U1rms_screen+0.001f*U1d*0.7071f;
	I1d_screen=0.999f*I1d_screen+0.001f*I1d;
	I1q_screen=0.999f*I1q_screen+0.001f*I1q;
	arm_sqrt_f32(I1d_screen*I1d_screen+I1q_screen*I1q_screen,&I1rms_screen);
//	PF=I1d_screen/I1rms;
	I1rms_screen=I1rms_screen*0.7071f;
//	I1rms_screen=I1rms_screen*0.7071f*0.8931f+0.2386f;
}

