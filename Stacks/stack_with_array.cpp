#include <iostream>
using namespace std;

// Custom Dynamic Array
class DynamicArray {
public:
    int* arr;
    int capacity;
    int size;

    DynamicArray() {
        capacity = 1;
        size = 0;
        arr = new int[capacity];
    }

    void push_back(int val) {
        if (size == capacity) {
            int* temp = new int[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[size] = val;
        size++;
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
    }
    
    int back() {
        if (size > 0) {
            return arr[size - 1];
        }
        return -1; // Should not happen in this stack implementation
    }

    bool empty() {
        return size == 0;
    }
};

class Stack {
private:
    DynamicArray arr;

public:
    void push(int data) {
        arr.push_back(data);
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int top = arr.back();
        arr.pop_back();
        return top;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr.back();
    }

    bool isEmpty() {
        return arr.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
    return 0;
}

