#include <iostream>
#include <cstdlib>
#include "hashtable.hpp"
#include "linkedlist.hpp"

using namespace std;

class HTSepChain : public HashTable{

    int N;
    LinkedList** table;

    public:

    HTSepChain(int N){

        this->N = N;

        table = new LinkedList*[N];
        for (int i = 0; i < N; i++){
            table[i] = nullptr;
        }
    }

    int hash_code(string key){
        int sum = 0;
        for (char c : key){
            sum = sum * 5 + c;
        }

        return sum;
    }

    int compress(int code){
        return code % N;
    }

    int insert(string key){
        int index = this->hashfn(key);

        if (table[index] == nullptr){
            table[index] = new LinkedList();
        }

        return table[index]->insert(key);
    }

    int search(string key){
        int index = this->hashfn(key);

        if (table[index] == nullptr){
            table[index] = new LinkedList();
        }

        return table[index]->search(key);
    }

    int remove(string key){
        int index = this->hashfn(key);

        if (table[index] == nullptr){
            table[index] = new LinkedList();
        }

        return table[index]->remove(key);
    }

    void print(){
        for (int i = 0; i < N; i++){
            cout << i << ": ";
            if (table[i] != nullptr){
                table[i]->print();
            }

            cout << endl;

        }
    }

};