#include <stdio.h>
#include <string.h>

int main()
{
    char string[20];
    int b=1,i,n,m=0,k=1,j=0,br=0;
    scanf("%s",string);
    if(string[0]!='9'||string[1]!='7'||(string[2]!='8'&&string[2]!='9')){
        b=0;
	}	
    if(string[6]=='9'&&string[7]=='3'&&string[8]=='3'&&string[9]=='3'&&string[10]=='4'&&string[11]=='6'){
        br=1;
	}
    if(string[6]=='5'&&string[7]=='5'&&string[8]=='5'&&string[9]=='8'&&string[10]=='3'){
        br=2;
	}
    if(string[6]=='4'&&string[7]=='2'&&string[8]=='1'&&string[9]=='0'){
        br=3;
	}
    if(string[6]=='0'&&string[7]=='1'){
        br=4;
	}
    n=strlen(string);
    for(i=0;i<n;i++){
		if(string[i]>'9'&&string[i]<'0'&&string[i]!='-'){
        	b=0;
		}
     	string[i]=string[i]-'0';
    }
    for(i=0;i<n-1;i++){
        if(string[i]<=9&&string[i]>=0)
        {
			m=m+string[i]*k;
            j++;
            if(j%2!=0){
                k=3;
			}
            else{
                k=1;
			}
        }
    }
    if(string[n-1]!=10-(m%10))
        b=0;
    if(b)
    {
        printf("1");
        if(br==1){
            printf("\nBluebridge");
		}
        if(br==2){
            printf("\nAlyson Books");
		}
        if(br==3){
            printf("\nFUNimation Productions, Ltd.");
		}
        if(br==4){
            printf("\nPyramid Books");
		}
    }
    else{
        printf("0");
	}
    return 0;
}
