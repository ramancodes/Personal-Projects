#include<stdio.h>
#define MAX 10

int main()
{
    int arr[MAX] = {1, 2, 3, 4};
    int LB = 0, UB = 4, i, k, element;

    printf("Original Array : \n");
    for(i = 0; i<UB; i++)
    {
        printf("%d ", arr[i]);
    }

    if(UB == MAX-1)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("\nEnter the element\n");
        scanf("%d", &element);

        k = UB;
        while(k>=LB)
        {
            arr[k+1] = arr[k];
            k--;
        }
        arr[LB] = element;
        UB++;

        printf("New array : \n");
        for(i =0; i<UB; i++)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}