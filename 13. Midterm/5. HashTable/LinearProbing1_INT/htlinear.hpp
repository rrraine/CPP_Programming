#include <cstdlib>
#include <iostream>
#include "hashtable.hpp"
using namespace std;

template <typename K>
class HTLinear : public Hashtable<K>{
    int* table;
    int N;
    int count;
    bool* occupied;
    
    public:

    HTLinear<K>(int n){
        table = (K*)malloc(n * sizeof(K));
        N = n;
        occupied = (bool*)malloc(N * sizeof(bool));
        for (int i = 0; i < N; i++){
            occupied[i] = false;
        }
        count = 0;
    }

    int hash_code(K key){
        return key;
    }

    int compress(int code){
        return (((code * 59) + 17) % 509) % N;
    }

    int insert(K key){
        int index = this->hashfn(key);
        int originalIndex = index;
        int collisions = 0;

        while(occupied[index]){
            if (table[index] == key){
                throw logic_error("Already added key " + to_string(key));
            }

            collisions++;
            index = (index + 1) % N;

            if (index == N){
                throw logic_error("Table is full");
            }

        }

        table[index] = key;
        occupied[index] = true;
        count++;
        return collisions;
    }

    int search(K key){
        int index = this->hashfn(key);
        int originalIndex = index;
        int collision = 0;
        int i = 0;

        while (i < N){
            if (table[index] == key){
                return collision;
            }
            
            index = (index+1) % N;
            i++;
            collision++;
        }

        return -1;

    }

    int remove(K key){
        int index = this->hashfn(key);
        int originalIndex = index;
        int collision = 0;
        int i = 0;
        
        while(i < N){
            if (table[index] == key){
                if (table[index + 1] == 0){
                    table[index] = 0;
                }
                table[index] = -1;
                count--;
                occupied[index] = false;
                return collision;
            }

            collision++;
            index = (index + 1) % N;
            i++;
        }
        return -1;
    }

    void print(){
        for (int i = 0; i < N; i++){
            cout << i << "\t";
         }
         cout << endl;
        
         for (int i = 0; i < N; i++){
            if (!isOccupied[i]) cout << 0 << "\t";
            
           cout << table[i] << "\t";
        }

        cout << endl;
    }
  
};