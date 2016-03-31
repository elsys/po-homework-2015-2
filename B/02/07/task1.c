#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void minmax(int *arr, int size, int *min, int *max);
int main(){
    int arr[500],size, min, max,i;
    scanf("%d", &size);
    for(i=0;i<size;i++) {
        scanf("%d", &arr[i]);
    }
    minmax(arr, size, &min, &max);
    max = min + max;
    printf("%d", max);
    return 0;
}
void minmax(int *arr, int size, int *min, int *max){
    *min = arr[0];
    *max = arr[0];
    for(;size>0;size--){
        if(*min>arr[size-1]) *min = arr[size-1];
        if(*max<arr[size-1]) *max = arr[size-1];
    }
}
