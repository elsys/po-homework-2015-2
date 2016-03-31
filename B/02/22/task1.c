#include <stdio.h>

void minmax(int *arr, int size, int *min, int *max);
int main(){
	int size ;
	int min = 0;
	int max = 0;

	int arr[500];
	scanf("%d",&size );
	for (int i = 0 ; i < size ; i++){
		scanf("%d",&arr[i]);
}
minmax(arr , size , &min , &max);

	printf("%d", max + min);
	return 0;
}

void minmax(int *arr, int size, int *min, int *max){
	int helper = 0;
	*min = *(arr + helper);
	for (helper = 0 ; helper < size ; helper ++){
		if (*(arr + helper) > *max){
		*max = *(arr + helper);
		}
		if(*(arr + helper) < *min){
		*min = *(arr + helper);
		}	
}

}
