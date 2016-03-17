#include <stdio.h>
#include <string.h>

long hash(char *);

int main()
{
struct occurance_t
	{
		long h1;
		int num1;
		char w1[200];
	}r[3000];
	char wr1[200];
	char wr[3000];
	int i, j, k, k1, wn, hind;
	char *tok;
	long wh, wh1, ww;
	const char s[2]=" ";
	char *ch;
	ch="";

	for(i=0;i<3000;i++)
    {
		r[i].num1=0;
		r[i].h1=0;
		strcpy(r[i].w1,ch);
	}
	hind=0;

	fgets(wr,3000,stdin);

	i=strlen(wr)-1;
	wr[i]='\0';

	tok=strtok(wr, s);
	r[hind].num1=1;
	r[hind].h1=hash(tok);
	strcpy(r[hind++].w1,tok);

	while(tok!= NULL )
    {
		tok = strtok(NULL, s);
		if(tok!=NULL )
		{
			r[hind].num1=1;
			r[hind].h1=hash(tok);
			strcpy(r[hind].w1,tok);
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
				strcpy(wr,r[j].w1);
				k=r[j].num1;

				r[j].h1=r[j+1].h1;
				strcpy(r[j].w1,r[j+1].w1);
				r[j].num1=r[j+1].num1;

				r[j+1].h1=ww;
				strcpy(r[j+1].w1,wr);
				r[j+1].num1=k;
			}
        }
    }

	for(i=0; i<hind; i++)
    {
        for(j=i+1; j<hind; j++)
        {
            if (r[j].h1==r[i].h1)
            {
                k1=strcmp(r[i].w1,r[j].w1);
                if (k1==0){
                    r[j].num1=0;
                }
                else{
                    r[i].num1++;
                    r[j].num1++;
                }
            }
        }
    }
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
						strcat(wr,r[j].w1);
					}
					else
					{
						strcat(wr,r[j].w1);
					}
					strcat(wr," ");
					r[j].num1=0;
				}
			}
            if(i!=(hind-1) && i!=0) printf("\n");
			printf("%s",wr);
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
