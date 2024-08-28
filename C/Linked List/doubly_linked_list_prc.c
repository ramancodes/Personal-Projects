#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void printlist(struct node *head)
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("The elements are \n NULL");
        while (ptr != NULL)
        {
            printf(" <- %d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

struct node *create(struct node *head, int data)
{
    head = (struct node *)malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;
    head->prev = NULL;

    return head;
}

struct node *add_at_beg(struct node *head, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = head;
    head->prev = new;

    head = new;

    return head;
}

struct node *add_at_end(struct node *head, int data)
{
    struct node *ptr = head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new;
    new->prev = ptr;

    return head;
}

struct node *add_at_pos(struct node *head, int data, int pos)
{
    struct node *new = NULL, *ptr = NULL, *ptr2 = NULL;
    int count = 0;

    if (pos == 1)
    {
        new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = head;
        head->prev = new;
        head = new;
        return head;
    }

    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    if (pos > count + 1)
    {
        printf("Elements : %d\n Total no of elements : %d\n The entered position is greater than the total no of elements in the list\n");
        return head;
    }

    ptr = head;

    pos--;
    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }

    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;

    if (ptr->next == NULL)
    {
        ptr->next = new;
        new->prev = ptr;
        new->next = NULL;
    }
    else
    {
        ptr2 = ptr->next;
        ptr->next = new;
        new->prev = ptr;
        new->next = ptr2;
        ptr2->prev = new;
    }

    return head;
}

struct node *del_at_beg(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("The list is empty\n");
        return head;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return head;
    }

    head = head->next;

    free(temp);
    temp = NULL;

    head->prev = NULL;

    return head;
}

struct node *del_at_end(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("The list is empty\n");
        return head;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return head;
    }

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return head;
}

struct node *del_at_pos(struct node *head, int pos)
{
    struct node *temp = NULL, *temp2 = NULL;
    int count = 0;
    if (head == NULL)
    {
        printf("The list is empty\n");
        return head;
    }

    if (pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
        temp = NULL;

        return head;
    }

    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (pos > count)
    {
        printf("Elements : %d\n Entered Position : %d\n The entered position is greater than the total no of elementsin the list\n", count, pos);
    }

    temp = head;
    pos--;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }

    if (temp->next == NULL)
    {
        temp2 = temp->prev;
        free(temp);
        temp = NULL;
        temp2->next = NULL;
    }
    else
    {
        temp2 = temp->next;
        temp = temp->prev;
        free(temp->next);
        temp->next = temp2;
        temp2->prev = temp;
    }

    return head;
}

int main()
{
    struct node *head = NULL;
    int choice, data, pos;

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
            printlist(head);
            break;

        case 2:
            printf("Enter the data\n");
            scanf("%d", &data);
            head = create(head, data);
            break;

        case 3:
            printf("Enter the data\n");
            scanf("%d", &data);
            head = add_at_beg(head, data);
            break;

        case 4:
            printf("Enter the data\n");
            scanf("%d", &data);
            head = add_at_end(head, data);
            break;

        case 5:
            printf("Enter the data\n");
            scanf("%d", &data);
            printf("Enter the position of the list\n");
            scanf("%d", &pos);
            head = add_at_pos(head, data, pos);
            break;

        case 6:
            head = del_at_beg(head);
            break;

        case 7:
            head = del_at_end(head);
            break;

        case 8:
            printf("Enter the position of the list\n");
            scanf("%d", &pos);
            head = del_at_pos(head, pos);
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