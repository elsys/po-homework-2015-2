#include <stdio.h>
#define MAX 500

void minmax(int *arr, int size, int *min, int *max);

int main(){
	
	int numbers[MAX];
	int n;
	int min;
	int max;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &numbers[i]);
	}
	
	minmax(numbers, n, &min, &max);
	
	printf("%d", min + max);
	
	return 0;
}

void minmax(int *arr, int size, int *min, int *max){
	
	*min = arr[0];
	*max = arr[0];
	for(int i = 0; i < size; i++){
		if(*min < arr[i]){
				*min = arr[i];
		}
		if(*max > arr[i]){
				*max = arr[i];
		}
	}
}
