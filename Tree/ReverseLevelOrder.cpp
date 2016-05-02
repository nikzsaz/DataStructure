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


void printLevelOrder(struct node* root){
    queue<node*> q;// create a queue of type (struct node*)
    stack<node*> myStack;
    q.push(root);   //push the root
    while(!q.empty())// do it unitl and unless the queue gonna be empty
    {
        node *s=q.front();// take out the front element 
        
        myStack.push(s);
        
        if(s==NULL)// if the queue is empty then return 
        return;
        
        q.pop();// now pop the element print the poped one and again push the left and then right child
        
        printf(" %d ",s->num);
        
        if(s->left)// check if it is null then dont do anything
        q.push(s->left);
        
        if(s->right)
        q.push(s->right);
    }
    printf("\n\n Here is the reverse Level Order\n");
    while(!myStack.empty()){
        
        node *val=myStack.top();
        
        printf(" %d ",val->num);
        
        myStack.pop();
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
    printLevelOrder(root);
	return 0;
}
