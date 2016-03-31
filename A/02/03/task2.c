#include <stdio.h>
#include<stdio.h>
char* find(char *haystack, char needle)
{
    char *c = NULL;
    while(*haystack)
    {
    	if(*haystack==needle)
    	{
    		c = haystack;
    		break;
    	}
    	haystack++;
    }
    return c;
    
}

int main(void) 
{
    char mychar, *foundchar=NULL, myrow[401];
    char *mr = NULL;
    int i=0;
    fgets(myrow,401,stdin);
    scanf("%c",&mychar);
    
    foundchar = find(myrow,mychar);
  
    
    if(foundchar==NULL)
    {
        printf("-1");
    }
    else
    {
  mr=myrow;
      
      while(*mr)
      {
           if(mr == foundchar)
           {
               printf("%d",i);
               break;
          }
          i++;
          mr++;
      } 
      
    }
    
   
	return 0;
} 
