#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i=1;
	while(i!=argc)
	{
		printf("%ld\n", strlen(argv[i++]));
	}
	return 0;
}