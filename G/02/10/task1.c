#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()  
{
int c;
void minmax(int arr, int size, int min, int *max){
    for ( c = 1 ; c < size ; c++ ) 
    {
        if ( arr[c] < *min ) 
        {
           *min = arr[c];
           
        }
    } 

  for (c = 1; c < size; c++)
  {
    if (arr[c] > *max)
    {
      *max  = arr[c];
    }
  }

int target;
 target=*max + *min;
printf("%d\n", target);

}



int minimum;
int maximum;
int size;
int arr[500];
scanf("%d",&size);
for(int i=0;i<size;i++){
 scanf("%d",&arr[i]);
}

  minimum = arr[0];
  maximum = arr[0];
 
 
minmax(arr,size,&minimum,&maximum);


    return 0;  
}
