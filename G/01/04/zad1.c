#include<stdio.h>
#include<string.h>
int long hash(char *word)
{
        int counter=0;
	int lenght=0;
	int sum=0;
	int count=1;
	int helper=0;

   lenght=strlen(word);

for(;counter<lenght;counter++)
{
		helper=word[counter]*count;
		sum=sum+helper;
		count++;
}

   sum=sum+42;
return sum;
}
	int main() {
	

   char word[200];
   scanf("%s",word);
  
   printf("%ld\n",hash(word));

return 0;
}
