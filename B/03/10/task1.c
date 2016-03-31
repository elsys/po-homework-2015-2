#include <stdio.h>
#include <string.h>

int UpnCheck(char *);
int convertCharacterToInt32 (char digit);

int main () {

    char EGN[12];

    scanf("%[^\n]s",EGN);

    if (strlen(EGN) == 10) {

        printf("%d",UpnCheck(EGN));

    }
    else printf("%d",NULL);


    return 0;
}

int convertCharacterToInt32(char digit) {

    return digit - 48;

}

int UpnCheck(char *upn) {
    int control = 0,helper = 0;

    if (upn[0] < '0' || upn[0] > '9') return 0;
    if (upn[1] < '0' || upn[1] > '9') return 0;

    //Month
    if (convertCharacterToInt32(upn[2])*10 + convertCharacterToInt32(upn[3]) > 52) return 0;

    //Date
    if (upn[4] > '3' || upn[4] < '0') return 0;
    if (upn[4] == '3') {
        if(upn[5] != '1' || upn[5] != '0') return 0;
    }
    if (upn[5] < '0' || upn[5] > '9') return 0;

    //Control number
    control += convertCharacterToInt32(upn[0]) * 2;
    control += convertCharacterToInt32(upn[1]) * 4;
    control += convertCharacterToInt32(upn[2]) * 8;
    control += convertCharacterToInt32(upn[3]) * 5;
    control += convertCharacterToInt32(upn[4]) * 10;
    control += convertCharacterToInt32(upn[5]) * 9;
    control += convertCharacterToInt32(upn[6]) * 7;
    control += convertCharacterToInt32(upn[7]) * 3;
    control += convertCharacterToInt32(upn[8]) * 6;
    if (control % 11 < 10) helper = control % 11;
    if (control % 11 == 10) helper = 0;

    if (convertCharacterToInt32(upn[9]) != helper) return 0;

    //If all digit is VALID
    return 1;
}
