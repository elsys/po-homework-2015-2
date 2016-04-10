#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i=0, len=0, n=0;
    int a=0, b=1, c=2, d=3, e=4, f=5;
    char cmnd[15];
    char click[15]="button_clicked";
    char cycle[15]="cycle_complete";
    int arr[100]={0};


    while(scanf("%s",cmnd)!=EOF)
    {
        if(0==strcmp(cmnd,click))
        {
            arr[i]=1;
        }
        if(0==strcmp(cmnd,cycle))
        {
            arr[i]=0;
        }
        i++;
        len++;
    }
    i=0;

    printf("Door: CLOSED\n");

    while(i<len)
    {
            if(arr[i]==1)
			{
				switch(n)
				{
				case 0:
				    printf("Door: OPENING\n");
				    n=b;
				    break;

				case 2:
				    printf("Door: CLOSING\n");
				    n=d;
				    break;

                case 1:
				    printf("Door: STOPPED_WHILE_OPENING\n");
				    n=c;
				    break;

				case 3:
				    printf("Door: STOPPED_WHILE_CLOSING\n");
				    n=e;
				    break;

				case 4:
				    printf("Door: OPENING\n");
				    n=b;
				    break;

				case 5:
				    printf("Door: CLOSING\n");
				    n=d;
				    break;
				}
			}

			if(arr[i]==0)
			{
				switch(n)
				{
                    case 1:
                        printf("Door: OPEN\n");
                        n=f;
                        break;

					case 5:
					    printf("Door: OPEN\n");
                        n=f;
                        break;

					case 0:
					    printf("Door: CLOSED\n");
                        n=a;
                        break;

					case 3:
					    printf("Door: CLOSED\n");
                        n=a;
                        break;
				}
			}

			i++;
    }


    return 0;
}
