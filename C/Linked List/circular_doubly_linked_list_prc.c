#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void printlist(struct node *tail)
{
    if (tail == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        struct node *temp = tail->next;
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
        printf("\n");
    }
}

struct node *create(struct node *tail, int data)
{
    tail = (struct node *)malloc(sizeof(struct node));
    tail->data = data;
    tail->next = tail;
    tail->prev = tail;

    return tail;
}

struct node *add_at_beg(struct node *tail, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = tail->next;
    tail->next->prev = new;
    tail->next = new;
    new->prev = tail;

    return tail;
}

struct node *add_at_end(struct node *tail, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = tail->next;
    tail->next->prev = new;
    tail->next = new;
    new->prev = tail;

    tail = new;

    return tail;
}

struct node *add_at_pos(struct node *tail, int data, int pos)
{
    struct node *temp = NULL, *temp2 = NULL;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;

    temp = tail->next;
    pos--;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }

    temp2 = temp->next;
    temp->next = new;
    new->prev = temp;
    new->next = temp2;
    temp2->prev = new;

    return tail;
}

struct node *del_at_beg(struct node *tail)
{
    struct node *temp = tail->next;

    tail->next = temp->next;
    temp->next->prev = tail;

    free(temp);
    temp = NULL;

    return tail;
}

struct node *del_at_end(struct node *tail)
{
    struct node *temp = tail->next;
    struct node *temp2 = tail->prev;

    temp2->next = temp;
    temp->prev = temp2;

    free(tail);
    tail = temp2;

    return tail;
}

struct node *del_at_pos(struct node *tail, int pos)
{
    struct node *temp = NULL, *temp2 = NULL;

    temp = tail->next;
    pos--;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }

    temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next->prev = temp;

    free(temp2);

    return tail;
}

int main()
{
    struct node *tail = NULL;
    printlist(tail);
    tail = create(tail, 12);
    printlist(tail);

    tail = add_at_beg(tail, 11);
    printlist(tail);

    tail = add_at_end(tail, 13);
    tail = add_at_end(tail, 15);
    printlist(tail);

    tail = add_at_pos(tail, 14, 3);
    printlist(tail);

    tail = del_at_beg(tail);
    printlist(tail);
    
    tail = del_at_end(tail);
    printlist(tail);

    tail = del_at_pos(tail, 2);
    printlist(tail);

    return 0;
}