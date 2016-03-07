#include<stdio.h>
#include<string.h>

long hash(char *word);

	int main()
	{
		char word[200];

		fgets(word, 200, stdin);

		printf("%ld",hash(word));
  return 0;
	}

	long hash(char *word)
	{
		long result = 42;
		int i = 0;
		for (;i < strlen(word)  ; i++)
        {
            result += word[i] * (i+1);
        }
		return result;
	}



