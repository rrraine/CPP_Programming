#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

// This hash table uses a MAD compression function
// where a = 11, b = 461, p = 919
//  Polynomial Hash Code using a=7


class HashTable {
   
    string* table;
    int N;
    int count;

    int hash(string key){
        int code = 0;
        int size = key.size();

        for (int i = 0; i < size; i++){
            code += (int) (key[i] + 'a' + 1) + pow(7, size - i + 1);
        }

        return code;
    }


    int compress(int code){
        return (11 * code + 461) % 919 % N;
    }


    int hash_fn(string key){
        return (compress(hash(key)));
    }

    public:

    HashTable(int N){
        this->N = N;
        table = (string*)malloc(N * sizeof(string));
        count = 0;
    }

    int add(string key){
        if (count == N){
            return -1;
        }

        int code = hash_fn(key);
        int numCollision = 0;

        while(!table[(code + (int)pow(numCollision, 2)) %N].empty()){
            ++numCollision;
        }

        table[(code + (int)pow(numCollision, 2)) % N] = key;

        return numCollision;
    }

    int remove(string key){
        int numCollision = search(key), hash = hash_fn(key);

        if (numCollision == -1){
            return -1;
        }

        table[(hash + (int)pow(numCollision, 2)) % N].clear();
        count--;

        return numCollision;
    }

    int search(string key){
       int numCollision = 0, hash = hash_fn(key);

       while (table[(hash + (int)pow(numCollision, 2)) % N] != key){
        ++numCollision;
        }

        return table[(hash + (int)pow(numCollision, 2)) % N].empty() || numCollision == N ? -1 : numCollision;
    }

    void print(){
        for (int i = 0; i < N; i++){
            cout << i << "\t";

            
        }

        cout << endl;

        for (int j = 0; j < N; j++){
            cout << table[j] << "\t";
        }

        cout << endl;
    }


};

