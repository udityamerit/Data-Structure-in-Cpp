#include<iostream>
using namespace std;

int main(){
        //for loop

        for(int i = 0; i<10; i++){
                cout<<i<<" ";
        }
        cout<<endl;

        //while loop
        int c = 10;
        while(c>2){
                cout<<c<<" ";
                c--;
        }

        // do-while loop
        cout<<endl;
        int p = 10;
        do
        {
                cout<<p+2<<" ";
                p = p-1;
        } while (p!=0);
        
        return 0;
}