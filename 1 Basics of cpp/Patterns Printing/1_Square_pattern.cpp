#include<bits/stdc++.h>
using namespace std;

int main(){
        cout<<"Enter the number of lines for the square pattern: ";
        int n;
        cin>>n;
        for(int i = 1; i<=n; i++){
                for(int j = 1; j<=n; j++){
                        cout<<j<<" ";
                }
                cout<<endl;
        }
        return 0;

}