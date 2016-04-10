#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int checksum(char number[]);
void pubhouse(char *copied);
void get_part(char string[], int num, char *result);
int is_number(char string[]);
int main()
{
    char result[15], result3[15], result2[15], result1[15], result4[15];
    int len =0;
    int checked;
    char str[18];
    scanf("%s", str);
    len = strlen(str);

    if(len != 17)
    {
        printf("0");
        return 0;
    }

    get_part(str, 1, result1);
    if(!(strcmp(result1, "978") == 0 || strcmp(result1, "979") == 0))
    {
        printf("0");
        return 0;
    }

    get_part(str, 2, result2);
    if(is_number(result2) != 1)
    {
        printf("0");
        return 0;
    }

    get_part(str, 3, result3);
    if(is_number(result3) != 1)
    {
        printf("0");
        return 0;
    }

    get_part(str, 4, result4);
    if(is_number(result4) != 1)
    {
        printf("0");
        return 0;
    }

    sprintf(result, "%s%s%s%s", result1, result2, result3, result4);
    checked = checksum(result);
    if(checked != str[len - 1]-48)
    {
        printf("0");
        return 0;

    }

    printf("1\n");
    pubhouse(result3);
    return 0;
}

void get_part(char string[], int num, char *result)
{
    int i = 0;
    int count = 0;

    while(count < num)
    {
        if(string[i] == '-')
        {
            count++;
            i++;
            continue;
        }
        if(count >= num - 1 && count <= num)
        {
            *result = string[i];
            result++;
        }

        i++;
    }

    *result = '\0';

}
int is_number(char string[])
{
    char c = string[0];
    int i = 0;
    if(c == '\0')
    {
        return 0;
    }

    while(c != '\0'){
        if(isdigit(c) == 0) {
            return 0;
        }
        c = string[i];
        i++;
    }

    return 1;
}
void pubhouse(char *copied)
{
    if(strcmp(copied, "933346") == 0)
    {
        printf("Bluebridge");
    }
    if(strcmp(copied, "55583") == 0)
    {
        printf("Alyson Books");
    }
    if(strcmp(copied, "4210") == 0)
    {
        printf("FUNimation Productions, Ltd.");
    }
    if(strcmp(copied, "01") == 0)
    {
        printf("Pyramid Books");
    }

}
int checksum(char number[])
{
    int sum = 0;
    int i = 0;
    int counter = 0, remainder = 0;

    for(i = 0; i < 12; i++)
    {
        if(counter == 0)
        {
             sum += number[i] -48;
             counter = 1;
        }
        else if(counter == 1)
        {
             sum += (number[i] -48)*3;
             counter = 0;
        }

    }

    remainder = sum % 10;
    return 10 - remainder;
}

