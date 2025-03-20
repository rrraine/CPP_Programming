#include "list.hpp"
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
/**
 * Your ArrayList must have an initial capacity of 4.
 * If the array is full, allocate an additional capacity of 50% its current size.
 * Example, 4 becomes 6, then 6 becomes 9, so on.
 * Maintain a minimum capacity of 4.
 *
 * On the fields:
 * array - holds the pointer to the array itself
 * index - holds the current size, initially zero
 * capacity - holds the current capacity of the array - minimum of 4
 */
class ArrayList : public List {
    int* array;
    int index;
    int capacity;


    void sizeUp(){
        int newcap = ceil(capacity * 1.5);
        int* temp = (int*)realloc(array, newcap * sizeof(int));
        
        if (temp){
            array = temp;
            capacity = newcap;  
        } else {
            return;
        }
        // capacity = ceil(capacity * 1.5);
        // array = (int*)realloc(array, capacity * sizeof(int));
    }
    
    
    public:
        // CONSTRUCTOR
        ArrayList() {
            capacity = 4;
            index = 0;
            array = (int*)malloc(sizeof(int) * capacity);
        }

        int add(int num) {
            if (index == capacity) sizeUp();
            
            array[index++]= num;
            
          return index;
        }

        int get(int pos){
          if (pos > index) return -1;
          
          return array[pos];
        }

        int size(){
            return index;
        }

        void swap(int pos1, int pos2){
            int temp = array[pos1];
            array[pos1] = array[pos2];
            array[pos2] = temp;
        }

        // WARNING! Do not modify the print method.
        // Doing so will nullify your score for this activity.
        void print() {
            cout << "[";
            for (int i = 0; i < capacity; i++) {
                if (i < index) {
                    cout << *(array + i);
                } else {
                    cout << "?";
                }

                if (i != capacity - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
};