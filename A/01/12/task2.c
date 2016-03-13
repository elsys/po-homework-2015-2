#include <stdio.h>
#include <string.h>

long hash(char *);

int main()
{
    struct occurance_t
    {
        long h1;
        int num1;
    }r[3000];

	char w[3000][200];
	int i, j, num, hn, flag, maxnum1;
	char c;
	long h, maxh1;

	for(i=0;i<3000;i++)
	{
		r[i].num1=0;
	}
	i=0;

	do
	{
		j=0;
		do
		{
			c=getchar();
			w[i][j++]=c;
		}while(c!=' ' && j<200 && strcmp(w[i],"vsmisal"));
		i++;
	}while(strcmp(w[i-1],"vsmisal") && i<3000);

	num=i-1;
	hn=0;
	for(i=0;i<num;i++)
	{
		h=hash(w[i]);
		flag=0;

		for(j=0;j<=hn;j++)
		{
			if(h==r[j].h1)
			{
				r[j].num1++;
				flag=1;
			}
		}
			if(flag==0)
			{
				r[hn].h1=h;
				r[hn].num1=1;
				hn++;
			}
	}
	maxnum1=-10;
	for(i=0; i<hn; i++)
    {
		if(r[i].num1>maxnum1)
		{
			maxnum1=r[i].num1;
			maxh1=r[i].h1;
		}
	}
	printf("%d %ld", maxnum1,maxh1);
	return 0;
}

long hash(char *word)
{
    long he;
    int num,i;
    num=strlen(word)-1;
    he=42;
    for(i=0;i<num;i++)
    {
        he=he+word[i]*(i+1);
    }
    return he;
}

