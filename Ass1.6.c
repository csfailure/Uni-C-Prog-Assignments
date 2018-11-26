/*
    JTSK-320112
    a1_p6_gA.c
    Kevin Silaj
    k.silaj@jacobs-university.de
*/

#include <stdio.h>

int main()
{
    //in this case I use 65536 because is all 0s
    unsigned int number;
    int i;
    int MASK = 65536;

    scanf("%d", &number);

    printf("The binary representation is: ");

    //bitmask checking
    //16 is for 16 bits
    for(i = 0; i < 16; i++)
    {
        if(number & MASK/2 >> i)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    printf("\n");

    return 0;
}
