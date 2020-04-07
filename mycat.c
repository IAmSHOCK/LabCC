#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#define MAXSIZE 200
//feito ate -n

int print (char *const *argv, int i, int nFlag, int sum)
{
	char ch;

	FILE* fp = fopen(argv[i], "r");
	if(fp==NULL)
	{
		printf("%s: No such file or directory \n", argv[i]);
		exit(1);
	}

	if(nFlag == 1)
	{
		char *str;
		str = (char *) malloc(MAXSIZE);

		while(fgets(str, MAXSIZE, fp) != NULL)
		{
			printf("%6d\t""%s", sum, str);
			sum++;
		}
		sum--;

		free(str);
	}
	else
	{ 
		while((ch = fgetc(fp))!=EOF)
		{
			printf("%c", ch);
		}
	}

	fclose(fp);
	return sum;
}

void print_stdin()
{
	char ch;
	int i=0;
	while((ch = fgetc(stdin)) != EOF)
	{
		printf("%c", ch);
		i++;
	}
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
	int nFlag 	= 0;
	int bFlag 	= 0;
	int sFlag 	= 0;

	int i = 1;
	if(argc == 1)	
	{
		print_stdin();
	}

	int current_sum = 1;
	int opt;
	while((opt = getopt(argc, argv, ":nbs")) != -1)
	{
		switch(opt)
		{
			case 'n':
				nFlag = 1;
				break;
			case 'b':
				bFlag = 1;
				break;
			case 's':
				sFlag = 1;
				break;
		}
	}

	i = optind;
	while(i<argc)
	{
		if(argv[i][0] == '-')
		{
			print_stdin();
		}

		if(file_exists(argv,i))
		{
			current_sum += print(argv, i, nFlag, current_sum);
		}
		
		i++;
	}

	exit(0);
}