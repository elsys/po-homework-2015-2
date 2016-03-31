#include <stdio.h>
#include <stdlib.h>

void minmax(int *arr, int size, int *min, int *max);

int main()
{
	int result=0;
	int s=0;
	int size=0;
	int n[500];
	printf("How many numbers?:");
	scanf("%d \n",&size);
	for(s=0;s<size;s++)
	{
		scanf("%d",&n[s]);
	}
	int min=0,max=0;
	minmax(n,size,&min,&max);
	result=min+max;
	printf("%d", result);
	return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{
	int i=0;
	for (i=0;i<size;i++)
	{
		if (*max<arr[i])
		{
			*max=arr[i];
		}
		if (*min>arr[i])
		{
			*min=arr[i];
		}
	}

}
