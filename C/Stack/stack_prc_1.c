#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX], top = -1, val, i;

void push()
{
    if (top >= MAX)
    {
        printf("Stack Overfliow\n");
    }
    else
    {
        printf("Enter the element to be inserted.\n");
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }
}

void pop()
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("The element %d is poped out\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top < 0)
    {
        printf("The stack is empty\n");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("|%d|\n", stack[i]);
        }
    }
}

int main()
{
    int choice;
    printf("Enter the operation you want to perform\n");
    printf("1. Push()\n");
    printf("2. Pop()\n");
    printf("3. Display()\n");
    printf("4. Exit\n");
    do
    {
        printf("Enter : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Successfully exited!\n");
            break;

        default:
            if (choice > 4)
            {
                printf("Enter the correct option.\n");
            }
            break;
        }
    } while (choice != 4);

    return 0;
}