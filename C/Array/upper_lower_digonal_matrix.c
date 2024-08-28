#include <stdio.h>
#define MAX 3

int main()
{
    int arr[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int i, j;

    // lower diagonal matrix
    printf("Lower diagonal matrix\n");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (i < j)
            {
                printf("0 ");
            }
            else
            {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }

    // upper diagonal matrix
    printf("Upper diagonal matrix\n");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if(i>j)
            {
                printf("0 ");
            }
            else
            {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}