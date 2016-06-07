#include <stdio.h>
#include <string.h>

#define CLOSED 0
#define CLOSING 1
#define STOPPED_WHILE_CLOSING 2

#define OPEN 4
#define OPENING 5
#define STOPPED_WHILE_OPENING 6


int main()
{
    char Command[18];

    char button[] = "button_clicked";

    char cycle[] = "cycle_complete";

    int TemporaryDoorCondition = CLOSED;

    printf("Door: CLOSED\n");
    for ( ;scanf("%s",Command) != EOF; ) {

        if (!strcmp(Command, button) && TemporaryDoorCondition == CLOSED) {
            TemporaryDoorCondition = OPENING;
            printf("Door: OPENING\n");
        }

        else if(!strcmp(Command, button) && TemporaryDoorCondition == OPEN) {
            TemporaryDoorCondition = CLOSING;
            printf("Door: CLOSING\n");
        }

        else if(!strcmp(Command, button) && TemporaryDoorCondition == OPENING) {
            TemporaryDoorCondition = STOPPED_WHILE_OPENING;
            printf("Door: STOPPED_WHILE_OPENING\n");
        }

        else if(!strcmp(Command, button) && TemporaryDoorCondition == STOPPED_WHILE_OPENING) {
            TemporaryDoorCondition = CLOSING;
            printf("Door: CLOSING\n");
        }

        else if(!strcmp(Command, button) && TemporaryDoorCondition == CLOSING) {
            TemporaryDoorCondition = STOPPED_WHILE_CLOSING;
            printf("Door: STOPPED_WHILE_CLOSING\n");
        }

        else if(!strcmp(Command, button) && TemporaryDoorCondition == STOPPED_WHILE_CLOSING) {
            TemporaryDoorCondition = OPENING;
            printf("Door: OPENING\n");
        }

        else if(!strcmp(Command, cycle) && TemporaryDoorCondition == OPENING) {
            TemporaryDoorCondition = OPEN;
            printf("Door: OPEN\n");
        }

        else if(!strcmp(Command, cycle) && TemporaryDoorCondition == CLOSING) {
            TemporaryDoorCondition = CLOSED;
            printf("Door: CLOSED\n");
        }
    }

    return 0;
}
