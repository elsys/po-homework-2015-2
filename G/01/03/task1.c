 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int long hash(char *word);
int main()
{
   char word[200] = {0};

  scanf("%s",word);

hash(word);

   return 0;
}
int long hash(char *word)
{

   int i;
   int core =1 ;
   int go;
   int helper=0;
   int answer=0;

   go = strlen(word);

   for(i=0;i<go;i++)

   {
     helper = word[i] * core;
     answer = answer + helper;
     core ++;
   }
answer = answer + 42;
printf("%d",answer);
return 0;
} 
