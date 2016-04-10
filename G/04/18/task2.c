#include <stdio.h>
#include <string.h>
	
int main()
{
	
	char commands[30];
	int helper = 1, count = 1, k;
	int output[100];
	

	
	output[0] = 1;
	
	while(scanf("%s", commands) != EOF)
	{
    		if(helper == 1 && strcmp(commands,"button_clicked") == 0 )
    		{	 
    			helper = 2;
    			output[count] = helper;  
    		}
	
 			else if(helper == 2 && strcmp(commands,"button_clicked") == 0 )
 		{
 			helper = 6;
 			output[count] = helper; 
 		}
    		else if(helper == 2 && strcmp(commands,"cycle_complete") == 0 )
    		{ 
    			helper = 3;
    			output[count] = helper; 
    		}

    		else if(helper == 4 && strcmp(commands,"button_clicked") == 0 )
    		{ 
    			helper = 5;
    			output[count] = helper; 
    		}
    		else if(helper == 4 && strcmp(commands,"cycle_complete") == 0 )
    		{
    			helper = 1;
    			output[count] = helper;
    		}

    		else if(helper == 6 && strcmp(commands,"button_clicked") == 0 )
    		{
    		 	helper = 4;
    		 	output[count] = helper; 
    		 }

    		else if(helper == 5 && strcmp(commands,"button_clicked") == 0 )
    		{
    			helper = 2;
    			output[count] = helper; 
    		}

    		else if(helper == 3 && strcmp(commands,"button_clicked") == 0 )
    		{
    		 	helper = 4; 
    		 	output[count] = helper;  
    		}
		
		count++;

	}
	
	for(k = 0; k <= count; k++)
	{
		if(output[k] == 1)
		{
			printf("Door: CLOSED\n");
		}
		if(output[k] == 2)
		{
			printf("Door: OPENING\n");
		}
		if(output[k] == 3)
		{
			printf("Door: OPEN\n");
		}
		if(output[k] == 4)
		{
			printf("Door: CLOSING\n");
		}
		if(output[k] == 5)
		{
			printf("Door: STOPPED_WHILE_CLOSING\n");
		}
		if(output[k] == 6)
		{
			printf("Door: STOPPED_WHILE_OPENING\n");
		}
	}
	return 0;
}
