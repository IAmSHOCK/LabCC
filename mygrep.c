#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>


void search_stdin(char word[])
{
	char *line = NULL;
	int j;
	int k;
	int l;
	//int exit_flag  = 1;
	int found_flag = 0;
	int nread;
	size_t len = 0;
	while((nread = getline(&line,&len,stdin)) != -1)
	{
		j = 0;
		k = 0;
		while(line[k] != '\0')//verificar para a linha toda
		{
			if(line[k] == word[j]) //encontrar primeiro char da word
			{
				j++;
				l = k+1;
				while(word[j] != '\0') //encontrar os restantes chars
				{
					if(line[l] == word[j])
					{
						found_flag = 1;
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
					//exit_flag = 0;
					break;
				}
			}
			j = 0;
			k++;
		}
	}
	free(line);
}

void search(char word[], char const *argv[], int i)
{
	char *line = NULL;
	int j;
	int k;
	int l;
	//int exit_flag  = 1;
	int found_flag = 0;
	int nread;
	size_t len = 0;
	FILE *fp = fopen(argv[i], "r");
	if(fp == NULL) 
		{
			printf("./my_grep: %s: No such file or directory\n", argv[i]);
			exit(2);
		}
	while((nread = getline(&line,&len,fp)) != -1)
	{
		j = 0;
		k = 0;
		while(line[k] != '\0')//verificar para a linha toda
		{
			if(line[k] == word[j]) //encontrar primeiro char da word
			{
				j++;
				l = k+1;
				while(word[j] != '\0') //encontrar os restantes chars
				{
					if(line[l] == word[j])
					{
						found_flag = 1;
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
					//exit_flag = 0;
					break;
				}
			}
			j = 0;
			k++;
		}
	}
	free(line);
	fclose(fp);
}

int main(int argc, char const *argv[])
{
	int i = 2;
	char word[255];
	strcpy(word, argv[1]);
	
	if(argc == 2)
	{
		search_stdin(word);
	}
	while(i < argc)
	{
		if(*argv[i] == '-')
		{
			search_stdin(word);
		}
		else
		{
			search(word, argv, i);
		}
		i++;
	}
	exit(0);
}