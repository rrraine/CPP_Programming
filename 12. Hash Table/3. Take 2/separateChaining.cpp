#include <iostream>
#include <list>
#include "hashtable.hpp"
using namespace std;

template<typename K, typename V>
class SeparateChaining : public Hashtable<K, V>{
    private:
    
    static const int TABLE_SIZE = 10;
    

    // division method palang ang ginamit dito
    int hashFunction(K key){
        //return key % TABLE_SIZE;
        std::hash<K> hash;
        return hash(key) % TABLE_SIZE;
    }

    int  hashFunctionMAD(K key){
        int a = 5, b = 3, p = 11;
        std::hash<K> h;
        size_t hash = h(key);
        return ((a * hash + b) % p) % TABLE_SIZE;
    }

    struct Entry{

        K key;
        V value;
        Entry(K k, V v) : key(k), value(v){}
    };

    list <Entry> table[SeparateChaining<K, V>::TABLE_SIZE];
    public:

    void add(K key, V value){
        int index = this->hashFunction(key);

        for (auto &entry : table[index]){
            if (entry.key == key){
                entry.value = value;
                return;
            }
        }
        //table[index].push_back(Entry(key, value));
        table[index].emplace_back(key, value);
    }

    V get(K key){
        int index = this->hashFunction(key);
        for (auto &entry: table[index]){
            if (entry.key == key){
                return entry.value;
            }
        }
        throw invalid_argument("Key not found");
    }
    bool search(K key){
        int index = this->hashFunction(key);
        for (auto &entry: table[index]){
            if (entry.key == key){
                return true;
            }
        }
        return false;
    }

    V remove(K key){
        V val;
        int index =  this->hashFunction(key);

        for (auto it = table[index].begin(); it!=table[index].end(); ++it){
            if (it->key == key){
                val = it->value;  
                table[index].erase(it);
                return val;
            }
        }
        throw invalid_argument("Key not found");
    }
    void print(){
        for (int i = 0; i < TABLE_SIZE; i++){
            cout <<"[" << i << "]: ";
            for (const auto &entry : table[i]){
                cout << "(" << entry.key << ") -> " << entry.value << " ";
            }
            cout << "NULL" << endl;
        }
    }
    ~SeparateChaining(){

    }
};

int r1(int n){
    int i,  sum = 0;
    if (n == 0){
        return 0;
    }
   
    for (i = 7; i <= n; i += 2){

        for (int j = 1; j < i / 2; j++){
            sum += i;
        }

    }

    return sum + r1(n - 2);
}