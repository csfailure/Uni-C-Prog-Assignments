/*
JTSK-320112
a1 p3.c
Kevin Silaj
k.silaj@jacobs-university.de
*/

#include <stdio.h>

//first macro simple: add the 3 elements
//second macro: if A > B and C print A else C
//if B > A and C print B else C
//same logic for the third macro but we use < instead of >
//fourth macro: the sum of all the macros above

#define SUM(A,B,C) (A)+(B)+(C)
#define MAX(A,B,C) ((A > B)?( A > C? A : C):(B > C ? B : C))
#define MIN(A,B,C) ((A < B)?( A < C? A : C):(B < C ? B : C))
#define EXPR(A,B,C) (SUM((A),(B),(C)) + MAX((A),(B),(C))) / MIN((A),(B),(C))

int main()
{
    int x,y,z;

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    printf("The value of the expression is: ");
    printf("%.6lf\n",(double)EXPR(x,y,z));

    return 0;
}
