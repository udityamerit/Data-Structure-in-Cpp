#include<iostream>
using namespace std;
/*
In this we are going to see the mainly three types of functions where we are mostly we use all these functions. for different different purpose.
1. Function call by value
2. Function call by reference
3. Function call by pointer
*/

//1. Function call by value:
void swapnums(int a, int b){
        int temp = a; 
        a = b;
        b = temp;
        cout<<"value of a: "<<a<<" and value of b: "<<b<<endl;

}

// 2. Function call by reference:
void swapingoriginal(int &a, int &b){
        int t = a;
        a = b; 
        b = t;
        cout<<"value of a: "<<a<<" and value of b: "<<b<<endl;

}

// Function call by pointers:
void usepointer(int *a, int*b){
        int t = *a;
        *a = *b;
        *b = t;
        cout<<"value of a: "<<*a<<" and value of b: "<<*b<<endl;

}

int main(){
        int x = 9, y = 8;
        cout<<"swapping the numbers using call by value:\n";
        swapnums(x, y);
        cout<<"value of x and y after using call by value swapping "<<"x: "<<x<<" y: "<<y<<endl;

        cout<<"swapping the numbers using the call by reference:\n";
        swapingoriginal(x, y);
        cout<<"value of x and y after using call by reference swapping "<<"x: "<<x<<" y: "<<y<<endl;

        cout<<"swapping the numbers using the call by pointer:\n";
        usepointer(&x, &y);

        cout<<"value of x and y after using call by pointer swapping "<<"x: "<<x<<" y: "<<y<<endl;

        swap(x, y);
        cout<<"Using the swap function: x = "<<x<<" and y= "<<y;
        return 0;
}

/*

Here the conclusion is if we are use the call by value it is not going to change any original value

but, if we use the call by reference or call by pointer it is use the original memory address for performing the operations on the variables. so these two methods are able to change the original variables 

*/