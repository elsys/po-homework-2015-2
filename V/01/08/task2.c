#include <stdio.h>
#include <string.h>


long hash(char *word);

struct occurance_t{
	long hash1;
	int num_of_oc;
};


int main()
{
	//long endd=hash("vsmisal");
	char word [200];

	struct occurance_t wd[3000]; 

	 memset(wd,0, sizeof(struct occurance_t )*300);

	 // printf("%li %d\n",wd[299].hash1, wd[299].num_of_oc );
	int i=0;
	for ( i = 0; i < 3000; ++i)
	{
		scanf("%200s",word);
		
		wd[i].hash1 = hash(word);
		wd[i].num_of_oc	++;
		printf("%li %d\n",wd[i].hash1, wd[i].num_of_oc );

		if (!strcmp(word,"vsmisal"))
		{
			break;
		}
	}
	
	for (int k = 0; k<i; ++k)
	{
		for (int l = 0; l<i; ++l)
		{
			if(wd[k].num_of_oc!=0 && wd[k].hash1 == wd[l].hash1  && wd[l].num_of_oc!=0)
			{
				if(k!=l){
					wd[k].num_of_oc++;
				
					wd[l].num_of_oc=0;
				}
			}
		}
	}

	int poz=0;
	int i1=i;

	for (int l = 0; l < i; ++l)
	{
		printf("\t%d %li\n",wd[l].num_of_oc,wd[l].hash1 );
	}


	for (int l = 1; l < i1; ++l)
	{
		if((wd[poz].num_of_oc) < (wd[l+1].num_of_oc) && wd[l+1].num_of_oc>0)
		{
			poz=l+1;	printf("\t\t\t%d %d\n",poz,l);
		}

	}
	//printf("%d\n",poz );
	
	printf("%d %li\n", wd[poz].num_of_oc, wd[poz].hash1);
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