#include<string.h>
#include<stdio.h>

int main()
{
char command[20];

int prev_command=0;
printf("Door: CLOSED\n");
while(scanf("%s",command) != EOF){


    if(prev_command == 0 && strcmp(command,"button_clicked") == 0 ){printf("Door: OPENING\n"); prev_command=1;  }
    else if(prev_command == 0 && strcmp(command,"cycle_complete") == 0 ){printf("Door: CLOSED\n");  }

    else if(prev_command == 1 && strcmp(command,"button_clicked") == 0 ){printf("Door: STOPPED_WHILE_OPENING\n"); prev_command = 3;}
    else if(prev_command == 1 && strcmp(command,"cycle_complete") == 0 ){printf("Door: OPEN\n"); prev_command = 5;}

    else if(prev_command == 2 && strcmp(command,"button_clicked") == 0 ){printf("Door: STOPPED_WHILE_CLOSING\n"); prev_command = 4;}
    else if(prev_command == 2 && strcmp(command,"cycle_complete") == 0 ){printf("Door: CLOSED\n"); prev_command = 0;}

    else if(prev_command == 3 && strcmp(command,"button_clicked") == 0 ){printf("Door: CLOSING\n"); prev_command = 2;}

    else if(prev_command == 4 && strcmp(command,"button_clicked") == 0 ){printf("Door: OPENING\n"); prev_command = 1;}

    else if(prev_command == 5 && strcmp(command,"button_clicked") == 0 ){printf("Door: CLOSING\n"); prev_command = 2;  }
    else if(prev_command == 5 && strcmp(command,"cycle_complete") == 0 ){printf("Door: OPEN\n");  }

}

    return 0;
}


