#include <stdio.h>
#include <string.h>

char find(char haystack, char needle)
{
 int i;
 for (i = 0; i < strlen(haystack); ++i)
 {
  if(haystack[i] == needle)
  {
   return &haystack[i];
  }
 }

 return 0;
}
int pos(char *haystack,char needle){
int i;
int g=0;
 for (i = 0; i < strlen(haystack); ++i)
 { 
  if(haystack[i] !=' '){
   g++;
  } 
  if(haystack[i] == needle)
  {
   return g;
  }
 }

}
int main()
{
 char arr[400];
 char needle;
 char *needle1;

 scanf("%400[0-9a-zA-Z ]", arr);
 scanf(" %c", &needle);

 needle1 = find(arr, needle);
 int position = pos(arr,needle);
 printf("%d\n",position);
 return 0;
}
