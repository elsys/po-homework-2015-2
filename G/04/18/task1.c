#include <stdio.h>
#include <string.h>

int main()
{
	char ISBN[20];
	int valid = 1, counter, l, sum = 0, check = 1, counter2 = 0, company = 0;
    
    	scanf("%s", ISBN);
    
    	if(ISBN[0] != '9' || ISBN[1] != '7' || (ISBN[2] != '8' && ISBN[2] != '9'))
        {
        	valid = 0;
    	}
    	if(ISBN[6] == '9' && ISBN[7] == '3' && ISBN[8] == '3' && ISBN[9] == '3' && ISBN[10] == '4' && ISBN[11] == '6')
        {
        	company = 1;
    	}
    	if(ISBN[6] == '5' && ISBN[7] == '5' && ISBN[8] == '5' && ISBN[9] == '8' && ISBN[10] == '3')
        {
        	company = 2;
    	}
    	if(ISBN[6] == '4' && ISBN[7] == '2' && ISBN[8] == '1' && ISBN[9] == '0')
        {
        	company = 3;
    	}
    	if(ISBN[6] == '0' && ISBN[7] == '1')
        {
        	company = 4;
        }
        	
    	l = strlen(ISBN);
    	
    	for(counter = 0; counter < l; counter++)
    	{
    		if(ISBN[counter] > '9' && ISBN[counter] < '0' && ISBN[counter] != '-')
        	valid = 0;
    	}
    	
    	for(counter = 0; counter < l; counter++)
	{
		ISBN[counter] = (ISBN[counter] - 48);
	}
	
    	for(counter = 0; counter < l-1; counter++)
    	{

        	if(ISBN[counter] <= 9 && ISBN[counter] >= 0)
        	{
        		sum = sum + ISBN[counter]*check;
            		counter2++;
            		
            		if(counter2%2 != 0)
            		{
                		check = 3;
            		}
            		
            		else
            		{
                		check = 1;
        		}
        	}
    	}
    	if(ISBN[l-1] != 10 - (sum%10))
    	{
    		valid = 0;
    	}
    	
    	if(valid != 0)
    	{
        	printf("1");
        	
        	if(company == 1)
            	{
            		printf("\nBluebridge");
        	}
        	if(company == 2)
            	{
            		printf("\nAlyson Books");
        	}
        	if(company == 3)
            	{
            		printf("\nFUNimation Productions, Ltd.");
        	}
        	if(company == 4)
            	{
            		printf("\nPyramid Books");
    		}
    	}
   
    	else
    	{
        	printf("0");
    	}
    	
    	return 0;
}
