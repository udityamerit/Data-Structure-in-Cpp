#include<bits/stdc++.h>
using namespace std;

void selectionsort(int arr[], int n){
        for(int i = 0; i<n-1; i++){
                int smallindex = i;
                for(int j = i+1; j<n; j++){
                        if(arr[j]<arr[smallindex]){
                                smallindex = j;
                        }
                }
                swap(arr[i], arr[smallindex]);
        }
        
}

void printarr(int arr[], int n){
        for(int i = 0; i<n; i++){
                cout<<arr[i]<<" ";

        }
        cout<<endl;
}

int main(){
        int n = 5;
        int arr[] = {2,23,67,54,32};
        selectionsort(arr, n);
        printarr(arr, n);
        return 0;
}