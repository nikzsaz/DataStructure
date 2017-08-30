#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      int arr[10001];
      for( int  i = 0 ; i < n ; i++){
          cin>>arr[i];
      }
      int min_value = 0;
      int min = INT_MIN;
      for(int i = 0 ; i < n ; i++){
          min_value += arr[i];
          if(min < min_value)
                min = min_value;
          if( min_value < 0)
                min_value = 0;
      }
      cout<<min<<endl;
    }
	return 0;
}
