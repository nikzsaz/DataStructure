#include <iostream>
using namespace std;
int arr[10001];
// here we need to swap not only the value but references also so swap with references.
void swap(int *a,int *b){
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}
void insert(int num,int index){
    int parent,temp;
    if(index==0){
        arr[index]=num;
    }else{
        arr[index]=num;
        parent=(index-1)/2;
        while(arr[index]>arr[parent] && parent>=0){
            swap(&arr[index],&arr[parent]);
            index=parent;
            parent=(index-1)/2;
        }
    }
}
int main() {
    int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    int num;
	    cin>>num;
	    insert(num,i);
	}
	for(int i=0;i<n;i++){
	    cout<<arr[i]<<" ";
	}
	return 0;
}
