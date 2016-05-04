#include <iostream>
#include <malloc.h>
#include <queue>
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

void increment(struct node* temp,int diff){
    if(temp->left){
        temp->left->data=temp->left->data+diff;
        increment(temp->left,diff);
    }else if(temp->right){
        temp->right->data=temp->right->data+diff;
        increment(temp->right,diff);
    }
}

void changeTree(struct node* temp){
    int leftval=0,rightval=0,diff;
    if(temp==NULL || (temp->left==NULL && temp->right==NULL)){
        return;
    }else{
        changeTree(temp->left);
        changeTree(temp->right);
        if(temp->left)
            leftval=temp->left->data;
        if(temp->right)
            rightval=temp->right->data;

        diff=leftval+rightval-temp->data;
        if(diff>0){
            temp->data=temp->data+diff;
        }else if(diff<0){
            increment(temp,-diff);
        }
    }
}

void inorder(struct node* temp){
    if(temp!=NULL){
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}
int main(){
    struct node *root = newNode(50);
    root->left        = newNode(7);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(5);
    root->right->left  = newNode(1);
    root->right->right = newNode(30);
    inorder(root);
    changeTree(root);
    cout<<"After the change"<<endl;
    inorder(root);
	return 0;
}