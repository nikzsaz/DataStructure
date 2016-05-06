#include <iostream>
#include <cstdlib>
using namespace std;
struct  node{
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
bool isBalanced(struct node* temp){
    int lh;
    int rh;
    if(temp==NULL){
        return true;
    }
    lh=isBalanced(temp->left);
    rh=isBalanced(temp->right);
    if(abs(lh-rh)<=1 && isBalanced(temp->left) && isBalanced(temp->right));
    return true;
    return false;
}
int main() {
	// your code goes here
	struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
    
    if(isBalanced(root)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
	return 0;
}
