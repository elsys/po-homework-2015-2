#include <stdio.h>
int main()

{

  char s[12];
  
  int EGN[12];
  int sum=0,i;
  int teglo[9]={2,4,8,5,10,9,7,3,6};
  int dati[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  
  
  scanf("%s",s);
  //---------proverka za simvoli --------
  
  
  for(i=0;i<10;i++)
  {
  	if(s[i]<'0' || s[i]>'9')
  	{
  		printf("\n0");
  		//printf("\n proverka na simvoli");
  		return 0;
        }
          
  }
  
  for(i=0;i<10;i++)
  {
      EGN[i]=s[i]-'0';
  }
  

 //---------- proverka na kontrolno chislo
 
  for(i=0;i<9;i++)
  {
     
     sum=sum+teglo[i]*EGN[i];
     
     
  }
  
  sum=sum % 11;
  if(sum<10)
  {
  	if(EGN[9] != sum)
  	{
  		printf("\n0");
  		return 0;
  	}
  	
  }else{
  
  	if(EGN[9] != '0')
  	{
  		printf("\n0");
  		return 0;
  	}
  
  }
  
  //---------proverka za dati
  
  int mes,den,god;
  
  god=EGN[0]*10+EGN[1];
  den=EGN[4]*10+EGN[5];
  mes=EGN[2]*10+EGN[3];
  
  if(god % 4 == 0){dati[1]=29;}
  if(mes>20 && mes<33){mes=mes-20;}
  if(mes>40 && mes<53){mes=mes-40;}
  
  if(den>dati[mes-1] || den<1)
  {
  	printf("\n0");
        return 0;
  }
   if(mes<1 || mes>12)
   {
   printf("\n0");
        return 0;
   }    
       
  
  
    
printf("\n1"); 
return 0;  
}
