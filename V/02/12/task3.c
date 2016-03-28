#include <stdio.h>


int* hop(int *elem);
int is_in_bound(int *arr,int size, int *ptr);

int main(){
	int step,size;
	int array[50];
	int * step_hop = array;
	for(size = 0; scanf("%d",&array[size]) != EOF;size++);
	for(step = 1; step < 50; step++){
		step_hop = hop(step_hop);
		if(*step_hop == 0){
			printf("1\n%d",step);
			break;
		}
		if(!is_in_bound(array,size, step_hop)){
			printf("0\n%d",step);
			break;
		}
	}
	if(step == 49){
		printf("0\n50");
	}
}

int* hop(int *elem){
	return (*elem + elem);
}

int is_in_bound(int *arr,int size, int *ptr){
	for(int i = 0; i < size;i++){
		if(arr + i == ptr){
			return 1;
		}
	}

	return 0;
}