#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#define MAXSIZE 200
//feito

int print (char *const *argv, int i, int nFlag, int bFlag, int sFlag, int sum)
{
	char ch;
	char *str;
	char *ant;


	FILE* fp = fopen(argv[i], "r");
	if(fp==NULL)
	{
		printf("%s: No such file or directory \n", argv[i]);
		exit(1);
	}

	int n = 0;
	n += nFlag*100;
	n += bFlag*10;
	n += sFlag;

	switch(n)
	{
		case 100:
			str = (char *) malloc(MAXSIZE);

			while(fgets(str, MAXSIZE, fp) != NULL)
			{
				printf("%6d\t""%s", sum, str);
				sum++;
			}
			sum--;

			free(str);
			break;

		case 10:
			str = (char *) malloc(MAXSIZE);

			while(fgets(str, MAXSIZE, fp) != NULL)
			{
				if (*str == '\n')
				{
					printf("%s", str);
				}
				else
				{
					printf("%6d\t""%s", sum, str);
					sum++;
				}
			}
			sum--;

			free(str);
			break;

		case 1:
			str = (char *) malloc(MAXSIZE);
			ant = (char *) malloc(MAXSIZE);

			while(fgets(str, MAXSIZE, fp) != NULL)
			{
				if (*str == '\n' && *ant == '\n')
				{
					
				}
				else
				{
					printf("%s", str);
				}
				*ant = *str;
			}

			free(str);
			break;	

		case 11:
			str  = (char *) malloc(MAXSIZE);
			ant  = (char *) malloc(MAXSIZE);
			*ant = '\n';
			while(fgets(str, MAXSIZE, fp) != NULL)
			{
				if (*str == '\n' && *ant != '\n')
				{
					printf("\n");
				}
				else
				{
					if((*str != '\n' && *ant == '\n') || (*str != '\n' && *ant != '\n'))
					{
						printf("%6d\t""%s", sum, str);
						sum++;
					}
				}
				*ant = *str;
			}
			sum--;
			
			free(str);
			break;

		case 0:
			while((ch = fgetc(fp))!=EOF)
			{
				printf("%c", ch);
			}
			break;

		case 101:
			str = (char *) malloc(MAXSIZE);
			ant = (char *) malloc(MAXSIZE);

			while(fgets(str, MAXSIZE, fp) != NULL)
			{
				if (*str == '\n' && *ant == '\n')
				{
					
				}
				else
				{
					printf("%6d\t""%s", sum, str);
					sum++;
				}
				*ant = *str;
			}
			sum--;
			
			free(str);			
			break;			
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
	int nFlag = 0;
	int bFlag = 0;
	int sFlag = 0;

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
	while(i < argc)
	{
		if(argv[i][0] == '-')
		{
			print_stdin();
		}

		if(file_exists(argv,i))
		{
			current_sum += print(argv, i, nFlag, bFlag, sFlag, current_sum);
		}
		
		i++;
	}

	exit(0);
}