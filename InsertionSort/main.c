#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int length){
    int key, j;
    for(int i = 1; i < length; i++){
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j-1;
        }
        arr[j + 1] = key;
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
    insertionSort(array, length);
    end = clock();
    //printArray(array, length);
    double t = (double)(end - start)/CLOCKS_PER_SEC;
    printf("\nTime for sorting: %f seconds", t);
    return 0;
}
