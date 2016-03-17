#include <stdio.h>

void minmax(int *arr, int size, int *min, int *max);

int main(int argc, const char * argv[]) {
    
    int n;
    int nums[500];
    scanf(" %d", &n);
    
    int i;
    for (i = 0; i < n; i++) {
        scanf(" %d", &nums[i]);
    }
    
    int min, max;
    minmax(nums, n, &min, &max);
    
    printf("%d\n", min + max);
    
    return 0;
}

void minmax(int *arr, int size, int *min, int *max) {
    int minimun = *arr, maximum = *arr;
    
    int i;
    for (i = 1; i < size; i++) {
        if (minimun > arr[i]) {
            minimun = arr[i];
        }
        if (maximum < arr[i]) {
            maximum = arr[i];
        }
    }
    
    *min = minimun;
    *max = maximum;
}
