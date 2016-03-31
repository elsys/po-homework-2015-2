#include <stdio.h>
#define MAX 500

void minmax(int*, int, int*, int*);

int main(){
    int arr[MAX], min, max, i, n, sum;

    scanf("%d",&n);

    for(i = 0; i < n; i++){

        scanf("%d", &arr[i]);
    }

    min = max = arr[0];

    minmax(arr, n, &min, &max);

    sum = min + max;

    printf("%d",sum);

    return 0;
}

void minmax(int *arr, int size, int *min, int *max){
    int i;

    for(i = 0; i < size; i++){

        if(arr[i] < *min)
            *min = arr[i];

        if(arr[i]> *max)
            *max = arr[i];
    }
}
