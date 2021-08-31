#include "sys.h"
#include "stdio.h"
#include "delay.h"
#include "led.h"
#include "usart.h"
int cycle = 0;

//main函数
int main(void)
{
    //初始化系统代码以及初始化所有外设代码
    //以及一些只需要运行一次的代码
    delay_init(); //delay初始化
    LED_Init();   //LED初始化
    uart_init(115200);
    while (1)
    {
        //用户代码
        //需要反复执行的对优先级不敏感的代码
        LED1_ON(); //点亮LED1
        delay_ms(500);
        LED1_OFF(); //熄灭LED1
        delay_ms(500);
        printf("OK,xiaofei!\r\n");
    }
}
