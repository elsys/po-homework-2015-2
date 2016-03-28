#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valid1(int*);
int valid2(int*);

int main(){
    char egn[12];
    int arr[12];
    int i, a = 0, b = 0;
    scanf("%s", egn);
    for(i = 0; i < 10; i++){
        arr[i] = egn[i] - '0';
    }
    a = valid1(arr);
    b = valid2(arr);
    if(b == arr[9] && a == 1)
        printf("1");
    else
        printf("0");
    return 0;
}

int valid1(int *ptr){
    int date, ch = 0;
    date = ptr[2]*10 + ptr[3];
    if((date >= 1 && date <= 12)||(date >= 21 && date <= 32)||(date >= 41 && date <= 52))
        ch =  1;
    return ch;
}

int valid2(int *ptr){
    int a, b;
    a = (ptr[0]*2 + ptr[1]*4 + ptr[2]*8 + ptr[3]*5 + ptr[4]*10 + ptr[5]*9 + ptr[6]*7 + ptr[7]*3 + ptr[8]*6);
    b = a % 11;
    if(b == 10)
        b = 0;
    return b;
}
