#include <stdio.h>
#include <string.h>

long hash (char *word);
struct occurance_t
{
	int xash;
	int occurance;
};
int main ()
{
	int i,k;
	char word [200];
	struct occurance_t DNNOTHENAME[1000];
	struct occurance_t perfetto;

	fgets(word, 200 , stdin);

	for (i=0;i<strlen(word);i++)
		{	
			if(word[i]=='v'&& word[i+1]=='s'&& word[i+2]  =='m' && word[i+3] =='i' && word[i+4] =='s' && word[i+5] =='a' && word[i+6] =='l')
			break;
			DNNOTHENAME[i].xash = hash (word);
			DNNOTHENAME[i].occurance = 0;
		}
	for (i=0;i<strlen(word);i++)
		{for( k=1;k<strlen(word);k++)
			if (DNNOTHENAME[i].xash==DNNOTHENAME[k].xash)
				{
					DNNOTHENAME[i].occurance=+1;
				}
		}
	for (i=0;i<strlen(word);i++)
		{
			if(perfetto.occurance<DNNOTHENAME[i].occurance)
			{
				perfetto.xash=DNNOTHENAME[i].xash;
				perfetto.occurance=DNNOTHENAME[i].occurance;
			}
		}
	printf("%d , %d \n",perfetto.occurance,perfetto.xash );
	return 0;
}
long hash (char *word)
{
	int sum = 42,i , n = 0,temp;
	n = strlen(word) - 1;
	for (i = 0; i < n; i++)
	{
		temp=word[i]*(i+1);
		sum=sum +temp;
	

	}



	return sum;
}
