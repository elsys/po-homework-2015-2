#include<stdio.h>
#include<stdlib.h>
int* hop(int *elem);

int is_in_bound(int *arr,int size,int *ptr);

int main()
{
	int arr[50],size;
	int* ptr=arr;
	int i=0,temp=0,hops=0,result=0;
	for(i=0;i<50 && scanf("%d",&temp)!=EOF;i++)
	{
		arr[i]=temp;
	}	
	size=i;
	temp=0;
	for(i=0;i<50;i++)
	{
		if(is_in_bound(arr,size,ptr)==1)
		{
			if(*ptr==0)
			{
				result=1;
				break;
			}
			ptr=hop(ptr);
			hops++;			
		}
		else
		{
			break;
		}
	}
	printf("\n%d\n%d",result,hops);
	return 0;
}

int* hop(int *elem)
{
	return (*elem+elem);
}

int is_in_bound(int *arr,int size,int *ptr)
{
	if(ptr<arr+size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
