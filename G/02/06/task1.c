#include <stdio.h>

void minmax(int *arr, int size, int *min, int *max);

int main()
{
	int counter = 0;
	int size = 0;
	int arr[500];
	int min;
	int max;

	scanf("%d", &size);
	
	for(counter = 0; counter < size; counter++)
	{
		arr[counter] = 0;
	}


	for(counter = 0; counter < size; counter++)
	{
		scanf("%d", &arr[counter]);
	}

	minmax(arr, size, &min, &max);

	return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{
	int help = 1;
	int counter = 0;
	int sum = 0;	
	
	*max = arr[0];
	*min = arr[0];

	for(counter = 0; help < size; counter++)
	{
		if(*max < arr[help])
		{
			*max = arr[help];
		}

		if(*min > arr[help])
		{
			*min = arr[help];
		}

		help++;

	}

	sum = *max + *min;

	if(size == 1)
	{
		sum = sum / 2;
	}

	printf("%d\n", sum);

}
