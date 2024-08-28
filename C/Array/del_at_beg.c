#include <stdio.h>
#define MAX 10

int main()
{
    int arr[MAX] = {1, 2, 3, 5, 6};
    int i, UB = 4, LB = 0, k;

    printf("Origianl Array : \n");
    for (i = 0; i <= UB; i++)
    {
        printf("%d ", arr[i]);
    }

    if (UB == (int)NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        for (i = 0; i < UB; i++)
        {
            arr[i] = arr[i + 1];
        }
        UB--;
        printf("\nNew array : \n");
        for (i = 0; i <= UB; i++)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}