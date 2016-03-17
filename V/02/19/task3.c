#include <stdio.h>

int* hop(int*);
int is_in_bound(int*, int, int*);

int main() {
    int array[100], size = 0;
    for(size = 0; scanf("%d", &array[size]); size++) {}
    int hops = 0;
    int* position = &array[0];
    while(is_in_bound(array, size, position) && hops++ != 50) {
        position = hop(position);
        if(*position == 0) {
            printf("1\n%d", hops);
            break;
        }

    }
    if(*position != 0) {
        if(hops >= 50) {
            hops = 50;
        }
        printf("0\n%d", hops);
    }
    return 0;
}

int* hop(int *elem) {
    int* result = elem + *elem;
    return result;
}

int is_in_bound(int *arr, int size, int *ptr) {
    int i;
    for(i = 0; i < size; i++) {
        if(&arr[i] == ptr) {
            return 1;
        }
    }
    return 0;
}
