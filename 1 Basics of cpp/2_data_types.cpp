#include<bits/stdc++.h>
using  namespace std;
int main(){

        // int data type
        int x = 2;
        int y = 3;
        cout<<"value of x and y is: "<<x<<" "<<y<<endl;
        // float data type
        float m;
        m = 56.345;
        cout<<"value of m is: "<<m<<endl;

        // char data type
        char ch = 'A';
        cout<<"value of ch is: "<<ch<<endl;

        // double data type
        double d = 345.23234;
        cout<<"value of d is: "<<d<<endl;

        // long data type
        long l = 2432542345;
        cout<<"value of l is: "<<l<<endl;

        // long long data type:
        long long ll = 234234234234234234;
        cout<<"value of ll is: "<<ll<<endl;

        // boolean data type
        bool b = true;
        cout<<"value of b is: "<<b<<endl;

        // string and getline function
        
        // let if the value of s is "hey! you are cool man" than in case of printing the value of s it will print only the first hey!  because the string is terminated by null character 

        // using the getline  function we can print the whole string present in the line 


        string s;
        getline(cin,s);
        // cin>>s;
        cout<<"the string is: "<<s;


        return 0;

}