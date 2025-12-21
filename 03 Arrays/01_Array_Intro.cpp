#include<iostream>
#include<array>
using namespace std;

void display(int arr[], int size){
        for(int i = 0; i<size; i++){
                cout<<arr[i]<<" ";
        }
        cout<<endl;
}

int main(){
        int arr[3];
        arr[0] = 9;
        arr[1] = 1;
        arr[2] = 2;
        display(arr, 3);
        cout<<sizeof(arr); // gives me the size in the bites which is 4*3 = 12
        cout<<endl;
        cout<<sizeof(arr)/sizeof(arr[0]); // this is print the length of the array

        // cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
        return 0;
}