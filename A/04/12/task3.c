#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

    int dig[10];
    int mi, pl;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

int main()
{
    char str[10];
    char str1[20]={""};
    char str2[20]={""};
    char ch;
    int res, i, flag=0, chk, l, tmp=0, j, broj, i1, pp=1;
    scanf("%s",str);
    scanf("%d",&res);
    l=strlen(str);
    for(i=0; i<l; i++)
    {
        chk=isdigit(str[i]);

        if(chk!=0)
        {
            dig[i]=str[i]-48;
        }
        else
        {
            flag=1;
        }
    }

    if(flag==1)
    {
        printf("-1");
        return 0;
    }
    else
    {
        chk=0;

        broj=1;
        for(i=0;i<l-1;i++)
        {
            broj=broj*2;
        }
        mi=broj-1;

        for(i=0; mi>=0 ;i++)
        {
            tmp=dig[0];
            ch=48+dig[0];
            strcpy(str1,str2);
            strncat(str1,&ch,1);
            for(j=0;j<l-1;j++)
            {
                i1=l-j-2;
                chk=CHECK_BIT(mi,i1);
                if (chk==0)
                {
                    tmp=tmp+dig[j+1];
                    ch='+';
                    strncat(str1,&ch,1);
                    ch=48+dig[j+1];
                    strncat(str1,&ch,1);
                }
                else
                {
                    tmp=tmp-dig[j+1];
                    ch='-';
                    strncat(str1,&ch,1);
                    ch=48+dig[j+1];
                    strncat(str1,&ch,1);
                }
            }
            if (tmp==res)
            {
                switch(pp)
                {
                    case 1:
                        printf("%s=%d",str1,res);
                        pp++;
                        break;
                    case 2:
                        printf("\n%s=%d",str1,res);
                        break;
                }
                flag=1;
            }
            mi--;
        }
    }
    if (flag==0)
    {
        printf("-1");
    }

    return 0;
}
