#include <stdio.h>
#include <string.h>

int main()
{
    char input1[200] = {"button_clicked"};
    char input2[200] = {"cycle_complete"};
    char box[200];
    int output[200] = {0};
    int state=0;
    int i =0;
    int yes1;
	int yes2;
    int lang;

    while(scanf("%s",box) != EOF)
    {



	       yes1 = strncmp(input1,box,12);
	       yes2 = strncmp(input2,box,12);



        if(yes1 == 0)
        {
            switch(state)
            {
            case 0:
                state = 1;
                output[i] = 1;
                break;
            case 1:
                state = 5; 
                output[i] = 5;
                break;
            case 2:
                state = 3;
                output[i] = 3;
                break;
            case 3:
                state =4;
                output[i] = 4;
                break;
            case 4:
                state = 1;
                output[i] = 1; 
                break;
            case 5:    
                state = 3;
                output[i] = 3;
                break;
             }
        }

        if(yes2 == 0 )
        {
            switch(state)
            {
            case 0:
                state =2;
                output[i] = 1;
                output[i+1] = 2;
                i++;
                break;
            case 1:
                state = 2;
                output[i] = 2;    
                break;
            case 2:
                state = 2;
                output[i] = 3;
                output[i+1] = 0;
                i++;
                break;
            case 3:
                state = 0;
                output[i] = 0;
                break;

            default:
		i--;
		break;
            }
        }
        i++; 

    }


    

    lang = i; 

    printf("Door:CLOSED\n");

    for(i = 0 ; i < lang ; i++)
    {
           switch(output[i])
           {
            case 0:
                printf("Door:CLOSED\n");
                break;
            case 1:
                printf("Door:OPENING\n");
                break;
            case 2:
                printf("Door:OPEN\n");
                break;
            case 3:
                printf("Door:CLOSING\n");
                break;
            case 4:
                printf("Door:STOPPED_WHILE_CLOSING\n");
                break;
            case 5:
                printf("Door:STOPPED_WHILE_OPENING\n");
                break;
           }
    }

    
return 0;
}
