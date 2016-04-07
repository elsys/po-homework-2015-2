#include<stdio.h>
#include<stdio.h>

int main(){
	int inputs[100] = {0};
	char input_command[20];
	int index = 0, length = 0;;
	
	inputs[0] = 2;
	
	for (index = 1 ; scanf("%s", input_command) != EOF; index++){
		if (!strcmp(input_command , "button_clicked" ))inputs[index] = 1;
		if (!strcmp(input_command , "cycle_complete" ))inputs[index] = 2;
	}
	
	length = index;
	printf("Door: CLOSED\n");
	int oppening = 1;
	for (index = 1 ; index < length ; index++){
		
			if ( inputs[index] == 1 && inputs[index - 1] == 2 && oppening == 1){
				printf("Door: OPENING\n");
			}
			else if ( inputs[index] == 2 && inputs[index - 1] == 1 && oppening == 1){
				printf("Door: OPEN\n");
				oppening = 0;
			}
			else if ( inputs[index] == 1 && inputs[index - 1] == 2 && oppening == 0){
				printf("Door: CLOSING\n");
			}
			
			else if ( inputs[index] == 2 && inputs[index - 1] == 1 && oppening == 0){
				printf("Door: CLOSED\n");
				oppening = 1;
			}
			else if ( inputs[index] == 1 && inputs[index - 1] == 1 && oppening == 0){
				printf("Door: STOPPED_WHILE_CLOSING\n");
				oppening = 1;
				inputs[index] = 3;
			}
			else if ( inputs[index] == 1 && inputs[index - 1] == 1 && oppening == 1){
				printf("Door: STOPPED_WHILE_OPENING\n");
				oppening = 0;
				inputs[index] = 3;
			}
			else if ( inputs[index] == 1 && inputs[index - 1] == 3 && oppening == 1){
				printf("Door: OPENING\n");
			}
			else if ( inputs[index] == 1 && inputs[index - 1] == 3 && oppening == 0){
				printf("Door: CLOSING\n");
			}			
			
	
		
	}
	
	
	return 0;
}
