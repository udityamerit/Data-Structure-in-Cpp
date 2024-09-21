#include<bits/stdc++.h>
using namespace std;

// pass by vlaue
void vlaue(int x, int y){
        cout<<"function using call by value"<<endl;
        cout<<x<<" "<<y<<endl;

}
// pass by address
void val(int *i, int *j){

        cout<<"function using call by address"<<endl;
        *i = *i+1;
        *j = *j+1;
        cout<<*i<<" "<<*j<<endl;

}

// pass by referance
void value(int &x, int &y){
        cout<<"function using call by referance"<<endl;
        x++;
        y++;
        cout<<x<<" "<<y<<endl;
}

int main(){
        int x = 5, y = 10;
        // call by value
        vlaue(x,y);
        cout<<x<<" "<<y<<endl;

        // call by referance
        value(x, y);
        cout<<x<<" "<<y<<endl;

        // call by address
        val(&x, &y);
        cout<<x<<" "<< y<<endl;

        return 0;
}