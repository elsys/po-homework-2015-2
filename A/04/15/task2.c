#include <stdio.h>
#include <string.h>
int main(){
	char command[15], states[6][22]={{"CLOSED"}, {"CLOSING"}, {"STOPPED_WHILE_CLOSING"}, {"OPEN"}, {"OPENING"}, {"STOPPED_WHILE_OPENING"}};
	int curstate=0;
	printf("Door: CLOSED");
	while(scanf("%s", command)!=EOF){
		if(strcmp(command, "button_clicked")==0){
			if(curstate==0){
				curstate=4;
			}
			else if(curstate==1){
				curstate=2;
			}
			else if(curstate==2){
				curstate=4;
			}
			else if(curstate==3){
				curstate=1;
			}
			else if(curstate==4){
				curstate=5;
			}
			else if(curstate==5){
				curstate=1;
			}
			printf("\nDoor: ");
			printf("%s", states[curstate]);
		}
		if(strcmp(command, "cycle_complete")==0){
			if(curstate==1){
				curstate=0;
			}
			else if(curstate==4){
				curstate=3;
			}
			printf("\nDoor: ");
			printf("%s", states[curstate]);
		}
	}
	return 0;
}
