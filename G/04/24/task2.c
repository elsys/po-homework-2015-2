#include <stdio.h>
#include <string.h>

int main()
{

	//Door states 1 - Closed, 2 - Open, 3 - Closing, 4- Opening, 5 - S_W_C, 6 - S_W_O

	int door_state=1, counter = 1;
	char cmd[15], door_states[100];
	
	door_states[0] = door_state;
	
	while(!feof(stdin)){
	
		scanf("%s", cmd);
		
		if(strcmp(cmd, "button_clicked")==0){
		
			switch(door_state)
			{
			
				case 1: door_state = 4; break;
				case 2: door_state = 3; break;
				case 3: door_state = 5; break;
				case 4: door_state = 6; break;
				case 5: door_state = 4; break;
				case 6: door_state = 3; break;
				
			}
			

		}else if(strcmp(cmd, "cycle_complete")==0){
		
			switch(door_state)
			{
			
				case 3: door_state = 1; break;
				case 4: door_state = 2; break;
				
			}
			
		}
		
		door_states[counter] = door_state;
		counter++;
	}
	
	for(counter=0; counter < strlen(door_states)-1; counter++){
	
		switch(door_states[counter]){
		
			case 1: printf("Door: CLOSED\n"); break;
			case 2: printf("Door: OPEN\n"); break;
			case 3: printf("Door: CLOSING\n"); break;
			case 4: printf("Door: OPENING\n"); break;
			case 5: printf("Door: STOPPED_WHILE_CLOSING\n"); break;
			case 6: printf("Door: STOPPED_WHILE_OPENING\n"); break;
			
		}
	}
	
	return 0;

}
