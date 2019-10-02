#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r){
    int pivot = r;  // Better if you take the index instead of value
    int i = l - 1;  // Cannot be l instead of l - 1
    for (int j = l; j < r; j++){
        if(arr[j] < arr[pivot]){
            i++;
            swap(&arr[i], &arr[j]);     // Swap i and j
        }
    }
    swap(&arr[i + 1], &arr[pivot]);     // Swap i + 1 and pivot
    return (i + 1);
}

int quickSort(int arr[], int l, int r){
    if(l < r){
        int p = partition(arr, l, r);  // Cannot be outside the if statement
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);   // p is not involved here
    }
}

int main(int argc, char const *argv[])
{
    int arr[10] = {1,3,8,9,0,2,4,6,7,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, 9);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
