#include <stdio.h>
#define MAX 5

int main()
{
    int arr[MAX][MAX] = {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}, {6, 7, 8, 9, 1}, {1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}};
    int i, j;

    printf("Tri Diagonal Matrix : \n");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (i == j)
            {
                printf("%d ", arr[i][j]);
            }
            else if (i == j + 1)
            {
                printf("%d ", arr[i][j]);
            }
            else if (i == j - 1)
            {
                printf("%d ", arr[i][j]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}