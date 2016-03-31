#include <stdio.h>
#include <stdlib.h>

int* hop(int* elem){
	return elem + *elem;
}

int is_in_bound(int *arr, int size, int *ptr){
	if ((ptr > arr + size - 1) || (ptr < arr)){
		return 0;
	} else {
		return 1;
	}
}

int main(){
	char* input = malloc(sizeof(char) * 6 * 50);
	int fake[50];
	int i = 0;

	while(scanf("%300s", input) != EOF){
		fake[i] = atoi(input);
		i += 1;
	}
	free(input);

	int real[i];
	int j = 0;
	for (j = 0; j <= i; j++){
		real[j] = fake[j];
	}
	int hops = 0;
	int *ptr = real;
	while((hops <= 50)){
		if(is_in_bound(real, i, ptr)){
			if(*ptr == 0){
				printf("1\n%d",hops);
				return 1;
			}
			ptr = hop(ptr);
			hops += 1;
		} else {
			printf("0\n%d", hops);
			return 2;
		}
	}

	printf("0\n50\n");

	return 0;
}