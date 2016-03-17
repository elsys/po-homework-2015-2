#include <stdio.h>
#include <string.h>
#define MAXARRSIZE 500


void minmax(int *, int , int *, int *);


int main()
{
	int n, input_arr[MAXARRSIZE], i, summed;
	int min, max;
	scanf("%d", &n);


	for(i = 0; i < n; i++)
	{
		scanf("%d", &input_arr[i]);
	}

	minmax(input_arr, n, &min, &max);

	summed = min + max;

	printf("%d", summed);
	return 0;
}

void minmax(int *array, int size, int *min, int *max)
{
	int i;
	*min = array[0];
	*max = array[0];
	for(i = 0; i < size; i++)
	{

		if(*min > array[i])
			*min = array[i];

		if(*max < array[i])
			*max = array[i];

	}
}