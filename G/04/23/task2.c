
#include <stdio.h>
#include <string.h>

int main()
{
	char command[20];
	int command_history[100] = {0};
	int i = 0;
	while(scanf("%s", command) != EOF)
	{
		if(!i) printf("Door: CLOSED");
		if(!strcmp(command, "button_clicked") && (command_history[i] == 0 || command_history[i] == 5))
		{
			command_history[i+1] = 1;
			printf("\nDoor: OPENING");
		}
		else if(!strcmp(command, "cycle_complete") && command_history[i] == 0) continue;
		else if(!strcmp(command, "button_clicked") && command_history[i] == 1)
		{
			command_history[i+1] = 2;
			printf("\nDoor: STOPPED_WHILE_OPENING");
		}
		else if(!strcmp(command, "cycle_complete") && command_history[i] == 1)
		{
			command_history[i+1] = 3;
			printf("\nDoor: OPEN");
		}
		else if(!strcmp(command, "button_clicked") && (command_history[i] == 2 || command_history[i] == 3))
		{
			command_history[i+1] = 4;
			printf("\nDoor: CLOSING");
		}
		else if(!strcmp(command, "cycle_complete") && (command_history[i] == 2 || command_history[i] == 5)) continue;
		else if(!strcmp(command, "cycle_complete") && command_history[i] == 3) continue;
		else if(!strcmp(command, "button_clicked") && command_history[i] == 4)
		{
			command_history[i+1] = 5;
			printf("\nDoor: STOPPED_WHILE_CLOSING");
		}
		else if(!strcmp(command, "cycle_complete") && command_history[i] == 4)
		{
			command_history[i+1] = 0;
			printf("\nDoor: CLOSED");
		}
		i++;
	}
	return 0;
}
