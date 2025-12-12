#include<iostream>
using namespace std;

// A variable is a container to hold the data
/*
Types of variables:
-> int, float, char, bool, long
*/


// we can add the same type of variable in the same data types


int glo = 9; // it is the global  variable
void sum(){
        cout<<glo<<endl;
        
}

int main(){
        int glo = 0; // it is a local variable
        cout<<glo<<endl;
        int var = 9;
        sum();
        int a=9, b=19, c=8;
        float f=0.0, g=3.1;
        cout<<a<<endl<<b<<endl<<c<<endl<<f<<endl<<g;
        cout<<"my variable is: "<<var;


        // reference variable
        float y = 78.9;
        float &x =y;
        // here you can see that we have created a reference  variable of y is x and we store the value of y in the x
        cout<<x;

        int t=a;

        cout<<endl<<t;


        // Type casting of the variables

        float X = 90.3;
        int Y = 9;
        cout<<"value of x is: "<<int(X)<<endl;
        cout<<"value of y is: "<<float(Y);

        return 0;
}