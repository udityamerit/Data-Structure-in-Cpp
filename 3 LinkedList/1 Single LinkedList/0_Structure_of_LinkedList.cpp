/*

We are know that in cpp programming language we need to include the packages to use the buildin functions so normally we use the -> 
#include<iostream>
#include<string>
#include<vecotr>
etc... 

so there is a package present in the cpp name " bits/stdc++.h " 
it is includes all the packages inside the cpp language 

so we can use all the buildin functions without including any package.

LinkedList:

A linked list is a linear data structure where each element is a separate object, known as a node.

Each node contains two items:
1. The data, which holds the value of the node.
2. A reference (or link) to the next node in the sequence.
        the reference to the next node should be a pointer.

This structure allows for efficient insertion or removal of elements from any position in the sequence.

Basic structure of the Single LinkedList:

Syntax:
struct node{
        int data;
        Node* next;
        
        Node(int data1, Node* next1){
                data = data1;
                next = next1 or nullptr;
        }
        
}

so that is the basic structure of the single LinkedList  in cpp programming language.

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
        int data;
        Node* next;
        public:
        Node(int data1, Node* next1){
                data = data1;
                next = next1;
        }

};

int main(){
        vector<int> arr = {1,2,3,4,5};
        Node* y = new Node(arr[3], nullptr);
        cout<<y->data;
}
