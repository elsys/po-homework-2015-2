#include<stdio.h>

int check_egn(char*);

int main()
{
  
  char egn[12];
	scanf("%s", egn);
	printf("%d", check_egn(egn));

	return 0;

}

int check_egn(char* egn)
{

	  int result = 1, number = (egn[3] - 48) * 10 + egn[4] - 48;


	  if(egn[0]== '0' && egn[1]== '0')
	{

		if(egn[2] < 50 || egn[2] >53) result = 0;

	}

	  if(egn[2] < 48 || egn[2] > 53)
	{

		result = 0;

	}

	  if(egn[3] > 50)
	{

		result = 0;

	}

	  if(egn[2] == '0' || egn[2] == '2'|| egn[2] == '4')
	{

		switch (egn[3])
		{

			case '1': if(number > 31) result =0; break;
			case '2': if(number > 29) result =0; break;
			case '3': if(number > 31) result =0; break;
			case '4': if(number > 30) result =0; break;
			case '5': if(number > 31) result =0; break;
			case '6': if(number > 30) result =0; break;
			case '7': if(number > 31) result =0; break;
			case '8': if(number > 31) result =0; break;
			case '9': if(number > 30) result =0; break;

		}

	}else if(egn[2] == '1' || egn[2] == '3' || egn[2] == '5'){
		switch(egn[3]){
			case '0': if(number > 31) result =0; break;
			case '1': if(number > 30) result =0; break;
			case '2': if(number > 31) result =0; break;
		}
	}

	return result;

}
