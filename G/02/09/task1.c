#include <stdio.h>
void minmax(int *arr, int size, int *min, int *max){
	int i,sum;
	*max = arr[0];
	*min = arr[0];
	for(i = 0; i < size; i++){
		if(arr[i] > *max){
			*max = arr[i];
		}
		if(arr[i] < *min){
			*min = arr[i];
		}
	}

	sum = *min + *max;
	printf("%d\n",sum);

}
int main(){

	int arr[500];
	int size, min, max, sum = 0;
	int i;
	scanf("%d",&size);
	for(i = 0; i < size; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	minmax(arr ,size ,&min ,&max);
	return 0;
}
