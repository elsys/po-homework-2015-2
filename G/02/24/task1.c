#include <stdio.h>
#define MAX_SIZE 500

void minmax(int *, int , int *, int *);

int main()
{
	int size, counter, min, max = 0;
	int arr[MAX_SIZE];
	
    	scanf("%d", &size);

    	for(counter = 0; counter < size; counter++){
    
       		scanf("%d",&arr[counter]);
       		
    	}
	
	minmax(arr, size, &min, &max);
	
	printf("%d\n", min + max);
	return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{

	int counter = 0;
	
	*min = arr[0];

	do{
	
		if(*min > arr[counter]){
		
			*min = arr[counter];

		}
		if(*max < arr[counter]){
		
			*max = arr[counter];
			
		}
		
	}while(counter++ < size);

}
