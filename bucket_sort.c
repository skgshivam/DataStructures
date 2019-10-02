#include<stdio.h>
#include<stdlib.h>

struct node{
    float num;
    struct node *next;
};

void swap(struct node *a, struct node *b) 
{ 
    float temp = a->num; 
    a->num = b->num; 
    b->num = temp; 
}

void sort(struct node *start) 
{ 
    int swapped; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
    /* Checking for empty list */
    if (start == NULL) 
        return; 
    do
    { 
        swapped = 0; 
        ptr1 = start; 
        while (ptr1->next != lptr){ 
            if (ptr1->num > ptr1->next->num){  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

struct node * insert(struct node* root, float num){
    struct node* freshnode = (struct node* )malloc(sizeof(struct node));
    freshnode->num = num;
    freshnode->next = root;
    root = freshnode;
    return root;
}

void bucket_sort(float arr[], int n){
    struct node *buck[10] = {NULL};
    for(int i = 0; i < n; i++){
        int ind = arr[i] * 10; 
        buck[ind] = insert(buck[ind], arr[i]);
    }
    for(int i = 0; i < 10; i++){
        sort(buck[i]);
    }
    for(int i = 0; i < 10; i++){
        struct node* temp = buck[i];
        while(temp){
            printf("%f  ", temp->num);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    float arr[15] = {0.12, 0.02, 0.24, 0.91, 0.32, 0.41, 0.22, 0.50, 0.59, 0.72, 0.21, 0.25, 0.205, 0.001, 0.05};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucket_sort(arr, n);
    return 0;
}