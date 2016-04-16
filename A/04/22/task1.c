#include <stdio.h>
#include <string.h>

int main()
{
	char ISBN13[20];
	int ISBN13_i[13];
	int n, i;
	scanf("%s",ISBN13);
	
	for(i = 0, n=0; n < 17; n++)
	{
		if (ISBN13[n]!='-')
		{
			ISBN13_i[i] = ISBN13[n] - '0';
			i++;
		}
	}
	n=strlen(ISBN13);
	if (n==17)
	{
		if (ISBN13[0]=='9' && ISBN13[1]=='7' && (ISBN13[2]=='8' || ISBN13[2]=='9'))
		{
			n = ISBN13_i[0] + 3*ISBN13_i[1] + ISBN13_i[2] + 3*ISBN13_i[3] + ISBN13_i[4] + 3*ISBN13_i[5] + ISBN13_i[6] + 3*ISBN13_i[7]+ ISBN13_i[8] + 3*ISBN13_i[9] + ISBN13_i[10] + 3*ISBN13_i[11];
			n=n%10;
			n=10-n;
			if (n==ISBN13_i[12])
			{
				i=4;
				while(ISBN13[i]!='-')
				{
					i++;
				}
				if (ISBN13[i+1]=='9' && ISBN13[i+2]=='3' && ISBN13[i+3]=='3' && ISBN13[i+4]=='3' && ISBN13[i+5]=='4' && ISBN13[i+6]=='6')
				{
					printf("1\nBluebridge");
				}
				else
				{
					if (ISBN13[i+1]=='5' && ISBN13[i+2]=='5' && ISBN13[i+3]=='5' && ISBN13[i+4]=='8' && ISBN13[i+5]=='3')
					{
						printf("1\nAlyson Books");
					}
					else
					{
						if (ISBN13[i+1]=='4' && ISBN13[i+2]=='2' && ISBN13[i+3]=='1' && ISBN13[i+4]=='0')
						{
							printf("1\nFUNimation Productions, Ltd.");
						}
						else
						{
							if (ISBN13[i+1]=='0' && ISBN13[i+2]=='1')
							{
								printf("1\nPyramid Books");
							}
							else
							{
								printf("1");
							}
						}
					}
				}
			}
			else
			{
				printf("0");
			}
		}
		else
		{
			printf("0");
		}
	}
	else
	{
		printf("0");
	}
	return 0;
}
