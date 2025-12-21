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

/*
Here you need to know the what is the segmentation fault or run time error in the array:

so if you initialize the int a[10];
        and you are try to run the cout<<a[10000];
        it gives you the error of runtime (which say's that the you are trying to access a memory which is not yours)

        cout<<a[-1] gives you the run time error

        we can make the array of maximum a[10^6] 
*/