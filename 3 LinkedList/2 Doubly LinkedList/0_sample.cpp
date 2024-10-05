#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
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

// Function to delete a node with a specific value
void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    
    // If the head needs to be deleted
    if (head->data == value) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }
    
    // Search for the node to be deleted
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        cout << "Node not found.\n";
        return;
    }
    
    // If it's the last node
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;
    delete temp;
}

// Function to traverse and display the doubly linked list
void traverse(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int choice, data, value;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Traverse\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                insertEnd(head, data);
                break;

            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                deleteNode(head, value);
                break;

            case 3:
                cout << "Doubly Linked List: ";
                traverse(head);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}