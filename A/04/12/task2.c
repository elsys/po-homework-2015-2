#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 50

char ms[MAX_LEN][MAX_LEN];
char s[MAX_LEN];
int i;
char ch2=10;
char strCmd[2][40]={"button_clicked","cycle_complete"};
int hrmr=0;
int broj=0, j=1;

int main()
{
    int flag=0;
    int cnt=0;
    int cmd=0;
    int first=1;
    char ch;
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
    broj=hrmr+1;

    for(i=0; i<hrmr;i++)
    {
        if(strcmp(ms[i],strCmd[0])==0)
        {
            cmd=1;
        }
        else if(strcmp(ms[i],strCmd[1])==0)
        {
            cmd=2;
        }
        else
        {
            cmd=0;
        }
        if(cmd!=0)
        {
            switch(cnt)
            {
                case 0 :   //CLOSED
                    if(cmd==1)
                    {
                        if(first==1)
                        {
                            printf("Door: CLOSED" );
                            if(j<broj)
                            {
                                printf("\n");
                                j++;
                            }
                            first=0;
                        }
                        printf("Door: OPENING" );
                        if(j<broj)
                        {
                            printf("\n");
                            j++;
                        }
                        cnt=1;
                    }
                break;

                case 1 : //OPENING
                    if(cmd==1)
                    {
                        printf("Door: STOPPED_WHILE_OPENING" );
                        if(j<broj)
                        {
                            printf("\n");
                            j++;
                        }
                        cnt=2;
                    }
                    else if(cmd==2)
                    {
                        printf("Door: OPEN" );
                        if(j<broj)
                        {
                            printf("\n");
                            j++;
                        }
                        cnt=3;
                    }
                break;

                case 2 :  //STOPPED_WHILE_OPENING
                    if(cmd==1)
                    {
                        printf("Door: CLOSING" );
                        if(j<broj)
                        {
                            printf("\n");
                            j++;
                        }
                    cnt=5;
                    }
                break;

                case 3 : //OPEN
                    if(cmd==1)
                    {
                        printf("Door: CLOSING" );
                        if(j<broj)
                        {
                            printf("\n");
                            j++;
                        }
                        cnt=5;
                    }
                break;

                case 4 : //STOPPED_WHILE_CLOSING
                    if(cmd==1)
                    {
                        printf("Door: OPENING" );
                        if(j<broj)
                        {
                            printf("\n");
                            j++;
                        }
                        cnt=1;
                    }
                break;

                case 5 : //CLOSING
                    if(cmd==1)
                    {
                        printf("Door: STOPPED_WHILE_CLOSING" );
                        if(j<broj)
                        {
                            printf("\n");
                            j++;
                        }
                        cnt=4;
                    }
                    else if(cmd==2)
                    {
                        printf("Door: CLOSED" );
                        if(j<broj)
                        {
                            printf("\n");
                            j++;
                        }
                        cnt=0;
                    }
                break;
            }
        }
    }
  return 0;
}
