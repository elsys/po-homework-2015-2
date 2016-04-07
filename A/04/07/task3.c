#include <stdio.h>
#include <string.h>

void solve(int currentIndex, int currentSum, int);

int expected = 0;
int length = 0;
int exists = 0;
char input[10] = { '0' };
char output[22] = { '0' };

int main()
{
    scanf("%s", input);
    length = strlen(input);

    scanf("%d", &expected);

    output[0] = input[0];
    solve(1, input[0] - '0', 0);
    if (exists == 0)
    {
        printf("%d\n", -1);
    }

    return 0;
}

void solve(int currentIndex, int currentSum, int level)
{
    int i;
    if (currentIndex == length)
    {
        if (currentSum == expected)
        {
        exists = 1;
        output[currentIndex * 2 - 1] = '=';
        printf("%s", output);
        printf("%d\n", currentSum);
        }
    return;
    }

    int sum = 0;

    if (currentIndex > 0)
    {
    output[currentIndex * 2 - 1] = '-';
    output[currentIndex * 2] = input[currentIndex];
    }

    sum = currentSum - (input[currentIndex] - '0');
    solve(currentIndex + 1, sum, level + 1);

    if (currentIndex > 0)
    {
        output[currentIndex * 2 - 1] = '+';
        output[currentIndex * 2] = input[currentIndex];
    }
    sum = currentSum + (input[currentIndex] - '0');
    solve(currentIndex + 1, sum, level + 1);
}
