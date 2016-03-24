#include<stdio.h>
#include<stdlib.h>
void minmax(int *arr,int size,int *min,int *max);

int main()
{
	int arr[500];
	int i=0,sum=0;
	int min=0,max=0,size;
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	minmax(arr,size,&min,&max);
	sum=min+max;
	printf("\n%d",sum);
	return 0;
}

void minmax(int *arr,int size,int *min,int *max)
{
	int i=0;
	*min=arr[0];
	*max=arr[0];
	for(i=0;i<size;i++)
	{
		if(arr[i]>*max)
		{
			*max=arr[i];
		}
		if(arr[i]<*min)
		{
			*min=arr[i];
		}
	}
}
