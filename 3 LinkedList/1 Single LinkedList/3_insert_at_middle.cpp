#include<bits/stdc++.h>
using namespace std;


// create a node:
struct Node{
        public:
        int data;
        Node* next;

        // creating the constructor
        Node(int data){
                this->data = data;
                this->next = NULL;
        }
};


// intert the node at head:
void insertathead(Node* &head, int dataa){
        Node* temp = new Node(dataa);
        temp->next = head;
        head = temp;
}

// creating a function to show the data of linkedlist:
void printdata(Node* &head){
        Node* temp = head;
        while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
        }
}
int main(){

        // creating a node
        Node* node1 = new Node(10);
        Node* head = node1;
        // cout<<node1->data;

        // insert the node;
        insertathead(head, 40);
        printdata(head);



        return 0;
}