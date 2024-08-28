#include <stdio.h>

int sumfunc(int arr[], int size)
{
    int sum = 0, i;
    for (i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int arr[30];
    int i, size, sum;
    printf("Enter the no of elements of the array\n");
    scanf("%d", &size);
    printf("Enter the elements\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    sum = sumfunc(arr, size);

    printf("The sum of the elements are : %d", sum);

    return 0;
}