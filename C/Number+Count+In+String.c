#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000

int main() {
    char num[MAX];
    char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int i, j, count;
    scanf("%s", num);
    int num_count[10];
    for(j=0; j<10; j++){
        count = 0;
        for(i=0; i<strlen(num); i++){
            if(digit[j]==num[i]){
                count++;
            }
        }
        num_count[j] = count;
    }

    for(i=0; i<10; i++){
        printf("%d ", num_count[i]);
    }

    return 0;
}
