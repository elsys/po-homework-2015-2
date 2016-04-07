#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * do_door( int * , int * , int );

int main() {
    char commands[5000];
    scanf("%[^EOF]s", commands);
    printf("Door: CLOSED\n");
    int f =0, door = 0, movement = 0, operation;
    for( ; f < strlen( commands ) ; f++ ) {
        if( commands[f] == 'b' ) operation = 1;
        if( commands[f] == 'c' ) operation = 0;
        printf("Door: %s\n", do_door( &door, &movement, operation ));
        while( commands[f] != '\n' ) f++;
    }
    return 0;
}

char * do_door( int * door, int * movement, int operation ) {
    if( !operation ) {
            if(!*door && *movement ) {
                *door = 1;
                *movement = 0;
                return "OPEN";
            }
            if(*door && *movement ) {
                *door = 0;
                *movement = 0;
                return "CLOSED";
            }
    }
    if( !*door && !*movement && operation ) {
        *movement = 1;
        return "OPENING";
    }
    if( *door && !*movement && operation ) {
        *movement = 1;
        return "CLOSING";
    }
    if( *door && *movement && operation ) {
        *movement = 0;
        *door = 0;
        return "STOPPED_WHILE_CLOSING";
    }
    if( !*door && *movement && operation ) {
        *movement = 0;
        *door = 1;
        return "STOPPED_WHILE_OPENING";
    }
    return "ERROR";
}



