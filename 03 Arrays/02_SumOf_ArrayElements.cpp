#include<iostream>
using namespace std;

int main(){
        int size;
        cout<<"Enter the size of the array: ";
        cin>>size;
        int arr[size];
        for(int i=0; i<size; i++){

                cout<<"Enter your arrays element "<<i<<": ";
                cin>>arr[i];

        }

        int summ =0;
        for(int i = 0; i<size; i++){
                summ = summ+arr[i];
        }

        cout<<"Sum of your array is: "<<summ;



        return 0;
}