#include<stdio.h>

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min])
            min = j;
        }
        swap(&arr[min], &arr[i]);
    }
}

int main(int argc, char const *argv[])
{
int arr[10] = {1,3,8,9,0,2,4,6,7,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, 10);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;    
}
