#include "start_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "delay.h"

#define START_TASK_PRIO 1
#define START_TASK_STK_SIZE 128
TaskHandle_t Start_Task_Handler;

#define LED_TASK_PRIO 2
#define LED_TASK_STK_SIZE 128
TaskHandle_t Led_Task_Handler;

#define TEST_TASK_PRIO 3
#define TEST_TASK_STK_SIZE 128
TaskHandle_t Test_Task_Handler;

extern void led_task(void *pvParameters);
extern void test_task(void *pvParameters);
void create_start_task(void)
{
    xTaskCreate((TaskFunction_t)start_task,
                (char *)"start_task",
                (uint16_t)START_TASK_STK_SIZE,
                (void *)NULL,
                (UBaseType_t)START_TASK_PRIO,
                (TaskHandle_t *)&Start_Task_Handler);
}

void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();

    xTaskCreate((TaskFunction_t)led_task,
                (char *)"led_task",
                (uint16_t)LED_TASK_STK_SIZE,
                (void *)NULL,
                (UBaseType_t)LED_TASK_PRIO,
                (TaskHandle_t *)&Led_Task_Handler);

    xTaskCreate((TaskFunction_t)test_task,
                (char *)"test_task",
                (uint16_t)TEST_TASK_STK_SIZE,
                (void *)NULL,
                (UBaseType_t)TEST_TASK_PRIO,
                (TaskHandle_t *)&Test_Task_Handler);

    vTaskDelete(Start_Task_Handler);
    taskEXIT_CRITICAL();
}
void led_task(void *pvParameters)
{
    while (1)
    {
        printf("Task1 Running!\r\n");
        GPIO_ToggleBits(GPIOC, GPIO_Pin_13);
        vTaskDelay(200);
    }
}
void test_task(void *pvParameters)
{
    while (1)
    {
        printf("Task2 Running!\r\n");
        vTaskDelay(200);
    }
}
