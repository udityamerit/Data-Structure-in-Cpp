#include<bits/stdc++.h>
using namespace std;

struct Node{
        public:
        int data; 
        Node* next;

        // constructor
        Node(int data){
                this ->data = data;
                this ->next = NULL;
        }
};

// creating a fuction for the insersion of the node at the start of linked list

void Insertathead(Node* &head, int d){
        // creating a node
        Node* temp = new Node(d);
        temp->next  = head;
        head = temp;
}

// function for printin the elements of the linkedlist
void  printlist(Node* &head){
        Node* temp = head;
        while(temp!= NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
        }
        cout<<endl;
}

int main(){
        // creating the node
        Node* node1 = new Node(10);
        cout<<node1->data<<endl;
        cout<<node1->next<<endl;

        // head pointed to node1
        Node* head = node1;
        printlist(head);

        Insertathead(head, 12);
        printlist(head);
        



        
        return 0;
}
