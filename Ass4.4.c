/*
    JTSK-320112
    a4_p4.c
    Kevin Silaj
    k.silaj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct book {
    char title[MAX];
    int year;
};

//first compare by title
int comparetitle(struct book *my_book1, struct book *my_book2)
{
    int str_cmp = strcmp(my_book1->title, my_book2->title);
    int int_cmp = (my_book2->year < my_book1->year) - (my_book1->year < my_book2->year);

    return str_cmp != 0 ? str_cmp : int_cmp;
}


//second compare by year
int compareyear(struct book *my_book1, struct book *my_book2)
{
    int str_cmp = strcmp(my_book1->title, my_book2->title);
    int int_cmp = (my_book2->year < my_book1->year) - (my_book1->year < my_book2->year);

    return int_cmp != 0 ? int_cmp : str_cmp;
}

//Bubble sort function
void bubble(struct book *my_book, int n, int (*compare)(struct book *book1, struct book *book2))
{
    int i, j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(compare(&my_book[j+1], &my_book[j]) < 0)
            {
                struct book bookie = my_book[j+1];
                my_book[j+1] = my_book[j];
                my_book[j] = bookie;
            }
        }
    }
}

int main()
{
    int n, i;

    //pointing to the function of Bubble Sort
    void (*p) (struct book *my_book, int n,
                  int (*compare) (struct book *book1, struct book *book2));

    p = &bubble;

    scanf("%d", &n);
    getchar();

    struct book *bookworm;

    //memory allocation
    bookworm = (struct book *) malloc(sizeof(struct book) * n);

    //check allocation
    if(!bookworm)
    {
        printf("memory not allocated");
        exit(1);
    }

    for(i=0; i<n; i++)
    {
        //scan titles
        fgets(bookworm[i].title, MAX, stdin);
        //without this the program won't be saved for grading
        bookworm[i].title[strlen(bookworm[i].title)-1]='\0';

        //scan years
        scanf("%d", &bookworm[i].year);
        getchar();
    }

    printf("By title:\n");


    (*p) (bookworm, n, comparetitle); //sort by title

    for(i=0; i<n; i++)
    {
        printf("{%s, %d}\n", bookworm[i].title, bookworm[i].year);

    }
    printf("By year:\n");


    (*p) (bookworm, n, compareyear); //sort by year

    for(i=0; i<n; i++)
    {
        printf("{%s, %d}\n", bookworm[i].title, bookworm[i].year);

    }

    //deallocate memory
    free(bookworm);

    return 0;
}
