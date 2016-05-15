#include<stdio.h>

void minmax(int *arr, int size, int *min, int *max) 
{
	 int i = 0; 
   
   for (; i < size; i++)  
   {
      if (arr[i] < *min) 
	     {
			*min = arr[i];
		 }
      if (arr[i] >*max) 
	     {
			*max = arr[i]; 
         }
   }  
}  
int main() 
{
   int arr[500] = {0};
   int i=0, size, min = 0, max = 0;
   int Sum = 0;
   scanf("%d", &size);
   for (; i < size; i++)
   {
	scanf("%d", &arr[i]);
   }  
   max = arr[0];
   min = arr[0];
   minmax(arr ,size ,&min ,&max);
   int sum = min + max;
   printf("%d",sum);  
   
    
   return (0);
}
