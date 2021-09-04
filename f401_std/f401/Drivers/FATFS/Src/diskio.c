/*-----------------------------------------------------------------------*/
/* Low level disk I/O module SKELETON for FatFs     (C)ChaN, 2019        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "ff.h"     /* Obtains integer types */
#include "diskio.h" /* Declarations of disk functions */
#include "w25qx.h"
/* Definitions of physical drive number for each drive */
#define DEV_FLASH 0 /* Example: Map Ramdisk to physical drive 0 */
#define FLASH_SECTOR_SIZE 512
#define FLASH_BLOCK_SIZE 8
#define FLASH_SECTOR_COUNT 2048 * 8
/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status(
    BYTE pdrv /* Physical drive nmuber to identify the drive */
)
{
    return RES_OK;
}

/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize(
    BYTE pdrv /* Physical drive nmuber to identify the drive */
)
{
    if (pdrv == DEV_FLASH)
    {
        W25QXX_Init();
        return RES_OK;
    }
    return STA_NOINIT;
}

/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read(
    BYTE pdrv,    /* Physical drive nmuber to identify the drive */
    BYTE *buff,   /* Data buffer to store read data */
    LBA_t sector, /* Start sector in LBA */
    UINT count    /* Number of sectors to read */
)
{
    if (pdrv == DEV_FLASH)
    {
        while (count--)
        {
            W25QXX_Read(buff, sector * FLASH_SECTOR_SIZE, FLASH_SECTOR_SIZE);
            sector++;
            buff += FLASH_SECTOR_SIZE;
        }
        return RES_OK;
    }

    return RES_PARERR;
}

/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if FF_FS_READONLY == 0

DRESULT disk_write(
    BYTE pdrv,        /* Physical drive nmuber to identify the drive */
    const BYTE *buff, /* Data to be written */
    LBA_t sector,     /* Start sector in LBA */
    UINT count        /* Number of sectors to write */
)
{
    if (pdrv == DEV_FLASH)
    {
        while (count--)
        {
            W25QXX_Write((u8 *)buff, sector * FLASH_SECTOR_SIZE, FLASH_SECTOR_SIZE);
            sector++;
            buff += FLASH_SECTOR_SIZE;
        }
        return RES_OK;
    }

    return RES_PARERR;
}

#endif

/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl(
    BYTE pdrv, /* Physical drive nmuber (0..) */
    BYTE cmd,  /* Control code */
    void *buff /* Buffer to send/receive control data */
)
{
    if (pdrv == DEV_FLASH)
    {
        switch (cmd)
        {
        case CTRL_SYNC:
            return RES_OK;
        case GET_SECTOR_COUNT:
            *(u32 *)buff = FLASH_SECTOR_COUNT;
            return RES_OK;
        case GET_SECTOR_SIZE:
            *(u16 *)buff = FLASH_SECTOR_SIZE;
            return RES_OK;
        case GET_BLOCK_SIZE:
            *(u16 *)buff = FLASH_BLOCK_SIZE;
            return RES_OK;
        }
    }
    return RES_PARERR;
}
