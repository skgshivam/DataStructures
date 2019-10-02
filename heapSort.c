#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i){
    int lc = 2 * i + 1;
    int rc = 2 * i + 2;
    int max = i;
    if(arr[lc] > arr[max] && lc < n)
        max = lc;
    if(arr[rc] > arr[max] && rc < n)
        max = rc;
    if(max != i){
        swap(&arr[i], &arr[max]);
        heapify(arr, n, max);
    }
}

void heapSort(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for(int i = n - 1; i >= 0; i--){
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
}

int main(int argc, char const *argv[])
{
    int arr[10] = {1, 4, 8, 9, 0, 7, 2, 5, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
