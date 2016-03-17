#include <stdio.h>

void minmax(int *arr, int size, int *min, int *max);

int main(){
	int n;
	scanf("%d",&n);
	int array[500],min,max;
	for(int i = 0;i < n;i++){
		scanf("%d",&array[i]);
		
	}
	min = array[0];
	max = array[0];
	minmax(array,n,&min,&max);
	printf("%d",min + max);
}

void minmax(int *arr, int size, int *min, int *max){
	for(int i = 0; i < size; i++){
		if(*min > arr[i]){
			*min = arr[i];
		}
		if(*max < arr[i]){
			*max = arr[i];
		}
	}
}
