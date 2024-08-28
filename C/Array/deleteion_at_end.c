#include <stdio.h>
#define MAX 10

int main()
{
    int arr[MAX] = {1, 2, 3, 4, 5};
    int UB = 4, i;

    printf("Original Array : \n");
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
        arr[UB] = (int)NULL;
        UB--;

        printf("\nNew Array : \n");
        for (i = 0; i <= UB; i++)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}