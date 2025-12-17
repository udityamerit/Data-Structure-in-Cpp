#include<iostream>
#include"01_basics.cpp"

using namespace std;

// functions and its prototypes

int sum(int a, int b){
        int c = a+b;
        return c;
}

// function prototyping means it is tell the compiler to search the function it is not finds in upper or before the main function, so basically it is force to search the function before throwing an error for that function

void g(); // this is function prototyping

int main(){
        // use();
        int num1, num2;
        cout<<"enter the num1 "<<endl;
        cin>>num1; 
        cout<<"enter the num2 "<<endl;
        cin>>num2;
        cout<<sum(num1, num2); 
        g();


        return 0;
}

void g(){
        cout<<"\nhello guy's";
}