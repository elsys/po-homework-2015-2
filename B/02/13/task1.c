#include<stdio.h>

void minimax(int *, int, int *, int *);

int main(){

int how_long;
scanf("%d", &how_long);

int arr[how_long];

int counter = 0;
 
 for(; counter < how_long; counter++)
   {
     scanf("%d", &arr[counter]);
   }

minimax(&arr[0], how_long, &arr[0], &arr[1]);


return 0; 
}

void minimax(int *arr, int size, int *min, int *max)
{
  int counter = 1;  
  *max = *min;  

  for(; counter < size; counter++)
    {
        if(arr[counter] < *min)  *min = arr[counter];
        if(arr[counter] > *max) *max = arr[counter];
    }
   
   printf("%d", *min + *max);
 
}
