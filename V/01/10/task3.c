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
  	
  	//printf("h=%ld ", d[i].h);
  	
  	d[i].count=1;
  	
  	for(j=0,n=1;j<i;j++)
  	{
  	
  	   if(d[j].h==d[i].h)
  	   {
  	     d[i].count++;
  	     //printf("\n%d",d[i].count);
  	     strcpy(d[i].str[n],d[j].str[0]);
  	     
  	     strcpy(d[j].str[d[j].count],d[i].str[0]);
  	     d[j].count++;
  	     //printf("\n%d",d[j].count);
  	     n++;
  	     //printf("\nn=%d",n);
  	   }
  	}
  	
  	i++;
  	
    }while(n != 4 );
    
        
    for(i=0;i<=3000;i++)
    {
    	
    	if(d[i].count>1)
    	{
 	
 	   printf("\n%ld ", d[i].h);
    	   
    	   for(j=0;j<=4;j++)
    	   {
    	   
    	   printf("%s ", d[i].str[j]);
    	   
    	   }
    	}
    	
    }
    
   


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
