#include <stdio.h>
#define MAX 10

int main()
{
    int arr[MAX] = {1, 2, 3, 4};
    int i, UB = 3, element;

    printf("Original array : \n");
    for (i = 0; i < UB; i++)
    {
        printf("%d ", arr[i]);
    }

    if (UB == MAX - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("\nEnter the element to be inserted\n");
        scanf("%d", &element);

        UB++;

        arr[UB] = element;

        printf("New array : \n");
        for (i = 0; i < UB; i++)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}