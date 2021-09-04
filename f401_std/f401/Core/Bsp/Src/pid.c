#include "pid.h"

void abs_limit(float *a, float ABS_MAX)
{
    if (*a > ABS_MAX)
        *a = ABS_MAX;
    if (*a < -ABS_MAX)
        *a = -ABS_MAX;
}

void PID_Init(PID *pid, float kp, float ki, float kd)
{
    pid->Kp = kp;
    pid->Ki = ki;
    pid->Kd = kd;

    pid->Sv = 0.0;
    pid->Pv = 0.0;
    pid->pout = 0.0;
    pid->iout = 0.0;
    pid->dout = 0.0;
    pid->err = 0.0;
    pid->err_last = 0.0;

    pid->OUT = 0.0;
}

void PID_Calc(PID *pid, float Sv_t, float Pv_t, float iout_limit, float pidout_limit, float err_limit)
{
    pid->Sv = Sv_t;
    pid->Pv = Pv_t;
    pid->err = pid->Sv - pid->Pv;
    abs_limit(&pid->err, err_limit);
    pid->total_err += pid->err;
    pid->pout = pid->Kp * pid->err;
    pid->iout += pid->Ki * pid->err;
    pid->dout = pid->Kd * (pid->err - pid->err_last);
    abs_limit(&pid->iout, iout_limit);
    pid->OUT = pid->pout + pid->iout + pid->dout;
    pid->err_last = pid->err;
    abs_limit(&pid->OUT, pidout_limit);
}
