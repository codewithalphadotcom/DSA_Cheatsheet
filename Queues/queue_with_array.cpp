#include <iostream>
using namespace std;

// Custom Dynamic Array
class DynamicArray {
public:
    int* arr;
    int capacity;
    int size;
    int front_idx;

    DynamicArray() {
        capacity = 1;
        size = 0;
        front_idx = 0;
        arr = new int[capacity];
    }

    void push_back(int val) {
        if (size == capacity) {
            int* temp = new int[2 * capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[front_idx + i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
            front_idx = 0;
        }
        arr[front_idx + size] = val;
        size++;
    }

    void erase_front() {
        if (size > 0) {
            front_idx++;
            size--;
        }
    }
    
    int front() {
        if (size > 0) {
            return arr[front_idx];
        }
        return -1; // Should not happen in this queue implementation
    }

    bool empty() {
        return size == 0;
    }
};

class Queue {
private:
    DynamicArray arr;

public:
    void enqueue(int data) {
        arr.push_back(data);
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int front_val = arr.front();
        arr.erase_front();
        return front_val;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr.front();
    }

    bool isEmpty() {
        return arr.empty();
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

