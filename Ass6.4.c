/*
    JTSK-320112
    a6_p4_gA.c
    Kevin Silaj
    k.silaj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer;
    char str[5];
    int *intb;
    int i;
    int x = 0, y = 0;

    buffer = (char *) malloc(sizeof(char) * 2);
    intb = (int *) malloc(sizeof(int) * 2);

    //open files and check for errors
    FILE *fi1 = fopen("chars.txt", "r+");
    FILE *fi2 = fopen("codesum.txt", "w+");

    if(fi1 == NULL){
        fprintf(stderr, "Cannot open file_read");
        exit(1);
    }

    if(fi2 == NULL){
        fprintf(stderr, "Cannot open file_write");
        exit(1);
    }

    for(i=0; i<2; i++)
    {
        fread(&buffer[i], sizeof(char), 2, fi1);
        buffer[(sizeof (buffer)) - 2] = '\0';


        intb[x++] = buffer[y++];
    }

    i = 0;

    //sum of the ascii rep
    int sum = intb[i] + intb[i+1];

    sprintf(str, "%d", sum);
    str[(sizeof (str)) - 1] = '\0';

    fwrite(&str, sizeof(str), 1, fi2);

    //close files and deallocate
    fclose(fi1);
    fclose(fi2);

    free(buffer);
    free(intb);

    return 0;
}


