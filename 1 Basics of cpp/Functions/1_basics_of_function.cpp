/*

Functions are set of code which performs something for you
Functions are reusable
Functions are used to modularise code.
Functions are used to increase reasability
Functions are used to use same code multiple times

void ==> which does not return anything
return 
parameterised
non-parameterised
*/

#include<bits/stdc++.h>
using namespace std;
 
void printname(){
        cout<<"hello"<<endl;
}

void hi(string s){
        cout<<"hi "<<s<<endl;
}
int main(){
        printname();
        hi("jello");
        return 0;
}