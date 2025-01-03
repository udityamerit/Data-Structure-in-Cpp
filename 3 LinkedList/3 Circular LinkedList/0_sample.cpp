#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(Node*& last, int data) {
    Node* newNode = createNode(data);
    
    if (last == nullptr) {
        last = newNode;
        last->next = last;  // Pointing to itself, since it's the only node
    } else {
        newNode->next = last->next;  
        last->next = newNode;         
        last = newNode;           
    }
}


void deleteNode(Node*& last, int value) {
    if (last == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = last->next;  
    Node* prev = last;

    
    if (last == last->next && last->data == value) {
        delete last;
        last = nullptr;
        return;
    }

    
    if (temp->data == value) {
        prev->next = temp->next;
        if (last->next == temp) {
            last->next = temp->next;  
        }
        delete temp;
        return;
    }

    // Traverse and search for the node to be deleted
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != last->next && temp->data != value);

    // If node not found
    if (temp == last->next) {
        cout << "Node not found.\n";
        return;
    }

    // If node is found
    prev->next = temp->next;
    if (temp == last) {  // If the last node is being deleted
        last = prev;     // Update the last pointer
    }
    delete temp;
}

// Function to traverse and display the circular linked list
void traverse(Node* last) {
    if (last == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = last->next;  // Start from the head
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);
    cout << endl;
}

int main() {
    Node* last = nullptr;  // Initialize the circular linked list

    int choice, data, value;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Traverse\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                insertEnd(last, data);
                break;

            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                deleteNode(last, value);
                break;

            case 3:
                cout << "Circular Linked List: ";
                traverse(last);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}