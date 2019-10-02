#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

void InOrder(struct node* head){
    if(head){
        InOrder(head -> left);
        printf("%d ", head -> data);
        InOrder(head -> right);
    }
}

struct node* NewNode(int num){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = num;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

struct node* Insert(struct node* head, int num){
    struct node* temp = head;
    if (!temp){
        temp = NewNode(num);
        head = temp;
    }
    else if (num < temp -> data)
        temp -> left = Insert(head -> left, num);
    else
        temp -> right = Insert(head -> right, num);
    return head;
}

strcut node* Remove(struct node* head, int num){
    l
}

struct node* SearchNode(struct node* head, int num){
    struct node* temp = head;
    if(!temp)
        return NULL;
    else if(num < temp -> data)
        SearchNode(temp -> left, num);
    else if(num > temp -> data)
        SearchNode(temp -> right, num);
    else if(num == temp ->data)
        return temp;
}

int main(int argc, char const *argv[])
{
    int arr[15] = {3, 2, 22, 32, 41, 1, 21, 89, 8, 92, 10, 99, 123, 68, 55};
    struct node* head = (struct node *)malloc(sizeof(struct node));
    for(int i = 0; i < 15; i++)
        head = Insert(head, arr[i]);
    InOrder(head);
    printf("\n");
    int num_search;
    scanf("%d", &num_search);
    struct node* poin_search = SearchNode(head, num_search);
    if(!poin_search)
        printf("No Such element\n");
    else
        printf("Element exists\n");
    return 0;
}
