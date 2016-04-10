#include<string.h>
#include<stdio.h>

void check_publisher(char *publisher);
int check_first3(char *isbn);
int parse(char *isbn, int *parsed,char *publisher);
int isbn13(int *parsed);
int main()
{

    char isbn[20];
    char publisher[10];
    int parsed[13] = {0};

    scanf("%s",isbn);

    if(strlen(isbn)!=17)
    {
        printf("0");
        return 0;
    }

    if(check_first3(isbn) ==0 )
    {
        printf("0");
        return 0;
    }

    if(parse(isbn,parsed,publisher) == 0 )
    {
        printf("0");
        return 0;
    }

    if (isbn13(parsed) == 0)
    {
        printf("0");
        return 0;
    }

    printf("1\n");

    check_publisher(publisher);
    return 0;
}

int check_first3(char *isbn)
{

    if((isbn[0] == '9' && isbn[1] == '7' && isbn[2] == '8' && isbn[3] == '-')||
            (isbn[0] == '9' && isbn[1] == '7' && isbn[2] == '9' && isbn[3] == '-'))return 1;


    return 0;
}

int parse(char *isbn, int *parsed,char *publisher)
{

    int i,j,dash=0,counter=0;

    for(i=0,j=0; i<17; i++,j++)
    {

        if(isbn[i] == '-')
        {
            i++;
            dash++;
        }
        if(dash>4)return 0;

        if (dash==2)
        {
            publisher[counter]=isbn[i];
            counter++;
        }

        if(isbn[i] == '-' && isbn[i+1] == '-')return 0;
        parsed[j]=isbn[i]-48;

    }
    return 1;
}

int isbn13(int *parsed)
{
    int sum=0,i;
    for(i=0; i<12; i++)
    {

        if(i%2==0)sum=sum+parsed[i];
        else
        {
            sum=sum+parsed[i]*3;
        }

    }

    if((10-sum%10) == parsed[12])
    {
        return 1;
    }

    return 0;
}

void check_publisher(char *publisher)
{

    if(strcmp(publisher,"55583")==0)printf("Alyson Books");
    else if(strcmp(publisher,"933346")==0)printf("Bluebridge");
    else if(strcmp(publisher,"4210")==0)printf("FUNimation Productions, Ltd.");
    else if(strcmp(publisher,"01")==0)printf("Pyramid Books");

}



