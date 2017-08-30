#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int count = 0;
        int n,k;
        cin>>n>>k;
        int arr[100001];
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        for(int i = 0 ; i < n ; i++){
            if(arr[i] <= k){
                k-=arr[i];
                count++;
            }else{
                break;
            }
        }
        cout<<count<<endl;
    }
	return 0;
}
