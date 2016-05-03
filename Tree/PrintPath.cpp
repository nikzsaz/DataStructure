#include <iostream>
#include <malloc.h>
#include <vector>
using namespace std;
//iven a binary tree, print out all of its root-to-leaf paths as defined above
struct node{
    int data;
    struct node* left;
    struct node* right;
};
vector<node*> vec;
void printArray(struct node* temp){
    for(int i=0;i<vec.size();i++){  
        struct node* val=vec[i];
        cout<<val->data<<" ";
    }
     cout<<temp->data<<" ";
    cout<<endl;
}

struct node* newNode(int key){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}



void printPath(struct node* temp){
    if(temp==NULL){
        return;
    }
    if(temp->left==NULL && temp->right==NULL){
        printArray(temp);
    }
    else{
        vec.push_back(temp);
        printPath(temp->left);
        printPath(temp->right);
        vec.pop_back();
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
	printPath(root);
	return 0;
}
