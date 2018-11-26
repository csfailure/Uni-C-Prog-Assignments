/*
JTSK-320112
a1 p5.c
Kevin Silaj
k.silaj@jacobs-university.de
*/

#include <stdio.h>

int main()
{
//You may wonder why I used 65535?
//65535 is the binary representation of 1111111111111111
//so it is all 1s
    unsigned int number;
    int i;
    int MASK = 65535;
    scanf("%d", &number);
    printf("The binary representation is: ");
// 16 is the number of bits
    for(i = 0; i < 16; i++)
    {
//bitmask check
//do NOT print if it is == 0

        if((number & MASK << i) == 0)
        {
            break;
        }else if(number & 1 << i)
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

