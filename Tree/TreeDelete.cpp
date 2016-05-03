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
//delete tree node.. To delete node we must need to access all element so
// we need to traverse.. now the question is which traversing inorder pre post
// answer is post coz we need to first delete the child then parent so only
// post is option we left with :)
void deleteTree(struct node* temp){
    if(temp!=NULL){
        deleteTree(temp->left);
        deleteTree(temp->right);
        cout<<temp->data<<" ";
        free(temp);
    }
}
int main() {
	// your code goes here
	struct node* root=newNode(12);
	root->left=newNode(34);
	root->right=newNode(23);
	root->left->left=newNode(56);
	root->right->right=newNode(98);
    deleteTree(root);
    root=NULL;// to make the root point again to NULL
    cout<<"Now the tree is deleted";
	return 0;
}
