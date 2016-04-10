include <stdio.h>
#include <string.h>

int main()
{
    char s[400];
    int i,j,st[20];
    st[0]=1;
    for(i=0;;i++)
    {
        s[i]=getchar();
        if(s[i]==EOF)
            break;
        while(1)
            if(getchar()=='\n')
                break;
    }
    for(i=0;i<strlen(s);i++)
    {if(s[i]=='b')
        {
         if(st[i]==1)
            st[i+1]=2;
         if(st[i]==2)
            st[i+1]=6;
         if(st[i]==3)
            st[i+1]=4;
         if(st[i]==4)
            st[i+1]=5;
         if(st[i]==5)
            st[i+1]=2;
         if(st[i]==6)
            st[i+1]=4;
        }
     else
        {
            if(st[i]==2)
                st[i+1]=3;
            if(st[i]==4)
                st[i+1]=1;

        }

    }
    for(j=0;j<i+2;j++)
    {
        if(st[j]==1)
            printf("Door: CLOSED\n");
        if(st[j]==2)
            printf("Door: OPENING\n");
        if(st[j]==3)
            printf("Door: OPEN\n");
        if(st[j]==4)
            printf("Door: CLOSING\n");
        if(st[j]==5)
            printf("Door: STOPPED_WHILE_CLOSING\n");
        if(st[j]==6)
            printf("Door: STOPPED_WHILE_OPENING\n");
    }
    return 0;
}
