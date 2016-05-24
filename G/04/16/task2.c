#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char command[14];

    int door_state = 0;
    int boolean = 0;


    printf("Door: CLOSED\n");

    while(scanf("%s",command) != EOF){

        if(strcmp(command,"button_clicked") == 0){

        if(door_state == 0 && boolean == 0){
            door_state = 1;
            printf("Door: OPENING\n");
            boolean = 1;
        }


        if(door_state == 1 && boolean == 0){
            door_state = 5;
            printf("Door: STOPPED_WHILE_OPENING\n");
            boolean = 1;
        }

        if(door_state == 2 && boolean == 0){
            door_state = 3;
            printf("Door: CLOSING\n");
            boolean = 1;
        }
        if(door_state == 3 && boolean == 0){
            door_state = 4;
            printf("Door: STOPPED_WHILE_CLOSING\n");
            boolean = 1;
        }
        if(door_state == 4 && boolean == 0){
            door_state = 1;
            printf("Door: OPENING\n");
            boolean = 1;
        }
        if(door_state == 5 && boolean == 0){
            door_state = 3;
            printf("Door: CLOSING\n");
            boolean = 1;
        }
        boolean = 0;
    }
        if(strcmp(command,"cycle_complete") == 0){

            if(door_state == 1 && boolean == 0){
                door_state = 2;
                printf("Door: OPEN\n");
                boolean = 1;
            }
            if(door_state == 3 && boolean == 0){
                door_state = 0;
                printf("Door: CLOSED\n");
                boolean = 1;
            }
            boolean = 0;

        }

    }


    return 0;
}
