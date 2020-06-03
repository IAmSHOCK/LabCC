#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
char *string0;
char *string1;

int print (char *const *argv, int i)
{
	int pos[50];
	char ch;
	char *curr;
	FILE* fp = fopen(argv[i], "r");
	if(fp==NULL)
	{
		printf("%s: No such file or directory \n", argv[i]);
		exit(1);
	}
	char *line = NULL;
	size_t len = 0;
	int nread;
	int j, k, l;
	while ((nread = getline(&line, &len, fp)) != -1)
	{
		j = 0;
		k = 0;
		while(line[k] != '\0')//verificar para a linha toda
		{
			if(line[k] == string1[j]) //encontrar primeiro char da word
			{
				i = 0;
				j++;
				l = k+1;
				while(string1[j] != '\0') //encontrar os restantes chars
				{
					if(line[l] == string1[j])
					{
						pos[i] 
					}
					else 
					{
						found_flag = 0;
						break;
					}
					j++;
					l++;
				}
				if(found_flag)
				{
					fwrite(line, nread, 1, stdout);
					break;
				}
			}
	}
	fclose(fp);
}

void print_stdin()
{
	char ch;
	int i = 0;
	while((ch = fgetc(stdin)) != EOF)
	{
		printf("%c", ch);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	string0 = *argv[1];
	string1 = *argv[2];
	int i = 3;
	if(argc == 2)
	{
		print_stdin();
	}
	else
	{
		while(i < argc)
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
	}
	exit(0);
}