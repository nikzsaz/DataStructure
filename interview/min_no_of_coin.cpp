#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    int t;
    cin>>t;
    while(t--){
        int j = 0;
        int count[10001];
        int currency;
        cin>>currency;
        for(int i = n-1 ; i >=0 ; i-- )
        {
            while(currency >= arr[i]){
                currency-=arr[i];
                count[j++] = arr[i];
            }
        }
        
        for(int i = 0 ;i < j ;i++){
            cout<<count[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
