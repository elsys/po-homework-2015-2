#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 20


int main()
{
	char inp_ISBN[MAXLEN];
	int final_checksum = 0,x,placeofcheck,i,ISBN_num_count;
	char header1[3] = "978",header2[3] = "979";


	scanf("%s",inp_ISBN);

	for(i = 0; i < 3; i++)
	{
		if(inp_ISBN[i] != header1[i] && inp_ISBN[i] != header2[i]) 
			{
				printf("0");
				return 0;
			}
	}

	for(i = 0 ; i < strlen(inp_ISBN) && ISBN_num_count != 13; i++)
	{
		if(inp_ISBN[i] >= '0' && inp_ISBN[i] <= '9')
		{
			ISBN_num_count++;
			placeofcheck = i;
		}

		else
		{
			

			if(inp_ISBN[i+1] == '-')
			{
				printf("0");
				return 0;
			}

			if(inp_ISBN[i] != '-')
			{
				printf("0");
				return 0;
			}

			
		}

	}
	if(ISBN_num_count < 13)
	{
		printf("0");
		return 0;
	}

	for(i = 0,ISBN_num_count = 0;i < strlen(inp_ISBN) && ISBN_num_count < 12; i++)
	{
		if(inp_ISBN[i]>= '0' && inp_ISBN[i]<= '9')
		{
			ISBN_num_count++;
			if(ISBN_num_count%2 == 0)
			{
				x = (inp_ISBN[i] - '0')*3;
			}
			if(ISBN_num_count%2 != 0)
			{
				x = (inp_ISBN[i] - '0');
			}
			final_checksum  = final_checksum + x;
		}
	}

	final_checksum = final_checksum % 10;

	final_checksum = 10 - final_checksum;

	if(final_checksum == (inp_ISBN[placeofcheck]- '0'))
	{
		printf("1");
		
	}



	if(inp_ISBN[6] == '9' && inp_ISBN[7] == '3' && inp_ISBN[8] == '3' && inp_ISBN[9] == '3' && inp_ISBN[10] == '4' && inp_ISBN[11] == '6')
	    printf("\nBluebridge");
   	
   	if(inp_ISBN[6] == '0' && inp_ISBN[7] == '1')                    
	    printf("\nPyramid Books");
    
    if(inp_ISBN[6] == '5' && inp_ISBN[7] == '5' && inp_ISBN[8] == '5' && inp_ISBN[9] == '8' && inp_ISBN[10] == '3')
	     printf("\nAlyson Books");
	
	if(inp_ISBN[6] == '4' && inp_ISBN[7] == '2' && inp_ISBN[8] == '1' && inp_ISBN[9] == '0')
	    printf("\nFUNimation Productions, Ltd.");
	

	
	return 0;
}