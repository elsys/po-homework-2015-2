#include <stdio.h>
#include <string.h>
long hash(char *word);

struct occurance_t{
   long h;
   int count;
   
   } d[3000];
   
int main()

{
   
   
   //d[0]={0,0};
  
  char duma[199];
  char end[7]="vsmisal";
  int i=0,j,max=1,n=0;
  
    do{
  	scanf("%s",duma);
  	d[i].h=hash(duma);
  	d[i].count=1;
  	
  	for(j=0;j<i;j++)
  	{
  	
  	   if(d[j].h==d[i].h)
  	   {
  	     d[i].count++;
  	   }
  	}
  	
  	i++;
  	
    }while(strcmp(duma,end) != 0 );
    
    for(j=0;j<i;j++)
     {
    	if(d[j].count > max)
   	   {
       	     max=d[j].count;
             n=j;
    	    }
	   
	   
     }
   printf("%d %ld", d[n].count, d[n].h);
   


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
