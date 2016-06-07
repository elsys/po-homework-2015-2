#include <stdio.h>
#include <string.h>

int main()
{
	unsigned char door_state=1, i=1, l;
	char command[15], door_states[100];
	
	door_states[0] = door_state;
	
	while(!feof(stdin))
	{
		scanf("%s", command);
		if(strcmp(command, "button_clicked")==0)
			switch(door_state)
			{
				case 1: door_state = 4; break;
				case 2: door_state = 3; break;
				case 3: door_state = 5; break;
				case 4: door_state = 6; break;
				case 5: door_state = 4; break;
				case 6: door_state = 3; break;
			}
		else if(strcmp(command, "cycle_complete")==0)
			switch(door_state)
			{
				case 3: door_state = 1; break;
				case 4: door_state = 2; break;
				default: continue;
			}
		else
			continue;
		door_states[i] = door_state;
		i++;
	}
	l=strlen(door_states);
	for(i=0; i<l-1; i++)
	{
		
		switch(door_states[i])
		{
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
