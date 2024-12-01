#include<bits/stdc++.h>
using namespace std;

// Time complexity is O(n^2)

void bubblesort(int arr[], int n){

        for(int i= 0; i<n-1; i++){
                for(int j =0; j<n-i-1; j++){
                        if(arr[j]>arr[j+1]){
                                swap(arr[j], arr[j+1]);
                        }
                }
        }
}

void printarry(int arr[], int n){
        for(int i = 0; i<n; i++){
                cout<<arr[i]<<" ";
        }
        cout<<endl;
}
int main(){
        int n = 5;
        int arr[] = {4,2,5,2,3};
        bubblesort(arr, n);
        printarry(arr, n);
        return 0;
}