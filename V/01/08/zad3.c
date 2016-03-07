#include <stdio.h>
#include <string.h>


long hash(char *word);

struct occurance_t{
	long hash1;
	int num_of_oc;
	int num_of_oc_w;
	char word1[200];
};


int main()
{
	//long endd=hash("vsmisal");

	struct occurance_t wd[3000]; 

	 memset(wd,0, sizeof(struct occurance_t )*3000);

	 // printf("%li %d\n",wd[299].hash1, wd[299].num_of_oc );
	int i=0;
	for ( i = 0; i < 3000; ++i)
	{
		scanf("%200s",wd[i].word1);
		
		wd[i].hash1 = hash(wd[i].word1);
		wd[i].num_of_oc	++;
		//printf("%li %d\n",wd[i].hash1, wd[i].num_of_oc );

		
	
	
	for (int k = 0; k<i; ++k)
	{
		for (int l = 0; l<i; ++l)
		{
			if(wd[k].num_of_oc!=0 && wd[k].hash1 == wd[l].hash1  && wd[l].num_of_oc!=0)
			{
				if(k!=l){
					wd[k].num_of_oc++;
				
					wd[l].num_of_oc=0;
					if (strcmp(wd[k].word1,wd[l].word1))
					{
						wd[k].num_of_oc_w++;
					}
				}
			}
		}
	}

	int poz=0;
	int i1=i;
/*
	for (int l = 0; l < i; ++l)
	{
		printf("\t%d %li\n",wd[l].num_of_oc,wd[l].hash1 );
	}

*/
	for (int l = 1; l < i1; ++l)
	{
		if((wd[poz].num_of_oc_w) < (wd[l+1].num_of_oc_w) && wd[l+1].num_of_oc_w>0)
		{
			poz=l+1;	//printf("\t\t\t%d %d\n",poz,l);
		}

	}
	if (wd[poz].num_of_oc_w>=4)
	{
		break;
	}
	//printf("%d\n",poz );
	
	
	}

	int poz^=poz , poz2;
	for (int l = 0; l < i; ++l)
	{
		poz2=poz;
		for (int l = 1; l < i; ++l)
		{
			if((wd[poz].hash1) < (wd[l+1].hash1) && wd[l+1].num_of_oc_w>1)
			{
				poz=l+1;	//printf("\t\t\t%d %d\n",poz,l);
			}

		}


		printf("%li",wd[poz],hash1 );
		for (int k = 0; k < wd[poz].num_of_oc_w; ++k)
		{
			for (int k = poz; k < i; ++k)
			{
					if (wd[poz].hash1 == wd[k].hash1 && !strcmp(wd[poz].word1,wd[k].word1))
					{
						printf("%s ", wd[k].word1);
					}
			}
		}


	}



	return 0;
}

long hash(char *word)
{
	long hash=42;
	int len=0;
	while(word[len]!='\0') len++; 
	

	for (int i = 0; i < len; ++i)
	{
		hash += ((long)word[i])*(i+1);
	}

	return hash;
}