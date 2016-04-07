#include <stdio.h>
#include <string.h>

typedef enum { button_clicked = 0, cycle_complete = 1 } command;
typedef enum { CLOSED, OPENING, OPEN, CLOSING, STOPPED_WHILE_CLOSING, STOPPED_WHILE_OPENING } state;

int main() {
	unsigned short commands[1000] = {0}, cmd = 0;
	char word[14] = {0};
	while(scanf("%s", word) != EOF) {
		if(strcmp(word, "button_clicked") == 0) {
			commands[cmd++] = button_clicked;
		}
		else if(strcmp(word, "cycle_complete") == 0) {
			commands[cmd++] = cycle_complete;
		}
	}

	int state = CLOSED;

	for(int i = 0; i < cmd+1; i++) {

		switch(state) {
			case CLOSED:
				printf("Door: CLOSED\n");
				break;
			case OPENING:
				printf("Door: OPENING\n");
				break;
			case OPEN:
				printf("Door: OPEN\n");
				break;
			case CLOSING:
				printf("Door: CLOSING\n");
				break;
			case STOPPED_WHILE_CLOSING:
				printf("Door: STOPPED_WHILE_CLOSING\n");
				break;
			case STOPPED_WHILE_OPENING:
				printf("Door: STOPPED_WHILE_OPENING\n");
				break;
			default:
				printf("UNDEFINED\n");
				break;
		}

		if(commands[i] == button_clicked && state == CLOSED)
			state = OPENING;
        else if(commands[i] == button_clicked && state == OPEN)
			state = CLOSING;
		else if(commands[i] == button_clicked && state == OPENING)
			state = STOPPED_WHILE_OPENING;
		else if(commands[i] == button_clicked && state == CLOSING)
			state = STOPPED_WHILE_CLOSING;
		else if(commands[i] == cycle_complete && state == CLOSING)
			state = CLOSED;
		else if(commands[i] == cycle_complete && state == OPENING)
			state = OPEN;
		else if(commands[i] == button_clicked && state == STOPPED_WHILE_CLOSING)
			state = OPENING;
		else if(commands[i] == button_clicked && state == STOPPED_WHILE_OPENING)
			state = CLOSING;

	}

	return 0;
}
