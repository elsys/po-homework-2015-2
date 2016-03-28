#include <stdio.h>
#include <stdlib.h>
void minmax(int *arr, int size, int *min, int *max)
{
    *max=arr[0];
    *min=arr[0];
    int counter=0;
    while(counter<size)
	{
		if(*max<arr[counter])
			{
            *max=arr[counter];
            }
        if(*min>arr[counter])
			{
			    *min=arr[counter];
			}
        counter++;
	}
}
int main()
{
    int counter=0,array[500],min,max,elem=0;
    do{
    scanf("%d",&elem);
    }while(elem<0);
   for(;counter<elem;counter++)
    {
        scanf("%d",&array[counter]);

    }

	minmax(array, counter, &min, &max);
	printf("%d",min+max);
    return 0;
}
