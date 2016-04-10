#include <stdio.h>
#include <string.h>

int check_beginning(char*);
int get_dashless(char*, int);
int check_last_digit();

int dashless[15];
char phousenum[7];

int main(){
    char input[20];
    char  publishers[2][4][35] = {{"933346", "55583", "4210", "01"}, {"Bluebridge", "Alyson Books", "FUNimation Productions, Ltd.", "Pyramid Books"}};
    int length, i;

    scanf("%s", input);
    length = strlen(input);


    if(check_beginning(input)&& length == 17){
       if(get_dashless(input, length)){
            if(check_last_digit())
                printf("1");

            for(i = 0; i < 4; i++){
                if(strcmp(phousenum, publishers[0][i]) == 0){
                    printf("\n%s", publishers[1][i]);
                    break;
                }
            }
        }

       else{
            printf("0");
            return 0;
       }
    }

    else
        printf("0");

return 0;
}

int check_beginning(char* input){
    int i, valid1 = 0, valid2 = 0;
    char begg1[4] = "978-";
    char begg2[4] = "979-";

    for(i = 0; i < 4; i++){
        if(input[i] == begg1[i])
            valid1++;

        if(input[i] == begg2[i])
            valid2++;
    }
    if(valid1 == 4 || valid2 == 4)
        return 1;

return 0;
}

int get_dashless(char* input, int length){
    int i, dashes = 0, k = 1, j = 0;

    for(i = 0; i < length; i++){

        if(input[i] >= '0' && input[i] <= '9'){
            dashless[k] = input[i] - '0';
            k++;

            if(dashes == 2){
                phousenum[j] = input[i];
                j++;
            }
        }

        else{
            if(input[i] == '-' && dashes < 5)
                dashes++;

            else
                return 0;
        }
    }

return 1;
}

int check_last_digit(){
    int sum = 0, i;

	for(i = 1; i < 13; i++){
		if(i % 2 == 0){
			sum += dashless[i] * 3;
		}

		else{
			sum += dashless[i];
		}
	}

	sum = 10 - (sum % 10);

	if(dashless[13] != sum)
        return 0;

return 1;
}
