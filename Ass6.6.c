/*
    JTSK-320112
    a6_p6_gA.c
    Kevin Silaj
    k.silaj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define SIZE 100

//concatenating two files
char* concatenate(int count, ...)
{
    va_list ap;
    int i,length = 1;


    //va_start or end or arg macros
    va_start(ap, count);

    for(i=0 ; i<count ; i++)
        length += strlen(va_arg(ap, char*));
    va_end(ap);

    //memory allocation
    char *merge = calloc(sizeof(char),length);
    int position = 0;
    va_start(ap, count);
    for(i=0 ; i < count ; i++)
    {
        char *c = va_arg(ap, char*);
        strcpy(merge + position, c);
        position += strlen(c);
    }

    va_end(ap);

    return merge;
}


int main()
{
    int i;
    int n;
    char file[SIZE];
    FILE *fi1, *fi2;
    char buffer[64];

    //the file names
    char s1[] = ".txt";
    char s2[] = "_copy.txt";
    char s3[] = "_copy";


    scanf("%d", &n);
    getchar();

    for(i=0; i<n; i++)
    {
        //fgets of the name of the file
        fgets(file, sizeof(file), stdin);
        file[strlen(file) - 1] = '\0';

        char *newfi1 = concatenate(2, file, s1);
        char *newfi2 = concatenate(2, file, s2);
        char *newfi3 = concatenate(2, file, s3);

        //open files fi1 and fi2 and their error checks
        fi1 = fopen(newfi1, "r");
        if(fi1 == NULL)
            {
                fprintf(stderr, "Cannot open file %s\n", newfi1);
                exit(1);
            }

        fi2 = fopen(newfi2, "w");
        if(fi1 == NULL)
            {
                fprintf(stderr,"Cannot open file %s\n", newfi2);
                exit(2);
            }

        do {
            size_t si;
            si = fread(buffer, 1, sizeof buffer, fi1);
            if (si == 0)
                break;

            fwrite(buffer, 1, si, fi2);

            }while (1);


        printf("Copied %s into %s.\n", file, newfi3);

    }

    //close files
    fclose(fi1);
    fclose(fi2);
    return 0;
}
