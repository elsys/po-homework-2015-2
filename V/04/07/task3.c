#include <stdio.h>
#include <math.h>
#include <string.h>

int sum(short int *);
void generate_result(char [100][19], short int *, int, short int, short int);

int main()
{
	short int target=0, digits[10]={0}, i=0, l, x, y, m;
	int n=0, q=0;
	char results[100][19];
	scanf("%d %hi",&n, &target);
	while(n!=0 && i<10)
	{
		digits[9-i]=n%10;
		n/=10;
		i++;
	}
	l=i;
	m=(int)pow(2, l);
	for(i=1; i<=m; i++)
	{
		if(sum(digits)==target)
		{
			generate_result(results, digits, q, l, target);
			q++;
		}
		for(x=1, y=9; x<m; x*=2, y--)
			if(i%x==0)
				digits[y]*=-1;
	}
	if(q==0)
		printf("-1");
	else
		for(i=0; i<q; i++)
			puts(results[i]);
	return 0;
}

int sum(short int digits[10])
{
	short int s=0;
	char j;
	for(j=0; j<10; j++)
		s+=digits[(int)j];
	return s;
}

void generate_result(char res[100][19], short int *n, int q, short int l, short int t)
{
	short int i, j;
	char targ[15];
	res[q][0]=n[10-l]+48;
	for(i=1, j=1; i<l; i++, j+=2)
	{
		if(n[10-l+i]>0)
		{
			res[q][j]='+';
			res[q][j+1]=n[10-l+i]+48;
		}
		else
		{
			res[q][j]='-';
			res[q][j+1]=(n[10-l+i]*-1)+48;
		}
	}
	res[q][j]='=';
	res[q][j+1]='\0';
	sprintf(targ, "%hi", t);
	strcat(res[q], targ);
}