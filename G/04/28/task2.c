#include <stdio.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define WRONG_INPUT -1
#define WRONG_LENGTH -1
#define CANNOT_TYPE_CYCLE_COMPLETE -1

#define BUTTON_CLICKED 1
#define CYCLE_COMPLETE 2

int is_correct_length(char *);
int command_input_and_function(char *);
char *door_condition_bc(char *);
char *door_condition_cc(char *);
int check_cycle_complete_function(char *);

int main() {
	char command[20] = {0};
	char condition[21] = "CLOSED";
	
	printf("Door: %s\n",condition);
	while(scanf("%s",command) != EOF) {
		if(is_correct_length(command) == EXIT_SUCCESS) {
			if(command_input_and_function(command) == BUTTON_CLICKED) {
				strcpy(condition ,door_condition_bc(condition));
				printf("Door: %s\n",condition);
			}
			if(command_input_and_function(command) == CYCLE_COMPLETE) {
				if(check_cycle_complete_function(condition) == EXIT_SUCCESS) {
					strcpy(condition ,door_condition_cc(condition));
				}
				printf("Door: %s\n",condition);
			}
		}
	}
	return 0;
}

int is_correct_length(char *command) {
	int command_length = 0;
	
	while(command[command_length] != '\0') {
		command_length ++;
	}
	if(command_length < 14 || command_length > 14) {
		return WRONG_LENGTH;
	}
	return EXIT_SUCCESS;
}

int command_input_and_function(char *command) {
	if(command[0] == 'b' && command[1] == 'u' && command[2] == 't' && command[3] == 't' && command[4] == 'o' &&
	   command[5] == 'n' && command[6] == '_' && command[7] == 'c' && command[8] == 'l' && command[9] == 'i' &&
	   command[10] == 'c' && command[11] == 'k' && command[12] == 'e' && command[13] == 'd') {
		return BUTTON_CLICKED;  
		 	
	}else if(command[0] == 'c' && command[1] == 'y' && command[2] == 'c' && command[3] == 'l' && command[4] == 'e' &&
	         command[5] == '_' && command[6] == 'c' && command[7] == 'o' && command[8] == 'm' && command[9] == 'p' &&
	         command[10] == 'l' && command[11] == 'e' && command[12] == 't' && command[13] == 'e') {
		return CYCLE_COMPLETE;   		 
	}else {
		return WRONG_INPUT; 
	}
}

char *door_condition_bc(char *condition) {
	if(condition[0] == 'C' && condition[1] == 'L' && condition[2] == 'O' && condition[3] == 'S' && condition[4] == 'E' &&
	   condition[5] == 'D') {
	   condition = "OPENING";
	   return condition;	
	   
   }else if(condition[0] == 'O' && condition[1] == 'P' && condition[2] == 'E' && 
            condition[3] == 'N' && condition[4] == 'I' && condition[5] == 'N' && condition[6] == 'G') {  
	        condition = "STOPPED_WHILE_OPENING";
	        return condition;
	        
   }else if(condition[0] == 'S' && condition[1] == 'T' && condition[2] == 'O' && condition[3] == 'P' && 
            condition[4] == 'P' && condition[5] == 'E' && condition[6] == 'D' && condition[7] == '_' && 
            condition[8] == 'W' && condition[9] == 'H' && condition[10] == 'I' && condition[11] == 'L' &&
            condition[12] == 'E' && condition[13] == '_' && condition[14] == 'O' && condition[15] == 'P' && 
            condition[16] == 'E' && condition[17] == 'N' && condition[18] == 'I' && condition[19] == 'N' && 
            condition[20] == 'G') {
            condition = "CLOSING";
            return condition;         
   
   }else if(condition[0] == 'C' && condition[1] == 'L' && condition[2] == 'O' && condition[3] == 'S' && 
            condition[4] == 'I' && condition[5] == 'N' && condition[6] == 'G') {
            condition = "STOPPED_WHILE_CLOSING";
            return condition;
            
   
   }else if(condition[0] == 'S' && condition[1] == 'T' && condition[2] == 'O' && condition[3] == 'P' && 
            condition[4] == 'P' && condition[5] == 'E' && condition[6] == 'D' && condition[7] == '_' && 
            condition[8] == 'W' && condition[9] == 'H' && condition[10] == 'I' && condition[11] == 'L' &&
            condition[12] == 'E' && condition[13] == '_' && condition[14] == 'C' && condition[15] == 'L' && 
            condition[16] == 'O' && condition[17] == 'S' && condition[18] == 'I' && condition[19] == 'N' && 
            condition[20] == 'G'){
    		condition = "OPENING";
    		return condition;        
 
   }else if(condition[0] == 'O' && condition[1] == 'P' && condition[2] == 'E' && condition[3] == 'N') {
       condition = "CLOSING";
       return condition;
   }
	return condition;	
}

char *door_condition_cc(char *condition) {
	if(condition[0] == 'O' && condition[1] == 'P' && condition[2] == 'E' && 
       condition[3] == 'N' && condition[4] == 'I' && condition[5] == 'N' && condition[6] == 'G') {
    	condition = "OPEN";
    	return condition;   
    
    }else if(condition[0] == 'C' && condition[1] == 'L' && condition[2] == 'O' && condition[3] == 'S' && 
             condition[4] == 'I' && condition[5] == 'N' && condition[6] == 'G') {
             condition = "CLOSED";
        return condition;
    }    
    return EXIT_SUCCESS;
}

int check_cycle_complete_function(char *condition) {
	if((condition[0] == 'S' && condition[1] == 'T' && condition[2] == 'O' && condition[3] == 'P' && 
       condition[4] == 'P' && condition[5] == 'E' && condition[6] == 'D' && condition[7] == '_' && 
       condition[8] == 'W' && condition[9] == 'H' && condition[10] == 'I' && condition[11] == 'L' &&
       condition[12] == 'E' && condition[13] == '_' && condition[14] == 'C' && condition[15] == 'L' && 
       condition[16] == 'O' && condition[17] == 'S' && condition[18] == 'I' && condition[19] == 'N' && 
       condition[20] == 'G')
       || 
       (condition[0] == 'S' && condition[1] == 'T' && condition[2] == 'O' && condition[3] == 'P' && 
       condition[4] == 'P' && condition[5] == 'E' && condition[6] == 'D' && condition[7] == '_' && 
       condition[8] == 'W' && condition[9] == 'H' && condition[10] == 'I' && condition[11] == 'L' &&
       condition[12] == 'E' && condition[13] == '_' && condition[14] == 'O' && condition[15] == 'P' && 
       condition[16] == 'E' && condition[17] == 'N' && condition[18] == 'I' && condition[19] == 'N' && 
       condition[20] == 'G')
       ||
       (condition[0] == 'O' && condition[1] == 'P' && condition[2] == 'E' && condition[3] == 'N' && 
        condition[4] == 'E' && condition[5] == 'D')
       ||
       (condition[0] == 'C' && condition[1] == 'L' && condition[2] == 'O' && condition[3] == 'S' && 
        condition[4] == 'E' && condition[5] == 'D')) {
        
     	return CANNOT_TYPE_CYCLE_COMPLETE;
       }
	return EXIT_SUCCESS;
}
