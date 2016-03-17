#include <stdio.h>

#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647 
#define MAX_ARRAY_LENGHT 500

void minmax(int *arr, int size, int *min, int *max);

int main()
{
	int array[MAX_ARRAY_LENGHT];
	int array_lenght, max_element, min_element;

	scanf("%d",&array_lenght);

	int i;
	for (i = 0; i < array_lenght; ++i)
	{
		scanf("%d",&array[i]);
	}

	minmax(array, array_lenght, &max_element, &min_element);

	printf("%d", max_element + min_element);

	return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{
	int i;
	*max = INT_MIN_VALUE;
	*min = INT_MAX_VALUE;

	for (i = 0; i < size; ++i)
	{
		if(arr[i] > *max)
		{
			*max = arr[i];
		}
		else if(arr[i] < *min)
		{
			*min = arr[i];
		}
	}
}
