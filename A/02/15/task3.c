#include <stdio.h>

int* hop(int *elem);
int is_in_bounds(int *arr, int size, int *ptr);

int main(){
	int array[50], temp=0, hops=0, i, size, result=0;
	int* ptr=array;
	
	for(i=0; i<50 && scanf("%d", &temp) != EOF; i++){
		array[i]=temp;
	}
	
	size=i;
	temp=0;
	
	
	for(i=0; i<50; i++){
		if(is_in_bounds(array, size, ptr)==0){
			break;
		}
		if(*ptr==0){
			result=1;
			break;
		}
		ptr=hop(ptr);
		hops++;
	}
	
	printf("%d\n%d", result, hops);
}


int* hop(int *elem){
	return (*elem+elem);
}

int is_in_bounds(int *arr, int size, int *ptr){
	if(ptr>=arr && ptr<arr+size){
		return 1;
	}
	return 0;
}
