#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node* newNode(struct node* root, int num){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = num;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

struct node* rightRotate(struct node* root){
    struct node* y = root->left;
    struct node* yr = y->right;
    y->right = root;
    root->left = yr;
    return y;
}

struct node* leftRotate(struct node* root){
    struct node* y = root->right;
    struct node* yl = y->left;
    y->left = root;
    root->right = yl;
    return y;
}

int a;
int height(struct node* N){
    if(N == NULL)
        return 0;
    else if(N->left == NULL && N->right == NULL)
        return 1;
    else
        return (1 + (height(N->left) > height(N->right) ? height(N->left) : height(N->right)));    
}

int getBalanceFactor(struct node* root){
    if(root != NULL)
        return height(root->left) - height(root->right);
    else
        return 0;
}

struct node* Insert(struct node* root, int num){
    int balance_factor;
    if (root == NULL)
        return newNode(root, num);
    else if (num < root->data)
        root->left = Insert(root->left, num);
    else if (num > root->data)
        root->right = Insert(root->right, num);
    else
        return root;
    
    balance_factor = getBalanceFactor(root);
    // Left-left Case
    if(balance_factor > 1 && num < root->left->data)
        return rightRotate(root);

    // Left-right Case
    if(balance_factor > 1 && num > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    // Right-right Case
    if(balance_factor < -1 && num > root->right->data)
        return leftRotate(root);

    // Right-left Case
    if(balance_factor < -1 && num < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

struct node* Delete(struct node* root, int num){

}

// void InOrder(struct node* root){
//     if(root != NULL){
//         printf("%d ", root->data);
//         InOrder(root->left);
//         InOrder(root->right);
//     }    
// }

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
} 

void printLevelOrder(struct node* root) 
{ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
    { 
        printGivenLevel(root, i); 
        printf("\n"); 
    } 
} 
  


int main(int argc, char const *argv[])
{
    struct node *root = NULL;   // Never initialise it without NULL like this (struct node *root;)
    int option, num;
    while(option){
        printf("Select an option:\n1.Insert\n2.Delete\n3.Print(Inorder)\n0.Exit\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter the number to Insert:\n");
                scanf("%d", &num);
                root = Insert(root, num);
                break;
            case 2:
                printf("Enter the number to Delete:\n");
                scanf("%d", &num);
                root = Delete(root, num);
                break;
            case 3:
                printf("\n");
                printLevelOrder(root);
                printf("\n");
                break;
            case 4:
                return 0;
                break;
        }
    }
    return 0;
}
