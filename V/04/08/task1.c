#include <stdio.h>
#include <string.h>

int main()
{
	char a[20]={0};
	scanf("%s",a);

	if(0==strncmp(a,"978",3) || 0==strncmp(a,"979",3))
	{
		long chek=0;
		for (int i = 0,k=0; i < strlen(a)-2; ++i)
		{
			if (a[i]<='9' && '0'<=a[i])
			{	

				k++;
				if(a[i]!='-')
				chek= chek + (a[i]-'0')*k;
				else 
				;	
				//printf("         %d\n", (a[i]-'0')*k);
				//printf("%li\n",chek );
			}
		}
		printf("%li\n",chek );
		//printf("%d\n",(a[strlen(a)-1]-'0' ));
		//if( chek%11 == (a[strlen(a)-1]-'0'))printf("1\n");
		//else printf("0\n");

		char *b=a+4;
		
		if(0==strncmp(b,"933346",6)){printf("%s\n", "Bluebridge");}

		if(0==strncmp(b,"55583",5)){printf("%s\n", "Alyson Books");}


		if(0==strncmp(b,"4210",4)){printf("%s\n", "FUNimation Productions, Ltd.");}


		if(0==strncmp(b,"1",1)){printf("%s\n", "Pyramid Books");}
		printf("1\n");

	}
	else
	{
		printf("0\n");
	}

// 	Номер - Издателска къща
// 933346 - Bluebridge
// 55583 - Alyson Books
// 4210 - FUNimation Productions, Ltd.
// 01 - Pyramid Books

	//printf("1\n");
	return 0;
}