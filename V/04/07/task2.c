#include <stdio.h>
#include <string.h>

#define CLOSED 1
#define OPEN 2
#define CLOSING 3
#define OPENING 4
#define STOPPED_WHILE_CLOSING 5
#define STOPPED_WHILE_OPENING 6

int main()
{
	unsigned char door_state=1, i=1, l;
	char input[15], output[100];
	output[0]=CLOSED;
	while(!feof(stdin))
	{
		scanf("%s", input);
		if(strcmp(input, "button_clicked")==0)
			switch(door_state)
			{
				case CLOSED: door_state=OPENING; break;
				case OPEN: door_state=CLOSING; break;
				case CLOSING: door_state=STOPPED_WHILE_CLOSING; break;
				case OPENING: door_state=STOPPED_WHILE_OPENING; break;
				case STOPPED_WHILE_CLOSING: door_state=OPENING; break;
				case STOPPED_WHILE_OPENING: door_state=CLOSING; break;
			}
		else if(strcmp(input, "cycle_complete")==0)
			switch(door_state)
			{
				case CLOSING: door_state=CLOSED; break;
				case OPENING: door_state=OPEN; break;
				default: continue;
			}
		else
			continue;
		output[i]=door_state;
		i++;
	}
	l=strlen(output);
	for(i=0; i<l-1; i++)
	{
		printf("Door: ");
		switch(output[i])
		{
			case CLOSED: printf("CLOSED\n"); break;
			case OPEN: printf("OPEN\n"); break;
			case CLOSING: printf("CLOSING\n"); break;
			case OPENING: printf("OPENING\n"); break;
			case STOPPED_WHILE_CLOSING: printf("STOPPED_WHILE_CLOSING\n"); break;
			case STOPPED_WHILE_OPENING: printf("STOPPED_WHILE_OPENING\n"); break;
		}
	}
	return 0;
}