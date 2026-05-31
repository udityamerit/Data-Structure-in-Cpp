#include<iostream>
#include<string>
using namespace std;

class Creating_object {
    public:
        string name;
        int age;
        string roll;
    
};

int main(){
    // creating object statically
    Creating_object co1, co2, co3; // 3 objects are created

    // created object dynamically
    Creating_object *co4 = new Creating_object;

    co1.name = "uditya";
    co1.age = 24;
    co1.roll = "00cjdke";


    cout<<"Printing the Statically assigned values"<<endl;
    cout<<co1.name<<endl;
    cout<<co1.age<<endl;
    cout<<co1.roll<<endl<<endl;

    //assigning the dynamic way
    (*co4).name = "dynamic assign";
    (*co4).age = 23;
    // (*co4).roll = "ookdsjfl";
    co4->roll = "roll no23";

    // or you can write this  as co4->name = "uditya"

    cout<<"printing the dynamically assigned values"<<endl;
    cout<<co4->name<<endl;
    cout<<co4->age<<endl;
    cout<<co4->roll<<endl;
    return 0;


}