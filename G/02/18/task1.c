#include <stdio.h> 

void minmax(int *, int, int *, int *);

int main()
{
	int size, i, min, max;
	int arr[500];
	
    	scanf("%d",&size);

    	for(i = 0; i < size; i++)
    	{
       		scanf("%d",&arr[i]);
    	}
	
	
	min = arr[0];
	max = arr[0];
	
	minmax(arr, size, &min, &max);
	
	printf("%d \n", min + max);
	return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{

	int i;

	for( i = 0; i < size ; i++)
	{
		if(*min > arr[i])
			*min = arr[i];

		if(*max < arr[i])
			*max = arr[i];
	}

}
