#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b; 
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}


int main(int argc, char const *argv[])
{
int arr[10] = {1,3,8,9,0,2,4,6,7,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, 10);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;    
}
