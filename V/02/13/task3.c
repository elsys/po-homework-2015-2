#include <stdio.h>
int* hop(int *elem);
int is_in_bound(int *arr, int size, int *ptr);

int main()
{
	int i = 0, in[51] = { 0 }, size = 0, *el = 0, a = 0;
	while(1)
	{
		if(scanf("%d",&in[i]) == EOF) break;
		else i++;
	}

	el = in;
	size = i;
	i = 1;

	for(a = 0 ; a < 50 ; a++)
	{
		if(is_in_bound(in, size, el) == 0)
		{
			i = 0;
			printf("0\n");
			break;
		}
		if(*el == 0)
		{
			i = 0;
			printf("1\n");
			break;
		}
		el = hop(el);
	}

	if(i) printf("0\n");
	printf("%d\n", a);
	return 0;
}

int* hop(int *elem)
{
	return elem + *elem;
}

int is_in_bound(int *arr, int size, int *ptr)
{
	if((arr+size) > ptr && ptr >= arr) return 1;
	else return 0;
}