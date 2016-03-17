#include<stdio.h>

void minmax(int *arr, int size, int *min, int *max);

int main()
{
	int arr[500];
	int size, counter = 0, min, max;
	
	scanf("%d", &size);
	
	min = arr[0];
	max = arr[0];
	
	while(counter < size)
	{
	
		scanf("%d", &arr[counter]);
		counter++;
		
	}
	
	minmax(arr, size, &min, &max);
	
    printf("%d\n", min+max);
    
	return 0;
}

void minmax(int *arr, int size, int *min, int *max){

	int counter = 0;

	while(counter < size){
	
		if (*min > arr[counter]) *min = arr[counter];
    	if (*max < arr[counter]) *max = arr[counter];
		counter++;
		
	}
    
}
