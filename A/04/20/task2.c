#include <stdio.h>
#include <string.h>

int main()
{
	char input[30] = "\0";
	int flag=0;

	printf("Door: CLOSED");


		while(scanf("%s", input)!=EOF)
		{
			if(strcmp(input, "button_clicked")==0)
			{
				switch(flag)
				{
					case 0: printf("Door: OPENING\n"); flag = 1; break;	
					case 1: printf("Door: STOPPED_WHILE_OPENING\n"); flag = 2; break;				
					case 2: printf("Door: CLOSING\n"); flag = 3; break;
					case 3: printf("Door: STOPPED_WHILE_CLOSING\n"); flag = 4; break;		
					case 4: printf("Door: OPENING\n"); flag = 5; break;	
					case 5: printf("Door: CLOSING\n"); flag = 6; break;	
					default: break; 
				}
			}
			
			if(strcmp(input, "cycle_complete")==0)
			{
				switch(flag)
				{
					case 0: printf("Door: CLOSED\n"); flag = 0; break;
					case 3: printf("Door: CLOSED\n"); flag = 0; break;
					case 1: printf("Door: OPEN\n"); flag = 5; break;
					case 5: printf("Door: OPEN\n"); flag = 5; break;
				}
			}
		}
	return 0;
}