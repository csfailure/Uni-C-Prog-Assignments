/*
 JTSK-320112
 a5_p5.c
 Kevin Silaj
 k.silaj@jacobs-university.de
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SIZE 30

typedef struct person
{
    char name[SIZE];
    int age;

} person;


//compares floats
int cmpfloat(const void *a, const void *b)
{
    return (*(float*)b - *(float*)a);
}

//compare names
int cmpname(const void *a, const void *b)
{
    person *p1 = (person *) a;
    person *p2 = (person *) b;

    int x = strcmp(p1->name, p2->name);
    return x;
}

//compares ages
int cmpage(const void *a, const void *b)
{
    person *p1 = (person *) a;
    person *p2 = (person *) b;

    return p1->age - p2->age;
}

void floatsort(int n){
    //init
    int i;
    float *array;
    char ch[100];

    //allocate
    array = (float *) malloc(sizeof(float) * n);
    if(array == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

    for(i=0; i<n; i++)
    {
        fgets(ch, sizeof(ch), stdin);
        sscanf(ch, "%f", array + i);
    }

    //sort
    qsort(array, (size_t) n, sizeof(float), cmpfloat);

    //print
    printf("Decreasingly sorted floats:\n");

    for(i=0; i<n; i++)
    {
        if(n - i == 1)
        {
            printf("%.3f", array[i]);
        }
        else
        {
            printf("%.3f ", array[i]);
        }
    }
    free(array);
}

void personsort(int n){
    //init
    int i, j;
    person *p;
    char ch[100];

    //allocate
    p = (struct person *) malloc(sizeof(struct person) * n);
    if(p == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }


    for(i=0; i<n; i++)
    {

        fgets(p[i].name, SIZE, stdin);

        for(j=0; j<SIZE; j++)
        {
            if(p[i].name[j] == '\n')
            {
                p[i].name[j] = '\0';
            }
        }

        fgets(ch, sizeof(ch), stdin);

        sscanf(ch, "%d", &p[i].age);
    }

    //qsort function
    qsort(p, (size_t) n, (size_t) sizeof(person), cmpname);

    //print names
    printf("\nAlphabetically sorted structs (name):\n");

    for(i=0; i<n; i++)
    {
        if(n - i == 1)
        {
            printf("%s:%d", p[i].name, p[i].age);
        }else
        {
            printf("%s:%d ", p[i].name, p[i].age);
        }
    }

    //qsort function (age)
    qsort(p, (size_t) n, (size_t) sizeof(person), cmpage);

    //print ages
    printf("\nIncreasingly sorted structs (age):\n");

    for(i=0; i<n; i++)
    {
        if(n - i == 1)
        {
            printf("%s:%d", p[i].name, p[i].age);
        }else
        {
            printf("%s:%d ", p[i].name, p[i].age);
        }
    }
    printf("\n");

    //deallocation
    free(p);

}

int main()
{
    int n;
    char ch[100];

    //scan
    fgets(ch, sizeof(ch), stdin);
    sscanf(ch, "%d", &n);

    //call functions and return
    floatsort(n);
    personsort(n);

    return 0;
}

