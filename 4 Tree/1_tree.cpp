#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert an element into the BST
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete an element from the BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to search for a key in the BST
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (key == root->data) {
        return true;
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to perform an inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display (Inorder Traversal)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;

            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;

            case 3:
                cout << "Enter the value to search: ";
                cin >> value;
                if (search(root, value)) {
                    cout << "Element " << value << " found in the BST." << endl;
                } else {
                    cout << "Element " << value << " not found in the BST." << endl;
                }
                break;

            case 4:
                cout << "Inorder traversal of the BST: ";
                inorderTraversal(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
