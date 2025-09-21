#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int data) {
        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = NULL;
        if (rear == NULL) {
            front = rear = new_node;
            return;
        }
        rear->next = new_node;
        rear = new_node;
    }

    int dequeue() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        Node* temp = front;
        int dequeued = temp->data;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
        return dequeued;
    }

    int peek() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << " Dequeued from queue\n";
    return 0;
}

