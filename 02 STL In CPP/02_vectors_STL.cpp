#include<iostream>
#include<vector>

using namespace std;

// Template function to display any vector
template<class T>
void display(vector<T> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

// Template function to handle vector input
template<class T>
void inputVector(vector<T> &v) {
    int size;
    cout << "Enter the size of vector: ";
    cin >> size;
    
    for (int i = 0; i < size; i++) {
        T el; // The type T now matches the vector's type
        cout << "Enter element " << i + 1 << ": ";
        cin >> el;
        v.push_back(el);
    }
}

int main(){
        /*
        // Now you can easily switch between types
        vector<int> v1; 


        inputVector(v1); // Works correctly for char, int, etc.
        // v1.pop_back();
        display(v1);

        vector<int>::iterator iter =  v1.begin(); // the iter is point the 0th position of the vector
        v1.insert(iter, 566);
        v1.insert(iter+4, 2, 34); // iter+3 move the iter to the 3rd position of the vector, 2 is tell that the make a 2 copy of the 34 from the 3rd index
        display(v1);

        */

       vector<int> v1; // zero length integer vector

//        vector<char> v2(4); // 4-element char vector with space
//        v2.push_back('8');
//        display(v2);

//        vector <char> v3(v2); // making the v3 from v2
//        display(v3);

        vector<int> v4(6, 23); //it say's that make a int vector of 23 and make a copy of 23 6 times
        display(v4);
        return 0;
}
