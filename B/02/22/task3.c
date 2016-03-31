#include <stdio.h>
#include <string.h>
int* hop(int *elem);
int is_in_bound(int *arr, int size, int *ptr);
int main () {
int arr[50];
int i = 0;
int *helper;
int size;
int helper1 = 0; 
	
	for(i = 0; scanf("%d", arr[i]) != EOF; i++){}

for (helper = 0 ; helper1 < i ; ){
	helper = hop(&arr[helper - &arr[0]]);
	helper1++;
		if(is_in_bound(arr,i,helper)){
		printf("0\n");
		printf("%d",helper1);
		break;
		}
			if(arr[helper - &arr[0]] == 0){
				printf("1\n");
				printf("%d",helper1);

			}
	if(helper1 > 50){printf("0\n50");}
}





	return 0;
}

int* hop(int *elem){
	return *elem + elem; 

}

int is_in_bound(int *arr, int size, int *ptr){
	while (size > 0){
	if(ptr == arr+size){
	return 0;
	
	}
	size--;
}
	return 1;
}
