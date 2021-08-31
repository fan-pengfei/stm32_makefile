#include "led.h"

//LED的IO口初始化程序
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //使能PB,PE端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;             //LED0-->PC.14 LED1-->PC.15 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //IO口速度为50MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure);                //根据设定参数初始化GPIOB.5
}
//点亮LED1
void LED1_ON(void)
{
    GPIO_SetBits(GPIOA, GPIO_Pin_8); //PC14置高电平
}
//熄灭LED1
void LED1_OFF(void)
{
    GPIO_ResetBits(GPIOA, GPIO_Pin_8); //PC14置低电平
}
