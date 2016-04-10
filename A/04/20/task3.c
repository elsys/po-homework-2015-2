#include <stdio.h>
#include <string.h>

void implementation(int, int, int);

int expected;
int length;
int flag = 0;
char input[10]="\0";
char output[22]="\0";

int main()
{
    scanf("%s", input);
    length = strlen(input);

    scanf("%d", &expected);

    output[0] = input[0];
    implementation(1, input[0] - '0', 0);
    if (flag == 0)
    {
        printf("%d\n", -1);
    }

    return 0;
}

void implementation(int number, int currentSum, int level)
{
	int temp;
    if (number == length)
    {
        if (currentSum == expected)
        {
        flag = 1;
        temp = number*2;
        output[temp-1] = '=';
        printf("%s", output);
        printf("%d\n", currentSum);
        }
    return;
    }

    int sum = 0;

    if (number > 0)
    {
		temp = number*2;
		
		output[temp-1] = '-';
    	
    	output[temp] = input[number];
    }
    	sum = currentSum - (input[number] - '0');
    	
    	implementation(number + 1, sum, level + 1);


    	if (number > 0)
    	{
        	output[temp - 1] = '+';
        	output[temp] = input[number];
    	}
    	sum = currentSum + (input[number] - '0');
    	
    	implementation(number + 1, sum, level + 1);
}