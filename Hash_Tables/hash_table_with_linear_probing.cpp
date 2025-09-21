#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
class HashTable {
private:
    int* table;
    int* status; // 0 for empty, 1 for occupied, -1 for deleted

public:
    HashTable() {
        table = new int[TABLE_SIZE];
        status = new int[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            status[i] = 0; // All slots are initially empty
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insertItem(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (status[(index + i) % TABLE_SIZE] == 1) {
            if (table[(index + i) % TABLE_SIZE] == key) {
                cout << "Key already exists" << endl;
                return;
            }
            i++;
            if (i == TABLE_SIZE) {
                cout << "Hash table is full" << endl;
                return;
            }
        }
        int newIndex = (index + i) % TABLE_SIZE;
        table[newIndex] = key;
        status[newIndex] = 1;
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (status[(index + i) % TABLE_SIZE] != 0) {
            if (table[(index + i) % TABLE_SIZE] == key && status[(index + i) % TABLE_SIZE] == 1) {
                status[(index + i) % TABLE_SIZE] = -1; // Mark as deleted
                cout << "Key " << key << " deleted" << endl;
                return;
            }
            i++;
            if (i == TABLE_SIZE) {
                break;
            }
        }
        cout << "Key not found" << endl;
    }

    void displayHash() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (status[i] == 1) {
                cout << "table[" << i << "] = " << table[i] << endl;
            }
        }
    }
};

int main() {
    HashTable ht;
    ht.insertItem(12);
    ht.insertItem(22);
    ht.insertItem(32);
    ht.insertItem(15);
    ht.insertItem(25);

    cout << "Hash table contents:" << endl;
    ht.displayHash();

    ht.deleteItem(22);
    cout << "\nAfter deleting 22:" << endl;
    ht.displayHash();

    return 0;
}

