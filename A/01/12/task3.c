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
	char wr1[200];
	char wr[200];
	int i, j, k, k1, hind, flag, n;
	long wh, wh1, ww;
	char ch2;
	char *ch, ch1;
	ch="";
	ch2=10;

	for(i=0;i<3000;i++)
    {
		r[i].num1=0;
		r[i].h1=0;
		strcpy(r[i].w,ch);
	}
	hind=0;

	scanf("%s",wr1);
	ch1=getchar();

	r[hind].num1=1;
	r[hind].h1=hash(wr1);
	strcpy(r[hind++].w,wr1);
	flag=0;
	while(ch1!=ch2 && flag==0)
    {
    	scanf("%s",wr1);
	    ch1=getchar();

		{
			r[hind].num1=1;
			r[hind].h1=hash(wr1);
			strcpy(r[hind].w,wr1);

            for(i=0; i<=hind; i++)
            {
                r[i].num1=1;
            }
			for(i=0; i<=hind; i++)
            {
				wh=r[i].h1;
				for(j=i+1; j<=hind; j++)
                {
					if(r[j].h1==wh)
                    {
                        k1=strcmp(r[i].w,r[j].w);
                        if (k1!=0)
                        {
                          r[i].num1++;
                          r[j].num1++;
                          if (r[j].num1>3)
                            flag=1;
                        }
                        else{
                          r[j].h1=0;
                        }
					}
				}
			}
			hind++;
		}
   }

	for(i=hind; i>0; i--)
    {
		for(j=0; j<i-1; j++)
        {
			if(r[j].h1>r[j+1].h1)
            {
				ww=r[j].h1;
				strcpy(wr,r[j].w);
				k=r[j].num1;

				r[j].h1=r[j+1].h1;
				strcpy(r[j].w,r[j+1].w);
				r[j].num1=r[j+1].num1;

				r[j+1].h1=ww;
				strcpy(r[j+1].w,wr);
				r[j+1].num1=k;
			}
        }
    }
    n=0;
	for(i=0; i<hind; i++)
    {
		if(r[i].num1>1)
		{
			wh=r[i].h1;
			strcpy(wr,"\0");
			for(j=0; j<hind; j++)
			{
				if(wh==r[j].h1)
				{
					if(strlen(wr)==0)
					{
						wh1=r[j].h1;
                        if(wh1!=0) sprintf(wr1,"%ld ",wh1);
						strcat(wr, wr1);
						strcat(wr,r[j].w);
					}
					else
					{
						strcat(wr,r[j].w);
					}
					strcat(wr," ");
					r[j].num1=0;
				}
			}
            if(i!=(hind-1) && n>0 && n!=1)
            {
                if(wh1!=0) printf("\n");
            }
            if(wh1!=0) printf("%s",wr);
			n++;
		}
	}
	return 0;
}

long hash(char *word)
{
	long he;
	int num,i;
	num=strlen(word);
	he=42;
	for(i=0;i<num;i++)
	{
		he=he+word[i]*(i+1);
	}
	return he;
}
