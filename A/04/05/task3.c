#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int Dora_Explorer,one_zero=0,result=0,len,temp1=0,temp2=0;
    int numbers_mason[11]={0};
    int counter=0,counter2=0;
    char input[11]={'\0'};
    char temp_c[30]={'\0'};
    char roast[512][30]={{'\0'}};
    fgets(input,11,stdin);
    scanf("%d",&Dora_Explorer);
    len=strlen(input);
    while(counter<len-1)
    {
        numbers_mason[counter]=input[counter]-'0';
        counter++;
    }
    result=numbers_mason[0];
    while(!(one_zero >> (len-2)) & 1)
    {
        for(counter=0;counter<len-2;counter++)
        {

            if((one_zero >> counter) & 1)
                {
                    result-=numbers_mason[counter+1];
                }
            else
                {
                    result+=numbers_mason[counter+1];
                }
        }
        if(result==Dora_Explorer)
        {
            temp1++;
            counter=0;
            while(counter<len-1)
                {
                    roast[temp1][counter*2]=input[counter];
                    if(counter < len-2)
                    {
                        if((one_zero >> counter) & 1)
                            {
                                temp2=(counter*2)+1;
                                roast[temp1][temp2]='-';
                            }
                        else
                            {
                                temp2=(counter*2)+1;
                                roast[temp1][temp2]='+';
                            }
                        }
                counter++;
                }
        }
        result=numbers_mason[0];
        one_zero++;

    }
    counter=1;
    while(counter<temp1)
        {
            counter2=0;
            while(counter2<temp1-counter2)
            {
                if(strcmp(roast[counter],roast[counter+1]) < 0)
                {
                    strcpy(temp_c,roast[counter]);
                    strcpy(roast[counter],roast[counter+1]);
                    strcpy(roast[counter+1],temp_c);
                }
            counter2++;
            }
        counter++;
        }
    counter=1;
    while(counter<=temp1)
    {
		printf("%s=%d\n", roast[counter],Dora_Explorer);
        counter++;
	}
	  if(!temp1)
        {
            printf("-1");
        }
    return 0;
}
