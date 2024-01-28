/*
 * eva_extern_paremeters.h
 *
 *  Created on: Jul 25, 2022
 *      Author: EVA
 */

#ifndef INC_EVA_EXTERN_PAREMETERS_H_
#define INC_EVA_EXTERN_PAREMETERS_H_

/*ADC采样后真实的电路参数*/
extern float U1,Is,Udc,I1;
/*存储Us数据*/
extern SqQueue U1_queue,Is_queue,I1_queue;
/*DQ变换参数*/
extern float U1d,U1q,Isd,Isq,I1d,I1q,U1rms_screen,I1rms_screen;
extern float ws,fs,thetas;
extern float sin_thetas,cos_thetas;
/*控制设计*/
extern pid_p PLL,pid_Udc,pid_I1d,pid_I1q;
extern float ref_Udc,ref_I1d,ref_Isqrms,ref_I1q;
/*占空比调制比等参数*/
extern float UId,UIq; //电流环后面*Udc的东西哦
extern float DdR,DqR,DalphaR,DbetaR,D1R,D2R;//占空比的dq轴值
extern float DdI,DqI,DalphaI,DbetaI,D3I,D4I;//占空比的dq轴值
/*LCR电路参数*/
extern float Xs;
/*Tim1 时钟*/
extern int time_Tim1;
/*PLL成功flag*/
extern int flag_PLL;
extern int flag_Start_Running;
extern int flag_Protect;
extern int flag_screen;
extern int ad5_avg_flag;
/*屏幕显示参数*/
extern float ref_Isqrms,U1rms_screen,I1rms_screen,PF_set;
extern int 		flag_fresh_screen;
//CC、CR、CP
extern float I1rms_set,Rin_set,Power_set,Spower_set;
extern int Mode;
extern int choose_inductance_capacity;

#endif /* INC_EVA_EXTERN_PAREMETERS_H_ */
