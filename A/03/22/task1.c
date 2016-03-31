#include <stdio.h>
#include <string.h>

int main()
{
	char egn[12];
	int egn_i[10];
	int god, mes, data;
	int i, temp;
	scanf("%s",egn);
	if (strlen(egn)==10)
	{
		for(i = 0; i < 10; i++)
		{
			egn_i[i] = egn[i] - '0';
		}
		god=egn_i[0]*10+egn_i[1];
		if(god>=0 && god<=99)
		{
			mes=egn_i[2]*10+egn_i[3];
			if((mes>=1 && mes<=12) || (mes>=21 && mes<=32) || (mes>=41 && mes<=52))
			{
				data=egn_i[4]*10+egn_i[5];
				if (data<=31)
				{
					temp = egn_i[0]*2 + egn_i[1]*4 + egn_i[2]*8 + egn_i[3]*5 + egn_i[4]*10 + egn_i[5]*9 + egn_i[6]*7 + egn_i[7]*3 + egn_i[8]*6;
					temp%=11;
					if(temp==10)
					{
						temp=0;
					}
					if (temp==egn_i[9])
					{
						printf("1");
						return 0;
					}
					else
					{
						printf("0");
						return 0;
					}
				}
				else
				{
					printf("0");
					return 0;
				}
			}
			else
			{
				printf("0");
				return 0;
			}
		}
		else
		{
			printf("0");
			return 0;
		}
	}
	else
	{
		printf("0");
		return 0;
	}
	return 0;
}