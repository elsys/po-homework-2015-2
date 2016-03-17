#include <stdio.h>

void minmax(int *arr, int size, int *min, int *max) {
    int i;
    *min = *max = arr[0];
    for(i = 0; i < size; ++i) {
        if(arr[i] > *max)
            *max = arr[i];
        if(arr[i] < *min)
            *min = arr[i];
    }
}

int digit(int curr, char n) {
  return (curr * 10) + n - '0';  
}

int main() {
    int min, max, n, i, nums[500], negs[500];
    char c;
    n = i = 0;
    while((c = getchar()) != '\n')
       n = digit(n, c);
    for(i = 0; i < n; ++i)
        nums[i] = negs[i] = 0;
    i = 0;
    while((c = getchar()) != EOF)
        switch(c) {
            case '-':
                negs[i] = 1;
                break;
            case ' ':
                i++;
                break;
            default:
                nums[i] = digit(nums[i], c);              
                break;
        }
    for(i = 0; i < n; ++i)
        if(negs[i])
            nums[i] *= -1;
    minmax(nums, n, &min, &max);
    printf("\n%d\n", min + max);
    return 0;
}
