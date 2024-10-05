#include<bits/stdc++.h>
using namespace std;


// create a Node:
struct Node{
        public:
        int data;
        Node* next;

        // creating a constructor
        Node(int data){
                this->data = data;
                this->next = NULL;
        }

        // creating a destructior
        ~Node(){
                int value = this->data;
                // memory free
                if(this->next != NULL){
                        delete next;
                        this->next = NULL;
                }
                cout<<"memory is free for node with data: "<<value<<endl;
        }
};


// insert a node at head:
void insertathead(Node* &head, int dataa){
        Node* temp = new Node(dataa);
        temp->next = head;
        head = temp;
        
}

// insert a node at the end:
void insertatlast(Node* &tail, int da){
        Node* temp  = new Node(da);
        tail->next = temp;
        tail = tail->next;

}

// insert a node at the middle of the linkedlist using the position:
void insertatmiddle(int position, int d, Node* head, Node* tail){

        // insert at start
        if (position==1){
                insertathead(head, d);
                return;
        }
        int cnt = 1;

        Node* temp = head;

        // updating the head
        while(cnt<position-1){
                temp = temp->next;
                cnt++;
        }

        // inserting at last position
        if (temp->next==NULL){
                insertatlast(tail, d);
                return;
        }

        // create a node which is insert at the middle
        Node* middlenode = new Node(d);
        middlenode->next = temp->next; 
        temp->next = middlenode;

}


// Deleting the node:
void deletnode(int position, Node* &head){
        // deleting first or start node
        if(position==1){
                Node* temp = head;
                head = head->next;
                // free the memory
                temp->next = NULL;
                delete temp;
        }
        else{
                // deleting any middle node or last node
                Node* curr = head;
                Node* prev = NULL;

                int cnt = 1;
                while(cnt < position){
                        prev = curr;
                        curr = curr->next;
                        cnt++;
                }
                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
        }
}


// creating a function to show the data of linkedlist:
void printdata(Node* &head){
        Node* temp = head;
        while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
        }
        cout<<endl;
}
int main(){

        // creating a node
        Node* node1 = new Node(10);

        // creating a head pointer for node1
        Node* head = node1;

        // creating a tail pointer for node1
        Node* tail = node1;
        // cout<<node1->data;

        // insert the node;
        insertathead(head, 40);
        printdata(head);

        // insert a node at last
        insertatlast(tail, 90);
        printdata(head);

        // insert a node at 3rd position
        insertatmiddle(3, 22, head, tail);
        printdata(head);

        // insertatmiddle(4, 90, head, tail);
        // printdata(head);

        cout<<"head = "<<head->data<<endl;
        cout<<"tail = "<<tail->data<<endl;

        // deleting the node
        deletnode(3,head);
        printdata(head);


        return 0;
}