#include <stdio.h>

void minmax(int *m, int n);
int main()
{
    int n,i,m[1000];

    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&m[i]);

    minmax(m,n);
    return 0;
}
void minmax(int *m, int n)
{
    int i,min=m[0],max=m[0];
     for(i=1;i<n;i++)

    { if(m[i]>max)
        max=m[i];
      if(m[i]<min)
        min=m[i];
    }
     printf("%d",min+max);
}
