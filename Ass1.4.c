/*
    JTSK-320112
    a1_p4_gA.c
    Kevin Silaj
    k.silaj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

void result(int **a, int **b, int x)
{
    int i, j, k, inter;
    int c[x][x];

    for(i = 0; i < x; i++)
    {
        for(j = 0; j < x; j++)
        {
//all the values are zero at first
            c[i][j] = 0;
        }
    }

    printf("The intermediate product values are:\n");

    for(i=0; i<x; i++)
    {
        for(j=0; j<x; j++)
        {
            for(k=0; k<x; k++)
            {
                //the formula given in the assignment(helpful)
                inter = a[i][k] * b[k][j];
                c[i][j] += inter;
                printf("%d\n", inter);
            }
        }
    }

    printf("The product of the matrices is:\n");

     for(i = 0; i < x; i++)
    {
        for(j = 0; j < x; j++)
        {

            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int **p1, **p2, i, j, n;

    scanf("%d", &n);

    //double pointers
    p1 = (int **) malloc(sizeof(int *) * n);
    p2 = (int **) malloc(sizeof(int *) * n);


    for(i = 0; i < n; i++)
    {
        p1[i] = (int *) malloc(sizeof(int) * n);
        p2[i] = (int *) malloc(sizeof(int) * n);

        //checking for errors
        if(p1[i] == NULL)
        {
            printf("Error, memory not allocated");
            exit(1);
        }

        if(p2[i] == NULL)
        {
            printf("Error, memory not allocated");
            exit(1);
        }
    }

    for(i=0; i < n; i++)
        {
            for(j=0; j < n; j++)
            {
                scanf("%d", &p1[i][j]);
            }
        }

    for(i=0; i < n; i++)
    {
        for(j=0; j < n; j++)
        {

            scanf("%d", &p2[i][j]);
        }
    }

        result(p1 , p2 , n);

    //deallocating
    for(i=0; i < n; i++)
    {
        free(p1[i]);
        free(p2 [i]);
    }

    free(p1);
    free(p2);

    return 0;
}
