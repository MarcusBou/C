#include <time.h>
#include <stdio.h>
#include <stdlib.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int arr[], int length){
    for(int i = 0; i < length; i++){
        int temp = i;
        for(int j = i+1; j < length; j++){
            if(arr[j] < arr[temp]){
                    temp = j;
            }
        }
        if (temp != i){
            swap(&arr[temp], &arr[i]);
        }
    }
}

void printArray(int arr[], int length){
    for(int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
}

void randomArray(int arr[], int length){
    srand( (unsigned)time( NULL ) );
    for(int i = 0; i < length; i++){
        arr[i] = rand();
    }
}

int main()
{
    clock_t start, end;
    int length = 100000;
    int array[length];
    randomArray(array, length);
    start = clock();
    sort(array, length);
    end = clock();
    //printArray(array, length);
    double t = (double)(end - start)/CLOCKS_PER_SEC;
    printf("\nTime for sorting: %f seconds", t);
    return 0;
}

