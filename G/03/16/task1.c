#include <stdio.h>
#include <string.h>

int is_legit (int, int, char *);

int main(){

    char egn[12];

    int year_int = 0,month_int = 0;

    scanf("%s",egn);

    int i;

    for(i = 0;i < 2;i++){
        year_int = year_int * 10 + ( egn[i] - '0' );
    }
    for(i = 2;i < 4;i++){
        month_int = month_int * 10 + ( egn[i] - '0' );
    }

    printf("%d",is_legit(month_int,year_int,egn));

    return 0;
}
int is_legit(int month_int, int year_int,char *egn){

    int tegla[] = {2,4,8,5,10,9,7,3,6};
    int answer = 0;
    int i;

    if(month_int > 52){
        return 0;
    }

    for(i = 0;i < 9;i++){
        answer = answer + ((egn[i] - 48) * tegla[i]);
    }
    answer = answer % 11;

    if(answer == 10){
        answer = 0;
    }

    if(answer != egn[9] - 48){
        return 0;
    }

    return 1;

}
