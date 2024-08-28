#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int i, UB = 6, loc;

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
        printf("\nEnter the location : \n");
        scanf("%d", &loc);

        loc--;
        for (i = loc; i < UB; i++)
        {
            arr[i] = arr[i + 1];
        }

        UB--;
        printf("New array : \n");
        for (i = 0; i <= UB; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}