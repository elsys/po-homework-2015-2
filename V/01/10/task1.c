#include <stdio.h>
#include <string.h>
long hash(char *word);

int main()

{
  char d[199];
  
  
  do{
  	scanf("%s",d);
  	
  	}while(strlen(d)>200);
  	
   //printf("d=%s",d);
   printf("%ld",hash(d));




return 0; 
}

long hash(char *word)
{
	long h=42;
	int i;
	for(i=0;i<=strlen(word)-1;i++)
	{
		
	    h=h+(i+1)*word[i];
		
	}
return h;	
}
