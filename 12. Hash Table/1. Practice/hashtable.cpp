// hashtable.cpp
#include <iostream>
#include "hashtable.hpp"
#include "hashfunction.hpp"
using namespace std;

template <typename K, typename V>
class HashTables : public HashTable{

    
    private: 
    
    static const int tableSize = 10;
    Entry table[tableSize];
    bool useMAD;


    public:

    HashTable(int size, bool usedMAD = false){}

    void add(K key, V value){

        int hash = useMad ? 

    }
    bool search(K key){

    }
    void remove(K key){

    }
    void print(){

    }
};


