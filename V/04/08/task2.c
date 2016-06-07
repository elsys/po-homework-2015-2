#include <stdio.h>
#include <string.h>

 void pr(int a)
 {
switch(a)
{
	case 0:	printf("%s\n","Door: CLOSED" );	break;
	case 1:	printf("%s\n","Door: OPENING" );	break;
	case 2:	printf("%s\n","Door: OPEN" );	break;
	case 3:	printf("%s\n","Door: CLOSING" );	break;
	case 4:	printf("%s\n","Door: STOPPED_WHILE_CLOSING" );	break;
	case 5:	printf("%s\n","Door: STOPPED_WHILE_OPENING" );	break;
}

 }

int main()
{
	char state=0;
	char c[200]={0};
	//printf("%s\n","CLOSED" );
	pr(0);
	while(scanf("%s", c)!=EOF)
	{
		if(!strcmp(c,"cycle_complete" ))
		{
			//puts("cc");
			switch(state)
			{
				case 1:	state=2;pr(2); break;
				case 3: state=0;pr(0); break;

				case 0: state=0;pr(0); break;
				case 2: state=2;pr(2); break;

				case 4:  break;
				case 5:  break;
 				
			}
		}		
	/*
button_clicked и cycle_complete.

 CLOSED 0, OPENING 1, OPEN 2 , CLOSING 3 , STOPPED_WHILE_CLOSING 4, STOPPED_WHILE_OPENING 5
	*/


		if(!strcmp(c,"button_clicked"))
		{
			//puts("sssss");
			switch(state)
			{
				case 1:	state=5; pr(state); break;
				case 3: state=4;pr(state); break;

				case 0: state=1;pr(state); break;
				case 2: state=3;pr(state); break;

				case 4: state=1;pr(state); break;
				case 5: state=3;pr(state); break;
			}
		}		

	}
	/*
button_clicked и cycle_complete.

 CLOSED 0, OPENING 1, OPEN 2 , CLOSING 3 , STOPPED_WHILE_CLOSING 4, STOPPED_WHILE_OPENING 5
	*/

	
	return 0;
}