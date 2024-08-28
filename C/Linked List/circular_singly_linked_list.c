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
        struct node *p = tail->next;
        do
        {
            printf("%d -> ", p->data);
            p = p->next;
        } while (p != tail->next);
        printf("HEAD\n");
    }
}

struct node *create(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = new;
    return new;
}

struct node *add_at_beg(struct node *tail, int data)
{
    struct node *new = create(data);
    new->next = tail->next;
    tail->next = new;
    return tail;
}

struct node *add_at_end(struct node *tail, int data)
{
    struct node *new = create(data);
    new->next = tail->next;
    tail->next = new;
    tail = new;
    return tail;
}

struct node *add_at_pos(struct node *tail, int pos, int data)
{
    struct node *new = create(data);
    struct node *ptr = tail->next;
    struct node *temp = tail->next;
    int count = 0;

    if (pos == 1)
    {
        new->next = tail->next;
        tail->next = new;
        return tail;
    }

    while (ptr != tail)
    {
        count++;
        ptr = ptr->next;
    }
    count++;

    if ((count + 1) < pos)
    {
        printf("There are only %d elements in list\n", count);
        return tail;
    }

    pos--;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }

    new->next = temp->next;
    temp->next = new;

    if (temp == tail)
    {
        tail = tail->next;
    }

    return tail;
}

struct node *del_at_first(struct node *tail)
{
    if (tail == NULL)
    {
        printf("The list is empty\n");
        return tail;
    }
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        printf("The first node is deleted\n");
        return tail;
    }
    struct node *temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    printf("The first node is deleted\n");
    return tail;
}

struct node *del_at_last(struct node *tail)
{
    struct node *temp = tail->next;
    if (tail == NULL)
    {
        printf("The list is empty\n");
        return tail;
    }
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        printf("The last node is deleted\n");
        return tail;
    }

    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;
    printf("The last node is deleted\n");
    return tail;
}

struct node *del_at_pos(struct node *tail)
{
    struct node *temp = NULL;
    struct node *temp2 = NULL;
    struct node *ptr = NULL;
    int pos, count = 0;

    if (tail == NULL)
    {
        printf("The list is empty\n");
        return tail;
    }

    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        printf("There was only 1 node and it is deleted\n");
        return tail;
    }

    printf("Enter the position to be deleted\n");
    scanf("%d", &pos);
    ptr = tail->next;

    while (ptr != tail)
    {
        count++;
        ptr = ptr->next;
    }
    count++;

    if (count < pos)
    {
        printf("There are only %d elements in list\n", count);
        return tail;
    }

    temp = tail->next;

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
    printf("The node is deleted\n");
    return tail;
}

void search(struct node *tail)
{
    struct node *ptr = NULL;
    int flag = 0, count = 0, data;
    if (tail == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        ptr = tail->next;
        printf("Enter the data to be searched\n");
        scanf("%d", &data);
        do
        {
            ptr = ptr->next;
            count++;
            if (ptr->data == data)
            {
                printf("The data %d is available at location %d\n", ptr->data, count + 1);
                flag = 1;
                break;
            }
        } while (ptr != tail->next);
        if (flag == 0)
        {
            printf("The data %d is not available in the list\n", data);
        }
    }
}

void operations()
{
    int choice, val, pos;
    struct node *tail = NULL;
    char ch;

    do
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printlist(tail);
            break;
        case 2:
            printf("Enter the data\n");
            scanf("%d", &val);
            tail = create(val);
            break;
        case 3:
            ch = 'y';
            do
            {
                if (ch == 'y')
                {
                    printf("Enter the data\n");
                    scanf("%d", &val);
                    tail = add_at_beg(tail, val);
                }
                else
                {
                    printf("Wrong input\n");
                }
                getchar();
                printf("Do you want to add more?(y/n) : ");
                scanf("%c", &ch);
            } while (ch != 'n');
            break;
        case 4:
            ch = 'y';
            do
            {
                if (ch == 'y')
                {
                    printf("Enter the data\n");
                    scanf("%d", &val);
                    tail = add_at_end(tail, val);
                }
                else
                {
                    printf("Wrong input\n");
                }
                getchar();
                printf("Do you want to add more?(y/n) : ");
                scanf("%c", &ch);
            } while (ch != 'n');
            break;
        case 5:
            ch = 'y';
            do
            {
                if (ch == 'y')
                {
                    printf("Enter the position to be inserted\n");
                    scanf("%d", &pos);
                    printf("Enter the data\n");
                    scanf("%d", &val);
                    tail = add_at_pos(tail, pos, val);
                }
                else
                {
                    printf("Wrong input\n");
                }
                getchar();
                printf("Do you want to add more?(y/n) : ");
                scanf("%c", &ch);
            } while (ch != 'n');
            break;
        case 6:
            tail = del_at_first(tail);
            break;
        case 7:
            tail = del_at_last(tail);
            break;
        case 8:
            tail = del_at_pos(tail);
            break;
        case 9:
            search(tail);
            break;
        default:
            if (choice == 0)
            {
                printf("Successfully exited!\n");
            }
            else
            {
                printf("Wrong choice\n");
            }
            break;
        }
    } while (choice != 0);
}

int main()
{
    printf("List of operations\n");
    printf("1. PRINT THE LIST\n");
    printf("2. Create the head node\n");
    printf("3. Add at begnning\n");
    printf("4. Add at end\n");
    printf("5. Add at a position\n");
    printf("6. Delete the first node\n");
    printf("7. Delete the last node\n");
    printf("8. Delete the node at any position\n");
    printf("9. Search an element\n");
    printf("0. Exit\n");

    operations();

    return 0;
}
