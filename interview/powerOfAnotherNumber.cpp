#include <iostream>
#include <queue>
using namespace std;

int main() {
        int t;
        cin>>t;
        while(t--){
            int x,y;
            cin>>x>>y;
            int power = x;
            if(x==1 && y!=1)
                cout<<"0"<<endl;
            else if(x==1 && y ==1)
                cout<<"1"<<endl;
            else if(x>y){
                if(y == 1)
                    cout<<"1"<<endl;
                else
                    cout<<"0"<<endl;
            }
            else{
                while(x<y){
                    x *=power;
                }
                if(x==y)
                    cout<<"1"<<endl;
                else
                    cout<<"0"<<endl;
            }
        }
    
	return 0;
}
