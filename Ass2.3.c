/*
    JTSK-320112
    a2_p3_gA.c
    Kevin Silaj
    k.silaj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

//the function determines if the matrices are identical
void identical(int **arr1,int **arr2, int n)
{
    int i, j;
    int identical;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++) //checking if both the main and sec diagonals are =
            {
            if ((arr1[i][j] == arr2[i][j]) && (arr1[i][n-i-1] == arr2[i][n-i-1]))
                {
                    identical = 1;
                } else
                    {
                        identical = 0;
                    }
            }
    }
    //used the switch case method to recall this syntax
    switch (identical)
    {
    case 1:
        printf("identical\n");
        break;
    case 0:
        printf("NOT identical\n");
        break;
    }

    return;
}


int main()
{
    int i , j , size;
    int **a, **b;

    scanf("%d", &size);

    //memory allocation (double pointer)
    a = (int**)malloc(sizeof(int*) * size);
    b = (int**)malloc(sizeof(int*) * size);

    //error check
    if(a == NULL)
        {
            printf("memory not allocated");
            exit(1);
        }


    if(b == NULL)
        {
            printf("memory not allocated");
            exit(1);
        }

    for(i = 0; i < size; i++)
        {
            //memory allocation
            a[i] = (int*)malloc(sizeof(int) * size);
            b[i] = (int*)malloc(sizeof(int) * size);

            //error check
            if(a[i] == NULL)
                {
                    printf("memory not allocated");
                    exit(1);
                }


            if(b[i] == NULL)
                {
                    printf("memory not allocated");
                    exit(1);
                }
        }

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
            {
                scanf("%d", &a[i][j]);
            }
    }

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
            {
                scanf("%d", &b[i][j]);
            }
    }

 printf("Matrix A:\n");

  for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");

  for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%d ", b[i][j]);
        }
    printf("\n");
    }

 printf("The comparison result: ");
 identical(a, b, size);

 //deallocating
  for(i=0; i < size; i++)
    {
        free(a[i]);
    }

    for(i=0; i < size; i++)
    {
        free(b[i]);
    }

    free(a);
    free(b);


 return 0;
}
