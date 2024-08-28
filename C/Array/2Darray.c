#include <stdio.h>

int AddAll1(int *arr, int m, int n)
{
    int sum = 0, i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum += *((arr + i * n) + j);
        }
    }
    return sum;
}

int SumALL2(int m, int n, int arr[][n])
{
    int sum = 0, i, j;
    for (i = 0; i<m; i++)
    {
        for(j =0 ; j<n; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

int main()
{
    int arr[2][3] = {{1, 2, 3}, {2, 4, 6}};
    int sum;

    sum = SumALL2(2, 3, arr);
    printf("1st Sum = %d\n", sum);

    sum = AddAll1((int *)arr, 2, 3);
    printf("2nd Sum = %d\n", sum);
    return 0;
}