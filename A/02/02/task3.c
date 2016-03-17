#include <stdio.h>
int* hop(int *e);
int is_in_bound(int *, int , int *);

int main()
{
    int m[50],i,n,*p;
    for(i=0;m[i]!=EOF;i++)
    scanf("%d",&m[i]);
    n=i-8;
    p=m;
    for(i=0;i<50 && is_in_bound(m,n,p)!=0 && *p!=0;++i)
        p=hop(p);
        if(m[i+1]==0)
            printf("1\n%d",i);
        else
            printf("0\n%d",i);
    return 0;
}
int* hop(int *e)
{
    return *e+e;
}
int is_in_bound(int *m, int n, int *p)
{ if(m<=p&&p<m+n)
    return 1;
  else
    return 0;
}
