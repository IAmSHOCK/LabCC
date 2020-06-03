#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

#define MAXSIZE 512
#define TRUE 1
#define FALSE 0

int b_flag  = FALSE;
int d_flag  = FALSE;
int f_flag  = FALSE;
int n;
char *list;
char *delim;

void buscar_pos(int *virgulas, int j, int last_number, char *const *argv, int *pos)
{
	int tmp;
	int i = 0;
	int incr;
	int k;
	int prev = -1;
	int virgula_flag = FALSE;
	while(i < strlen(argv[2]))
	{
		if(argv[2][i] == ',') virgula_flag = TRUE;
		i++;
	}

	if(virgula_flag)
	{
		while(i < j)
		{
			incr = 1;
			tmp = 0;
			k = virgulas[i]-1; // ultima posiçao antes da virgula
			while(k > prev)
			{
				tmp += (argv[2][k]-'0') * incr; 
				k--;
				incr *= 10;
			}
			prev = virgulas[i];
			pos[i] = tmp;
			i++;
		}
		tmp = 0;
		incr = 1;
		k = virgulas[i-1];
		while(last_number > k)
		{
			tmp += (argv[2][last_number]-'0') * incr;
			last_number--;
			incr *= 10;
		}
		pos[i] = tmp;
		n = i;
	}
	else
	{
		pos[i] = atoi(argv[2]);
		n = 0;
	}
	
}

void cut_stdin(char *const *argv)
{
	char ch;
	// char line[MAXSIZE];
	int virgulas[MAXSIZE];
	int pos[MAXSIZE];
	int i = 0;
	int j = 0;

	while(i < strlen(argv[2]))
	{
		if(argv[2][i] == ',') 
		{
			virgulas[j] = i;
			j++;
		}
		i++;
	}
	int last_number = i-1;
	buscar_pos(virgulas, j, last_number, argv, pos);
	
	if(b_flag && d_flag && f_flag)
	{
		while((ch = fgetc(stdin)) != EOF)
		{
			
		}
	}

	else if(f_flag && d_flag)
	{
		
	}

	else if(b_flag)
	{
		
	}
}



void cut(char *const *argv, int i)
{
	FILE *fp = fopen(argv[i], "r");
	if(fp == NULL) 
		{
			printf("./my_wc: %s: No such file or directory\n", argv[i]);
			return;
		}
	char ch;
	char *line = NULL;
	int virgulas[MAXSIZE];
	int pos[MAXSIZE];
	i = 0;
	int j = 0;
	size_t len = 0;
	int nread;
	// char delim = argv[1][2];

	while(i < strlen(argv[2]))
	{
		if(argv[2][i] == ',') 
		{
			virgulas[j] = i;
			j++;
		}
		i++;
	}
	int last_number = i-1;
	buscar_pos(virgulas, j, last_number, argv, pos);
	
	if(b_flag && d_flag && f_flag)
	{
		while((ch = fgetc(stdin)) != EOF)
		{
			
		}
	}

	else if(f_flag && d_flag)
	{
		
	}

	else if(b_flag)
	{
		i = 0;
		while ((nread = getline(&line, &len, fp)) != -1)
		{
			while(i < strlen(line))
			{
				if(line[i] == '\n') printf("\n");
				else
				{
					while(j <= n)
					{
						if(line[i] == pos[j]) printf("%c", line[i]);
						j++;
					}
				}	
				i++;
			}
		}
	}
}


int main(int argc, char *const *argv)
{
	
	int i = 1;
	int opt;
	while((opt = getopt(argc, argv, ":b:d:f:")) != -1)
	{
		switch(opt)
		{
			case 'b':
				b_flag = TRUE;
				list = optarg;
				break;
			case 'd':
				d_flag = TRUE;
				delim = optarg;
				break;
			case 'f':
				f_flag = TRUE;
				list = optarg;
				break;
		}
	}

	i = optind;
	i++;
	while(i < argc)
	{
		if(*argv[i] == '-')
		{
			cut_stdin(argv);
		}
		else
		{
			cut(argv, i);
		}
		
		i++;
	}

	exit(0);
}