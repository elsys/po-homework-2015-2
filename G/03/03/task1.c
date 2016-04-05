#include <stdio.h>
#include <stdlib.h>

int t_month(int *box,int month)
{

  int check = 0;

  while(check != 2)
  {

    if(month>=1 && month<=12)
      {
	      return 1;	
  
      }
    else 
      {	

        return 0 ;
      }

  }
return 0 ;
}

int t_day(int month,int *box,int day)
{

  int mst;



  switch(month)
    {


      case 1:
        mst = 31;
        break;
      case 2:
        mst = 29;
        break;
      case 3:
        mst = 31;
        break;
      case 4:
        mst = 30;
        break;
      case 5:
        mst = 31;
        break;
      case 6:
        mst = 30;
        break;
      case 7:
        mst = 31;
        break;
      case 8:
        mst = 31;
        break;
      case 9:
        mst = 30;
        break;
      case 10:
        mst = 31;
        break;
      case 11:  
        mst = 30;
        break;
      case 12:
        mst = 31;
        break;

    }

  if(day >= 1 && day <= mst)
    {
      return 1;
    }

      return 0;

}

int t_digit(int *box)
{

int sum;

sum = (box[9]*2)+(box[8]*4)+(box[7]*8)+(box[6]*5)+(box[5]*10)+(box[4]*9)+(box[3]*7)+(box[2]*3)+(box[1]*6);


  if(sum%11 == box[0])
    {
      return 1 ;
    }
  else 
    {
      return 0;
    }

}

int main()
{
    unsigned long int  enter;
    int box[12] = {0};
    int i;
	  int month;
	 int day;

   scanf("%lu",&enter);
    
    while(enter != 0 )
    {
       if(i < 10 )
        {
            box[i] = enter%10;
            enter= enter/10;
            i++;

        }
       else
       {
       	    printf("0\n");
            return 0 ;
       }
    }


	month = (box[7]*10)+box[6];
	day = (box[5]*10) + box[4];

if(month > 40)
  {
    month = month - 40 ; 
  }
if(month> 20 )
  {
    month = month -20; 
  }

 

if(t_month(box,month)== 1 && t_day(month,box,day) == 1 && t_digit(box) == 1)
  {
    printf("1\n");
  }
else
  {
    printf("0\n");
  }
   

   return 0;
}

