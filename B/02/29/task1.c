#include<stdio.h>


void minmax(int *arr, int size, int *min, int *max);

int main(){
	int arr[500];
	int size, min, max, index, sum = 0;


	scanf("%d",&size);
	for(index = 0 ; index < size ; index++){
		scanf("%d",&arr[index]);
	}
	min = arr[0];
	max = arr[0];
	for(index = 0 ; index < size ; index++){
		minmax(&arr[index] , size, &min, &max);
	}
	
	sum = min + max;
	printf("%d",sum);
	return 0;
}

void minmax(int *arr, int size, int *min, int *max){

		if(*min > *arr)*min = *arr;
		if(*max < *arr)*max = *arr; 

}
