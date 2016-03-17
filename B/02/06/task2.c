#include <stdio.h>
#include <string.h>

char* find(char *haystack, char needle);

int main()
{
    char haystack[400],needle;
    int count=0,help = -1, length;
    scanf("%[^\n]s", haystack);
    scanf(" %c", &needle);
    length = strlen(haystack);
    while(count < length)
	{
        if (find(&haystack[count],needle) == 1)
		{
            help = count;
            break;
        }
        else return NULL;
		count++;
    }
    printf("%d",help);
    return 0;
}

char* find(char *haystack, char needle){
int help = 0;
  if(needle == *haystack){
    help = 1;
  }
  if (help == 1) return 1;
  else return 0;
}