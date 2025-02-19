#include <iostream>
#include <list>
#include "hashtable.hpp"

using namespace std;

template<typename K, typename V>

class LinearProbing : public Hashtable<K, V>{
    private:

    static const int TABLE_SIZE = 10;
    
    struct Entry{
        K key;
        V value;
        bool isOccupied;
        Entry(): isOccupied(false){}
        Entry(K k, V v): key(k), value(v), isOccupied(true){}

    };

    int  hashFunctionMAD(K key){
        int a = 5, b = 3, p = 11;
        std::hash<K> h;
        size_t hash = h(key);
        return ((a * hash + b) % p) % TABLE_SIZE;
    }

    int hashFunction(K key){
        std::hash<K> hash;
        return hash(key) % TABLE_SIZE;
    }

    Entry table[LinearProbing<K, V>::TABLE_SIZE];
    public:

    void add(K key, V value) {
        int index = hashFunctionMAD(key);
        int originalIndex = index;
        while(table[index].isOccupied && table[index].key != key){
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex){
                throw invalid_argument("Table is full");
            }
        }
        table[index] = Entry(key, value);
    }

    V get(K key) {

        int index = hashFunctionMAD(key);
        int originalIndex = index;

        while (table[index].isOccupied){
            if (table[index].key == key){
                return table[index].value;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) break;
        }
        throw invalid_argument("Key not found");
    }

    bool search(K key) {
        int index = hashFunctionMAD(key);
        int originalIndex = index;

        while (table[index].isOccupied){
            if (table[index].key == key){
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) return false;
        }
        return false;
    }

    V remove(K key) {
        int index = hashFunctionMAD(key);
        while (table[index].isOccupied){
            if (table[index].key == key){
                V val = table[index].value;
                table[index].isOccupied = false;
                return val;
            }
        }
        throw invalid_argument("Key not found");
    }

    void print() {

        for (int i; i < TABLE_SIZE; i++){
            cout << "Index " << i;
            if (table[i].isOccupied){
                cout << " Key: " << table[i].key << " Value: " << table[i].value << endl;
            } else {
                cout << ": NULL" << endl;
            }
           
        }
    }

    ~LinearProbing(){

    }

};