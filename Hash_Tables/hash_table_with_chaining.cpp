#include <iostream>
using namespace std;

// Custom Node for the Linked List
struct Node {
    int data;
    Node* next;
};

// Custom Linked List for chaining
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert a key into the linked list
    void push_back(int key) {
        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Delete a key from the linked list
    void deleteNode(int key) {
        Node *temp = head, *prev = NULL;

        if (temp != NULL && temp->data == key) {
            head = temp->next; 
            delete temp;
            return;
        }

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;

        prev->next = temp->next;

        delete temp; 
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << " --> " << temp->data;
            temp = temp->next;
        }
    }
};

class Hash {
    int BUCKET;
    LinkedList *table; // Use custom LinkedList

public:
    Hash(int V);
    void insertItem(int x);
    void deleteItem(int key);
    int hashFunction(int x) {
        return (x % BUCKET);
    }

    void displayHash();
};

Hash::Hash(int b) {
    this->BUCKET = b;
    table = new LinkedList[BUCKET];
}

void Hash::insertItem(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key) {
    int index = hashFunction(key);
    table[index].deleteNode(key);
}

void Hash::displayHash() {
    for (int i = 0; i < BUCKET; i++) {
        cout << i;
        table[i].display();
        cout << endl;
    }
}

int main() {
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a) / sizeof(a[0]);

    Hash h(7);

    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

    h.deleteItem(12);

    h.displayHash();

    return 0;
}

