#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char input[30];
    int doorStatus = 0;
    printf("Door: ");
    printf("CLOSED\n");
    while(scanf("%s", input) != EOF)
    {
        if(strcmp(input, "button_clicked") == 0)
            {
            switch(doorStatus)
            {
                case 0:
                {
                doorStatus = 1;
                printf("Door: ");
                printf("OPENING\n");
                }
                break;

                case 1:
                {
                doorStatus = 5;
                printf("Door: ");
                printf("STOPPED_WHILE_OPENING\n");
                }
                break;

                case 2:
                {
                doorStatus = 3;
                printf("Door: ");
                printf("CLOSING\n");
                }
                break;
                case 3:
                {
                doorStatus = 4;
                printf("Door: ");
                printf("STOPPED_WHILE_CLOSING\n");
                }
                break;

                case 4:
                {
                doorStatus = 1;
                printf("Door: ");
                printf("OPENING\n");
                }
                break;

                case 5:
                {
                doorStatus = 3;
                printf("Door: ");
                printf("CLOSING\n");
                }
            }
        }
        else if(strcmp(input, "cycle_complete") == 0)
        {
        switch(doorStatus)
        {
        case 1:
        {
        doorStatus = 2;
        printf("Door: ");
        printf("OPEN\n");
        }
        break;
        case 3:
        {
        doorStatus = 0;
        printf("Door: ");
        printf("CLOSED\n");
        }
        break;

        }
        }
    }

    return 0;
}
