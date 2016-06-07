#include <stdio.h>
#include <math.h>

int main()
{
	
	int a[10]={0};
	int i;
	for ( i = 0; i < 10 && scanf("%c",(char *)&a[i])>0; ++i)
	{
		if(a[i]==10)break;
		else
		{ 
			a[i]=a[i]-'0';
		}
	}
	
	a[i]=0;
	char ima=0;
	int rez=0;
	scanf("%d", &rez);

	long sum=0;
		for (int j = 0; j <= (long int)powl(2,i-1); ++j)
		{
			sum=0;
			sum=a[0];
			//printf("%li ",sum);

			for (int k = 1; k <= i-1; ++k)
			{
				if( ((j>>(k-1)) & 1))
				{
					sum=sum+a[k];
					//printf("1");
				}
				else
				{
					sum=sum-a[k];
					//printf("0");

				}
			}
			//printf("\t%li\n",sum);


			if ((long int)rez == sum )
			{
				ima=1;
				for (int k = 0; k <i; ++k)
				{
					printf("%d",a[k] );
					if( ((j>>k) & 1) && k <i-1 )
					{
						printf("+");
					}
					else
					{
						printf("-");
					}
				}
				printf("\b=%d\n", rez);
			}
		}

	


		if(ima==0)printf("-1\n" );
	return 0;
}