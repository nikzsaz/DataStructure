#include <iostream>
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
        pair<int,int> arr[n];
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i].first;
        }
        
        for(int i = 0 ; i < n ;i++){
            cin>>arr[i].second;
        }
        
        sort(arr,arr+n,comp);
        
        int count = 1;
        int j = 0;
        for(int i = 1; i < n; i++){
       /*     cout<<arr[i].first<< " "<<arr[i].second<<" "<<endl;*/
            if(arr[j].second <= arr[i].first){
                count++;
                j = i;
            }
        }
        cout<<count<<endl;
        
    }
	return 0;
}
