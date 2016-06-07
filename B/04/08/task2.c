#include <stdio.h>
#include <string.h>

/*
button_clicked = 0
cycle_complete = 1
*/

int main() {

	char line[14];
	int commands[500] = {0};
	int i, com_counter = 0;
	char *prev = "CLOSED";

	for(i = 0; scanf("%s", line) != EOF; i++) {
		if(!strcmp(line, "button_clicked")) {
			commands[i] = 2;
			com_counter++;
		}

		else if(!strcmp(line, "cycle_complete")) {
			commands[i] = 1;
			com_counter++;
		}
	}

	printf("Door: CLOSED\n");
	for(i = 0; commands[i] != 0; i++) {
		printf("Door: ");

		if(commands[i] == 0) break;
		else if(commands[i] == 2) {
			if(!strcmp(prev, "CLOSED")) {
				prev = "OPENING";
				printf("%s\n", prev);
			}
			else if(!strcmp(prev, "OPENING")){
				prev = "STOPPED_WHILE_OPENING";
				printf("%s\n", prev);
			}
			else if(!strcmp(prev, "STOPPED_WHILE_OPENING")) {
				prev = "CLOSING";
				printf("%s\n", prev);
			}
			else if(!strcmp(prev, "CLOSING")) {
				prev = "STOPPED_WHILE_CLOSING";
				printf("%s\n", prev);
			}
			else if(!strcmp(prev, "OPEN")) {
				prev = "CLOSING";
				printf("%s\n", prev);
			}
			else if(!strcmp(prev, "STOPPED_WHILE_CLOSING")) {
				prev = "OPENING";
				printf("%s\n", prev);
			}
		}
		else if(commands[i] == 1) {
			if(!strcmp(prev, "CLOSING")) {
				prev = "CLOSED";
				printf("%s\n", prev);
			}
			else if(!strcmp(prev, "OPENING")) {
				prev = "OPEN";
				printf("%s\n", prev);
			}

		}

	}



	return 0;
}