#include<stdio.h>

void minmax(int *arr, int size, int *min, int *max)
{
int count;

	for(count=1;count<size;count++)
	{
		if(*min > arr[count])
		{
		*min=arr[count];
		}
	if(*max < arr[count])
	{
	*max=arr[count];
	}
	}
}
int main ()
{
	int arr[500];
	int size;
	int max;
	int min;
	int counter=0;
	int sum=0;
		scanf("%d",&size);
	if(size > 0){
	for(;counter<size;counter++)
	{
		scanf("%d",&arr[counter]);
	}
		     }
min=arr[0];
max=arr[0];
	minmax(arr,size,&min,&max);

	sum = min + max;
	printf("%d\n",sum);
return 0;
}
