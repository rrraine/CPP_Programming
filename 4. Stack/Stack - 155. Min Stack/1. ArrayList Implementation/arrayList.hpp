// TODO change this to handle int elements

#include <iostream>
#include <cstdlib>
#include <math.h>
#include "list.hpp"
using namespace std;

class ArrayList : public List {
    int* array;
    int size;
    int capacity = 5;

	void dynamic_add() {
		int new_size = ceil(capacity * 1.5);
        int* new_array = (int*) realloc(array, sizeof(int)*new_size);
        array = new_array;
        capacity = new_size;

	}

	void dynamic_deduce() {
		int new_size = ceil(capacity * 0.75);
        int* new_array = (int*) realloc (array, new_size* sizeof(int));
        array = new_array;
        capacity = new_size;
	}

    public:
    // constructor
    ArrayList() {
    	
        array = (int*) malloc(capacity * sizeof(int));
        size = 0;
    }

    void add(int c) {
        // TODO add num
        if (size == capacity){
            dynamic_add();
        }
        array[size++] = c;
    }

    int _size() {
        if (size < 0){
            size = 0;
        }
    	return size;
	}

    int removeLast() {
        // TODO remove and return last element
        /*
        int last = array[size-1];
        // size--;
        size = size - 1;
        return last;
        */
        if (size == 0){
            return ' ';
        }
        return array[--size];
	}


	int removeFirst() {
        // NOT NECESSARY
        return 0;
    }

    int remove(int num) {
        // NOT NECESSARY
        return 0;
    }

    int get(int pos) {
        if (size == 0){
            return ' ';
        }
        return array[pos-1];
    }
    
    int top(){
        return array[size-1];
    }

    bool isEmpty(){
        return size == 0;
    }
    void print() {
   		int i;
        for (i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        for (; i < capacity; i++) {
            cout << "? ";
		}
        cout << endl << size << "/" << capacity << endl;
    }
};