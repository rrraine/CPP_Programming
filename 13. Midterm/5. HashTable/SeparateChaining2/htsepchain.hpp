#include <iostream>
#include <cstdlib>
#include "hashtable.hpp"
#include "staticArray.hpp"

using namespace std;

class HTSepChain : public HashTable{

    int N;
    ArrayStatic** table;

    public:

    HTSepChain(int N){

        this->N = N;

        table = new ArrayStatic*[N];
        for (int i = 0; i < N; i++){
            table[i] = nullptr;
        }
    }

    int hash_code(int key){
       return key;
    }

    int compress(int code){
        return ((72 * code + 13) % 101) % N;
    }

    int insert(int key){
       int index = this->hashfn(key);

       if (table[index] == nullptr){
            table[index] = new ArrayStatic();
       }

       return table[index]->insert(key, index);
       
    }

    int search(int key){
        int index = this->hashfn(key);

        if (table[index] == nullptr){
             table[index] = new ArrayStatic();
        }
 
        return table[index]->search(key);
    }

    int remove(int key){
        int index = this->hashfn(key);

       if (table[index] == nullptr){
            table[index] = new ArrayStatic();
       }

       return table[index]->remove(key);
    }

    void print(){
        for (int i = 0; i < N; i++){

            cout << i << "\t";
            if (table[i] != nullptr){
                table[i]->print();
            }
            cout << endl;
        }
        cout << endl;
    }

};