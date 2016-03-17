#include <stdio.h>

void minmax( int *arr , int size , int *min, int *max);

  
int main(){
  int arr[500];   
  int n, i, max, min;

     scanf("%d", &n);

    for(i = 0; i < n; i++){

        scanf("%d", &arr[i]);

    }

    minmax(arr,n,&max , &min);

    printf("%d", max + min);

    return 0;
}

void minmax( int *arr , int size , int *min, int *max){
    int i;
    *max = -2000000000;
    *min=20000000;

    for(i = 0; i< size; i++){

        if(arr[i]> *max){

            *max = arr[i];

        }if(arr[i] < *min){

            *min = arr[i];

        }

    }

}
