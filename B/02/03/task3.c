#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMB 50
int * hop(int *);
int is_in_bound(int *, int , int *);
int main()
{
    int arr[MAX_SYMB];
    int i;
    for( i = 0; scanf("%d", &arr[i]) != EOF; i++) {
        if(i==MAX_SYMB) break;
    }
    int lenght = i - 1;
    int inarray = 0, err = 1;
    for ( i = 0; i < MAX_SYMB && err != 0; i++ ) {
        if( is_in_bound( arr, lenght, hop(&arr[inarray])) ) {
            inarray += arr[inarray];
            if(!*hop(&arr[inarray])) {
                err = 0;
                i++;
            }
        } else {
            err = 1;
            i++;
            break;
        }
    }
    if(err == 1)printf("0\n%d", i);
    else printf("1\n%d", i);
    return 0;
}

int * hop(int *elem) {
    return elem + *elem;
}

int is_in_bound(int *arr, int size, int *ptr) {
    if( ptr < arr || ptr > arr + size ) return 0;
    else return 1;
}
