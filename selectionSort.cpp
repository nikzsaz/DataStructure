 #include <iostream>
#include <algorithm>
using namespace std;

int main() {
   // this is the program for the selection sorted
   int n;
   cin>>n;
   int arr[100001];
   for(int i = 0 ; i < n ; i++){
       cin>>arr[i];
   }
   // in selection sort i used to select all the element one 
   // after another and assume that element to be minimum. 
   int min,pos;
   for(int i = 0 ; i < n ;i++){
       min = arr[i];
       pos = i;
       for(int j = i+1 ; j < n ;j++){
           //then i really find whether the assumed element is 
           // actually minimum or not if not then i find the minimum
           //element from the selection and update the same
           if(arr[j]<min){
               min = arr[j];
               pos = j;
           }
       }
       // once i'll able to find the real minimum element then 
       // i can swap the values
       int temp = arr[i];
       arr[i] = arr[pos];
       arr[pos] = temp;
       // after this i am sure that 1 minimum element 
       // is sorted and placed at the right position
   }
    
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<endl;
    }
	return 0;
}
