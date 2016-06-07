#include <stdio.h>
#include <string.h>

#define BUTTON_CLICKED_STRING "button_clicked"
#define CYCLE_COMPLETE_STRING "cycle_complete"

typedef enum state {
    CLOSED,
    CLOSING,
    STOPPED_WHILE_CLOSING,
    OPEN,
    OPENING,
    STOPPED_WHILE_OPENING
} state;

void print_state(state);

int main(int argc, const char * argv[]) {
    state door_state = CLOSED;
    int run = 0;

    char input[30][15];

    while (scanf("%15s", input[run++]) != EOF);

    print_state(door_state);

   	for(int i = 0; i < run - 1; i++) {
        if (strcmp(BUTTON_CLICKED_STRING, input[i]) == 0) {
            switch (door_state) {
                case CLOSED:
                    door_state = OPENING;
                    break;
                    
                case CLOSING:
                    door_state = STOPPED_WHILE_CLOSING;
                    break;
                    
                case STOPPED_WHILE_CLOSING:
                    door_state = OPENING;
                    break;
                    
                case OPEN:
                    door_state = CLOSING;
                    break;
                    
                case OPENING:
                    door_state = STOPPED_WHILE_OPENING;
                    break;
                    
                case STOPPED_WHILE_OPENING:
                    door_state = CLOSING;
                    break;
            }
        } else if (strcmp(CYCLE_COMPLETE_STRING, input[i]) == 0) {
            switch (door_state) {
                case OPENING:
                    door_state = OPEN;
                    break;
                case CLOSING:
                    door_state = CLOSED;
                    break;
                default:
                    return 1;
            }
        }
        print_state(door_state);
    }
    
    return 0;
}

void print_state(state st) {
    printf("Door: ");
    switch (st) {
        case CLOSED:
            printf("CLOSED\n");
            break;
        case CLOSING:
            printf("CLOSING\n");
            break;
        case STOPPED_WHILE_CLOSING:
            printf("STOPPED_WHILE_CLOSING\n");
            break;
        case OPEN:
            printf("OPEN\n");
            break;
        case OPENING:
            printf("OPENING\n");
            break;
        case STOPPED_WHILE_OPENING:
            printf("STOPPED_WHILE_OPENING\n");
            break;
            
    }
}
