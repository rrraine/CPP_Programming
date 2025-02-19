#include <iostream>

using namespace std;

const int PRIME = 109345121;

// Base Hash Table Class
template <typename K, typename V>
class HashTable {
public:
    virtual void add(K key, V value) = 0;
    virtual bool search(K key) = 0;
    virtual void remove(K key) = 0;
    virtual void print() = 0;
};

// Hash Table using Separate Chaining
template <typename K, typename V>
class HashTableSeparateChaining : public HashTable<K, V> {
private:
    static const int tableSize = 10;
    struct Entry {
        K key;
        V value;
        Entry* next;
        Entry(K k, V v) : key(k), value(v), next(nullptr) {}
    };
    Entry* table[tableSize] = {nullptr};
    
    int hashFunction(K key) {
        return key % tableSize;
    }

public:
    void add(K key, V value) override {
        int index = hashFunction(key);
        Entry* newNode = new Entry(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    bool search(K key) override {
        int index = hashFunction(key);
        Entry* current = table[index];
        while (current) {
            if (current->key == key) return true;
            current = current->next;
        }
        return false;
    }

    void remove(K key) override {
        int index = hashFunction(key);
        Entry* current = table[index];
        Entry* prev = nullptr;
        while (current) {
            if (current->key == key) {
                if (prev) prev->next = current->next;
                else table[index] = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void print() override {
        for (int i = 0; i < tableSize; i++) {
            cout << "Bucket " << i << ": ";
            Entry* current = table[i];
            while (current) {
                cout << "(" << current->key << ", " << current->value << ") ";
                current = current->next;
            }
            cout << "\n";
        }
    }
};

// Hash Table using Linear Probing
template <typename K, typename V>
class HashTableLinearProbing : public HashTable<K, V> {
private:
    static const int tableSize = 10;
    struct Entry {
        K key;
        V value;
        bool isOccupied;
        Entry() : isOccupied(false) {}
    };
    Entry table[tableSize];

    int hashFunction(K key) {
        return key % tableSize;
    }

public:
    void add(K key, V value) override {
        int index = hashFunction(key);
        while (table[index].isOccupied) {
            index = (index + 1) % tableSize;
        }
        table[index] = {key, value, true};
    }

    bool search(K key) override {
        int index = hashFunction(key);
        while (table[index].isOccupied) {
            if (table[index].key == key) return true;
            index = (index + 1) % tableSize;
        }
        return false;
    }

    void remove(K key) override {
        int index = hashFunction(key);
        while (table[index].isOccupied) {
            if (table[index].key == key) {
                table[index].isOccupied = false;
                return;
            }
            index = (index + 1) % tableSize;
        }
    }

    void print() override {
        for (int i = 0; i < tableSize; i++) {
            if (table[i].isOccupied) {
                cout << "Index " << i << ": (" << table[i].key << ", " << table[i].value << ")\n";
            } else {
                cout << "Index " << i << ": EMPTY\n";
            }
        }
    }
};

int main() {
    HashTableSeparateChaining<int, string> hashTableSC;
    HashTableLinearProbing<int, string> hashTableLP;

    pair<int, string> data[] = {{15, "Apple"}, {25, "Banana"}, {35, "Cherry"}, {45, "Date"}, {55, "Elderberry"}};
    
    for (const auto& entry : data) {
        hashTableSC.add(entry.first, entry.second);
        hashTableLP.add(entry.first, entry.second);
    }

    cout << "Hash Table using Separate Chaining:\n";
    hashTableSC.print();

    cout << "\nHash Table using Linear Probing:\n";
    hashTableLP.print();
    
    return 0;
}
