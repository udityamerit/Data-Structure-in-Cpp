#include<iostream>
using namespace std;

int main(){
        int a = 9; 
        // & ---> (Address of) operator
        int* b = &a;  //it stores the address of a in the b
        cout<<b;  // it is printing the address of the b

        // you also is the print the address of a
        cout<<endl<<&a<<endl;
        
        // * ---> it is called as the dereference operator and it is show the value at the address
        
        cout<<"Value in the b is: "<<*b<<endl;

        return 0;

}