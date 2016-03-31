#include <stdio.h>

int* hop(int *elem){
    return elem + *elem;
}


int is_in_bound(int *arr, int size, int *ptr){

    return ptr > arr ||  (arr + size - 1) < ptr ? 0 : 1;

}

int main(){
    int size = 50;
    int arr[size];
    int c = 0;
    int hops = 0;
    int path = 1;

	while(scanf("%d",&arr[size]) != EOF || c >=size) ++c;

	int *current = arr;

	while(current != 0 ){
        if(is_in_bound(arr, size, current)){
            if(hops <= 50){
                hop(current);
                hops++;
            }else{
                path = 0;
            }
        } else{
                path = 0;
        }
	}

    printf("%d\n%d", path, hops);
}
