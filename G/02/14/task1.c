#include <stdio.h>

void minmax(int *arr, int size, int *min, int *max){
     int c;

    *min = arr[0];
    *max = arr[0];

    for (c = 1; c < size; c++) {
        if (arr[c] < *min) *min = arr[c];
        if (arr[c] > *max) *max = arr[c];
  }
}


int main(){
    int c,
        array[500],
        size,
        min,
        max;

    scanf("%d", &size);
    if(size > 500) return -1;

    for (c = 0; c < size; c++) scanf("%d", &array[c]);

    minmax(array, size , &min, &max);

    printf("%d" , min + max);

    return 0;
}
