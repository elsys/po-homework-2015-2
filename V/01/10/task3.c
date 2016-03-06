#include <stdio.h>
#include <string.h>
long hash(char *word);

struct occurance_t{
   long h;
   int count;
   char str[4][200];
   
   } d[3000];
   
int main()

{
   
   
   
  int i=0,j,n;
  
    do{
  	scanf("%s",d[i].str[0]);
  	d[i].h=hash(d[i].str[0]);
  	
  	d[i].count=1;
  	
  	for(j=0,n=1;j<i;j++)
  	{
  	
  	   if(d[j].h==d[i].h)
  	   {
  	     d[i].count++;
  	     strcpy(d[i].str[n],d[j].str[0]);
  	     n++;
  	   }
  	}
  	
  	i++;
  	
    }while(n != 4 );
    
    
   printf("%s %s %s %s", d[i-1].str[0], d[i-1].str[1], d[i-1].str[2], d[i-1].str[3]);
   


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
