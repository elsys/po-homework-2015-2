#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* find(char *haystack, char needle);

int main()
{
    char haystack[400] , needle;
    int counter = 0 , result  = -1 , length;

    scanf("%[^\n]s", haystack);
    scanf("\n%c", &needle);

     length = strlen(haystack);
	do{
            if (find(&haystack[counter] , needle) )
            {
                result = counter;
                break;
            }
        counter ++ ;
      }while(counter < length);

    printf("%d", result);
    return 0;
}

char* find(char *haystack, char needle){
int counter = 0 , length , ok = 0;

 length = strlen(haystack);

for(counter = 0 ; counter < length ; counter ++){
    if(*haystack == needle){
        ok = 1;
        break;
    }

}
if(ok == 1)return haystack;
else return 0;
}
