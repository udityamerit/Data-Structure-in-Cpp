#include<iostream>
using namespace std;

// this is the normal methods
class vector{
        public:
                int *arr;
                int size ;
        
                vector(int m){
                        size = m;
                        arr = new int[size];
                }
        int dotProduct1(vector &v){
                int d = 0;
                for(int i =0; i<size; i++){
                        d = d+ this->arr[i]*v.arr[i];
                        
                }
                return d;
        }
};



// using templates, we use the templates for our one type of data types which it automatically assign the datatypes when i call the class or functions;
template <class T>
class vector1{
        public:
                T *arr;
                int size ;
        
                vector1(int m){
                        size = m;
                        arr = new T[size];
                }
        T dotProduct(vector1 &v){
                T d = 0;
                for(int i =0; i<size; i++){
                        d = d+ this->arr[i]*v.arr[i];
                        
                }
                return d;
        }
};

int main(){
        // vector v1(3);
        // v1.arr[0] = 4;
        // v1.arr[1] = 2;
        // v1.arr[2] = 3;

        // vector v2(3);
        // v2.arr[0] = 1;
        // v2.arr[1] = 4;
        // v2.arr[2] = 3;

        // int a = v1.dotProduct(v2);
        // cout<<a<<endl;


        vector1 <float> v1(3);
        v1.arr[0] = 4.0;
        v1.arr[1] = 0.2;
        v1.arr[2] = 3.9;

        vector1 <float> v2(3);
        v2.arr[0] = 0.1;
        v2.arr[1] = 0.4;
        v2.arr[2] = 0.3;

        float a = v1.dotProduct(v2);
        cout<<a<<endl;

        return 0;
}

/*
So conclusion is if you write the vector<datatype> it is replace the whole codes data type with your given datatype so you can use the multiple datatypes multiple times but you have write you code only one 
*/