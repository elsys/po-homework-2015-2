#include <stdio.h>
#include <string.h>

int main()
{
	char egn[12];
	int l, egn_control, months, i;
	
	scanf("%s", egn);
	
	l = strlen(egn);
	
	if(l != 10)
	{
		printf("0");
		return 0;
	}
	
	for(i = 0; i < l; i++)
	{
		egn[i] = (egn[i] - 48);
	}
	
	months = (egn[2]) * 10 + (egn[3]);
	
	if(months < 1 && months > 12)
	{
		printf("0");
		return 0;
	}	
	
	if(months < 1 + 20 && months > 12 + 20)
	{
		printf("0");
		return 0;
	}
	
	if(months < 1 + 40 && months > 12 + 40)
	{
		printf("0");
		return 0;
	}
		
	egn_control = (egn[0]*2) + (egn[1]*4) + (egn[2]*8) + (egn[3]*5) + (egn[4]*10) + (egn[5]*9) + (egn[6]*7) + (egn[7]*3) + (egn[8]*6);
	
	egn_control = egn_control % 11;
	
	if(egn_control == 10)
	{
		egn_control = 0;	
	}
	if(egn[9] != egn_control)
	{
		printf("0");
	}
	else
	{
		printf("1");
	}
	return 0;
}
