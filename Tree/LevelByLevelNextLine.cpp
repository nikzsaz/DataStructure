#include <iostream>
#include <malloc.h>
#include <queue>
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
 //level order traversal line by line
void levelOrderLineByLine(struct node* temp){
    if(temp==NULL)
    return;
// make a queue and then push the root node
    queue<node*> q;
    q.push(temp);
    while(1){
// run the infinite loop and until and unless the sizeof queue is not zero
        int count=q.size();
        if(count==0)
            break;
        while(count>0){
            struct node* val=q.front();
            cout<<val->data<<" ";
            q.pop();
            // push the values of the next level
            if(val->left)
                q.push(val->left);
            if(val->right)
                q.push(val->right);
            count--;
        }
        cout<<endl;
    }
    
}
 
int main(){
    struct node* root=newNode(10);
    root->left= newNode(8);
    root->right= newNode(2);
    root->left->left= newNode(3);
    root->left->right= newNode(5);
    root->right->right= newNode(2);
    levelOrderLineByLine(root);
	return 0;
}