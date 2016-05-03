#include <iostream>
#include <malloc.h>
using namespace std;
//Given a tree and a sum, return true if there is a path from the root 
// down to a leaf, such that adding up all the values along the path 
// equals the given sum.

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
bool hasPathExist(struct node* temp,int num){
    if(temp==NULL){
        return (num==0);
    }else{
        int newSum=num-temp->data;
        return (hasPathExist(temp->left,newSum) || hasPathExist(temp->right,newSum));
    }
}
int main() {
	struct node* root=newNode(5);
	root->left=newNode(4);
	root->right=newNode(8);
	root->left->left=newNode(11);
	root->left->left->left=newNode(7);
	root->left->left->right=newNode(2);
	root->right->left=newNode(13);
	root->right->right=newNode(4);
	root->right->right->right=newNode(1);
	if(hasPathExist(root,26)){
	    cout<<"Yes";
	}else{
	    cout<<"No";
	}
	return 0;
}
