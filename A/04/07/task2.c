#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char command[20];
    int condition = 0;

    printf("Door: CLOSED");
    scanf("%s", command);

    while(1)
    {
        if(condition == 0)
        {
            if(strcmp(command, "button_clicked") == 0)
            {
                condition = 2;
                printf("\nDoor: OPENING");
                if(scanf("%s", command) == EOF)
                    break;
            }
        }
        if(condition == 1)
        {
            if(strcmp(command, "button_clicked") == 0)
            {
                condition = -2;
                printf("\nDoor: CLOSING");
                if(scanf("%s", command) == EOF)
                    break;
            }
        }
        if(condition == 2)
        {
            if(strcmp(command, "button_clicked") == 0)
            {
                condition = 3;
                printf("\nSTOPPED_WHILE_OPENING");
                if(scanf("%s", command) == EOF)
                    break;
            }
            if(strcmp(command, "cycle_complete") == 0)
            {
                condition = 1;
                printf("\nDoor: OPEN");
                if(scanf("%s", command) == EOF)
                    break;
            }
        }
        if(condition == -2)
        {
            if(strcmp(command, "button_clicked") == 0)
            {
                condition = -3;
                printf("\nDoor: STOPPED_WHILE_CLOSING");
                if(scanf("%s", command) == EOF)
                    break;
            }
            if(strcmp(command, "cycle_complete") == 0)
            {
                condition = 0;
                printf("\nDoor: CLOSED");
                if(scanf("%s", command) == EOF)
                    break;
            }
        }
        if(condition == 3)
        {
            if(strcmp(command, "button_clicked") == 0)
            {
                condition = -2;
                printf("\nDoor: CLOSING");
                if(scanf("%s", command) == EOF)
                    break;
            }
        }
        if(condition == -3)
        {
            if(strcmp(command, "button_clicked") == 0)
            {
                condition = 2;
                printf("\nDoor: OPENING");
                if(scanf("%s", command) == EOF)
                    break;
            }
        }
    }
    return 0;
}
