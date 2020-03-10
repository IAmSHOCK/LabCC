#include <stdio.h>
#include <string.h>

int tamanho(char *ch)
{
	int i=0;
	while(ch[i]!='\0')
	{
		i++;
	}
	return i;
}

int main(int argc, char *argv[])
{
	int i=1;
	while(i!=argc)
	{
		printf("%d\n", tamanho(argv[i++]));
	}
	return 0;
}