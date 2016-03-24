#include <stdio.h>

int* hop(int *);
int is_in_bound(int *arr, int size, int *ptr);

int main(){

	int arr[50];
	int size;
	
	for(int i = 0; i < 50; i++){
		
		if(scanf("%d", &arr[i]) == EOF){
			size = i;
			break;
		}
	}
	
	int *i;
	int ok = 1;
	int count = 1;
	
	for(i = &arr[0]; is_in_bound(arr, size, i) != 0 && count <= 50;){	
		
		if(hop(i) > (arr + size))
		{
			count++;
			ok = 1;
			break;
		}
		else if(*hop(i) == 0){
			printf("1\n");
			printf("%d", count);
			ok = 0;
			break;
		}
		
			count++;
			i = hop(i);
	}
	
	if(ok){
		printf("0\n");
		printf("%d", count - 1);
	}
	
}

int* hop(int *elem){
	return elem + *elem;
}

int is_in_bound(int *arr, int size, int *ptr){
	if(ptr >= arr && ptr <= (arr + size))
		return 1;
	else
		return 0; 
}
