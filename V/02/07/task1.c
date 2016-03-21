#include <stdio.h>

void minmax(int *arr, int size, int *min, int *max);

int main()
{
	int n, i, minimum=0, maximum=0;
	do
	{
		scanf("%d",&n);
	}
	while(n<1);
	int array[n];
	for(i=0; i<n; i++)
		scanf("%d",&array[i]);
	minmax(array, n, &minimum, &maximum);
	printf("%d",minimum+maximum);
	return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{
	int j;
	*min=arr[0];
	*max=arr[0];
	for(j=1; j<size; j++)
	{
		if(arr[j]<*min)
			*min=arr[j];
		if(arr[j]>*max)
			*max=arr[j];
	}
}