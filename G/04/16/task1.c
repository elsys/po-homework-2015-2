#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_digit_calc(char *);

int main()
{

    char isbn[20];
    char isbn_only_numbers[13];



    int EAN;
    int publisher;
    int dash_counter = 0;

    int i,length,x = 0;


    scanf("%s",isbn);

    length = strlen(isbn);


    for(i = 0; i < length; i++){

        if(isbn[i] >= '0' && isbn[i] <= '9'){

            isbn_only_numbers[x] = isbn[i];
            x++;


        }
    }


    EAN = ((isbn[0]- '0') * 10 + isbn[1] - '0' ) * 10 + isbn[2] - '0';

    for(i = 0;i < length;i++){

        if(isbn[i] == '-'){
            dash_counter++;


        }

        if(dash_counter == 2){

            publisher = isbn[i + 1] - '0';

            i += 2;

            while(isbn[i] != '-'){
                 publisher = (publisher) * 10 + isbn[i] - '0';
                 i++;

            }

            break;
        }

    }


    if(EAN == 978 || EAN == 979){

        printf("%d",check_digit_calc(isbn_only_numbers));
        if(check_digit_calc(isbn_only_numbers)){

            switch(publisher){

            case 933346 : printf("\nBluebridge");
            break;

            case 55583 : printf("\nAlyson Books");
            break;

            case 4210 : printf("\nFUNimation Productions, Ltd.");
            break;

            case 01 : printf("\nPyramid Books");
            break;

            }

        }

    }else{

        printf("0");

    }


    return 0;
}
int check_digit_calc(char *isbn_only_numbers){

    int i = 0;
    int last_digit = 0;

    for(i = 11; i >= 1;i -= 2){
        last_digit = last_digit + ((isbn_only_numbers[i] -'0') * 3 + isbn_only_numbers[i-1] - '0');
    }

    last_digit = last_digit % 10;

    last_digit = 10 - last_digit;



    if(last_digit == isbn_only_numbers[12] - '0'){
        return 1;
    }


    return 0;
}
