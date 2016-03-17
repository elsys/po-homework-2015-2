#include <stdio.h>
#define MAX_LENGTH 50

int* hop(int*);
int is_in_bound(int*, int, int*);

int main() {
    
    int arr[MAX_LENGTH], i, length, *ptr, way = 0, hops = 0;
    
    for (i = 0; scanf("%d", &arr[i]) != EOF; i++) {
        if (i == MAX_LENGTH - 1) {
            break;
        }
    }
    
    length = i + 1;
    ptr = arr;

    for (i = 0; is_in_bound(arr, length, ptr) && hops < 50; i += arr[i]) {
        
        hops++;
        
        if (arr[i] == 0) {
            way = 1;
            hops--;
            break;
        }
        
        ptr = hop(&arr[i]);
    }
    
    printf("%d\n%d", way, hops);
    
    return 0;
}

int* hop(int *elem) {
    return elem + *(elem);
}

int is_in_bound(int *arr, int size, int *ptr) {
    
    for (int i = 0; i < size; i++) {
        if (&arr[i] == ptr) {
            return 1;
        }
    }
    
    return 0;
}