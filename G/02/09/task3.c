#include <stdio.h>
 
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
 
int main() {
    int arr[100], size = 0, *p = &arr[0], hops = 0;
   
    while(scanf("%d",&arr[size]) != EOF)
    {
        size++;
    }
 
    while(1) {
        p = hop(p);
        hops++;
       
        if(!is_in_bound(arr, size, p))
        {
            printf("0\n%d", hops);
            break;
        }
        else if(*p == 0) {
            printf("1\n%d", hops);
            break;
        }
        else if(hops == 50)
        {
            printf("0\n%d", hops);
            break;
        }
    }
    return 0;
}
