#include <stdio.h>
#include <string.h>

int* hops(int *);
int is_in_bound(int *, int , int *);
int main()
{
    int arr[49],i,*ptr,l,res=0;

   for(l=0 ;scanf("%d", &arr[l]) != EOF;l++);

        ptr = hops(&arr[0]);
        for(i=1;i<50;i++){
            if(is_in_bound(arr, l, ptr) == 0 && ptr - &arr[0]  > l)
                break;
            else if(arr[ptr - &arr[0]] == 0){
                    res = 1;
                    break;
                    }
            else
                ptr = hops(ptr);

        }



        printf("%d\n%d", res, i);

	return 0;
}
int* hops(int *elem){
    return elem + *elem;

}
int is_in_bound(int *arr, int l, int *ptr){
     if( ptr > arr  )
        return 0;
     else if( ptr < arr + l)
        return 0;
     else return 1;
}

