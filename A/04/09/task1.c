#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 20

int valid_isbn(char*);
void print_publisher(char*);

int main() {
    char isbn[MAX_LENGTH], reserved[MAX_LENGTH];
    fgets(isbn, MAX_LENGTH + 1, stdin);
    
    strcpy(reserved, isbn);
    
    if (valid_isbn(isbn)) {
        printf("1");
        print_publisher(reserved);
    } else {
        printf("0");
    }
}

int valid_isbn(char *isbn) {
    int i, j, length = 0, multiplier, checksum = 0;
    char *temp;
    
    for (i = 0; i < strlen(isbn); i++) {
        if (isbn[i] >= '0' && isbn[i] <= '9') {
            length++;
        } else if (isbn[i] != '-') {
            return 0;
        }
    }
    
    if (length != 13) {
        return 0;
    }
    
    length = strlen(isbn);
    if (isbn[0] == '-' || isbn[length - 1] == '-') {
        return 0;
    }
    
    temp = strtok(isbn, "-");
    if (strcmp(temp, "978") != 0 && strcmp(temp, "979") != 0) {
        return 0;
    }
    
    j = 0;
    multiplier = 1;
    while (temp != NULL) {
        j++;
        for (i = 0; i < strlen(temp); i++) {
            checksum += (temp[i] - '0') * multiplier;
            if (j == 5) {
                checksum -= multiplier * (temp[0] - '0');
            }
            if (multiplier == 1) {
                multiplier = 3;
            } else if (multiplier == 3) {
                multiplier = 1;
            }
        }
        
        temp = strtok(NULL, "-");
    }
    
    if (10 - (checksum % 10) != isbn[length - 1] - '0') {
        return 0;
    }
    
    return 1;
}

void print_publisher(char *isbn) {
    int i = 0;
    char *temp;
    temp = strtok(isbn, "-");
    while (temp != NULL) {
        i++;
        if (i <= 3) {
            if (strcmp(temp, "933346") == 0) {
                printf("\nBluebridge");
            } else if (strcmp(temp, "55583") == 0) {
                printf("\nAlyson Books");
            } else if (strcmp(temp, "4210") == 0) {
                printf("\nFUNimation Productions, Ltd.");
            } else if (strcmp(temp, "01") == 0) {
                printf("\nPyramid Books");
            }
        } else {
            return;
        }
        temp = strtok(NULL, "-");
    }
}
