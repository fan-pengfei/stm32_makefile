#include "led.h"

//LED��IO�ڳ�ʼ������
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //ʹ��PB,PE�˿�ʱ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;             //LED0-->PC.14 LED1-->PC.15 �˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //�������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //IO���ٶ�Ϊ50MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure);                //�����趨������ʼ��GPIOB.5
}
//����LED1
void LED1_ON(void)
{
    GPIO_SetBits(GPIOA, GPIO_Pin_8); //PC14�øߵ�ƽ
}
//Ϩ��LED1
void LED1_OFF(void)
{
    GPIO_ResetBits(GPIOA, GPIO_Pin_8); //PC14�õ͵�ƽ
}
