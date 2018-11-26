/*
JTSK-320112
a6 p1.c
Kevin Silaj
k.silaj@jacobs-university.de
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

int main()
{
    char file[MAX];
    char word[MAX];
    //read the file
    fgets(file, sizeof(file), stdin);
    file[strlen(file)-1] = '\0';

    //read the word
    fgets(word, sizeof(word), stdin);
    word[strlen(word)-1] = '\0';
    int length = strlen(word)-1;


    FILE *f;
    f = fopen(file, "r");
    //checking if file is available
    if(f == NULL)
    {
        exit(1);
    }

    char x;
    int i = 0;
    int size = 0;
    x = getc(f);
    size++;
    while(x != EOF) {
        size++;
        x = getc(f);
    }
        printf("\n");

    char * bb;
    bb = (char *) malloc(sizeof(char) * (size+1));
    if(bb == NULL)
    {
        printf("error");
        exit(1);
    }

    char y;

    fseek(f, 0, SEEK_SET);

    while(1)
    {
        y = fgetc(f);

        //end of file
        if(feof(f))
            break;

        bb[i++] = y;
    }
    bb[i] = '\0';

    i = 0;

    //since it is case insensitive even the word containing uppercase letters
    //counts
    //so i turned it into lowercase to count it
    //didn't know any other way about it
    while(word[i]) {
        word[i]=(tolower(word[i]));
    i++;
    }

    i = 0;
    while(bb[i]) {
        bb[i]= (tolower(bb[i]));
    i++;
    }
    int count = 0, compare = 0, j;
    for(i = 0; i < size; i++)
    {
        compare = 0;
        //using these things here required by the assignment
        //the idea is that if they are in front of the word we want
        //the word counts and its not a substring
        if(bb[i] == word[0])
        {
            if((bb[i-1] == ' ' || bb[i-1] == ',' || bb[i-1] == '?' ||
            bb[i-1] == '!' || bb[i-1] == '\t' || bb[i-1] =='\r' ||
            bb[i-1] == '\n')
            && (bb[i+length+1] == ' ' || bb[i+length+1] == ','
            ||bb[i+length+1] == '?' ||bb[i+length+1] == '!' ||
            bb[i+length+1] == '\t' ||
            bb[i+length+1] == '\r' || bb[i+length+1] == '\n'))
            {
                for(j = 0; j < length; j++)
                {
                    if(word[j] != bb[i+j])
                    {
                        compare = 0;
                        break;
                    }
                    else
                        compare = 1;
                }
            }
        }
        if(compare == 1)
            count++;
    }

    printf("The word '%s' occurs %d times", word, count);

    //deallocate and close file
    free(bb);
    fclose(f);

    return 0;
}
