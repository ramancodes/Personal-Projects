#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void printlist(struct node *tail)
{
    struct node *ptr = NULL;
    if (tail == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        ptr = tail->next;
        do
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        } while (ptr != tail->next);
        printf("HEAD\n");
    }
}

void search(struct node *tail)
{
    struct node *ptr = NULL;
    int index = 0, flag = 0, data;

    if (tail == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("Enter the data to be searched\n");
        scanf("%d", &data);
        ptr = tail->next;

        do
        {
            index++;
            if (ptr->data == data)
            {
                printf("The element %d is alailable at location %d\n", ptr->data, index);
                flag = 1;
                break;
            }
            ptr = ptr->next;
        } while (ptr != tail->next);
        if (flag == 0)
        {
            printf("The data %d is not available in the list.", data);
        }
    }
}

struct node *create(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = new;
    new->prev = new;
    return new;
}

struct node *add_at_beg(struct node *tail)
{
    struct node *new = NULL;
    int data;

    if (tail == NULL)
    {
        printf("The list is empty\n");
        return tail;
    }

    printf("Enter the element to be inserted\n");
    scanf("%d", &data);

    new = create(data);
    new->next = tail->next;
    tail->next->prev = new;
    tail->next = new;
    new->prev = tail;

    return tail;
}

struct node *add_at_end(struct node *tail)
{
    struct node *new = NULL;
    int data;

    if (tail == NULL)
    {
        printf("The list is empty\n");
        return tail;
    }

    printf("Enter the element to be inserted\n");
    scanf("%d", &data);

    new = create(data);
    new->prev = tail;
    new->next = tail->next;
    tail->next->prev = new;
    tail->next = new;
    tail = new;
    return tail;
}

struct node *add_at_pos(struct node *tail) // solve the errors
{
    struct node *new = NULL, *temp = NULL, *ptr = NULL;
    int index = 0, pos, data;

    if (tail == NULL) // if the list empty
    {
        printf("The list is empty\n");
        return tail;
    }

    printf("Enter the position of the element be inserted\n"); // enter the position
    scanf("%d", &pos);

    if (pos == 1) // insertion at the 1st position
    {
        tail = add_at_beg(tail);
        return tail;
    }

    ptr = tail->next;
    while (ptr != tail)
    {
        index++;
        ptr = ptr->next;
    }
    index++;

    if (index + 1 < pos)
    {
        printf("There are only %d elements in the list\n", index);
        return tail;
    }

    temp = tail->next;

    while (pos != 2)
    {
        temp = temp->next;
        pos--;
    }

    printf("Enter the element to be inserted\n");
    scanf("%d", &data);

    new = create(data);
    ptr = temp->next;
    temp->next = new;
    new->prev = temp;
    new->next = ptr;
    ptr->prev = new;

    if(temp == tail)
    {
        tail = tail->next;
    }

    return tail;
}

struct node *del_at_first(struct node *tail)
{
    struct node *temp = NULL;
    if(tail == NULL)
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

    temp = tail->next;
    tail->next = temp->next;
    temp->next->prev = tail;
    free(temp);
    temp = NULL;
    printf("The first node is deleted\n");
    return tail;
}

struct node *del_at_last(struct node *tail)
{
    struct node *temp = NULL;
    if(tail == NULL)
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

    temp = tail->prev;
    temp->next = tail->next;
    tail->next->prev = temp;
    free(tail);
    tail = temp;
    printf("The last node is deleted\n");
    return tail;
}

struct node *del_at_pos(struct node *tail)
{
    struct node *temp = NULL, *ptr = NULL;
    int index = 0, pos;

    if(tail == NULL)
    {
        printf("The list is empty\n");
        return tail;
    }
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        printf("The was only 1 element and it is deleted\n");
        return tail;
    }

    printf("Enter the position to be deleted\n");
    scanf("%d", &pos);

    if(pos == 1)
    {
        tail = del_at_first(tail);
        return tail;
    }

    ptr = tail->next;
    while(ptr != tail)
    {
        index++;
        ptr = ptr->next;
    }
    index++;

    if(index<pos)
    {
        printf("No of Elements in the list = %d\nEntered Position = %d\nData Unavilable\n", index, pos);
        return tail;
    }

    temp = tail->next;
    while(pos!=2)
    {
        temp = temp->next;
        pos--;
    }

    ptr = temp->next;
    temp->next = ptr->next;
    ptr->next->prev = temp;

    if(ptr == tail)
    {
        tail = temp;
    }

    free(ptr);
    ptr = NULL;
    printf("The node is deleted\n");
    return tail;
}

void operations()
{
    int choice, val;
    char ch;
    struct node *tail = NULL;

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
            search(tail);
            break;
        case 3:
            printf("Enter the data\n");
            scanf("%d", &val);
            tail = create(val);
            break;
        case 4:
            ch = 'y';
            do
            {
                if (ch == 'y')
                {
                    tail = add_at_beg(tail);
                }
                else
                {
                    printf("Wrong Choice\n");
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
                    tail = add_at_end(tail);
                }
                else
                {
                    printf("Wrong Choice\n");
                }
                getchar();
                printf("Do you want to add more?(y/n) : ");
                scanf("%c", &ch);
            } while (ch != 'n');
            break;
        case 6:
            ch = 'y';
            do
            {
                if (ch == 'y')
                {
                    tail = add_at_pos(tail);
                }
                else
                {
                    printf("Wrong Choice\n");
                }
                getchar();
                printf("Do you want to add more?(y/n) : ");
                scanf("%c", &ch);
            } while (ch != 'n');
            break;
        case 7:
            tail = del_at_first(tail);
            break;
        case 8:
            tail = del_at_last(tail);
            break;
        case 9:
            tail = del_at_pos(tail);
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
    printf("1. Print the list\n");
    printf("2. Search an element in the list\n");
    printf("3. Create the head node\n");
    printf("4. Insert at begnning\n");
    printf("5. Insert at end\n");
    printf("6. Insert at any position\n");
    printf("7. Delete the first node\n");
    printf("8. Delete the last node\n");
    printf("9. Delete node at any position\n");
    printf("0. Exit\n");

    operations();

    return 0;
}