#include <stdio.h>
#include <string.h>

int main(){
	char operator[20];
	char door[30] = "CLOSED";
	while(scanf("%s", operator) != EOF){
		printf("\nDoor: %s",door);
		if(!strcmp(operator,"button_clicked")){
			//printf("SUP\n");
			// printf("AAAAAAAAAAAAAaa%d\n",strcmp("CLOSED",door));
			if(!(strcmp(door,"CLOSED"))){
				// printf("KAKSD\n");
				strcpy(door,"OPENING");
				// printf("DEBUG\n");
				// printf("Doorssss!!!: %s",door );
			}else if(!strcmp(door,"OPEN")){
				strcpy(door,"CLOSING");
			}else if(!strcmp(door,"OPENING")){
				strcpy(door,"STOPPED_WHILE_OPENING");
			}else if(!strcmp(door,"CLOSING")){
				strcpy(door,"STOPPED_WHILE_CLOSING");
			}else if(!strcmp(door,"STOPPED_WHILE_CLOSING")){
				strcpy(door,"OPENING");
			}else if(!strcmp(door,"STOPPED_WHILE_OPENING")){
				strcpy(door,"CLOSING");
			}
		}else if(!strcmp(operator,"cycle_complete")){
			if(!strcmp(door,"CLOSING")){
				strcpy(door,"CLOSED");
			}else if(!strcmp(door,"OPENING")){
				strcpy(door,"OPEN");
			}
		}
	}
	return 0;
}