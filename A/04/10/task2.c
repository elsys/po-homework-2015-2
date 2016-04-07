#include<stdio.h>
#include<stdlib.h>

int main()
{
	char command[20];
	int i=0, y=0,temp=0;
	printf("Door: CLOSED\n");
	while(scanf("%s",command)!=EOF)
	{
		switch (command[0])
		{
			case 'b':
				y=i%4;
				switch (y)
				{
					case 0:
						printf("Door: OPENING\n");
						i++;
						break;
					case 1:
						printf("Door: STOPPED_WHILE_OPENING\n");
						i++;
						break;
					case 2:
						printf("Door: CLOSING\n");
						i++;
						break;
					case 3:
						printf("Door: STOPPED_WHILE_CLOSING\n");
						i++;
						break;
				}
				break;
			case 'c':
				switch (temp)
				{
					case 0:
						printf("Door: OPEN\n");
						temp=1;
						i=2;
						break;
					case 1:
						printf("Door: CLOSED\n");
						temp=0;
						i=0;
						break;
				}
				break;
		}
	}
	return 0;
}
