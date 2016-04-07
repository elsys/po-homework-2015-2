#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int check_length(char data[20]){
    int i;
    int length = strlen (data);
    int num_digits = 0;
    for (i=0;i<length; i++)
        if (isdigit(data[i])){
            num_digits++;
        }
    if(num_digits == 13)
        return 1;
    return 0;
}
char* stringify(char data[20]){
    int i, j = 0;
    int length = strlen (data);
    static char string[13];
    for (i=0;i<length; i++)
        if (isdigit(data[i])){
            string[j++]=data[i];
        }
        string[j] = '\0';
    return string;
}
int check_checksum(char data[13]){
    int i;
    int x;
    int sum = 0;
    for(i = 0 ; i < 12; ++i){
        if(i%2 == 0){
            x = 1;
        } else {
            x = 3;
        }
    sum += ((int)data[i] - '0') * x;
    }
    int checksum = 10 - sum%10;
    if(checksum == (int)data[12] - '0')
        return 1;
    return 0;
}
void print_house(char* str){
    if(strcmp(str, "933346") == 0){
        printf("Bluebridge");
    }
    else if(strcmp(str, "55583") == 0){
            printf("Alyson Books");
    }
    else if(strcmp(str, "4210") == 0){
            printf("FUNimation Productions, Ltd.");
    }
    else if(strcmp(str, "01") == 0){
            printf("Pyramid Books");
    }
}
int main(){
    char *ch;
    char data[20];
    char data_copy[20];
    char* splitted[5];
    int i = 0, j =0;
    char *string;
    if (fgets(data, sizeof data, stdin)) {
        strcpy(data_copy, data);
        ch = strtok(data, "-");
        while (ch != NULL) {
            splitted[i++] = ch;
            ch = strtok(NULL, "-");
        }
    }
    string = stringify(data_copy);
    if(check_length(data_copy)){
        if(!strcmp(splitted[0],"978") || !strcmp(splitted[0],"979")){
            if(check_checksum(string)){
                printf("1\n");
                print_house(splitted[2]);
            } else printf("0\n");
        } else printf("0\n");
    } else printf("0\n");
    return 0;
}
