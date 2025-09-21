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
    
    int& operator[](int index) {
        return arr[index];
    }
};

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(DynamicArray &hT, int i) {
    int size = hT.size;
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && hT[l] < hT[smallest])
        smallest = l;
    if (r < size && hT[r] < hT[smallest])
        smallest = r;

    if (smallest != i) {
        swap(hT[i], hT[smallest]);
        heapify(hT, smallest);
    }
}

void insert(DynamicArray &hT, int newNum) {
    int size = hT.size;
    if (size == 0) {
        hT.push_back(newNum);
    } else {
        hT.push_back(newNum);
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(hT, i);
        }
    }
}

void deleteNode(DynamicArray &hT, int num) {
    int size = hT.size;
    int i;
    for (i = 0; i < size; i++) {
        if (num == hT[i])
            break;
    }
    swap(hT[i], hT[size - 1]);

    hT.pop_back();
    for (int i = hT.size / 2 - 1; i >= 0; i--) {
        heapify(hT, i);
    }
}

void printArray(DynamicArray &hT) {
    for (int i = 0; i < hT.size; ++i)
        cout << hT[i] << " ";
    cout << "\n";
}

int main() {
    DynamicArray heapTree;

    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);

    cout << "Min-Heap array: ";
    printArray(heapTree);

    deleteNode(heapTree, 4);

    cout << "After deleting an element: ";
    printArray(heapTree);
}

