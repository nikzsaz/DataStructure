#include <iostream>
using namespace std;
bool isHeap(int arr[],int n){
    for(int i=0;i<(n-1)/2;i++){// we gonna iterate it till the last internal node
        if(arr[2*i+1]>arr[i]){
            return false;
            break;
        }
        if(arr[2*i+2]>arr[i]){
            return false;
            break;
        }
    }
}
int main() {
	int arr[]={90, 15, 10, 7, 12, 2, 7, 3};
	int n=sizeof(arr)/sizeof(arr[0]);
	isHeap(arr,n)?cout<<"yes":cout<<"no";
	return 0;
}
