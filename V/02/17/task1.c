#include <stdio.h>
#include <stdlib.h>

void minmax(int *arr, int *min, int *max, int size);

int main()
{
    int n, min = 0, max = 15, arr[500];
    do{
        scanf("%d", &n);
    }while(n < 1)
    minmax(arr, &min, &max, n);
    return 0;
}

void minmax(int *arr, int *min, int *max, int size)
{
    int i;
    for(i = 0;i < size;i++){
        scanf("%d", &arr[i]);
    }
    *max = 0;
    *min = 0;
    for(i = 0;i < size; i++){
        if(arr[i] > *max){
            *max = arr[i];
        }
        if(arr[i] < *min){
            *min = arr[i];
        }
    }
    printf("%d", *max + *min);
}
