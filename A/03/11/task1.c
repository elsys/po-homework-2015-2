#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int month_valid;

  int remainder_from_check;
  int check;
  int month_number;
  int value_pos1;
  int value_pos2;
  int value_pos3;
  int value_pos4;
  int value_pos5;
  int value_pos6;
  int value_pos7;
  int value_pos8;
  int value_pos9;
  int value_pos10;
  char upn[12];
  // const char* upn = "";
  scanf("%s", upn);
  // printf("%s", upn);

  char *month;
  char *pos1;
  char *pos2;
  char *pos3;
  char *pos4;
  char *pos5;
  char *pos6;
  char *pos7;
  char *pos8;
  char *pos9;
  char *pos10;

  month = strndup(upn+2, 2);
  pos1 = strndup(upn, 1);
  pos2 = strndup(upn+1, 1);
  pos3 = strndup(upn+2, 1);
  pos4 = strndup(upn+3, 1);
  pos5 = strndup(upn+4, 1);
  pos6 = strndup(upn+5, 1);
  pos7 = strndup(upn+6, 1);
  pos8 = strndup(upn+7, 1);
  pos9 = strndup(upn+8, 1);
  pos10 = strndup(upn+9, 1);

  month_number = atoi(month);
  value_pos1 = atoi(pos1); 
  value_pos2 = atoi(pos2);
  value_pos3 = atoi(pos3);
  value_pos4 = atoi(pos4);
  value_pos5 = atoi(pos5);
  value_pos6 = atoi(pos6);
  value_pos7 = atoi(pos7);
  value_pos8 = atoi(pos8);
  value_pos9 = atoi(pos9);
  value_pos10 = atoi(pos10);

  if((month_number >= 1 && month_number <= 12) || (month_number >= 21 && month_number <= 32) || (month_number >= 41 && month_number <= 52))
  {
  	month_valid = 1;
  }

  check = (value_pos1 * 2) + (value_pos2 * 4) + (value_pos3 * 8) + (value_pos4 * 5) + (value_pos5 * 10) + (value_pos6 * 9) + (value_pos7 * 7) + (value_pos8 * 3) + (value_pos9 * 6);

  remainder_from_check = check % 11;

  if(remainder_from_check == 10)
  {
  	remainder_from_check = 0;
  }

  if((remainder_from_check == value_pos10) && (month_valid == 1))
  {
  	printf("1");
  }
  
  else
  {
  	printf("0");
  }


  return 0;
}
