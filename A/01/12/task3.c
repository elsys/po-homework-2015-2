#include <stdio.h>
#include <string.h>

long hash(char *);

int main()
{
    struct occurance_t
    {
        long h1;
		int num1;
		char w[200];
    }r[3000];

	char wr[200], wr1[20];
	int i, j, k, wn, hind, tst[200];
	char c;
	long wh, wh1, tsth[200], ww;

	for(i=0;i<3000;i++)
	{
		r[i].num1=0;
		r[i].h1=0;
	}

	hind=0;
	do
	{
		j=0;
		do
		{
			c=getch();
			putch(c);
			wr[j++]=c;
		}while(c!=' ' && j<200);

		if(strcmp(wr," "))
        {
			strcpy(r[hind].w,wr);
			r[hind].num1=1;
			ww=hash(wr);
			r[hind].h1=ww;
			tsth[hind]=r[hind].h1;
			hind++;
			wn=0;
			for(i=0; i<hind; i++)
			{
				wh=r[i].h1;
				wn=0;
				for(j=0; j<hind; j++)
				{
					if(r[j].h1==wh)
					{
						wn++;
					}
				}
				for(j=0; j<hind; j++)
				{
					if(r[j].h1==wh)
					{
						r[j].num1=wn;
					}
				}
				tst[i]=wn;

			}
		for(k=0; k<200; k++) wr[k]='\0';
		}
		i=i;
	}while(hind<3000 && wn<4);

	for(i=0; i<hind; i++)
    {
		if(r[i].num1>1)
        {
			wh=r[i].h1;
			wn=r[i].num1;
			strcpy(wr,"\0");
			for(j=0; j<hind; j++)
			{
				if(wh==r[j].h1 && wn==r[j].num1)
				{
					if(strlen(wr)==0)
					{
						wh1=r[j].h1;
						sprintf(wr1,"%ld ",wh1);
						strcat(wr, wr1);
						strcat(wr,r[j].w);
					}
					else
                    {
						strcat(wr,r[j].w);
					}
					r[j].num1=0;
				}
			}
			printf("\n%s",wr);
		}
	}
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

