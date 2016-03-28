#include <stdio.h>
#include <stdlib.h>

void minmax(int *r, int size, int *min, int *max)
{
	*max = -2147483647;
	*min = 2147483647;
    int i;
    for(i=0;i<size;i++)
    {
		if (r[i] > *max)
		{
			*max = r[i];
		}
		if (r[i] < *min)
		{
			*min = r[i];
		}
	}
}
int main()
{
    int r[500];
    int i,n;
    int max,min;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&r[i]);
    }
    minmax(r,n,&min,&max);
    printf("%d",min +  max);
    return 0;
}
