#include <stdio.h>
#include <string.h>

int* hop(int *elem);
int is_in_bound(int *arr, int size, int *ptr);

int main()
{
   int arr[50], n = 0, i = 0;
   int *ptr;
   
   while(scanf("%d", &arr[i]) != EOF && i < 50){
        i++;
    }
    ptr = &arr[0];
  do{
  	    if (*ptr == 0){
	        printf("1\n");
	        break;
	    }
    ptr=hop(ptr);
  	n++;
	if (is_in_bound(arr,i,ptr) == 0 || n > 49){
	    printf("0\n");
	    break;
	}
  }while(5);
printf("%d\n",n);

return 0;
}

int *hop(int *elem){
    elem = elem + *elem;
    return(elem);
}
int is_in_bound(int *arr, int size, int *ptr){
	if((ptr - arr < 0) || (ptr - arr > size)){
		return 0;
	}
	 
   return 1;
}
