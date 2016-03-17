#include <stdio.h>

void minMax(int *arr, int size, int *min, int *max){
	int i;
	*min=arr[0];
	*max=arr[0];
	for(i=0; i<size; i++){
		if(arr[i]>*max){
			*max=arr[i];
		}
		if(arr[i]<*min){
			*min=arr[i];
		}
	}
}

int main(){
	int arr[500], n, min, max, i;
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	minMax(arr, n, &min, &max);
	
	printf("%d", min+max);
	
	return 0;
}
