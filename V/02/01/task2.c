#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *find(char *haystack,char needle);

int main()
{
 int i;
 char* haystack = (char*)malloc(sizeof(char)*400);
 char needle,c;
 for(i=0;c!='\n';i++)
 {
  haystack[i]=getchar();
  c=haystack[i];
 }
 scanf("%c",&needle);
 printf("%ld",find(haystack,needle)-haystack);
 return 0;
}


char *find(char *haystack, char needle)
{
 int i;
 for(i=0;i<strlen(haystack);i++)
 {
  if(needle==haystack[i])
  {
   return(haystack+i);
  }
 }
 return NULL;
}
