#include<stdio.h>
// In all the functions of merge and quick sort we need to pass arr, l and r

void merge(int arr[], int l, int r){
    int m = (l + r) / 2;
    int n1 = m - l + 1; // +1 is added here as the left merge should include the middle element also
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];
    int i = 0;  // Determines the first index of the left merge
    int j = 0;  // Determines the first index of the right merge
    int k = l;  // Determines the first index of the merged array; it should start from l and not zero
    for (i, j, k; i < n1 && j < n2; k++){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
    }
    for (i; i < n1; i++, k++)
        arr[k] = L[i];
    for (j; j < n2; j++, k++)
        arr[k] = R[j];
}

void mergeSort(int arr[], int l, int r){  // The formal arguement is arr[] and not arr
    if (l < r){
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, r);
    }
}

int main(int argc, char const *argv[])
{
    int arr[10] = {1,3,8,9,0,2,4,6,7,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, 9);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}