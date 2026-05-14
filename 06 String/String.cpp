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
        vector<string> v1;
        v.push_back("mohan");
        v.push_back("ramesh");
        for(int i=0; i<v.size(); i++){
                cout<<v[i]<<endl;
                sort(v[i].begin(), v[i].end());
                cout<<v[i]<<endl;
        }
        
        //geting the input from the user
        string input_string;
        // getline(cin,input_string);
        // cout<<input_string<<endl;

        // concatenate the strings

        string ne_s = s+sc+*sp;
        cout<<ne_s<<endl;

        // using the substrings
        string sub = "hi,Hello?";
        cout<<sub.substr(3)<<endl;

        //using the loop to print the all substrings
        for(int i = 0 ; i<sub.size(); i++){
                for(int j = )
        }
        return 0;
}