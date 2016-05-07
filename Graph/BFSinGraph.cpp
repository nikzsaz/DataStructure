#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX 1001

#define INITIAL 1
#define WAITING 2
#define VISITED 3

int n;
int adj[MAX][MAX];
int state[MAX];
void create_graph();
void BF_traversal();
void BFS(int v);

int queue[MAX],front=-1,rear=-1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

int main(void) {
	create_graph();
	BF_traversal();
	return 0;
}

void BF_traversal(){
    for(int i=0;i<n;i++){
        state[i]=INITIAL;
    }
    int startnode;
    cin>>startnode;
    BFS(startnode);
}

void BFS(int v){
    insert_queue(v);
    state[v]=WAITING;
    while(!isEmpty_queue()){
        v=delete_queue();
        cout<<v<<" ";
        state[v]=VISITED;
        for(int i=0;i<n;i++){
            if(adj[v][i]==1 && state[i]==INITIAL){
                insert_queue(i);
                state[i]=WAITING;
            }
        }
    }
    cout<<endl;
}

void insert_queue(int vertex){
    if(rear==MAX-1)
        cout<<"OVERFLOW";
    else{
        if(front==-1)
            front=0;
        rear++;
        queue[rear]=vertex;
    }
}

int isEmpty_queue()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int delete_queue()
{
    int delete_item;
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    
    delete_item = queue[front];
    front = front+1;
    return delete_item;
} 

void create_graph(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }   
    }
}

