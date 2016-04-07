#include <stdio.h>
#include <string.h>

int main()
{
	char cmds[2][15] = {"button_clicked","cycle_complete"};
	char states[6][22] = {"CLOSED","OPENING","OPEN","CLOSING","STOPPED_WHILE_CLOSING","STOPPED_WHILE_OPENING"};
	char command[15];
	int state = 0;
	printf("Door: %s\n", states[state]);
	
	while(scanf("%15s",command) == 1)
	{
		if( strcmp(command,cmds[0]) == 0 )
		{
			switch(state)
			{
				case 0: { state = 1; break; }
				case 1: { state = 5; break; }
				case 2: { state = 3; break; }
				case 3: { state = 4; break; }
				case 4: { state = 1; break; }
				case 5: { state = 3; break; }
			}
		}
		else if( strcmp(command,cmds[1]) == 0 )
		{
			switch(state)
			{
				case 1: { state = 2; break; }
				case 3: { state = 0; break; }
			}	
		}
		printf("Door: %s\n", states[state]);
	}

	return 0;
}