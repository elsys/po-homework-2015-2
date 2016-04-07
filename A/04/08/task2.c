#include <stdio.h>
#include <string.h>

/*button_clicked
cycle_complete
button_clicked
button_clicked
button_clicked
button_clicked
button_clicked
cycle_complete*/

void PrintState(int state, int stopped);

int main(){
	char state = -2, stopped = 1; //bools
	char command[20];

	PrintState(state, stopped);
	while(scanf("%[^\n]%*c", command) != EOF){
		if(strcmp(command, "button_clicked") == 0){
			if(stopped == 1){
				if(state == -2){
					state = 1;
				}else if(state == -1){
					state = 1;
				}else if(state == 1){
					state = -1;
				}else if(state == 2){
					state = -1;
				}
				stopped = 0;
			}else{
				stopped = 1;
			}
		}else if(strcmp(command, "cycle_complete") == 0){
			if(stopped == 0){
				if(state == 1){
					state = 2;
				}else if(state == -1){
					state = -2;
				}
				stopped = 1;
			}
		}

		printf("\n");
		PrintState(state, stopped);
	}

	return 0;
}

void PrintState(int state, int stopped){
	if(state == -2 && stopped == 1)
		printf("Door: CLOSED");
	if(state == 2 && stopped == 1)
		printf("Door: OPEN");
	if(state == -1 && stopped == 1)
		printf("Door: STOPPED_WHILE_CLOSING");
	if(state == 1 && stopped == 1)
		printf("Door: STOPPED_WHILE_OPENING");
	if(state == -1 && stopped == 0)
		printf("Door: CLOSING");
	if(state == 1 && stopped == 0)
		printf("Door: OPENING");
}