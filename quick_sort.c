#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r)
{
    int pivot = r;
    int i = l - 1;
    for (int j = l; j <= r - 1; j++){
        if (arr[j] < arr[pivot]){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[pivot]);
    return (i+1);
}

void quick_sort(int arr[], int l, int r)
{
    if(l < r){
        int p = partition(arr, l, r);
        quick_sort(arr, l, p-1);
        quick_sort(arr, p+1, r);
    }
}

int main(int argc, char const *argv[])
{
    int arr[10] = {2, 8, 9, 0, 1, 3, 4, 7, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, 9);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
