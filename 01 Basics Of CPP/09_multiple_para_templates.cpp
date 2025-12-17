#include<iostream>
using namespace std;

/*
template<class T1, class T2>
class nameOfClass{
        //body
}
        */

template<class T1, class T2>
class myClass{
        public:
                T1 data1;
                T2 data2;

                myClass(T1 a, T2 b){
                        data1 = a;
                        data2 = b;
                }

                void display(){
                        cout<<this->data1<<endl<<this->data2;
                }

};



// using the templates with the default parameters

template<class t1=int, class t2=float, class t3 = char>

class uditya{
        public:
                t1 a;
                t2 b;
                t3 c;
        uditya(t1 x, t2 y, t3 z){
                a = x;
                b = y;
                c = z;
        }
        void display1(){
                cout<<"The value of a is: "<<a<<endl;
                cout<<"The value of b is: "<<b<<endl;
                cout<<"The value of c is: "<<c<<endl;
                cout<<endl;
        }

};

int main(){
        myClass<int, float> obj(2, 3.5f);
        obj.display();

        // calling the default templates
        uditya<> u(3,4.5,'c');
        u.display1();

        uditya<float, float, float> rutu(3.4, 5.6, 6.5);
        rutu.display1();

        uditya<char, char, char> rutu1('c', 'd', 'p');
        rutu1.display1();

        uditya<int, int, int> rutu2(3, 5, 6);
        rutu2.display1();



        return 0;
}