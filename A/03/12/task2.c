#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 1000

char  ms[MAX_LEN][MAX_LEN];
char  s[MAX_LEN];
int i;
char ch2=10;

struct command_t
	{
		char arg1[10];
		char op[10];
		char arg2[10];
		int result;
	}cmd;
int execCmd(struct command_t *);
int isDig(char *);

int main()
{
    int hrmr=0;
    int flag=0, broj, j=0;
    char *tok, sp[2]=" ";

    char ch;
    int i1;
    int i10;
    while(flag==0)
    {
        i=0;
        ch=getchar();
        while((ch!=EOF && ch!=ch2) && i<(MAX_LEN))
        {
            s[i++]=ch;
            ch=getchar();
        }
        if(ch==EOF)
        {
            flag=1;
            if(i==0)
            {
                break;
            }
        }
    s[i]='\0';

    strcpy(ms[hrmr],s);
    hrmr++;
    }

    for(i10=0; i10<hrmr; i10++)
    {
        broj=0;
        tok=strtok(ms[i10], sp);
        strcpy(cmd.arg1,tok);
        broj++;
        while(tok!= NULL )
        {
            tok = strtok(NULL,sp);
            if(tok!=NULL )
            {
                if(broj==1)
                {
                    strcpy(cmd.op,tok);
                }
                else if(broj==2)
                {
                    strcpy(cmd.arg2,tok);
                }
                broj++;
            }
        }
        cmd.result=broj;
        i1=execCmd(&cmd);
        if(i1==0)
        {
            printf("%d",cmd.result);
            if(j<=broj)
            {
                printf("\n");
                j++;
            }
        }
        else if(i1==-1)
        {
            printf("%s","operation not suppurted");
            if(j<=broj)
            {
                printf("\n");
                j++;
            }
        }
        else if(i1==-2)
        {
            printf("%s","invald command argument count");
            if(j<=broj)
            {
                printf("\n");
                j++;
            }
        }
        else if(i1==-3)
        {
            printf("%s","invald command arguments");
            if(j<=broj)
            {
                printf("\n");
                j++;
            }
        }
        else if(i1==-4)
        {
            printf("%s","invald input");
            if(j<=broj)
            {
                printf("\n");
                j++;
            }
        }
        else if(i1==-5)
        {
            printf("%s","invald aritmetic operation");
            if(j<=broj)
            {
                printf("\n");
                j++;
            }
        }
        else if(i1==-42)
        {
            printf("%s","the ansver to life, the universe and everything else");
            if(j<=broj)
            {
                printf("\n");
                j++;
            }
        }
    }
  return 0;
}

int isDig(char *str)
{
    int i, len, chk;
    len=strlen(str);
    if(((str[0]=='-') || (str[0]=='+')) && len!=0)
    {
        return 1;
    }
    for(i=0;i<len;i++)
    {
        if(((str[0]=='-') || (str[0]=='+')) && len!=1)
        {
            i++;
        }
        chk=isdigit(str[i]);
        if(chk==0)
        {
            return 1;
        }
    }
   return 0;
}

int execCmd(struct command_t *cmd)
{
    int res=0;
    int flag1=0, flag2=1, flag3=0;
    char str1[10], str2[10], str3[10];
    int ar1, ar2;
    res=cmd->result;
    if(res<2 || res>3)
    {
        return -4;
    }
    if(res==2)
    {
        strcpy(str1,"\0");
        strcpy(str2,cmd->arg1);
        strcpy(str3,cmd->op);

        if(isDig(str3)==0)
        {
            ar1=atoi(str3);
        }
        else
        {
            if((strlen(str3)==1) && ((str3[0]=='+') || (str3[0]=='-') || (str3[0]=='*') || (str3[0]=='/') || (str3[0]=='%')))
            {
                flag3=2;
            }
            else
            {
                flag3=1;
            }
        }

        if(flag3==2)
        {
            if(isDig(str2)==0)
            {
                return -2;
            }
            else
            {
                return -4;
            }

        }
        if(strlen(str2)==1)
        {
            if(str2[0]=='!')
            {
                flag2=0;
            }
            if((str2[0]=='+') || (str2[0]=='-') || (str2[0]=='*') || (str2[0]=='/') || (str2[0]=='%'))
            {
                flag2=2;
            }

            if(flag1==0 && flag2==0 && flag3==0)
            {
                res=!ar1;
                if(res!=42)
                {
                    cmd->result=res;
                    return 0;
                }
                else
                {
                    return -42;
                }
            }
        }
        if(strlen(str2)==2)
        {
            if((str2[0]=='+') && (str2[1]=='+'))
            {
                flag2=3;
            }
        }

        if(flag1==0 && flag2==3 && flag3==0)
        {
            res=++ar1;
            if(res!=42)
            {
                cmd->result=res;
                return 0;
            }
           else
           {
             return -42;
           }
        }
        if(flag1==0 && flag2==1 && flag3==1)
        {
            return -4;
        }
        if(flag1==0 && flag2==2 && flag3==1)
        {
            return -4;
        }


    }


    else
    {
        strcpy(str1,cmd->arg1);
        strcpy(str2,cmd->op);
        strcpy(str3,cmd->arg2);
        if(isDig(str1)==0)
        {
            ar1=atoi(str1);
        }
        else
        {
            flag1=1;
        }
        if(isDig(str3)==0)
        {
            ar2=atoi(str3);
        }
        else
        {
            flag3=1;
        }

        if(strlen(str2)==1)
        {
            if((str2[0]=='+') || (str2[0]=='-') || (str2[0]=='*') || (str2[0]=='/') || (str2[0]=='%'))
            {
                flag2=0;
            }
            if(str2[0]=='!')
            {
                flag2=2;
            }
        }
        if(strlen(str2)==2)
        {
            if((str2[0]=='+') && (str2[1]=='+'))
            {
                flag2=2;
            }
        }

        if(flag1==0 && flag2==1 && flag3==0)
        {
            return -1;
        }

        if(flag1==0 && flag2==2 && flag3==0)
        {
            return -2;
        }

        if((flag1==1 || flag3==1) && flag2==0)
        {
            return -3;
        }
        if((flag1==1 || flag3==1) && flag2==1)
        {
            return -4;
        }

        if(flag1==0 && flag2==0 && flag3==0)
        {
            if(str2[0]=='+')
            {
                res=ar1+ar2;
                if(res!=42)
                {
                    cmd->result=res;
                    return 0;
                }
                else
                {
                    return -42;
                }
            }
            else if(str2[0]=='-')
            {
                res=ar1-ar2;
                if(res!=42)
                {
                    cmd->result=res;
                    return 0;
                }
                else
                {
                    return -42;
                }
            }
            else if(str2[0]=='*')
            {
                res=ar1*ar2;
                if (res!=42)
                {
                    cmd->result=res;
                    return 0;
                }
                else
                {
                return -42;
                }
            }
            else if(str2[0]=='/')
            {
                if(ar2!=0)
                {
                    res=ar1/ar2;
                    if(res!=42)
                    {
                        cmd->result=res;
                        return 0;
                    }
                    else
                    {
                        return -42;
                    }
                }
            }
            else if(str2[0]=='%')
            {
                if(ar2!=0)
                {
                    res=ar1%ar2;
                    cmd->result=res;
                    return 0;
                }
            }
        }

    }
    return 0;
}

