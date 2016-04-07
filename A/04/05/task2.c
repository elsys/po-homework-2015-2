#include <stdio.h>
#include <string.h>
struct clicker{
char result[50];
};
int main()
{
	char command[20];
	int temp=0,checker=0 ,counter=0,s_counter=0;
	struct clicker clicks[50];
	while(scanf("%s",command) != EOF && s_counter<50)
	{
		if(command[0]=='b')
				{
				    checker=counter%4;
                    if(checker==0)
                    {strcpy(clicks[s_counter].result,"Door: OPENING");
                            counter++;}
                    if(checker==1)
                    {strcpy(clicks[s_counter].result,"Door: STOPPED_WHILE_OPENING");
                            counter++;}
                    if(checker==2)
                     {strcpy(clicks[s_counter].result,"Door: CLOSING");
                            counter++;}
                    if(checker==3)
                      {strcpy(clicks[s_counter].result,"Door: STOPPED_WHILE_CLOSING");
                            counter++;}
                }
        if(command[0]=='c')
					if(temp==0)
						{strcpy(clicks[s_counter].result,"Door: OPEN");
						temp=1;
						counter=2;}
					else
                        {strcpy(clicks[s_counter].result,"Door: CLOSED");
                        temp=0;
                        counter=0;}
        s_counter++;
		}
  printf("Door: CLOSED\n");
	for(counter=0;counter<s_counter;counter++)
    {
        printf("%s\n",clicks[counter].result);
    }
	return 0;
}
