#include <stdio.h>
#include <string.h>

int main(){

    char command[15];
    char routine[101];
    int position = 1;
    int counter = 1;

    routine[0] = 1;

    while(!feof(stdin)){
        scanf("%s", command);
        if(strcmp(command, "button_clicked") == 0){
            switch(position){
                case 1: position = 2; break;
                case 2: position = 6; break;
                case 3: position = 4; break;
                case 4: position = 5; break;
                case 5: position = 2; break;
                case 6: position = 4; break;

            }
        }else if(strcmp(command, "cycle_complete") == 0){
            switch(position){
                case 4: position = 1; break;
                case 2: position = 3; break;

            }
        }
        routine[counter] = position;
        counter++;
    }

    counter = 0;

    for(;counter < (strlen(routine)-1); counter++){
        		switch(routine[counter]){
                       		case 1: printf("Door: CLOSED\n"); break;
                              	case 2: printf("Door: OPENING\n"); break;
                              	case 3: printf("Door: OPEN\n"); break;
                             	case 4: printf("Door: CLOSING\n"); break;
                            	case 5: printf("Door: STOPPED_WHILE_CLOSING\n"); break;
                           	case 6: printf("Door: STOPPED_WHILE_OPENING\n"); break;

                            }
    }

return 0;
}
