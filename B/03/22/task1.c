#include <stdio.h>

int main () {
	char egn[10];
	int check = 1 ;
	int check_sum = 0; 
	
		fgets(egn , 12 , stdin);

	
	if ( egn [2] < '0' || egn[2] > '5'   ){
		check = 0;

	}	
	else if(  (egn[2] == '1' && egn[3] > '2' ) || (egn[2] == '3' && egn[3] > '2' ) || (egn[2] == '5' && egn[3] > '2' )){
	    check = 0;

	}
	if( egn[4] > '3' || (egn[4] == '3' && egn[5] > '1') || (egn[4] == '0' && egn[5] == '0' ) ){

		check = 0;
	}
check_sum = check_sum + ((egn[0] - '0') * 2);
check_sum = check_sum + ((egn[1] - '0') * 4);
check_sum = check_sum + ((egn[2] - '0') * 8);
check_sum = check_sum + ((egn[3] - '0') * 5);
check_sum = check_sum + ((egn[4] - '0') * 10);
check_sum = check_sum + ((egn[5] - '0') * 9);
check_sum = check_sum + ((egn[6] - '0') * 7);
check_sum = check_sum + ((egn[7] - '0') * 3);
check_sum = check_sum + ((egn[8] - '0') * 6);

if( check_sum % 11 < 10 ){
	
	if(( egn[9] - '0') != (check_sum % 11) ){
	 check  =  0; 	
	 printf("kzl")
         }
}else {	if( egn[9] != '0' ) check  =  0;}

	printf("%d", check);
	return 0;
}
