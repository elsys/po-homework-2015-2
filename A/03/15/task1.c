#include <stdio.h>

struct upn_t{
	int year;
	int month;
	int day;
	int birthOrder;
	int controlNumber;
};

int getControlNumber(char *upn);
int checkUpn(struct upn_t upn, char *upnstring);

int main(){
	char upnstring[12];
	scanf("%s", upnstring);
	struct upn_t upn;
	upn.year = ((upnstring[0] - '0') * 10) + (upnstring[1]-'0');
	upn.month = ((upnstring[2] - '0') * 10) + (upnstring[3]-'0');
	upn.day = ((upnstring[4] - '0') * 10) + (upnstring[5]-'0');
	upn.birthOrder = ((upnstring[6] - '0') * 100) + ((upnstring[7]-'0') * 10) + (upnstring[8]-'0');
	upn.controlNumber=upnstring[9]-'0';
	
	printf("%d", checkUpn(upn, upnstring));
	return 0;
}

int checkUpn(struct upn_t upn, char *upnstring){
	for(int i = 0; i<10; i++){
		if(upnstring[i]<'0' || upnstring[i]>'9'){
			return 0;
		}
	}
	if( !( (upn.month>=1 && upn.month <=12) || (upn.month>=21 && upn.month <= 32) || (upn.month>=41 && upn.month <=52) ) ){
		return 0;
	}
	if(upn.day == 0 || upn.month == 0 || upn.birthOrder==0){
		return 0;
	}
	if(upn.day>=29 && (upn.month == 2 || upn.month==22 || upn.month==42) && upn.year%4!=0){
		return 0;
	}
	if(getControlNumber(upnstring) != upn.controlNumber){
		return 0;
	}
	return 1;
}

int getControlNumber(char *upn){
		int i, controlNumber=0, weights[9] = {2, 4, 8, 5, 10, 9, 7, 3, 6};
		for(i=0; i<9; i++){
			controlNumber+= ((upn[i]-'0') * weights[i]);
		}
		controlNumber = controlNumber % 11;
		if(controlNumber==10){
			controlNumber=0;
		}
		return controlNumber;
}
