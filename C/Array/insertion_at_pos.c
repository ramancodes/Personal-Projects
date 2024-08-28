#include<stdio.h>
#define MAX 10

int main()
{
    int arr[MAX] = {2, 4, 6, 8};
    int LB = 0, UB = 4, k, data, loc, i;

    printf("Original Array : \n");
    for(i =0; i<UB; i++)
    {
        printf("%d ", arr[i]);
    }

    if(UB == MAX-1)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("\nEnter the element : ");
        scanf("%d", &data);
        printf("\nEnter the location in the array : ");
        scanf("%d", &loc);

        k = UB;
        loc--;
        while(k>=loc)
        {
            arr[k+1] = arr[k];
            k--;
        }
        arr[loc] = data;
        UB++;

        printf("New Array : \n");
        for(i = 0; i<UB; i++)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}