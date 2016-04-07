#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test();
void check();

int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, expected = 0, ii = -1, count = 0;
char input[10] = { "aaaaaaaaaa" };

int main()
{
	scanf("%s %d",input,&expected);
	
	for(int ij = 0 ; ij<10 ; ij ++)
	{
		if(input[ij] != 'a')
		{
			ii++;
			if(input[ij] != '\0') input[ij] -= '0';
		}
		else input[ij] -= 'a';
	}

	check();

	if(count == 0) printf("-1\n");
	
	return 0;
}

void test()
{
	char res[20] = { 0 }, old[20] = { 0 };
	int result = input[0];
	if(ii >= 2) { if(a) result += input[1]; else result -= input[1]; }
	if(ii >= 3) { if(b) result += input[2]; else result -= input[2]; }
	if(ii >= 4) { if(c) result += input[3]; else result -= input[3]; }
	if(ii >= 5) { if(d) result += input[4]; else result -= input[4]; }
	if(ii >= 6) { if(e) result += input[5]; else result -= input[5]; }
	if(ii >= 7) { if(f) result += input[6]; else result -= input[6]; }
	if(ii >= 8) { if(g) result += input[7]; else result -= input[7]; }
	if(ii >= 9) { if(h) result += input[8]; else result -= input[8]; }
	if(ii == 10) { if(i) result += input[9]; else result -= input[9]; }

	if(result == expected)
	{
		count++;
		sprintf(res,"%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d",input[0],((a) ? '+' : '-'),input[1],((b) ? '+' : '-'),input[2],((c) ? '+' : '-'),input[3],((d) ? '+' : '-'),input[4],((e) ? '+' : '-'),input[5],((f) ? '+' : '-'),input[6],((g) ? '+' : '-'),input[7],((h) ? '+' : '-'),input[8],((i) ? '+' : '-'),input[9]);
		if(strcmp(res, old) != 0) printf("%.*s=%d\n", 2*ii-1, res, expected);
		strcpy(old,res);
	}
}

void check()
{
	if(ii > 1) for(a = 0 ; a < 2 ; a++)
	{
		if(ii > 2) for(b = 0 ; b < 2 ; b++)
		{
			if(ii > 3) for(c = 0 ; c < 2 ; c++)
			{
				if(ii > 4) for(d = 0 ; d < 2 ; d++)
				{
					if(ii > 5) for(e = 0 ; e < 2 ; e++)
					{
						if(ii > 6) for(f = 0 ; f < 2 ; f++)
						{
							if(ii > 7) for(g = 0 ; g < 2 ; g++)
							{
								if(ii > 8) for(h = 0 ; h < 2 ; h++)
								{
									if(ii > 9) for(i = 0 ; i < 2 ; i++)
									{
										test();
									}
									else test();
								}
								else test();
							}
							else test();
						}
						else test();
					}
					else test();
				}
				else test();
			}
			else test();
		}
		else test();
	}
	else
	{
		printf("%d\n", input[0]);
		count++;
	}
}