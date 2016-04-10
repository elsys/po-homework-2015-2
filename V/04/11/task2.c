#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { button_clicked = 0, cycle_complete = 1 } commands;
typedef enum { CLOSED, OPENING, OPEN, CLOSING, STOPPED_WHILE_CLOSING, STOPPED_WHILE_OPENING } sust;

int main(){
    unsigned short cm[1000] = {0}, cmd = 0;
	char duma[14] = {0};
	int i, sust = CLOSED;
	while(scanf("%s", duma) != EOF){
		if(strcmp(duma, "button_clicked") == 0)
			cm[cmd++] = button_clicked;
		else if(strcmp(duma, "cycle_complete") == 0)
			cm[cmd++] = cycle_complete;
	}
	for(i = 0; i < cmd+1; i++){
		switch(sust){
			case CLOSED: printf("Door: CLOSED\n"); break;
			case OPENING: printf("Door: OPENING\n"); break;
			case OPEN: printf("Door: OPEN\n"); break;
			case CLOSING: printf("Door: CLOSING\n"); break;
			case STOPPED_WHILE_CLOSING: printf("Door: STOPPED_WHILE_CLOSING\n"); break;
			case STOPPED_WHILE_OPENING: printf("Door: STOPPED_WHILE_OPENING\n"); break;
			default: printf("UNDEFINED\n"); break;
		}
        if(cm[i] == button_clicked && sust == CLOSED)
            sust = OPENING;
        else if(cm[i] == button_clicked && sust == OPEN)
			sust = CLOSING;
		else if(cm[i] == button_clicked && sust == OPENING)
			sust = STOPPED_WHILE_OPENING;
		else if(cm[i] == button_clicked && sust == CLOSING)
			sust = STOPPED_WHILE_CLOSING;
		else if(cm[i] == cycle_complete && sust == CLOSING)
			sust = CLOSED;
		else if(cm[i] == cycle_complete && sust == OPENING)
			sust = OPEN;
		else if(cm[i] == button_clicked && sust == STOPPED_WHILE_CLOSING)
			sust = OPENING;
		else if(cm[i] == button_clicked && sust == STOPPED_WHILE_OPENING)
			sust = CLOSING;
	}
	return 0;
}
