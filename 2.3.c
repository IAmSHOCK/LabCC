#include <stdio.h>

FILE *fr, *fp;

int countchar(FILE *fr)
{
	int soma = 0;
	char ch;
	while((ch=fgetc(fr))!=EOF)
	{
		if(ch!=' ' && ch!='\n')
		soma++;
	}
	return soma;
}

int main(int argc, char const *argv[])
{
	
	fr = fopen(argv[1], "r");
	if(fr==NULL) printf("Erro.\n");
	fp = fopen(argv[2], "a");
	fprintf(fp, "O ficheiro %s tem %d carateres.\n", argv[1],countchar(fr));
	fclose(fr);
	fclose(fp);
	return 0;
}