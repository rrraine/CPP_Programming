#include <bits/stdc++.h>
using namespace std;

class Hash{
    string* table;
     int N; // capacity
     int count;


     int hash(string key){
        int code = 0, size = key.size();
        for (int i = 0; i < size; i++){
            code +=(int) (key[i] + 'a' + 1) * pow(7, size - i + 1 );
        }

        return code;
     }

     // This hash table uses a MAD compression function
    // where a = 11, b = 461, p = 919
     int compress(int code){
        return (11 * code + 461) % 919 % N;
     }

     int hash_fn(string key){
        return compress(hash(key));
     }

     public:

     Hash(int N){
        this->N = N;
        count = 0;
        table = new string[N];
     }

     int insert(string key){

        if (count == N){
            return -1;
        }
        int numCollision = 0, hash = hash_fn(key);

        while(!table[(hash + (int)(pow(numCollision, 2)) % N)].empty()){
            ++numCollision;
        }

        table[(hash + (int)pow(numCollision, 2)) % N] = key;
        count++;
        return numCollision;

     }

     int search(string key){
        int numCollision = 0, hash = hash_fn(key);

        while(table[(hash + (int) pow(numCollision, 2)) % N] != key){
            ++numCollision;
        }

        return table[(hash + (int)pow(numCollision, 2)) % N].empty() || numCollision == N ? -1 : numCollision;
     }

     int remove(string key){

        int numCollision = search(key), hash = hash_fn(key);

        if (numCollision != 1){
            table[(hash + (int)pow(numCollision, 2)) % N] = "";
        }

        return numCollision;
     }

     void print() {
        for(int i = 0; i < N; i++)
            cout << i << '\t';
        cout << '\n';
        for(int i = 0; i < N; i++)
            cout << table[i] << '\t';
        cout << '\n';
    }

};