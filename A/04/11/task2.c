#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int j = 0;

	char commands[20];

	while(scanf("%s", commands) != EOF)
	{
		if(j == 0) printf("Door: CLOSED\n");
		
		if((strcmp(commands, "button_clicked") == 0) && (j == 0 || j == 5))
		{
			printf("Door: OPENING\n");
			j = 1;
		} 
		else if((strcmp(commands, "cycle_complete") == 0) && (j == 0 || j == 3)) continue;
		else if((strcmp(commands, "button_clicked") == 0) && (j == 1))
		{
			printf("Door: STOPPED_WHILE_OPENING\n");
			j = 2;
		}
		else if((strcmp(commands, "cycle_complete") == 0) && (j == 1))
		{
			printf("Door: OPEN\n");
			j = 3;
		}
		else if((strcmp(commands, "button_clicked") == 0) && (j == 2 || j == 3))
		{
			printf("Door: CLOSING\n");
			j = 4;
		}
		else if((strcmp(commands, "cycle_complete") == 0) && (j == 2 || j == 5)) continue;
		else if((strcmp(commands, "button_clicked") == 0) && (j == 4))
		{
			printf("Door: STOPPED_WHILE_CLOSING\n");
			j = 5;
		}
		else if((strcmp(commands, "cycle_complete") == 0) && (j == 4))
		{
			printf("Door: CLOSED\n");
			j = 0;
		}


	}

	return 0;
}
