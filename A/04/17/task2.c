#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char gate[20];
    int state = 0;//0-CLOSED, 1-OPEN,2-OPENING,3-CLOSING,4-STOPPED_WHILE_OPENING,5-STOPPED_WHILE_CLOSING
    int clicks = 0;

    printf("Door: CLOSED");

     while(scanf("%s",gate) != EOF)
     {
         if(strcmp(gate,"button_clicked") == 0 && (state == 0 || state == 5))
         {
             printf("Door: OPENING");
             state = 2;
             clicks++;
         }
         if(strcmp(gate,"button_clicked") == 0 && state == 2 && clicks == 5)
         {
             state = 4;
             clicks++;
             printf("Door: STOPPED_WHILE_OPENING");
             continue;
         }
         if(strcmp(gate,"cycle_complete") == 0 && state == 2 && clicks == 1)
         {
             printf("Door: OPEN");
             state = 1;
             clicks ++;
         }
         if(strcmp(gate,"cycle_complete") == 0 && state == 3 && clicks == 7)
         {
             printf("Door: CLOSED");
             state = 0;
             clicks++;
         }
        if(strcmp(gate,"button_clicked") == 0 && state == 3 && clicks == 3)
         {
             printf("Door: STOPPED_WHILE_CLOSING");
             state = 5;
             clicks++;
             continue;
         }
        if(strcmp(gate,"button_clicked") == 0 && (state == 1 || state == 4) && clicks == 2)
         {
             printf("Door: CLOSING");
             state = 3;
             clicks++;
         }
         if(strcmp(gate,"button_clicked") == 0 && (state == 4 || state == 1) && clicks == 6)
         {
              printf("Door: CLOSING");
             state = 3;
             clicks++;
         }
         if((state == 5 || state == 0) && clicks == 4 && strcmp(gate,"button_clicked") == 0)
         {
             printf("Door: OPENING");
             state = 2;
             clicks++;
         }
     }
     return 0;
}
