#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
//feito count stdin

int lines_total = 0;
int words_total = 0;
int chars_total = 0;
int bigger_line = 0;
int file_bigger_line = 0;

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
	if(!isspace(prev)) words++;

	lines_total += lines;
	words_total += words;
	chars_total += chars;
	printf("%d %d %d\n", lines, words, chars );
}

void count(char *const *argv, int i, int flag)
{
	FILE *fp = fopen(argv[i], "r");
	if(fp == NULL) 
		{
			printf("./my_wc: %s: No such file or directory\n", argv[i]);
			return;
		}

	int chars 		= 0;
	int lines 		= 0;
	int words 		= 0;
	int tmp_line    = 0;

	char ch;
	char prev = '\n';

	while((ch = fgetc(fp)) != EOF)
	{
		
		chars++;
		tmp_line++;
		if(ch  == '\n') 
			{
				lines++;
				if(tmp_line > bigger_line )bigger_line = tmp_line;
				tmp_line = 0;
			}

		if(!isspace(prev) && (isspace(ch)) ) words++;

		prev = ch;
	}
	bigger_line--;
	if(bigger_line > file_bigger_line) file_bigger_line = bigger_line;
	if(!isspace(prev)) words++;

	lines_total += lines;
	words_total += words;
	chars_total += chars;

	switch(flag)
	{
		case 0: case 111:
			printf("%d %d %d\n", lines, words, chars);
			break;
		case 1:
			printf("%d\n", chars);
			break;
		case 10:
			printf("%d\n", lines);
			break;
		case 11:
			printf("%d %d\n", lines, chars);
			break;
		case 110:
			printf("%d %d\n", lines, words);
			break;
		case 101:
			printf("%d %d\n", words, chars);
			break;
		case 100:
			printf("%d\n", words);
			break;
		case 1111:
			printf("%d %d %d %d\n", lines, words, chars, bigger_line);
			break;
		case 1110:
			printf("%d %d %d\n", lines, words, bigger_line);
			break;
		case 1101:
			printf("%d %d %d\n", words, chars, bigger_line);
			break;
		case 1100:
			printf("%d %d\n", words, bigger_line);
			break;
		case 1011:
			printf("%d %d %d\n", lines, chars, bigger_line);
			break;
		case 1010:
			printf("%d %d\n", lines, bigger_line);
			break;
		case 1001:
			printf("%d %d\n", chars, bigger_line);
			break;
		case 1000:
			printf("%d\n", bigger_line);
			break;
	}
}
int file_exists(char *const *argv, int i)
{
	FILE *fp = fopen(argv[i], "r");
	if(fp == NULL) return 0;
	fclose(fp);
	return 1;
} 

void print_total(int flag, int numFiles)
{
	if(numFiles >= 2)
	{
		switch(flag)
		{
			case 0: case 111:
				printf("%d %d %d total\n", lines_total, words_total, chars_total);
				break;
			case 1:
				printf("%d total\n", chars_total);
				break;
			case 10:
				printf("%d total\n", lines_total);
				break;
			case 11:
				printf("%d %d total\n", lines_total, chars_total);
				break;
			case 110:
				printf("%d %d total\n", lines_total, words_total);
				break;
			case 101:
				printf("%d %d total\n", words_total, chars_total);
				break;
			case 100:
				printf("%d total\n", words_total);
				break;
			case 1111:
				printf("%d %d %d %d total\n", lines_total, words_total, chars_total, bigger_line);
				break;
			case 1110:
				printf("%d %d %d total\n", lines_total, words_total, bigger_line);
				break;
			case 1101:
				printf("%d %d %d total\n", words_total, chars_total, bigger_line);
				break;
			case 1100:
				printf("%d %d total\n", words_total, bigger_line);
				break;
			case 1011:
				printf("%d %d %d total\n", lines_total, chars_total, bigger_line);
				break;
			case 1010:
				printf("%d %d total\n", lines_total, bigger_line);
				break;
			case 1001:
				printf("%d %d total\n", chars_total, bigger_line);
				break;
			case 1000:
				printf("%d total\n", file_bigger_line);
				break;
		}
	}
	
}
int main(int argc, char *const *argv)
{
	int i = 1;
	int numFiles;
	if(argc == 1)
	{
		count_stdin();
	}

	int flag = 0;
	int opt;
	while((opt = getopt(argc, argv, ":clwL")) != -1)
	{
		switch(opt)
		{
			case 'c':
				flag += 1;
				break;
			case 'l':
				flag += 10;
				break;
			case 'w':
				flag += 100;
				break;
			case 'L':
				flag += 1000;
				break;
		}
	}
	i = optind;
	
	numFiles = argc-i; 

	while(i < argc)
	{
		if(*argv[i] == '-')
		{
			count_stdin();
		}
		else
		{
			count(argv, i, flag);
		}
		
		i++;
	}

	print_total(flag, numFiles);
	exit(0);
}