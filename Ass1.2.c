/*
JTSK-320112
a1 p2.c
Kevin Silaj
k.silaj@jacobs-university.de
*/

#include <stdio.h>

//number 4 represents the 3rd position from right to left
//if (x & 4) tells if the binary rep. is 1 or not

#define DET_BIT(x) {if (x & 4) {printf ("1\n");} else {printf ("0\n");}}

int main()

{
    unsigned char c;

    scanf("%c", &c);

    //I used %d to print the character's decimal rep
    printf("The decimal representation is: %d\n", c); //I used %d to print the character's decimal rep

    printf("The third least significant bit is: ");
    DET_BIT(c);

    return 0;
}
