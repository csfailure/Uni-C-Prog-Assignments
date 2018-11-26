/*
JTSK-320112
a1 p1.c
Kevin Silaj
k.silaj@jacobs-university.de
*/

#include <stdio.h>

//with this function I use temp to sort the numbers
//by swapping B with A and then A with C
//the new order is C A B
#define SWAP(A,B,C,D) {D temp = (B); (B) = (A) ; (A) = temp;\
                        temp = (A); (A) = (C); (C) = temp;}


int main()
{
    int a,b,c;
    double d,e,f;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    scanf("%lf", &d);
    scanf("%lf", &e);
    scanf("%lf", &f);

    SWAP(a,b,c, int);
    SWAP(d,e,f, double);

    printf("After the permutation:\n");
    printf("%d\n%d\n%d\n", a , b, c);
    printf("%.5lf\n%.5lf\n%.5lf\n", d , e, f);

    return 0;
}
