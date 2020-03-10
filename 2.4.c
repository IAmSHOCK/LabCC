#include <stdio.h>

void esp(char *s)
{
	for(int i=0; i<strlen(s); i++)
	{
		if(!isalpha(s[i]) || !isdigit(s[i]))
		{
			s[i]=' ';
		}
	}
}

char *esp1(char*s)
{

}

int main(int argc, char const *argv[])
{
	
	return 0;
}