#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
        // initializing the string statically
        string sc;
        sc = "hi i am a student";
        cout<<sc<<endl;

        string s = "hello";
        cout<<s<<endl;
        
        // initializing the string dynamically
        string *sp = new string;
        *sp = "Hello i am dynamic";
        cout<<sp<<endl;
        cout<<*sp<<endl;

        // using the vectors to initializing the 2d string using the vectors
        vector<string> v;
        v.push_back("mohan");
        v.push_back("ramesh");
        

        return 0;
}