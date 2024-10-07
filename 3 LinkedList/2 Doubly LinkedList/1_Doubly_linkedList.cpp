#include<bits/stdc++.h>
using namespace std;

struct Node{
        public:
        int data;
        Node* next;

        Node(int data){
                this->data = data;
                this->next = NULL;
        }
};

// inssert at start
void insertstart(Node* &head, int d){
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
}


// insert at tail
void inserttail(Node* &tail, int d){
        Node* temp = new Node(d);
        tail->next = temp;
        tail = tail->next;
}

// insert middle node
void insertmiddle(Node* &head, Node* &tail, int position, int d){
        if (position==1){
                insertstart(head, d);
                return;
        }
        int cnt = 1;
        Node* temp = head;
        while(cnt<position-1){
                temp->next = head;
                cnt++;
        }

        if (temp->next == NULL){
                inserttail(tail, d);
                return;
        }

        Node* insertpoint = new Node(d);
        insertpoint->next = temp->next;
        temp->next = insertpoint;

}
// print the node
void printnode(Node* &head){
        Node* temp = head;
        while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
        }
        cout<<endl;

}

int main(){
        Node* node1 = new Node(10);
        Node* head = node1;
        Node* tail = node1;
        insertstart(head, 60);
        printnode(head);

        inserttail(tail, 40);
        printnode(head);

        insertmiddle(head, tail, 2, 45);
        printnode(head);

        return 0;
}