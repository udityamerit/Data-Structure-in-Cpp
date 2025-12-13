#include<iostream>
using namespace std;

int main(){
        // we can make the array in two different way
        // 1st way
        int marks[]= {1,2,3,4};
        for(int i  = 0; i<4; i++){
                cout<<"Marks at "<<i<<" is: "<<marks[i]<<endl;
        }

        // 2nd way
        //taking the input of an array
        int score[3];
        for(int j = 0; j<3; j++){
                cout<<"Enter your "<<j<<"th score: ";
                cin>>score[j];
        }

        //printing the array
        for(int j = 0; j<3; j++){
                cout<<"your "<<j<<"th score is: "<<score[j]<<endl;
        }

        // using the pointer in the array
        int *p = marks; // store the address of marks, because it is already store the address in the p no need to use the & for the address storing in case of arrays
         for(int i  = 0; i<4; i++){
                cout<<"Marks at "<<i<<" is: "<<*p<<endl;
                p = p+1; //increment the pointer by one
        }



        return 0;
}