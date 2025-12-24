#include<iostream>

using namespace std;

int main(){
        int arr[10][10];
        int m,n;
        cin>>m>>n;
        for(int i = 0; i<m; i++){
                for(int j=0; j<n; j++){
                        cin>>arr[i][j];
                }
                
        }
        //output for 2d matrix; row wise printing
        cout<<"Row wise printing"<<endl;
        for(int i = 0; i<m; i++){
                for(int j=0; j<n; j++){
                        cout<<arr[i][j]<<" ";
                }
                cout<<endl;
        }

        cout<<"column wise printing"<<endl;

        for(int i = 0; i<n; i++){
                for(int j=0; j<m; j++){
                        cout<<arr[j][i]<<" ";
                }
                cout<<endl;
        }
        
        return 0;
}
