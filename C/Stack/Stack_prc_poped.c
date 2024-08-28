#include <stdio.h>
#define MAX 50
#define N 50

int stack[MAX];
int poped[N];
int tos = -1, i;
int popedno = -1;

void display()
{
    if (tos < 0)
    {
        printf("The stack is empty\n");
    }
    else
    {
        for (i = 0; i <= tos; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void displayPoped()
{
    if (popedno < 0)
    {
        printf("There are no poped elements\n");
    }
    else
    {
        printf("The poped elements are : \n");
        for (i = 0; i <= popedno; i++)
        {
            printf("%d ", poped[i]);
        }
        printf("\n");
    }
}

void peek()
{
    if (tos < 0)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("TOS : %d\n", stack[tos]);
    }
}

void push(int val)
{
    if (tos >= MAX)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        tos++;
        stack[tos] = val;
    }
}

void pop()
{
    if (tos < 0)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("Poped Element : %d\n", stack[tos]);
        popedno++;
        poped[popedno] = stack[tos];
        stack[tos] = (int)NULL;
        tos--;
    }
}

int main()
{
    push(10);
    push(20);
    pop();
    push(10);
    push(20);
    pop();
    pop();
    pop();
    push(20);
    pop();

    display();
    displayPoped();

    return 0;
}