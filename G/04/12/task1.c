#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char isbn[20];
    int counter;
    int dash_counter;

    scanf("%s", isbn);

    if(strlen(isbn) != 17){
        printf("0");
        return 0;
    }
    if((isbn[0] != '9' && isbn[1] != '7' && isbn[2] != '8' && isbn[3] != '-') || (isbn[0] != '9' && isbn[1] != '7' && isbn[2] != '9' && isbn[3] != '-')){
        printf("0");
        return 0;
    }

    dash_counter = 0;

    for(counter = 0; counter < 17; counter++){
        if(isbn[counter] == '-'){
        dash_counter++;
        }
    }
    if(dash_counter != 4){
        printf("0");
        return 0;
    }

    counter = 3;

    for(;counter < 17; counter++){
        if(isbn[counter] == '-'){
            if(isbn[counter + 1] == '-'){
                printf("0");
                return 0;
            }
        }
    }

    printf("1");


    if(isbn[6] == '9' && isbn[7] == '3' && isbn[8] == '3' && isbn[9] == '3' && isbn[10] == '4' && isbn[11] == '6'){
                if(isbn[12] == '-'){
                    printf("\nBluebridge");
                }
        }
    if(isbn[6] == '5' && isbn[7] == '5' && isbn[8] == '5' && isbn[9] == '8' && isbn[10] == '3'){
                if(isbn[11] == '-'){
                    printf("\nAlyson Books");
                }
        }
    if(isbn[6] == '4' && isbn[7] == '2' && isbn[8] == '1' && isbn[9] == '0'){
                if(isbn[10] == '-'){
                    printf("\nFUNimation Productions, Ltd.");
                }
        }
    if(isbn[6] == '0' && isbn[7] == '1'){
                if(isbn[8] == '-'){
                    printf("\nPyramid Books");
                }
        }

   return 0;
}
