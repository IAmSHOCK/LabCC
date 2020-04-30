#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFloat(double FIRST, double INCREMENT, double LAST)
{
	if(INCREMENT < 0)
	{
		for (float i = FIRST; i >= LAST; i += INCREMENT)
		{
			printf("%.2lf\n", i);
		}
	}
	else
	{
		for (float i = FIRST; i <= LAST; i = i + INCREMENT)
		{
			printf("%.2lf\n", i);
		}
	}
	
}
void printInt(int FIRST, int INCREMENT, int LAST)
{
	if(INCREMENT < 0)
	{
		for (int i = FIRST; i >= LAST; i += INCREMENT)
		{
			printf("%d\n", i);
		}
	}
	else
	{
		for (int i = FIRST; i <= LAST; i += INCREMENT)
		{
			printf("%d\n", i);
		}
	}
	
}


int main(int argc, char const *argv[])
{
	switch(argc)
	{
		case 2:
		{
			int FIRST	  = 1;
			int INCREMENT = 1;
			int LAST = atoi(argv[1]);
			printInt(FIRST, INCREMENT, LAST);
			break;		
		}


		case 3:
		{
			int FIRST	  = atoi(argv[1]);
			int INCREMENT = 1;
			int LAST = atoi(argv[2]);\
			printInt(FIRST, INCREMENT, LAST);
			break;			
		}

			
		case 4:
		{
			if(strchr(argv[2], '.') == NULL)
			{
				int FIRST 	  = atoi(argv[1]);
				int LAST  	  = atoi(argv[3]);
				int INCREMENT = atoi(argv[2]);
				printInt(FIRST, INCREMENT, LAST);
			}
			else
			{
				double FIRST		= strtof(argv[1], NULL);
				double LAST 		= strtof(argv[3], NULL);
				double INCREMENT 	= strtof(argv[2], NULL);
				printFloat(FIRST, INCREMENT, LAST);
			}
			break;		
		}	
	}
	exit(0);
}  