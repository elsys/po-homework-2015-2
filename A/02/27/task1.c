#include <stdio.h>

void minmax(int*, int, int*, int*);

int main()
{
	int n, min, max;
	int arr[500];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	min = arr[0];
	max = arr[0];
	minmax(arr, n, &min, &max);
	printf("%d", min + max);
	return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{
	for(int i = 0; i < size; i++)
	{
		if(*max < arr[i])
			*max = arr[i];
		if(*min > arr[i])
			*min = arr[i];
	}
}
