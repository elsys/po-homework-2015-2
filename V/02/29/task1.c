#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minmax(int *arr, int size, int* min, int* max){
	*min = *arr;
	*max = *arr;
	int i=0;
	for (i = 1; i < size; i++){
		if (arr[i] > *max){
			*max = arr[i];
		}
		if (arr[i] < *min){
			*min = arr[i];
		}
	}
}

int main(){
	char* data = malloc(3);
	scanf("%s", data);
	int size_of_array = atoi(data);
	free(data);

	if (size_of_array > 500){
		return 2;
	}

	int array[size_of_array];
	char* all_data = malloc(1000);
	
	scanf("%*c%[^\n]s", all_data);


	char* token;
	int counter = 0;
	int test = 0;
	int test2 = 0;
	int* min = &test;
	int* max = &test2;
	

	//while((token = strtok_r(all_data, " ", &all_data))){
	//	array[counter] = atoi(token);
	//	counter++;
	//}

	minmax(array, size_of_array, min, max);

	printf("%d", *max + *min);

	free(all_data);
	free(all_data);

	return 0;
}
