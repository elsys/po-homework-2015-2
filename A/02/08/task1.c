#include <stdio.h>
#include <string.h>

void myMinmax(int* arr, int size, int* min, int* max);
void swap(int* x, int* y);

int main(){
	int i, arrLen, arr[500];
	int minNum = 2147483647, maxNum = -2147483648;

	scanf("%d", &arrLen);
	for(i = 0; i < arrLen; i++){
        scanf("%d", &arr[i]);
	}

	myMinmax(arr, arrLen, &minNum, &maxNum);

	printf("%d", minNum + maxNum);

	return 0;
}

void myMinmax(int* arr, int size, int* min, int* max){
    int i;
    for(i = 0; i < size; i++){
        if(*min > arr[i])
            *min = arr[i];
        if(*max < arr[i])
            *max = arr[i];
    }
}
