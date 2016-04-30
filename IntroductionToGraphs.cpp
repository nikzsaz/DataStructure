#include <iostream>
#include <cstring>
using namespace std;
const int MAX=101;
int arr[MAX][MAX];
int n=0;
// introduction to graph algorithm

int main() {
    memset(arr,0,MAX*MAX*sizeof(arr[0][0]));
    int index;
	cin>>n>>index;
	int row,col;
	while(cin>>row>>col){
	    arr[row-1][col-1]=1;
	}
	// to add one more node in this graph
	 n++;
   for(int j=0;j<n;j++){
       arr[n][j]=0;
       arr[j][n]=0;
   }

	//to delete index node from the graph, we are deleting the input index (0,1.....) 
    for(int i=index;i<n-1;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=arr[i+1][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=index;j<n-1;j++){
            arr[i][j]=arr[i][j+1];
        }
    }
    n--;
    // after adding the node its upto us that we can add edges also give take the value and put as 1 if there are edges else 0
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        cout<<arr[i][j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
