#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int length_t(int  *box, char *help)
{
    int ct= 0 ;
    int i= 0 ;
    while(help[i]!='\0')
    {

       if(help[i]!= '-')
       {

           switch(help[i])
           {
           case 48:
               box[ct] = 0;
               break;
           case 49:
               box[ct] = 1;
               break;
           case 50:
               box[ct] = 2;
               break;
           case 51:
               box[ct] = 3;
               break;
           case 52:
               box[ct] = 4;
               break;
            case 53:
                box[ct] = 5;
               break;
            case 54:
                box[ct] = 6;
               break;
            case 55:
                box[ct] = 7;
               break;
            case 56:
                box[ct] = 8;
               break;
            case 57:
                box[ct] = 9;
               break;

           }
           ct ++ ;
       }
       i++;
    }
      return ct;

}

int begin_t(int  *box)
{
    if((box[0] == 9 && box[1] == 7 && box[2] == 8) || (box[0] == 9 && box[1] == 7 && box[2] == 9))
    {

        return 1 ;
    }
    return 0 ;
}

int name_t(char * help,char *bb,char *ab,char * fp,char*pb)
{
    int i= 6;
    int b;



    if(help[i]== 57 && help[i+1]== 51&& help[i+2]== 51 && help[i+3]== 51 &&help[i+4]== 52 &&help[i+5]== 54 && help[i+6] == '-')
    {
        return b= 1 ;
    }
    if(help[i]== 53 &&help[i+1]== 53 && help[i+2]== 53 && help[i+3]== 56 && help[i+4] == 51 && help[i+5] == '-')
    {

        return b = 2 ;
    }
    if(help[i]== 52 &&help[i+1]== 50 && help[i+2]== 49 && help[i+3]== 48 && help[i+4] == '-')
    {
        return b = 3 ;
    }
    if(help[i]== 48 &&help[i+1]== 49 && help[i+2] == '-')
    {
        return b = 4;
    }
    return 0;
}

int check_sum(int *box)
{

    int sax[200] = {1,3,1,3,1,3,1,3,1,3,1,3};
    int minc;
    int score=0;

    for(minc = 0 ; minc < 12; minc ++)
    {

        score = score +(sax[minc] * box[minc] );
    }

    score = score%10;
    score = 10 - score;

    if(score == box[12])
    {
        return 1 ;
    }

        return 0;

}

int main()
{

int box[15]  = {0};
char help[200];

char bb[100] ={"Bluebridge"};

char ab[100] = {"Alyson Books"};

char fp[100] = {"FUNimation Productions, Ltd."};

char pb[100] = {"Pyramid Books"};


scanf("%[^\n]",help);


 if(length_t(box,help) == 13 && begin_t(box)== 1 && check_sum(box) == 1  )
 {
     printf("1\n");

        switch(name_t(help,bb,ab,fp,pb))
        {
    case 1 :
        printf("%s\n",bb);
        break;
    case 2 :
        printf("%s\n",ab);
        break;
    case 3 :
        printf("%s\n",fp);
        break;
    case 4:
        printf("%s\n",pb);
        break;

        }


 }
 else
 {
     printf("0\n");
 }


    return 0;
}
