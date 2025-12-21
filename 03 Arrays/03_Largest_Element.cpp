#include<iostream>
// #include <climits> 
using namespace std;

int main(){

        // int larg = INT_MIN;
        // int sml = INT_MAX;


        int size;
        cout<<"Enter the size of array: ";
        cin>>size;
        int arr[size];
        for(int i = 0; i<size; i++){
                cout<<"Enter the elements: ";
                cin>>arr[i];
        }
        
        int larg = arr[0];
        int sml = arr[0];

        for(int i = 0; i<size; i++){
                if(larg<arr[i]){
                        larg = arr[i];
                }

                if(sml>arr[i]){
                        sml = arr[i];
                }
                
        }

        cout<<"Your Largest Element in the array is: "<<larg<<endl;
        cout<<"Your Smallest Element in the array is: "<<sml;

        return 0;

}