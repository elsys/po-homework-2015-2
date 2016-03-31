#include <stdio.h>
#include <string.h>


int main()
{
	char egn[12];
	int m = 0, result, last_num;

	scanf ("%s", egn);
	

	if(strlen(egn) != 10)
		printf("10");




	else{
		if (egn[2] == 1 || egn[2] == 3 || egn[2] == 5)
		{	
			if (egn[3] <= 2)
				m = 1;
		}	




	
		else if (egn[2]-48 == 0 || egn[2]-48 == 2 || egn[2]-48 == 4)
			{
				if (egn[3]-48 <= 9)
				m = 1;
			}
		if( m )
		{	
			result = (egn[0]-48)*2;
			result = result + (egn[1]-48) * 4;
			result = result + (egn[2]-48) * 8;
			result = result + (egn[3]-48) * 5;
			result = result + (egn[4]-48) * 10;
			result = result + (egn[5]-48) * 9;
			result = result + (egn[6]-48) * 7;
			result = result + (egn[7]-48) * 3;
			result = result + (egn[8]-48) * 6;	
			last_num = result % 11;
			if(last_num == 10) last_num = 0;
			if(last_num == egn[9] - 48) 
				printf("1");		
			else printf("20");
		}




		else printf("30");		
	}

}



