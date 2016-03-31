#include <stdio.h>

int* hop(int *elem);
int is_in_bound(int *arr, int size, int *ptr);

int main()
{
	int arr[50];
	short unsigned int i, size;
	int *pos;
	for(i=0;i<50;i++)
	{
		if(scanf("%d",&arr[i])!=1)
			break;
	}
	size=i;
	pos=arr;
	for(i=0;i<50;i++)
	{
		if(*pos==0 || is_in_bound(arr, size, pos)==0)
			break;
		pos=hop(pos);
	}
	if(is_in_bound(arr, size, pos)==0)
		printf("0");
	else if(i==50)
		printf("0");
	else if(*pos==0)
		printf("1");
	else
		printf("0");
	printf("\n%d",i);
	return 0;
}

int* hop(int *elem)
{
	return elem+*elem;
}

int is_in_bound(int *arr, int size, int *ptr)
{
	if(arr+size>ptr && ptr>=arr)
		return 1;
	else
		return 0;
}
