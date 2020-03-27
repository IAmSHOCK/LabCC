#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
// ponto 1 feito

void print (char const *argv[], int i)
{
	char ch;

	FILE* fp = fopen(argv[i], "r");
	if(fp==NULL)
	{
		printf("%s: No such file or directory \n", argv[i]);
		exit(1);
	}

	while((ch = fgetc(fp))!=EOF)
	{
		printf("%c", ch);
	}

	fclose(fp);
}

void print_stdin()
{
	char ch;
	int i=0;
	while((ch = fgetc(stdin)) != EOF)
	{
		if(i==0) printf("\n");
		printf("%c", ch);
		i++;
	}
}

int file_exists(char const *argv[], int i)
{
	FILE *fp = fopen(argv[i], "r");
	if(fp == NULL) return 0;
	fclose(fp);
	return 1;
} 

int main(int argc, char const *argv[])
{
	int i=1;
	if(argc == 1)	
	{
		print_stdin();
	}

	while(i<argc)
	{
		if(argv[i][0] == '-')
		{
			print_stdin();
		}

		if(file_exists(argv,i))
		{
			print(argv, i);
		}
		
		i++;
	}

	exit(0);
}