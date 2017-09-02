#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
    return (a.second < b.second);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
	    // Pair is used to combine together two values
	    //which may be different in type. Pair provides a way to store two heterogeneous objects as a single unit.
        pair<int,int> arr[n];
        pair<int,int> arr1[n];
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i].first;
            arr1[i].first = arr[i].first;
        }
        
        for(int i = 0 ; i < n ;i++){
            cin>>arr[i].second;
            arr1[i].second = arr[i].second;
        }
        
        sort(arr,arr+n,comp);
        for(int k = 0 ; k < n ;k++){
        if((arr1[k].second == arr[0].second) && (arr1[k].first == arr[0].first))
            cout<<k+1<<" ";
        }
        int count = 1;
        int j = 0;
        for(int i = 1; i < n; i++){
            if(arr[j].second <= arr[i].first){
                count++;
                j = i;
                 for(int k = 0 ; k < n ;k++){
                   if((arr1[k].second == arr[j].second) && (arr1[k].first == arr[j].first)){
                        cout<<k+1<<" ";
                    } 
                }
            }
        }
        cout<<endl;
        
    }
	return 0;
}
