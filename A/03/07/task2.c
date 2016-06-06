#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int exec_cmd(int firstNumber, char operation[2], int secondNumber);

int main()
{
    char input[100];

    while(fgets(input, 100, stdin))
    {
        if(input[0] == '+' || input[0] == '!')
        {
            char operation[2];
            int secondNumber = 0;

            sscanf(input, "%s %d", operation, &secondNumber);

            if(operation[0] == '+' && operation[1] == '+')
            {
                secondNumber++;
                printf("%d", secondNumber);
            }
            else if(operation[0] == '!')
            {
                secondNumber = secondNumber * (-1);
                printf("%d", secondNumber);
            }
            else
            {
                printf("invalid input");
            }
        }
        else
        {
            int breaked = 0;
            int i;
            for(i = 0; i < strlen(input) - 1; i++)
            {
                if(input[i] == ',')
                {
                    printf("invalid command arguments");
                    breaked = 1;
                    break;
                }
                if(input[i] == ' ' || input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' || input[i] == '%' || input[i] == '!')
                {
                    continue;
                }
                if(input[i] < '0' || input[i] > '9')
                {
                    printf("invalid command arguments");
                    breaked = 1;
                    break;
                }
            }
            if(breaked)
            {
                continue;
            }
            int firstNumber = 0;
            char operation[2];
            int secondNumber = 0;

            sscanf(input, "%d %s %d", &firstNumber, operation, &secondNumber);

            if(secondNumber == 0 && operation[0] == '/')
            {
                printf("invalid arithmetic operation");
                continue;
            }

            int result = exec_cmd(firstNumber, operation, secondNumber);

            if(result == -1)
            {
                printf("operation not supported");
            }
            else if(result == 42)
            {
                printf("the answer to life, the universe and everything else");
            }
            else if(result == -2)
            {
                printf("invalid input");
            }
            else
            {
                printf("%d", result);
            }
        }
    }

    return 0;
}

int exec_cmd(int firstNumber, char operation[2], int secondNumber)
{
    if(secondNumber == 00)
    {
        return -2;
    }
    if(operation[0] == '+' && strlen(operation) == 1)
    {
        return (firstNumber + secondNumber);
    }
    if(operation[0] == '-' && strlen(operation) == 1)
    {
        return (firstNumber - secondNumber);
    }
    if(operation[0] == '*' && strlen(operation) == 1)
    {
        return (firstNumber * secondNumber);
    }
    if(operation[0] == '/' && strlen(operation) == 1)
    {
        return (firstNumber / secondNumber);
    }
    if(operation[0] == '%' && strlen(operation) == 1)
    {
        return (firstNumber % secondNumber);
    }

    return -1;
}
