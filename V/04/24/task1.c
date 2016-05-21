#include<stdio.h>
#include<string.h>

int check(char*);
void publishing_house(char*);


int main ()
{
	char ISBN13[20];
	scanf("%s", ISBN13);
	printf("%d", check(ISBN13));	
	if(check(ISBN13)!=0)publishing_house(ISBN13);

	return 0;

}


int check(char *ISBN13)
{

	int result = 1, length = 0, i;

	if(ISBN13[0] != '9' || ISBN13[1] != '7' || (ISBN13[2] != '8' && ISBN13[2] != '9'))
	{

		result = 0;
	
	}
	for(i=0; i<strlen(ISBN13); i++)
	{

		if(ISBN13[i]<='9' && ISBN13[i]>='0')
		{

			length++;
		
		}

	}

	if(length != 13) result = 0;

	return result;

}

void publishing_house(char*ISBN13)
{

	int i = 0;

	while(i<strlen(ISBN13))
	{
		if(ISBN13[i]=='6'&& ISBN13[i-1]=='4' && ISBN13[i-2]=='3'&& ISBN13[i-3]=='3' && ISBN13[i-4]=='3'&& ISBN13[i-5]=='9')	
			printf("\nBluebridge");
		if(ISBN13[i]=='3'&& ISBN13[i-1]=='8' && ISBN13[i-2]=='5'&& ISBN13[i-3]=='5' && ISBN13[i-4]=='5') 
			printf("\nAlyson Books");
		if(ISBN13[i]=='0'&& ISBN13[i-1]=='1' && ISBN13[i-2]=='2'&& ISBN13[i-3]=='4') 
			printf("\nFUNimation Productions, Ltd.");	
		if(ISBN13[i]=='1'&& ISBN13[i-1]=='0') 
			printf("\nPyramid Books");

		i++;

  }

}
