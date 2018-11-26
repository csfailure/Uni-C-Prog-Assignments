/*
    JTSK-320112
    a6_p5_gA.c
    Kevin Silaj
    k.silaj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int main()
{
    char file[MAX];

    fgets(file, MAX, stdin);
    file[strlen(file) - 1] = '\0';

    FILE *fi;

    fi = fopen(file, "r");

    //if error
    if(fi == NULL)
        fprintf(stderr , "Cannot  open  file!\n"), exit (1);

    while(1)
    {

        fseek(fi, SEEK_SET, 0);
        char name[MAX];
        char x[MAX];

        memset(x, '\0', MAX);

        char ch;
        int i = 0;

        //getting input
        fgets(name, MAX, stdin);

        name[strlen(name)-1] = '\0';

        //if we type exit
        if(strcmp(name, "exit") == 0)
            break;

        //end of file check
        while((ch = getc(fi)) != EOF)
        {
            char buffer[MAX];


            if(ch == '\n')
            {
                x[i++] = '\0';
                i = 0;

                //if x we enter is the name
                if(strcmp(x, name) == 0)
                {
                    printf("Age and city of %s:\n", name);

                    fgets(buffer, MAX, fi);
                    buffer[strlen(buffer)-1] = '\0';
                    printf("%s\n", buffer);

                    memset(buffer, '\0', MAX);

                    fgets(buffer, MAX, fi);
                    buffer[strlen(buffer)-1] = '\0';
                    printf("%s\n", buffer);

                    break;
                }
            }
            else
            {
                x[i++] = ch;
            }
        }

    }

    //file close
    fclose(fi);

    return 0;
}
