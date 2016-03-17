#include <stdio.h>

void minmax(int *arr,  int size, int *min, int *max);

int main()
{
	int arr[500];
	int n,min,max,i = 0;
	scanf("%d",&n);
	while(i < n)
	{
		scanf("%d",&arr[i]);
		i++;
	}
	minmax (arr, n, &min, &max);

	printf("%d\n", min + max);
	return 0;
}

void minmax(int *arr,  int size, int *min, int *max)
{
	int k = 0;
	*min = arr[0];
	*max = arr[0];

	while(k < size)
	{
		while(arr[k] > *max)
			*max = arr[k];
		while(arr[k] < *min)
			*min = arr[k];
		k++;
	}
}
