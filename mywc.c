#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//feito count stdin

int lines_total = 0;
int words_total = 0;
int chars_total = 0;

void count_stdin()
{
	int chars = 0;
	int lines = 0;
	int words = 0;

	char ch;
	char prev = '\n';

	while((ch = fgetc(stdin)) != EOF)
	{
		
		chars++;

		if(ch  == '\n') lines++;

		if(!isspace(prev) && (isspace(ch)) ) words++;

		prev = ch;
	}

	lines_total += lines;
	words_total += words;
	chars_total += chars;
	printf("%d %d %d \n", lines, words, chars );
}

void count(char *const *argv, int i)
{
	FILE *fp = fopen(argv[i], "r");
	if(fp == NULL) printf("./my_wc: %s: No such file or directory\n", argv[i]);

	int chars = 0;
	int lines = 0;
	int words = 0;

	char ch;
	char prev = '\n';

	while((ch = fgetc(fp)) != EOF)
	{
		
		chars++;

		if(ch  == '\n') lines++;

		if(!isspace(prev) && (isspace(ch)) ) words++;

		prev = ch;
	}

	lines_total += lines;
	words_total += words;
	chars_total += chars;
	printf("%d %d %d %s \n", lines, words, chars, argv[i] );
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
			count(argv, i);
		}
		else printf("./my_wc: %s: No such file or directory\n", argv[i]);
		i++;
	}

	if (argc > 2) printf("%d %d %d total", lines_total, words_total, chars_total);

	exit(0);
}