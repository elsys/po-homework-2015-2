#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long hash(char *word);

int main()
{
	char word[200]={0};
	long sum=0;
	do{
		scanf("%s",word);
	}while(strlen(word)>200);
	sum=hash(word);
	printf("\n%ld",sum);
	return 0;
}

long hash(char *word)
{
	long sum=42;
	int i=0;
	for(i=0;i<strlen(word);i++)
	{
		sum=sum+word[i]*(i+1);
	}
	return sum;
}
