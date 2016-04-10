#include <stdio.h>
#include <string.h>

int checksum(short unsigned int n[13]);
int group_size_check(int m[5]);

int main()
{
	char input[20];
	short unsigned int ISBN[13]={0}, l, j, i=0, groups=0;
	int ISBN_grouped[5];
	fgets(input, sizeof(input), stdin);
	l=strlen(input);
	if(input[l-1]=='\n')
	{
		input[l-1]='\0';
		l--;
	}
	if(l!=17)
	{
		printf("0");
		return -1;
	}
	for(j=0; j<17; j++)
	{
		if(input[j]=='-')
			continue;
		else if(input[j]>='0' && input[j]<='9')
		{
			ISBN[i]=(short unsigned int)input[j]-48;
			i++;
		}
		else
		{
			printf("0");
			return -1;
		}
	}
	groups=sscanf(input, "%d-%d-%d-%d-%d",&ISBN_grouped[0], &ISBN_grouped[1], &ISBN_grouped[2], &ISBN_grouped[3], &ISBN_grouped[4]);
	if(groups!=5 || group_size_check(ISBN_grouped)==-1 || (ISBN_grouped[0]!=978 && ISBN_grouped[0]!=979) || checksum(ISBN)==-1)
	{
		printf("0");
		return -1;
	}
	printf("1");
	switch(ISBN_grouped[2])
	{
		case 933346: printf("\nBluebridge"); break;
		case 55583: printf("\nAlyson Books"); break;
		case 4210: printf("\nFUNimation Productions, Ltd."); break;
		case 01: printf("\nPyramid Books"); break;
	}
	return 0;
}

int checksum(short unsigned int n[13])
{
	short unsigned int s=0, i, expected_check_digit;
	for(i=0; i<12 ;i++)
	{
		s+=n[i]*(1+(i%2)*2);
	}
	expected_check_digit=10-s%10;
	if(n[12]!=expected_check_digit)
		return -1;
	else
		return 0;
}

int group_size_check(int m[5])
{
	if(m[1]>9 || m[4]>9 || m[3]>999999 || m[2]>9999999)
		return -1;
	else
		return 0;
}