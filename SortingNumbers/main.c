#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {3,12,34,12,31,42,56,32,123,3,4,5,6,2,1,4,7,8,9,21,31,24,35};
    int LEN = sizeof(arr)/sizeof(int);
    for(int i = 0; i < LEN; i++){
        for(int j = 0; i < LEN - i - 1; i++){
            if (arr[i] > arr[j + 1]){
                int a = arr[i];
                arr[i] = arr[j+ 1];
                arr[j + 1] = a;
            }
        }
    }
    for(int i = 0; i < LEN; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
