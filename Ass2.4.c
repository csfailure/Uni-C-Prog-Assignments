/*
    JTSK-320112
    a2_p4_gA.c
    Kevin Silaj
    k.silaj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>


//the input function
void scan(int ***threeD, int x, int y, int z)
{

    int i , j , k;

    //scan
    for(i = 0; i < x; i++)
    {
        for(j = 0; j < y; j++)
        {
            for(k = 0; k < z; k++)
            {
                scanf("%d", &threeD[i][j][k]);
            }
        }

    }

}

//the output function
void print(int ***threeD, int x, int y, int z)
{
    int i,j,k;

    //print
    for(j = 0; j < y; j++)
    {
        printf("Section %d:\n", j+1);
        for(i = 0; i < x; i++)
        {
            for(k = 0; k < z; k++)
            {
                printf("%d ", threeD[i][j][k]);
            }
            printf("\n");
        }
    }

}


int main()
{
    int i , j , x , y , z;
    scanf("%d%d%d", &x, &y, &z);
    int ***threeD;


    //allocate memory
    threeD = (int***) malloc(sizeof(int**) * x);
    if(threeD == NULL)//check
                {
                    printf("memory not allocated");
                    exit(1);
                }

    for(i = 0; i < x; i++)
    {
        threeD[i] = (int**) malloc(sizeof(int*) * y);
        if(threeD[i] == NULL)
                {
                    printf("memory not allocated");
                    exit(1);
                }
    }
    for(i = 0; i < x; i++)
    {
        for(j = 0; j < y; j++)
        {
            threeD[i][j] = (int*) malloc(sizeof(int) * z);
            if(threeD[i][j] == NULL)
                {
                    printf("memory not allocated");
                    exit(1);
                }
        }
    }

    scan(threeD, x, y, z);

    print(threeD, x, y, z);

    //deallocate memory
     for(i = 0; i < x; i++)
    {
        for(j = 0; j < y; j++)
        {
            free(threeD[i][j]);
        }
    }

     for(i = 0; i < x; i++)
    {
        free(threeD[i]);
    }


    free(threeD);

    return 0;
}


