#include <stdio.h>
#include <stdlib.h>
// feito ate ./my_cat file1 - file2 - file3

void print (char const *argv[], int i)
{
	char* text;
	text = (char*) malloc(50*sizeof(char));

	FILE* fp = fopen(argv[i], "r");
	if(fp==NULL)
	{
		printf("%s: No such file or directory \n", argv[i]);
		exit(0);
	}

	while(fgets(text, 50, fp)!=NULL)
	{
		printf("%s", text);
	}

	free(text);
	fclose(fp);
}

void print_stdin()
{
	char ch;
	while((ch = fgetc(stdin)) != EOF)
	{
		printf("%c", ch);
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
	int i=2;
	print(argv, 1);
	if(argc == 1)	
	{
		print_stdin();
	}

	while(i!=argc)
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

	return 0;
}