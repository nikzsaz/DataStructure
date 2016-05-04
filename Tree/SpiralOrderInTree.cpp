#include <iostream>
#include <malloc.h>
#include <stack>
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

void PrintSpiral(struct node* temp){
    if(temp==NULL){
        return;
    }    
 // we need to declare two stack in such a way that we push element in stack one 
 // and then we print n pop it then if there is left and right child then we again
 //gonna push that in the second stack again we take element from the top of the 
 // second stack and then same process repets until and unless both the stack 
 //gonnna empty
    stack<node*> s1;
    stack<node*> s2;
    s1.push(temp);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            struct node* val=s1.top();
            s1.pop();
            cout<<val->data<<" ";
            if(val->right)
                s2.push(val->right);
            if(val->left)
                s2.push(val->left);
        }
        
        while(!s2.empty()){
            struct node* val=s2.top();
            s2.pop();
            cout<<val->data<<" ";
            if(val->left)
                s1.push(val->left);
            if(val->right)
                s1.push(val->right);
        }
    }
}

int main() {
	struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    PrintSpiral(root);
	return 0;
}
