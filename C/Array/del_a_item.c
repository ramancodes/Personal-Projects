#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int i, UB = 7, data, j;

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
        printf("\nEnter the element to delete\n");
        scanf("%d", &data);

        for (i = 0; i <= UB; i++)
        {
            if (arr[i] == data)
            {
                for (j = i; j < UB; j++)
                {
                    arr[j] = arr[j + 1];
                }
            }
        }

        UB--;
        printf("New Array : \n");
        for(i=0; i<=UB; i++)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}