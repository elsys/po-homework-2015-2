#include <stdio.h>
#include <stdlib.h>

int step = 0;
int start_element = 0;
int size = -1;

int* hop(int *elem){
	step += 1;
	int address_value = *elem;
	elem += address_value;
	return elem;
}

int victory_met(int *ptr){
	if (*ptr == 0){
		return 1;
	} else {
		return 0;
	}
}

int is_in_bound(int *arr, int size, int *ptr){
	if (ptr < arr){
		return 0;
	} else if (ptr > arr + size){
		return 0;
	} else {
		return 1;
	}
}

void read_from_stdin(int* arr){
	int counter = 0;
	while(1){
		size += 1;
		int flag = 0;
		char c = getchar();
		if(c == EOF){
			break;
		}
		if (c == '-'){
			flag = 1;
			char m = getchar();
			int hello = atoi(&m);
			arr[counter] = -hello;
			counter += 1;
		}
		char j = getchar();
		if (!flag){
			if (j == EOF){
				break;
			}
		}
		if (!flag){
			arr[counter] = atoi(&c);
			counter+=1;
		}
	}
}

void print_all(int* arr){
	int i;
	for (i = 0; i < size; i++){
		printf("arr[%d] = %d\n",i ,arr[i]);
	}
}

void copy_arrays(int* dummy, int* real){
	int i;
	for (i = 0; i < size; i++){
		real[i] = dummy[i];
	}
}

int main(){
	int* dummy = malloc(50 * sizeof(int));
	int *arr;

	read_from_stdin(dummy);
	arr = malloc(size * sizeof(int));
	copy_arrays(dummy, arr);
	//print_all(arr);
	int* ptr = arr;
	int flag = 0;
	while(1){
		if ( (!is_in_bound(arr, size, ptr)) || (step == 50) ){
			break;
		}
		if (victory_met(ptr)){
			flag = 1;
			break;
		}

		ptr = hop(ptr);
	}

	printf("%d\n", flag);
	printf("%d\n", step);
	return 0;
}
