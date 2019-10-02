#include<stdio.h>

void counting_sort(int arr[], int n){
    int min = 0;
    int max = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < arr[min])
            min = i;
        if(arr[i] > arr[max])
            max = i;
    }
    int range = arr[max] - arr[min] + 1;
    int count[range];
    int output[n];
    for(int i = 0 ; i < range; i++)     // Don't forget to initialise it 
        count[i] = 0;
    for(int i = 0; i < n; i++){
        count[arr[i] - arr[min]]++; // For min element count is 0 and for maxm element the count is max - min
    }
    for(int i = 1; i < range; i++){
        count[i] += count[i - 1];
    }
    for (int i = 0; i < n; i++){
        output[count[arr[i] - arr[min]] - 1] = arr[i];  // Each element should be placed at one element less than the the position
        count[arr[i] - arr[min]] --;    // in the count
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main(int argc, char const *argv[])
{
    int arr[10] = {1,3,8,9,0,2,4,6,7,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    counting_sort(arr, 10);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
