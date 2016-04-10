#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0, p = 0;

void commands(char string[]);
char read(char *string);
int main()
{
    char c;
    char string[15];
    printf("Door: CLOSED");
    while(c != EOF)
    {
        c = read(string);
        if(c == '\n')
        {
            commands(string);
        }

    }
    return 0;
}

char read(char *string)
{
    char c;
    int i = 0;
    while(1)
    {
        c = getchar();
        if(c == '\n' || c == EOF) {
            string[i] = '\0';
            return c;
        }
        string[i] = c;
        i++;
    }
}
void commands(char string[])
{


    
    if(strcmp("button_clicked", string) == 0)
    {
        if(count == 0 && p == 0)
        {
            printf("Door: OPENING");
            count = 1;
        }
        else if(count == 1 && p == 0)
        {
            printf("Door: STOPPED_WHILE_OPENING");
            p = 1;
        }
        else if(count == 1 && p == 1)
        {
            printf("Door: CLOSING");
            p = 2;
        }
        else if(count == 1 && p == 2)
        {
            printf("Door: STOPPED_WHILE_CLOSING");
            p = 0;
            count = 0;
        }
        printf("\n");

    }
    else if(strcmp("cycle_complete", string) == 0)
    {
        if(count == 1 && p == 0)
        {
            printf("Door: OPEN");
            p = 1;

        }
        else if(count == 1 && p == 2)
        {
            printf("Door: CLOSED");
            count = 0;
            p = 0;
        }
        printf("\n");
    }
}

