/*
    JTSK-320112
    a1_p7_gA.c
    Kevin Silaj
    k.silaj@jacobs-university.de
*/

#include <stdio.h>

//similar to a1.6 I just add the switch and set parts
int main()
{
    int MASK = 65536;//represented by all 0s

    unsigned int number;
    int a, b, i;

    scanf("%d", &number);
    scanf("%d", &a);
    scanf("%d", &b);

    printf("The binary representation is: ");

    //checking bitmask
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

    number = (number | 1 << a); //setting
    number = (number ^ 1 <<b); //switching

    printf("\nAfter setting and switching: ");
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
