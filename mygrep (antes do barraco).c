#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <ctype.h>


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

void search(char word[], char* const *argv, int i, int flag)
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

	switch (flag)
	{
		case 0:
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
							if(line[l] == word[j]) found_flag = 1;
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
			break;
		case 1:
			while((nread = getline(&line,&len,fp)) != -1)
			{
				j = 0;
				k = 0;
				while(line[k] != '\n')
				{
					if(isupper(line[k])) line[k] = tolower(line[k]);
					k++;
				}

				while(j < strlen(word))
				{
					if(isupper(word[j]) word[j]) = tolower(word[j]);
					j++;
				}
				k = 0;
				j = 0;
				while(line[k] != '\0')//verificar para a linha toda
				{
					
					if(line[k] == word[j]) //encontrar primeiro char da word
					{
						j++;
						l = k+1;
						while(word[j] != '\0') //encontrar os restantes chars
						{
							if(line[l] == word[j]) found_flag = 1;
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
			break;
		case 10:
			break;
		case 11:
			break;
		case 110:
			break;
		case 111:
			break;	
		case 101:
			break;
		case 100:
			break;
		case 1111:
			break;
		case 1110:
			break;
		case 1101:
			break;
		case 1100:
			break;
		case 1011:
			break;
		case 1010:
			break;
		case 1001:
			break;
		case 1000:
			break;
	}

	
	free(line);
	fclose(fp);
}

int main(int argc, char* const *argv)
{
	int i = 1;
	int flag = 0;
	int opt;
	char word[255];
		
	while((opt = getopt(argc, argv, ":ivlc")) != -1)
	{
		switch(opt)
		{
			case 'i':
				flag += 1;
				break;
			case 'v':
				flag += 10;
				break;
			case 'l':
				flag += 100;
				break;
			case 'c':
				flag += 1000;
				break;
		}
	}

	i = optind;
	strcpy(word, argv[i++]);
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
			search(word, argv, i, flag);
		}
		i++;
	}
	exit(0);
}