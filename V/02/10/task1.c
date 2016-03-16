#include<stdio.h>

void minmax(int *arr, int size, int *min, int *max);

int main()
{
   int size,min,max,sum;
   do{
   	
   	scanf("%d",&size);
   
   }while(size>500 || size<1);
   
   int arr[size];
   int i;
   
   for(i=0;i<size;i++)
   {	
	scanf("%d",&arr[i]);	
	
   }
	
    minmax(arr,size,&min,&max);
    sum=max+min;
    
    printf("%d",sum);
    
return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{
	int j;
	*min=arr[0];
	*max=arr[0];
	
	for(j=0;j<size;j++)
	{
		if(arr[j]>*max)
		{
			*max=arr[j];
		}
		
		if(arr[j]<*min)
		{
			*min=arr[j];
		}
		
	}
}
