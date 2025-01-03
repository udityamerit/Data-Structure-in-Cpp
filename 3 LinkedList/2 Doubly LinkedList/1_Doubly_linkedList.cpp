#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtTail(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int data) {
        if (head == nullptr) return;
        Node* temp = head;

        while (temp != nullptr && temp->data != data) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        if (temp->prev != nullptr) temp->prev->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = temp->prev;

        if (temp == head) head = temp->next;

        delete temp;
    }

    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        if (head == nullptr) return;
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtHead(10);
    dll.insertAtHead(20);
    dll.insertAtTail(5);
    dll.insertAtTail(1);

    cout << "Forward display: ";
    dll.displayForward();

    cout << "Backward display: ";
    dll.displayBackward();

    dll.deleteNode(20);

    cout << "After deleting 20, forward display: ";
    dll.displayForward();

    return 0;
}
