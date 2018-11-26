/*
JTSK-320112
a4 p2.c
Kevin Silaj
k.silaj@jacobs-university.de
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define LIMIT 50


/* For the three functions, in order to return to the original one
after printing the new string, I created another string char original
= to string so I can modify and print original and then return to string
which is the original string*/

void allupper(char string[LIMIT])
{
    int i;
    char original[LIMIT];
    for(i = 0; i < LIMIT; i++)
        original[i]=string[i];


    for (i=0; i<LIMIT; i++)
    {
        if (islower(original[i]))
        {
            original[i] = toupper(original[i]);
        }
    }
    printf("%s", original);

}

void alllower(char string[LIMIT])
{
    int i;
    char original[LIMIT];
    for(i = 0; i < LIMIT; i++)
        original[i]=string[i];

    for (i=0; i<LIMIT; i++)
    {
        if (isupper(original[i]))
        {
            original[i] = tolower(original[i]);
        }
    }

    printf("%s", original);
}

void both(char string[LIMIT])
{
    int i;
    char original[LIMIT];
    for(i = 0; i < LIMIT; i++)
        original[i]=string[i];

    for (i=0; i<LIMIT; i++)
    {
        if (isupper(original[i]))
        {
            original[i] = tolower(original[i]);
        } else
            {
                original[i]=toupper(original[i]);
            }
    }
    printf("%s", original);
}

void end(char string[LIMIT])
{
    exit(0);
}

int main()
{
    char ch;
    char string[LIMIT];

    fgets(string,LIMIT,stdin);

    //the function pointers
    void (*p)(char *string);
    void (*pp)(char *string);
    void (*ppp)(char *string);
    void (*pppp)(char *string);

    p = &allupper;
    pp = &alllower;
    ppp = &both;
    pppp = &end;

    //array of function pointer
    void (*functions[4])(char *string) = {p, pp, ppp, pppp};

    while(1)
    {
        scanf("%c", &ch);
        getchar();

        //a = 97 in ascii
        //if we push a we have 97-97 = 0 which is function 0
        //same for b and c
        //if we push d it will return 0 from function end()
        functions[ch-97](string);
    }

    return 0;
}





