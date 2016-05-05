#include <iostream>
#include <stack>
#include <malloc.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int key){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void inorderMy(struct node* temp){
    stack<node*> s;// first we will make a stack
    struct node* current=temp;
    while(current!=NULL || !s.empty()){
        //check either the current node  is null or the stack is empty
    while(current!=NULL){
    // do push the elements until and unless there is element in the tree
        s.push(current);
        current=current->left;
        // try to go as left as possible 
    }
    // if there is no left element then pop that and go to right
        struct node* val=s.top();
        cout<<val->data<<" ";
        s.pop();
        current=val->right;
}
}

int main() {
    struct node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    
    inorderMy(root);
	return 0;
}
