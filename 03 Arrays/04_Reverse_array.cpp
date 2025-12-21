#include<iostream>
using namespace std;

int main(){


        int size;
        cout<<"Enter the size of array: ";
        cin>>size;
        int arr[size];
        for(int i = 0; i<size; i++){
                cout<<"Enter the elements: ";
                cin>>arr[i];
        }
        
       int start = 0;
       int end = size-1;
       while(start<=end){
        swap(arr[start], arr[end]);
        start++;
        end--;

       }
       cout<<"Array in reverse order: ";
       for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
       }


        return 0;

}