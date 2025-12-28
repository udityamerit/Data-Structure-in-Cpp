#include<iostream>
#include<cmath>
using namespace std;

void display(int a[][5], int m, int n){ //here the rows is optional but the columns are mandatory to mention in array
        for(int i = 0; i<m; i++){
                for(int j=0; j<n; j++){
                        cout<<a[i][j]<<" ";
                }
                cout<<endl;
        }
}

int main(){
        int a[][5] = {{0}};
        display(a, 5,5);
        return 0;
}