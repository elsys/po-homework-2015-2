#include <stdio.h>

void minmax(int*, int, int*, int*);

int main(){

    int max, size, min, i;
    
    int arr[500];
    
    scanf("%d", &size);
    
    for(i = 0; i < size; i++){
    
        scanf("%d", &arr[i]);
        
    }
    
    minmax(arr, size, &min, &max);
    
    printf("%d", min + max);
    
    return 0;
}

void minmax(int *arr, int size, int *min, int *max){

    int i;
    
    *max = arr[0];
    *min = arr[0];
    
    for(i = 1; i < size; i++){
    
        if(arr[i] > *max){
            *max = arr[i];
        }
        if(arr[i] < *min){
            *min = arr[i];
        }
    }
}
