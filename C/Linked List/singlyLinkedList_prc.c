#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
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
        printf("The elements are : \n\n");
        while (ptr != NULL)
        {
            printf("%d ->", ptr->data);
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

    return head;
}

struct node *add_at_beg(struct node *head, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = head;
    head = new;

    return head;
}

struct node *add_at_end(struct node *head, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new;

    return head;
}

struct node *add_at_pos(struct node *head, int data, int pos)
{
    struct node *new = NULL, *ptr = NULL;
    int count = 0;

    if (pos == 1)
    {
        new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = head;
        head = new;
        return head;
    }

    // for positon checking
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    if (pos > (count + 1))
    {
        printf("Elements : %d\n Entered position : %d\n The entered position is more han the number of elements\n", count, pos);
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

    new->next = ptr->next;
    ptr->next = new;

    return head;
}

struct node *del_at_beg(struct node *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;

        free(temp);
        temp = NULL;
    }

    return head;
}

struct node *del_at_end(struct node *head)
{
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

    struct node *temp = head;

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
    struct node *ptr = NULL, *ptr2 = NULL;
    int count = 0;
    if (head == NULL)
    {
        printf("The list is empty\n");
        return head;
    }

    if (pos == 1)
    {
        ptr = head;
        head = head->next;

        free(ptr);
        ptr = NULL;

        return head;
    }

    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    if (pos > count)
    {
        printf("Elements : %d\n Entered Position : %d\n The entered position is larger than the total no of elements\n", count, pos);
        return head;
    }

    ptr2 = head;
    pos--;
    while (pos != 1)
    {
        ptr = ptr2;
        ptr2 = ptr2->next;
        pos--;
    }
    ptr->next = ptr2->next;

    free(ptr2);
    ptr2 = NULL;

    return head;
}

int main()
{
    struct node *head = NULL;
    int data, pos, choice;

    do
    {
        printf("\nChoose from the options\n");
        printf("1. Print List\n");
        printf("2. Create head node\n");
        printf("3. Add node at the begnning\n");
        printf("4. Add node at the end\n");
        printf("5. Add node at any position\n");
        printf("6. Delete node at begnning\n");
        printf("7. Delete node at the end\n");
        printf("8. Delete node at any position\n");
        printf("0. Exit\n");
        printf("\nEnter : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printlist(head);
            break;

        case 2:
            printf("Enter the data item for the head node\n");
            scanf("%d", &data);
            head = create(head, data);
            break;

        case 3:
            printf("Enter the data to add at the begnning of the list\n");
            scanf("%d", &data);
            head = add_at_beg(head, data);
            break;

        case 4:
            printf("Enter the data to add at the end of the list\n");
            scanf("%d", &data);
            head = add_at_end(head, data);
            break;

        case 5:
            printf("Enter the data to add in the list\n");
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
                printf("Wrong choice\n\n");
            }
            break;
        }
    } while (choice != 0);

    printf("Successfull\n");

    return 0;
}