#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main()
{
    char input[40] = {'\0'};
    char equation[40] = {'\0'};
    char tempequation[40] = {'\0'};
    int tempeq1 = 0;
    int tempeq2 = 0;
    int tempsum = 0;
    int num_counter = 0;
    int num_counter2 = 0;
    int op_counter = 1;
    int counter = 0;
    int counter2 = 0;
    int failurecount = 0;
    int successcount = 0;
    int checkcounter = 0;
    int repeatflag = 1;
    char success[40][40] = {{'\0'}};
    char failure[40][40] = {{'\0'}};
    int desired_output = 0;
    int op_selector = 0;
    int possibilitites = 0;
    scanf("%s", input);
    scanf("%d", &desired_output);
    if(strlen(input)>10)
    {
        return 0;
    }
    possibilitites = strlen(input) - 1;
    possibilitites = pow(2, possibilitites);
    while(input[num_counter2] != '\0')
    {
        equation[num_counter] = input[num_counter2];
        if(input[num_counter2+1]!=0)
        {
            equation[op_counter] = 'a';
        }
        num_counter++;
        num_counter++;
        op_counter++;
        op_counter++;
        num_counter2++;
    }
    counter2 = 0;
    srand(time(NULL));
    op_counter = 1;
    strcpy(tempequation, equation);
    while(counter<possibilitites)
    {
        while(repeatflag==1)
        {
            strcpy(tempequation, equation);
            while(equation[op_counter+1]!='\0')
            {
                op_selector = rand() % 2;
                switch(op_selector)
                {
                    case 0:
                        tempequation[op_counter] = 45;
                        break;
                    case 1:
                        tempequation[op_counter] = 43;
                        break;
                }
                op_counter++;
                op_counter++;
            }
            counter2 = 0;
            tempsum = 0;
            tempeq1 = tempequation[counter2] - 48;
            tempsum = tempsum + tempeq1;
            while(counter2<=strlen(tempequation))
            {
                counter2++;
                tempeq2 = tempequation[counter2+1] - 48;
                switch(tempequation[counter2])
                {
                    case '-':
                        tempsum = tempsum - tempeq2;
                        break;
                    case '+':
                        tempsum = tempsum + tempeq2;
                        break;
                }
                counter2++;
            }
            repeatflag = 0;
            while(checkcounter<40)
            {
                if(strcmp(tempequation, success[checkcounter]) == 0)
                {
                    strcpy(tempequation, equation);
                    repeatflag = 1;
                    tempsum = 0;
                }
                if(strcmp(tempequation, failure[checkcounter]) == 0)
                {
                    strcpy(tempequation, equation);
                    repeatflag = 1;
                    tempsum = 0;
                }
                checkcounter++;
            }
            if(counter==possibilitites)
            {
                repeatflag = 0;
            }
            checkcounter = 0;
            op_counter = 1;
        }
        repeatflag = 1;
        checkcounter = 0;
        if(tempsum==desired_output)
        {
            strcpy(success[successcount], tempequation);
            printf("\n%s", success[successcount]);
            printf("=%d", desired_output);
            successcount++;
        }
        if(tempsum!=desired_output)
        {
            strcpy(failure[failurecount], tempequation);
            failurecount++;
        }
        tempsum = 0;
        counter2 = 0;
        op_counter = 1;
        counter++;
    }
    if(successcount==0)
    {
        printf("-1");
    }
    return 0;
}
