/*
JTSK-320112
a2 p2.c
Kevin Silaj
k.silaj@jacobs-university.de
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char string[100];
    int b , e , i;
    char *allocate;
    int err=0;

    scanf("%s", string);
    scanf("%d", &b);
    scanf("%d", &e);

//if one of the errors occurs or two of them it prints the comment
     if(b < 0)
    {
        printf("The first position is negative!\n");
        err++;
    }

    if(e > strlen(string) - 1)
    {
        printf("The second position is higher than the last position!\n");
        err++;
    }
//it stops here if the errors occur
    if(err)
    {
        exit(1);
    }

    //memory allocation
    allocate = (char*) malloc(sizeof(char)*(e - b + 1));
    if(!allocate)
        exit(1);


    for (i = b; i < e + 1; i++)
    {
        allocate[i-b] = string[i];

    }

    printf("Result of substring(%d, %d): %s\n", b, e ,allocate);

//deallocation
    free(allocate);

    return 0;

}
