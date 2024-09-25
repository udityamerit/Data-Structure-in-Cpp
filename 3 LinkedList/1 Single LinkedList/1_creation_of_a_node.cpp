#include<bits/stdc++.h>
using namespace std;

struct Node{
        // defining the node data type
        public:
        int data;
        Node* next;

        // creating the constructor 
        Node(int data){
                this->data = data;
                this->next = NULL;
        }

};

int main(){
        // creating a new node object
        Node* node1 = new Node(10);
        cout<<node1->data<<endl;
        cout<<node1->next<<endl;
        
        return 0;
}