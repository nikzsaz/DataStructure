#include <iostream>
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
// to convert the binary tree to its mirror image
void mirrorItHard(struct node* temp){
    if(temp==NULL){
        return;
    }else{
        struct node* star;
        mirrorItHard(temp->left);
        mirrorItHard(temp->right);
        star=temp->left;
        temp->left=temp->right;
        temp->right=star;
    }
}

void inorder(struct node* temp){
    if(temp!=NULL){
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}

int main() {
	// your code goes here
	struct node* root=newNode(12);
	root->left=newNode(34);
	root->right=newNode(23);
	root->left->left=newNode(56);
	root->right->right=newNode(98);
    inorder(root);
    mirrorItHard(root);
    cout<<"After mirror"<<endl;
    inorder(root);
	return 0;
}
