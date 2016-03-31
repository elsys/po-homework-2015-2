#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void minimax(int *arr, int size, int *min, int *max);

int main()
{
    int i, num, ar[500], mn, mx;

    scanf("%d", &num);

    for (i=0; i<num; i++)
    {
        scanf("%d", &ar[i]);
    }

	minimax(ar, num, &mn, &mx);

	printf("%d",mn+mx);
	return 0;
}

void minimax(int *arr, int size, int *min, int *max)
{
    int i, mini, maxi;

	mini=*arr;
	maxi=*arr;

	arr++;
	for(i=1; i<size; i++)
    {
		if(*arr<mini)
		{
            mini=*arr;
		}
		if(*arr>maxi)
        {
            maxi=*arr;
        }
		arr++;
	}
	*min=mini;
	*max=maxi;
}
