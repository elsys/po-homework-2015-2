#include <stdio.h>
#include <string.h>

int is_valid_ucn(char*);

int main() {
    
    char ucn[12];
    fgets(ucn, 13, stdin);
    
    printf("%d", is_valid_ucn(ucn));
    
    return 0;
}

int is_valid_ucn(char *ucn) {
    
    int control = 0, month = (ucn[2] - '0') * 10 + (ucn[3] - '0');
    int length = strlen(ucn);
    int weights[] = { 2, 4, 8, 5, 10, 9, 7, 3, 6 };
    
    if (length == 10) {
        
        if (!(
            (month >= 1 && month <= 12) || 
            (month >= 1 + 20 && month <= 12 + 20) ||
            (month >= 1 + 40 && month <= 12 + 40))
        ) { 
            return 0; 
        }
        
        for (int i = 0; i < length - 1; i++) {
            control += (ucn[i] - '0') * weights[i];
        }
        
        control %= 11;
        if (control != ucn[9] - '0' || control > 10) {
            return 0;
        }
        
    } else {
        return 0;
    }
    
    return 1;
}