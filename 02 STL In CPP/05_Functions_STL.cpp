#include<iostream>
#include<functional>
#include<algorithm>

using namespace std;

int main(){

        // Functional Objects(Functor): Function wrapped in a class so that it available like an object
        int arr[] = {1, 45, 23, 65, 6, 2};
        sort(arr, arr+4); // it is sort the elements from 0 to 4th index in the ascending order
        sort(arr,arr+6, greater<int>());  // it is sort the elements from 0 to 4th index in the descending order

        for(int i  = 0; i<6; i++){
                cout<<arr[i]<<endl;
        }

        return 0;
}