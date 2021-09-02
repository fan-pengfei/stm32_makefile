#include <stdio.h>
int main(void)
{
    long i, j;
    FILE *cfPtr;
    if ((cfPtr = fopen("data.txt", "w")) == NULL)
    {
        printf("File could not be opened.\n");
    }
    for (i = 0; i < 256  * 256; i++)
    {
        if(i!=256*256-1)
        {
            fprintf(cfPtr, "0x%04X,", i);
        }
        else
        {
            fprintf(cfPtr, "0x%04X", i);
        }
        
        if (((i+1) % 16 == 0) && (i != 0))
        {
            fprintf(cfPtr, "\n");
        }
    }
    fclose(cfPtr);
    printf("OK!\n");
    return 0;
}