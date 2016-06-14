#include <stdio.h>
#include <string.h>

#define CLOSED 0
#define OPENING 1
#define OPEN 2
#define CLOSING 3
#define STOPPED_WHILE_CLOSING 4
#define STOPPED_WHILE_OPENING 5

void print(int state);

int main() {

	int j = 1;
	int command[50] = {0};
	char text[14] = {0};

	while(scanf("%s", text) != EOF) {
		if(!strcmp(text, "button_clicked")) {
			command[j++] = 1;
		}
		if(!strcmp(text, "cycle_complete")) {
			command[j++] = 2;
		}
	}


	int state = CLOSED;

	for(int i = 1; i <= j; i++) {


		print(state);

		if(command[i] == 1 && state == CLOSED) {
			state = OPENING;
			continue;
		}
		if(command[i] == 1 && state == OPEN) {
			state = CLOSING;
			continue;
		}
		if(command[i] == 1 && state == STOPPED_WHILE_OPENING) {
			state = CLOSING;
			continue;
		}
		if(command[i] == 1 && state == STOPPED_WHILE_CLOSING) {
			state = OPENING;
			continue;
		}
		if(command[i] == 1 && state == OPENING) {
			state = STOPPED_WHILE_OPENING;
			continue;
		}
		if(command[i] == 1 && state == CLOSING) {
			state = STOPPED_WHILE_CLOSING;
			continue;
		}
		if(command[i] == 2 && state == CLOSING) {
			state = CLOSED;
			continue;
		}
		if(command[i] == 2 && state == OPENING) {
			state = OPEN;
			continue;
		}
	}

}

void print(int state) {
	if(state == CLOSED)
		printf("Door: CLOSED\n");
	if(state == OPEN)
		printf("Door: OPEN\n");
	if(state == OPENING)
		printf("Door: OPENING\n");
	if(state == CLOSING)
		printf("Door: CLOSING\n");
	if(state == STOPPED_WHILE_CLOSING)
		printf("Door: STOPPED_WHILE_CLOSING\n");
	if(state == STOPPED_WHILE_OPENING) 
		printf("Door: STOPPED_WHILE_OPENING\n");
}