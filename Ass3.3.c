/*
    JTSK-320112
    a3_p3_gA.c
    Kevin Silaj
    k.silaj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

struct list
{
    struct list *next;
    struct list *prev;
    int info;
};

struct list *push_front(struct list *my_list, int x)
{
    struct list *newelem = (struct list*) malloc(sizeof(struct list));

    //initialize
    newelem->info = x;
    newelem->prev = NULL;
    newelem->next = NULL;

    if(newelem == NULL)
    {
        printf("Error allocating memory!\n");
        return my_list;
    }

    if(my_list == NULL)
    {
        my_list = newelem;
        return my_list;
    }

    my_list->prev = newelem;
    newelem->next = my_list;
    my_list = newelem;

    return newelem;
}

void printfront(struct list *my_list)
{
    if(my_list == NULL)
    {
        printf("empty list\n");
    }

    while(my_list != NULL)
    {
        printf("%d ", my_list->info);
        my_list = my_list->next;
    }
    printf("\n");
}

void printback(struct list *my_list)
{
    struct list *temp = my_list;

    if(temp == NULL)
        return;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    while(temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->prev;
    }
    printf("\n");
}

struct list* remove_data(struct list *my_list, int x)
{
    struct list *current,*next,*prev,*begin;
    current=my_list;
    begin=my_list;
    int ok=0;
    while(current!=NULL)
    {
        if(current->info==x)
        {
            next=current->next;
            prev=current->prev;
            if(current->next!=NULL)
            {
                next->prev=prev;
            }
            if(current->prev!=NULL)
            {
                prev->next=next;
            }
            if(current->prev==NULL)
            {
                free(current);
                begin=next;
                current=next;
                current->prev=NULL;
                ok=1;
                continue;
            }
            free(current);
            current=next;
            ok=1;
        }
        else
        {
            current=current->next;
        }
    }
    if(ok==0)
    {
        printf("The element is not in the list!\n");
    }
    //my_list=current;
    return begin;
};


void dispose_list(struct list *my_list)
{
    struct list *nextelem;

    while (my_list != NULL)
    {
        nextelem = my_list->next;
        free (my_list);
        my_list = nextelem;
    }
}

int main()
{


    struct list *my_list = NULL;

    while(1)

    {
    char ch;
    int x;
    scanf("%c", &ch);
    getchar();



        switch(ch)
        {
        case ('a'):
            scanf("%d", &x);
            getchar();
            my_list = push_front(my_list, x);
            break;

        case ('r'):
            scanf("%d", &x);
            getchar();
            my_list=remove_data(my_list, x);
            break;

        case ('p'):
            printfront(my_list);
            break;

        case ('b'):
            printback(my_list);
            break;
        case ('q'):
            dispose_list(my_list);
            exit(0);

        }
    }
    return 0;
}
