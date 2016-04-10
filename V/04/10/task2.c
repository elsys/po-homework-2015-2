#include <stdio.h>
#include <string.h>

struct d_t{
  char door[25];
  };
  
struct c_t{
  char command[18];  
  };

int main()
{
   struct d_t gate[6];
   struct c_t com[2];
   strcpy(gate[0].door,"closed");
   strcpy(gate[1].door,"opening");
   strcpy(gate[2].door,"closing");
   strcpy(gate[3].door,"open");
   strcpy(gate[4].door,"stopped_while_closing");
   strcpy(gate[5].door,"stopped_while_opening");
   
   strcpy(com[0].command,"button_clicked");
   strcpy(com[1].command,"cycle_complete");
   
   char input[14];
   int commands[1000];
   
   int status=0;
   int i=0,j;
   
  while(scanf("%s",input) !=EOF )
  {
    if(strcmp(input,com[0].command)==0)
    {
      commands[i]=0;
      i++;
      //printf("\n%d",commands[i]);
      
    }else if(strcmp(input,com[1].command)==0)
    
	{commands[i]=1;
	i++;
	//printf("\n%d",commands[i]); 
   
   }
  }
  
  printf("\nDOOR: %s",gate[status].door);
  
  for(j=0;j<i;j++)
  {
     if(commands[j]==0)
    {
       switch(status){
       
       case 0: status=1;break;
       case 1: status=5;break;
       case 2: status=4;break;
       case 3: status=2;break;
       case 4: status=1;break;
       case 5: status=2;break;
      }
    } 
  else if(commands[j]==1)
  {
   switch(status)
    {
  	
  	case 1: status=3;break;
  	case 2: status=0;break;
    }
  }
      printf("\nDOOR: %s",gate[status].door);
    
  }
  
return 0;
}
