/*
JTSK-320112
a3 p1.c
Kevin Silaj
k.silaj@jacobs-university.de
*/


#include <stdio.h>
#include <stdlib.h>


struct list
{
    struct list *next;
    char info;
};


//case 2
struct list* push_front(struct list* my_list, char c)
{
    struct list *newel;
    newel = (struct list*)malloc(sizeof(struct list));
    if (newel == NULL)
    {
        printf("Memory not allocated");
        return my_list;
    }

    newel -> info = c;
    newel -> next = my_list;
    return newel;

}

//case 1
struct list* push_back(struct list* my_list, char c)
{
    struct list *cursor, *newel;
    cursor = my_list;
    newel = (struct list*)malloc(sizeof(struct list));
    if (newel == NULL)
    {
        printf("Memory not allocated");
        return my_list;
    }

    newel -> info = c;
    newel -> next = NULL;
    if(my_list == NULL)
        return newel;
    while (cursor -> next != NULL)
        cursor = cursor -> next;
    cursor -> next = newel;
    return my_list;

}

//case 5
void dispose_list(struct list* my_list)
{
    struct list *nextelem;
    while(my_list != NULL)
    {
        nextelem = my_list->next;
        free(my_list);
        my_list = nextelem;
    }

}

//case 4
void print_list(struct list * my_list)
{

    while(my_list != NULL)
    {
        printf("%c ", my_list->info);
        my_list = my_list -> next;
    }

    printf("\n");

}

//case 3
struct list* delete_first( struct list* my_list )
{
    if ( my_list == NULL)
        return NULL;

    struct list *remove1st = my_list -> next;

    free(my_list);

    return remove1st;
}

//case 6
void insertEl(struct list** my_list) {

    if (my_list == NULL) {
        return NULL;
    }

    int i;
    struct list *newel = (struct list*)malloc(sizeof(list));
    struct list *scan = *my_list;
    new->info = info;
    new->next = 0;

    if (scan == NULL && index == 0) {

         new->next = *my_list;
         *my_list = new;

    }

    for (i = 0; scan != NULL && i <= index; i++) {
        if (i == index) {

            new->next = scan->next;
            scan->next = new;
        } else {

            scan = scan->next;
        }
    }
    // scan == NULL indicates reached end of list before index
    return (scan != NULL);
}


int main ()
{
    struct list* my_list = NULL;
    int nr;
    char c;

    scanf("%d", &nr);

    //using all the elements inside the loop until I press 5
    while(nr != 5)
    {
        switch(nr)
        {

        case 1:
            getchar();
            scanf("%c", &c);
            my_list = push_back(my_list, c);
            break;

        case 2:
            getchar();
            scanf("%c", &c);
            my_list = push_front(my_list, c);
            break;

        case 3:
            my_list = delete_first(my_list);
            break;


        case 4:
            print_list(my_list);
            break;

        case 6:
            scanf("%d", &int pos);
            insertEl(my_list);
            break;


        }

        scanf("%d", &nr);
    }

    //if I push 5
    //separated to close the program
    dispose_list(my_list);

    return 0;
}

