#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input[20];
    int commands[1000] = {0};
    int i = 0;
    int temp = 0;    
    
    for (i = 1; scanf(" %s", input) != EOF; i++) {
                
        if (!strcmp(input, "button_clicked") && commands[i - 1] == 0) {
            commands[i] = 1;
        }
        
        else if (!strcmp(input, "button_clicked") && commands[i - 1] == 2) {
            commands[i] = 3;
        } 
        
        else if (!strcmp(input, "button_clicked") && commands[i - 1] == 1) {
            commands[i] = 5;
        }     
        
        else if (!strcmp(input, "button_clicked") && commands[i - 1] == 5) {
            commands[i] = 3;
        }
        
        else if (!strcmp(input, "button_clicked") && commands[i - 1] == 3) {
            commands[i] = 4;   
        }
        
        else if (!strcmp(input, "button_clicked") && commands[i - 1] == 4) {
            commands[i] = 1;   
        }
        
        else if (!strcmp(input, "cycle_complete") && commands[i - 1] == 1) {
            commands[i] = 2;   
        }
        
        else if (!strcmp(input, "cycle_complete") && commands[i - 1] == 3) {
            continue; 
        }
              
    }
   
    temp = i;
    
    for (i = 0; i < temp; i++) {

        printf("Door: ");
        
        switch(commands[i]) {
        
            case 0:
                printf("CLOSED\n");
                break;
                
            case 1:
                printf("OPENING\n");
                break;
            
            case 2:
                printf("OPEN\n");
                break;
           
            case 3:
                printf("CLOSING\n");
                break;
            
            case 4:
                printf("STOPPED_WHILE_CLOSING\n");
                break;
            
            case 5:
                printf("STOPPED_WHILE_OPENING\n");
                break;
        }
    }

    return 0;    
}
