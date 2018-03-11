#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int p , int r){
    // most right element i am selecting as pivot element
    int pivot = arr[r];
    // two point i as -1 and j as current where i keeps tracks
    // of the element smaller than the pivot element
    int i = p - 1;
    for(int j = p ; j <= (r -1) ; j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // at the end put the pivot in the middle 
    int temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    
    return (i+1);
}

void quickSort(int arr[] , int p , int r){
    if(p < r){
        int q = partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}

int main() {
// let's start with the quick sort first
// in the quick sort we have to call the partition procedure
   int n;
   cin>>n;
   int arr[100001];
   
   for(int i = 0 ; i < n ; i++){
       cin>>arr[i];
   }
   
   quickSort(arr,0,n-1);
   
   for(int i = 0 ;i < n ;i++){
       cout<<arr[i]<<endl;
   }

   return 0;
}
