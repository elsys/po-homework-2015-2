#include <stdio.h>
#include <string.h>

int door_state(char*, int);

/*
state = 0 CLOSED
state = 1 OPENING
state = 2 OPEN
state = 3 CLOSING
state = 4 STOPPED WHILE CLOSING
state = 5 STOPPED WHILE OPENING
state = 6 error
*/

int main(){
    char command[20];
    int state = 0;

    printf("Door: CLOSED\n");

    while((scanf("%s", command)) != EOF){

        state = door_state(command, state);

        if(state == 0)
            printf("Door: CLOSED\n");

        if(state == 1)
            printf("Door: OPENING\n");

        if(state == 2)
            printf("Door: OPEN\n");

        if(state == 3)
            printf("Door: CLOSING\n");

        if(state == 4)
            printf("Door: STOPPED_WHILE_CLOSING\n");

        if(state == 5)
            printf("Door: STOPPED_WHILE_OPENING\n");

        if(state == 6)
            return 0;

        }

return 0;
}

int door_state(char* command, int state){

    int temp;

    if(strcmp(command, "button_clicked") == 0)
        temp = 1;


    else {
        if(strcmp(command, "cycle_complete") == 0)
            temp = 0;

        else
            return 6;
    }

    if(temp)
        switch(state){

            case 0: state = 1; break;
            case 1: state = 5; break;
            case 2: state = 3; break;
            case 5: state = 3; break;
            case 3: state = 4; break;
            case 4: state = 2; break;
            default: state = 6; break;
        }

    else{
        if(state == 4 || state == 5)
            return 6;

        switch(state){

            case 1: state = 2; break;
            case 3: state = 0; break;
            default: state = 6; break;
        }
    }

return state;
}
