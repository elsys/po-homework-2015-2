#include <stdio.h>
#include <string.h>

int main(){

    char string[20];

    int help = 1 , counter , res = 0 , p = 1 , j = 0 , house_num = 0 , length;

    scanf("%s",string);

    if(string[0] != '9' || string[1] != '7'|| (string[2] != '8' && string[2] != '9'))
        help = 0;


    if(string[6] == '0' && string[7] == '1')
        house_num = 1;
    if(string[6] == '4' && string[7] == '2' && string[8] == '1' && string[9] == '0')
        house_num = 2;
    if(string[6] == '9' && string[7] == '3' && string[8] == '3' && string[9] == '3' && string[10] == '4' && string[11] == '6')
        house_num = 3;
    if(string[6] == '5' && string[7] == '5' && string[8] == '5' && string[9] == '8' && string[10] == '3')
        house_num = 4;


    length = strlen(string);

    for(counter = 0 ; counter < length ; counter++){

        if(string[counter] > '9' && string[counter] < '0' && string[counter] != '-')

        help = 0;

        string[counter] = string[counter] - '0';
    }

    for(counter = 0 ; counter < length-1 ; counter++){

        if(string[counter] <= 9 && string[counter] >= 0){
            res = res + string[counter]*p;

            j++;

            if(j % 2 != 0)
                p = 3;
            else
                p = 1;
        }
    }

    if(string[length-1] != 10 - (res % 10))
        help = 0;

    if(help){

        printf("1");

        if(house_num == 1)
            printf("\nPyramid Books");
        if(house_num == 2)
            printf("\nFUNimation Productions, Ltd.");
        if(house_num == 3)
            printf("\nBluebridge");
        if(house_num == 4)
            printf("\nAlyson Books");

    }
    else
        printf("0");

    return 0;
}
