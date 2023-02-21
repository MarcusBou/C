#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int arr[], int high, int low){
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++ ){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, high, low);

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
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
    QuickSort(array, 0, length);
    end = clock();
    printArray(array, length - 1);
    double t = (double)(end - start)/CLOCKS_PER_SEC;
    printf("\nTime for sorting: %f seconds", t);
    return 0;
}
