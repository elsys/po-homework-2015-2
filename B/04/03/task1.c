#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_valid_isbn ( char *  );
int char_to_int ( char );
int check_sum ( char *  );
int is_publisher ( int );

int main() {
    char isbn[20];
    fgets( isbn, 20, stdin );

    int result = check_valid_isbn(isbn);
    printf("%d",  result );
    if( result == 2 ) printf("Bluebridge");
    if( result == 3 ) printf("Alyson Books");
    if( result == 4 ) printf("FUNimation Productions, Ltd.");
    if( result == 5 ) printf("Pyramid Books");

return 0;
}

int check_valid_isbn ( char * isbn ) {
    int i, beg = 0, pub = 0, to_return = 1, check_s = 0;
    if(strlen(isbn) != 17 ) return 0;
    for( i = 0; isbn[i] != '-' ; i ++ ) {
        beg = beg * 10 + char_to_int( isbn[i] );
    }
    if( beg != 978 && beg != 979 ) return 0;
    for( ++i; isbn[i] != '-'; i++ );
    for( ++i; isbn[i] != '-'; i++ ) {
        pub = pub * 10 + char_to_int( isbn[i] );
    }
    if( is_publisher(pub) > 0) to_return = is_publisher( pub );
    for( ++i; isbn[i] != '-'; i++ );
    if( char_to_int(isbn[++i] ) == check_sum( isbn ) ) check_s = 1;
    if( !check_s ) return 0;
    else {
        return to_return;
    }
}

int char_to_int ( char c ) {
    return c - '0';
}

int check_sum ( char * isbn ) {
    int i, evenodd = 0, sum = 0;
    for( i = 0; i < strlen(isbn) -1 ; i++ ) {
        if( isbn[i] != '-' ) {
            if( evenodd % 2 == 1 ) {
                sum = sum  + ( char_to_int( isbn[i] ) * 3);
            } else {
                sum = sum  + ( char_to_int( isbn[i] ) * 1);
            }
            evenodd++;
        }
    }
    sum = sum % 10;
    sum = 10 - sum;
    return sum;
}

int is_publisher ( int pub ) {
    int blueb = 933346;
    int alyson = 55583;
    int funimation = 4210;
    int pyramid = 1;

    if( pub == blueb ) return 2;
    if( pub == alyson ) return 3;
    if( pub == funimation ) return 4;
    if( pub == pyramid ) return 5;
    return 0;
}

