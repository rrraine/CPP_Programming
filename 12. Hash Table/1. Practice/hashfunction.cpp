#include <bits/stdc++.h>
#include "hashfunction.hpp"
using namespace std;

class HashFunction : public HashFunctions{
    // const static int prime = 31;

    // public:
    // template<typename K>
    // static int hashCode(K key){
    //     return key;
    // }

    // // tablesize and N are the same

    // static int divisionMethod(int key, int tableSize){
    //     return key % tableSize;
    // }

    // static int madMethod(int key, int a, int b, int N){
    //     return ((a * key + b) % prime) % N;
    // }

    static int divisionMethod(int key, int tableSize) {
        return key % tableSize;
    }

    static int madMethod(int key, int a, int b, int N) {
        return ((a * key + b) % 31) % N;  // Using 31 as a prime number
    }
};