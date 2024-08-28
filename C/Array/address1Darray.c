#include <stdio.h>

int address(int arr[], int i, int LB)
{
    // arr[i] = base address + size * (i - first element)
    int add;
    printf("Address of arr[0] : %d\n", &arr[0]);
    add = (int)&arr[0] + (sizeof(int) * (i - LB));

    return add;
}

int main()
{
    int n, add, i;
    int arr[] = {1, 2, 3, 4};

    printf("Enter the index of the array to find the address\n");
    scanf("%d", &n);

    add = address(arr, n, 0);

    printf("Address of arr[%d] is : %d\n", n, add);

    return 0;
}