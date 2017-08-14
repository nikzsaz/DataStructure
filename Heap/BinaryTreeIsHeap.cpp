#include <iostream>
#include <queue>
#include <malloc.h>
using namespace std;
struct node{
    int num;
    struct node* left;
    struct node* right;
};
       
struct node *newNode(int key){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->num=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int height(struct node* root){
    if(root==NULL){
        return 0;
    }
    int l=1+height(root->left);
    int r=1+height(root->right);
    if(l>r){
        return l;
    }else{
        return r;
    }
}

bool bfs(struct node* root){
    bool b;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *temp=q.front();
        q.pop();
        int l=height(temp->left);
        int r=height(temp->right);
        int d=l-r;// it is assumed that in completeBinaryTree node should be as left as possible
        if(d>1 || d<0){
            b=false;
            break;
        }else{
            b=true;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return b;
}

bool isHeapUtil(struct node* root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }    
    if(root->right==NULL){
        return (root->num>=root->left->num);
    }else{
        if(root->num>=root->left->num && root->num>=root->right->num)
            return (isHeapUtil(root->left) && isHeapUtil(root->right));
        else
            return false;
    }
}

bool IsBinaryHeap(struct node *root){
    if(bfs(root)&&isHeapUtil(root))
    return true;
    else 
    return false;
}

int main() {
    
    struct node* root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);
    
    if(IsBinaryHeap(root)){
        cout<<"GIVEN BINARY TREE IS HEAP";
    }else{
        cout<<"GIVEN BINARY TREE IS NOT HEAP";
    }
	return 0;
}
