#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int state = 1;
	int input_state = 0;
	char* input = malloc(15);
	printf("Door: CLOSED\n");
	while(scanf("%s", input) == 1){
		if(!strcmp(input, "button_clicked")){
			input_state = 0;
		} else if(!strcmp(input, "cycle_complete")){
			input_state = 1;
		} else {
			continue;
		}

		if ((state == 1) && (!input_state)){
			state = 2;
			printf("Door: OPENING\n");
			continue;
		}
		if ((state == 2) && (!input_state)){
			state = 6;
			printf("Door: STOPPED_WHILE_OPENING\n");
			continue;
		}
		if ((state == 3) && (!input_state)){
			state = 4;
			printf("Door: CLOSING\n");
			continue;
		}
		if ((state == 4) && (!input_state)){
			state = 5;
			printf("Door: STOPPED_WHILE_CLOSING\n");
			continue;
		}
		if ((state == 5) && (!input_state)){
			state = 2;
			printf("Door: OPENING\n");
			continue;
		}
		if ((state == 6) && (!input_state)){
			state = 4;
			printf("Door: CLOSING\n");
			continue;
		}

		if ((state == 2) && (input_state)){
			state = 3;
			printf("Door: OPEN\n");
			continue;
		}
		if ((state == 4) && (input_state)){
			state = 1;
			printf("Door: CLOSED\n");
			continue;
		}
	}
	return 0;
}