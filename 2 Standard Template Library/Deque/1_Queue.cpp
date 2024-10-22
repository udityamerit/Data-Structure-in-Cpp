#include<bits\stdc++.h>
using namespace std;

class Queue {
private:
    int front, rear;
    int size;
    int* queue;

public:
    Queue(int s) {
        front = -1;
        rear = -1;
        size = s;
        queue = new int[size];
    }

    bool isFull() {
        return rear == size - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void insert(int item) {
        if (isFull()) {
            cout << "Queue is full! Cannot insert item." << endl;
        } else {
            if (front == -1) front = 0;  // Initialize front
            rear++;
            queue[rear] = item;
            cout << "Inserted " << item << " into the queue." << endl;
        }
    }

    void deleteItem() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot delete item." << endl;
        } else {
            cout << "Deleted " << queue[front] << " from the queue." << endl;
            front++;
        }
    }

};
int main() {
    Queue q(5);  // Queue with a maximum size of 3

    q.insert(10);
    q.insert(20);
    q.insert(50);
    q.insert(66);
    q.insert(2);
    q.insert(40);  // This will show "Queue is full"

    q.deleteItem();
    q.insert(40);  // Now insert will work

    q.deleteItem();
    q.deleteItem();
    q.deleteItem();  // This will show "Queue is empty"

    return 0;
}