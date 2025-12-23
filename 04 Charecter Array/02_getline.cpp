#include<iostream>
using namespace std;

int main(){
        // in case of cin it is stop taking input when it is encounter the space, tab or new line in case of the string or chars

        // so we have solve this isues using the cin.getline() function;

        // char name[15];
        // cout<<"What is your name: ";
        // cin>>name;
        // cout<<"your name is: "<<name;
        // cout<<endl;

        //using cin.getline()
        char inp[100];

        cout<<"Give the input: ";
        cin.getline(inp, 50, 'i'); // the third parameter it tells us where you stop the string
        
        cout<<"output using getline(): "<<inp;


        return 0;
}