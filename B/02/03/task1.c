#include <stdio.h>
#include <stdlib.h>


void minmax(int *, int , int *, int *);

int main()
{
    int arr[500];
    int size = 0, min = 0, max = 0, entered = 0;
    int i;
    for ( i = 0; i < 500; i++ ) arr[i] = 0;
    do {
        scanf("%d", &size);
    } while ( size < 1 || size > 500 );
    do {
        if(scanf("%d", &arr[ entered ])) entered++;
    } while ( entered < size );
    minmax(arr, size, &min, &max);
    printf("%d", min+max );

    return 0;
}

void minmax(int *arr, int size, int *min, int *max) {
    int i;
    for ( i = 0; i < size; i++ ) {
        if( arr[i] < *min ) *min = arr[i];
        if( arr[i] > *max ) *max = arr[i];
    }
}
