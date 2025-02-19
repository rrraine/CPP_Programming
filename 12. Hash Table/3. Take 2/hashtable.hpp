#include <iostream>
using namespace std;

template<typename K, typename V>
class Hashtable{
    public:
    virtual void add(K key, V value) = 0;
    virtual V get(K key) = 0;
    virtual bool search(K key) = 0;
    virtual V remove(K key) = 0;
    virtual void print() = 0;
     ~Hashtable(){};
     
};

/*
        Hastable();
        ~Hastable();
        void insert(K key, V value);
        void remove(K key);
        V get(K key);
        bool contains(K key);
        void print();
    private:
        struct Node{
            K key;
            V value;
            Node* next;
        };
        Node** table;
        int size;
        int capacity;
        int hash(K key);
     */  