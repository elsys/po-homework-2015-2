#include <stdio.h>
#include <stdlib.h>

void minmax(int *arr, int size, int *min, int *max);

int main()
{
    int n;
    int arr[500];


    int min = 0,max = 15;

    do{

        scanf("%d",&n);

    }while(n < 1);

    minmax(arr, n, &min, &max);

    return 0;
}


void minmax(int *arr, int size, int *min, int *max){

    int i;

    for(i = 0;i < size;i++){
        scanf("%d",&arr[i]);
    }

    *max = 0;
    *min = 0;



    for(i = 0;i < size;i++){

        if(arr[i] > *max){
            *max = arr[i];
        }
        if(arr[i] < *min){
            *min = arr[i];
        }

    }

    printf("%d",*max + *min);

}
