#include <stdio.h>
#include <string.h>

char* find(char *haystack,char needle);

int main()
{
	char symbol;
	char row[400];
	scanf("%[^\n]",row);

	
	scanf("\n%c", &symbol);
	
	if(find(row,symbol))
	{
  	printf("%ld",find(row,symbol)-row);
        }
	else
	{printf("-1");}

return 0;
}

  char* find(char *haystack,char needle)
  {
     int i;
     
     for(i=0;i<=strlen(haystack);i++)
     {
     	if(haystack[i]==needle)
     	{
     	    return &haystack[i];
     	    
     	}
     }
     
  return NULL;
  }
