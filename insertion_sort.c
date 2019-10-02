#include<stdio.h>

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int j = i - 1;
        int key = arr[i]; // Key is important to remember as it can be modified
        while(key < arr[j] && j >= 0){  // Checking the boundary condition of j >= 0 is required.
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char const *argv[])
{
int arr[10] = {1,3,8,9,0,2,4,6,7,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, 10);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;    
}
