// hashtable.hpp
#include <bits/stdc++.h>
using namespace std;

template<typename K, typename V>

class HashTable{

    public:

    struct Entry{
        K key;
        V value;
        bool isOccupied;

        Entry() : isOccupied(false) {}
    };
    void add(K key, V value);
    bool search(K key);
    void remove(K key);
    void print();

};