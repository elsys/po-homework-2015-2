#include <stdio.h>
#include <string.h>

void minmax(int *arr, int *size,int *counter,int *min,int *max);

static int min;
static int max;

int main()
{
    int size,arr[100],counter,min,max;

    scanf("%d",&size);

     scanf("%d",&arr[0]);
     min = arr[0];
     max = arr[0];

    for(counter = 1; counter < size; counter++){
      scanf("%d",&arr[counter]);
      minmax(&arr[counter], &size,&counter,&min,&max);
    }

    return 0;
}

void minmax(int *arr, int *size,int *counter,int *min,int *max){

    if (*min > *arr) *min = *arr;
    if (*max < *arr) *max = *arr;

   if (*counter == *size - 1){ *min += *max;

    printf("%d",*min);
}}
