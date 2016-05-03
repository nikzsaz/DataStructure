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
//height of the tree is same as the max depth idea
//is to find the length of both left sub tree and right subtree.. see which one is max
// return max with the +1 thats the answer
int treeHeight(struct node* temp){
    if(temp==NULL){
        return 0;
    }else{
        int l=treeHeight(temp->left);
        int r=treeHeight(temp->right);
        if(l>r){
            return (l+1);
        }else{
            return (r+1);
        }
    }
}
int main() {
	// your code goes here
	struct node* root=newNode(12);
	root->left=newNode(34);
	root->right=newNode(23);
	root->left->left=newNode(56);
	root->right->right=newNode(98);
    cout<<treeHeight(root);
	return 0;
}
