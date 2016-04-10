#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLOSED 0
#define OPENING 1
#define OPEN 2
#define CLOSING 3
#define STOPPED_WHILE_CLOSING 4
#define STOPPED_WHILE_OPENING 5
void printMsg(int);
int main()
{
    char input[30];
    int doorStatus = CLOSED;
    printMsg(doorStatus);

    while(scanf("%s", input) != EOF)
    {
        if(strcmp(input, "button_clicked") == 0)
        {
            switch(doorStatus)
            {
                case CLOSED:
                {
                    doorStatus = OPENING;
                    printMsg(doorStatus);
                }
                break;

                case OPENING:
                {
                    doorStatus = STOPPED_WHILE_OPENING;
                    printMsg(doorStatus);
                }
                break;

                case OPEN:
                {
                    doorStatus = CLOSING;
                    printMsg(doorStatus);
                }
                break;

                case CLOSING:
                {
                    doorStatus = STOPPED_WHILE_CLOSING;
                    printMsg(doorStatus);
                }
                break;

                case STOPPED_WHILE_CLOSING:
                {
                    doorStatus = OPENING;
                    printMsg(doorStatus);
                }
                break;

                case STOPPED_WHILE_OPENING:
                {
                    doorStatus = CLOSING;
                    printMsg(doorStatus);
                }
                break;
            }
        }
        else if(strcmp(input, "cycle_complete") == 0)
        {
            switch(doorStatus)
            {
                case OPENING:
                {
                    doorStatus = OPEN;
                    printMsg(doorStatus);
                }
                break;

                case CLOSING:
                {
                    doorStatus = CLOSED;
                    printMsg(doorStatus);
                }
                break;


            }
        }
    }

    return 0;
}

void printMsg(int status)
{
    printf("Door: ");
    switch(status)
            {
                case CLOSED:
                {
                   printf("CLOSED\n");
                }
                break;

                case OPENING:
                {
                    printf("OPENING\n");
                }
                break;

                case OPEN:
                {
                    printf("OPEN\n");
                }
                break;

                case CLOSING:
                {
                    printf("CLOSING\n");
                }
                break;

                case STOPPED_WHILE_CLOSING:
                {
                    printf("STOPPED_WHILE_CLOSING\n");
                }
                break;

                case STOPPED_WHILE_OPENING:
                {
                   printf("STOPPED_WHILE_OPENING\n");
                }
                break;
            }
}


