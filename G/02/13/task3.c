#include <stdio.h>

int* hop(int *);
int is_in_bound(int *arr, int size, int *ptr);

int main(int argc, const char * argv[]) {
    
    int size = 0;
    int nums[50];

    
    while (scanf("%d", &nums[size]) != EOF) {
        size++;
    }
    
    int *ptr = nums;
    int hops = 0;
    while (1) {
        if (*ptr == 0) {
            printf("1\n");
            break;
        }
        ptr = hop(ptr);
        hops++;
        if (!is_in_bound(nums, size, ptr) || hops >= 50) {
            printf("0\n");
            break;
        }
    }
    
    printf("%d\n", hops);
    
    return 0;
}


int * hop(int *elem) {
    return (elem + *elem);
}

int is_in_bound(int *arr, int size, int *ptr) {
    if ((ptr - arr < 0) || (ptr - arr > size)) {
        return 0;
    }
    return 1;
}
