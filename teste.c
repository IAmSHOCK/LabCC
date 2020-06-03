#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>

int n;
int first = 1;
int last;
int incr = 1;

int main(int argc, char const *argv[])
{
	n = atoi(argv[1]);
	if(argc == 3)
	{

		last = atoi(argv[2]);
	}
	else 
	{
		if(argc == 4)
		{
			first = atoi(argv[2]);
			last  = atoi(argv[3]);
		}
		else
		{
			first = atoi(argv[2]);
			incr  = atoi(argv[3]);
			last  = atoi(argv[4]);
		}
	}	
	if(first < last)
	{
		for (; first <= last; first += incr)
		{
			printf("%d\n", first%n);
		}
	}
	else
	{
		incr = -incr;
		for (; first >= last; first -= incr)
		{
			printf("%d\n", first%n);
		}
	}
	return 0;
}