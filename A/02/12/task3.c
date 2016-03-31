#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 50
#define MAX_HOPS 50

int *hop(int *);
int is_in_bound(int *, int, int *);

int main()
{
    int arr[MAX_LEN], *p, hops, flag, num, lim=0;

    num=0;
    while(scanf("%d", &arr[num]) != EOF) num++;

    flag=0;
    p=arr;
    hops=0;
    while(*p!=0 && hops<MAX_HOPS && lim<1)
    {
        p=hop(p);
        lim=is_in_bound(arr,num,p);
        hops++;
    }

    if(*p==0 && lim!=1)
    {
        flag=1;
    }
    printf("%d\n%d",flag,hops);
    return 0;
}

int *hop(int *elem)
{
    elem=elem+*elem;
    return elem;
}

int is_in_bound(int *arr, int size, int *ptr)
{
    if(ptr>=arr && ptr<=(arr+size))
    {
        return 0;
    }
    else return 1;
}
