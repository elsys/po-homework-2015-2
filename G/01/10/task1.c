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
char *word;  
 word = (char *) malloc(200);
 scanf("%s", word);
  int a=hash(word);
printf("%d",a);


 free(word);

    return 0;  
}
