#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert_char_to_int( char );
int check_valid_birth_date ( char * );
int check_valid_control_number ( char *  );

int main()
{
    char id[12];
    int valid_id = 0;
    fgets(id, 12, stdin);

    if( strlen(id) - 1 == 10 ) {
        if( check_valid_birth_date( id ) ) {
            if( check_valid_control_number ( id ) ) {
                valid_id = 1;
            }
        }
    }
    printf("%d", valid_id);
    return 0;
}

int check_valid_birth_date ( char * id ) {
    //check valid year
    if( id[0] < '0' || id[0] > '9' ) return 0;
    if( id[1] < '0' || id[1] > '9' ) return 0;

    //check valid month
    if( id[2] < '0' || id[2] > '5') return 0;
    else {
        if( id[2] == '1' || id[3] > '2' ) return 0;
        if( id[2] == '3' || id[3] > '2' ) return 0;
        if( id[2] == '5' || id[3] > '2' ) return 0;
    }

    //check valid date of the month
    if( id[4] < '0' || id[4] > '3' ) return 0;
    if( id[4] == '3' && id[5] > '1' ) return 0;
    if( id[5] < '0' || id[5] > '9' ) return 0;

    //if everything is ok return 1
    return 1;
}

int check_valid_control_number ( char * id ) {
    int sum = 0, reminder;
    sum = sum + (convert_char_to_int( id[0] ) * 2 );
    sum = sum + (convert_char_to_int( id[1] ) * 4 );
    sum = sum + (convert_char_to_int( id[2] ) * 8 );
    sum = sum + (convert_char_to_int( id[3] ) * 5 );
    sum = sum + (convert_char_to_int( id[4] ) * 10);
    sum = sum + (convert_char_to_int( id[5] ) * 9 );
    sum = sum + (convert_char_to_int( id[6] ) * 7 );
    sum = sum + (convert_char_to_int( id[7] ) * 3 );
    sum = sum + (convert_char_to_int( id[8] ) * 6 );
    if( sum % 11 == 10 ) reminder = 0;
    if( sum % 11 < 10  ) reminder = sum % 11;
    if( reminder == convert_char_to_int( id[9] ) ) return 1;
    else return 0;
}

int convert_char_to_int( char to_convert ) {
    return to_convert - 48;
}

