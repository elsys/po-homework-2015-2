#include <stdio.h>
#include <string.h>

void minimax(int *arr, int size, int *min, int *max);

int main()
{
    int i, num, ar[500], mn, mx;
    char w[2000], sp[2]=" ", *tok;

	scanf("%d",&num);
	getchar();
	fgets(w,2000,stdin);

	i=strlen(w)-1;
	w[i]='\0';
	tok = strtok(w, sp);
	num=0;
	while(tok!=NULL)
	{
	  ar[num++]=atoi(tok);
	  tok = strtok(NULL, sp);
	};
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
