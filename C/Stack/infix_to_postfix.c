// incompleted
#include <stdio.h>
#include <stdio.h>
#define MAX 50

char stack[MAX];
int top = -1;

void push(char val)
{
    if (top >= MAX)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

void pop()
{
    if(top<0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%c", stack[top]);
        top--;
    }
}

int main()
{
    char temparr[MAX], value;
    int count = 0, i = 0;
    printf("Enter the expression\n");
    while(value != '~')
    {
        scanf("%c", &value);
        if(value != '~')
        {
            temparr[i] = value;
            count++;
        }
        i++;
    }

    int arr[count];

    for(i = 0; i<count; i++)
    {
        arr[i] = temparr[i];
    }

    return 0;
}