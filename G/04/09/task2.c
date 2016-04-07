#include <stdio.h>

int main(){

char command[17];
char status[30];
int condition = 0;

// 0=closed
// 1=opening
// 2=stoped_while_opening
// 3=closing
// 4=stoped_while_closing
// 5=opening
// 6=opened
printf("\nDoor: CLOSED");
while(scanf("%s", command) != EOF){

	
	if(command == "button_clicked" ){
		condition ++;
	}

	if(command == "cycle_complete"){
		condition = 6; 
	}

	if(command == "cycle_complete" && (condition==2 || condition == 4)){
		return 0;
	}

	if(condition == 0){
		printf("\nDoor: CLOSED");
	}
	
	
	if(condition == 1){
		printf("\nDoor: OPENING");
	}

	
	if(condition == 2){
		printf("\nDoor: STOPED_WHILE_OPENING");
	}

	
	if(condition == 3){
		printf("\nDoor: CLOSING");
	}

	
	if(condition == 4){
		printf("\nDoor: STOPED_WHILE_CLOSING");
	}

	
	if(condition == 5){
		printf("\nDoor: OPENING");
	}

	
	if(condition == 6){
		printf("\nDoor: OPENED");
	}

	if(condition>6){
		condition = 0;
	}
}


return 0;
}
