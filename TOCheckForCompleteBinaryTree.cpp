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

int main() {
    struct node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    cout<<height(root)<<endl;
    
    if(bfs(root))
    cout<<"COMPLETE";
    else
    cout<<"INCOMPLETE";
	return 0;
}
