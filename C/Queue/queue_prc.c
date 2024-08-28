#include <stdio.h>
#define MAX 20

int queue[MAX], front = -1, rear = -1, i;

void enqueue(int data)
{
    if (rear > MAX)
    {
        printf("Overflow\n");
    }
    else
    {
        if (front = -1)
        {
            front = 0;
        }

        rear = rear + 1;
        queue[rear] = data;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("The element deleted : %d\n", queue[front]);
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
        printf("The elements are : \n");
        for(i= front; i<=rear;i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();

    dequeue();
    display();

    return 0;
}