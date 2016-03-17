#include<stdio.h>
#include<string.h>

char* find(char *, char);

int main(){

char haystack[400];
char needle;

scanf("%[^\n]s", haystack);

scanf(" %c", &needle);


if(find(haystack, needle) != NULL)
  {
   printf("%d", find(haystack, needle) - haystack);
  }
else
  {
  printf("-1");
  }

return 0;
}

char* find(char *haystack, char needle)
{
  int counter = 0;
  for(; counter < strlen(haystack); counter++)
    {
       if(haystack[counter] == needle) 
         {
            return &haystack[counter];
            break;
         } 
    }
   
    return NULL;
}
