#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <cstdio>
using namespace std;
struct node{
    int num;
    struct node* left;
    struct node* right;
};
static int count=0;
// this is a program to make a binary search treee
struct node* newNode(int num){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->num=num;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node* insert(struct node* root,int num){
    if(root==NULL){
       return newNode(num);
    }
    if(root->num<num){
        root->right=insert(root->right,num);
    }else{
        root->left=insert(root->left,num);
    }
    return root;
}
void leafNode(struct node* root){
    if(root!=NULL){
        if(root->left==NULL && root->right==NULL)
            count++;
        leafNode(root->left);
        leafNode(root->right);
    }
}


int main(void) {
    struct node* root=NULL;
    root=insert(root,6);
    insert(root,12);
    insert(root,78);
    insert(root,23);
    insert(root,54);
    insert(root,51);
    leafNode(root);
    printf(" %d ",count);
	return 0;
}
