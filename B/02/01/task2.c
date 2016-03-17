#include <stdio.h>
#include <string.h>

char* find(char *haystack, char needle);

int main()
{
    char haystack[400],needle;
    int counter,helper = -1, lenght;

    scanf("%[^\n]s", haystack);
    scanf(" %c", &needle);

    lenght = strlen(haystack);

    for (counter = 0; counter < lenght ; counter ++){
        if (find(&haystack[counter],needle) == 1){
            helper = counter;
            break;
        }
    }
    printf("%d",helper);

    return 0;
}

char* find(char *haystack, char needle){

int helper = 0;

  if(needle == *haystack){
    helper = 1;
  }

  if (helper == 1) return 1;
  else return 0;
}
