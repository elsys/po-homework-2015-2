#include <stdio.h>
#include <string.h>

struct ibsn_t {
char prefix[4];
   char rg[5];
   char re[7];
   char pe[6];
   char cd;   
   } ibsn;
  

int main()

{
    int i,k=0,j=0,sum=0,n=0;

    char str[20];
    int teglo[12]={1,3,1,3,1,3,1,3,1,3,1,3};

   
    
    scanf("%s",str);
    
    for(i=0;i<strlen(str);i++)
    {
         if(str[i]!='-')
         {
            switch(k){
            
            case 0 :
            
               ibsn.prefix[j]=str[i];
               //printf("%c",prefix[j]);                            
               break;
            case 1 :           
              ibsn.rg[j]=str[i];                          
              break;
            case 2:         
              ibsn.re[j]=str[i];              
              break;
            case 3:               
              ibsn.pe[j]=str[i];             
              break;
            case 4:
              
              ibsn.cd=str[i];
              
         }
             j++;
             if(k!=4)
             {
                  n=str[i]-'0';
                  
                  sum=sum+n*teglo[i-k];
             }
           
            
            }else if(str[i]=='-')
         
         {
             k++;
             j=0;
         
         }
    
      }
      
 
sum=10-sum % 10;
n=strlen(ibsn.prefix)+strlen(ibsn.re)+strlen(ibsn.rg)+strlen(ibsn.pe)+1;
//printf("\ncd=%d",ibsn.cd);
//printf("\nsum=%d",sum);

if ((ibsn.cd-'0' == sum) && (strcmp(ibsn.prefix,"978")==0 || strcmp(ibsn.prefix,"979")==0)&& k==4 && n==13)
{
    printf("\n1");
    
    
    
     if(strcmp(ibsn.re,"933346")==0){ printf("\nBluebridge");} 
     
     if(strcmp(ibsn.re,"55583")==0){ printf("\nAlyson Books");} 
     
     if(strcmp(ibsn.re,"4210")==0){ printf("\nFUNimation Productions, Ltd.");} 
     
     if(strcmp(ibsn.re,"01")==0) {printf("\nPyramid Books");} 
   
   
          
 
}else printf("\n0");

//printf("%s %s %s %s %c",ibsn.prefix,ibsn.rg,ibsn.re,ibsn.pe,ibsn.cd);
//printf("\n%d",sum);



return 0;

}
