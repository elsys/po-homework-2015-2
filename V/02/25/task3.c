#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* hop(int *elem);
int is_in_bound(int *arr, int size, int *ptr);
void PrintResult(int i, int step);

int main(){
	int arr [50];
	int step=1;
	int *p=NULL;
	int i=1;
	int j=0;
	int index=0;
	int tempIndex=0;
	while (scanf("%d", &arr[j])!=EOF){
		j++;
	}
	while (true){
		p=&arr[index];
		if (step==50 || is_in_bound(arr, j, p)==0){
			if (step < 50)
				step--;
			PrintResult(0, step);
			return 0;
		}
		if (*p==0){
			PrintResult(1, step);
			return 0;
		}
		tempIndex=*p;
		p=hop(&arr[index]);
		index=index+tempIndex;
		step++;
	}
	return 0;
}

int* hop(int *elem){
	return (elem + *elem);
}

int is_in_bound(int *arr, int size, int *ptr)
{
	int i=0;
	for (i=0;i<size;i++){
		if (&arr[i]==ptr)
			return 1;
	}
	return 0;
}

void PrintResult(int i, int step){
	printf("%d\n%d",i,step);
}
