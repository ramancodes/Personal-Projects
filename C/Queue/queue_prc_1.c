#include <stdio.h>
#include <stdio.h>
#define MAX 10

int queue[MAX], front = -1, rear = -1, i, val;

void enqueue()
{
    if (rear > MAX)
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        printf("Enter the element to be inserted\n");
        scanf("%d", &val);

        rear++;
        queue[rear] = val;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("The element %d is deleted\n", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The elements are :\n| ");
        for (i = front; i <= rear; i++)
        {
            printf("%d | ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    printf("Choose from the following\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    do
    {
        printf("Enter : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Successfully Exited!\n");
            break;

        default:
            if (choice > 4)
            {
                printf("Enter the correct option\n");
            }
        }
    } while (choice != 4);

    return 0;
}