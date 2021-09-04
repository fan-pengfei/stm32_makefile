#include "user_lib.h"
#include "ff.h"
#include "diskio.h"
#include "usart.h"
FATFS fs; //文件系统对象
FIL fp;   //文件对象
char *write_text = "FATFS test success!";
unsigned int write_bytes = 0;
char read_buff[512];
unsigned int read_bytes = 0;
BYTE work[FF_MAX_SS];
void spi_flash_init(void)
{
    char res;
    res = f_mount(&fs, "0:", 1);
    if (res == FR_NO_FILESYSTEM)
    {
        printf("FR_NO_FILESYSTEM！\r\n");
        res = f_mkfs("", 0, work, sizeof work);
        if (res == FR_OK)
        {
            printf("Success!\r\n");
            //格式化后先取消挂载
            res = f_mount(NULL, "0:", 1);
            //再重新挂载
            res = f_mount(&fs, "0:", 1);
            if (res != FR_OK)
            {
                printf("Success!\r\n");
            }
        }
        else
        {
            printf("Fail,Res：%d\r\n", res);
            while (1)
                ;
        }
    }
    else if (res != FR_OK)
    {
        printf("Fail！Res：%d\r\n", res);
    }
    else
    {
        printf("Success!\r\n");
    }
}
char text_flash[]="Hello,xiaofei!\n";
void test_write(void)
{
    FIL fil;
    UINT bw;
    FRESULT res = 0;

    res = f_open(&fil, "0:/test.txt", FA_OPEN_APPEND | FA_WRITE);
    if (res == 0)
    {
        res = f_write(&fil, text_flash, sizeof(text_flash), &bw);
        f_close(&fil);
    }
}