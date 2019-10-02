#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
    char color;
};

struct node* NewNode(int num){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* Insert(struct node* root, int num){
    if(!root)
        return NewNode(num);
    else if(num < root->data)
        root->left = Insert(root->left, num);
    else if(num > root->data)
        root->right = Insert(root->right, num);
    else
        return root;
    
    return root;
}

int main(int argc, char const *argv[])
{
    Node *u = BSTreplace(v); 
  
    // True when u and v are both black 
    bool uvBlack = ((u == NULL or u->color == BLACK) and (v->color == BLACK)); 
    Node *parent = v->parent; 
  
    if (u == NULL) { 
      // u is NULL therefore v is leaf 
      if (v == root) { 
        // v is root, making root null 
        root = NULL; 
      } else { 
        if (uvBlack) { 
          // u and v both black 
          // v is leaf, fix double black at v 
          fixDoubleBlack(v); 
        } else { 
          // u or v is red 
          if (v->sibling() != NULL) 
            // sibling is not null, make it red" 
            v->sibling()->color = RED; 
        } 
  
        // delete v from the tree 
        if (v->isOnLeft()) { 
          parent->left = NULL; 
        } else { 
          parent->right = NULL; 
        } 
      } 
      delete v; 
      return; 
    } 
}
