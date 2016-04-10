#include <stdio.h>
#include <string.h>


int main()

{
    char  v[10];
    int chislo,n,i,p,bk=0,sum,j;
    char min='-';
    char plus='+';
    
    do{
    
    scanf("%s",v);
    
    }while(strlen(v)>10 || strlen(v)<2);
    
    
    
    scanf("%d",&chislo);
    n=strlen(v);
    
        
    char z[n-1];
    
 // --------inicializaciq
    
    for(i=0;i<=n-2;i++)
    {
        z[i]=min;
    }
    
 //---------------------------   
    p=1;
    for(i=1;i<=n-1;i++){ p=p*2; }
    
    
    
for(j=1;j<=p-1;j++)
{	
 
//    -------------- izbor na komb----
    i=n-2;
    while(i>=0)
    {if(z[i]==plus)
        {z[i]=min; i=i-1;}
      else
      {z[i]=plus; break;}
     }
     
//------------izchislqvane---------
    sum=v[0]-'0';
    
    for(i=0;i<=n-2;i++)	
    {
       if (z[i]==plus){sum=sum+(v[i+1]-'0');}
       		
       else {sum=sum-(v[i+1]-'0');}
       		
    }    
    //printf("\nsum=%d",sum);
// -------printirane na kombinacii-------------   
    if(sum==chislo)
    {
    bk++;
    printf("\n%c",v[0]);
    for(i=0;i<=n-2;i++)
    { 
    	if(z[i]==plus) printf("+");
    	else printf("-");
    
    printf("%c",v[i+1]);
        
    }
    printf("=%d",sum);
    }
//-------------------------------------

}
    if(bk==0){printf("-1");}




return 0;
}
