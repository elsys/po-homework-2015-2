#include <stdio.h>
#define MAX 500

void minmax(int*, int, int* , int*);

int main()
{
	int n, count; 
	int arr[MAX];
	int min, max;

	scanf("%d", &n);

	for(count=0; count<n; count++)
	{
		scanf("%d", &arr[count]);
	}

	minmax(arr, n, &min, &max);
	printf("%d", min+max);
}


void minmax(int *arr, int n, int *min, int *max)
{
	*min = arr[0];
	*max = arr[0];

	for(int i=0; i<n; i++)
	{
		if(*min < arr[i])
		{
			*min = arr[i];
		}
		if(*max > arr[i])
		{
			*max = arr[i];
		}
	}
}