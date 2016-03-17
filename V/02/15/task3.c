#include <stdio.h>
#include <stdlib.h>

int* hop(int* elem) {
    return (int*)(elem+*elem);
}

int is_in_bound(int* arr, int size, int* ptr) {
    return ((ptr-arr)/(sizeof(int))) < size;
}

int main() {
    int size = 0;
    int* arr = (int*)malloc(sizeof(int));
    while(scanf("%d", &arr[size]) != EOF) {
        arr = (int*)realloc(arr, sizeof(int)*(++size+1));
    }
    int* ptr = &arr[0], hops = 0;

    while(is_in_bound(arr, size, ptr) && ++hops < 50) {
        if(*ptr == 0) {
            printf("1\n%d", hops-1);
            free(arr);
            return 0;
        }

        ptr = hop(ptr);
    }
    printf("0\n%d", is_in_bound(arr, size, ptr) ? 50 : hops-1);
    free(arr);
    return 0;
}