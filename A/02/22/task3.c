#include <stdio.h>

int* hop(int *);
int is_in_bound(int *, int, int *);

int main()
{
	int arr[50], size, *ptr;
	int hops=0;
	int i=0, temp=0;
	for(i=0; scanf("%d", &temp)!=EOF; i++)
	{
		arr[i]=temp;
	}
	temp=0;
	size=i;
	i=0;
	ptr=&arr[0];
	while(hops!=50)
	{
		temp=0;
		temp=is_in_bound(&arr[0], size, ptr);
		if(*ptr==0 && temp==1)
		{
			temp=1;
			break;
		}
		if(temp==0)
		{
			break;
		}
		if(temp==1)
		{
			hops++;
		}
		temp=0;
		ptr=hop(ptr);
	}
	if(temp==1)
	{
		printf("1\n%d", hops);
	}
	else
	{
		printf("0\n%d", hops);
	}
	return 0;
}

int* hop(int *elem)
{
	return elem + *elem;
}

int is_in_bound(int *arr, int size, int *ptr)
{
	int i=0;
	while(i!=size)
	{
		if (&arr[i]==ptr)
		{
			return 1;
		}
		i++;
	}
	return 0;
}