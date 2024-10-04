#include<bits/stdc++.h>
using namespace std;

int main(){
           //vector
           // intitialisation
        vector<int> v;
           // check the size of the vector v
        cout<<"capacity of the vector "<<v.capacity()<<endl;


        // difference between the capacity of a vector and size of a vector

        // so capacity tells us how much element vector can store. 

        // where size tells us how many element present in the vector.

        cout<<"size of the vector "<<v.size()<<endl;

        // we can add the elements in the vector using push_front and push_back operation or method

        v.push_back(3424);
        v.push_back(24);
        v.push_back(44);
        cout<<"size of the  vector is: "<<v.size()<<endl;
        cout<<"capacity of the vector is: "<<v.capacity()<<endl;

        // accessing the elementns of the front and last of any vector: we have to use the front and back operation
        cout<<"front element of a vector is: "<<v.front()<<endl;
        cout<<"last element of the vector is: "<<v.back()<<endl;

        // printing all the elements of the vector :
        for(int i:v){
                cout<<i<<" ";
        }

        // copy the vector to another vector:
        
        vector<int> a(5,3); // a(5,3) create a vector and assign the 5 times 3 in the vector a
        // print the vector a
        for(int i: a){
                cout<<i<<" ";
        }

        vector<int> b(a);
        // print the vector b
        
        for(int i: b){
                cout<<i<<" ";
        }

        return 0;


}