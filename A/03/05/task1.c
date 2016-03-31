#include <stdio.h>

int validation(char* EGN)
{
    int counter=0,cont=0,chisla[12];
    int weights[9] = {2, 4, 8, 5, 10, 9, 7, 3, 6};
    for(counter=0;counter<10;counter++)
    {
        if(EGN[counter] < '0' || EGN[counter] > '9')
        {
            return 0;
        }
    }
    if(EGN[4] == 3 && EGN[5] > '1')
        {
            return 0;
        }
    if(EGN[4] > '3' || counter == 0 || EGN[2] >= '6')
	    {
		return 0;
	    }
    if(EGN[2] == '1' || EGN[2] == '3' || EGN[2] == '5')
	if(EGN[3] > '2')
        {
            return 0;
        }
    counter=0;
    while(counter<10)
    {
        chisla[counter] = EGN[counter] - 48;
        if(counter < 10)
            {
                cont=cont+(weights[counter]*chisla[counter]);
            }
        counter++;
    }
    cont=cont%11;

    if(cont < 10)
        if(chisla[9] != cont)
        {
            return 0;
        }
    if(cont == 10)
        if(chisla[9] != 0)
        {
            return 0;
        }
    return 1;
}
int main()
{
    int result=0;
    char EGN[12];
    scanf("%s", EGN);
    result=validation(EGN);
    printf("%d",result);
}
