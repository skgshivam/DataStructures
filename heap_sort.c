#include<stdio.h>

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int max_heapify(int arr[], int i, int n){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;
    if (arr[left] > arr[max] && left < n)
        max = left;
    if (arr[right] > arr[max] && right < n)
        max = right;
    if (max != i){
        swap(&arr[i], &arr[max]);
        max_heapify(arr, max, n);
    }
}

int min_heapify(int arr[], int i, int n){

}

int heap_sort(int arr[], int n){
    for (int i = n/2; i >= 0; i--)
        max_heapify(arr, i, n);
    for (int i = n - 1; i >= 0; i--){
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i);
    }
}

int main(int argc, char const *argv[])
{
    int arr[10] = {5,2,3,1,8,9,0,7,6,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    heap_sort(arr, n);
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}