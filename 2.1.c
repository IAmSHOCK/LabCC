#include <stdio.h>
#include <ctype.h> 
int main(int argc, char *argv[])
{
	int soma = 0;

	for (int i = 1; i < argc; i++)
	{
		if(isdigit(*argv[i]))
			soma += *argv[i]-'0';
	}
	printf("%d\n", soma);
	return 0;
}