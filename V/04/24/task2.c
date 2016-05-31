#include <stdio.h>
#include <string.h>

int main()
{
	char com[20];
	int com_history[100] = {0};
	int i = 0;
	while(scanf("%s", com) != EOF)
	{
		if(!i) printf("Door: CLOSED");
		if(!strcmp(com, "button_clicked") && (com_history[i] == 0 || com_history[i] == 5))
		{
			com_history[i+1] = 1;
			printf("\nDoor: OPENING");
		}
		else if(!strcmp(com, "cycle_complete") && com_history[i] == 0) continue;
		else if(!strcmp(com, "button_clicked") && com_history[i] == 1)
		{
			com_history[i+1] = 2;
			printf("\nDoor: STOPPED_WHILE_OPENING");
		}
		else if(!strcmp(com, "cycle_complete") && com_history[i] == 1)
		{
			com_history[i+1] = 3;
			printf("\nDoor: OPEN");
		}
		else if(!strcmp(com, "button_clicked") && (com_history[i] == 2 || com_history[i] == 3))
		{
			com_history[i+1] = 4;
			printf("\nDoor: CLOSING");
		}
		else if(!strcmp(com, "cycle_complete") && (com_history[i] == 2 || com_history[i] == 5)) continue;
		else if(!strcmp(com, "cycle_complete") && com_history[i] == 3) continue;
		else if(!strcmp(com, "button_clicked") && com_history[i] == 4)
		{
			com_history[i+1] = 5;
			printf("\nDoor: STOPPED_WHILE_CLOSING");
		}
		else if(!strcmp(com, "cycle_complete") && com_history[i] == 4)
		{
			com_history[i+1] = 0;
			printf("\nDoor: CLOSED");
		}
		i++;
	}
	return 0;
}
