#include <stdio.h>
#include <string.h>
#define MAX 200

long hash(char*);

int main() 
{
    char input[MAX];
    fgets(input, 200, stdin);
    
    printf("%li", hash(input));
    
    return 0;
}

long hash(char *input) 
{
    
    long sum = 42;
    int length = strlen(input);
    
    for (int count=0; count<length; count++) 
    {
    	if(input[count]!= '\n')
    	{
       		sum += input[count]*(count+1);
    	}
    }
    
    return sum;
}