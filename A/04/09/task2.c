#include <stdio.h>
#include <string.h>
#define CLOSED 0
#define OPENING 1
#define OPEN 2
#define CLOSING 3
#define STOPPED_WHILE_CLOSING 4
#define STOPPED_WHILE_OPENING 5

void print_state(const int);

int main() {
    int state = CLOSED;
    char command[14];
    
    print_state(state);
    
    while (fgets(command, 15, stdin)) {
        if (strcmp(command, "button_clicked") == 0) {
            switch (state) {
                case CLOSED:
                    state = OPENING;
                    break;
                case OPENING:
                    state = STOPPED_WHILE_OPENING;
                    break;
                case OPEN:
                    state = CLOSING;
                    break;
                case CLOSING:
                    state = STOPPED_WHILE_CLOSING;
                    break;
                case STOPPED_WHILE_CLOSING:
                    state = OPENING;
                    break;
                case STOPPED_WHILE_OPENING:
                    state = CLOSING;
                    break;
            }
            printf("\n");
            print_state(state);
        } else if (strcmp(command, "cycle_complete") == 0) {
            switch (state) {
                case OPENING:
                    state = OPEN;
                    break;
                case CLOSING:
                    state = CLOSED;
                    break;
            }
            printf("\n");
            print_state(state);
        }
    }
    
    return 0;
}

void print_state(const int state) {
    printf("Door: ");
    switch (state) {
        case CLOSED:
            printf("CLOSED");
            return;
        case OPENING:
            printf("OPENING");
            return;
        case OPEN:
            printf("OPEN");
            return;
        case CLOSING:
            printf("CLOSING");
            return;
        case STOPPED_WHILE_CLOSING:
            printf("STOPPED_WHILE_CLOSING");
            return;
        case STOPPED_WHILE_OPENING:
            printf("STOPPED_WHILE_OPENING");
            return;
    }
}
