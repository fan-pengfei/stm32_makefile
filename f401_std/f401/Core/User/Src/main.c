#include "stm32f4xx.h"
#include "main.h"
#include "start_task.h"
int cnt = 0;
int main(void)
{
    LED_Init();
    delay_init(84);
    uart_init(115200);
    spi_flash_init();
    test_write();
    USBD_Init(&USB_OTG_dev, USB_OTG_FS_CORE_ID, &USR_desc, &USBD_MSC_cb, &USR_cb);
    create_start_task();  
    vTaskStartScheduler(); 
    while (1)
    {
    }
}
