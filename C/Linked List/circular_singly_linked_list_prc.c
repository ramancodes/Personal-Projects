#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void printlist(struct node *tail)
{
    if (tail == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        struct node *ptr = tail->next;
        do
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        } while (ptr != tail->next);
        printf("\n");
    }
}

struct node *create(struct node *tail, int data)
{
    tail = (struct node *)malloc(sizeof(struct node));
    tail->data = data;
    tail->next = tail;

    return tail;
}

struct node *add_at_beg(struct node *tail, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = tail->next;
    tail->next = new;

    return tail;
}

struct node *add_at_end(struct node *tail, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = tail->next;
    tail->next = new;
    tail = new;

    return tail;
}

struct node *add_at_pos(struct node *tail, int data, int pos)
{
    struct node *ptr = NULL;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;

    ptr = tail->next;
    pos--;
    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }

    new->next = ptr->next;
    ptr->next = new;

    return tail;
}

struct node *del_at_beg(struct node *tail)
{
    struct node *temp = tail->next;
    tail->next = temp->next;

    free(temp);
    temp = NULL;

    return tail;
}

struct node *del_at_end(struct node *tail)
{
    struct node *temp = tail->next;
    do
    {
        temp = temp->next;
    } while (temp->next->next != tail->next);
    temp->next = tail->next;
    free(tail);
    tail = temp;
    temp = NULL;
    return tail;
}

struct node *del_at_pos(struct node *tail, int pos)
{
    struct node *temp = tail->next, *temp2 = NULL;

    pos--;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }
    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    temp2 = NULL;

    return tail;
}

int main()
{
    struct node *tail = NULL;
    int data, pos, choice;

    do
    {
        printf("\nChoose :\n");
        printf("1. Print List\n");
        printf("2. Create head node\n");
        printf("3. Add at beg\n");
        printf("4. Add at end\n");
        printf("5. Add at any pos\n");
        printf("6. Delete at beg\n");
        printf("7. Delete at end\n");
        printf("8. Delete at any pos\n");
        printf("0. Exit\n");
        printf("\nEnter : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printlist(tail);
            break;

        case 2:
            printf("Enter the data\n");
            scanf("%d", &data);
            tail = create(tail, data);
            break;

        case 3:
            printf("Enter the data\n");
            scanf("%d", &data);
            tail = add_at_beg(tail, data);
            break;

        case 4:
            printf("Enter the data\n");
            scanf("%d", &data);
            tail = add_at_end(tail, data);
            break;

        case 5:
            printf("Enter the data\n");
            scanf("%d", &data);
            printf("Enter the position of the list\n");
            scanf("%d", &pos);
            tail = add_at_pos(tail, data, pos);
            break;

        case 6:
            tail = del_at_beg(tail);
            break;

        case 7:
            tail = del_at_end(tail);
            break;

        case 8:
            printf("Enter the position of the list\n");
            scanf("%d", &pos);
            tail = del_at_pos(tail, pos);
            break;

        default:
            if (choice != 0)
            {
                printf("Wrong input\n");
            }
            break;
        }
    } while (choice != 0);

    return 0;
}