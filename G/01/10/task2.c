#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long
    hash(unsigned char *str)
    {
int i=1;
        unsigned long hash = 42;
        int c;


        while (c = *str++){

            hash = hash + c*i;
i++;

}
        return hash;
    }

int main()  
{ 
 char word[200];
  int a;
char str[200];
int i=0;
scanf("%1000[0-9a-zA-Z ]", str);
  char * pch;
 const char *arr[200000];
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
   
  }






    return 0;  
 free(word);
}
