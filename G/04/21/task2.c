#include <stdio.h>

typedef enum 
{
	CLOSED, 
	CLOSING,
	STOPPED_WHILE_CLOSING,
	OPEN,
	OPENING,
	STOPPED_WHILE_OPENING

} door_state;

typedef enum 
{
	button_clicked,
	cycle_complete

} command_type;

int is_string_equals(char *first, char *second);
command_type parse_command(char *command);

int main()
{
	char input_command[100],c;
	door_state door = CLOSED;
	command_type command;

	printf("Door: CLOSED\n");

	while(scanf("%[^\n]%c", input_command, &c) != EOF)
	{
		command = parse_command(input_command);
		
		if(command == button_clicked)
		{
			switch(door)
			{
				case CLOSED:
					door = OPENING;
					printf("Door: OPENING\n");
					break;
				case OPEN:
					door = CLOSING;
					printf("Door: CLOSING\n");
					break;
				case CLOSING:
					door = STOPPED_WHILE_CLOSING;
					printf("Door: STOPPED_WHILE_CLOSING\n");
					break;
				case OPENING:
					door = STOPPED_WHILE_OPENING;
					printf("Door: STOPPED_WHILE_OPENING\n");
					break;
				case STOPPED_WHILE_OPENING:
					door = CLOSING;
					printf("Door: CLOSING\n");
					break;
				case STOPPED_WHILE_CLOSING:
					door = OPENING;
					printf("Door: OPENING\n");
					break;
			}
		}
		else if(command == cycle_complete)
		{
			if(door == CLOSING)
			{
				door = CLOSED;
				printf("Door: CLOSED\n");
			}
			else if(door == OPENING)
			{
				door = OPEN;
				printf("Door: OPEN\n");
			}
		}
	}

	return 0;
}

int is_string_equals(char *first, char *second)
{
	int counter = 0;

	while(first[counter] != '\0' && second[counter] != '\0')
	{
		if(first[counter] != second[counter])
		{
			return 0;
		}

		counter++;
	}

	if(first[counter] != second[counter])
	{
		return 0;
	}

	return 1;
}

command_type parse_command(char *command)
{
	if(is_string_equals(command,"button_clicked"))
	{
		return button_clicked;
	}
	else if(is_string_equals(command,"cycle_complete"))
	{
		return cycle_complete;
	}

	return -1;
}
