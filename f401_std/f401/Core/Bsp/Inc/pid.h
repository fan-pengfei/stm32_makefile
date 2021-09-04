#ifndef _PID_H
#define _PID_H

typedef struct
{
	float Sv;
	float Pv;

	float Kp;
	float Ki;
	float Kd;

	float err;
	float err_last;
	float total_err;
	float del_err;
	
	float pout;
	float iout;
	float dout;

	float OUT;
}PID;


void abs_limit(float *a,float ABS_MAX);
void PID_Init(PID *pid,float kp,float ki,float kd);
void PID_Calc(PID *pid, float Sv_t,float Pv_t,float iout_limit,float pidout_limit,float err_limit);

float Pid_out_buff(float pid_out);
	
#endif

