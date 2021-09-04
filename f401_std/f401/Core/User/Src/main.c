#include "stm32f4xx.h"
#include "led.h"
#include "delay.h"
#include "pid.h"
#include "usart.h"
#include "w25qx.h"
#include "user_lib.h"
#include "string.h"
#include "usbd_msc_core.h"
#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usb_conf.h" 
USB_OTG_CORE_HANDLE USB_OTG_dev;
extern vu8 USB_STATUS_REG;		//USB¡Á???
extern vu8 bDeviceState;		//USB???? ?¨¦??
 
int cnt = 0;
int main(void)
{
    LED_Init(); //³õÊ¼»¯LED¶Ë¿Ú
    delay_init();
    uart_init(115200);
    spi_flash_init();
    test_write();
    USBD_Init(&USB_OTG_dev,USB_OTG_FS_CORE_ID,&USR_desc,&USBD_MSC_cb,&USR_cb);
    
    while (1)
    {
        printf("PK!\r\n");
        cnt++;
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        delay_ms(500);
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        delay_ms(500);
    }
}
