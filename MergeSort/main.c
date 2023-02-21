#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int splitter, int right){
    int i, j, k;
    int L = splitter - left + 1;
    int R = right - splitter;
    int Lft[L], Rgt[R];

    for(i = 0; i < L; i++){
        Lft[i] = arr[left + i];
    }
    for(i = 0; i < R; i++){
        Rgt[i] = arr[splitter + 1 + i];
    }

    i = 0;
    j = 0;
    k = left;
    while(i < L && j < R){
        if(Lft[i] <= Rgt[j]){
            arr[k] = Lft[i];
            i++;
        }
        else{
            arr[k] = Rgt[j];
            j++;
        }
        k++;
    }
    while (i < L){
        arr[k] = Lft[i];
        i++;
        k++;
    }
    while (j < R){
        arr[k] = Rgt[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int m = left + (right-left) / 2;

        mergeSort(arr, left, m);
        mergeSort(arr, m + 1, right);

        merge(arr, left, m, right);
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

int main(){
    clock_t start, end;
    int length = 100000;
    int array[length];
    randomArray(array, length);
    start = clock();
    mergeSort(array, 0, length - 1);
    end = clock();
    printArray(array, length);
    double t = (double)(end - start)/CLOCKS_PER_SEC;
    printf("\nTime for sorting: %f seconds", t);
    return 0;
}
