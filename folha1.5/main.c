#include <stdio.h>

//mat2file
int main(int arg, char **argsc)
{
    FILE *fp;
    fp = fopen("matriz.txt", "a+");
    fprintf(fp, "%s %s", argsc[1], argsc[2]);
    for (int i = 3; i < arg ; ++i)
    {
        fprintf(fp, " %s", argsc[i]);
    }
    fprintf(fp, "\n");
    fclose(fp);
    return 0;
}

//
// Created by Aires on 03/03/20.
//

