#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/**Link to the question***/
/**http://practice.geeksforgeeks.org/problems/coin-piles/0**/
int main() {
   int t;
   cin>>t;
   while(t--){
       int count = 0;
       int arr[100001];
       int n,k;
       int temp;
       int final = 1000001;
       cin>>n>>k;
       for(int i = 0 ; i < n; i++){
           cin>>arr[i];
       }
       sort(arr,arr+n);
       int loop = 0;
       for(int i = 0 ; i < n ; i++){
           count = loop;
           cout<<"Initial count "<<count;
           for(int j = i+1 ; j < n ; j++ ){
               if((arr[j]-arr[i]) > k ){
                  count+=arr[j] - arr[i] - k;
               }
           }
           cout<<" after processing "<<count<<" element is "<<arr[i]<<endl;
           if(count < final)
                final = count;
            loop+=arr[i];
       }
       cout<<final<<endl;
   }
	return 0;
}
