#include<stdio.h>
void minmax(int *, int *, int *, int *);
int main(){
	int size;
	scanf("%d", &size);
	int arr[500];
	int count;
	
	for(count=0; count<size; count++){
		scanf("%d", &arr[count]);
	}
	int min = arr[0];
	int max = arr[0];
	for(count =0; count< size; count ++){	
	minmax(&arr[count], &size, &min, &max);}
	printf("%d", max+min);
return 0;
}

void minmax(int *arr, int *size, int *min, int *max){
		if(*arr>*max) *max = *arr;
		if(*arr<*min) *min = *arr;
}
