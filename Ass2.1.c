/*
JTSK-320112
a2 p1.c
Kevin Silaj
k.silaj@jacobs-university.de
*/


#include <stdio.h>
#include <stdlib.h>

int count(double arr[], int n)
{
    double *ptr1 = arr; //this pointer remains at the first position
    double *ptr2;//this pointer changes positions through the array

    //the second pointer increments until we find an integer
    //or even a floating point with .000
    for(ptr2 = arr; ptr2 != (arr+n); ptr2++)
    {
        if(*ptr2 - (int)*ptr2 == 0)
        {
            return ptr2 - ptr1;
        }
    }
    return -1;
}

int main()
{
    int i, size;
    scanf("%d", &size);

    double a[size];

    for(i = 0; i < size; i++)
    {
        scanf("%lf", &a[i]);
    }

    printf("Before the first integer: %d elements\n", count(a, size));

    return 0;

}
