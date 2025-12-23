#include<iostream>
using namespace std;

int length(char input[]){
        int c = 0; 
        for(int i = 0; input[i]!='\0'; i++){
                c++;
        }
        return c;
}


void reverse(char input[]){
        int s = 0; 
        int l = length(input)-1;
        while (s<l)
        {
                swap(input[s], input[l]);
                l--;
                s++;

        }
        

      
}

int main(){
        char st[40];
        cout<<"Enter the char array:";
        cin.getline(st, 40);
        reverse(st);
        cout<<"your reversed array is : "<<st;

        return 0;
}