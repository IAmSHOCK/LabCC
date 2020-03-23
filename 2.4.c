#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void esp(char *s)
{
	for(int i=0; i<strlen(s); i++)
	{
		if(!isalpha(s[i]) && !isdigit(s[i]))
		{
			s[i]=' ';
		}
	}
}

char* esp1(char*s)
{
	char str[strlen(s)];
	char* final;
	int j,i;
	for(i=0; i<strlen(s); i++)
	{
		str[i] = s[i];
	}
	str[i]='\0';
	esp(str);
	final = (char*) malloc(strlen(str) *sizeof(char));
	if(final == NULL) 
	{
		printf("malloc unsucessfull.\n");
		exit(1);
	}
	for(j=0; j<strlen(str); j++)
	{
		final[j]=str[j];
	}
	return final;
}

int main(int argc, char const *argv[])
{
	char str[] = "a, Ah Ah!";
	char* final;
	final = esp1(str);
	printf("%s", final);
	free(final);
	return 0;
}