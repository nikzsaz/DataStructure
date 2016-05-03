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
// one idea is to iterate through the inorder or any order and compare every element in the same order
// another is use of recursion in which we compare every element of the tree
bool identicalTree(struct node* temp1,struct node *temp2){
    if(temp1==NULL && temp2==NULL){
        return true;
    }else{
        return (temp1->data==temp2->data && identicalTree(temp1->left,temp2->left) && identicalTree(temp1->right,temp2->right));
    }
}

int main() {
	// your code goes here
	struct node* root=newNode(12);
	root->left=newNode(34);
	root->right=newNode(23);
	root->left->left=newNode(56);
	root->right->right=newNode(98);
	
	struct node* root1=newNode(12);
	root1->left=newNode(34);
	root1->right=newNode(23);
	root1->left->left=newNode(56);
	root1->right->right=newNode(98);
	
	if(identicalTree(root,root1)){
	    cout<<"They are identical";
	}else{
	    cout<<"No they are not identical";
	}
	
	return 0;
}
