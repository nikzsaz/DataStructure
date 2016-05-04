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
 
bool isChildSum(struct node* root){
    int leftval=0,rightval=0;
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return true;
    }
    else{
        if(root->left!=NULL)
        leftval=root->left->data;
        rightval=root->right->data;
        if(root->data==leftval+rightval)
             return (isChildSum(root->left) && isChildSum(root->right));
        else
            return false;
    }
}
 
int main(){
    struct node* root=newNode(10);
    root->left= newNode(8);
    root->right= newNode(2);
    root->left->left= newNode(3);
    root->left->right= newNode(5);
    root->right->right= newNode(2);
    if(isChildSum(root)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
	return 0;
}