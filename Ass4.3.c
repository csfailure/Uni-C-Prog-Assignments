/*
JTSK-320112
a4 p3.c
Kevin Silaj
k.silaj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(char*)a - *(char*)b);
}

//will be used for the descending part
void opposite(char *c, int n)
{
	int i;
	char xtra[n];

    for(i = 0; i < n; i++)
    {
		xtra[n - 1 - i] = c[i];
	}

	for (i = 0; i < n; i++){
		c[i] = xtra[i];
	}
}

void ascending(char* c, int n)
{
    //just like problem 4.2
    //after every print of the modified array
    //we should go back to the original array
    int i;
    char xtra[n];


    for(i = 0; i < n; i++)
    {
        xtra[i] = c[i];
    }

    //qsort function
    qsort(xtra, n, sizeof(char), compare);

    for(i = 0; i < n; i++)
    {
        printf("%c ", xtra[i]);
    }
    printf("\n");
}

void descending(char *c, int n)
{
    //same method applies for descending
    //the only difference is the reverse of the numbers
    int i;
    char xtra[n];

    for(i = 0; i < n; i++)
    {
        xtra[i] = c[i];
    }

    //qsort function
     qsort(xtra, n , sizeof(char), compare);

     opposite(xtra,n);

     for(i = 0; i < n; i++)
    {
        printf("%c ", xtra[i]);
    }
    printf("\n");
}

//a function when we press 3
void end(char *c, int n)
{
    exit(0);
}

int main()
{
    int x,n,i;

    scanf("%d", &n);

    char c[n];

    for(i = 0; i < n; i++)
    {
        scanf("%s", &c[i]);
    }

    void (*p) (char *arr, int n);
    void (*pp) (char *arr, int n);
    void (*ppp) (char *arr, int n);

    p = &ascending;
    pp = &descending;
    ppp = &end;
    //a pointer of functions
    void (*functions[3])(char *c, int n) = {p, pp, ppp};


   while(1)
   {
    scanf("%d", &x);

    functions[x-1](c,n);
    }

   return 0;
}




