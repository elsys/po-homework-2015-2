#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define STRUCT_MAX_LEN 3000
#define WORD_LEN 200


struct occurance_t{
	int hash;
	char same[4][WORD_LEN];
};



int sorting(struct occurance_t* );

int hash(char * );

void printing(struct occurance_t *,int );



int main()
{
	
	char input[WORD_LEN];
	struct occurance_t array[STRUCT_MAX_LEN];
	int i, j,length;


	for(i = 0; i < STRUCT_MAX_LEN; i++)
	{
		array[i].hash = 0;

		for(j = 0; j < 4; j++)
			array[i].same[j][0] = 0;
		
	}


	do{
		i = 0;

		scanf(" %s", input);
		

		while(array[i].hash != 0)
		{
			if(hash(input) == array[i].hash)
			{

				for(j = 0; array[i].same[j][0] != 0  && strcmp(input, array[i].same[j]) != 0; j++);
				

				if(strcmp(input, array[i].same[j]) != 0 && j < 3)
					strcpy(array[i].same[j], input);
               


                break;
			}

			i++;
		}
		
		if(array[i].hash == 0)
		{
			array[i].hash = hash(input);

			strcpy(array[i].same[0], input);
		}

		if(j == 3)
            break;
	

	}while(1);

	
	length = sorting(array);


	printing(array,length);
	

	return 0;
}

int hash(char* input)
{

	int length = strlen(input);
	int hashed_value = 42;
	int i;

	if(length > 1)
	{
		for(i = 0; i < length; i++)
		{
			hashed_value = hashed_value + input[i]*(i+1);
		}
	}

	return hashed_value;
}

int sorting(struct occurance_t* array)
{
	int i,j,k;

	struct occurance_t temp;
	
	int len;
	
	for(len = 0; array[len].hash != 0; len++);

	for(i = 0; i < (len-1); i++)
	{
		
		for(j = 0; j < (len-i-1); j++)
		{
			
			if(array[j].hash > array[j+1].hash)
			{
				
				temp.hash = array[j].hash;


				for(k = 0; array[j].same[k] != 0 && k < 4 ; k++)
					strcpy(temp.same[k], array[j].same[k]);
				
				array[j].hash = array[j+1].hash;
				
				for(k = 0; array[j+1].same[k] != 0 && k < 4; k++)
					strcpy(array[j].same[k], array[j+1].same[k]);
				

				array[j+1].hash = temp.hash;
				for(k = 0; temp.same[k] != 0 && k < 4 ; k++)
					strcpy(array[j+1].same[k], temp.same[k]);
			}
		}
	}
	return len;
}

void printing(struct occurance_t* array, int len)
{
	int i,j;



	for(i = 0; i < len; i++)
	{
		if(array[i].same[1][0] != 0)
		{
			printf("%d", array[i].hash);
			
			for(j = 0; j < 4 ; j++)
			{
				if(array[i].same[j][0] != 0)
					printf(" %s", array[i].same[j]);
			}
			printf(" ");
		}
	}
}