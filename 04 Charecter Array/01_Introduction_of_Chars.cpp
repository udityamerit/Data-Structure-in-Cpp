#include<iostream>
using namespace std;

// finding the length of the string
int length(char input[]){
        int c = 0;
        for(int i = 0; input[i]!='\0'; i++){
                c = c+1;
               
        }
        return c;
}

int main(){
        char name[10];
        cout<<"Enter your name: ";
        cin>>name;
        cout<<"Your name is: "<<name<<endl; 

        int size = length(name);
        cout<<"Size of the name is: "<<size;

        
        
        return 0;
}