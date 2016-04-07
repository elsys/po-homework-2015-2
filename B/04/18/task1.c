#include <stdio.h>
#include <string.h>

int check_ISBN(char *);

int main() {
    
    char input_str[20] = {0};
    char *str_arr[20];
    char *temp;
    int i = 0;
    int valid = 0;
    int sum = 0;
    int length = 0;
    
    scanf("%s", input_str);
    
    length = strlen(input_str) - 4;
    
    sum = check_ISBN(input_str);  
    
    temp = strtok(input_str, "-");
    
    for (i = 0; temp != NULL; i++) {
        str_arr[i] = temp;
        temp = strtok(NULL, "-");
    }
    
    if (strstr(str_arr[0], "978") || strstr(str_arr[0], "979"))
        if (length == 13 && *str_arr[4] - '0' == sum)
            valid = 1;
            
    printf("%d\n", valid);  
                  
    if (valid) {
        if (strstr(str_arr[2], "933346")) {
            printf("Bluebridge");
        }
        
        if (strstr(str_arr[2], "55583")) {
            printf("Alyson Books");
        }
        
        if (strstr(str_arr[2], "4210")) {
            printf("FUNimation Productions, Ltd.");
        }
        
        if (strstr(str_arr[2], "01")) {
            printf("Pyramid Books");
        }    
    }            
                

    
    return 0;
}

int check_ISBN(char *arr) {

    int i = 0;
    int j = 1;
    int result = 0;
    
    for (i = 0; i < strlen(arr) - 1; i++) {
        if (arr[i] != '-') {
         
            if (j % 2 == 1) {
                result += (arr[i] - '0') * 1;
            } else {
                result += (arr[i] - '0') * 3;
            }
            j++;
           
        }
    }

    result %= 10; 
    return 10 - result;
}
