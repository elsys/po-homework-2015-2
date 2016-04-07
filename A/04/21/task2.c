#include <stdio.h>
#include <string.h>
#define MAX 30

int main(){
	
	char input[MAX];
	int state = 0; 
	
	printf("Door: CLOSED\n");
	
	while(scanf("%s", input) != EOF){
		if(strcmp(input, "button_clicked") == 0){
			switch(state){
				case 0: printf("Door: OPENING\n"); state = 1; break;
				case 1: printf("Door: STOPPED_WHILE_OPENING\n"); state = 2; break;
				case 2: printf("Door: CLOSING\n"); state = 3; break;
				case 3: printf("Door: STOPPED_WHILE_CLOSING\n"); state = 4; break;
				case 4: printf("Door: OPENING\n"); state = 1; break;
				case 5: printf("Door: CLOSING\n"); state = 3; break;
			}
		}
		if(strcmp(input, "cycle_complete") == 0){
			switch(state){
				case 0: printf("Door: CLOSED\n"); state = 0; break;
				case 1: printf("Door: OPEN\n"); state = 5; break;
				case 3: printf("Door: CLOSED\n"); state = 0; break;
				case 5: printf("Door: OPEN\n"); state = 5; break;
			}	
		}	
	}
	return 0;
}
