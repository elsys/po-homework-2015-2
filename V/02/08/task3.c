#include <stdio.h>
int is_in_bound(int *arr, int size, int *ptr);
int* hop(int *elem);


int main()
{
	int arr[50]={0};
int size=0;

	for (int i = 0; i < 50 && getchar()!='\n' ; ++i)
	{
		scanf("%d",&arr[i]);
		size =i;
		if(arr[i] == EOF )break;

	}

	int *a=&arr[0];
	
	
	for (int i = 0; i < 50; ++i)
	{
		if(!is_in_bound(arr,size, a))
		{
			printf("%d\n%d\n", 0 ,i+1);
		 return 0;
		}
		
		if (*a==0)
		{
			printf("%d\n%d\n", 1,i+1);
		 return 0;
		}
		
		a=hop(a);
		
		
	}
	
	printf("0\n50" );
	
	return 0;
}

int is_in_bound(int *arr, int size, int *ptr)
{

	if(ptr<=arr+size && ptr>=arr) return 1;
	else return 0;

}


int* hop(int *elem)
{
	return (elem+*elem);
}