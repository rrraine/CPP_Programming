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

    // if u want to map using lower case only use <cctype>, char ch = tolower(key[i]);  

    int hash_code(string key) {
        int code = 0, size = key.size();

        for (int i = 0; i < size; i++){
            //code += (int) key[i] * pow(7, size - i - 1); 
            code += (int) (key[i] -'a' + 1) * pow(7, size - i + 1);
        }

        return code;
    }

    int compress(int code) {
        return (11 * code + 461) % 919 % N;
    }

    int hashfn(string key) {
        return compress(hash_code(key));
    }


    public:

    HashTable(int N){
        this->N = N;
        count = 0;
        table = new string[N];
    }

    int insert(string key) {
        if (count == N){
            //throw overflow_error("Hash table is full");
            return -1;
        }

        int collision = 0, hash = hashfn(key);


        while (!table[(hash + (int)pow(collision, 2)) % N].empty()){
            ++collision;
        } 

        table[(hash + (int)pow(collision, 2)) % N] = key;
        count++;
        return collision;
    }

    int search(string key) {
        int collision = 0, hash = hashfn(key);


        while (table[(hash + (int)pow(collision, 2)) %N] != key && collision < N){
            ++collision;  
        }

        return table[(hash + (int)pow(collision, 2)) % N].empty() || collision == N ? -1 : collision;
    }

    int remove(string key) {
        int collision= search(key), hash = hashfn(key);

        if (collision != -1){
            table[(hash + (int)pow(collision, 2)) % N] = "";
            count--;
        }

        return collision;
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

