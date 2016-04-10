#include <stdio.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0

bool have = false;

int check(bool, int );
void func (int [], int , int );

int main()
{
    int number[10];
    int num;
    int lenght=0;
    int i=0, j=0;
    int chisloto;
    int temp;
    scanf("%d", &chisloto);
    while(chisloto > 1)
    {
        number[lenght]=chisloto%10;
        chisloto/=10;
        lenght++;
    }
    for(i=0, j=lenght-1; i<=j; i++, j--)
    {
        temp=number[i];
        number[i]=number[j];
        number[j]=temp;
    } 
    scanf("%d", &num);
    func(number, lenght, num);
    if(have == false)
    {
        printf("-1");
    }
    return 0;
}

int check(bool a, int n)
{
    if(a)
    {
        return n;
    }
    else
    {
        return -n;
    }
}

void func (int number[], int len, int num)
{
    bool c[len-1];
    int i=0, k=0, z=0;
    int ch;
    for(i=0; i<len-1; i++)
    {
        c[i]=true;
    }
    for(i=0; i<pow(2, len-1); i++)
    {
        for(k=0; k<len-1; k++)
        {
            int kk= pow(2,k);
            if(i%kk==0)
            {
                c[len-2-k]=!c[len-2-k];
            }
        }
        ch=number[0];
        for(z=0; z<len-1; z++)
        {
            ch+=check(c[z], number[z+1]);
        }
        if(ch==num)
        {
            have=true;
            printf("%d", number[0]);
            for(z=1; z<len; z++)
            {
                printf("%c%d",(c[z-1]) ? ('+') : ('-'), number[z]);  
            }
            printf("=%d\n", num);
        }
    }
}