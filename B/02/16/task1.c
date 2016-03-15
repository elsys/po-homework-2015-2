#include<stdio.h>

void minmax(int *, int , int *, int *);

int main()
{
int num[500];
int *min;
int *max;
int i, len;

min = &num[0];
max = &num[0];

scanf("%d", &len);

	for(i = 0; i < len; i++)
	{
		scanf("%d", &num[i]);
	}
	
minmax(num, len, min, max);

return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{
int i;

	for(i = 0; i < size; i++)
	{
		if(*min > arr[i])		
		{
			min = &arr[i];
		}
		if(*max < arr[i])
		{
			max = &arr[i];
		}
	}
	printf("%d", *max + *min);

}
