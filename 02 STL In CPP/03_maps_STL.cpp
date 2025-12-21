#include<iostream>
#include<map>
using namespace std;


int main(){

        // it is store the key value pairs like a dictionary
        map<string, int> marks;
        marks["uditya"] = 90;
        marks["sai"] = 98;
        marks["kirti"] = 99;
        marks["rutu"] = 97;
        marks.insert({{"rohan", 123}, {"ramu", 56}});

        // accessing the elements
        map<string, int>:: iterator iter;
        for(iter = marks.begin(); iter!=marks.end(); iter++){
                cout<<(*iter).first<<" "<<(*iter).second<<"\n";

        }

        return 0;
}