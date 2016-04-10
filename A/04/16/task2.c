#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[30] = {'\0'};
    int command[20] = {2};
    int state = 0;
    int counter = 0;
    int counter2 = 0;
    while(scanf("%s", input) != EOF)
    {
        if(strcmp(input, "button_clicked")==0)
        {
            command[counter] = 0;
        }
        if(strcmp(input, "cycle_complete")==0)
        {
            command[counter] = 1;
        }
        counter++;
    }
    counter2 = 0;
    while(counter2<=counter)
    {
        switch(state)
        {
            case 0:
                printf("\nDoor: CLOSED");
                break;
            case 1:
                printf("\nDoor: OPENING");
                break;
            case 2:
                printf("\nDoor: OPEN");
                break;
            case 3:
                printf("\nDoor: CLOSING");
                break;
            case 4:
                printf("\nDoor: STOPPED_WHILE_CLOSING");
                break;
            case 5:
                printf("\nDoor: STOPPED_WHILE_OPENING");
                break;
            default:
                return 1;
                break;
        }
        if(command[counter2]==0)
        {
            switch(state)
            {
                case 0:
                    state = 1;
                    break;
                case 1:
                    state = 5;
                    break;
                case 2:
                    state = 3;
                    break;
                case 3:
                    state = 4;
                    break;
                case 4:
                    state = 1;
                    break;
                case 5:
                    state = 3;
                    break;
                default:
                    return 1;
                    break;
            }
        }
        if(command[counter2]==1)
        {
            switch(state)
            {
                case 0:
                    state = 0;
                    break;
                case 1:
                    state = 2;
                    break;
                case 2:
                    state = 2;
                    break;
                case 3:
                    state = 0;
                    break;
                case 4:
                    return 1;
                    break;
                case 5:
                    return 1;
                    break;
                default:
                    return 1;
                    break;
            }
        }
        counter2++;
    }
    return 0;
}
