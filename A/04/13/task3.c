#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void sort(char **array,int index);
int main()
{
    char string[11];
    int i, len = 0, number_combinations = 0;
    int p, bit = 0, sum = 0;
    int result = 0, j = 0, index=0;
    char *expression;
    char *expressions[511];

    scanf("%s", string);
    scanf("%d", &result);
    len = strlen(string);

    for(i = 0; i < len - 1; i++)
    {
        number_combinations += pow(2, i);
    }


    for(p = 0; p <= number_combinations; p++)
    {

        j = 0;
        expression = (char *) malloc(24);
        expression[j] = string[0];
        j++;
        sum = string[0] - 48;
        for(i = 1; i < len ; i++)
        {
            bit = (p >> (i-1)) & 1;
            int coef = 1;
            if(bit == 0)
            {
                coef = -1;
                expression[j] = '-';

            }
            else
            {
                coef = 1;
                expression[j] = '+';

            }
            j++;
            expression[j] = string[i];
            j++;
            sum += (string[i]-48)*coef;


        }

        expression[j] = '\0';
        if(sum == result)
        {
             sprintf(expression,"%s=%d", expression, sum);
             expressions[index] = expression;
             index++;

        }
    }
    if(index == 0)
    {
        printf("-1");
        return 0;
    }
    sort(expressions, index);
    for(i = 0; i < index; i++)
    {
        printf("%s\n", expressions[i]);
    }
    return 0;
}

void sort(char **array, int index)
{
    int d;
    int c;
    char* swap;
      for (c = 0 ; c < ( index - 1 ); c++)
      {
        for (d = 0 ; d < index - c - 1; d++)
        {
          if (strcmp(array[d], array[d + 1]) < 0)
          {
            swap       = array[d];
            array[d]   = array[d+1];
            array[d+1] = swap;
          }
        }
      }
}

