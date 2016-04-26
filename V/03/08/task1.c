#include <stdio.h>

int dddddd()
{
	
	char a[13]={0};

	scanf("%12s",a);

	if(a[10]!=0) return 0;
 
	int numbers[10];
	for (int i = 0; i < 10; ++i)
	{
		numbers[i]=a[i]-'0';
	}

//01
	if (!(!(numbers[2]>=0  && numbers[2]<=1 && numbers[3]>=0  && numbers[3]<=9) ||  !(numbers[2]>=4  && numbers[2]<=5 && numbers[3]>=0  && numbers[3]<=9))) return 0;
 

	if(!(numbers[4]>=0 && numbers[4]<=3)) return 0;
 

	int sum = numbers[0]*2 + numbers[1]*4 +numbers[2]*8+numbers[3]*5+numbers[4]*10+numbers[5]*9+numbers[6]*7+numbers[7]*3+numbers[8]*6;


	sum = (sum %11)%10;

	if(!(numbers[9]==sum)) return 0; 


	return 1;

	return 0;
}

 int main(int argc, char const *argv[])
{
	printf("%d",dddddd() );
	return 0;
}