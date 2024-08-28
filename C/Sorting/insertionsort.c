#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int arr[n];
    printf("Enter N = ");
    scanf("%d", &n);
    printf("Enter Array -> ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i-1;
        while(arr[j]>temp && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    printf("Sorted Array -> ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}