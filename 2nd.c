#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

int n = 0;
int m = 0;
void print (char const *argv[], int n, int m)
{
	char *line = NULL;
	size_t len = 0;
	int nLines = 0;
	FILE* fp = fopen(argv[3], "r");
	int i = 0;
	while(getline(&line, &len, fp) != -1)
	{
		nLines++;
		if(nLines >= n && nLines < m)
		{
			while(i < strlen(line))
			{
				printf("%c", line[i]);
				i++;
			}
			i = 0;
		}	
	}
	fclose(fp);
}

void print_stdin(int n, int m)
{
	char *line = NULL;
	size_t len = 0;
	int nLines = 0;
	int i = 0;
	while(getline(&line, &len, stdin) != -1)
	{
		nLines++;
		if(nLines >= n && nLines < m)
		{
			while(i < strlen(line))
			{
				printf("%c", line[i]);
				i++;
			}
			i = 0;
		}	
	}
}

int main(int argc, char const *argv[])
{
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	if (n > m) printf("Argumentos trocados?\n");
	if(argc == 3)
	{
		print_stdin(n, m);
	}
	else
	{
		print(argv, n, m);
	}
	return 0;
}