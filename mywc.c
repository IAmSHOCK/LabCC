#include <stdio.h>

void count_stdin()
{
	int chars = 0;
	int lines = 0;
	int words = 0;

	char ch;
	char ant = ' ';

	while((ch = fgetc(stdin)) != EOF)
	{
		if(ant == ' ') words++;
		if(ch == '\n') lines++;
		else if(ch != ' ' && ch != '\t') chars++;

		ant = ch;
	}	
	printf("%d %d %d \n", lines, words, chars );
}

void count()
{

}

int file_exists(char *const *argv, int i)
{
	FILE *fp = fopen(argv[i], "r");
	if(fp == NULL) return 0;
	fclose(fp);
	return 1;
} 

int main(int argc, char *const *argv)
{
	int i = 1;

	if(argc == 1)
	{
		count_stdin();
	}

	while(i < argc)
	{
		if(*argv[i] == '-')
		{
			count_stdin();
		}

		if(file_exists(argv, i))
		{
			count();
		}
		else printf("./my_wc: %s: No such file or directory\n", argv[i]);
	}


	return 0;
}