#include<iostream>
using namespace std;

struct node{
    int i;
    struct node *next;
};

struct node* insert_beg(struct node *head, int num){
    struct node *new = (struct node *)malloc(sizeof(struct node));
}

struct node * insert_mid(struct node *head, int num){

}

struct node * insert_end(struct node *head, int num){

}

void print(struct node *head){
    struct node *temp = head;
    while(temp){
        cout << temp->i << "\n";
        temp = temp -> next;
    }
}

int main(int argc, char const *argv[])
{
    int num_elem, option, elem;
    cout << "No. of elements to insert\n:";
    cin >> num_elem;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    cout << "B,M,E\n";
    cin >> option;
    cout << "Enter\n";
    cin >> elem;
    switch(option){
        case 0:
            head = insert_beg(head, elem);
            break;
        case 1:
            head = insert_mid(head, elem);
            break;
        case 2:
            head = insert_end(head, elem);
            break;
    }
    return 0;
}
