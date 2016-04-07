#include <stdio.h>
#include <string.h>
#define NOT_VALID -1
#define VALID 1

int checkLength (char *);
int checkFirstDigits (char *);
int IsOnlyDigits (char *);
int checkSum(char *);
int conVertToInt32 (char);
void CheckPublisher(char *);

int main () {

    char inputISBN[20];

    scanf("%[^\n]s",inputISBN);

    if (checkLength(inputISBN)
        && checkFirstDigits(inputISBN)
        && IsOnlyDigits(inputISBN)) {

            if ((checkSum(inputISBN) + 48) == inputISBN[strlen(inputISBN) - 1]) {
                printf("%d",VALID);
                CheckPublisher(inputISBN);
                return 0;
            }
        }
    printf("0");
    return 0;
}

int checkLength(char *isbn) {

    int length = 0;
    length = strlen(isbn);
    if (length != 17) return NOT_VALID;
    return VALID;
}

int checkFirstDigits(char *isbn) {

    char start1[] = "978";
    char start2[] = "979";

    int first = strncmp(isbn, start1, 3);
    int sec = strncmp(isbn, start2, 3);

    if (first == 0 || sec == 0) {
        return VALID;
    }
    return NOT_VALID;

}

int IsOnlyDigits(char *isbn) {

    int index = 0;

    for(; index < strlen(isbn); index++) {

        if (isbn[index] < '0' || isbn[index] > '9' || isbn[index] != '-') {

            break;
            return NOT_VALID;
        }
    }
    return VALID;
}

int checkSum (char *isbn) {

    int counter = 0;
    int position = counter + 1;
    int sum = 0;

    for (counter = 0; counter < strlen(isbn) - 1; counter++) {
        if (isbn[counter] != '-') {

            if (position % 2 == 0) {
                sum = sum + conVertToInt32(isbn[counter])*3;
            }
            else sum = sum + conVertToInt32(isbn[counter])*1;
            position = position + 1;
        }
    }

    return 10 - (sum%10);
}

int conVertToInt32(char elem) {

    return elem - 48;
}

void CheckPublisher(char *isbn) {
    /* 933346 - Bluebridge
55583 - Alyson Books
4210 - FUNimation Productions, Ltd.
01 - Pyramid Books*/
    char BlueBridge[] = "933346";
    char Alyson[] = "55583";
    char FUNimation[] = "4210";
    char Pyramid[] = "01";

    if (strstr(isbn,BlueBridge) != NULL) {
        printf("\nBluebridge");
    }
    if (strstr(isbn, Alyson) != NULL) {
        printf("\nAlyson Books");
    }
    if (strstr(isbn, FUNimation) != NULL) {
        printf("\nFUNimation Productions, Ltd.");
    }
    if (strstr(isbn, Pyramid) != NULL) {
        printf("\nPyramid Books");
    }
}
