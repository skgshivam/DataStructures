#include<stdio.h>

int merge(int arr[], int l, int r){ 
    int m = (l + r) / 2;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];
    int p = 0;
    int q = 0;
    int r2 = l;
    for (p, q, r2; p < n1 && q < n2; r2++){
        if (L[p] < R[q]){
            arr[r2] = L[p];
            p++;
        }
        else{
            arr[r2] = R[q];
            q++;
        }
    }
    for (p; p < n1; p++, r2++)
        arr[r2] = L[p];
    for (q; q < n2; q++, r2++)
        arr[r2] = R[q];
    
}

int merge_sort(int arr[], int l, int r){
    int m = (l + r) / 2;
    if(l < r){
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, r);
    }
}

int main(int argc, char const *argv[])
{
    int arr[10] = {5, 3, 2, 7, 9, 0, 8, 1, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, 9);
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    return 0;
}