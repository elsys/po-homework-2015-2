#include <stdio.h>
#include <string.h>

int* hop(int *elem);
int is_in_bound(int *arr, int size, int *ptr);

int main(){
	
	int string[50];
	int *hopp;
	int lenght = 0;
	int check = 0;
	int i = 0;
	
	while(scanf("%d", &string[i]) != EOF && (i < 50)){
		i++;
	}
	lenght = i;
	hopp = string;
	i = 0;
	while(is_in_bound(string, lenght, hopp) && (i < 50)){
		if(*hopp == 0){
			check = 1;
			break;
		} 
		hopp = hop(hopp);
		i++;
	}
	
	printf("%d\n%d", check, i);
	
	return 0;
	
}

int* hop(int *elem){
	
	return (elem + *elem);
	
}

int is_in_bound(int *arr, int size, int *ptr){
	
	if(ptr < size + arr){
		return 1;
	}
	
	return 0;
}
