#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *hop(int *);
int is_in_bound(int *, int, int *);

int main()
{
    int arr[50], i, *p, hops, flag, num, lim;
    char s[2000], *tok, sp[2]=" ";

	fgets(s,2000,stdin);
	i=strlen(s)-1;
	s[i]='\0';

    tok = strtok(s, sp);
    num=0;
    while(tok!=NULL)
    {
	  arr[num++]=atoi(tok);
	  tok = strtok(NULL, sp);
	}

	flag=0;
	p=arr;
	hops=0;
	do
    {
		p=hop(p);
		lim=is_in_bound(arr,num,p);
        hops++;
	}while(*p!=0 && hops<50 && lim<1);

	if(*p==0)
    {
        flag=1;
    }
	printf("%d\n%d",flag,hops);
	return 0;
}

int *hop(int *elem)
{
	elem=elem+*elem;
	return elem;
}

int is_in_bound(int *arr, int size, int *ptr)
{
	if(ptr>=arr && ptr<=(arr+size))
    {
        return 0;
    }
	else return 1;
}
