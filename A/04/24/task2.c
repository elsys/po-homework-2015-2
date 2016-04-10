#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//void Memoriser(int , int);

int main()
{
	char command_line[100];
	int door_state = 0, closeoropen = 0;
	printf("Door: CLOSED\n");
	while(scanf("%s",command_line) != EOF)
	{	
		if(!strcmp(command_line,"button_clicked") && door_state == 1 && closeoropen == 0)
		{
			door_state = 0;
			closeoropen = 1;
			printf("Door: STOPPED_WHILE_OPENING\n");
			continue;
		}

		if(!strcmp(command_line,"button_clicked") && door_state == 1 && closeoropen == 1)
		{

			door_state = 0;
			closeoropen = 0;
			
			
			printf("Door: STOPPED_WHILE_CLOSING\n");
			continue;
		}



		if(!strcmp(command_line,"button_clicked") && door_state == 0 && closeoropen == 0 )
		{
			door_state = 1;
			printf("Door: OPENING");
		}

		if(!strcmp(command_line,"cycle_complete") && door_state == 1 && closeoropen == 0)
		{
			door_state = 0;
			closeoropen = 1; //1 = opened 0 = closed
			printf("Door: OPEN");
		}

		if(!strcmp(command_line,"button_clicked") && door_state == 0 && closeoropen == 1)
		{
			door_state = 1;
			printf("Door: CLOSING");
		}

		if(!strcmp(command_line,"cycle_complete") && door_state == 1 && closeoropen == 1)
		{
			door_state = 0;
			closeoropen = 0;
			printf("Door: CLOSED");
		}
		printf("\n");

	};
	
	return 0;
}