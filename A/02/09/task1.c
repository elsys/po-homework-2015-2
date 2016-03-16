#include <stdio.h>
#include <limits.h>

void minmax(int*, int, int*, int*);

int main() {
    
    int i, n, arr[500], min, max;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    minmax(arr, n, &min, &max);
    
    printf("%d", min + max);
    
    return 0;
}


void minmax(int *arr, int size, int *min, int *max) {
    
    *min = INT_MAX;
    *max = INT_MIN;
    
    for (int i = 0; i < size; i++) {
        
        if (arr[i] > *max) {
            *max = arr[i];
        }
        
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}