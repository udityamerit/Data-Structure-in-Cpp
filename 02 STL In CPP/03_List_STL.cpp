#include<iostream>
#include<list>
using namespace std;

void display(list<int> &li){
        list<int> :: iterator it;
        for( it=li.begin(); it!=li.end(); it++){
                cout<<*it<<" ";
        }
        cout<<endl;
}
int main(){

        list<int> list1; // List of 0 length
       
        list1.push_back(5);
        list1.push_back(3);
        list1.push_back(2);
        list1.push_back(3);
        list1.push_back(6);

        display(list1);
        // // remove operations on the list
        // list1.pop_back(); // removing the elements from back
        // display(list1);
        // list1.pop_front(); // removing the elements from front
        // display(list1);
        // list1.remove(2); // removing the specific element
        // display(list1);

        // // sorting the list
        // list1.sort();
        // display(list1);



        list<int> list2(7); // Empty list of size 7
        list<int> :: iterator itr;
        itr = list2.begin();
        *itr = 43;
        itr++;
        *itr = 4;
        itr++;
        *itr = 3;
        itr++;
        display(list2);  // in the output you got the list as [43 4 3 0 0 0 0] because you have created a list of length of 7 which is initially filled with 0

        // merging the lists
        list1.merge(list2);
        cout<<"list 1 after merging ";
        display(list1);
        cout<<"reversing the list: ";
        list1.reverse();
        display(list1);
        cout<<"sorting the list ";
        list1.sort();
        display(list1);

        
        return 0;
}