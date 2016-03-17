#include <stdio.h>
#include <string.h>

char find(char *haystack, char needle);
int main ()
{
	
	char needle;
	char haystack[400];
	fgets (haystack, 400 , stdin);
	scanf ("%c",&needle);
	printf("%d\n",find (haystack,needle));
	return 0;
}
char find(char *haystack, char needle)
{
	int times,i,n;
	n=strlen(haystack);
	for(i=0;i<n-1;i++){
		if(haystack[i]==needle){
				times=i;
				break;
		}
	}



	return times;
}