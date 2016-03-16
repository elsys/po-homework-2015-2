#include <stdio.h>

int is_in_bound(int *arr, int size, int *ptr);
int* hops(int *);

int main() {

	int nums[50];
	int size, i, func_result, check, is_found = 0;
	int *ptr;

	for(size = 0; scanf("%d", &nums[size]) != EOF; size++);

	ptr = hops(&nums[0]);

	

	for(i = 0; i < 50; i++) {
		check = ptr - &nums[0];
		func_result = is_in_bound(nums, size, ptr);
		if(func_result == 1 && check < size){
			if(nums[check] == 0){
				is_found = 1;
				break;
			}
			ptr = hops(ptr);
		}
		else{
			break;
		}

	}
	
	if(i == 50) {
		printf("%d\n%d", is_found, i);
	}
	else {
		printf("%d\n%d", is_found, i + 1);
	}

 
	return 0;
}

int* hops (int *elem) {
	return elem + *elem;
}


int is_in_bound(int *arr, int size, int *ptr) {

	if(arr > ptr - 49) {
		return 1;
	}

	return 0;
}