#include <stdio.h>
#include <string.h>

#define CLOSED 0
#define OPEN 1

#define OPENING 2
#define CLOSING 4

#define STOPPED_WHILE_OPENING 3
#define STOPPED_WHILE_CLOSING 5

void write_console(int);

int main(){
	char input[10000];
	int state = CLOSED;

	scanf("%[^EOF]s", input);
	printf("\n");

	char *token;
	token = strtok(input, "\n");
	while(token != NULL){
		write_console(state);
		printf("\n");

		if(strcmp(token, "button_clicked") == 0){
			switch (state){
				case CLOSED: state = OPENING; break; 
				case OPEN: state = CLOSING; break;

				case CLOSING: state = STOPPED_WHILE_CLOSING; break;
				case OPENING: state = STOPPED_WHILE_OPENING; break;

				case STOPPED_WHILE_CLOSING: state = OPENING; break;
				case STOPPED_WHILE_OPENING: state = CLOSING; break;
			}
		}
		else{
			if(state == OPENING){
				state = OPEN;
			}
			else if(state == CLOSING){
				state = CLOSED;
			}
		}

		token = strtok(NULL, "\n");
	} 

	write_console(state);

	return 0;
}

void write_console(int state){
	switch(state){
		case OPEN: printf("Door: OPEN"); break;
		case CLOSED: printf("Door: CLOSED"); break;

		case OPENING: printf("Door: OPENING"); break;
		case CLOSING: printf("Door: CLOSING"); break;

		case STOPPED_WHILE_OPENING: printf("Door: STOPPED_WHILE_OPENING"); break;
		case STOPPED_WHILE_CLOSING: printf("Door: STOPPED_WHILE_CLOSING"); break;
	}
}