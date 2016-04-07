#include <stdio.h>
#include <string.h>
 
int main(){
 
char command[17];
char status[30];
int condition = 0;
 
// 0=closed
// 1=opening
// 2=stoped_while_opening
// 3=closing
// 4=stoped_while_closing
// 5=opened
printf("Door: CLOSED\n");
while(scanf("%s", command) != EOF){
 
   
    if(!strcmp(command, "button_clicked")){
        if(condition == 0){
            condition = 1;
        }
        else if(condition == 1){
            condition = 2;
        }
        else if(condition == 2){
            condition = 3;
        }
        else if(condition == 3){
            condition = 4;
        }
        else if(condition == 4){
            condition = 1;
        }
        else if(condition == 5){
            condition = 3;
        }
    }
 
    if(!strcmp(command,"cycle_complete")){     
        if(condition == 1){
            condition = 5;
        }
        else if(condition == 3){
            condition = 0;
        }
    }
 
 
    if(condition == 0){
        printf("Door: CLOSED\n");
    }
   
   
    if(condition == 1){
        printf("Door: OPENING\n");
    }
 
   
    if(condition == 2){
        printf("Door: STOPED_WHILE_OPENING\n");
    }
 
   
    if(condition == 3){
        printf("Door: CLOSING\n");
    }
 
   
    if(condition == 4){
        printf("Door: STOPED_WHILE_CLOSING\n");
    }
 
   
    if(condition == 5){
        printf("Door: OPEN\n");
    }
}
 
 
return 0;
}
