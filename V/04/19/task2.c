#include <stdio.h>
#include <string.h>

const int open = 0, opening = 1, stopped_open = 2, stopped_close = 3, closing = 4, closed = 5;

int main() {

    char word[14][1000];
    int time = 0, i;
    int current = closed;

    while(!feof(stdin)) {
        scanf("%s", word[time++]);
    }

    printf("Door: CLOSED\n");

    for(i = 0; i < time-1; i++) {
        if(strcmp(word[i], "button_clicked") == 0) {
            if(current == closed) {
                printf("Door: OPENING\n");
                current = opening;
                continue;
            }
            if(current == open) {
                printf("Door: CLOSING\n");
                current = closing;
                continue;
            }
            if(current == opening) {
                printf("Door: STOPPED_WHILE_OPENING\n");
                current = stopped_open;
                continue;
            }
            if(current == closing) {
                printf("Door: STOPPED_WHILE_CLOSING\n");
                current = stopped_close;
                continue;
            }
            if(current == stopped_open) {
                printf("Door: CLOSING\n");
                current = closing;
                continue;
            }
            if(current == stopped_close) {
                printf("Door: OPENING\n");
                current = opening;
                continue;
            }
        }
        else if(strcmp(word[i], "cycle_complete") == 0){
            if(current == opening) {
                printf("Door: OPEN\n");
                current = open;
            }
            if(current == closing) {
                printf("Door: CLOSED\n");
                current = closed;
            }
        }
    }

    return 0;
}
