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

    for(i = 0; i<n-1;i++)
    {
        for(j = i+1; j<n; j++)
        {
            if(arr[j]<arr[i])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    printf("Sorted Array -> ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}