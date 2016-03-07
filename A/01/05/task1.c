#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long hash(char *word)
{
	int counter=0,lenght;
	long res=42;
    lenght=strlen(word);
	while(counter<=lenght-1)
	{
		res=res + word[counter]*(counter+1);
		counter++;
	}
    return res;
}

int main()
{
	int result;
	char array[200];

    scanf("%s",array);
    result = hash(array);
    printf("%d",result );
    return 0;
}
