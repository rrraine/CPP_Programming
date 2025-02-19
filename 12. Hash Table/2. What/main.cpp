#include <iostream>
#include <list>

const int PRIME = 109345121; // Large prime number for MAD method

// Hash Table using Separate Chaining
template <typename K, typename V>
class HashTableSeparateChaining {
private:
    int N;
    std::list<std::pair<K, V>>* table;

    int hashCode(K key) {
        return std::hash<K>{}(key);
    }

    int divisionMethod(K key) {
        return hashCode(key) % N;
    }

    int madMethod(K key, int a, int b) {
        return ((a * hashCode(key) + b) % PRIME) % N;
    }

public:
    HashTableSeparateChaining(int size) : N(size) {
        table = new std::list<std::pair<K, V>>[N];
    }

    ~HashTableSeparateChaining() {
        delete[] table;
    }

    void insert(K key, V value, int a = 1, int b = 0, bool useMAD = false) {
        int index = useMAD ? madMethod(key, a, b) : divisionMethod(key);
        table[index].push_back({key, value});
    }

    void display() {
        for (int i = 0; i < N; i++) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& entry : table[i]) {
                std::cout << "(" << entry.first << ", " << entry.second << ") ";
            }
            std::cout << "\n";
        }
    }
};

// Hash Table using Linear Probing
template <typename K, typename V>
class HashTableLinearProbing {
private:
    int N;
    std::pair<K, V>* table;
    bool* occupied;

    int hashCode(K key) {
        return std::hash<K>{}(key);
    }

    int divisionMethod(K key) {
        return hashCode(key) % N;
    }

    int madMethod(K key, int a, int b) {
        return ((a * hashCode(key) + b) % PRIME) % N;
    }

public:
    HashTableLinearProbing(int size) : N(size) {
        table = new std::pair<K, V>[N];
        occupied = new bool[N]{false};
    }

    ~HashTableLinearProbing() {
        delete[] table;
        delete[] occupied;
    }

    void insert(K key, V value, int a = 1, int b = 0, bool useMAD = false) {
        int index = useMAD ? madMethod(key, a, b) : divisionMethod(key);
        while (occupied[index]) {
            index = (index + 1) % N; // Linear probing
        }
        table[index] = {key, value};
        occupied[index] = true;
    }

    void display() {
        for (int i = 0; i < N; i++) {
            if (occupied[i]) {
                std::cout << "Index " << i << ": (" << table[i].first << ", " << table[i].second << ")\n";
            } else {
                std::cout << "Index " << i << ": EMPTY\n";
            }
        }
    }
};

int main() {
    int size = 10;
    HashTableSeparateChaining<int, std::string> hashTableSC(size);
    HashTableLinearProbing<int, std::string> hashTableLP(size);

    // Sample keys and values
    std::pair<int, std::string> data[] = {{15, "Apple"}, {25, "Banana"}, {35, "Cherry"}, {45, "Date"}, {55, "Elderberry"}};
    
    for (const auto& entry : data) {
        hashTableSC.insert(entry.first, entry.second);
        hashTableLP.insert(entry.first, entry.second);
    }

    std::cout << "Hash Table using Separate Chaining:\n";
    hashTableSC.display();

    std::cout << "\nHash Table using Linear Probing:\n";
    hashTableLP.display();
    
    return 0;
}